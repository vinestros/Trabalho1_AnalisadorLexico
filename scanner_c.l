%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
%}

%option noyywrap
%option yylineno

DIGITO           [0-9]
LETRA            [a-zA-Z_]
ID_TOKEN         {LETRA}({LETRA}|{DIGITO})*
INTEIRO          {DIGITO}+
FLOAT_NUM        {DIGITO}+\.{DIGITO}*
COMENTARIO_LINHA \/\/[^\n]*
COMENTARIO_BLOCO \/\*([^*]|\*+[^*/])*\*+\/
STRING_LITERAL   \"[^"]*\"
CHAR_LITERAL     '[^']'

%%
[ \t\r]+              { /* ignora espacos */ }
\n                    { /* yylineno atualizado automaticamente */ }

{COMENTARIO_LINHA}    { /* ignora comentario de linha */ }
{COMENTARIO_BLOCO}    { /* ignora comentario de bloco */ }

"prove"               { return IF; }
"se_ruim"             { return ELSE; }
"cozinhando"          { return WHILE; }
"medida"              { return INT_KEYWORD; }
"liquido"             { return FLOAT_KEYWORD; }
"tempero"             { return CHAR_KEYWORD; }
"sirva"               { return RETURN; }
"vazio"               { return VOID_KEYWORD; }
"receita"             { return FUNCTION_KEYWORD; }

{FLOAT_NUM}           { yylval.str = strdup(yytext); return FLOAT; }
{INTEIRO}             { yylval.str = strdup(yytext); return INTEGER; }
{STRING_LITERAL}      { yylval.str = strdup(yytext); return STRING; }
{CHAR_LITERAL}        { yylval.str = strdup(yytext); return LITERAL_CHAR; }

"se_for"              { return OP_IGUALDADE; }
"se_nao_for"          { return OP_DIFERENTE; }
"no_maximo"           { return OP_MENOR_IGUAL; }
"no_minimo"           { return OP_MAIOR_IGUAL; }
"menos_que"           { return OP_MENOR; }
"mais_que"            { return OP_MAIOR; }
"adiciona"            { return OP_SOMA; }
"tira"                { return OP_SUB; }
"vezes"               { return OP_MULT; }
"fatiado_por"         { return OP_DIV; }
"vira"                { return OP_ATRIBUICAO; }

{ID_TOKEN}            { yylval.str = strdup(yytext); return ID; }

";"                   { return PONTO_VIRGULA; }
","                   { return VIRGULA; }
"("                   { return PARENTESES_ESQ; }
")"                   { return PARENTESES_DIR; }
"{"                   { return CHAVES_ESQ; }
"}"                   { return CHAVES_DIR; }
"["                   { return COLCHETE_ESQ; }
"]"                   { return COLCHETE_DIR; }

.                     {
                          fprintf(stderr, "Erro lexico na linha %d: caractere inesperado '%s'\n", yylineno, yytext);
                          return yytext[0];
                      }
%%
