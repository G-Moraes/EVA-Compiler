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
int mapAtual = 0;
unordered_map <string, variable> globalTabSym;
vector <string> tempVector;
vector <string> globalTempVector;
stack <int> stackLoops;
stack <string> stackCommands;
vector <unordered_map<string, variable>> contextoVariaveis;

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
void addVarToTempVector(string nomeVar);
void addVarToGlobalTempVector(string nomeVar);
void printVector();
void printGlobalVector();

//funções para acessar tabela de simbolos
void addMapToStack();
string addVarToTabSym(string nomeDado, string conteudoVar, string tipoVar);
string addVarToGlobalTabSym(string nomeDado, string conteudoVar, string tipoVar);
variable searchForVariable(string nome);
void checkForVariable(string nome);
void printGlobalVariables();

#line 145 "y.tab.c" /* yacc.c:339  */

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
    TK_UN_SUM = 278,
    TK_CONV_FLOAT = 279,
    TK_CONV_INT = 280,
    TK_LE = 281,
    TK_HE = 282,
    TK_EQ = 283,
    TK_DIFF = 284,
    TK_CHAR = 285,
    TK_FLOAT = 286,
    TK_BOOL = 287,
    TK_NUM = 288,
    TK_STRING = 289,
    TK_FIM = 290,
    TK_ERROR = 291
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
#define TK_UN_SUM 278
#define TK_CONV_FLOAT 279
#define TK_CONV_INT 280
#define TK_LE 281
#define TK_HE 282
#define TK_EQ 283
#define TK_DIFF 284
#define TK_CHAR 285
#define TK_FLOAT 286
#define TK_BOOL 287
#define TK_NUM 288
#define TK_STRING 289
#define TK_FIM 290
#define TK_ERROR 291

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

#line 268 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   354

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,     2,     2,     2,    40,     2,
      47,    48,    45,    43,     2,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
      41,    37,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    39,    50,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   112,   119,   124,   128,   134,   139,   144,
     149,   154,   159,   164,   169,   174,   179,   184,   189,   194,
     200,   209,   216,   240,   264,   288,   310,   332,   355,   371,
     396,   416,   431,   446,   467,   485,   499,   525,   549,   565,
     579,   586,   593,   602,   614,   620,   626,   633,   633,   652,
     652,   672,   672,   684,   684,   723,   723,   762,   762,   767,
     794,   822,   837,   852,   878,   894,   910,   926,   934,   962,
     982,  1001,  1020,  1028,  1036,  1045,  1064,  1090,  1095,  1103,
    1111,  1119,  1127,  1135
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
  "TK_TIPO_STRING", "TK_UN_SUM", "TK_CONV_FLOAT", "TK_CONV_INT", "TK_LE",
  "TK_HE", "TK_EQ", "TK_DIFF", "TK_CHAR", "TK_FLOAT", "TK_BOOL", "TK_NUM",
  "TK_STRING", "TK_FIM", "TK_ERROR", "'='", "'!'", "'|'", "'&'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'{'", "'}'", "';'",
  "$accept", "S", "BLOCO", "BLOCOGLOBAL", "BLOCOCONTEXTO", "COMANDOS",
  "COMANDO", "ENTRADA", "SAIDA", "CONDICIONAL", "ATRIBUICAO", "DECLARACAO",
  "IF", "$@1", "$@2", "ELSE", "$@3", "WHILE", "$@4", "DOWHILE", "$@5",
  "FOR", "$@6", "FORMODES", "BREAK", "CONTINUE", "E", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,    61,    33,   124,
      38,    60,    62,    43,    45,    42,    47,    40,    41,   123,
     125,    59
};
# endif

#define YYPACT_NINF -109

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-109)))

#define YYTABLE_NINF -52

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -109,     4,  -109,  -109,   -11,    28,   -14,     3,   -15,   154,
    -109,  -109,  -109,    -1,    -8,    10,  -109,  -109,  -109,  -109,
    -109,    34,    34,    50,     7,   114,    12,    18,    20,    22,
      29,    45,   191,    46,  -109,   178,    82,    64,    74,   280,
     257,    99,  -109,  -109,  -109,   112,  -109,  -109,    72,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
    -109,  -109,  -109,    34,    34,   280,    90,    94,    95,    96,
     122,  -109,   136,    34,   113,   -15,     1,   157,  -109,   151,
     151,    93,    93,   287,   308,   151,   151,    41,    41,  -109,
    -109,   280,   280,    34,    34,    34,    34,   126,   130,   134,
     140,   -18,   153,    49,   136,   170,    19,    13,   128,  -109,
     175,   280,   280,   280,   280,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,   142,   142,   135,   143,   -12,
     136,   203,   167,    34,   142,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   192,   193,   -15,   136,   147,
      90,    94,    95,    96,   208,   212,   198,   155,   156,  -109,
     165,    34,   126,   130,   134,   140,    34,   163,  -109,  -109,
    -109,   233,   233,  -109,  -109,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     5,     1,     0,     0,     0,     0,     0,     5,
       2,    61,    62,     0,    83,     0,    80,    79,    81,    78,
      82,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,    67,     0,     0,     0,    83,    74,
       0,    49,    53,    55,    57,    13,    14,    15,     0,    17,
       3,     6,    11,    12,     9,    10,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,    21,    20,     0,     0,    36,    40,    41,    42,    39,
       0,    77,     0,     0,     0,     0,     0,     0,    16,    70,
      71,    75,    76,    72,    73,    68,    69,    63,    64,    65,
      66,    37,    38,     0,     0,     0,     0,    44,    45,    46,
      43,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,    29,    30,    31,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     5,     0,     0,     0,
       0,     0,     0,     0,     5,    33,    34,    35,    32,    25,
      24,    26,    27,    23,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    50,
      56,     0,     0,    52,    59,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,   -83,  -109,   213,   -20,  -109,  -109,  -109,  -108,
     158,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,   -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    10,     2,    23,    24,    25,    26,    27,   112,
      28,    29,    45,    82,    83,    46,    87,    47,    84,    48,
      85,    49,    86,   119,    30,    31,    32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    40,   115,    38,     3,    51,   137,     5,   129,   130,
     131,   132,    73,    74,    75,    34,   116,   117,    16,    17,
      18,    19,    20,   133,   134,    36,    21,    37,   141,    35,
     142,     6,   159,     7,     9,    22,    33,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    38,
     170,     8,   101,   102,    41,   136,   139,    50,    42,    43,
      44,    71,   113,    52,    16,    17,    18,    19,    20,    53,
     140,    54,    21,    55,   169,    58,    59,    60,    61,    80,
      56,    22,   121,   122,   123,   124,    68,    69,    62,    63,
      64,    65,    66,    67,    68,    69,    57,    34,   184,   185,
      76,    77,    78,    79,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   -47,   155,   156,   -51,    75,    58,
      59,    -7,   165,    88,   166,    11,    12,   103,    13,    14,
      15,   104,   105,   106,    64,    65,    66,    67,    68,    69,
     107,   108,   109,   110,    16,    17,    18,    19,    20,    -7,
     181,   111,    21,    11,    12,   182,    13,    14,    15,   135,
     114,    22,   120,   125,    -7,    11,    12,   126,    13,    14,
      15,   127,    16,    17,    18,    19,    20,   128,   138,   143,
      21,   144,   164,   157,    16,    17,    18,    19,    20,    22,
     158,    72,    21,    38,    66,    67,    68,    69,   171,   167,
     168,    22,    73,    74,    -7,   177,   178,   179,    16,    17,
      18,    19,    20,   180,   183,     4,    21,    58,    59,    60,
      61,   160,   161,   162,   163,    22,   172,   173,   174,   175,
      62,    63,    64,    65,    66,    67,    68,    69,    58,    59,
      60,    61,    70,     0,   118,     0,     0,     0,     0,     0,
       0,    62,    63,    64,    65,    66,    67,    68,    69,    58,
      59,    60,    61,   176,     0,     0,     0,     0,     0,     0,
       0,     0,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     9,    58,    59,    60,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    81,    58,    59,    60,    61,
       0,     0,     0,    58,    59,    60,    61,     0,     0,    62,
      63,    64,    65,    66,    67,    68,    69,    63,    64,    65,
      66,    67,    68,    69,    58,    59,    60,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    66,    67,    68,    69
};

static const yytype_int16 yycheck[] =
{
      21,    22,    85,    15,     0,    25,   114,    18,    26,    27,
      28,    29,    24,    25,    35,    23,    15,    16,    30,    31,
      32,    33,    34,    41,    42,    15,    38,    17,    15,    37,
      17,     3,   140,    47,    49,    47,    37,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    15,
     158,    48,    73,    74,     4,     6,    37,    50,     8,     9,
      10,    15,    83,    51,    30,    31,    32,    33,    34,    51,
      51,    51,    38,    51,   157,    26,    27,    28,    29,    15,
      51,    47,   103,   104,   105,   106,    45,    46,    39,    40,
      41,    42,    43,    44,    45,    46,    51,    23,   181,   182,
      18,    19,    20,    21,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    15,   135,   136,     5,   139,    26,
      27,     7,   143,    51,   144,    11,    12,    37,    14,    15,
      16,    37,    37,    37,    41,    42,    43,    44,    45,    46,
      18,    19,    20,    21,    30,    31,    32,    33,    34,     7,
     171,    15,    38,    11,    12,   176,    14,    15,    16,     6,
      47,    47,     5,    37,    50,    11,    12,    37,    14,    15,
      16,    37,    30,    31,    32,    33,    34,    37,     8,    51,
      38,     6,    15,    48,    30,    31,    32,    33,    34,    47,
      47,    13,    38,    15,    43,    44,    45,    46,    51,     7,
       7,    47,    24,    25,    50,     7,    51,    51,    30,    31,
      32,    33,    34,    48,    51,     2,    38,    26,    27,    28,
      29,    18,    19,    20,    21,    47,    18,    19,    20,    21,
      39,    40,    41,    42,    43,    44,    45,    46,    26,    27,
      28,    29,    51,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    26,
      27,    28,    29,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    49,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    26,    27,    28,    29,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    40,    41,    42,
      43,    44,    45,    46,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    55,     0,    56,    18,     3,    47,    48,    49,
      54,    11,    12,    14,    15,    16,    30,    31,    32,    33,
      34,    38,    47,    56,    57,    58,    59,    60,    62,    63,
      76,    77,    78,    37,    23,    37,    15,    17,    15,    78,
      78,     4,     8,     9,    10,    64,    67,    69,    71,    73,
      50,    57,    51,    51,    51,    51,    51,    51,    26,    27,
      28,    29,    39,    40,    41,    42,    43,    44,    45,    46,
      51,    15,    13,    24,    25,    78,    18,    19,    20,    21,
      15,    48,    65,    66,    70,    72,    74,    68,    51,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    37,    37,    37,    37,    18,    19,    20,
      21,    15,    61,    78,    47,    54,    15,    16,    62,    75,
       5,    78,    78,    78,    78,    37,    37,    37,    37,    26,
      27,    28,    29,    41,    42,     6,     6,    61,     8,    37,
      51,    15,    17,    51,     6,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    57,    57,    48,    47,    61,
      18,    19,    20,    21,    15,    78,    57,     7,     7,    54,
      61,    51,    18,    19,    20,    21,    51,     7,    51,    51,
      48,    78,    78,    51,    54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    55,    56,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    60,    61,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    65,    64,    66,
      64,    68,    67,    70,    69,    72,    71,    74,    73,    75,
      75,    76,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     3,     0,     0,     2,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     5,
       5,     5,     6,     6,     6,     6,     3,     4,     4,     3,
       3,     3,     3,     4,     4,     4,     4,     0,     7,     0,
       7,     0,     7,     0,     6,     0,     7,     0,     3,     6,
       6,     1,     1,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     1,     1,
       1,     1,     1,     1
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
#line 104 "sintatica.y" /* yacc.c:1646  */
    {
				printGlobalVariables();
				cout << "/*Compilador Eva*/\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n#define TRUE 1\n#define FALSE 0\n\nint main(void)\n{" <<endl;
				printVector();
				cout << (yyvsp[0]).traducao << "\treturn 0;\n}" << endl;
			}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 113 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).traducao = (yyvsp[-1]).traducao;
				}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 119 "sintatica.y" /* yacc.c:1646  */
    {
								contextoVariaveis.push_back(globalTabSym);
							}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 124 "sintatica.y" /* yacc.c:1646  */
    {
								addMapToStack();
							}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 129 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
					}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 134 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).traducao = "";
					}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 140 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 145 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 150 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 155 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 160 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 165 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
						}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 170 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
						}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 175 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
						}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 180 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 185 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
						}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 190 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 195 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 201 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = (yyvsp[-2]).tipo;
				variable Var = searchForVariable((yyvsp[-2]).label);
				cout << "$3.label = " << (yyvsp[0]).label << endl;
				(yyval).traducao = "\tstd::cin" + (yyval).traducao + (yyvsp[-2]).traducao + ";\n";
			}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 210 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				variable Var = searchForVariable((yyvsp[0]).label);
				(yyval).traducao = "\tstd::cout " + (yyvsp[0]).traducao + ";\n";
			}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 217 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				variable Var = searchForVariable((yyvsp[-2]).label);
				structAux aux = implicitConversion(Var.tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

				if(aux.varConvertida == (yyvsp[-2]).label){

					(yyval).traducao = (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " > " + (yyvsp[0]).label + ";\n";
				}
				else if(aux.varConvertida == (yyvsp[0]).label){

					(yyval).traducao = (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + Var.nome + " > " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo

					(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + Var.nome + " > " + (yyvsp[0]).label + ";\n";
				}

				addVarToTempVector("\tint " + (yyval).label + ";\n");
			}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 241 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				variable Var = searchForVariable((yyvsp[-2]).label);
				structAux aux = implicitConversion(Var.tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

				if(aux.varConvertida == (yyvsp[-2]).label){

					(yyval).traducao = (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " < " + (yyvsp[0]).label + ";\n";
				}
				else if(aux.varConvertida == (yyvsp[0]).label){

					(yyval).traducao = (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + Var.nome + " < " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo

					(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + Var.nome + " < " + (yyvsp[0]).label + ";\n";
				}

				addVarToTempVector("\tint " + (yyval).label + ";\n");
			}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 265 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				variable Var = searchForVariable((yyvsp[-2]).label);
				structAux aux = implicitConversion(Var.tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

				if(aux.varConvertida == (yyvsp[-2]).label){

					(yyval).traducao = (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " >= " + (yyvsp[0]).label + ";\n";
				}
				else if(aux.varConvertida == (yyvsp[0]).label){

					(yyval).traducao = (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + Var.nome + " >= " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo

					(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + Var.nome + " >= " + (yyvsp[0]).label + ";\n";
				}

				addVarToTempVector("\tint " + (yyval).label + ";\n");
			}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 289 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				variable Var = searchForVariable((yyvsp[-2]).label);
				structAux aux = implicitConversion(Var.tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

				if(aux.varConvertida == (yyvsp[-2]).label){

					(yyval).traducao = (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " <= " + (yyvsp[0]).label + ";\n";
				}
				else if(aux.varConvertida == (yyvsp[0]).label){

					(yyval).traducao = (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + Var.nome + " <= " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo

					(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + Var.nome + " <= " + (yyvsp[0]).label + ";\n";
				}
			}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 311 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				variable Var = searchForVariable((yyvsp[-2]).label);
				structAux aux = implicitConversion(Var.tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

				if(aux.varConvertida == (yyvsp[-2]).label){

					(yyval).traducao = (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " == " + (yyvsp[0]).label + ";\n";
				}
				else if(aux.varConvertida == (yyvsp[0]).label){

					(yyval).traducao = (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + Var.nome + " == " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo

					(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + Var.nome + " == " + (yyvsp[0]).label + ";\n";
				}
			}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 333 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				variable Var = searchForVariable((yyvsp[-2]).label);
				structAux aux = implicitConversion(Var.tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

				if(aux.varConvertida == (yyvsp[-2]).label){

					(yyval).traducao = (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " != " + (yyvsp[0]).label + ";\n";
				}
				else if(aux.varConvertida == (yyvsp[0]).label){

					(yyval).traducao = (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + Var.nome + " != " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo

					(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + Var.nome + " != " + (yyvsp[0]).label + ";\n";
				}
			}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 356 "sintatica.y" /* yacc.c:1646  */
    {
							erroTipo("char", (yyvsp[0]).tipo);
							string nomeAuxID = addVarToTabSym((yyvsp[-3]).label, (yyvsp[0]).traducao, "char");
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label + ";\n";
							addVarToTempVector("\tchar " + nomeAuxID + ";\n");
						}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 372 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "int";
							if((yyval).tipo != (yyvsp[0]).tipo){

								if((yyvsp[0]).tipo == "char" || (yyvsp[0]).tipo == "string"){
									yyerror("Declaração de char/string em int não permitido!");
								}

								else{

									string nomeAuxID = addVarToTabSym((yyvsp[-3]).label, (yyvsp[0]).traducao, "int");
									(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (int) " + (yyvsp[0]).label  + ";\n";
									addVarToTempVector("\tint " + nomeAuxID +  ";\n");
								}
							}

							else{

								string nomeAuxID = addVarToTabSym((yyvsp[-3]).label, (yyvsp[0]).traducao, "int");
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label  + ";\n";
								addVarToTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 397 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "float";
							if((yyval).tipo != (yyvsp[0]).tipo){
								if((yyvsp[0]).tipo == "char" || (yyvsp[0]).tipo == "string"){
									yyerror("Declaração de char/string em float não permitido!");
								}
								else{
									string nomeAuxID = addVarToTabSym((yyvsp[-3]).label, (yyvsp[0]).traducao, "float");
									(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (float) " + (yyvsp[0]).label  + ";\n";
									addVarToTempVector("\tfloat " + nomeAuxID +  ";\n");
								}
							}
							else{
								string nomeAuxID = addVarToTabSym((yyvsp[-3]).label, (yyvsp[0]).traducao, "float");
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label  + ";\n";
								addVarToTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 417 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "bool";
							if((yyval).tipo != (yyvsp[0]).tipo){
								yyerror("Tipo booleano somente aceita boleano!");
							}
							else{
								string nomeAuxID = addVarToTabSym((yyvsp[-3]).label, (yyvsp[0]).traducao, "int");
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label  + ";\n";
								addVarToTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 432 "sintatica.y" /* yacc.c:1646  */
    {
							erroTipo("char", (yyvsp[0]).tipo);
							string nomeAuxID = addVarToGlobalTabSym((yyvsp[-4]).label, (yyvsp[0]).traducao, "char");
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label + ";\n";
						}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 447 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "int";
							if((yyval).tipo != (yyvsp[0]).tipo){

								if((yyvsp[0]).tipo == "char" || (yyvsp[0]).tipo == "string"){
									yyerror("Declaração de char/string em int não permitido!");
								}

								else{
									string nomeAuxID = addVarToGlobalTabSym((yyvsp[-4]).label, (yyvsp[0]).traducao, "int");
									(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (int) " + (yyvsp[0]).label  + ";\n";
								}
							}

							else{
								string nomeAuxID = addVarToGlobalTabSym((yyvsp[-4]).label, (yyvsp[0]).traducao, "int");
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label  + ";\n";
							}
						}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 468 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "float";
							if((yyval).tipo != (yyvsp[0]).tipo){
								if((yyvsp[0]).tipo == "char" || (yyvsp[0]).tipo == "string"){
									yyerror("Declaração de char/string em float não permitido!");
								}
								else{
									string nomeAuxID = addVarToGlobalTabSym((yyvsp[-4]).label, (yyvsp[0]).traducao, "float");
									(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (float) " + (yyvsp[0]).label  + ";\n";
								}
							}
							else{
								string nomeAuxID = addVarToGlobalTabSym((yyvsp[-4]).label, (yyvsp[0]).traducao, "float");
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label  + ";\n";
							}
						}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 486 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "bool";
							if((yyval).tipo != (yyvsp[0]).tipo){
								yyerror("Tipo booleano somente aceita boleano!");
							}
							else{
								string nomeAuxID = addVarToGlobalTabSym((yyvsp[-4]).label, (yyvsp[0]).traducao, "int");
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label  + ";\n";
							}
						}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 500 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-2]).label);
							cout << "\n\nNome expressão: " << (yyvsp[0]).label << "\nTipo expressão: " << (yyvsp[0]).tipo << endl;

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
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 526 "sintatica.y" /* yacc.c:1646  */
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
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 550 "sintatica.y" /* yacc.c:1646  */
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
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 566 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[-1]).label, "none", "char");
							(yyval).traducao = "\t";
							addVarToTempVector("\tchar " + nomeAuxID +  ";\n");
						}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 580 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[-1]).label, "0", "int");
							(yyval).traducao = "\t";
							addVarToTempVector("\tint " + nomeAuxID + ";\n");
						}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 587 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[-1]).label, "0.0", "float");
							(yyval).traducao = "\t";
							addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
						}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 594 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[-1]).label, "TRUE", "bool");
							(yyval).traducao = "\t";
							addVarToTempVector("\tint " + nomeAuxID + ";\n");
						}
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 603 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToGlobalTabSym((yyvsp[-2]).label, "none", "char");
							(yyval).traducao = "\t";
						}
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 615 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToGlobalTabSym((yyvsp[-2]).label, "0", "int");
							(yyval).traducao = "\t";
						}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 621 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToGlobalTabSym((yyvsp[-2]).label, "0.0", "float");
							(yyval).traducao = "\t";
						}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 627 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToGlobalTabSym((yyvsp[-2]).label, "TRUE", "bool");
							(yyval).traducao = "\t";
						}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 633 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 634 "sintatica.y" /* yacc.c:1646  */
    {
						if((yyvsp[-4]).tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + (yyvsp[-4]).label;
							(yyval).traducao = "\n//if\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + (yyvsp[-4]).traducao + "\n\t" + auxVar + " = " +
							auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + (yyvsp[-2]).traducao + "\tfinal" +
							to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 652 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 653 "sintatica.y" /* yacc.c:1646  */
    {
						if((yyvsp[-4]).tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + (yyvsp[-4]).label;
							(yyval).traducao = "\n//if\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + (yyvsp[-4]).traducao + "\n\t" + auxVar + " = " +
							auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + (yyvsp[-2]).traducao + "\tfinal" +
							to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 672 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 673 "sintatica.y" /* yacc.c:1646  */
    {
					int posiAlteracao = (yyvsp[-6]).traducao.rfind("final");
					string auxRetorno = (yyvsp[-6]).traducao;
					auxRetorno.insert(posiAlteracao, "goto final" + to_string(stackLoops.top()) + ";\n\n\t");
					(yyval).traducao = auxRetorno + (yyvsp[-2]).traducao + "\tfinal" + to_string(stackLoops.top()) + ":\n";
					stackLoops.pop();
					contextoVariaveis.pop_back();
					mapAtual--;
				}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 684 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("while");}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 685 "sintatica.y" /* yacc.c:1646  */
    {
						if((yyvsp[-2]).tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + (yyvsp[-2]).label;
							(yyval).traducao = "\n//while:\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + (yyvsp[-2]).traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
							auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + (yyvsp[0]).traducao + "\tgoto loop" + to_string(stackLoops.top()) +
							";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 723 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("while");}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 724 "sintatica.y" /* yacc.c:1646  */
    {
						if((yyvsp[-1]).tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + (yyvsp[-1]).label;
							(yyval).traducao = "\n//do while:\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + (yyvsp[-4]).traducao + "\n\tloop" + to_string(stackLoops.top()) + ":\n" + (yyvsp[-1]).traducao +
							"\t" + auxVar + " = " + auxVar2 + ";\n\tif (" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n\tgoto comeco" + to_string(stackLoops.top()) +
							";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 762 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("for");}
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 763 "sintatica.y" /* yacc.c:1646  */
    {
			  	(yyval) = (yyvsp[0]);
			  }
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 768 "sintatica.y" /* yacc.c:1646  */
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

					(yyval).traducao = "\n//for\n" + (yyvsp[-5]).traducao + "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + (yyvsp[-3]).traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
					auxVar3 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + (yyvsp[0]).traducao +"\t"+ nomeVar + " = " + Var.nome + " + 1;\n" +
					"\tgoto loop" + to_string(stackLoops.top()) + ";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
					stackLoops.pop();
					contextoVariaveis.pop_back();
					mapAtual--;
				}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 795 "sintatica.y" /* yacc.c:1646  */
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

					(yyval).traducao = "\n//for\n" + (yyvsp[-5]).traducao + "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + (yyvsp[-3]).traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
					auxVar3 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + (yyvsp[0]).traducao +"\t"+ nomeVar + " = " + Var.nome + " + 1;\n" +
					"\tgoto loop" + to_string(stackLoops.top()) + ";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
					stackLoops.pop();
					contextoVariaveis.pop_back();
					mapAtual--;
				}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 823 "sintatica.y" /* yacc.c:1646  */
    {
						if(stackLoops.empty()){
							(yyval).traducao = "";
						}

						else if(stackCommands.empty()){
							yyerror("Break fora de um laço. Erro!");
						}

						else{
							(yyval).traducao = "\tgoto final" + to_string(stackLoops.top()) + ";// isso é um break\n";
						}
					}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 838 "sintatica.y" /* yacc.c:1646  */
    {
						if(stackLoops.empty()){
							(yyval).traducao = "";
						}

						else if(stackCommands.empty()){
							yyerror("Continue fora de um laço. Erro!");
						}

						else{
							(yyval).traducao = "\tgoto inicio" + to_string(stackLoops.top()) + ";// isso é um continue\n";
						}
					}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 853 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();

				if((yyval).tipo != "string" && (yyvsp[-2]).tipo != "string" && (yyvsp[0]).tipo != "string")
				{
					cout << (yyval).tipo << endl;
					structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);
					if(aux.varConvertida == (yyvsp[-2]).label){
						(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " + " + (yyvsp[0]).label + ";\n";
					}
					else if(aux.varConvertida == (yyvsp[0]).label){
						(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " + " + aux.nomeVar + ";\n";
					}
					else{ //se as duas variáveis são do mesmo tipo
						(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " + " + (yyvsp[0]).label + ";\n";
				}				}

				else
				{
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " + " + (yyvsp[0]).label + ";\n";
					cout << "aqui" << endl;
				}
				addVarToTempVector("\t" + (yyval).tipo + " " + (yyval).label  + ";\n");
			}
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 879 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);
				if(aux.varConvertida == (yyvsp[-2]).label){
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " - " + (yyvsp[0]).label + ";\n";
				}
				else if(aux.varConvertida == (yyvsp[0]).label){
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " - " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " - " + (yyvsp[0]).label + ";\n";
				}
				addVarToTempVector("\t" + (yyval).tipo + " " + (yyval).label + ";\n");
			}
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 895 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);
				if(aux.varConvertida == (yyvsp[-2]).label){
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " * " + (yyvsp[0]).label + ";\n";
				}
				else if(aux.varConvertida == (yyvsp[0]).label){
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " * " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " * " + (yyvsp[0]).label + ";\n";
				}
				addVarToTempVector("\t" + (yyval).tipo + " " + (yyval).label + ";\n");
			}
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 911 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);
				if(aux.varConvertida == (yyvsp[-2]).label){
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " / " + (yyvsp[0]).label + ";\n";
				}
				else if(aux.varConvertida == (yyvsp[0]).label){
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " / " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " / " + (yyvsp[0]).label + ";\n";
				}
				addVarToTempVector("\t" + (yyval).tipo + " " + (yyval).label + ";\n");
			}
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 927 "sintatica.y" /* yacc.c:1646  */
    {

				variable Var = searchForVariable((yyvsp[-1]).label);
				(yyval).tipo = Var.tipo;
				(yyval).traducao = "\t" + (yyvsp[-1]).label + " = " + (yyvsp[-1]).label + " + 1;\n";
			}
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 935 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = "bool";
				//cout << "carai " << $1.traducao << endl;
				structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

				if(aux.varConvertida == (yyvsp[-2]).label){
					string abacate = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " < " + (yyvsp[0]).label + ";\n";
					cout << "SAI DESSA MANO" << abacate << endl;
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " < " + (yyvsp[0]).label + ";\n";
				}
				else if(aux.varConvertida == (yyvsp[0]).label){
					string caraioo = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " < " + aux.nomeVar + ";\n";
					cout << "TODO DIA ISSO" << caraioo << endl;
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " < " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					
					cout << "carai " << (yyvsp[-2]).traducao << (yyvsp[0]).traducao << "\t" << (yyval).label << " = " << (yyvsp[-2]).label << " < " << (yyvsp[0]).label << ";\n";
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " < " + (yyvsp[0]).label + ";\n";
					

				}

				addVarToTempVector("\tint " + (yyval).label + ";\n");
			}
#line 2491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 963 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);

				if(aux.varConvertida == (yyvsp[-2]).label){
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " > " + (yyvsp[0]).label + ";\n";
				}
				else if(aux.varConvertida == (yyvsp[0]).label){
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " > " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " > " + (yyvsp[0]).label + ";\n";
				}

				addVarToTempVector("\tint " + (yyval).label + ";\n");
			}
#line 2514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 983 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);
				if(aux.varConvertida == (yyvsp[-2]).label){
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " <= " + (yyvsp[0]).label + ";\n";
				}
				else if(aux.varConvertida == (yyvsp[0]).label){
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " <= " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " <= " + (yyvsp[0]).label + ";\n";
				}

				addVarToTempVector("\tint " + (yyval).label + ";\n");
			}
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1002 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);
				if(aux.varConvertida == (yyvsp[-2]).label){
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " >= " + (yyvsp[0]).label + ";\n";
				}
				else if(aux.varConvertida == (yyvsp[0]).label){
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " >= " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " >= " + (yyvsp[0]).label + ";\n";
				}

				addVarToTempVector("\tint " + (yyval).label + ";\n");
			}
#line 2558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1021 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = isBoolean((yyvsp[-2]).tipo, (yyvsp[0]).tipo);
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " || " + (yyvsp[0]).label + ";\n";
				addVarToTempVector("\tint " + (yyval).label + ";\n");
			}
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1029 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = isBoolean((yyvsp[-2]).tipo, (yyvsp[0]).tipo);
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " && " + (yyvsp[0]).label + ";\n";
				addVarToTempVector("\tint " + (yyval).label + ";\n");
			}
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1037 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
				(yyval).tipo = isBoolean("bool", (yyvsp[0]).tipo);
				(yyval).label = genLabel();
				(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = !" + (yyvsp[0]).label + ";\n";
				addVarToTempVector("\tint " + (yyval).label + ";\n");
			}
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1046 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);
				if(aux.varConvertida == (yyvsp[-2]).label){
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " == " + (yyvsp[0]).label + ";\n";
				}
				else if(aux.varConvertida == (yyvsp[0]).label){
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " == " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " == " + (yyvsp[0]).label + ";\n";
				}

				addVarToTempVector("\tint " + (yyval).label + ";\n");
			}
#line 2614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1065 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = "bool";

				if(((yyvsp[-2]).tipo == "bool" && (yyvsp[0]).tipo == "bool") || ((yyvsp[-2]).tipo == "char" && (yyvsp[0]).tipo == "char")){

					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " != " + (yyvsp[0]).label + ";\n";
				}

				else{

					structAux aux = implicitConversion((yyvsp[-2]).tipo, (yyvsp[0]).tipo, (yyvsp[-2]).label, (yyvsp[0]).label);
					if(aux.varConvertida == (yyvsp[-2]).label){
						(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + aux.nomeVar + " != " + (yyvsp[0]).label + ";\n";
					}
					else if(aux.varConvertida == (yyvsp[0]).label){
						(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + aux.implicita + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " != " + aux.nomeVar + ";\n";
					}
					else{ //se as duas variáveis são do mesmo tipo
						(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " != " + (yyvsp[0]).label + ";\n";
					}
					addVarToTempVector("\tint " + (yyval).label + ";\n");
				}
			}
#line 2643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1091 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[-1]);
			}
#line 2651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1096 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "nomeTemporarioInt" + to_string(valorTemp++);
				(yyval).tipo = "int";
				addVarToTempVector("\t" + (yyval).tipo + " " + (yyval).label + ";\n");
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
			}
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1104 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "nomeTemporarioFloat" + to_string(valorTemp++);
				(yyval).tipo = "float";
				addVarToTempVector("\tfloat " + (yyval).label + ";\n");
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
		 	}
#line 2673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1112 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "nomeTemporarioChar" + to_string(valorTemp++);
				(yyval).tipo = "char";
				addVarToTempVector("\tchar "  + (yyval).label + ";\n");
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
			}
#line 2684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1120 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "nomeTemporarioBool" + to_string(valorTemp++);
				(yyval).tipo = "bool";
				addVarToTempVector("\tint " + (yyval).label + ";\n");
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
			}
#line 2695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1128 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "nomeTemporarioString" + to_string(valorTemp++);
				(yyval).tipo = "string";
				addVarToTempVector("\tstring "  + (yyval).label + ";\n");
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
			}
#line 2706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1136 "sintatica.y" /* yacc.c:1646  */
    {
				variable auxVar = searchForVariable((yyvsp[0]).label);
				(yyval).label = auxVar.nome;
				(yyval).tipo = auxVar.tipo;
				(yyval).traducao;
			}
#line 2717 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2721 "y.tab.c" /* yacc.c:1646  */
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
#line 1143 "sintatica.y" /* yacc.c:1906  */


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
}

string addVarToTabSym(string nomeDado, string conteudoVar, string tipoVar){

	checkForVariable(nomeDado);
	unordered_map<string, variable> tabSym = contextoVariaveis.back();
	cout << "\ntabSym antes " << (tabSym.empty() ? "is empty" : "is not empty" ) << endl;
	cout << "\nconteudo da variavel: " << conteudoVar << endl;
	unordered_map<string, variable>::const_iterator got = tabSym.find(nomeDado);
	string nomeGerado;

	if(got == tabSym.end()){

		variable Var2;
		nomeGerado = genLabel();

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

string addVarToGlobalTabSym(string nomeDado, string conteudoVar, string tipoVar){

	checkForVariable(nomeDado);
	//unordered_map<string, variable> tabSym = contextoVariaveis.back();
	cout << "\nglobalTabSym antes " << (globalTabSym.empty() ? "is empty" : "is not empty" ) << endl;
	unordered_map<string, variable>::const_iterator got = globalTabSym.find(nomeDado);
	string nomeGerado;

	if(got == globalTabSym.end()){

		variable Var;
		nomeGerado = genLabel();

		Var =	{
					.tipo = tipoVar,
				   	.nome = nomeGerado,
					.valor = conteudoVar
		  		};

		globalTabSym[nomeDado] = Var;
		//contextoVariaveis.pop_back();
		//ScontextoVariaveis.push_back(abSym);
		cout << "globalTabSym depois " << (globalTabSym.empty() ? "is empty" : "is not empty" ) << endl;
		cout << "\nAdicionado " << globalTabSym[nomeDado].nome << " de tipo "<< globalTabSym[nomeDado].tipo <<" na tabela global de simbolos!\n" << endl;
		return globalTabSym[nomeDado].nome;
	}

	/*else {

		return tabSym[nomeDado].nome;
	}*/

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

	for(i; i > 0; i--){

		auxMap = auxVector.back();
		auxVector.pop_back();

		cout << "auxMap search iteração " << i << " " << (auxMap.empty() ? "is empty" : "is not empty" ) << endl;

		unordered_map<string, variable>::const_iterator got = auxMap.find(nome); //procuro a variável pelo nome no map mais interno

		if(got != auxMap.end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

			cout << "\n\nEncontrada variável!\nNome: " << nome << "\nTipo: " << auxMap[nome].tipo << endl;
			cout << "Conteudo: " << auxMap[nome].valor << endl;
			variable auxVar = auxMap[nome];
			return auxVar; //se for, retorno essa variável
		}
	}
}

void checkForVariable(string nome){

	int i = mapAtual; //inteiro para percorrer o vetor de mapas
	vector<unordered_map<string, variable>> auxVector; //vetor auxiliar para percorrer
	auxVector = contextoVariaveis; //atribuo o vetor de contexto global para o vetor auxiliar
	unordered_map<string, variable> auxMap; //mapa auxiliar para checar as variáveis dele

	cout << "\ncontextoVariaveis " << (contextoVariaveis.empty() ? "is empty" : "is not empty" ) << endl;
	cout << "quantidade de contextos: " << i << endl;
	cout << "variavel buscando: " << nome << endl;
	cout << "auxVector " << (auxVector.empty() ? "is empty" : "is not empty" ) << endl;

	for(i; i > 0; i--){

		auxMap = auxVector.back();
		auxVector.pop_back();

		cout << "auxMap check iteração " << i << " " << (auxMap.empty() ? "is empty" : "is not empty" ) << endl;

		unordered_map<string, variable>::const_iterator got = auxMap.find(nome); //procuro a variável pelo nome no map mais interno

		if(got != auxMap.end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

			string errorMessage = "\n\nEncontrada variável!\nNome: " + nome + "\nTipo: " + auxMap[nome].tipo + "\n";
			yyerror(errorMessage);
		}
	}
}
