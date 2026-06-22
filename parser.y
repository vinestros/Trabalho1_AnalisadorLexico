%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ASTNode ASTNode;
typedef struct ASTChild ASTChild;

struct ASTChild {
    ASTNode *node;
    ASTChild *next;
};

struct ASTNode {
    char *label;
    ASTChild *first_child;
    ASTChild *last_child;
};

static ASTNode *g_root = NULL;
extern int yylineno;
extern FILE *yyin;
int yylex(void);
void yyerror(const char *msg);

static ASTNode *ast_make_node(const char *label) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Erro: memoria insuficiente para AST\n");
        exit(1);
    }
    node->label = strdup(label ? label : "");
    node->first_child = NULL;
    node->last_child = NULL;
    return node;
}

static ASTNode *ast_make_leaf(const char *prefix, const char *value) {
    char buffer[512];
    if (prefix && prefix[0] != '\0') {
        snprintf(buffer, sizeof(buffer), "%s: %s", prefix, value ? value : "");
    } else {
        snprintf(buffer, sizeof(buffer), "%s", value ? value : "");
    }
    return ast_make_node(buffer);
}

static void ast_add_child(ASTNode *parent, ASTNode *child) {
    ASTChild *entry;
    if (!parent || !child) return;
    entry = (ASTChild *)malloc(sizeof(ASTChild));
    if (!entry) {
        fprintf(stderr, "Erro: memoria insuficiente para filho da AST\n");
        exit(1);
    }
    entry->node = child;
    entry->next = NULL;

    if (!parent->first_child) {
        parent->first_child = entry;
        parent->last_child = entry;
    } else {
        parent->last_child->next = entry;
        parent->last_child = entry;
    }
}

static ASTNode *ast_wrap_statement(ASTNode *stmt) {
    ASTNode *wrapper = ast_make_node("statement");
    ast_add_child(wrapper, stmt);
    return wrapper;
}

static void ast_print(ASTNode *node, int depth) {
    ASTChild *it;
    int i;
    if (!node) return;
    for (i = 0; i < depth; i++) {
        putchar('-');
    }
    printf("%s\n", node->label);
    it = node->first_child;
    while (it) {
        ast_print(it->node, depth + 1);
        it = it->next;
    }
}

static void ast_free(ASTNode *node) {
    ASTChild *it;
    ASTChild *next;
    if (!node) return;
    it = node->first_child;
    while (it) {
        next = it->next;
        ast_free(it->node);
        free(it);
        it = next;
    }
    free(node->label);
    free(node);
}
/* AI_GENERATED_CODE_END */
%}

%code requires {
typedef struct ASTNode ASTNode;
}

%union {
    char *str;
    ASTNode *node;
}

%token IF ELSE WHILE VOID_KEYWORD FUNCTION_KEYWORD
%token INT_KEYWORD FLOAT_KEYWORD CHAR_KEYWORD RETURN
%token OP_IGUALDADE OP_DIFERENTE OP_MENOR OP_MAIOR OP_MENOR_IGUAL OP_MAIOR_IGUAL
%token OP_SOMA OP_SUB OP_MULT OP_DIV OP_ATRIBUICAO
%token PONTO_VIRGULA VIRGULA PARENTESES_ESQ PARENTESES_DIR CHAVES_ESQ CHAVES_DIR COLCHETE_ESQ COLCHETE_DIR
%token <str> ID INTEGER FLOAT STRING LITERAL_CHAR

%type <node> program item_list item statement_list statement
%type <node> declaration function_declaration function_return_type type_spec
%type <node> assignment location expression condition relop
%type <node> if_statement while_statement return_statement
%type <node> function_call argument_list_opt argument_list
%type <node> parameter_list_opt parameter_list parameter
%type <node> block
%type <node> expression_statement

%left OP_IGUALDADE OP_DIFERENTE OP_MENOR OP_MAIOR OP_MENOR_IGUAL OP_MAIOR_IGUAL
%left OP_SOMA OP_SUB
%left OP_MULT OP_DIV

%start program

%%

program
    : item_list
      {
          $$ = ast_make_node("program");
          ast_add_child($$, $1);
          g_root = $$;
      }
    ;

item_list
    : item_list item
      {
          ast_add_child($1, $2);
          $$ = $1;
      }
    | /* empty */
      {
          $$ = ast_make_node("statement list");
      }
    ;

item
    : statement
      {
          $$ = $1;
      }
    | function_declaration
      {
          $$ = ast_wrap_statement($1);
      }
    ;

statement_list
    : statement_list statement
      {
          ast_add_child($1, $2);
          $$ = $1;
      }
    | /* empty */
      {
          $$ = ast_make_node("statement list");
      }
    ;

statement
    : declaration
      {
          $$ = ast_wrap_statement($1);
      }
    | assignment PONTO_VIRGULA
      {
          $$ = ast_wrap_statement($1);
      }
    | if_statement
      {
          $$ = ast_wrap_statement($1);
      }
    | while_statement
      {
          $$ = ast_wrap_statement($1);
      }
    | return_statement
      {
          $$ = ast_wrap_statement($1);
      }
    | expression_statement
      {
          $$ = ast_wrap_statement($1);
      }
    | block
      {
          $$ = ast_wrap_statement($1);
      }
    ;

declaration
    : type_spec ID PONTO_VIRGULA
      {
          $$ = ast_make_node("declaration");
          ast_add_child($$, $1);
          ast_add_child($$, ast_make_leaf("", $2));
          free($2);
      }
    | type_spec ID COLCHETE_ESQ expression COLCHETE_DIR PONTO_VIRGULA
      {
          ASTNode *vector_node = ast_make_node("vector size");
          $$ = ast_make_node("declaration");
          ast_add_child($$, $1);
          ast_add_child($$, ast_make_leaf("", $2));
          ast_add_child(vector_node, $4);
          ast_add_child($$, vector_node);
          free($2);
      }
    ;

function_declaration
    : FUNCTION_KEYWORD function_return_type ID PARENTESES_ESQ parameter_list_opt PARENTESES_DIR block
      {
          $$ = ast_make_node("function declaration");
          ast_add_child($$, $2);
          ast_add_child($$, ast_make_leaf("id", $3));
          ast_add_child($$, $5);
          ast_add_child($$, $7);
          free($3);
      }
    ;

function_return_type
    : type_spec
      {
          $$ = $1;
      }
    | VOID_KEYWORD
      {
          $$ = ast_make_node("VOID");
      }
    ;

type_spec
    : INT_KEYWORD
      {
          $$ = ast_make_node("INT");
      }
    | FLOAT_KEYWORD
      {
          $$ = ast_make_node("FLOAT");
      }
    | CHAR_KEYWORD
      {
          $$ = ast_make_node("CHAR");
      }
    ;

parameter_list_opt
    : parameter_list
      {
          $$ = $1;
      }
    | /* empty */
      {
          $$ = ast_make_node("parameter list");
      }
    ;

parameter_list
    : parameter
      {
          $$ = ast_make_node("parameter list");
          ast_add_child($$, $1);
      }
    | parameter_list VIRGULA parameter
      {
          ast_add_child($1, $3);
          $$ = $1;
      }
    ;

parameter
    : type_spec ID
      {
          $$ = ast_make_node("parameter");
          ast_add_child($$, $1);
          ast_add_child($$, ast_make_leaf("id", $2));
          free($2);
      }
    ;

assignment
    : location OP_ATRIBUICAO expression
      {
          $$ = ast_make_node("attribution");
          ast_add_child($$, $1);
          ast_add_child($$, $3);
      }
    ;

location
    : ID
      {
          $$ = ast_make_leaf("", $1);
          free($1);
      }
    | ID COLCHETE_ESQ expression COLCHETE_DIR
      {
          $$ = ast_make_node("vector access");
          ast_add_child($$, ast_make_leaf("id", $1));
          ast_add_child($$, $3);
          free($1);
      }
    ;

if_statement
    : IF PARENTESES_ESQ condition PARENTESES_DIR block
      {
          $$ = ast_make_node("if statement");
          ast_add_child($$, $3);
          ast_add_child($$, $5);
      }
    | IF PARENTESES_ESQ condition PARENTESES_DIR block ELSE block
      {
          $$ = ast_make_node("if statement");
          ast_add_child($$, $3);
          ast_add_child($$, $5);
          ast_add_child($$, $7);
      }
    ;

while_statement
    : WHILE PARENTESES_ESQ condition PARENTESES_DIR block
      {
          $$ = ast_make_node("while statement");
          ast_add_child($$, $3);
          ast_add_child($$, $5);
      }
    ;

condition
    : expression relop expression
      {
          $$ = ast_make_node("condition");
          ast_add_child($$, $1);
          ast_add_child($$, $2);
          ast_add_child($$, $3);
      }
    ;

relop
    : OP_IGUALDADE
      {
          $$ = ast_make_node("rlop");
          ast_add_child($$, ast_make_leaf("", "se_for"));
      }
    | OP_DIFERENTE
      {
          $$ = ast_make_node("rlop");
          ast_add_child($$, ast_make_leaf("", "se_nao_for"));
      }
    | OP_MENOR
      {
          $$ = ast_make_node("rlop");
          ast_add_child($$, ast_make_leaf("", "menos_que"));
      }
    | OP_MAIOR
      {
          $$ = ast_make_node("rlop");
          ast_add_child($$, ast_make_leaf("", "mais_que"));
      }
    | OP_MENOR_IGUAL
      {
          $$ = ast_make_node("rlop");
          ast_add_child($$, ast_make_leaf("", "no_maximo"));
      }
    | OP_MAIOR_IGUAL
      {
          $$ = ast_make_node("rlop");
          ast_add_child($$, ast_make_leaf("", "no_minimo"));
      }
    ;

return_statement
    : RETURN PONTO_VIRGULA
      {
          $$ = ast_make_node("return");
      }
    | RETURN expression PONTO_VIRGULA
      {
          $$ = ast_make_node("return");
          ast_add_child($$, $2);
      }
    ;

expression_statement
    : function_call PONTO_VIRGULA
      {
          $$ = $1;
      }
    ;

function_call
    : ID PARENTESES_ESQ argument_list_opt PARENTESES_DIR
      {
          $$ = ast_make_node("function call");
          ast_add_child($$, ast_make_leaf("id", $1));
          ast_add_child($$, $3);
          free($1);
      }
    ;

argument_list_opt
    : argument_list
      {
          $$ = $1;
      }
    | /* empty */
      {
          $$ = ast_make_node("argument list");
      }
    ;

argument_list
    : expression
      {
          $$ = ast_make_node("argument list");
          ast_add_child($$, $1);
      }
    | argument_list VIRGULA expression
      {
          ast_add_child($1, $3);
          $$ = $1;
      }
    ;

block
    : CHAVES_ESQ statement_list CHAVES_DIR
      {
          $$ = $2;
      }
    ;

expression
    : expression OP_SOMA expression
      {
          $$ = ast_make_node("add");
          ast_add_child($$, $1);
          ast_add_child($$, $3);
      }
    | expression OP_SUB expression
      {
          $$ = ast_make_node("sub");
          ast_add_child($$, $1);
          ast_add_child($$, $3);
      }
    | expression OP_MULT expression
      {
          $$ = ast_make_node("mul");
          ast_add_child($$, $1);
          ast_add_child($$, $3);
      }
    | expression OP_DIV expression
      {
          $$ = ast_make_node("div");
          ast_add_child($$, $1);
          ast_add_child($$, $3);
      }
    | PARENTESES_ESQ expression PARENTESES_DIR
      {
          $$ = $2;
      }
    | location
      {
          $$ = $1;
      }
    | function_call
      {
          $$ = $1;
      }
    | INTEGER
      {
          $$ = ast_make_leaf("", $1);
          free($1);
      }
    | FLOAT
      {
          $$ = ast_make_leaf("", $1);
          free($1);
      }
    | STRING
      {
          $$ = ast_make_leaf("", $1);
          free($1);
      }
    | LITERAL_CHAR
      {
          $$ = ast_make_leaf("", $1);
          free($1);
      }
    ;

%%

void yyerror(const char *msg) {
    fprintf(stderr, "Erro sintatico na linha %d: %s\n", yylineno, msg);
}

int main(int argc, char **argv) {
    int result;
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror(argv[1]);
            return 1;
        }
    }
    result = yyparse();
    if (result == 0 && g_root) {
        printf("Arvore sintatica:\n");
        ast_print(g_root, 1);
    }
    ast_free(g_root);
    if (yyin && yyin != stdin) {
        fclose(yyin);
    }
    return result;
}
