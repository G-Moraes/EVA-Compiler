/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "sintatica.y" /* yacc.c:339  */

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <list>
using std::string;
using std::getline;


#define YYSTYPE atributos

using namespace std;

typedef struct Variable{

	string tipo;
	string nome;
	string valor;
} variable;

typedef struct Atributos
{
	string tipo;
	string label;
	string traducao;
} atributos;

typedef struct{

	string implicita; //tradução após conversão
	string nomeVar; //nome da variável
	string varConvertida; //nome da variável que foi convertida
} structAux; //struct auxiliar utilizada para conversões

int valorVar = 0;
int valorTemp = 0;
int valorLoops = 0;
int valorAuxiliar = 0;
int mapAtual = 0; //indica qual contexto está
int tamanho_vetor = 0; //indica o tamanho do vetor atual
int tamanho_linhas = 0;
int tamanho_colunas = 0;
int elementos_matriz;

stack <string> label_vet; //stack para armazenar o nome dos elementos sendo adicionados no vetor
stack <string> tipo_vet; //stack para armazenar o tipo do elemento armazenado no vetor
stack <string> trad_vet; //stack para armazenar a traducao do elemento armazenado no vetor

unordered_map <string, variable> globalTabSym; //tabela de símbolos global
vector <string> tempVector; //vetor de impressão de variáveis em cód. interm.
vector <string> globalTempVector; //vetor de impressão global
stack <int> stackLoops; //pilha de variáveis de controle de loop
stack <string> stackCommands; //pilha que auxilia qual o tipo de loop existem
stack <string> stackVectors;

unordered_map <string, int> map_vetor;
unordered_map <string, int> map_linhas;
unordered_map <string, int> map_colunas;
unordered_map <string, int> pointer_vector;

unordered_map <string, variable> arrayPointerNames;

vector <unordered_map<string, variable>> contextoVariaveis; //pilha de contextos

//funções yacc
int yylex(void);
void yyerror(string);

//função geradora de label
string genLabel();

//funções de conversão
structAux implicitConversion(string tipo0, string tipo1, string nome0, string nome1);
string explicitConversion(string tipo0, string tipo1);

//funções para checar tipos específicos
string isBoolean(string tipo0, string tipo1);
int erroTipo(string tipo0, string tipo1);

//funções para acessar o vetor de variáveis
void addVarToTempVector(string nomeVar);
void addVarToGlobalTempVector(string nomeVar);
void printVector();
void freeVectors();
void printGlobalVector();

//funções de array e matrix
string addElementsToArray(int tamanhoArray, string nomeArray);

//funções para acessar tabela de simbolos
void addMapToStack();
string addVarToTabSym(string nomeGerado, string nomeDado, string conteudoVar, string tipoVar);
string addVarToGlobalTabSym(string nomeGerado, string nomeDado, string conteudoVar, string tipoVar);
variable searchForVariable(string nome);
variable searchForGlobalVariable(string nome);
void checkForVariable(string nome);
void printGlobalVariables();

#line 168 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_MAIN = 258,
    TK_IF = 259,
    TK_ELSE = 260,
    TK_THEN = 261,
    TK_END_LOOP = 262,
    TK_WHILE = 263,
    TK_DO = 264,
    TK_FOR = 265,
    TK_BREAK = 266,
    TK_CONTINUE = 267,
    TK_ENTRADA = 268,
    TK_SAIDA = 269,
    TK_ID = 270,
    TK_DEC_VAR = 271,
    TK_GLOBAL = 272,
    TK_TIPO_INT = 273,
    TK_TIPO_FLOAT = 274,
    TK_TIPO_BOOL = 275,
    TK_TIPO_CHAR = 276,
    TK_TIPO_STRING = 277,
    TK_CONV_FLOAT = 278,
    TK_CONV_INT = 279,
    TK_LE = 280,
    TK_HE = 281,
    TK_EQ = 282,
    TK_DIFF = 283,
    TK_UN_SUM = 284,
    TK_UN_SUB = 285,
    TK_NUN_SUM = 286,
    TK_NUN_SUB = 287,
    TK_NUN_MUL = 288,
    TK_NUN_DIV = 289,
    TK_CHAR = 290,
    TK_FLOAT = 291,
    TK_BOOL = 292,
    TK_NUM = 293,
    TK_STRING = 294,
    TK_FIM = 295,
    TK_ERROR = 296
  };
#endif
/* Tokens.  */
#define TK_MAIN 258
#define TK_IF 259
#define TK_ELSE 260
#define TK_THEN 261
#define TK_END_LOOP 262
#define TK_WHILE 263
#define TK_DO 264
#define TK_FOR 265
#define TK_BREAK 266
#define TK_CONTINUE 267
#define TK_ENTRADA 268
#define TK_SAIDA 269
#define TK_ID 270
#define TK_DEC_VAR 271
#define TK_GLOBAL 272
#define TK_TIPO_INT 273
#define TK_TIPO_FLOAT 274
#define TK_TIPO_BOOL 275
#define TK_TIPO_CHAR 276
#define TK_TIPO_STRING 277
#define TK_CONV_FLOAT 278
#define TK_CONV_INT 279
#define TK_LE 280
#define TK_HE 281
#define TK_EQ 282
#define TK_DIFF 283
#define TK_UN_SUM 284
#define TK_UN_SUB 285
#define TK_NUN_SUM 286
#define TK_NUN_SUB 287
#define TK_NUN_MUL 288
#define TK_NUN_DIV 289
#define TK_CHAR 290
#define TK_FLOAT 291
#define TK_BOOL 292
#define TK_NUM 293
#define TK_STRING 294
#define TK_FIM 295
#define TK_ERROR 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 301 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   1097

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  354

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,     2,     2,     2,    45,     2,
      52,    53,    50,    48,    57,    49,     2,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
      46,    42,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,    44,    55,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   127,   127,   138,   145,   151,   155,   161,   166,   171,
     176,   181,   186,   191,   196,   201,   206,   211,   216,   221,
     226,   232,   244,   256,   265,   275,   284,   291,   308,   339,
     361,   376,   394,   411,   430,   447,   472,   494,   510,   527,
     543,   561,   587,   606,   625,   644,   663,   687,   702,   733,
     755,   775,   795,   816,   836,   863,   882,   901,   920,   940,
     965,   982,  1004,  1025,  1046,  1066,  1071,  1097,  1126,  1145,
    1164,  1183,  1203,  1222,  1241,  1260,  1279,  1303,  1319,  1344,
    1360,  1391,  1413,  1432,  1452,  1472,  1492,  1514,  1535,  1556,
    1576,  1591,  1599,  1608,  1620,  1647,  1674,  1702,  1727,  1752,
    1779,  1805,  1832,  1859,  1873,  1881,  1889,  1900,  1924,  1950,
    1976,  2003,  2030,  2058,  2082,  2106,  2131,  2151,  2170,  2216,
    2261,  2261,  2281,  2281,  2287,  2298,  2319,  2319,  2339,  2339,
    2359,  2359,  2364,  2364,  2369,  2397,  2424,  2439,  2454,  2480,
    2502,  2524,  2548,  2557,  2566,  2591,  2613,  2635,  2658,  2666,
    2674,  2683,  2705,  2728,  2733,  2742,  2751,  2760,  2769,  2777
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_MAIN", "TK_IF", "TK_ELSE", "TK_THEN",
  "TK_END_LOOP", "TK_WHILE", "TK_DO", "TK_FOR", "TK_BREAK", "TK_CONTINUE",
  "TK_ENTRADA", "TK_SAIDA", "TK_ID", "TK_DEC_VAR", "TK_GLOBAL",
  "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_TIPO_BOOL", "TK_TIPO_CHAR",
  "TK_TIPO_STRING", "TK_CONV_FLOAT", "TK_CONV_INT", "TK_LE", "TK_HE",
  "TK_EQ", "TK_DIFF", "TK_UN_SUM", "TK_UN_SUB", "TK_NUN_SUM", "TK_NUN_SUB",
  "TK_NUN_MUL", "TK_NUN_DIV", "TK_CHAR", "TK_FLOAT", "TK_BOOL", "TK_NUM",
  "TK_STRING", "TK_FIM", "TK_ERROR", "'='", "'!'", "'|'", "'&'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'{'", "'}'", "';'",
  "','", "'['", "']'", "$accept", "S", "BLOCO", "BLOCOGLOBAL",
  "BLOCOCONTEXTO", "COMANDOS", "COMANDO", "VETOR", "MATRIZ", "ENTRADA",
  "SAIDA", "ATRIBUICAO", "TRYING", "ATTGLOBAL", "DECLARACAO",
  "ARRAYDECLARATION", "GADECLARATION", "MATRIXDECLARATION",
  "GMDECLARATION", "IF", "$@1", "ELSEE", "$@2", "ELSE", "WHILE", "$@3",
  "DOWHILE", "$@4", "FOR", "$@5", "$@6", "FORMODES", "BREAK", "CONTINUE",
  "E", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    61,    33,   124,    38,    60,    62,    43,    45,
      42,    47,    40,    41,   123,   125,    59,    44,    91,    93
};
# endif

#define YYPACT_NINF -189

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-189)))

#define YYTABLE_NINF -133

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -189,     5,  -189,  -189,     7,     9,   -33,    24,   -22,    12,
    -189,  -189,  -189,    61,   534,   -11,   107,  -189,  -189,  -189,
    -189,  -189,   536,   536,    48,    70,    12,    -2,    83,    86,
     547,    99,    -3,   256,   267,   292,   115,   118,   885,   148,
    -189,  -189,   165,   199,   291,   302,   121,  -189,    52,   166,
     237,   565,   127,    33,  1046,   939,  -189,  -189,  -189,   139,
     193,    -1,  -189,  -189,   154,  -189,  -189,  -189,  -189,  -189,
    -189,   -21,   102,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
    -189,  -189,   184,  1046,   197,  1046,   198,  1046,   203,  1046,
    -189,   111,   204,   327,   338,   167,   536,   576,  1046,   182,
     189,   190,   191,   328,   536,    73,   363,   374,   399,   410,
     224,     1,   642,  -189,  -189,   174,   194,   -22,   161,   201,
     238,   212,  -189,  -189,   223,   230,   249,   249,   310,   310,
     657,   684,   249,   249,   143,   143,  -189,  -189,  -189,  -189,
    -189,  -189,   208,   594,   265,  1046,   269,  1046,   536,   -35,
     -16,  1046,    36,   669,   536,   536,   536,   536,   250,   251,
     252,   696,   270,   273,   274,   279,   350,   536,   308,  1046,
     317,  1046,   318,  1046,   333,  1046,   335,   435,   446,   167,
     536,   605,  1046,   283,   309,   536,   536,   299,   153,    44,
     296,  -189,   161,  -189,   536,   471,   482,    39,   723,  -189,
    -189,    17,  -189,   314,   536,  -189,  -189,  -189,  1046,  1046,
    1046,  1046,   167,   167,   167,   326,   536,   536,   536,   536,
     325,   344,   345,   750,  -189,  -189,  -189,  -189,   208,   623,
     373,  1046,   377,  1046,    80,    50,    67,   777,   507,   518,
     968,   978,   343,   266,   536,    93,   382,   536,   351,  1007,
     388,  1046,   390,  1046,  -189,  -189,  -189,   536,  1046,   361,
     361,   361,   536,  1046,  1046,  1046,  1046,   167,   167,   167,
     349,   103,   804,  -189,  -189,  -189,  -189,  -189,  -189,   393,
    1046,   404,  1046,   -22,   -22,   536,   898,   182,   189,   190,
     191,   364,   202,   912,  -189,   -22,  -189,  -189,   113,   831,
     361,   361,   361,   536,  -189,  -189,  -189,  -189,  -189,  -189,
    1017,   536,   250,   251,   252,   270,   273,   274,   279,   375,
     536,  -189,  -189,  -189,   858,  -189,   925,   325,   344,   345,
     925,  -189,  -189,  -189
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     5,     1,     0,     0,     0,     0,     0,     5,
       2,   136,   137,     0,   159,     0,     0,   156,   155,   157,
     154,   158,     0,     0,     0,     0,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,     0,   159,   150,     0,   120,   126,   128,   130,
      13,     0,    14,    15,     0,    17,     3,     6,    11,    12,
       9,   159,     0,    10,    96,    95,    94,   110,   111,   112,
      97,    98,    99,   113,   114,   115,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,    26,     0,    42,     0,    43,     0,    44,     0,    45,
      25,   159,     0,     0,     0,     0,     0,     0,    41,    91,
      92,    93,    90,     0,     0,     0,     0,     0,     0,     0,
       0,   159,     0,    20,   153,     0,     0,     0,     0,     0,
       0,     0,   124,    16,     0,     0,   146,   147,   151,   152,
     148,   149,   144,   145,   138,   139,   140,   141,    55,    56,
      57,    58,    54,     0,     0,    46,     0,    47,     0,     0,
       0,    21,   159,     0,     0,     0,     0,     0,   100,   101,
     102,     0,   104,   105,   106,   103,     0,     0,     0,    68,
       0,    69,     0,    70,     0,    71,     0,     0,     0,     0,
       0,     0,    66,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,   123,     0,     0,     0,   159,     0,    59,
      60,     0,    49,     0,     0,    48,    52,    53,    28,    29,
      30,    27,     0,     0,     0,   116,     0,     0,     0,     0,
     107,   108,   109,     0,    72,    73,    74,    75,    67,     0,
       0,    76,     0,    77,     0,     0,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,    51,    63,    64,    23,     0,    22,    31,
      32,    33,     0,    35,    36,    37,    34,     0,     0,     0,
     117,   159,     0,    78,    79,    81,    80,    84,    85,     0,
      82,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,     0,    61,    62,     0,     0,
      38,    39,    40,     0,    88,    89,    86,    87,   121,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,    24,   118,     0,   129,     0,     0,     0,     0,
       0,   119,   134,   135
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -189,  -189,   -59,  -189,   418,   395,  -189,  -161,  -188,  -189,
    -189,  -137,    -6,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,   210,  -189,  -189,    -9
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    10,     2,    24,    25,    26,   170,   169,    27,
      28,    29,    30,    52,    31,    32,    33,    34,    35,    60,
     135,    61,   140,    62,    63,   136,    64,   137,    65,   138,
     139,   211,    36,    37,   171
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,   210,   142,   141,    48,     3,    49,   221,    40,    41,
      51,   254,     6,    54,    55,    74,    75,    38,    76,     7,
     222,    72,   223,    11,    12,     5,    13,    14,    15,    16,
      40,    41,     9,   103,   105,   107,   109,   118,   144,   255,
     117,   224,   132,   225,   279,   280,   281,    17,    18,    19,
      20,    21,    56,     9,    68,    22,    57,    58,    59,   265,
     203,   266,    40,    41,    23,    40,    41,    -7,    40,    41,
     119,   120,   121,   122,   224,   210,   276,     8,   207,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   182,   183,   184,   185,   226,    40,    41,   274,   320,
     321,   322,   123,    39,   165,   167,   163,   224,   173,   296,
     124,   307,   308,   309,   310,   181,   318,   189,   191,   193,
     195,   202,    50,   186,   201,    66,   297,    88,    89,    90,
      91,   187,    40,    41,   110,   295,   111,   223,   112,    69,
      40,    41,    70,   311,   113,   114,    92,    93,    94,    95,
      96,    97,    98,    99,   218,    73,    17,    18,    19,    20,
      21,   145,   324,   101,    22,   228,   229,   230,   231,    47,
     224,    86,   342,    23,    87,   115,   208,   209,   243,   116,
      53,   125,   102,   133,    42,    43,    44,    45,   251,   253,
     249,  -132,   257,    98,    99,   263,   260,   261,  -122,   158,
      17,    18,    19,    20,    21,   269,   271,   273,    22,   264,
     143,    47,   159,   160,    53,   278,   104,    23,   161,   162,
     335,   336,   337,   338,   174,   168,   205,   283,   284,   285,
     286,   175,   176,   177,    17,    18,    19,    20,    21,   111,
     292,   196,    22,   213,   328,   329,   206,   197,   198,   300,
     302,    23,   339,   212,   118,   306,   341,   117,   313,    17,
      18,    19,    20,    21,   214,   215,    47,    22,   126,   127,
     128,   129,   216,   319,    77,    78,    23,    79,   199,   130,
     219,   111,   200,   112,   220,    80,    81,   352,    82,   113,
     114,   353,   232,   233,   234,    47,   330,    96,    97,    98,
      99,    17,    18,    19,    20,    21,    53,   262,   106,    22,
      83,    84,   236,    85,   344,   237,   238,    53,    23,   108,
     115,   239,   346,   244,   116,   258,    17,    18,    19,    20,
      21,   350,   245,   246,    22,    88,    89,    17,    18,    19,
      20,    21,    53,    23,   164,    22,   178,   179,   247,   180,
     248,   259,   267,    53,    23,   166,    94,    95,    96,    97,
      98,    99,    17,    18,    19,    20,    21,   287,   240,   241,
      22,   242,   277,    17,    18,    19,    20,    21,    53,    23,
     188,    22,   332,   333,   282,   334,   288,   289,   293,    53,
      23,   190,   294,   347,   348,   305,   349,   312,    17,    18,
      19,    20,    21,   316,   314,   317,    22,   323,   326,    17,
      18,    19,    20,    21,    53,    23,   192,    22,   223,   327,
       4,    67,   268,     0,     0,    53,    23,   194,     0,     0,
       0,     0,     0,     0,    17,    18,    19,    20,    21,     0,
       0,     0,    22,     0,     0,    17,    18,    19,    20,    21,
      53,    23,   250,    22,     0,     0,     0,     0,     0,     0,
       0,    53,    23,   252,     0,     0,     0,     0,     0,     0,
      17,    18,    19,    20,    21,     0,     0,     0,    22,     0,
       0,    17,    18,    19,    20,    21,    53,    23,   270,    22,
       0,     0,     0,     0,     0,     0,     0,    53,    23,   272,
       0,     0,     0,     0,     0,     0,    17,    18,    19,    20,
      21,     0,     0,     0,    22,     0,     0,    17,    18,    19,
      20,    21,    53,    23,   299,    22,     0,     0,     0,     0,
       0,     0,     0,    53,    23,   301,     0,     0,     0,     0,
       0,     0,    17,    18,    19,    20,    21,     0,     0,     0,
      22,    53,     0,    17,    18,    19,    20,    21,     0,    23,
       0,    22,    71,    40,    41,    42,    43,    44,    45,     0,
      23,    17,    18,    19,    20,    21,    46,     0,     0,    22,
     131,     0,    17,    18,    19,    20,    21,     0,    23,     0,
      22,   172,    47,     0,     0,     0,     0,     0,     0,    23,
      17,    18,    19,    20,    21,     0,     0,     0,    22,   217,
       0,    17,    18,    19,    20,    21,     0,    23,     0,    22,
     256,     0,     0,     0,     0,     0,     0,     0,    23,    17,
      18,    19,    20,    21,     0,     0,     0,    22,   291,     0,
      17,    18,    19,    20,    21,     0,    23,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    17,    18,
      19,    20,    21,     0,     0,     0,    22,    88,    89,    90,
      91,     0,     0,     0,     0,    23,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    88,    89,    90,    91,     0,     0,
       0,   204,    93,    94,    95,    96,    97,    98,    99,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    88,    89,    90,    91,     0,     0,     0,   227,     0,
      94,    95,    96,    97,    98,    99,     0,     0,     0,     0,
      92,    93,    94,    95,    96,    97,    98,    99,    88,    89,
      90,    91,     0,     0,     0,   235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    93,    94,
      95,    96,    97,    98,    99,    88,    89,    90,    91,     0,
       0,     0,   275,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    99,    88,    89,    90,    91,     0,     0,     0,   290,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,    98,    99,    88,
      89,    90,    91,     0,     0,     0,   298,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    99,    88,    89,    90,    91,
       0,     0,     0,   325,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,    95,    96,
      97,    98,    99,    88,    89,    90,    91,     0,     0,     0,
     343,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    94,    95,    96,    97,    98,    99,
      88,    89,    90,    91,     0,     0,     0,   351,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,     0,    92,
      93,    94,    95,    96,    97,    98,    99,    88,    89,    90,
      91,   100,    92,    93,    94,    95,    96,    97,    98,    99,
      88,    89,    90,    91,   331,     0,    92,    93,    94,    95,
      96,    97,    98,    99,    88,    89,    90,    91,   340,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,     9,
       0,     0,     0,    92,    93,    94,    95,    96,    97,    98,
      99,     0,   134,    88,    89,    90,    91,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,     0,     0,
       0,     0,    92,    93,    94,    95,    96,    97,    98,    99,
       0,   303,    92,    93,    94,    95,    96,    97,    98,    99,
       0,   304,    88,    89,    90,    91,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,    98,    99,     0,
     315,    92,    93,    94,    95,    96,    97,    98,    99,     0,
     345,    88,    89,    90,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    93,    94,    95,    96,    97,    98,    99
};

static const yytype_int16 yycheck[] =
{
       9,   138,    61,     4,    15,     0,    17,   168,    29,    30,
      16,   199,     3,    22,    23,    18,    19,    26,    21,    52,
      55,    30,    57,    11,    12,    18,    14,    15,    16,    17,
      29,    30,    54,    42,    43,    44,    45,    46,    59,   200,
      46,    57,    51,    59,   232,   233,   234,    35,    36,    37,
      38,    39,     4,    54,    56,    43,     8,     9,    10,    15,
      59,    17,    29,    30,    52,    29,    30,    55,    29,    30,
      18,    19,    20,    21,    57,   212,    59,    53,   137,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    18,    19,    20,    21,    59,    29,    30,    59,   287,
     288,   289,    50,    42,   113,   114,   112,    57,   117,    59,
      58,    18,    19,    20,    21,   124,   277,   126,   127,   128,
     129,   130,    15,    50,   130,    55,    59,    25,    26,    27,
      28,    58,    29,    30,    13,    55,    15,    57,    17,    56,
      29,    30,    56,    50,    23,    24,    44,    45,    46,    47,
      48,    49,    50,    51,   163,    56,    35,    36,    37,    38,
      39,    59,    59,    15,    43,   174,   175,   176,   177,    58,
      57,    56,    59,    52,    56,    54,    15,    16,   187,    58,
      15,    15,    17,    56,    31,    32,    33,    34,   197,   198,
     196,    52,   201,    50,    51,    42,   205,   206,     5,    15,
      35,    36,    37,    38,    39,   214,   215,   216,    43,    56,
      56,    58,    15,    15,    15,   224,    17,    52,    15,    15,
      18,    19,    20,    21,    42,    58,    52,   236,   237,   238,
     239,    42,    42,    42,    35,    36,    37,    38,    39,    15,
     249,    17,    43,     5,   303,   304,    52,    23,    24,   258,
     259,    52,    50,    52,   263,   264,   315,   263,   267,    35,
      36,    37,    38,    39,    52,    42,    58,    43,    31,    32,
      33,    34,    42,   282,    18,    19,    52,    21,    54,    42,
      15,    15,    58,    17,    15,    18,    19,   346,    21,    23,
      24,   350,    42,    42,    42,    58,   305,    48,    49,    50,
      51,    35,    36,    37,    38,    39,    15,     8,    17,    43,
      18,    19,    42,    21,   323,    42,    42,    15,    52,    17,
      54,    42,   331,    15,    58,    42,    35,    36,    37,    38,
      39,   340,    15,    15,    43,    25,    26,    35,    36,    37,
      38,    39,    15,    52,    17,    43,    18,    19,    15,    21,
      15,    42,    56,    15,    52,    17,    46,    47,    48,    49,
      50,    51,    35,    36,    37,    38,    39,    42,    18,    19,
      43,    21,    58,    35,    36,    37,    38,    39,    15,    52,
      17,    43,    18,    19,    58,    21,    42,    42,    15,    15,
      52,    17,    15,    18,    19,    52,    21,    15,    35,    36,
      37,    38,    39,    15,    53,    15,    43,    58,    15,    35,
      36,    37,    38,    39,    15,    52,    17,    43,    57,    15,
       2,    26,   212,    -1,    -1,    15,    52,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    43,    -1,    -1,    35,    36,    37,    38,    39,
      15,    52,    17,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    52,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    43,    -1,
      -1,    35,    36,    37,    38,    39,    15,    52,    17,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    52,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    43,    -1,    -1,    35,    36,    37,
      38,    39,    15,    52,    17,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    52,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      43,    15,    -1,    35,    36,    37,    38,    39,    -1,    52,
      -1,    43,    15,    29,    30,    31,    32,    33,    34,    -1,
      52,    35,    36,    37,    38,    39,    42,    -1,    -1,    43,
      15,    -1,    35,    36,    37,    38,    39,    -1,    52,    -1,
      43,    15,    58,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    43,    15,
      -1,    35,    36,    37,    38,    39,    -1,    52,    -1,    43,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    43,    15,    -1,
      35,    36,    37,    38,    39,    -1,    52,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    43,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    44,    45,    46,    47,
      48,    49,    50,    51,    25,    26,    27,    28,    -1,    -1,
      -1,    59,    45,    46,    47,    48,    49,    50,    51,    25,
      26,    27,    28,    44,    45,    46,    47,    48,    49,    50,
      51,    25,    26,    27,    28,    -1,    -1,    -1,    59,    -1,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    25,    26,
      27,    28,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    25,    26,    27,    28,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    25,    26,    27,    28,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    25,
      26,    27,    28,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    25,    26,    27,    28,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    25,    26,    27,    28,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      25,    26,    27,    28,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    25,    26,    27,
      28,    56,    44,    45,    46,    47,    48,    49,    50,    51,
      25,    26,    27,    28,    56,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    25,    26,    27,    28,    56,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,    54,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    63,     0,    64,    18,     3,    52,    53,    54,
      62,    11,    12,    14,    15,    16,    17,    35,    36,    37,
      38,    39,    43,    52,    64,    65,    66,    69,    70,    71,
      72,    74,    75,    76,    77,    78,    92,    93,    94,    42,
      29,    30,    31,    32,    33,    34,    42,    58,    15,    17,
      15,    72,    73,    15,    94,    94,     4,     8,     9,    10,
      79,    81,    83,    84,    86,    88,    55,    65,    56,    56,
      56,    15,    94,    56,    18,    19,    21,    18,    19,    21,
      18,    19,    21,    18,    19,    21,    56,    56,    25,    26,
      27,    28,    44,    45,    46,    47,    48,    49,    50,    51,
      56,    15,    17,    94,    17,    94,    17,    94,    17,    94,
      13,    15,    17,    23,    24,    54,    58,    72,    94,    18,
      19,    20,    21,    50,    58,    15,    31,    32,    33,    34,
      42,    15,    94,    56,    53,    80,    85,    87,    89,    90,
      82,     4,    62,    56,    59,    59,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    15,    15,
      15,    15,    15,    72,    17,    94,    17,    94,    58,    68,
      67,    94,    15,    94,    42,    42,    42,    42,    18,    19,
      21,    94,    18,    19,    20,    21,    50,    58,    17,    94,
      17,    94,    17,    94,    17,    94,    17,    23,    24,    54,
      58,    72,    94,    59,    59,    52,    52,    62,    15,    16,
      71,    91,    52,     5,    52,    42,    42,    15,    94,    15,
      15,    67,    55,    57,    57,    59,    59,    59,    94,    94,
      94,    94,    42,    42,    42,    59,    42,    42,    42,    42,
      18,    19,    21,    94,    15,    15,    15,    15,    15,    72,
      17,    94,    17,    94,    68,    67,    15,    94,    42,    42,
      94,    94,     8,    42,    56,    15,    17,    56,    91,    94,
      17,    94,    17,    94,    59,    59,    59,    58,    94,    68,
      68,    68,    58,    94,    94,    94,    94,    42,    42,    42,
      59,    15,    94,    15,    15,    55,    59,    59,    59,    17,
      94,    17,    94,    53,    53,    52,    94,    18,    19,    20,
      21,    50,    15,    94,    53,    53,    15,    15,    67,    94,
      68,    68,    68,    58,    59,    59,    15,    15,    62,    62,
      94,    56,    18,    19,    21,    18,    19,    20,    21,    50,
      56,    62,    59,    59,    94,    53,    94,    18,    19,    21,
      94,    59,    62,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    63,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    68,    68,    69,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    76,    77,    78,
      80,    79,    82,    81,    83,    83,    85,    84,    87,    86,
      89,    88,    90,    88,    91,    91,    92,    93,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     3,     0,     0,     2,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     2,     2,     2,
       3,     1,     3,     3,     5,     3,     3,     5,     5,     5,
       5,     6,     6,     6,     6,     6,     6,     6,     7,     7,
       7,     3,     3,     3,     3,     3,     4,     4,     5,     5,
       5,     5,     5,     5,     4,     4,     4,     4,     4,     5,
       5,     6,     6,     6,     6,     2,     3,     4,     3,     3,
       3,     3,     4,     4,     4,     4,     4,     4,     5,     5,
       5,     5,     5,     5,     5,     5,     6,     6,     6,     6,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     2,
       4,     4,     4,     4,     4,     4,     4,     5,     5,     5,
       2,     2,     2,     2,     2,     2,     5,     6,     8,     9,
       0,     6,     0,     3,     2,     6,     0,     6,     0,     7,
       0,     3,     0,     5,     6,     6,     1,     1,     3,     3,
       3,     3,     2,     2,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 128 "sintatica.y" /* yacc.c:1646  */
    {
				printGlobalVariables();
				cout << "/*Compilador Eva*/\n" << "#include <iostream>\n#include <stdlib.h>\n#include <string.h>\n#include <stdio.h>\n#define TRUE 1\n#define FALSE 0\n\nint main(void)\n{" <<endl;
				printVector();
				cout << (yyvsp[0]).traducao << endl;
				freeVectors();
				cout << "\treturn 0;\n}" << endl;
			}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 139 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).traducao = (yyvsp[-1]).traducao;
				}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 145 "sintatica.y" /* yacc.c:1646  */
    {
								contextoVariaveis.push_back(globalTabSym);
								cout << "Adicionado o contexto global!" << endl;
							}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 151 "sintatica.y" /* yacc.c:1646  */
    {
								addMapToStack();
							}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 156 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
					}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 161 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).traducao = "";
					}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 167 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 172 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 177 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 182 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 187 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 192 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
						}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 197 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
						}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 202 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
						}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 207 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 212 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
						}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 217 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 222 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 227 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 233 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				tamanho_vetor++;
				//tamanho_linhas++;
				label_vet.push((yyvsp[0]).label);
				tipo_vet.push((yyvsp[0]).tipo);
				trad_vet.push((yyvsp[0]).traducao);
				(yyval).tipo = (yyvsp[0]).tipo;
				cout << "TAMANHO: " << tamanho_vetor << endl;
			}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 245 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
				tamanho_vetor++;
				(yyval).tipo = (yyvsp[-2]).tipo;
				label_vet.push((yyvsp[0]).label);
				tipo_vet.push((yyvsp[0]).tipo);
				trad_vet.push((yyvsp[0]).traducao);
				cout << "TAMANHO: " << tamanho_vetor << endl;
			}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 257 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).traducao = (yyvsp[-1]).traducao;
					(yyval).tipo = (yyvsp[-1]).tipo;
          tamanho_linhas++;
					tamanho_vetor = 0;
					cout << "Adicionado uma linha! Linhas totais: " << tamanho_linhas << endl;
				}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 266 "sintatica.y" /* yacc.c:1646  */
    {
          (yyval).traducao = (yyvsp[-4]).traducao + (yyvsp[-1]).traducao;
          tamanho_linhas++;
					tamanho_colunas = tamanho_vetor;
					tamanho_vetor = 0;
					cout << "Adicionado uma linha! Linhas totais: " << tamanho_linhas << endl;
        }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 276 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = (yyvsp[-2]).tipo;
				variable Var = searchForVariable((yyvsp[-2]).label);
				cout << "$3.label = " << (yyvsp[0]).label << endl;
				(yyval).traducao = "\tstd::cin" + (yyval).traducao + (yyvsp[-2]).traducao + ";\n";
			}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 285 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				variable Var = searchForVariable((yyvsp[0]).label);
				(yyval).traducao = "\tstd::cout " + (yyvsp[0]).traducao + ";\n";
			}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 292 "sintatica.y" /* yacc.c:1646  */
    {
							erroTipo("char", (yyvsp[0]).tipo);
							string nomeAuxID = genLabel();
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label + ";\n";
							addVarToTabSym(nomeAuxID, (yyvsp[-3]).label, (yyval).traducao, "char");
							addVarToTempVector("\tchar " + nomeAuxID + ";\n");
						}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 309 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "int";
							if((yyval).tipo != (yyvsp[0]).tipo){

								if((yyvsp[0]).tipo == "char" || (yyvsp[0]).tipo == "string"){
									yyerror("Declaração de char/string em int não permitido!");
								}

								else{

									string nomeAuxID = genLabel();
									(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (int) " + (yyvsp[0]).label  + ";\n";

									addVarToTabSym(nomeAuxID, (yyvsp[-3]).label, (yyval).traducao, "int");
									addVarToTempVector("\tint " + nomeAuxID +  ";\n");
								}
							}

							else{

								string nomeAuxID = genLabel();
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label  + ";\n";

								addVarToTabSym(nomeAuxID, (yyvsp[-3]).label, (yyval).traducao, "int");
								variable Var = searchForVariable((yyvsp[-3]).label);
								cout << "WHATS IN THE BOX? " << Var.valor << endl;
								addVarToTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 340 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "float";
							if((yyval).tipo != (yyvsp[0]).tipo){
								if((yyvsp[0]).tipo == "char" || (yyvsp[0]).tipo == "string"){
									yyerror("Declaração de char/string em float não permitido!");
								}
								else{
									string nomeAuxID = genLabel();
									(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (float) " + (yyvsp[0]).label  + ";\n";
									addVarToTabSym(nomeAuxID, (yyvsp[-3]).label, (yyval).traducao, "float");
									addVarToTempVector("\tfloat " + nomeAuxID +  ";\n");
								}
							}
							else{
								string nomeAuxID = genLabel();
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label  + ";\n";
								addVarToTabSym(nomeAuxID, (yyvsp[-3]).label, (yyval).traducao, "float");
								addVarToTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 362 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "bool";
							if((yyval).tipo != (yyvsp[0]).tipo){
								yyerror("Tipo booleano somente aceita boleano!");
							}
							else{
								string nomeAuxID = genLabel();
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label  + ";\n";
								addVarToTabSym(nomeAuxID, (yyvsp[-3]).label, (yyval).traducao, "int");
								addVarToTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 377 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "int";
							if((yyvsp[0]).tipo != (yyval).tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();
								stackVectors.push("\tfree(" + nomeAuxID + ");\n");
								//variable Var = searchForVariable(nomeAuxID);
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (int*) malloc(" +
								addVarToTabSym(nomeAuxID, (yyvsp[-4]).label, (yyval).traducao, "int*");
								to_string(tamanho_vetor) + " * sizeof(int));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToTempVector("\tint* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 395 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "float";
							if((yyvsp[0]).tipo != (yyval).tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();stackVectors.push("\tfree(" + nomeAuxID + ");\n");
								//variable Var = searchForVariable(nomeAuxID);
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (float*) malloc(" +
								addVarToTabSym(nomeAuxID, (yyvsp[-4]).label, (yyval).traducao, "float*");
								to_string(tamanho_vetor) + " * sizeof(float));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 412 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "char";
							if((yyvsp[0]).tipo != (yyval).tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();stackVectors.push("\tfree(" + nomeAuxID + ");\n");
								//variable Var = searchForVariable(nomeAuxID);
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (char*) malloc(" +
								addVarToTabSym(nomeAuxID, (yyvsp[-4]).label, (yyval).traducao, "char*");
								to_string(tamanho_vetor) + " * sizeof(char));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 431 "sintatica.y" /* yacc.c:1646  */
    {
							erroTipo("char", (yyvsp[0]).tipo);
							string nomeAuxID = genLabel();
							addVarToGlobalTabSym(nomeAuxID, (yyvsp[-3]).label, (yyvsp[0]).traducao, "char");
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label + ";\n";
							addVarToGlobalTempVector("\tchar " + nomeAuxID +  ";\n");
						}
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 448 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "int";
							if((yyval).tipo != (yyvsp[0]).tipo){

								if((yyvsp[0]).tipo == "char" || (yyvsp[0]).tipo == "string"){
									yyerror("Declaração de char/string em int não permitido!");
								}

								else{
									string nomeAuxID = genLabel();
									(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (int) " + (yyvsp[0]).label  + ";\n";
									addVarToGlobalTabSym(nomeAuxID, (yyvsp[-3]).label, (yyval).traducao, "int");
									addVarToGlobalTempVector("\tint " + nomeAuxID +  ";\n");
								}
							}

							else{
								string nomeAuxID = genLabel();
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label  + ";\n";
								addVarToGlobalTabSym(nomeAuxID, (yyvsp[-3]).label, (yyval).traducao, "int");
								addVarToGlobalTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 473 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "float";
							if((yyval).tipo != (yyvsp[0]).tipo){
								if((yyvsp[0]).tipo == "char" || (yyvsp[0]).tipo == "string"){
									yyerror("Declaração de char/string em float não permitido!");
								}
								else{
									string nomeAuxID = genLabel();
									(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (float) " + (yyvsp[0]).label  + ";\n";
									addVarToGlobalTabSym(nomeAuxID, (yyvsp[-3]).label, (yyval).traducao, "float");
									addVarToGlobalTempVector("\tfloat " + nomeAuxID +  ";\n");
								}
							}
							else{
								string nomeAuxID = genLabel();
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label  + ";\n";
								addVarToGlobalTabSym(nomeAuxID, (yyvsp[-3]).label, (yyval).traducao, "float");
								addVarToGlobalTempVector("\tfloat " + nomeAuxID +  ";\n");
							}
						}
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 495 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "bool";
							if((yyval).tipo != (yyvsp[0]).tipo){
								yyerror("Tipo booleano somente aceita boleano!");
							}
							else{
								string nomeAuxID = genLabel();
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyval).label  + ";\n";
								addVarToGlobalTabSym(nomeAuxID, (yyvsp[-3]).label, (yyvsp[0]).traducao, "int");
								addVarToGlobalTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 511 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "int";
							if((yyvsp[0]).tipo != (yyval).tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (int*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(int));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToGlobalTempVector("\tint* " + nomeAuxID + ";\n");
								addVarToGlobalTabSym(nomeAuxID, (yyvsp[-5]).label, (yyval).traducao, "int*");
								//variable Var = searchForVariable(nomeAuxID);
								tamanho_vetor = 0;
							}
						}
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 528 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "float";
							if((yyvsp[0]).tipo != (yyval).tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (float*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(float));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToGlobalTempVector("\tfloat* " + nomeAuxID + ";\n");
								addVarToGlobalTabSym(nomeAuxID, (yyvsp[-5]).label, (yyval).traducao, "float*");
								tamanho_vetor = 0;
							}
						}
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 544 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "char";
							if((yyvsp[0]).tipo != (yyval).tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = genLabel();
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (char*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(char));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToGlobalTempVector("\tchar* " + nomeAuxID + ";\n");
								addVarToGlobalTabSym(nomeAuxID, (yyvsp[-5]).label, (yyval).traducao, "char*");
								tamanho_vetor = 0;
							}
						}
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 562 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-2]).label);

							if(((yyvsp[0]).tipo != Var.tipo)){

								if(((yyvsp[0]).tipo == "char" && Var.tipo != "char") || ((yyvsp[0]).tipo == "bool" && Var.tipo != "bool") || ((yyvsp[0]).tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + (yyvsp[0]).tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}

								else{

									(yyval).tipo = Var.tipo;
									(yyval).traducao = (yyvsp[0]).traducao + "\t" + Var.nome + " = " + "(" + Var.tipo + ") " + (yyvsp[0]).label + ";\n";
								}
							}

							else{

								(yyval).tipo = (yyvsp[0]).tipo;
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + Var.nome + " = " + (yyvsp[0]).label + ";\n";
							}
						}
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 588 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-2]).label);
							variable Var2 = searchForVariable((yyvsp[0]).label);
							if(((yyvsp[0]).tipo != Var.tipo)){

								if(((yyvsp[0]).tipo == "char" && Var.tipo != "char") || ((yyvsp[0]).tipo == "bool" && Var.tipo != "bool") || ((yyvsp[0]).tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + (yyvsp[0]).tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								(yyval).tipo = Var.tipo;
								(yyval).label = Var.nome;
								(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " + " + (yyvsp[0]).label + ";\n";
							}
						}
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 607 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-2]).label);
							variable Var2 = searchForVariable((yyvsp[0]).label);
							if(((yyvsp[0]).tipo != Var.tipo)){

								if(((yyvsp[0]).tipo == "char" && Var.tipo != "char") || ((yyvsp[0]).tipo == "bool" && Var.tipo != "bool") || ((yyvsp[0]).tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + (yyvsp[0]).tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								(yyval).tipo = Var.tipo;
								(yyval).label = Var.nome;
								(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " - " + (yyvsp[0]).label + ";\n";
							}
						}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 626 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-2]).label);
							variable Var2 = searchForVariable((yyvsp[0]).label);
							if(((yyvsp[0]).tipo != Var.tipo)){

								if(((yyvsp[0]).tipo == "char" && Var.tipo != "char") || ((yyvsp[0]).tipo == "bool" && Var.tipo != "bool") || ((yyvsp[0]).tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + (yyvsp[0]).tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								(yyval).tipo = Var.tipo;
								(yyval).label = Var.nome;
								(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " * " + (yyvsp[0]).label + ";\n";
							}
						}
#line 2373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 645 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-2]).label);
							variable Var2 = searchForVariable((yyvsp[0]).label);
							if(((yyvsp[0]).tipo != Var.tipo)){

								if(((yyvsp[0]).tipo == "char" && Var.tipo != "char") || ((yyvsp[0]).tipo == "bool" && Var.tipo != "bool") || ((yyvsp[0]).tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + (yyvsp[0]).tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								(yyval).tipo = Var.tipo;
								(yyval).label = Var.nome;
								(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " / " + (yyvsp[0]).label + ";\n";
							}
						}
#line 2395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 664 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-3]).label);
							//unordered_map<string, variable> tabSym = contextoVariaveis.back();
							if(((yyvsp[0]).tipo == "char" && Var.tipo != "char") || ((yyvsp[0]).tipo == "bool" && Var.tipo != "bool")){
								string msgError = "Atribuição de " + (yyvsp[0]).tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}

							else{

								if((Var.tipo == "int") && (yyvsp[0]).tipo == "float"){

									cout << "Conversão para float em "<< Var.nome << " não suportada! Resultado será armazenado como inteiro!\n" << endl;
									(yyval).tipo = "int";
									(yyval).traducao = (yyvsp[0]).traducao + "\t" + Var.nome + " = " + (yyvsp[0]).label + ";\n";
								}
								else{
										(yyval).tipo = "float";
										(yyval).traducao = (yyvsp[0]).traducao + "\t" + Var.nome + " = (float) " + (yyvsp[0]).label + ";\n";
								}
							}
						}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 688 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-3]).label);
							//unordered_map<string, variable> tabSym = contextoVariaveis.back();
							if(((yyvsp[0]).tipo == "char" && Var.tipo != "char") || ((yyvsp[0]).tipo == "bool" && Var.tipo != "bool")){
								string msgError = "Atribuição de " + (yyvsp[0]).tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}

							else{

								(yyval).traducao = (yyvsp[0]).traducao + "\t" + Var.nome + " = (int) " + (yyvsp[0]).label + ";\n";
							}
						}
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 703 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-4]).label);
							map_vetor[Var.nome] = tamanho_vetor;
							cout << Var.nome << endl;
							cout << Var.tipo << endl;
							cout << Var.valor << endl;

							if(Var.tipo != (yyvsp[-1]).tipo + '*'){

								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}

							else{

								if(map_linhas[Var.nome] >= map_vetor[Var.nome]){

									(yyval).traducao = (yyvsp[-1]).traducao + addElementsToArray(map_vetor[Var.nome], Var.nome);
									cout << "TAMANHO VETOR: " << tamanho_vetor <<"\nTAMANHO LINHA: " << tamanho_linhas << endl;
									map_linhas[Var.nome] = map_linhas[Var.nome] - map_vetor[Var.nome];
									cout << "TAMANHO LINHA ATUAL: " << tamanho_linhas << endl;
									tamanho_vetor = 0;
									map_vetor[Var.nome] = 0;
								}

								else{
									yyerror("Vetor atribuido maior que suportado na variável!");
								}
							}
						}
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 734 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-4]).label);
							cout << Var.nome << endl;
							cout << Var.tipo << endl;
							cout << Var.valor << endl;
							if(Var.tipo != (yyvsp[-1]).tipo + '*'){
								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}
							else{
							if(tamanho_vetor > elementos_matriz){
									yyerror("Vetor atribuido maior que variável suporta!");
								}
								else{
									variable Var = searchForVariable((yyvsp[-4]).label);
									(yyval).traducao = (yyvsp[-1]).traducao + addElementsToArray(elementos_matriz, Var.nome);
									//tamanho_vetor -= tamanho_linhas;
									tamanho_vetor = 0;
								}
							}
						}
#line 2499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 756 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-4]).label);

							if(Var.tipo != (yyvsp[0]).tipo + "*"){

								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}

							else{
								if(map_linhas[Var.nome] != 0){
									//checkForVariable($2.label);
									variable pointer = arrayPointerNames[Var.nome];
									variable kmpls = searchForVariable((yyvsp[-3]).label);
									(yyval).traducao = (yyvsp[0]).traducao + "\t" + pointer.nome + " = " + kmpls.nome +
									";\n\t" + Var.nome + "[" + pointer.nome + "] = " + (yyvsp[0]).label + ";\n";
								}
							}
						}
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 776 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-4]).label);

							if(Var.tipo != (yyvsp[0]).tipo + "*"){

								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}

							else{
								if(map_linhas[Var.nome] != 0){
									//checkForVariable($2.label);
									variable pointer = arrayPointerNames[Var.nome];
									//variable kmpls = searchForVariable($3.label);
									(yyval).traducao = (yyvsp[-3]).traducao + (yyvsp[0]).traducao + "\t" + pointer.nome + " = " + (yyvsp[-3]).label +
									";\n\t" + Var.nome + "[" + pointer.nome + "] = " + (yyvsp[0]).label + ";\n";
								}
							}
						}
#line 2545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 796 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-4]).label);
							variable Vector = searchForVariable((yyvsp[-2]).label);
							variable Index = searchForVariable((yyvsp[-1]).label);

							if(Var.tipo + "*" != Vector.tipo){

								yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
							}

							else{

								variable pointer = arrayPointerNames[Vector.nome];
								(yyval).traducao = "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
								Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
							}

						}
#line 2568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 817 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-4]).label);
							variable Vector = searchForVariable((yyvsp[-2]).label);
							variable Index = searchForVariable((yyvsp[-1]).label);

							if(Var.tipo + "*" != Vector.tipo){

								yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
							}

							else{

								variable pointer = arrayPointerNames[Vector.nome];
								(yyval).traducao = (yyvsp[-1]).traducao + "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
								Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
							}
						}
#line 2590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 837 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-3]).label);
							variable Var2 = searchForGlobalVariable((yyvsp[0]).label);

							if((Var2.tipo != Var.tipo)){

								if((Var2.tipo == "char" && Var.tipo != "char") || (Var2.tipo == "bool" && Var.tipo != "bool") || (Var2.tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}

								else{

									(yyval).tipo = Var.tipo;
									cout << "TIPO VAR 2: " << Var2.valor << endl;
									(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + "(" + Var.tipo + ") " + Var2.nome + ";\n";
								}
							}

							else{

								(yyval).tipo = Var2.tipo;
								(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var2.nome + ";\n";
							}
						}
#line 2620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 864 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-3]).label);
							variable Var2 = searchForGlobalVariable((yyvsp[0]).label);
							if((Var2.tipo != Var.tipo)){

								if((Var2.tipo == "char" && Var.tipo != "char") || (Var2.tipo == "bool" && Var.tipo != "bool") || (Var2.tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								(yyval).tipo = Var.tipo;
								(yyval).label = Var.nome;
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + Var.nome + " = " + Var.nome + " + " + Var2.nome + ";\n";
							}
						}
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 883 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-3]).label);
							variable Var2 = searchForGlobalVariable((yyvsp[0]).label);
							if((Var2.tipo != Var.tipo)){

								if((Var2.tipo == "char" && Var.tipo != "char") || ((yyvsp[-1]).tipo == "bool" && Var.tipo != "bool") || (Var2.tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								(yyval).tipo = Var.tipo;
								(yyval).label = Var.nome;
								(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " - " + Var2.nome + ";\n";
							}
						}
#line 2664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 902 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-3]).label);
							variable Var2 = searchForVariable((yyvsp[0]).label);
							if((Var2.tipo != Var.tipo)){

								if((Var2.tipo == "char" && Var.tipo != "char") || (Var2.tipo == "bool" && Var.tipo != "bool") || (Var2.tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								(yyval).tipo = Var.tipo;
								(yyval).label = Var.nome;
								(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " * " + Var2.nome + ";\n";
							}
						}
#line 2686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 921 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-3]).label);
							variable Var2 = searchForGlobalVariable((yyvsp[0]).label);
							if((Var2.tipo != Var.tipo)){

								if((Var2.tipo == "char" && Var.tipo != "char") || (Var2.tipo == "bool" && Var.tipo != "bool") || (Var2.tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}
							}
							else{

								(yyval).tipo = Var.tipo;
								(yyval).label = Var.nome;
								(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " / " + Var2.nome + ";\n";
							}
						}
#line 2708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 941 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-4]).label);
							variable Var2 = searchForGlobalVariable((yyvsp[0]).label);
							//unordered_map<string, variable> tabSym = contextoVariaveis.back();
							if((Var2.tipo == "char" && Var.tipo != "char") || (Var2.tipo == "bool" && Var.tipo != "bool")){
								string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}

							else{

								if((Var.tipo == "int") && Var2.tipo == "float"){

									cout << "Conversão para float em "<< Var.nome << " não suportada! Resultado será armazenado como inteiro!\n" << endl;
									(yyval).tipo = "int";
									(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var2.nome + ";\n";
								}
								else{
										(yyval).tipo = "float";
										(yyval).traducao = Var2.valor + "\t" + Var.nome + " = (float) " + Var2.nome + ";\n";
								}
							}
						}
#line 2736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 966 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-4]).label);
							variable Var2 = searchForGlobalVariable((yyvsp[0]).label);
							//unordered_map<string, variable> tabSym = contextoVariaveis.back();
							if((Var2.tipo == "char" && Var.tipo != "char") || (Var2.tipo == "bool" && Var.tipo != "bool")){
								string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}

							else{

								(yyval).traducao = Var2.valor + "\t" + Var.nome + " = (int) " + Var2.nome + ";\n";
							}
						}
#line 2755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 983 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-5]).label);
							variable Var2 = searchForGlobalVariable((yyvsp[0]).label);

							if(Var.tipo != Var2.tipo + "*"){
								cout << "NOME E: " << (yyvsp[0]).label << endl;
								cout << "TIPO E: " << Var2.tipo << endl;
								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}

							else{

								if(map_linhas[Var.nome] != 0){
									variable pointer = arrayPointerNames[Var.nome];
									variable kmpls = searchForVariable((yyvsp[-4]).label);
									(yyval).traducao = Var2.valor + "\t" + pointer.nome + " = " + kmpls.nome +
									";\n\t" + Var.nome + "[" + pointer.nome + "] = " + Var2.nome + ";\n";
								}
							}
						}
#line 2780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1005 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-5]).label);
							variable Var2 = searchForGlobalVariable((yyvsp[0]).label);

							if(Var.tipo != Var2.tipo + "*"){

								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}

							else{
								if(map_linhas[Var.nome] != 0){
									//checkForVariable($2.label);
									variable pointer = arrayPointerNames[Var.nome];
									//variable kmpls = searchForVariable($3.label);
									(yyval).traducao = (yyvsp[-4]).traducao + Var2.valor + "\t" + pointer.nome + " = " + (yyvsp[-4]).label +
									";\n\t" + Var.nome + "[" + pointer.nome + "] = " + Var2.nome + ";\n";
								}
							}
						}
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1026 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-5]).label);
							variable Vector = searchForGlobalVariable((yyvsp[-2]).label);
							variable Index = searchForVariable((yyvsp[-1]).label);

							if(Var.tipo + "*" != Vector.tipo){

								cout << "TIPO i: " << Var.tipo << endl;
								yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
							}

							else{

								variable pointer = arrayPointerNames[Vector.nome];
								(yyval).traducao = "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
								Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
							}
						}
#line 2827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1047 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-5]).label);
							variable Vector = searchForGlobalVariable((yyvsp[-2]).label);
							variable Index = searchForVariable((yyvsp[-1]).label);

							if(Var.tipo + "*" != Vector.tipo){

								yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
							}

							else{

								variable pointer = arrayPointerNames[Vector.nome];
								(yyval).traducao = (yyvsp[-1]).traducao + "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
								Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
							}
						}
#line 2849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1067 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval) = (yyvsp[-1]);
				}
#line 2857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1072 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-2]).label);
						cout <<"NOME2: " << (yyvsp[0]).label << endl;
						if(((yyvsp[0]).tipo != Var.tipo)){

							if(((yyvsp[0]).tipo == "char" && Var.tipo != "char") || ((yyvsp[0]).tipo == "bool" && Var.tipo != "bool") || ((yyvsp[0]).tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + (yyvsp[0]).tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}

							else{

								(yyval).tipo = Var.tipo;
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + Var.nome + " = " + "(" + Var.tipo + ") " + (yyvsp[0]).label + ";\n";
							}
						}

						else{

							(yyval).tipo = (yyvsp[0]).tipo;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + Var.nome + " = " + (yyvsp[0]).label + ";\n";
						}
					}
#line 2885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1098 "sintatica.y" /* yacc.c:1646  */
    {
						cout << "NOME2: " << (yyvsp[0]).label << endl;
						variable Var = searchForGlobalVariable((yyvsp[-3]).label);
						variable Var2 = searchForGlobalVariable((yyvsp[0]).label);

						if((Var2.tipo != Var.tipo)){

							if((Var2.tipo == "char" && Var.tipo != "char") || (Var2.tipo == "bool" && Var.tipo != "bool") || (Var2.tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}

							else{

								(yyval).tipo = Var.tipo;
								cout << "TIPO VAR 2: " << Var2.valor << endl;
								(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + "(" + Var.tipo + ") " + Var2.nome + ";\n";
							}
						}

						else{

							(yyval).tipo = Var2.tipo;
							(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var2.nome + ";\n";
						}
					}
#line 2916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1127 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-2]).label);
						variable Var2 = searchForVariable((yyvsp[0]).label);
						if(((yyvsp[0]).tipo != Var.tipo)){

							if(((yyvsp[0]).tipo == "char" && Var.tipo != "char") || ((yyvsp[0]).tipo == "bool" && Var.tipo != "bool") || ((yyvsp[0]).tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + (yyvsp[0]).tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							(yyval).tipo = Var.tipo;
							(yyval).label = Var.nome;
							(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " + " + (yyvsp[0]).label + ";\n";
						}
					}
#line 2938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1146 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-2]).label);
						variable Var2 = searchForVariable((yyvsp[0]).label);
						if(((yyvsp[0]).tipo != Var.tipo)){

							if(((yyvsp[0]).tipo == "char" && Var.tipo != "char") || ((yyvsp[0]).tipo == "bool" && Var.tipo != "bool") || ((yyvsp[0]).tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + (yyvsp[0]).tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							(yyval).tipo = Var.tipo;
							(yyval).label = Var.nome;
							(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " - " + (yyvsp[0]).label + ";\n";
						}
					}
#line 2960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1165 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-2]).label);
						variable Var2 = searchForVariable((yyvsp[0]).label);
						if(((yyvsp[0]).tipo != Var.tipo)){

							if(((yyvsp[0]).tipo == "char" && Var.tipo != "char") || ((yyvsp[0]).tipo == "bool" && Var.tipo != "bool") || ((yyvsp[0]).tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + (yyvsp[0]).tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							(yyval).tipo = Var.tipo;
							(yyval).label = Var.nome;
							(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " * " + (yyvsp[0]).label + ";\n";
						}
					}
#line 2982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1184 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-2]).label);
						variable Var2 = searchForVariable((yyvsp[0]).label);
						if(((yyvsp[0]).tipo != Var.tipo)){

							if(((yyvsp[0]).tipo == "char" && Var.tipo != "char") || ((yyvsp[0]).tipo == "bool" && Var.tipo != "bool") || ((yyvsp[0]).tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + (yyvsp[0]).tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							(yyval).tipo = Var.tipo;
							(yyval).label = Var.nome;
							(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " / " + (yyvsp[0]).label + ";\n";
						}
					}
#line 3004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1204 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-3]).label);
						variable Var2 = searchForGlobalVariable((yyvsp[0]).label);
						if((Var2.tipo != Var.tipo)){

							if((Var2.tipo == "char" && Var.tipo != "char") || (Var2.tipo == "bool" && Var.tipo != "bool") || (Var2.tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							(yyval).tipo = Var.tipo;
							(yyval).label = Var.nome;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + Var.nome + " = " + Var.nome + " + " + Var2.nome + ";\n";
						}
					}
#line 3026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1223 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-3]).label);
						variable Var2 = searchForGlobalVariable((yyvsp[0]).label);
						if((Var2.tipo != Var.tipo)){

							if((Var2.tipo == "char" && Var.tipo != "char") || ((yyvsp[-1]).tipo == "bool" && Var.tipo != "bool") || (Var2.tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							(yyval).tipo = Var.tipo;
							(yyval).label = Var.nome;
							(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " - " + Var2.nome + ";\n";
						}
					}
#line 3048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1242 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-3]).label);
						variable Var2 = searchForVariable((yyvsp[0]).label);
						if((Var2.tipo != Var.tipo)){

							if((Var2.tipo == "char" && Var.tipo != "char") || (Var2.tipo == "bool" && Var.tipo != "bool") || (Var2.tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							(yyval).tipo = Var.tipo;
							(yyval).label = Var.nome;
							(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " * " + Var2.nome + ";\n";
						}
					}
#line 3070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1261 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-3]).label);
						variable Var2 = searchForGlobalVariable((yyvsp[0]).label);
						if((Var2.tipo != Var.tipo)){

							if((Var2.tipo == "char" && Var.tipo != "char") || (Var2.tipo == "bool" && Var.tipo != "bool") || (Var2.tipo == "string" && Var.tipo != "string")){
								string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}
						}
						else{

							(yyval).tipo = Var.tipo;
							(yyval).label = Var.nome;
							(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var.nome + " / " + Var2.nome + ";\n";
						}
					}
#line 3092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1280 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-3]).label);
						//unordered_map<string, variable> tabSym = contextoVariaveis.back();
						if(((yyvsp[0]).tipo == "char" && Var.tipo != "char") || ((yyvsp[0]).tipo == "bool" && Var.tipo != "bool")){
							string msgError = "Atribuição de " + (yyvsp[0]).tipo + " em " + Var.tipo  + " é inválida!\n";
							yyerror(msgError);
						}

						else{

							if((Var.tipo == "int") && (yyvsp[0]).tipo == "float"){

								cout << "Conversão para float em "<< Var.nome << " não suportada! Resultado será armazenado como inteiro!\n" << endl;
								(yyval).tipo = "int";
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + Var.nome + " = " + (yyvsp[0]).label + ";\n";
							}
							else{
									(yyval).tipo = "float";
									(yyval).traducao = (yyvsp[0]).traducao + "\t" + Var.nome + " = (float) " + (yyvsp[0]).label + ";\n";
							}
						}
					}
#line 3119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1304 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-3]).label);
						//unordered_map<string, variable> tabSym = contextoVariaveis.back();
						if(((yyvsp[0]).tipo == "char" && Var.tipo != "char") || ((yyvsp[0]).tipo == "bool" && Var.tipo != "bool")){
							string msgError = "Atribuição de " + (yyvsp[0]).tipo + " em " + Var.tipo  + " é inválida!\n";
							yyerror(msgError);
						}

						else{

							(yyval).traducao = (yyvsp[0]).traducao + "\t" + Var.nome + " = (int) " + (yyvsp[0]).label + ";\n";
						}
					}
#line 3137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1320 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-4]).label);
						variable Var2 = searchForGlobalVariable((yyvsp[0]).label);
						//unordered_map<string, variable> tabSym = contextoVariaveis.back();
						if((Var2.tipo == "char" && Var.tipo != "char") || (Var2.tipo == "bool" && Var.tipo != "bool")){
							string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
							yyerror(msgError);
						}

						else{

							if((Var.tipo == "int") && Var2.tipo == "float"){

								cout << "Conversão para float em "<< Var.nome << " não suportada! Resultado será armazenado como inteiro!\n" << endl;
								(yyval).tipo = "int";
								(yyval).traducao = Var2.valor + "\t" + Var.nome + " = " + Var2.nome + ";\n";
							}
							else{
									(yyval).tipo = "float";
									(yyval).traducao = Var2.valor + "\t" + Var.nome + " = (float) " + Var2.nome + ";\n";
							}
						}
					}
#line 3165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1345 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-4]).label);
						variable Var2 = searchForGlobalVariable((yyvsp[0]).label);
						//unordered_map<string, variable> tabSym = contextoVariaveis.back();
						if((Var2.tipo == "char" && Var.tipo != "char") || (Var2.tipo == "bool" && Var.tipo != "bool")){
							string msgError = "Atribuição de " + Var2.tipo + " em " + Var.tipo  + " é inválida!\n";
							yyerror(msgError);
						}

						else{

							(yyval).traducao = Var2.valor + "\t" + Var.nome + " = (int) " + Var2.nome + ";\n";
						}
					}
#line 3184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1361 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-4]).label);
						map_vetor[Var.nome] = tamanho_vetor;
						cout << Var.nome << endl;
						cout << Var.tipo << endl;
						cout << Var.valor << endl;

						if(Var.tipo != (yyvsp[-1]).tipo + '*'){

							yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
						}

						else{

							if(map_linhas[Var.nome] >= map_vetor[Var.nome]){

								(yyval).traducao = (yyvsp[-1]).traducao + addElementsToArray(map_vetor[Var.nome], Var.nome);
								cout << "TAMANHO VETOR: " << tamanho_vetor <<"\nTAMANHO LINHA: " << tamanho_linhas << endl;
								map_linhas[Var.nome] = map_linhas[Var.nome] - map_vetor[Var.nome];
								cout << "TAMANHO LINHA ATUAL: " << tamanho_linhas << endl;
								tamanho_vetor = 0;
								map_vetor[Var.nome] = 0;
							}

							else{
								yyerror("Vetor atribuido maior que suportado na variável!");
							}
						}
					}
#line 3218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1392 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-4]).label);
						cout << Var.nome << endl;
						cout << Var.tipo << endl;
						cout << Var.valor << endl;
						if(Var.tipo != (yyvsp[-1]).tipo + '*'){
							yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
						}
						else{
						if(tamanho_vetor > elementos_matriz){
								yyerror("Vetor atribuido maior que variável suporta!");
							}
							else{
								variable Var = searchForVariable((yyvsp[-4]).label);
								(yyval).traducao = (yyvsp[-1]).traducao + addElementsToArray(elementos_matriz, Var.nome);
								//tamanho_vetor -= tamanho_linhas;
								tamanho_vetor = 0;
							}
						}
					}
#line 3243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1414 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-4]).label);

						if(Var.tipo != (yyvsp[0]).tipo + "*"){
							cout << "TIPO E: " << Var.tipo << endl;
							yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
						}

						else{
							if(map_linhas[Var.nome] != 0){
								variable pointer = arrayPointerNames[Var.nome];
								variable kmpls = searchForVariable((yyvsp[-3]).label);
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + pointer.nome + " = " + kmpls.nome +
								";\n\t" + Var.nome + "[" + pointer.nome + "] = " + (yyvsp[0]).label + ";\n";
							}
						}
					}
#line 3265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1433 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-4]).label);

						if(Var.tipo != (yyvsp[0]).tipo + "*"){

							yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
						}

						else{
							if(map_linhas[Var.nome] != 0){
								//checkForVariable($2.label);
								variable pointer = arrayPointerNames[Var.nome];
								//variable kmpls = searchForVariable($3.label);
								(yyval).traducao = (yyvsp[-3]).traducao + (yyvsp[0]).traducao + "\t" + pointer.nome + " = " + (yyvsp[-3]).label +
								";\n\t" + Var.nome + "[" + pointer.nome + "] = " + (yyvsp[0]).label + ";\n";
							}
						}
					}
#line 3288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1453 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-4]).label);
						variable Vector = searchForVariable((yyvsp[-2]).label);
						variable Index = searchForVariable((yyvsp[-1]).label);

						if(Var.tipo + "*" != Vector.tipo){

							yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
						}

						else{

							variable pointer = arrayPointerNames[Vector.nome];
							(yyval).traducao = "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
							Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
						}
					}
#line 3310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1473 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-4]).label);
						variable Vector = searchForVariable((yyvsp[-2]).label);
						variable Index = searchForVariable((yyvsp[-1]).label);

						if(Var.tipo + "*" != Vector.tipo){

							yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
						}

						else{

							variable pointer = arrayPointerNames[Vector.nome];
							(yyval).traducao = (yyvsp[-1]).traducao + "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
							Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
						}
					}
#line 3332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1493 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-5]).label);
						variable Var2 = searchForGlobalVariable((yyvsp[0]).label);

						if(Var.tipo != Var2.tipo + "*"){
							cout << "NOME E: " << (yyvsp[0]).label << endl;
							cout << "TIPO E: " << Var2.tipo << endl;
							yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
						}

						else{

							if(map_linhas[Var.nome] != 0){
								variable pointer = arrayPointerNames[Var.nome];
								variable kmpls = searchForVariable((yyvsp[-4]).label);
								(yyval).traducao = Var2.valor + "\t" + pointer.nome + " = " + kmpls.nome +
								";\n\t" + Var.nome + "[" + pointer.nome + "] = " + Var2.nome + ";\n";
							}
						}
					}
#line 3357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1515 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-5]).label);
						variable Var2 = searchForGlobalVariable((yyvsp[0]).label);

						if(Var.tipo != Var2.tipo + "*"){

							yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
						}

						else{
							if(map_linhas[Var.nome] != 0){
								//checkForVariable($2.label);
								variable pointer = arrayPointerNames[Var.nome];
								//variable kmpls = searchForVariable($3.label);
								(yyval).traducao = (yyvsp[-4]).traducao + Var2.valor + "\t" + pointer.nome + " = " + (yyvsp[-4]).label +
								";\n\t" + Var.nome + "[" + pointer.nome + "] = " + Var2.nome + ";\n";
							}
						}
					}
#line 3381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1536 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-5]).label);
						variable Vector = searchForGlobalVariable((yyvsp[-2]).label);
						variable Index = searchForVariable((yyvsp[-1]).label);

						if(Var.tipo + "*" != Vector.tipo){

							cout << "TIPO i: " << Var.tipo << endl;
							yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
						}

						else{

							variable pointer = arrayPointerNames[Vector.nome];
							(yyval).traducao = "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
							Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
						}
					}
#line 3404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1557 "sintatica.y" /* yacc.c:1646  */
    {
						variable Var = searchForGlobalVariable((yyvsp[-5]).label);
						variable Vector = searchForGlobalVariable((yyvsp[-2]).label);
						variable Index = searchForVariable((yyvsp[-1]).label);

						if(Var.tipo + "*" != Vector.tipo){

							yyerror("Atribuição de elemento de vetor em uma variável de tipo incompatível!");
						}

						else{

							variable pointer = arrayPointerNames[Vector.nome];
							(yyval).traducao = (yyvsp[-1]).traducao + "\t" + pointer.nome + " = " + Index.nome + ";\n\t" +
							Var.nome + " = " + Vector.nome + "[" + pointer.nome + "];\n";
						}
					}
#line 3426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1577 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							(yyval).traducao = "";
							addVarToTabSym(nomeAuxID, (yyvsp[-1]).label, "none", "char");
							addVarToTempVector("\tchar " + nomeAuxID +  ";\n");
						}
#line 3437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1592 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							(yyval).traducao = "\t" + nomeAuxID + " = 0;\n";
							addVarToTabSym(nomeAuxID, (yyvsp[-1]).label, (yyval).traducao, "int");
							addVarToTempVector("\tint " + nomeAuxID + ";\n");
						}
#line 3448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1600 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();

							(yyval).traducao = "\t" + nomeAuxID + " = 0.0;\n";;
							addVarToTabSym(nomeAuxID, (yyvsp[-1]).label, (yyval).traducao, "float");
							addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
						}
#line 3460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1609 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							(yyval).traducao = "\t" + nomeAuxID + " = TRUE;\n";;
							addVarToTabSym(nomeAuxID, (yyvsp[-1]).label, (yyval).traducao, "bool");
							addVarToTempVector("\tint " + nomeAuxID + ";\n");
						}
#line 3471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1621 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable((yyvsp[-1]).label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							(yyval).traducao = "\t" + nomeAuxID + " = (char*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(char));\n";
							addVarToTabSym(nomeAuxID, (yyval).label, "empty", "char*");
							addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
						}
#line 3501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1648 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable((yyvsp[-1]).label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							(yyval).traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(float));\n";
							addVarToTabSym(nomeAuxID, (yyvsp[0]).label, "empty", "float*");
							addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
						}
#line 3531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1675 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable((yyvsp[-1]).label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							(yyval).traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(int));\n";
 							addVarToTabSym(nomeAuxID, (yyvsp[0]).label, "empty", "int*");
							addVarToTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 3561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1703 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							(yyval).traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(int));\n";
							addVarToTabSym(nomeAuxID, (yyvsp[0]).label, "empty", "int*");
							addVarToTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 3589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1728 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							(yyval).traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(float));\n";
							addVarToTabSym(nomeAuxID, (yyvsp[0]).label, "empty", "float*");
							addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
						}
#line 3617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1753 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							(yyval).traducao = "\t" + nomeAuxID + " = (char*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(char));\n";
							addVarToTabSym(nomeAuxID, (yyvsp[0]).label, "empty", "char*");
							addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
						}
#line 3645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1780 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							(yyval).traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(50 * sizeof(int));\n";
							addVarToTabSym(nomeAuxID, (yyvsp[-2]).label, "empty", "int*");
							//tamanho_vetor = 50;
							addVarToTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 3674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1806 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();

							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							(yyval).traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							to_string(tamanho_vetor) + " * sizeof(float));\n";
							addVarToTabSym(nomeAuxID, (yyvsp[-2]).label, "empty", "float*");
							addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
						}
#line 3704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1833 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							(yyval).traducao = "\t" + nomeAuxID + " = (char*) malloc(50 * sizeof(char));\n";
							addVarToTabSym(nomeAuxID, (yyvsp[-2]).label, "empty", "char*");
							addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
						}
#line 3732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1860 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							addVarToTabSym(nomeAuxID, (yyvsp[-1]).label, "none", "char");
							(yyval).traducao = "";
							addVarToGlobalTempVector("\tchar " + nomeAuxID + ";\n");
						}
#line 3743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1874 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							(yyval).traducao = "\t" + nomeAuxID + " = 0;\n";
							addVarToGlobalTabSym(nomeAuxID, (yyvsp[-1]).label, (yyval).traducao, "int");
							//addVarToGlobalTempVector("\tint " + nomeAuxID + ";\n");
						}
#line 3754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1882 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							(yyval).traducao = "\t" + nomeAuxID + " = 0.0;\n";
							addVarToGlobalTabSym(nomeAuxID, (yyvsp[-1]).label, (yyval).traducao, "float");
							addVarToGlobalTempVector("\tfloat " + nomeAuxID + ";\n");
						}
#line 3765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1890 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							(yyval).traducao = "\t" + nomeAuxID + " = TRUE;\n";
							addVarToGlobalTabSym(nomeAuxID, (yyvsp[-1]).label, (yyval).traducao, "bool");
							addVarToGlobalTempVector("\tint " + nomeAuxID + ";\n");
						}
#line 3776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1901 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							(yyval).traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(50 * sizeof(int));\n";
							addVarToGlobalTabSym(nomeAuxID, (yyvsp[-2]).label, "empty", "int*");
						}
#line 3803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1925 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();

							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							(yyval).traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							to_string(tamanho_vetor) + " * sizeof(float));\n";
							addVarToGlobalTabSym(nomeAuxID, (yyvsp[-2]).label, "empty", "float*");
						}
#line 3832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1951 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							map_linhas[nomeAuxID] = 50;
							(yyval).traducao = "\t" + nomeAuxID + " = (char*) malloc(50 * sizeof(char));\n";
							addVarToGlobalTabSym(nomeAuxID, (yyvsp[-2]).label, "empty", "char*");
						}
#line 3859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1977 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable((yyvsp[-1]).label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							(yyval).traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(int));\n";
 							addVarToGlobalTabSym(nomeAuxID, (yyvsp[0]).label, "empty", "int*");
							//addVarToGlobalTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 3889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 2004 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable((yyvsp[-1]).label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							(yyval).traducao = trad + "\t" + nomeAuxID + " = (float*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(float));\n";
 							addVarToGlobalTabSym(nomeAuxID, (yyvsp[0]).label, "empty", "float*");
							//addVarToGlobalTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 3919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 2031 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");
							variable auxiliarInteiro = searchForVariable((yyvsp[-1]).label);
							map_linhas[nomeAuxID] = tamanho_linhas;

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							(yyval).traducao = trad + "\t" + nomeAuxID + " = (char*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(char));\n";
 							addVarToGlobalTabSym(nomeAuxID, (yyvsp[0]).label, "empty", "char*");
							//addVarToGlobalTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 3949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 2059 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							(yyval).traducao = trad + "\t" + nomeAuxID + " = (int*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(int));\n";
							addVarToGlobalTabSym(nomeAuxID, (yyvsp[0]).label, "empty", "int*");
						}
#line 3976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 2083 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							(yyval).traducao = trad + "\t" + nomeAuxID + " = (float*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(float));\n";
							addVarToGlobalTabSym(nomeAuxID, (yyvsp[0]).label, "empty", "float*");
						}
#line 4003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 2107 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = genLabel();
							stackVectors.push("\tfree(" + nomeAuxID + ");\n");

							string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
							string nome1 = "Auxiliar" + to_string(valorAuxiliar++);
							string nomeAux = genLabel();
							addVarToTabSym(nomeAux, nome0, "0", "int");
							string acrescimo = genLabel();
							addVarToTabSym(acrescimo, nome1, "1", "int");
							addVarToTempVector("\tint " + nomeAux + ";\n");
							addVarToTempVector("\tint " + acrescimo + ";\n");
							Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
							Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
							string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";
							arrayPointerNames[nomeAuxID] = Var1; //aqui eu armazeno o nome da variável que servirá de ponteiro pro vetor
							arrayPointerNames[nomeAuxID + "Acrescimo"] =  Var2; //essa é o " + 1"

							(yyval).traducao = trad + "\t" + nomeAuxID + " = (char*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(char));\n";
							addVarToGlobalTabSym(nomeAuxID, (yyvsp[0]).label, "empty", "char*");
						}
#line 4030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 2132 "sintatica.y" /* yacc.c:1646  */
    {
									 (yyval) = (yyvsp[-1]);
									 stringstream tamanho;

									 tamanho << (yyvsp[-1]).traducao;
									 string temp;
									 int found;

									 while(!tamanho.eof()){
										 tamanho >> temp;

										 if(stringstream(temp) >> found){
											 cout << "______________ " << found << endl;
											 tamanho_linhas = found;
										 }
									 }
								 }
#line 4052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 2152 "sintatica.y" /* yacc.c:1646  */
    {
									(yyval) = (yyvsp[-1]);
									stringstream tamanho;

									tamanho << (yyvsp[-1]).traducao;
									string temp;
									int found;

									while(!tamanho.eof()){
										tamanho >> temp;

										if(stringstream(temp) >> found){
											cout << "______________ " << found << endl;
											tamanho_linhas = found;
										}
									}
								}
#line 4074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 2171 "sintatica.y" /* yacc.c:1646  */
    {
									 (yyval) = (yyvsp[-4]);

									 //cout << $4.traducao << $7.traducao << endl;

									 stringstream v0;
									 stringstream v1;

									 v0 << (yyvsp[-4]).traducao;
									 v1 << (yyvsp[-1]).traducao;

									 string temp;

									 int found0;
									 int found1;

									 while(!v0.eof()){

										 //extraindo palavra por palavra
										 v0 >> temp;

										 //checando se a palavra é um inteiro ou não
										 if(stringstream(temp) >> found0){
											 //cout << found0 << " ";
										 }
									 }

									 while(!v1.eof()){

										 v1 >> temp;

										 if(stringstream(temp) >> found1){
											 //cout << found1 << " ";
										 }
									 }

									 cout << "tamanho linhas " << found0 << "\ntamanho colunas " << found1 << endl;
									 tamanho_linhas = found0;
									 tamanho_colunas = found1;
									 elementos_matriz = tamanho_linhas * tamanho_colunas;
									 cout << "quantidade de elementos na matriz: " << elementos_matriz << endl;
									 //tamanho_vetor =  found0 * found1;
								 }
#line 4122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 2217 "sintatica.y" /* yacc.c:1646  */
    {
									(yyval) = (yyvsp[-4]);

									//cout << $4.traducao << $7.traducao << endl;

									stringstream v0;
									stringstream v1;

									v0 << (yyvsp[-4]).traducao;
									v1 << (yyvsp[-1]).traducao;

									string temp;

									int found0;
									int found1;

									while(!v0.eof()){

										//extraindo palavra por palavra
										v0 >> temp;

										//checando se a palavra é um inteiro ou não
										if(stringstream(temp) >> found0){
											//cout << found0 << " ";
										}
									}

									while(!v1.eof()){

										v1 >> temp;

										if(stringstream(temp) >> found1){
											//cout << found1 << " ";
										}
									}

									cout << "tamanho linhas " << found0 << "\ntamanho colunas " << found1 << endl;
									tamanho_linhas = found0;
									tamanho_colunas = found1;
									elementos_matriz = tamanho_linhas * tamanho_colunas;
									cout << "quantidade de elementos na matriz: " << elementos_matriz << endl;
									//tamanho_vetor =  found0 * found1;
								}
#line 4170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 2261 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 4176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 2262 "sintatica.y" /* yacc.c:1646  */
    {
						if((yyvsp[-2]).tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + (yyvsp[-2]).label;
							(yyval).traducao = "\n//if\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + (yyvsp[-2]).traducao + "\n\t" + auxVar + " = " +
							auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + (yyvsp[0]).traducao + "\tfinal" +
							to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
#line 4198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 2281 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 4204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 2282 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval) = (yyvsp[-2]);
					}
#line 4212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 2288 "sintatica.y" /* yacc.c:1646  */
    {
						int posiAlteracao = (yyvsp[-1]).traducao.rfind("final");
						string auxRetorno = (yyvsp[-1]).traducao;
						auxRetorno.insert(posiAlteracao, "goto final" + to_string(stackLoops.top()) + ";\n\n\t");
						(yyval).traducao = auxRetorno + "\n//else\n" + (yyvsp[0]).traducao + "\tfinal" + to_string(stackLoops.top()) + ":\n";
						stackLoops.pop();
						contextoVariaveis.pop_back();
						mapAtual--;
					}
#line 4226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 2299 "sintatica.y" /* yacc.c:1646  */
    {
						if((yyvsp[-2]).tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + (yyvsp[-2]).label;
							(yyval).traducao = (yyvsp[-5]).traducao + "\n//else if\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + (yyvsp[-2]).traducao + "\n\t" + auxVar + " = " +
							auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + (yyvsp[0]).traducao + "\tfinal" +
							to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
#line 4248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 2319 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("while");}
#line 4254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 2320 "sintatica.y" /* yacc.c:1646  */
    {
						if((yyvsp[-2]).tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + (yyvsp[-2]).label;
							(yyval).traducao = "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + (yyvsp[-2]).traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
							auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + (yyvsp[0]).traducao + "\tgoto loop" + to_string(stackLoops.top()) +
							";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
#line 4276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 2339 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("while");}
#line 4282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 2340 "sintatica.y" /* yacc.c:1646  */
    {
						if((yyvsp[-1]).tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + (yyvsp[-1]).label;
							(yyval).traducao = "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + (yyvsp[-4]).traducao + "\n\tloop" + to_string(stackLoops.top()) + ":\n" + (yyvsp[-1]).traducao +
							"\t" + auxVar + " = " + auxVar2 + ";\n\tif (" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n\tgoto comeco" + to_string(stackLoops.top()) +
							";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
#line 4304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 2359 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("for");}
#line 4310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 2360 "sintatica.y" /* yacc.c:1646  */
    {
				  	(yyval) = (yyvsp[0]);
				  }
#line 4318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 2364 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("for");}
#line 4324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 2365 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval) = (yyvsp[-1]);
					}
#line 4332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 2370 "sintatica.y" /* yacc.c:1646  */
    {

							variable Var = searchForVariable((yyvsp[-3]).label);

				  		if((yyvsp[-3]).tipo != "bool"){
				  			string msgError = "For somente itera sobre booleano! Tentativa de iterar sobre " + (yyvsp[-3]).tipo + " inválida!\n";
				  			yyerror(msgError);
				  		}

				  		string nomeVar = genLabel();
							addVarToTempVector("\tint " + nomeVar + ";\n");

				  		string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");

							string auxVar2 = genLabel();
							string auxVar3 = "!" + (yyvsp[-3]).label;

							(yyval).traducao = "\n//for\n\n" + (yyvsp[-5]).traducao + "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + (yyvsp[-3]).traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
							auxVar3 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + (yyvsp[0]).traducao + "\t" + nomeVar + " = " + Var.nome + " + 1;\n" +
							"\tgoto loop" + to_string(stackLoops.top()) + ";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							addVarToTabSym(nomeVar, (yyvsp[-1]).label, (yyvsp[-1]).traducao, (yyvsp[-1]).tipo);
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
#line 4363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 2398 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-3]).label);

					  	if((yyvsp[-3]).tipo != "bool"){
					  		string msgError = "For somente itera sobre booleano! Tentativa de iterar sobre " + (yyvsp[-3]).tipo + " inválida!\n";
					  		yyerror(msgError);
					  	}

						  string nomeVar = genLabel();
							addVarToTempVector("\tint " + nomeVar + ";\n");

						  string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");

							string auxVar2 = genLabel();
							string auxVar3 = "!" + (yyvsp[-3]).label;

							(yyval).traducao = "\n//for\n" + (yyvsp[-3]).traducao + "\n\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
							auxVar3 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + (yyvsp[0]).traducao + (yyvsp[-1]).traducao + "\n" +
							"\tgoto loop" + to_string(stackLoops.top()) + ";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
#line 4392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 2425 "sintatica.y" /* yacc.c:1646  */
    {
						if(stackLoops.empty()){
							(yyval).traducao = "";
						}

						else if(stackCommands.empty()){
							yyerror("Break fora de um laço. Erro!");
						}

						else{
							(yyval).traducao = "\n\tgoto final" + to_string(stackLoops.top()) + "; //isso é um break\n\n";
						}
					}
#line 4410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 2440 "sintatica.y" /* yacc.c:1646  */
    {
						if(stackLoops.empty()){
							(yyval).traducao = "";
						}

						else if(stackCommands.empty()){
							yyerror("Continue fora de um laço. Erro!");
						}

						else{
							(yyval).traducao = "\n\tgoto comeco" + to_string(stackLoops.top()) + "; //isso é um continue\n\n";
						}
					}
#line 4428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 2455 "sintatica.y" /* yacc.c:1646  */
    {
						structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

						if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[-2]).label){ //var1 != var2, sendo var2 float
							(yyval).label = genLabel();
							(yyval).tipo = "float";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " + " + (yyvsp[0]).label + ";\n";

						}

						else if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[0]).label){ //var1 != var2, sendo var1 float
							(yyval).label = genLabel();
							(yyval).tipo = "float";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " + " + aux.nomeVar + ";\n";

						}

						else{ //se as duas variáveis são do mesmo tipo
							(yyval).label = genLabel();
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " + " + (yyvsp[0]).label + ";\n";

						}
							addVarToTempVector("\t" + (yyval).tipo + " " + (yyval).label  + ";\n");
					}
#line 4457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 2481 "sintatica.y" /* yacc.c:1646  */
    {

						structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

						if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[-2]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "float";
							(yyval).traducao =  (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " - " + (yyvsp[0]).label + ";\n";
						}
						else if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[0]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "float";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " - " + aux.nomeVar + ";\n";
						}
						else{ //se as duas variáveis são do mesmo tipo
							(yyval).label = genLabel();
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " - " + (yyvsp[0]).label + ";\n";
						}
						addVarToTempVector("\t" + (yyval).tipo + " " + (yyval).label + ";\n");
					}
#line 4482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 2503 "sintatica.y" /* yacc.c:1646  */
    {

						structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

						if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[-2]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "float";
							(yyval).traducao =  (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " * " + (yyvsp[0]).label + ";\n";
						}
						else if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[0]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "float";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " * " + aux.nomeVar + ";\n";
						}
						else{ //se as duas variáveis são do mesmo tipo
							(yyval).label = genLabel();
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " * " + (yyvsp[0]).label + ";\n";
						}
						addVarToTempVector("\t" + (yyval).tipo + " " + (yyval).label + ";\n");
					}
#line 4507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 2525 "sintatica.y" /* yacc.c:1646  */
    {
						structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

						if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[-2]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "float";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " / " + (yyvsp[0]).label + ";\n";
						}

						else if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[0]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "float";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " / " + aux.nomeVar + ";\n";
						}

						else{ //se as duas variáveis são do mesmo tipo
							(yyval).label = genLabel();
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " / " + (yyvsp[0]).label + ";\n";
						}

						addVarToTempVector("\t" + (yyval).tipo + " " + (yyval).label + ";\n");
					}
#line 4534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 2549 "sintatica.y" /* yacc.c:1646  */
    {

						variable Var = searchForVariable((yyvsp[-1]).label);
						(yyval).tipo = Var.tipo;
						(yyval).label = Var.nome;
						(yyval).traducao = "\t" + Var.nome + " = " + Var.nome + " + 1;\n";
					}
#line 4546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 2558 "sintatica.y" /* yacc.c:1646  */
    {

						variable Var = searchForVariable((yyvsp[-1]).label);
						(yyval).tipo = Var.tipo;
						(yyval).label = Var.nome;
						(yyval).traducao = "\t" + Var.nome + " = " + Var.nome + " - 1;\n";
					}
#line 4558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 2567 "sintatica.y" /* yacc.c:1646  */
    {
						structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

						if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[-2]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " < " + (yyvsp[0]).label + ";\n";
						}

						else if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[0]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " < " + aux.nomeVar + ";\n";
						}

						else{ //se as duas variáveis são do mesmo tipo
							(yyval).label = genLabel();
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " < " + (yyvsp[0]).label + ";\n";

						}
						addVarToTempVector("\tint " + (yyval).label + ";\n");
					}
#line 4586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 2592 "sintatica.y" /* yacc.c:1646  */
    {
						structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

						if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[-2]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " > " + (yyvsp[0]).label + ";\n";
						}
						else if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[0]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao +  aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " > " + aux.nomeVar + ";\n";
						}
						else{ //se as duas variáveis são do mesmo tipo
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " > " + (yyvsp[0]).label + ";\n";
						}

						addVarToTempVector("\tint " + (yyval).label + ";\n");
					}
#line 4611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 2614 "sintatica.y" /* yacc.c:1646  */
    {
						structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

						if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[-2]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "int";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " <= " + (yyvsp[0]).label + ";\n";
						}
						else if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[0]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "int";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " <= " + aux.nomeVar + ";\n";
						}
						else{ //se as duas variáveis são do mesmo tipo
							(yyval).label = genLabel();
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " <= " + (yyvsp[0]).label + ";\n";
						}

						addVarToTempVector("\tint " + (yyval).label + ";\n");
					}
#line 4636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 2636 "sintatica.y" /* yacc.c:1646  */
    {

						structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);
						if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[-2]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " >= " + (yyvsp[0]).label + ";\n";
						}
						else if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[0]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " >= " + aux.nomeVar + ";\n";
						}
						else{ //se as duas variáveis são do mesmo tipo
							(yyval).label = genLabel();
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " >= " + (yyvsp[0]).label + ";\n";
						}

						addVarToTempVector("\tint " + (yyval).label + ";\n");
					}
#line 4662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 2659 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = genLabel();
						(yyval).tipo = isBoolean((yyvsp[-2]).tipo, (yyvsp[0]).tipo);
						(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " || " + (yyvsp[0]).label + ";\n";
						addVarToTempVector("\tint " + (yyval).label + ";\n");
					}
#line 4673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 2667 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = genLabel();
						(yyval).tipo = isBoolean((yyvsp[-2]).tipo, (yyvsp[0]).tipo);
						(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " && " + (yyvsp[0]).label + ";\n";
						addVarToTempVector("\tint " + (yyval).label + ";\n");
					}
#line 4684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 2675 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval) = (yyvsp[0]);
						(yyval).tipo = isBoolean("bool", (yyvsp[0]).tipo);
						(yyval).label = genLabel();
						(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = !" + (yyvsp[0]).label + ";\n";
						addVarToTempVector("\tint " + (yyval).label + ";\n");
					}
#line 4696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 2684 "sintatica.y" /* yacc.c:1646  */
    {
						structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);
						if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[-2]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " == " + (yyvsp[0]).label + ";\n";
						}
						else if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[0]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " == " + aux.nomeVar + ";\n";
						}
						else{ //se as duas variáveis são do mesmo tipo
							(yyval).label = genLabel();
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " == " + (yyvsp[0]).label + ";\n";
						}

						addVarToTempVector("\tint " + (yyval).label + ";\n");
					}
#line 4721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 2706 "sintatica.y" /* yacc.c:1646  */
    {

						structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);
						if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[-2]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " != " + (yyvsp[0]).label + ";\n";
						}
						else if(((yyvsp[-2]).tipo != (yyvsp[0]).tipo) && aux.varConvertida == (yyvsp[0]).label){
							(yyval).label = genLabel();
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " != " + aux.nomeVar + ";\n";
						}
						else{ //se as duas variáveis são do mesmo tipo
							(yyval).label = genLabel();
							(yyval).tipo = "bool";
							(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " != " + (yyvsp[0]).label + ";\n";
						}

						addVarToTempVector("\tint " + (yyval).label + ";\n");
					}
#line 4747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 2729 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval) = (yyvsp[-1]);
					}
#line 4755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 2734 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = "nomeTemporarioInt" + to_string(valorTemp++);
						(yyval).tipo = "int";
						addVarToTempVector("\tint " + (yyval).label + ";\n");
						(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
						addVarToTabSym((yyval).label, (yyval).label, (yyval).traducao, "int");
					}
#line 4767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 2743 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = "nomeTemporarioFloat" + to_string(valorTemp++);
						(yyval).tipo = "float";
						addVarToTempVector("\tfloat " + (yyval).label + ";\n");
						(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
						addVarToTabSym((yyval).label, (yyval).label, (yyval).traducao, "float");
				 	}
#line 4779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 2752 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = "nomeTemporarioChar" + to_string(valorTemp++);
						(yyval).tipo = "char";
						addVarToTempVector("\tchar "  + (yyval).label + ";\n");
						(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
						addVarToTabSym((yyval).label, (yyval).label, (yyval).traducao, "char");
					}
#line 4791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 2761 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = "nomeTemporarioBool" + to_string(valorTemp++);
						(yyval).tipo = "bool";
						addVarToTempVector("\tint " + (yyval).label + ";\n");
						(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
						addVarToTabSym((yyval).label, (yyval).label, (yyval).traducao, "int");
					}
#line 4803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 2770 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = "nomeTemporarioString" + to_string(valorTemp++);
						(yyval).tipo = "string";
						addVarToTempVector("\tstring "  + (yyval).label + ";\n");
						(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
					}
#line 4814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 2778 "sintatica.y" /* yacc.c:1646  */
    {
						variable auxVar = searchForVariable((yyvsp[0]).label);
						(yyval).label = auxVar.nome;
						(yyval).tipo = auxVar.tipo;
						(yyval).traducao = auxVar.valor;
					}
#line 4825 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4829 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 2785 "sintatica.y" /* yacc.c:1906  */


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	//yydebug = 1;
	yyparse();
	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}

string genLabel(){

	return "temp" + to_string(valorVar++);
	cout << "==== Valor atual: " << valorVar << endl;
}

string addVarToTabSym(string nomeGerado, string nomeDado, string conteudoVar, string tipoVar){

	checkForVariable(nomeDado);
	unordered_map<string, variable> tabSym = contextoVariaveis.back();
	cout << "\ntabSym antes " << (tabSym.empty() ? "is empty" : "is not empty" ) << endl;
	cout << "\nconteudo da variavel: " << conteudoVar << endl;
	unordered_map<string, variable>::const_iterator got = tabSym.find(nomeDado);

	if(got == tabSym.end()){

		variable Var2;

		Var2 =	{
							.tipo = tipoVar,
							.nome = nomeGerado,
							.valor = conteudoVar
		  			};

		tabSym[nomeDado] = Var2;
		contextoVariaveis.pop_back();
		contextoVariaveis.push_back(tabSym);
		cout << "tabSym depois " << (contextoVariaveis.empty() ? "is empty" : "is not empty" ) << endl;
		cout << "\nAdicionado " << tabSym[nomeDado].nome << " de tipo "<< tabSym[nomeDado].tipo <<" na tabela de simbolos " << mapAtual << "!\n" << endl;
		return tabSym[nomeDado].nome;
	}

	else {

		return tabSym[nomeDado].nome;
	}

	return "";
}

string addVarToGlobalTabSym(string nomeGerado, string nomeDado, string conteudoVar, string tipoVar){

	checkForVariable(nomeDado);
	cout << "\nglobalTabSym antes " << (globalTabSym.empty() ? "is empty" : "is not empty" ) << endl;
	unordered_map<string, variable>::const_iterator got = globalTabSym.find(nomeDado);

	if(got == globalTabSym.end()){

		variable Var;

		Var =	{
						.tipo = tipoVar,
				   	.nome = nomeGerado,
						.valor = conteudoVar
		  		};

		globalTabSym[nomeDado] = Var;
		cout << "globalTabSym depois " << (globalTabSym.empty() ? "is empty" : "is not empty" ) << endl;
		cout << "\nAdicionado " << globalTabSym[nomeDado].nome << " de tipo "<< globalTabSym[nomeDado].tipo << " na tabela global de simbolos!\n" << endl;
		return globalTabSym[nomeDado].nome;
	}

	else {
		cout << "Variável "<< nomeDado << " não adicionada!" << endl;
		return globalTabSym[nomeDado].nome;
	}

	return "";
}

void printGlobalVariables(){

	unordered_map<string, variable> auxMap = globalTabSym;

	for (auto& it: globalTabSym){

		addVarToGlobalTempVector("\t" + it.second.tipo + " " + it.second.nome + ";\n");
	}

	printGlobalVector();
}

structAux implicitConversion(string tipo0, string tipo1, string nome0, string nome1){

	if(tipo0 == "float" && tipo1 == "int"){ //se a primeira variável for float e segunda for int

		string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);
		addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
		string stringRetorno = "\t" + nomeAuxID + " = (float) " + nome1 + ";\n";

		structAux aux = {

							.implicita = stringRetorno,
							.nomeVar = nomeAuxID,
							.varConvertida = nome1
						};

		return aux;
	}

	else if(tipo0 == "int" && tipo1 == "float") //se a primeira variável for int e a segunda for float
	{

  	string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);
		addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
		string stringRetorno = "\t" + nomeAuxID + " = (float) " + nome0 + ";\n";

		structAux aux = {

											.implicita = stringRetorno,
											.nomeVar = nomeAuxID,
											.varConvertida = nome0
										};

		return aux;

  }

  else if(tipo0 == "float" && tipo1 == "float") //se as duas são float
  {

		string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);
		string stringRetorno = "";
		structAux aux = {

											.implicita = stringRetorno,
											.nomeVar = nomeAuxID,
											.varConvertida = nome0
										};
		return aux;
   }

  else if(tipo0 == "int" && tipo1 == "int") //se as duas são int
  {

		string nomeAuxID = "nomeTemporarioInt" + to_string(valorTemp);
		string stringRetorno = "";
		structAux aux = {

											.implicita = stringRetorno,
											.nomeVar = nomeAuxID,
											.varConvertida = nome0
										};
		return aux;
  }

  else
  {
    yyerror("Nao e possivel realizar operacoes com tipos nao numericos!\n");
  }
}

string explicitConversion(string tipo0, string tipo1){

	if (tipo0 == "char" || tipo0 == "bool")
	{
		yyerror("não é possivel converter em char ou booleano!\n");
	}

	else
	{
		string nomeAuxID = "nomeTemporario" + tipo1 + to_string(valorTemp);
    	addVarToTempVector("\t" + tipo1 + " " + nomeAuxID + ";\n");
    	return tipo1;
	}

	return "";
}

void addVarToTempVector(string nomeVar)
{
	tempVector.push_back(nomeVar);
}

void addVarToGlobalTempVector(string nomeVar)
{
	globalTempVector.push_back(nomeVar);
}

void printVector()
{
	for(auto i: tempVector)
	{
		cout << i;
	}
	cout << "\n\n" << endl;
}

void printGlobalVector()
{
	cout << "\n" << endl;
	for(auto i: globalTempVector)
	{
		cout << i;
	}
	cout << "\n\n" << endl;
}

string isBoolean(string tipo0, string tipo1)
{
	if (tipo1 != "bool" || tipo0 != "bool")
	{
		yyerror("Operacao logica sem tipo booleano!\n");
	}

	else{

		return "bool";
	}

	return "";
}

int erroTipo(string tipo0, string tipo1)
{
	if (tipo1 != tipo0)
	{
		yyerror("tipo de variaveis incompativeis\n");

	}
			return 0;
}

void addMapToStack(void){

	unordered_map<string, variable> auxMap;
	contextoVariaveis.push_back(auxMap);
	mapAtual++;
	cout << "adicionei o map de numero " << mapAtual << " na tabela de mapas!\n" << endl;
}

variable searchForVariable(string nome){

	int i = mapAtual; //inteiro para percorrer o vetor de mapas
	vector<unordered_map<string, variable>> auxVector; //vetor auxiliar para percorrer
	auxVector = contextoVariaveis; //atribuo o vetor de contexto global para o vetor auxiliar
	unordered_map<string, variable> auxMap; //mapa auxiliar para checar as variáveis dele

	cout << "\ncontextoVariaveis " << (contextoVariaveis.empty() ? "is empty" : "is not empty" ) << endl;
	cout << "quantidade de contextos: " << i << endl;
	cout << "variavel buscando: " << nome << endl;
	cout << "auxVector " << (auxVector.empty() ? "is empty" : "is not empty" ) << endl;
	cout << "global " << (globalTabSym.empty() ? "is empty" : "is not empty" ) << endl;

	for(i; i > 0; i--){

		auxMap = auxVector.back();
		auxVector.pop_back();

		cout << "auxMap search iteração " << i << " " << (auxMap.empty() ? "is empty" : "is not empty" ) << endl;

		unordered_map<string, variable>::const_iterator got = auxMap.find(nome); //procuro a variável pelo nome no map mais interno

		if(got != auxMap.end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

			cout << "\n\nEncontrada variável!\nNome: " << nome << "\nTipo: " << auxMap[nome].tipo <<"\nContexto: " << i << endl;
			cout << "Conteudo: " << auxMap[nome].valor << endl;
			variable auxVar = auxMap[nome];
			return auxVar; //se for, retorno essa variável
		}
	}
}

void checkForVariable(string nome){

	unordered_map<string, variable>::const_iterator got = (contextoVariaveis.back()).find(nome); //procuro a variável pelo nome no map mais interno

	if(got != (contextoVariaveis.back()).end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

		string errorMessage = "\n\nEncontrada variável 2!\nNome: " + nome + "\nTipo: " + (contextoVariaveis.back())[nome].tipo + "\n";
		yyerror(errorMessage);
	}
}

variable searchForGlobalVariable(string nome){

	unordered_map<string, variable>::const_iterator got = globalTabSym.find(nome); //procuro a variável pelo nome no map mais interno

	if(got != globalTabSym.end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

		cout << "\n\nEncontrada variável!\nNome: " << nome << "\nTipo: " << globalTabSym[nome].tipo << endl;
		cout << "Conteudo: " << globalTabSym[nome].valor << endl;
		variable auxVar = globalTabSym[nome];
		return auxVar; //se for, retorno essa variável
	}

	else{
		cout << "Não foi encontrada variável de nome " << nome << "!" << endl;
	}
}

string addElementsToArray(int tamanhoArray, string nomeArray){

	string trad = "";
	stack <string> auxStack;

	for(int i = 0; i < tamanhoArray; i++){ //uma das gambiarras mais criminosas que eu fiz
		auxStack.push(label_vet.top());
		label_vet.pop();
		tipo_vet.pop();
		trad_vet.pop();
	}

	variable Var1 = arrayPointerNames[nomeArray];
	variable Var2 = arrayPointerNames[nomeArray + "Acrescimo"];

	for(int i = 0; i < tamanhoArray; i++){
		trad = trad + "\t" + nomeArray + "[" + Var1.nome + "] = " + auxStack.top() +
		";\n\t" + Var1.nome + " = " + Var1.nome + " + " + Var2.nome + ";\n"; //olha que coisa feia
		auxStack.pop();
	}

	return trad;
}

void freeVectors(){

	string aux;
	while (!stackVectors.empty()){
		aux = stackVectors.top();
		stackVectors.pop();
		cout << aux << endl;
	}
	cout << "\n\n" << endl;
}
