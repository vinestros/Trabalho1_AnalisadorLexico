/* Seção de Definições em C */
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Enumeração de Tokens Refinada */
typedef enum {
    T_EOF = 0,

    // Palavras-chave
    T_IF = 258, 
    T_ELSE, 
    T_WHILE, 
    T_VOID_KEYWORD, 
    T_FUNCTION_KEYWORD,

    T_INT_KEYWORD, 
    T_FLOAT_KEYWORD, 
    T_CHAR_KEYWORD,
    T_RETURN,

    // Identificadores e Literais
    T_ID,
    T_INTEGER,
    T_FLOAT,
    T_STRING,
    T_LITERAL_CHAR,

    // Operadores
    T_OP_IGUALDADE, 
    T_OP_DIFERENTE, 
    T_OP_MENOR, 
    T_OP_MAIOR, 
    T_OP_MENOR_IGUAL,
    T_OP_MAIOR_IGUAL, 
    T_OP_SOMA, 
    T_OP_SUB, 
    T_OP_MULT, 
    T_OP_DIV, 
    T_OP_ATRIBUICAO,

    // Separadores
    T_PONTO_VIRGULA, 
    T_VIRGULA, 
    T_PARENTESES_ESQ, 
    T_PARENTESES_DIR,
    T_CHAVES_ESQ, 
    T_CHAVES_DIR, 
    T_COLCHETE_ESQ, 
    T_COLCHETE_DIR, 

    // Erro
    T_UNKNOWN
} TokenType;

int yylval;

#define MAX_SYMBOLS 100
char *symbol_table[MAX_SYMBOLS];
int symbol_count = 0;

int get_symbol_position(const char *id) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i], id) == 0) {
            return i;
        }
    }
    // Adiciona uma verificação para não estourar a tabela de símbolos
    if (symbol_count < MAX_SYMBOLS) {
        symbol_table[symbol_count] = strdup(id);
        return symbol_count++;
    } else {
        fprintf(stderr, "Erro: Tabela de símbolos cheia!\n");
        return -1; // Retorna um índice inválido
    }
}
%}

/* Opções do Flex: noyywrap evita erro de compilação, yylineno liga o contador automático de linhas */
%option noyywrap
%option yylineno

/* Definições de Expressões Regulares (apelidos) */
DIGITO         [0-9]
LETRA          [a-zA-Z_]
ID             {LETRA}({LETRA}|{DIGITO})*
INTEIRO        {DIGITO}+
FLOAT          {DIGITO}+\.{DIGITO}*
COMENTARIO_LINHA \/\/[^\n]*
COMENTARIO_BLOCO \/\*([^*]|\*+[^*/])*\*+\/
STRING_LITERAL \"[^"]*\"
CHAR_LITERAL   '[^']'

/* Seção de Regras */
%%
[ \t]+         { /* Ignorar espaços em branco e tabulações */ }
\n             { /* Ignora nova linha, yylineno incrementa sozinho */ }

{COMENTARIO_LINHA} { /* Ignora comentário de linha */ }
{COMENTARIO_BLOCO} { /* Ignora comentário de bloco */ }

"prove"        { return T_IF; }
"se_ruim"      { return T_ELSE; }
"cozinhando"   { return T_WHILE; }
"medida"       { return T_INT_KEYWORD; }
"liquido"      { return T_FLOAT_KEYWORD; }
"tempero"      { return T_CHAR_KEYWORD; }
"sirva"        { return T_RETURN; }
"vazio"        { return T_VOID_KEYWORD; }
"receita"      { return T_FUNCTION_KEYWORD; }

{INTEIRO}      { yylval = atoi(yytext); return T_INTEGER; }
{FLOAT}        { return T_FLOAT; }
{STRING_LITERAL} { return T_STRING; }
{CHAR_LITERAL} { return T_LITERAL_CHAR; }

{ID}           { yylval = get_symbol_position(yytext); if (yylval != -1) return T_ID; }

"se_for"           { return T_OP_IGUALDADE; }
"se_nao_for"           { return T_OP_DIFERENTE; }
"no_maximo"           { return T_OP_MENOR_IGUAL; }
"no_minimo"           { return T_OP_MAIOR_IGUAL; }
"menos_que"            { return T_OP_MENOR; }
"mais_que"            { return T_OP_MAIOR; }
"adiciona"            { return T_OP_SOMA; }
"tira"            { return T_OP_SUB; }
"vezes"            { return T_OP_MULT; }
"fatiado_por"            { return T_OP_DIV; }
"vira"            { return T_OP_ATRIBUICAO; }

";"            { return T_PONTO_VIRGULA; }
","            { return T_VIRGULA; }
"("            { return T_PARENTESES_ESQ; }
")"            { return T_PARENTESES_DIR; }
"{"            { return T_CHAVES_ESQ; }
"}"            { return T_CHAVES_DIR; }
"["            { return T_COLCHETE_ESQ; }
"]"            { return T_COLCHETE_DIR; }

.              {
                   fprintf(stderr, "\nErro Léxico na linha %d: Caractere inesperado '%s'\n", yylineno, yytext);
                   return T_UNKNOWN;
               }
%%

/* Seção de Código do Usuário */
int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror(argv[1]);
            return 1;
        }
    } else {
        yyin = stdin;
    }

    printf("Sequência de Tokens:\n");

    int token_id;
    while ((token_id = yylex())) {
        switch (token_id) {
            // Palavras-chave
            case T_IF:            printf("<if> "); break;
            case T_ELSE:          printf("<else> "); break;
            case T_WHILE:         printf("<while> "); break;
            case T_INT_KEYWORD:   printf("<int> "); break;
            case T_FLOAT_KEYWORD: printf("<float> "); break;
            case T_RETURN:        printf("<return> "); break;
            case T_CHAR_KEYWORD:  printf("<char> "); break;

            // Identificadores e Literais
            case T_ID:            printf("<id, %d> ", yylval); break;
            case T_INTEGER:       printf("<num, %d> ", yylval); break;
            case T_FLOAT:         printf("<float_val, %s> ", yytext); break;
            case T_STRING:        printf("<str, %s> ", yytext); break;
            case T_LITERAL_CHAR:  printf("<char_val, %s> ", yytext); break;

            // Operadores
            case T_OP_IGUALDADE:  printf("<==> "); break;
            case T_OP_DIFERENTE:  printf("<!=> "); break;
            case T_OP_MENOR:      printf("<<> "); break;
            case T_OP_MAIOR:      printf("<>> "); break;
            case T_OP_MENOR_IGUAL:printf("<<=> "); break;
            case T_OP_MAIOR_IGUAL:printf("<>=> "); break;
            case T_OP_SOMA:       printf("<+> "); break;
            case T_OP_SUB:        printf("<-> "); break;
            case T_OP_MULT:       printf("<*> "); break;
            case T_OP_DIV:        printf("</> "); break;
            case T_OP_ATRIBUICAO: printf("<=> "); break;

            // Separadores
            case T_PONTO_VIRGULA: printf("<;> "); break;
            case T_VIRGULA:       printf("<,> "); break;
            case T_PARENTESES_ESQ:printf("<(> "); break;
            case T_PARENTESES_DIR:printf("<)> "); break;
            case T_CHAVES_ESQ:    printf("<{> "); break;
            case T_CHAVES_DIR:    printf("<}> "); break;
            case T_COLCHETE_ESQ:  printf("<[> "); break;
            case T_COLCHETE_DIR:  printf("<]> "); break;

            case T_UNKNOWN:
                break;
            default:
                break;
        }
    }

    printf("\n\n--- Tabela de Símbolos Final ---\n");
    printf("Posição | Identificador\n");
    printf("-----------------------------\n");
    for (int i = 0; i < symbol_count; i++) {
        printf("%-7d | %s\n", i, symbol_table[i]);
    }
    printf("-----------------------------\n\n");

    for (int i = 0; i < symbol_count; i++) {
        free(symbol_table[i]);
    }
    
    if (yyin != stdin) {
        fclose(yyin);
    }

    return 0;
}
