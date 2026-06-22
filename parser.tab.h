/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 111 "parser.y"

typedef struct ASTNode ASTNode;

#line 53 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    VOID_KEYWORD = 261,            /* VOID_KEYWORD  */
    FUNCTION_KEYWORD = 262,        /* FUNCTION_KEYWORD  */
    INT_KEYWORD = 263,             /* INT_KEYWORD  */
    FLOAT_KEYWORD = 264,           /* FLOAT_KEYWORD  */
    CHAR_KEYWORD = 265,            /* CHAR_KEYWORD  */
    RETURN = 266,                  /* RETURN  */
    OP_IGUALDADE = 267,            /* OP_IGUALDADE  */
    OP_DIFERENTE = 268,            /* OP_DIFERENTE  */
    OP_MENOR = 269,                /* OP_MENOR  */
    OP_MAIOR = 270,                /* OP_MAIOR  */
    OP_MENOR_IGUAL = 271,          /* OP_MENOR_IGUAL  */
    OP_MAIOR_IGUAL = 272,          /* OP_MAIOR_IGUAL  */
    OP_SOMA = 273,                 /* OP_SOMA  */
    OP_SUB = 274,                  /* OP_SUB  */
    OP_MULT = 275,                 /* OP_MULT  */
    OP_DIV = 276,                  /* OP_DIV  */
    OP_ATRIBUICAO = 277,           /* OP_ATRIBUICAO  */
    PONTO_VIRGULA = 278,           /* PONTO_VIRGULA  */
    VIRGULA = 279,                 /* VIRGULA  */
    PARENTESES_ESQ = 280,          /* PARENTESES_ESQ  */
    PARENTESES_DIR = 281,          /* PARENTESES_DIR  */
    CHAVES_ESQ = 282,              /* CHAVES_ESQ  */
    CHAVES_DIR = 283,              /* CHAVES_DIR  */
    COLCHETE_ESQ = 284,            /* COLCHETE_ESQ  */
    COLCHETE_DIR = 285,            /* COLCHETE_DIR  */
    ID = 286,                      /* ID  */
    INTEGER = 287,                 /* INTEGER  */
    FLOAT = 288,                   /* FLOAT  */
    STRING = 289,                  /* STRING  */
    LITERAL_CHAR = 290             /* LITERAL_CHAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 115 "parser.y"

    char *str;
    ASTNode *node;

#line 110 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
