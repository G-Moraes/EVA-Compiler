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
int tamanho_linhas = 1;
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
void addVarToTempVector(string nomeVar);
void addVarToGlobalTempVector(string nomeVar);
void printVector();
void printGlobalVector();

//funções de array e matrix
string addElementsToArray(int tamanhoArray, string nomeArray);

//funções para acessar tabela de simbolos
void addMapToStack();
string addVarToTabSym(string nomeDado, string conteudoVar, string tipoVar);
string addVarToGlobalTabSym(string nomeDado, string conteudoVar, string tipoVar);
variable searchForVariable(string nome);
void checkForVariable(string nome);
void printGlobalVariables();

#line 158 "y.tab.c" /* yacc.c:339  */

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

#line 281 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   476

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  250

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
      47,    48,    45,    43,    52,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
      41,    37,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
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
       0,   116,   116,   125,   132,   138,   142,   148,   153,   158,
     163,   168,   173,   178,   183,   188,   193,   198,   203,   208,
     214,   224,   236,   245,   254,   263,   270,   294,   318,   342,
     364,   386,   409,   425,   450,   470,   484,   499,   515,   533,
     548,   569,   587,   601,   616,   633,   651,   676,   700,   715,
     742,   771,   785,   792,   799,   810,   819,   828,   838,   847,
     856,   866,   875,   884,   895,   907,   913,   919,   928,   934,
     946,   954,   962,   970,   979,   999,  1044,  1044,  1063,  1063,
    1083,  1083,  1095,  1095,  1134,  1134,  1173,  1173,  1178,  1205,
    1233,  1248,  1263,  1289,  1305,  1321,  1337,  1345,  1373,  1393,
    1412,  1431,  1439,  1447,  1456,  1475,  1501,  1506,  1515,  1524,
    1533,  1542,  1550
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
  "','", "'['", "']'", "$accept", "S", "BLOCO", "BLOCOGLOBAL",
  "BLOCOCONTEXTO", "COMANDOS", "COMANDO", "VETOR", "MATRIZ", "ENTRADA",
  "SAIDA", "CONDICIONAL", "ATRIBUICAO", "DECLARACAO", "ARRAYDECLARATION",
  "MATRIXDECLARATION", "IF", "$@1", "$@2", "ELSE", "$@3", "WHILE", "$@4",
  "DOWHILE", "$@5", "FOR", "$@6", "FORMODES", "BREAK", "CONTINUE", "E", YY_NULLPTR
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
     125,    59,    44,    91,    93
};
# endif

#define YYPACT_NINF -135

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-135)))

#define YYTABLE_NINF -81

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -135,    33,  -135,  -135,   -12,    59,    18,    25,    36,   201,
    -135,  -135,  -135,    44,   -13,     6,  -135,  -135,  -135,  -135,
    -135,   234,   234,   184,    58,    72,    61,    67,    75,    90,
      -4,    48,    98,   104,   313,   147,  -135,   148,    19,   149,
     143,   402,   379,   152,  -135,  -135,  -135,   171,  -135,  -135,
     134,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,  -135,  -135,
    -135,   234,   234,   136,   234,   402,   153,   154,   159,   161,
      96,   234,    71,  -135,   187,   234,   164,    36,    10,   194,
    -135,    32,    32,   324,   324,   409,   430,    32,    32,    51,
      51,  -135,  -135,   402,   402,   234,   -18,   -11,   402,   234,
     234,   234,   234,   163,   182,   191,   250,   192,   193,   199,
     203,   102,   234,   142,   212,   181,   187,   230,   -15,    65,
     190,  -135,   236,    41,  -135,   197,   234,  -135,   402,   402,
     402,   402,   136,   136,   136,   204,   234,   234,   234,   234,
     206,   207,   208,   271,   234,   234,   234,   234,   234,   234,
      -3,    -3,   210,   214,   222,   187,   109,   244,   234,    -3,
    -135,   234,   402,   211,   211,   211,   234,   402,   402,   402,
     402,   136,   136,   136,   121,   402,   402,   402,   402,   402,
     402,   255,   263,    36,   187,   223,   153,   154,   159,   161,
     156,   113,   334,   266,    55,   292,   211,   211,   211,  -135,
    -135,  -135,   229,   231,  -135,   235,   234,   163,   182,   191,
     192,   193,   199,   203,   185,   234,   233,  -135,  -135,  -135,
    -135,  -135,   355,   206,   207,   208,   355,  -135,  -135,  -135
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     5,     1,     0,     0,     0,     0,     0,     5,
       2,    90,    91,     0,   112,     0,   109,   108,   110,   107,
     111,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,     0,     0,     0,
     112,   103,     0,    78,    82,    84,    86,    13,    14,    15,
       0,    17,     3,     6,    11,    12,     9,    10,    57,    56,
      55,    58,    59,    60,    18,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,    25,
      24,     0,     0,     0,     0,    46,    52,    53,    54,    51,
       0,     0,     0,   106,     0,     0,     0,     0,     0,     0,
      16,    99,   100,   104,   105,   101,   102,    97,    98,    92,
      93,    94,    95,    47,    48,     0,     0,     0,    20,     0,
       0,     0,     0,    61,    62,    63,     0,    65,    66,    67,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,     0,    50,     0,     0,    49,    33,    34,
      35,    32,     0,     0,     0,    74,     0,     0,     0,     0,
      68,    69,    70,     0,     0,     0,     0,     0,     0,     0,
       5,     5,     0,     0,     0,     0,     0,     0,     0,     5,
      22,     0,    21,    36,    37,    38,     0,    40,    41,    42,
      39,     0,     0,     0,     0,    29,    28,    30,    31,    27,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    44,    45,    71,
      72,    73,     0,     0,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    75,    77,
      79,    85,     0,     0,     0,     0,     0,    81,    88,    89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,   -90,  -135,   283,   -20,  -135,  -113,  -134,  -135,
    -135,  -133,   188,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
     -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    10,     2,    23,    24,    25,   117,   116,    26,
      27,   134,    28,    29,    30,    31,    47,    94,    95,    48,
      99,    49,    96,    50,    97,    51,    98,   141,    32,    33,
      34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    42,   143,   172,    -7,    53,     5,   137,    11,    12,
      36,    13,    14,    15,    58,    59,    85,    60,   183,   184,
     185,    38,   174,    39,    37,   138,   139,    16,    17,    18,
      19,    20,   144,     3,   145,    21,   175,    86,    87,    88,
      89,   146,   205,   147,    22,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   216,   217,   218,
     113,   114,     6,   118,    90,     7,    61,    62,   214,    63,
     126,   225,    91,     8,   135,    74,    75,    76,    77,    -7,
     176,    35,   177,    11,    12,     9,    13,    14,    15,   127,
     128,   129,   130,   146,   118,   180,    76,    77,   148,   149,
     150,   151,    16,    17,    18,    19,    20,   146,    52,   237,
      21,   163,    54,   224,   123,   124,   131,   125,    55,    22,
     160,   161,    -7,   162,   132,   182,    56,   206,   207,   208,
     209,   230,   231,   232,   233,   187,   188,   189,   190,   219,
     220,    57,   221,   195,   196,   197,   198,   199,   200,    64,
     201,   202,   248,    85,   210,    65,   249,   212,   234,   213,
     118,    80,    79,    40,    92,   215,    36,   -76,   164,   165,
     166,   167,    81,    82,   227,   228,   -80,   229,    16,    17,
      18,    19,    20,   168,   169,   100,    21,   171,    43,   115,
     119,   120,    44,    45,    46,    22,   121,    83,   122,   142,
     152,    84,   133,   243,   244,   242,   245,    66,    67,    68,
      69,   136,    11,    12,   246,    13,    14,    15,   170,   153,
      70,    71,    72,    73,    74,    75,    76,    77,   154,   156,
     157,    16,    17,    18,    19,    20,   158,    40,   173,    21,
     159,   178,   179,   191,   192,   193,    81,    82,    22,    40,
     181,    -7,    16,    17,    18,    19,    20,   186,   203,   211,
      21,   204,   222,   145,    16,    17,    18,    19,    20,    22,
     223,    83,    21,   236,   226,    84,    66,    67,    68,    69,
     239,    22,   240,   241,   247,     4,   140,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    66,    67,    68,
      69,     0,     0,     0,   155,     0,     0,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    66,    67,
      68,    69,     0,     0,     0,   194,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    66,
      67,    68,    69,     0,     0,     0,   238,     0,     0,     0,
      66,    67,    70,    71,    72,    73,    74,    75,    76,    77,
      66,    67,    68,    69,    78,    72,    73,    74,    75,    76,
      77,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    66,    67,    68,    69,   235,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,     0,     0,     9,    66,    67,    68,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,     0,    93,    66,    67,
      68,    69,     0,     0,     0,    66,    67,    68,    69,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    71,
      72,    73,    74,    75,    76,    77,    66,    67,    68,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    73,    74,    75,    76,    77
};

static const yytype_int16 yycheck[] =
{
      21,    22,   115,   136,     7,    25,    18,    97,    11,    12,
      23,    14,    15,    16,    18,    19,    37,    21,   152,   153,
     154,    15,    37,    17,    37,    15,    16,    30,    31,    32,
      33,    34,    50,     0,    52,    38,    51,    18,    19,    20,
      21,    52,   175,    54,    47,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,   191,   192,   193,
      81,    82,     3,    84,    45,    47,    18,    19,   181,    21,
      91,   204,    53,    48,    95,    43,    44,    45,    46,     7,
      15,    37,    17,    11,    12,    49,    14,    15,    16,    18,
      19,    20,    21,    52,   115,    54,    45,    46,   119,   120,
     121,   122,    30,    31,    32,    33,    34,    52,    50,    54,
      38,   132,    51,   203,    18,    19,    45,    21,    51,    47,
      18,    19,    50,    21,    53,   146,    51,    18,    19,    20,
      21,    18,    19,    20,    21,   156,   157,   158,   159,    18,
      19,    51,    21,   164,   165,   166,   167,   168,   169,    51,
     170,   171,   242,   174,    45,    51,   246,   178,    45,   179,
     181,    13,    15,    15,    15,   186,    23,    15,    26,    27,
      28,    29,    24,    25,    18,    19,     5,    21,    30,    31,
      32,    33,    34,    41,    42,    51,    38,     6,     4,    53,
      37,    37,     8,     9,    10,    47,    37,    49,    37,     5,
      37,    53,    15,    18,    19,   226,    21,    26,    27,    28,
      29,    47,    11,    12,   235,    14,    15,    16,     6,    37,
      39,    40,    41,    42,    43,    44,    45,    46,    37,    37,
      37,    30,    31,    32,    33,    34,    37,    15,     8,    38,
      37,    51,     6,    37,    37,    37,    24,    25,    47,    15,
      53,    50,    30,    31,    32,    33,    34,    53,    48,    15,
      38,    47,     7,    52,    30,    31,    32,    33,    34,    47,
       7,    49,    38,     7,    51,    53,    26,    27,    28,    29,
      51,    47,    51,    48,    51,     2,    98,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    26,    27,    28,
      29,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    26,    27,
      28,    29,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    26,
      27,    28,    29,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      26,    27,    39,    40,    41,    42,    43,    44,    45,    46,
      26,    27,    28,    29,    51,    41,    42,    43,    44,    45,
      46,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    26,    27,    28,    29,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    49,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    26,    27,
      28,    29,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    40,
      41,    42,    43,    44,    45,    46,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,    58,     0,    59,    18,     3,    47,    48,    49,
      57,    11,    12,    14,    15,    16,    30,    31,    32,    33,
      34,    38,    47,    59,    60,    61,    64,    65,    67,    68,
      69,    70,    83,    84,    85,    37,    23,    37,    15,    17,
      15,    85,    85,     4,     8,     9,    10,    71,    74,    76,
      78,    80,    50,    60,    51,    51,    51,    51,    18,    19,
      21,    18,    19,    21,    51,    51,    26,    27,    28,    29,
      39,    40,    41,    42,    43,    44,    45,    46,    51,    15,
      13,    24,    25,    49,    53,    85,    18,    19,    20,    21,
      45,    53,    15,    48,    72,    73,    77,    79,    81,    75,
      51,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    53,    63,    62,    85,    37,
      37,    37,    37,    18,    19,    21,    85,    18,    19,    20,
      21,    45,    53,    15,    66,    85,    47,    57,    15,    16,
      67,    82,     5,    62,    50,    52,    52,    54,    85,    85,
      85,    85,    37,    37,    37,    54,    37,    37,    37,    37,
      18,    19,    21,    85,    26,    27,    28,    29,    41,    42,
       6,     6,    66,     8,    37,    51,    15,    17,    51,     6,
      54,    53,    85,    63,    63,    63,    53,    85,    85,    85,
      85,    37,    37,    37,    54,    85,    85,    85,    85,    85,
      85,    60,    60,    48,    47,    66,    18,    19,    20,    21,
      45,    15,    85,    60,    62,    85,    63,    63,    63,    18,
      19,    21,     7,     7,    57,    66,    51,    18,    19,    21,
      18,    19,    20,    21,    45,    51,     7,    54,    54,    51,
      51,    48,    85,    18,    19,    21,    85,    51,    57,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    58,    59,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    63,    63,    64,    65,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    70,    72,    71,    73,    71,
      75,    74,    77,    76,    79,    78,    81,    80,    82,    82,
      83,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     3,     0,     0,     2,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     2,     2,     2,
       1,     3,     3,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     5,     5,     5,     6,     6,     6,     6,
       6,     6,     6,     7,     7,     7,     3,     4,     4,     5,
       5,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     4,     4,     4,     4,     4,     4,     4,     5,     5,
       5,     7,     7,     7,     5,     8,     0,     7,     0,     7,
       0,     7,     0,     6,     0,     7,     0,     3,     6,     6,
       1,     1,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     1,     1,     1,
       1,     1,     1
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
#line 117 "sintatica.y" /* yacc.c:1646  */
    {
				printGlobalVariables();
				cout << "/*Compilador Eva*/\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n#define TRUE 1\n#define FALSE 0\n\nint main(void)\n{" <<endl;
				printVector();
				cout << (yyvsp[0]).traducao << "\treturn 0;\n}" << endl;
			}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 126 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).traducao = (yyvsp[-1]).traducao;
				}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 132 "sintatica.y" /* yacc.c:1646  */
    {
								contextoVariaveis.push_back(globalTabSym);
								cout << "Adicionado o contexto global!" << endl;
							}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 138 "sintatica.y" /* yacc.c:1646  */
    {
								addMapToStack();
							}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 143 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
					}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 148 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).traducao = "";
					}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 154 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 159 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 164 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 169 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 174 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 179 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
						}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 184 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
						}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 189 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
						}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 194 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 199 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
						}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 204 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 209 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[-1]);
						}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 215 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				tamanho_vetor++;
				label_vet.push((yyvsp[0]).label);
				tipo_vet.push((yyvsp[0]).tipo);
				trad_vet.push((yyvsp[0]).traducao);
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 225 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
				tamanho_vetor++;
				tamanho_linhas++;
				(yyval).tipo = (yyvsp[-2]).tipo;
				label_vet.push((yyvsp[0]).label);
				tipo_vet.push((yyvsp[0]).tipo);
				trad_vet.push((yyvsp[0]).traducao);
			}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 237 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).traducao = (yyvsp[-1]).traducao;
					(yyval).tipo = (yyvsp[-1]).tipo;
          tamanho_linhas++;
					//tamanho_vetor = 0;
					cout << "Adicionado uma linha! Linhas totais: " << tamanho_linhas << endl;
				}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 246 "sintatica.y" /* yacc.c:1646  */
    {
          (yyval).traducao = (yyvsp[-4]).traducao + (yyvsp[-1]).traducao;
          tamanho_colunas++;
					//tamanho_vetor = 0;
					cout << "Adicionado uma coluna! Colunas totais: " << tamanho_colunas << endl;
        }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 255 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = (yyvsp[-2]).tipo;
				variable Var = searchForVariable((yyvsp[-2]).label);
				cout << "$3.label = " << (yyvsp[0]).label << endl;
				(yyval).traducao = "\tstd::cin" + (yyval).traducao + (yyvsp[-2]).traducao + ";\n";
			}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 264 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				variable Var = searchForVariable((yyvsp[0]).label);
				(yyval).traducao = "\tstd::cout " + (yyvsp[0]).traducao + ";\n";
			}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 271 "sintatica.y" /* yacc.c:1646  */
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
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 295 "sintatica.y" /* yacc.c:1646  */
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
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 319 "sintatica.y" /* yacc.c:1646  */
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
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 343 "sintatica.y" /* yacc.c:1646  */
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
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 365 "sintatica.y" /* yacc.c:1646  */
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
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 387 "sintatica.y" /* yacc.c:1646  */
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
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 410 "sintatica.y" /* yacc.c:1646  */
    {
							erroTipo("char", (yyvsp[0]).tipo);
							string nomeAuxID = addVarToTabSym((yyvsp[-3]).label, (yyvsp[0]).traducao, "char");
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label + ";\n";
							addVarToTempVector("\tchar " + nomeAuxID + ";\n");
						}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 426 "sintatica.y" /* yacc.c:1646  */
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
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 451 "sintatica.y" /* yacc.c:1646  */
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
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 471 "sintatica.y" /* yacc.c:1646  */
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
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 485 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "int";
							if((yyvsp[0]).tipo != (yyval).tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = addVarToTabSym((yyvsp[-4]).label, (yyvsp[0]).traducao, "int*");
								//variable Var = searchForVariable(nomeAuxID);
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (int*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(int));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToTempVector("\tint* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 500 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "float";
							if((yyvsp[0]).tipo != (yyval).tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = addVarToTabSym((yyvsp[-4]).label, (yyvsp[0]).traducao, "float*");
								//variable Var = searchForVariable(nomeAuxID);
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (float*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(float));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 516 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "char";
							if((yyvsp[0]).tipo != (yyval).tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = addVarToTabSym((yyvsp[-4]).label, (yyvsp[0]).traducao, "char*");
								//variable Var = searchForVariable(nomeAuxID);
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (char*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(char));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 534 "sintatica.y" /* yacc.c:1646  */
    {
							erroTipo("char", (yyvsp[0]).tipo);
							string nomeAuxID = addVarToGlobalTabSym((yyvsp[-4]).label, (yyvsp[0]).traducao, "char");
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = " + (yyvsp[0]).label + ";\n";
						}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 549 "sintatica.y" /* yacc.c:1646  */
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
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 570 "sintatica.y" /* yacc.c:1646  */
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
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 588 "sintatica.y" /* yacc.c:1646  */
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
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 602 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "int";
							if((yyvsp[0]).tipo != (yyval).tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = addVarToGlobalTabSym((yyvsp[-5]).label, (yyvsp[0]).traducao, "int*");
								//variable Var = searchForVariable(nomeAuxID);
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (int*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(int));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToGlobalTempVector("\tint* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 617 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "float";
							if((yyvsp[0]).tipo != (yyval).tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = addVarToGlobalTabSym((yyvsp[-5]).label, (yyvsp[0]).traducao, "float*");
								//variable Var = searchForVariable(nomeAuxID);

								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (float*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(float));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToGlobalTempVector("\tfloat* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 634 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval).tipo = "char";
							if((yyvsp[0]).tipo != (yyval).tipo){
								yyerror("Erro de tipo na atribuição de vetor!");
							}
							else{
								string nomeAuxID = addVarToGlobalTabSym((yyvsp[-5]).label, (yyvsp[0]).traducao, "char*");
								//variable Var = searchForVariable(nomeAuxID);
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + nomeAuxID + " = (char*) malloc(" +
								to_string(tamanho_vetor) + " * sizeof(char));\n" + addElementsToArray(tamanho_vetor, nomeAuxID);
								addVarToGlobalTempVector("\tchar* " + nomeAuxID + ";\n");
								tamanho_vetor = 0;
							}
						}
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 652 "sintatica.y" /* yacc.c:1646  */
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
#line 2232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 677 "sintatica.y" /* yacc.c:1646  */
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
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 701 "sintatica.y" /* yacc.c:1646  */
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
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 716 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-4]).label);
							cout << Var.nome << endl;
							cout << Var.tipo << endl;
							cout << Var.valor << endl;
							if(Var.tipo != (yyvsp[-1]).tipo + '*'){

								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}

							else{

								/*if(tamanho_vetor > tamanho_linhas * tamanho_colunas){
									yyerror("Vetor atribuido maior que variável suporta!");
								}*/

								//else{
									variable Var = searchForVariable((yyvsp[-4]).label);
									cout << "********* " << tamanho_vetor << endl;
									(yyval).traducao = (yyvsp[-1]).traducao + addElementsToArray(tamanho_vetor, Var.nome);
									//tamanho_vetor -= tamanho_linhas;
									tamanho_vetor = 0;
								//}
							}
						}
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 743 "sintatica.y" /* yacc.c:1646  */
    {
							variable Var = searchForVariable((yyvsp[-4]).label);
							cout << Var.nome << endl;
							cout << Var.tipo << endl;
							cout << Var.valor << endl;
							if(Var.tipo != (yyvsp[-1]).tipo + '*'){

								yyerror("Um elemento tentando ser adicionado ao vetor que não é do mesmo tipo!");
							}

							else{

								cout << "?????? " << tamanho_linhas << " " << tamanho_colunas << endl;
								/*if(tamanho_vetor > tamanho_linhas * tamanho_colunas){
									yyerror("Vetor atribuido maior que variável suporta!");
								}*/

								//else{
									variable Var = searchForVariable((yyvsp[-4]).label);
									cout << "********* " << tamanho_vetor << endl;
									(yyval).traducao = (yyvsp[-1]).traducao + addElementsToArray(elementos_matriz, Var.nome);
									//tamanho_vetor -= tamanho_linhas;
									tamanho_vetor = 0;
								//}
							}
						}
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 772 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[-1]).label, "none", "char");
							(yyval).traducao = "\t";
							addVarToTempVector("\tchar " + nomeAuxID +  ";\n");
						}
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 786 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[-1]).label, "0", "int");
							(yyval).traducao = "\t";
							addVarToTempVector("\tint " + nomeAuxID + ";\n");
						}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 793 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[-1]).label, "0.0", "float");
							(yyval).traducao = "\t";
							addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
						}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 800 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[-1]).label, "TRUE", "bool");
							(yyval).traducao = "\t";
							addVarToTempVector("\tint " + nomeAuxID + ";\n");
						}
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 811 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[0]).label, "empty", "char*");
							variable auxiliarInteiro = searchForVariable((yyvsp[-1]).label);
							(yyval).traducao = "\t" + nomeAuxID + " = (char*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(char));\n";
							addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
						}
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 820 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[0]).label, "empty", "float*");
							variable auxiliarInteiro = searchForVariable((yyvsp[-1]).label);
							(yyval).traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(float));\n";
							addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
						}
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 829 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[0]).label, "empty", "int*");
							variable auxiliarInteiro = searchForVariable((yyvsp[-1]).label);
							(yyval).traducao = "\t" + nomeAuxID + " = (int*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(int));\n";
							addVarToTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 839 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[0]).label, "empty", "int*");
							//variable auxiliarInteiro = searchForVariable($1.label);
							(yyval).traducao = "\t" + nomeAuxID + " = (int*) malloc(" +
							to_string(elementos_matriz) + " * sizeof(int));\n";
							addVarToTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 848 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[0]).label, "empty", "float*");
							//variable auxiliarInteiro = searchForVariable($1.label);
							(yyval).traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							to_string(tamanho_vetor) + " * sizeof(float));\n";
							addVarToTempVector("\tfloa* " + nomeAuxID + ";\n");
						}
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 857 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[0]).label, "empty", "char*");
							//variable auxiliarInteiro = searchForVariable($1.label);
							(yyval).traducao = "\t" + nomeAuxID + " = (char*) malloc(" +
							to_string(tamanho_vetor) + " * sizeof(char));\n";
							addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
						}
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 867 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[-2]).label, "empty", "int*");
							variable auxiliarInteiro = searchForVariable((yyvsp[-3]).label);
							(yyval).traducao = "\t" + nomeAuxID + " = (int*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(int));\n";
							addVarToTempVector("\tint* " + nomeAuxID + ";\n");
						}
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 876 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[-2]).label, "empty", "float*");
							variable auxiliarInteiro = searchForVariable((yyvsp[-3]).label);
							(yyval).traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(float));\n";
							addVarToTempVector("\tfloat* " + nomeAuxID + ";\n");
						}
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 885 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[-2]).label, "empty", "char*");
							variable auxiliarInteiro = searchForVariable((yyvsp[-3]).label);
							(yyval).traducao = "\t" + nomeAuxID + " = (char*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(char));\n";
							addVarToTempVector("\tchar* " + nomeAuxID + ";\n");
						}
#line 2486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 896 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[-2]).label, "none", "char");
							(yyval).traducao = "\t";
						}
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 908 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToGlobalTabSym((yyvsp[-2]).label, "0", "int");
							(yyval).traducao = "\t";
						}
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 914 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToGlobalTabSym((yyvsp[-2]).label, "0.0", "float");
							(yyval).traducao = "\t";
						}
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 920 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToGlobalTabSym((yyvsp[-2]).label, "TRUE", "bool");
							(yyval).traducao = "\t";
						}
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 929 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToGlobalTabSym((yyvsp[-2]).label, "empty", "int*");
							(yyval).traducao = "\t";
						}
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 935 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToGlobalTabSym((yyvsp[-2]).label, "empty", "float*");
							variable Var = searchForVariable(nomeAuxID);
							cout << "SAÍ!" << endl;
							cout << Var.nome << endl;
							cout << Var.tipo << endl;
							cout << Var.valor << endl;
							//$$.tipo = "float*";
							(yyval).traducao = "\t";
						}
#line 2546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 947 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToTabSym((yyvsp[-2]).label, "empty", "char*");
							(yyval).traducao = "\t";
						}
#line 2555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 955 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToGlobalTabSym((yyvsp[-4]).label, "empty", "int*");
							variable auxiliarInteiro = searchForVariable((yyvsp[-2]).label);
							(yyval).traducao = "\t" + nomeAuxID + " = (int*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(int));\n";
						}
#line 2566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 963 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToGlobalTabSym((yyvsp[-4]).label, "empty", "float*");
							variable auxiliarInteiro = searchForVariable((yyvsp[-2]).label);
							(yyval).traducao = "\t" + nomeAuxID + " = (float*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(float));\n";
						}
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 971 "sintatica.y" /* yacc.c:1646  */
    {
							string nomeAuxID = addVarToGlobalTabSym((yyvsp[-4]).label, "empty", "char*");
							variable auxiliarInteiro = searchForVariable((yyvsp[-2]).label);
							(yyval).traducao = "\t" + nomeAuxID + " = (char*) malloc(" +
							auxiliarInteiro.valor + " * sizeof(char));\n";
						}
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 980 "sintatica.y" /* yacc.c:1646  */
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
										 }
									 }
								 }
#line 2610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1000 "sintatica.y" /* yacc.c:1646  */
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
#line 2658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1044 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 2664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1045 "sintatica.y" /* yacc.c:1646  */
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
#line 2686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1063 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 2692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1064 "sintatica.y" /* yacc.c:1646  */
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
#line 2714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1083 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops);}
#line 2720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1084 "sintatica.y" /* yacc.c:1646  */
    {
					int posiAlteracao = (yyvsp[-6]).traducao.rfind("final");
					string auxRetorno = (yyvsp[-6]).traducao;
					auxRetorno.insert(posiAlteracao, "goto final" + to_string(stackLoops.top()) + ";\n\n\t");
					(yyval).traducao = auxRetorno + (yyvsp[-2]).traducao + "\tfinal" + to_string(stackLoops.top()) + ":\n";
					stackLoops.pop();
					contextoVariaveis.pop_back();
					mapAtual--;
				}
#line 2734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1095 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("while");}
#line 2740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1096 "sintatica.y" /* yacc.c:1646  */
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
#line 2762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1134 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("while");}
#line 2768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1135 "sintatica.y" /* yacc.c:1646  */
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
#line 2790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1173 "sintatica.y" /* yacc.c:1646  */
    {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("for");}
#line 2796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1174 "sintatica.y" /* yacc.c:1646  */
    {
			  	(yyval) = (yyvsp[0]);
			  }
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1179 "sintatica.y" /* yacc.c:1646  */
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
#line 2834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1206 "sintatica.y" /* yacc.c:1646  */
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
#line 2864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1234 "sintatica.y" /* yacc.c:1646  */
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
#line 2882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1249 "sintatica.y" /* yacc.c:1646  */
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
#line 2900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1264 "sintatica.y" /* yacc.c:1646  */
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
#line 2929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1290 "sintatica.y" /* yacc.c:1646  */
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
#line 2948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1306 "sintatica.y" /* yacc.c:1646  */
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
#line 2967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1322 "sintatica.y" /* yacc.c:1646  */
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
#line 2986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1338 "sintatica.y" /* yacc.c:1646  */
    {

				variable Var = searchForVariable((yyvsp[-1]).label);
				(yyval).tipo = Var.tipo;
				(yyval).traducao = "\t" + (yyvsp[-1]).label + " = " + (yyvsp[-1]).label + " + 1;\n";
			}
#line 2997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1346 "sintatica.y" /* yacc.c:1646  */
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
#line 3028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1374 "sintatica.y" /* yacc.c:1646  */
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
#line 3051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1394 "sintatica.y" /* yacc.c:1646  */
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
#line 3073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1413 "sintatica.y" /* yacc.c:1646  */
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
#line 3095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1432 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = isBoolean((yyvsp[-2]).tipo, (yyvsp[0]).tipo);
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " || " + (yyvsp[0]).label + ";\n";
				addVarToTempVector("\tint " + (yyval).label + ";\n");
			}
#line 3106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1440 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = isBoolean((yyvsp[-2]).tipo, (yyvsp[0]).tipo);
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " && " + (yyvsp[0]).label + ";\n";
				addVarToTempVector("\tint " + (yyval).label + ";\n");
			}
#line 3117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1448 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
				(yyval).tipo = isBoolean("bool", (yyvsp[0]).tipo);
				(yyval).label = genLabel();
				(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = !" + (yyvsp[0]).label + ";\n";
				addVarToTempVector("\tint " + (yyval).label + ";\n");
			}
#line 3129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1457 "sintatica.y" /* yacc.c:1646  */
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
#line 3151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1476 "sintatica.y" /* yacc.c:1646  */
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
#line 3180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1502 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[-1]);
			}
#line 3188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1507 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "nomeTemporarioInt" + to_string(valorTemp++);
				(yyval).tipo = "int";
				addVarToTempVector("\t" + (yyval).tipo + " " + (yyval).label + ";\n");
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
				addVarToTabSym((yyval).label, (yyvsp[0]).traducao, "int");
			}
#line 3200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1516 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "nomeTemporarioFloat" + to_string(valorTemp++);
				(yyval).tipo = "float";
				addVarToTempVector("\tfloat " + (yyval).label + ";\n");
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
				addVarToTabSym((yyval).label, (yyvsp[0]).traducao, "float");
		 	}
#line 3212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1525 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "nomeTemporarioChar" + to_string(valorTemp++);
				(yyval).tipo = "char";
				addVarToTempVector("\tchar "  + (yyval).label + ";\n");
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
				addVarToTabSym((yyval).label, (yyvsp[0]).traducao, "char");
			}
#line 3224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1534 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "nomeTemporarioBool" + to_string(valorTemp++);
				(yyval).tipo = "bool";
				addVarToTempVector("\tint " + (yyval).label + ";\n");
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
				addVarToTabSym((yyval).label, (yyvsp[0]).traducao, "int");
			}
#line 3236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1543 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "nomeTemporarioString" + to_string(valorTemp++);
				(yyval).tipo = "string";
				addVarToTempVector("\tstring "  + (yyval).label + ";\n");
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
			}
#line 3247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1551 "sintatica.y" /* yacc.c:1646  */
    {
				variable auxVar = searchForVariable((yyvsp[0]).label);
				(yyval).label = auxVar.nome;
				(yyval).tipo = auxVar.tipo;
				(yyval).traducao;
			}
#line 3258 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3262 "y.tab.c" /* yacc.c:1646  */
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
#line 1558 "sintatica.y" /* yacc.c:1906  */


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
		cout << "globalTabSym depois " << (globalTabSym.empty() ? "is empty" : "is not empty" ) << endl;
		cout << "\nAdicionado " << globalTabSym[nomeDado].nome << " de tipo "<< globalTabSym[nomeDado].tipo <<" na tabela global de simbolos!\n" << endl;
		return globalTabSym[nomeDado].nome;
	}

	else {

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

	for(i; i >= 0; i--){

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

	int i = mapAtual; //inteiro para percorrer o vetor de mapas
	vector<unordered_map<string, variable>> auxVector; //vetor auxiliar para percorrer
	auxVector = contextoVariaveis; //atribuo o vetor de contexto global para o vetor auxiliar
	unordered_map<string, variable> auxMap; //mapa auxiliar para checar as variáveis dele

	cout << "\ncontextoVariaveis2 " << (contextoVariaveis.empty() ? "is empty" : "is not empty" ) << endl;
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

string addElementsToArray(int tamanhoArray, string nomeArray){

	string nome0 = "Auxiliar" + to_string(valorAuxiliar++);
	string nome1 = "Auxiliar" + to_string(valorAuxiliar++);

	cout << nome0 << endl;
	cout << nome1 << endl;

	if(mapAtual == 0){

		string nomeAux = addVarToGlobalTabSym(nome0, "0", "int");
		string acrescimo = addVarToGlobalTabSym(nome1, "1", "int");
		addVarToGlobalTempVector("\tint " + nomeAux + ";\n");
		addVarToGlobalTempVector("\tint " + acrescimo + ";\n");
	}

	else if (mapAtual != 0){
		string nomeAux = addVarToTabSym(nome0, "0", "int");
		string acrescimo = addVarToTabSym(nome1, "1", "int");
		addVarToTempVector("\tint " + nomeAux + ";\n");
		addVarToTempVector("\tint " + acrescimo + ";\n");
	}

	Variable Var1 = searchForVariable(nome0); //usar "var" como nome de variável é uma decisão horrível
	Variable Var2 = searchForVariable(nome1); //seja quem for lendo isso, não faça o que eu fiz
	string trad = "\t" + Var1.nome + " = 0;\n" + "\t" + Var2.nome + " = 1;\n";

	stack <string> auxStack;

	for(int i = 0; i < tamanhoArray; i++){ //uma das gambiarras mais criminosas que eu fiz
		auxStack.push(label_vet.top());
		label_vet.pop();
		tipo_vet.pop();
		trad_vet.pop();
	}

	for(int i = 0; i < tamanhoArray; i++){
		trad = trad + "\t" + nomeArray + "[" + Var1.nome + "] = " + auxStack.top() +
		";\n\t" + Var1.nome + " = " + Var1.nome + " + " + Var2.nome + ";\n"; //olha que coisa feia
		auxStack.pop();
	}

	return trad;
}
