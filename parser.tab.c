/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 181 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_VOID_KEYWORD = 6,               /* VOID_KEYWORD  */
  YYSYMBOL_FUNCTION_KEYWORD = 7,           /* FUNCTION_KEYWORD  */
  YYSYMBOL_INT_KEYWORD = 8,                /* INT_KEYWORD  */
  YYSYMBOL_FLOAT_KEYWORD = 9,              /* FLOAT_KEYWORD  */
  YYSYMBOL_CHAR_KEYWORD = 10,              /* CHAR_KEYWORD  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_OP_IGUALDADE = 12,              /* OP_IGUALDADE  */
  YYSYMBOL_OP_DIFERENTE = 13,              /* OP_DIFERENTE  */
  YYSYMBOL_OP_MENOR = 14,                  /* OP_MENOR  */
  YYSYMBOL_OP_MAIOR = 15,                  /* OP_MAIOR  */
  YYSYMBOL_OP_MENOR_IGUAL = 16,            /* OP_MENOR_IGUAL  */
  YYSYMBOL_OP_MAIOR_IGUAL = 17,            /* OP_MAIOR_IGUAL  */
  YYSYMBOL_OP_SOMA = 18,                   /* OP_SOMA  */
  YYSYMBOL_OP_SUB = 19,                    /* OP_SUB  */
  YYSYMBOL_OP_MULT = 20,                   /* OP_MULT  */
  YYSYMBOL_OP_DIV = 21,                    /* OP_DIV  */
  YYSYMBOL_OP_ATRIBUICAO = 22,             /* OP_ATRIBUICAO  */
  YYSYMBOL_PONTO_VIRGULA = 23,             /* PONTO_VIRGULA  */
  YYSYMBOL_VIRGULA = 24,                   /* VIRGULA  */
  YYSYMBOL_PARENTESES_ESQ = 25,            /* PARENTESES_ESQ  */
  YYSYMBOL_PARENTESES_DIR = 26,            /* PARENTESES_DIR  */
  YYSYMBOL_CHAVES_ESQ = 27,                /* CHAVES_ESQ  */
  YYSYMBOL_CHAVES_DIR = 28,                /* CHAVES_DIR  */
  YYSYMBOL_COLCHETE_ESQ = 29,              /* COLCHETE_ESQ  */
  YYSYMBOL_COLCHETE_DIR = 30,              /* COLCHETE_DIR  */
  YYSYMBOL_ID = 31,                        /* ID  */
  YYSYMBOL_INTEGER = 32,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 33,                     /* FLOAT  */
  YYSYMBOL_STRING = 34,                    /* STRING  */
  YYSYMBOL_LITERAL_CHAR = 35,              /* LITERAL_CHAR  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_item_list = 38,                 /* item_list  */
  YYSYMBOL_item = 39,                      /* item  */
  YYSYMBOL_statement_list = 40,            /* statement_list  */
  YYSYMBOL_statement = 41,                 /* statement  */
  YYSYMBOL_declaration = 42,               /* declaration  */
  YYSYMBOL_function_declaration = 43,      /* function_declaration  */
  YYSYMBOL_function_return_type = 44,      /* function_return_type  */
  YYSYMBOL_type_spec = 45,                 /* type_spec  */
  YYSYMBOL_parameter_list_opt = 46,        /* parameter_list_opt  */
  YYSYMBOL_parameter_list = 47,            /* parameter_list  */
  YYSYMBOL_parameter = 48,                 /* parameter  */
  YYSYMBOL_assignment = 49,                /* assignment  */
  YYSYMBOL_location = 50,                  /* location  */
  YYSYMBOL_if_statement = 51,              /* if_statement  */
  YYSYMBOL_while_statement = 52,           /* while_statement  */
  YYSYMBOL_condition = 53,                 /* condition  */
  YYSYMBOL_relop = 54,                     /* relop  */
  YYSYMBOL_return_statement = 55,          /* return_statement  */
  YYSYMBOL_expression_statement = 56,      /* expression_statement  */
  YYSYMBOL_function_call = 57,             /* function_call  */
  YYSYMBOL_argument_list_opt = 58,         /* argument_list_opt  */
  YYSYMBOL_argument_list = 59,             /* argument_list  */
  YYSYMBOL_block = 60,                     /* block  */
  YYSYMBOL_expression = 61                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   145,   145,   154,   160,   166,   170,   177,   183,   189,
     193,   197,   201,   205,   209,   213,   220,   227,   240,   252,
     256,   263,   267,   271,   278,   283,   289,   294,   302,   312,
     321,   326,   336,   342,   352,   361,   371,   376,   381,   386,
     391,   396,   404,   408,   416,   423,   433,   438,   444,   449,
     457,   464,   470,   476,   482,   488,   492,   496,   500,   505,
     510,   515
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "VOID_KEYWORD", "FUNCTION_KEYWORD", "INT_KEYWORD", "FLOAT_KEYWORD",
  "CHAR_KEYWORD", "RETURN", "OP_IGUALDADE", "OP_DIFERENTE", "OP_MENOR",
  "OP_MAIOR", "OP_MENOR_IGUAL", "OP_MAIOR_IGUAL", "OP_SOMA", "OP_SUB",
  "OP_MULT", "OP_DIV", "OP_ATRIBUICAO", "PONTO_VIRGULA", "VIRGULA",
  "PARENTESES_ESQ", "PARENTESES_DIR", "CHAVES_ESQ", "CHAVES_DIR",
  "COLCHETE_ESQ", "COLCHETE_DIR", "ID", "INTEGER", "FLOAT", "STRING",
  "LITERAL_CHAR", "$accept", "program", "item_list", "item",
  "statement_list", "statement", "declaration", "function_declaration",
  "function_return_type", "type_spec", "parameter_list_opt",
  "parameter_list", "parameter", "assignment", "location", "if_statement",
  "while_statement", "condition", "relop", "return_statement",
  "expression_statement", "function_call", "argument_list_opt",
  "argument_list", "block", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-60)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -60,     4,     3,   -60,    -3,     6,    11,   -60,   -60,   -60,
      -7,   -60,   -20,   -60,   -60,   -60,   -60,    -2,    24,    27,
     -60,   -60,   -60,   -60,    29,   -60,    49,    49,   -60,    23,
     -60,   -60,    49,   -60,   -60,   -60,   -60,   -60,   -60,    67,
      48,    49,    49,    19,   -60,    49,   -60,    44,    80,    45,
      25,    84,    49,    49,    49,    49,   -60,   -60,   -60,    52,
      65,    88,    42,   -60,    49,    88,    87,   -60,   -60,   -60,
     -60,   -60,   -60,    49,    87,   103,   -60,    18,    18,   -60,
     -60,   -60,    49,   -60,    47,   111,    88,   -60,    85,    91,
      94,   -60,    88,    96,    87,   -60,    87,   103,   -60,   -60,
     -60,   -60
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,    21,    22,    23,
       0,     8,    30,     3,     5,     9,     6,     0,     0,     0,
      11,    12,    13,    14,     0,    15,     0,     0,    20,     0,
      19,    42,     0,    58,    59,    60,    61,    56,    57,     0,
       0,    47,     0,     0,    10,     0,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    50,     7,     0,
      46,    48,     0,    16,     0,    29,     0,    36,    37,    38,
      39,    40,    41,     0,     0,    25,    55,    51,    52,    53,
      54,    45,     0,    31,     0,    32,    35,    34,     0,     0,
      24,    26,    49,     0,     0,    28,     0,     0,    17,    33,
      18,    27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -60,   -60,   -60,    81,   -60,   -60,   -60,    -6,
     -60,   -60,    26,   -60,     0,   -60,   -60,    93,   -60,   -60,
     -60,     1,   -60,   -60,   -59,    -9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    13,    40,    14,    15,    16,    29,    17,
      89,    90,    91,    18,    37,    20,    21,    47,    73,    22,
      23,    38,    59,    60,    25,    48
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,    39,    19,    24,     3,    41,     4,    85,     5,    42,
       6,     7,     8,     9,    10,    87,    31,    28,    32,     7,
       8,     9,    26,    51,    12,    33,    34,    35,    36,    43,
      11,    27,    61,    62,    12,    99,    65,   100,    54,    55,
      19,    24,    63,    77,    78,    79,    80,    44,    64,    45,
      75,     4,    46,     5,    50,    84,     7,     8,     9,    10,
      52,    53,    54,    55,    86,    52,    53,    54,    55,    88,
      66,    74,    83,    92,    32,    11,    57,    93,    81,    12,
      12,    33,    34,    35,    36,    52,    53,    54,    55,    82,
      56,    88,    67,    68,    69,    70,    71,    72,    52,    53,
      54,    55,    52,    53,    54,    55,    52,    53,    54,    55,
      76,     7,     8,     9,    11,    94,    95,    96,    97,    98,
      49,    58,     0,   101
};

static const yytype_int8 yycheck[] =
{
       6,    10,     2,     2,     0,    25,     3,    66,     5,    29,
       7,     8,     9,    10,    11,    74,    23,     6,    25,     8,
       9,    10,    25,    32,    31,    32,    33,    34,    35,    31,
      27,    25,    41,    42,    31,    94,    45,    96,    20,    21,
      40,    40,    23,    52,    53,    54,    55,    23,    29,    22,
      25,     3,    23,     5,    31,    64,     8,     9,    10,    11,
      18,    19,    20,    21,    73,    18,    19,    20,    21,    75,
      26,    26,    30,    82,    25,    27,    28,    30,    26,    31,
      31,    32,    33,    34,    35,    18,    19,    20,    21,    24,
      23,    97,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    18,    19,    20,    21,    18,    19,    20,    21,
      26,     8,     9,    10,    27,     4,    31,    26,    24,    23,
      27,    40,    -1,    97
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    37,    38,     0,     3,     5,     7,     8,     9,    10,
      11,    27,    31,    39,    41,    42,    43,    45,    49,    50,
      51,    52,    55,    56,    57,    60,    25,    25,     6,    44,
      45,    23,    25,    32,    33,    34,    35,    50,    57,    61,
      40,    25,    29,    31,    23,    22,    23,    53,    61,    53,
      31,    61,    18,    19,    20,    21,    23,    28,    41,    58,
      59,    61,    61,    23,    29,    61,    26,    12,    13,    14,
      15,    16,    17,    54,    26,    25,    26,    61,    61,    61,
      61,    26,    24,    30,    61,    60,    61,    60,    45,    46,
      47,    48,    61,    30,     4,    31,    26,    24,    23,    60,
      60,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    40,    40,    41,
      41,    41,    41,    41,    41,    41,    42,    42,    43,    44,
      44,    45,    45,    45,    46,    46,    47,    47,    48,    49,
      50,    50,    51,    51,    52,    53,    54,    54,    54,    54,
      54,    54,    55,    55,    56,    57,    58,    58,    59,    59,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     2,     0,     1,
       2,     1,     1,     1,     1,     1,     3,     6,     7,     1,
       1,     1,     1,     1,     1,     0,     1,     3,     2,     3,
       1,     4,     5,     7,     5,     3,     1,     1,     1,     1,
       1,     1,     2,     3,     2,     4,     1,     0,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: item_list  */
#line 146 "parser.y"
      {
          (yyval.node) = ast_make_node("program");
          ast_add_child((yyval.node), (yyvsp[0].node));
          g_root = (yyval.node);
      }
#line 1311 "parser.tab.c"
    break;

  case 3: /* item_list: item_list item  */
#line 155 "parser.y"
      {
          ast_add_child((yyvsp[-1].node), (yyvsp[0].node));
          (yyval.node) = (yyvsp[-1].node);
      }
#line 1320 "parser.tab.c"
    break;

  case 4: /* item_list: %empty  */
#line 160 "parser.y"
      {
          (yyval.node) = ast_make_node("statement list");
      }
#line 1328 "parser.tab.c"
    break;

  case 5: /* item: statement  */
#line 167 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1336 "parser.tab.c"
    break;

  case 6: /* item: function_declaration  */
#line 171 "parser.y"
      {
          (yyval.node) = ast_wrap_statement((yyvsp[0].node));
      }
#line 1344 "parser.tab.c"
    break;

  case 7: /* statement_list: statement_list statement  */
#line 178 "parser.y"
      {
          ast_add_child((yyvsp[-1].node), (yyvsp[0].node));
          (yyval.node) = (yyvsp[-1].node);
      }
#line 1353 "parser.tab.c"
    break;

  case 8: /* statement_list: %empty  */
#line 183 "parser.y"
      {
          (yyval.node) = ast_make_node("statement list");
      }
#line 1361 "parser.tab.c"
    break;

  case 9: /* statement: declaration  */
#line 190 "parser.y"
      {
          (yyval.node) = ast_wrap_statement((yyvsp[0].node));
      }
#line 1369 "parser.tab.c"
    break;

  case 10: /* statement: assignment PONTO_VIRGULA  */
#line 194 "parser.y"
      {
          (yyval.node) = ast_wrap_statement((yyvsp[-1].node));
      }
#line 1377 "parser.tab.c"
    break;

  case 11: /* statement: if_statement  */
#line 198 "parser.y"
      {
          (yyval.node) = ast_wrap_statement((yyvsp[0].node));
      }
#line 1385 "parser.tab.c"
    break;

  case 12: /* statement: while_statement  */
#line 202 "parser.y"
      {
          (yyval.node) = ast_wrap_statement((yyvsp[0].node));
      }
#line 1393 "parser.tab.c"
    break;

  case 13: /* statement: return_statement  */
#line 206 "parser.y"
      {
          (yyval.node) = ast_wrap_statement((yyvsp[0].node));
      }
#line 1401 "parser.tab.c"
    break;

  case 14: /* statement: expression_statement  */
#line 210 "parser.y"
      {
          (yyval.node) = ast_wrap_statement((yyvsp[0].node));
      }
#line 1409 "parser.tab.c"
    break;

  case 15: /* statement: block  */
#line 214 "parser.y"
      {
          (yyval.node) = ast_wrap_statement((yyvsp[0].node));
      }
#line 1417 "parser.tab.c"
    break;

  case 16: /* declaration: type_spec ID PONTO_VIRGULA  */
#line 221 "parser.y"
      {
          (yyval.node) = ast_make_node("declaration");
          ast_add_child((yyval.node), (yyvsp[-2].node));
          ast_add_child((yyval.node), ast_make_leaf("", (yyvsp[-1].str)));
          free((yyvsp[-1].str));
      }
#line 1428 "parser.tab.c"
    break;

  case 17: /* declaration: type_spec ID COLCHETE_ESQ expression COLCHETE_DIR PONTO_VIRGULA  */
#line 228 "parser.y"
      {
          ASTNode *vector_node = ast_make_node("vector size");
          (yyval.node) = ast_make_node("declaration");
          ast_add_child((yyval.node), (yyvsp[-5].node));
          ast_add_child((yyval.node), ast_make_leaf("", (yyvsp[-4].str)));
          ast_add_child(vector_node, (yyvsp[-2].node));
          ast_add_child((yyval.node), vector_node);
          free((yyvsp[-4].str));
      }
#line 1442 "parser.tab.c"
    break;

  case 18: /* function_declaration: FUNCTION_KEYWORD function_return_type ID PARENTESES_ESQ parameter_list_opt PARENTESES_DIR block  */
#line 241 "parser.y"
      {
          (yyval.node) = ast_make_node("function declaration");
          ast_add_child((yyval.node), (yyvsp[-5].node));
          ast_add_child((yyval.node), ast_make_leaf("id", (yyvsp[-4].str)));
          ast_add_child((yyval.node), (yyvsp[-2].node));
          ast_add_child((yyval.node), (yyvsp[0].node));
          free((yyvsp[-4].str));
      }
#line 1455 "parser.tab.c"
    break;

  case 19: /* function_return_type: type_spec  */
#line 253 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1463 "parser.tab.c"
    break;

  case 20: /* function_return_type: VOID_KEYWORD  */
#line 257 "parser.y"
      {
          (yyval.node) = ast_make_node("VOID");
      }
#line 1471 "parser.tab.c"
    break;

  case 21: /* type_spec: INT_KEYWORD  */
#line 264 "parser.y"
      {
          (yyval.node) = ast_make_node("INT");
      }
#line 1479 "parser.tab.c"
    break;

  case 22: /* type_spec: FLOAT_KEYWORD  */
#line 268 "parser.y"
      {
          (yyval.node) = ast_make_node("FLOAT");
      }
#line 1487 "parser.tab.c"
    break;

  case 23: /* type_spec: CHAR_KEYWORD  */
#line 272 "parser.y"
      {
          (yyval.node) = ast_make_node("CHAR");
      }
#line 1495 "parser.tab.c"
    break;

  case 24: /* parameter_list_opt: parameter_list  */
#line 279 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1503 "parser.tab.c"
    break;

  case 25: /* parameter_list_opt: %empty  */
#line 283 "parser.y"
      {
          (yyval.node) = ast_make_node("parameter list");
      }
#line 1511 "parser.tab.c"
    break;

  case 26: /* parameter_list: parameter  */
#line 290 "parser.y"
      {
          (yyval.node) = ast_make_node("parameter list");
          ast_add_child((yyval.node), (yyvsp[0].node));
      }
#line 1520 "parser.tab.c"
    break;

  case 27: /* parameter_list: parameter_list VIRGULA parameter  */
#line 295 "parser.y"
      {
          ast_add_child((yyvsp[-2].node), (yyvsp[0].node));
          (yyval.node) = (yyvsp[-2].node);
      }
#line 1529 "parser.tab.c"
    break;

  case 28: /* parameter: type_spec ID  */
#line 303 "parser.y"
      {
          (yyval.node) = ast_make_node("parameter");
          ast_add_child((yyval.node), (yyvsp[-1].node));
          ast_add_child((yyval.node), ast_make_leaf("id", (yyvsp[0].str)));
          free((yyvsp[0].str));
      }
#line 1540 "parser.tab.c"
    break;

  case 29: /* assignment: location OP_ATRIBUICAO expression  */
#line 313 "parser.y"
      {
          (yyval.node) = ast_make_node("attribution");
          ast_add_child((yyval.node), (yyvsp[-2].node));
          ast_add_child((yyval.node), (yyvsp[0].node));
      }
#line 1550 "parser.tab.c"
    break;

  case 30: /* location: ID  */
#line 322 "parser.y"
      {
          (yyval.node) = ast_make_leaf("", (yyvsp[0].str));
          free((yyvsp[0].str));
      }
#line 1559 "parser.tab.c"
    break;

  case 31: /* location: ID COLCHETE_ESQ expression COLCHETE_DIR  */
#line 327 "parser.y"
      {
          (yyval.node) = ast_make_node("vector access");
          ast_add_child((yyval.node), ast_make_leaf("id", (yyvsp[-3].str)));
          ast_add_child((yyval.node), (yyvsp[-1].node));
          free((yyvsp[-3].str));
      }
#line 1570 "parser.tab.c"
    break;

  case 32: /* if_statement: IF PARENTESES_ESQ condition PARENTESES_DIR block  */
#line 337 "parser.y"
      {
          (yyval.node) = ast_make_node("if statement");
          ast_add_child((yyval.node), (yyvsp[-2].node));
          ast_add_child((yyval.node), (yyvsp[0].node));
      }
#line 1580 "parser.tab.c"
    break;

  case 33: /* if_statement: IF PARENTESES_ESQ condition PARENTESES_DIR block ELSE block  */
#line 343 "parser.y"
      {
          (yyval.node) = ast_make_node("if statement");
          ast_add_child((yyval.node), (yyvsp[-4].node));
          ast_add_child((yyval.node), (yyvsp[-2].node));
          ast_add_child((yyval.node), (yyvsp[0].node));
      }
#line 1591 "parser.tab.c"
    break;

  case 34: /* while_statement: WHILE PARENTESES_ESQ condition PARENTESES_DIR block  */
#line 353 "parser.y"
      {
          (yyval.node) = ast_make_node("while statement");
          ast_add_child((yyval.node), (yyvsp[-2].node));
          ast_add_child((yyval.node), (yyvsp[0].node));
      }
#line 1601 "parser.tab.c"
    break;

  case 35: /* condition: expression relop expression  */
#line 362 "parser.y"
      {
          (yyval.node) = ast_make_node("condition");
          ast_add_child((yyval.node), (yyvsp[-2].node));
          ast_add_child((yyval.node), (yyvsp[-1].node));
          ast_add_child((yyval.node), (yyvsp[0].node));
      }
#line 1612 "parser.tab.c"
    break;

  case 36: /* relop: OP_IGUALDADE  */
#line 372 "parser.y"
      {
          (yyval.node) = ast_make_node("rlop");
          ast_add_child((yyval.node), ast_make_leaf("", "se_for"));
      }
#line 1621 "parser.tab.c"
    break;

  case 37: /* relop: OP_DIFERENTE  */
#line 377 "parser.y"
      {
          (yyval.node) = ast_make_node("rlop");
          ast_add_child((yyval.node), ast_make_leaf("", "se_nao_for"));
      }
#line 1630 "parser.tab.c"
    break;

  case 38: /* relop: OP_MENOR  */
#line 382 "parser.y"
      {
          (yyval.node) = ast_make_node("rlop");
          ast_add_child((yyval.node), ast_make_leaf("", "menos_que"));
      }
#line 1639 "parser.tab.c"
    break;

  case 39: /* relop: OP_MAIOR  */
#line 387 "parser.y"
      {
          (yyval.node) = ast_make_node("rlop");
          ast_add_child((yyval.node), ast_make_leaf("", "mais_que"));
      }
#line 1648 "parser.tab.c"
    break;

  case 40: /* relop: OP_MENOR_IGUAL  */
#line 392 "parser.y"
      {
          (yyval.node) = ast_make_node("rlop");
          ast_add_child((yyval.node), ast_make_leaf("", "no_maximo"));
      }
#line 1657 "parser.tab.c"
    break;

  case 41: /* relop: OP_MAIOR_IGUAL  */
#line 397 "parser.y"
      {
          (yyval.node) = ast_make_node("rlop");
          ast_add_child((yyval.node), ast_make_leaf("", "no_minimo"));
      }
#line 1666 "parser.tab.c"
    break;

  case 42: /* return_statement: RETURN PONTO_VIRGULA  */
#line 405 "parser.y"
      {
          (yyval.node) = ast_make_node("return");
      }
#line 1674 "parser.tab.c"
    break;

  case 43: /* return_statement: RETURN expression PONTO_VIRGULA  */
#line 409 "parser.y"
      {
          (yyval.node) = ast_make_node("return");
          ast_add_child((yyval.node), (yyvsp[-1].node));
      }
#line 1683 "parser.tab.c"
    break;

  case 44: /* expression_statement: function_call PONTO_VIRGULA  */
#line 417 "parser.y"
      {
          (yyval.node) = (yyvsp[-1].node);
      }
#line 1691 "parser.tab.c"
    break;

  case 45: /* function_call: ID PARENTESES_ESQ argument_list_opt PARENTESES_DIR  */
#line 424 "parser.y"
      {
          (yyval.node) = ast_make_node("function call");
          ast_add_child((yyval.node), ast_make_leaf("id", (yyvsp[-3].str)));
          ast_add_child((yyval.node), (yyvsp[-1].node));
          free((yyvsp[-3].str));
      }
#line 1702 "parser.tab.c"
    break;

  case 46: /* argument_list_opt: argument_list  */
#line 434 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1710 "parser.tab.c"
    break;

  case 47: /* argument_list_opt: %empty  */
#line 438 "parser.y"
      {
          (yyval.node) = ast_make_node("argument list");
      }
#line 1718 "parser.tab.c"
    break;

  case 48: /* argument_list: expression  */
#line 445 "parser.y"
      {
          (yyval.node) = ast_make_node("argument list");
          ast_add_child((yyval.node), (yyvsp[0].node));
      }
#line 1727 "parser.tab.c"
    break;

  case 49: /* argument_list: argument_list VIRGULA expression  */
#line 450 "parser.y"
      {
          ast_add_child((yyvsp[-2].node), (yyvsp[0].node));
          (yyval.node) = (yyvsp[-2].node);
      }
#line 1736 "parser.tab.c"
    break;

  case 50: /* block: CHAVES_ESQ statement_list CHAVES_DIR  */
#line 458 "parser.y"
      {
          (yyval.node) = (yyvsp[-1].node);
      }
#line 1744 "parser.tab.c"
    break;

  case 51: /* expression: expression OP_SOMA expression  */
#line 465 "parser.y"
      {
          (yyval.node) = ast_make_node("add");
          ast_add_child((yyval.node), (yyvsp[-2].node));
          ast_add_child((yyval.node), (yyvsp[0].node));
      }
#line 1754 "parser.tab.c"
    break;

  case 52: /* expression: expression OP_SUB expression  */
#line 471 "parser.y"
      {
          (yyval.node) = ast_make_node("sub");
          ast_add_child((yyval.node), (yyvsp[-2].node));
          ast_add_child((yyval.node), (yyvsp[0].node));
      }
#line 1764 "parser.tab.c"
    break;

  case 53: /* expression: expression OP_MULT expression  */
#line 477 "parser.y"
      {
          (yyval.node) = ast_make_node("mul");
          ast_add_child((yyval.node), (yyvsp[-2].node));
          ast_add_child((yyval.node), (yyvsp[0].node));
      }
#line 1774 "parser.tab.c"
    break;

  case 54: /* expression: expression OP_DIV expression  */
#line 483 "parser.y"
      {
          (yyval.node) = ast_make_node("div");
          ast_add_child((yyval.node), (yyvsp[-2].node));
          ast_add_child((yyval.node), (yyvsp[0].node));
      }
#line 1784 "parser.tab.c"
    break;

  case 55: /* expression: PARENTESES_ESQ expression PARENTESES_DIR  */
#line 489 "parser.y"
      {
          (yyval.node) = (yyvsp[-1].node);
      }
#line 1792 "parser.tab.c"
    break;

  case 56: /* expression: location  */
#line 493 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1800 "parser.tab.c"
    break;

  case 57: /* expression: function_call  */
#line 497 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1808 "parser.tab.c"
    break;

  case 58: /* expression: INTEGER  */
#line 501 "parser.y"
      {
          (yyval.node) = ast_make_leaf("", (yyvsp[0].str));
          free((yyvsp[0].str));
      }
#line 1817 "parser.tab.c"
    break;

  case 59: /* expression: FLOAT  */
#line 506 "parser.y"
      {
          (yyval.node) = ast_make_leaf("", (yyvsp[0].str));
          free((yyvsp[0].str));
      }
#line 1826 "parser.tab.c"
    break;

  case 60: /* expression: STRING  */
#line 511 "parser.y"
      {
          (yyval.node) = ast_make_leaf("", (yyvsp[0].str));
          free((yyvsp[0].str));
      }
#line 1835 "parser.tab.c"
    break;

  case 61: /* expression: LITERAL_CHAR  */
#line 516 "parser.y"
      {
          (yyval.node) = ast_make_leaf("", (yyvsp[0].str));
          free((yyvsp[0].str));
      }
#line 1844 "parser.tab.c"
    break;


#line 1848 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 522 "parser.y"


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
