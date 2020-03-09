/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#line 1 "syntax.y" /* yacc.c:339  */

	#include "lang_tools.h"

	extern int yylineno;
	extern char *yyval;
	extern char *yytext;
	extern FILE *yyin;
	extern FILE *yyout;
	
	int yyerror (char* yaccProvideMessage);
	int yylex (void);
	void messageHandler(const char *state1, const char *state2);

	int function_flag = 0;
	unsigned int scope;
	SymTable_T oSymTable;


#line 85 "syntax.c" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "syntax.h".  */
#ifndef YY_YY_SYNTAX_H_INCLUDED
# define YY_YY_SYNTAX_H_INCLUDED
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
    MY_MULTILINE_COMMENTS = 258,
    MY_SIMPLE_COMMENTS = 259,
    MY_STRING = 260,
    MY_IF = 261,
    MY_ELSE = 262,
    MY_FOR = 263,
    MY_WHILE = 264,
    MY_DO = 265,
    MY_CONTINUE = 266,
    MY_BREAK = 267,
    MY_RETURN = 268,
    MY_AND = 269,
    MY_OR = 270,
    MY_NOT = 271,
    MY_LOCAL = 272,
    MY_GLOBAL = 273,
    MY_STATIC = 274,
    MY_NIL = 275,
    MY_TRUE = 276,
    MY_FALSE = 277,
    MY_FUNCTION = 278,
    MY_ID = 279,
    MY_BLANK = 280,
    MY_NL = 281,
    MY_INTEGER = 282,
    MY_REAL = 283,
    MY_ASSIGN = 284,
    MY_EQUAL = 285,
    MY_NEQUAL = 286,
    MY_PLUS = 287,
    MY_INC = 288,
    MY_MINUS = 289,
    MY_DEC = 290,
    MY_MUL = 291,
    MY_DIV = 292,
    MY_MOD = 293,
    MY_L = 294,
    MY_LE = 295,
    MY_G = 296,
    MY_GE = 297,
    MY_OPEN_ANG = 298,
    MY_OPEN_BRA = 299,
    MY_OPEN_PAR = 300,
    MY_CLOSE_ANG = 301,
    MY_CLOSE_BRA = 302,
    MY_CLOSE_PAR = 303,
    MY_DOT_UD = 304,
    MY_DOT_STREAM = 305,
    MY_DOT_SIMPLE = 306,
    MY_DOT_DOUBLE = 307,
    MY_COMMA = 308,
    MY_SEMICOLON = 309,
    MY_OTHER = 310,
    UNARY_MINUS = 311
  };
#endif
/* Tokens.  */
#define MY_MULTILINE_COMMENTS 258
#define MY_SIMPLE_COMMENTS 259
#define MY_STRING 260
#define MY_IF 261
#define MY_ELSE 262
#define MY_FOR 263
#define MY_WHILE 264
#define MY_DO 265
#define MY_CONTINUE 266
#define MY_BREAK 267
#define MY_RETURN 268
#define MY_AND 269
#define MY_OR 270
#define MY_NOT 271
#define MY_LOCAL 272
#define MY_GLOBAL 273
#define MY_STATIC 274
#define MY_NIL 275
#define MY_TRUE 276
#define MY_FALSE 277
#define MY_FUNCTION 278
#define MY_ID 279
#define MY_BLANK 280
#define MY_NL 281
#define MY_INTEGER 282
#define MY_REAL 283
#define MY_ASSIGN 284
#define MY_EQUAL 285
#define MY_NEQUAL 286
#define MY_PLUS 287
#define MY_INC 288
#define MY_MINUS 289
#define MY_DEC 290
#define MY_MUL 291
#define MY_DIV 292
#define MY_MOD 293
#define MY_L 294
#define MY_LE 295
#define MY_G 296
#define MY_GE 297
#define MY_OPEN_ANG 298
#define MY_OPEN_BRA 299
#define MY_OPEN_PAR 300
#define MY_CLOSE_ANG 301
#define MY_CLOSE_BRA 302
#define MY_CLOSE_PAR 303
#define MY_DOT_UD 304
#define MY_DOT_STREAM 305
#define MY_DOT_SIMPLE 306
#define MY_DOT_DOUBLE 307
#define MY_COMMA 308
#define MY_SEMICOLON 309
#define MY_OTHER 310
#define UNARY_MINUS 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 27 "syntax.y" /* yacc.c:355  */

		char *stringValue;
		int integerValue;
		double realValue;

#line 243 "syntax.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 258 "syntax.c" /* yacc.c:358  */

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
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
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   503

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   125,   126,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   142,   143,   144,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   162,   163,   164,   165,   166,   167,   168,   169,   172,
     175,   176,   177,   178,   179,   182,   201,   202,   203,   206,
     207,   208,   209,   212,   213,   214,   217,   218,   221,   224,
     227,   228,   231,   232,   235,   236,   239,   242,   243,   246,
     249,   249,   256,   257,   260,   261,   262,   263,   264,   265,
     268,   269,   272,   273,   276,   277,   280,   283,   287,   288
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MY_MULTILINE_COMMENTS",
  "MY_SIMPLE_COMMENTS", "MY_STRING", "MY_IF", "MY_ELSE", "MY_FOR",
  "MY_WHILE", "MY_DO", "MY_CONTINUE", "MY_BREAK", "MY_RETURN", "MY_AND",
  "MY_OR", "MY_NOT", "MY_LOCAL", "MY_GLOBAL", "MY_STATIC", "MY_NIL",
  "MY_TRUE", "MY_FALSE", "MY_FUNCTION", "MY_ID", "MY_BLANK", "MY_NL",
  "MY_INTEGER", "MY_REAL", "MY_ASSIGN", "MY_EQUAL", "MY_NEQUAL", "MY_PLUS",
  "MY_INC", "MY_MINUS", "MY_DEC", "MY_MUL", "MY_DIV", "MY_MOD", "MY_L",
  "MY_LE", "MY_G", "MY_GE", "MY_OPEN_ANG", "MY_OPEN_BRA", "MY_OPEN_PAR",
  "MY_CLOSE_ANG", "MY_CLOSE_BRA", "MY_CLOSE_PAR", "MY_DOT_UD",
  "MY_DOT_STREAM", "MY_DOT_SIMPLE", "MY_DOT_DOUBLE", "MY_COMMA",
  "MY_SEMICOLON", "MY_OTHER", "UNARY_MINUS", "$accept", "program", "stmts",
  "stmt", "expr", "operator", "term", "assignexpr", "primary", "lvalue",
  "member", "call", "callsuffix", "normcall", "methodcall", "elist",
  "commaexprs", "objectdef", "indexed", "commaindex", "indexedelem",
  "block", "$@1", "funcdef", "const", "idlist", "idwithcommas", "ifstmt",
  "whilestmt", "forstmt", "returnstmt", YY_NULL
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -129

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-129)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     123,  -129,   -37,   -24,   -15,   -29,   -22,     7,   216,     9,
    -129,  -129,  -129,   -19,  -129,  -129,  -129,    62,   216,    62,
    -129,   154,   185,    19,  -129,    44,  -129,   123,   233,  -129,
    -129,  -129,    64,  -129,   -35,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,   216,   216,   216,  -129,  -129,  -129,   262,
    -129,  -129,     5,    32,    35,    39,   -35,  -129,    39,   123,
     216,    34,    12,    13,    10,   334,    14,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,   216,   216,  -129,  -129,   216,   216,
      43,    45,  -129,  -129,  -129,   216,   216,    56,   363,    31,
     376,  -129,    32,    41,    48,    52,    46,   320,   216,  -129,
    -129,  -129,    59,  -129,  -129,    58,   461,   461,   405,    57,
    -129,    61,   419,    63,  -129,   123,   216,   123,    66,    80,
    -129,    67,    58,  -129,   216,    34,    10,   216,  -129,  -129,
     216,  -129,  -129,   110,   291,  -129,    67,    41,  -129,   448,
    -129,  -129,    70,    72,   123,   216,  -129,  -129,  -129,  -129,
    -129,  -129,    73,   123,  -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    76,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,     0,    45,    75,    74,     0,     0,     0,
      70,    61,     0,     0,    14,     0,     2,     4,     0,    17,
      15,    38,    40,    48,    41,    42,    12,    13,    44,     6,
       7,     8,     9,     0,    61,     0,    11,    10,    88,     0,
      33,    46,     0,    81,     0,    34,     0,    32,    36,     4,
       0,    63,     0,     0,    68,     0,     0,    47,     1,     3,
      29,    30,    27,    28,    18,    19,    20,    21,    22,    25,
      26,    23,    24,     5,     0,     0,    35,    37,     0,    61,
       0,     0,    54,    56,    57,     0,    61,     0,     0,     0,
       0,    89,    81,    83,     0,     0,     0,     0,     0,    60,
      64,    65,     0,    66,    31,    43,    16,    39,     0,     0,
      49,     0,     0,     0,    51,     0,     0,     0,     0,     0,
      80,     0,     0,    71,     0,    63,    68,    61,    50,    58,
      61,    52,    53,    84,     0,    86,     0,    83,    72,     0,
      62,    67,     0,     0,     0,    61,    73,    82,    69,    55,
      59,    85,     0,     0,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,   -20,  -108,    -7,  -129,  -129,  -129,  -129,   -13,
    -129,     3,  -129,  -129,  -129,   -42,   -12,  -129,  -129,   -14,
      25,  -128,  -129,    -9,  -129,    22,   -21,  -129,  -129,  -129,
    -129
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    84,    29,    30,    31,    32,
      33,    34,    92,    93,    94,    62,   109,    35,    63,   113,
      64,    36,    59,    37,    38,   104,   130,    39,    40,    41,
      42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      49,    50,    99,   148,    55,    52,    58,    69,    43,    95,
      96,    57,     1,    66,    61,    65,    97,   143,   156,   145,
      56,    44,    56,     8,     9,    46,    53,    10,    11,    12,
      45,    14,    47,    51,    15,    16,    98,    61,   100,   106,
      17,    18,    19,    67,    68,   105,   161,   119,    70,    71,
     102,    21,    22,   107,   123,   164,   103,    23,    13,   110,
     111,    48,   115,   112,    72,    73,    74,   120,    75,   121,
      76,    77,    78,    79,    80,    81,    82,   116,   117,     9,
     124,   118,    61,    88,    89,   126,    14,   108,   122,    61,
      90,    91,   133,    85,   129,   152,   131,    86,   153,    87,
     132,   135,    60,   137,   147,   139,   140,    54,    88,    89,
      20,   142,    23,   162,   146,    90,    91,   154,   159,   144,
     160,   163,   151,   150,   128,     0,   157,   149,     1,     2,
      61,     3,     4,    61,     5,     6,     7,   136,     0,     8,
       9,     0,     0,    10,    11,    12,    13,    14,    61,     0,
      15,    16,     0,     0,     0,     0,    17,    18,    19,     1,
       0,     0,     0,     0,     0,     0,    20,    21,    22,     0,
       8,     9,     0,    23,    10,    11,    12,    24,    14,     0,
       0,    15,    16,     0,     0,     0,     0,    17,    18,    19,
       1,     0,     0,     0,     0,     0,     0,    60,    21,    22,
       0,     8,     9,     0,    23,    10,    11,    12,    13,    14,
       0,     0,    15,    16,     0,     0,     0,     0,    17,    18,
      19,     1,     0,     0,     0,     0,     0,     0,     0,    21,
      22,     0,     8,     9,     0,    23,    10,    11,    12,     0,
      14,     0,     0,    15,    16,     0,     0,    70,    71,    17,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    22,     0,    72,    73,    74,    23,    75,     0,    76,
      77,    78,    79,    80,    81,    82,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,    72,    73,    74,     0,    75,     0,    76,    77,
      78,    79,    80,    81,    82,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,     0,     0,     0,
       0,    72,    73,    74,     0,    75,     0,    76,    77,    78,
      79,    80,    81,    82,    70,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   155,     0,     0,    70,    71,
      72,    73,    74,     0,    75,     0,    76,    77,    78,    79,
      80,    81,    82,     0,    72,    73,    74,     0,    75,   134,
      76,    77,    78,    79,    80,    81,    82,    70,    71,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
      70,    71,     0,    72,    73,    74,     0,    75,     0,    76,
      77,    78,    79,    80,    81,    82,    72,    73,    74,     0,
      75,   125,    76,    77,    78,    79,    80,    81,    82,    70,
      71,     0,     0,     0,   127,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    71,    72,    73,    74,     0,    75,
       0,    76,    77,    78,    79,    80,    81,    82,     0,    72,
      73,    74,   138,    75,     0,    76,    77,    78,    79,    80,
      81,    82,    70,    71,     0,     0,   141,     0,     0,     0,
       0,     0,     0,     0,     0,    70,    71,     0,    72,    73,
      74,     0,    75,     0,    76,    77,    78,    79,    80,    81,
      82,    72,    73,    74,   158,    75,     0,    76,    77,    78,
      79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
       7,     8,    44,   131,    17,    24,    19,    27,    45,    44,
      45,    18,     5,    22,    21,    22,    51,   125,   146,   127,
      17,    45,    19,    16,    17,    54,    45,    20,    21,    22,
      45,    24,    54,    24,    27,    28,    43,    44,    45,    59,
      33,    34,    35,    24,     0,    54,   154,    89,    14,    15,
      45,    44,    45,    60,    96,   163,    24,    50,    23,    47,
      47,    54,    48,    53,    30,    31,    32,    24,    34,    24,
      36,    37,    38,    39,    40,    41,    42,    84,    85,    17,
      24,    88,    89,    44,    45,    54,    24,    53,    95,    96,
      51,    52,    46,    29,    53,   137,    48,    33,   140,    35,
      48,   108,    43,    45,    24,    48,    45,    45,    44,    45,
      43,    48,    50,   155,    48,    51,    52,     7,    48,   126,
      48,    48,   136,   135,   102,    -1,   147,   134,     5,     6,
     137,     8,     9,   140,    11,    12,    13,   112,    -1,    16,
      17,    -1,    -1,    20,    21,    22,    23,    24,   155,    -1,
      27,    28,    -1,    -1,    -1,    -1,    33,    34,    35,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    -1,
      16,    17,    -1,    50,    20,    21,    22,    54,    24,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      -1,    16,    17,    -1,    50,    20,    21,    22,    23,    24,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    16,    17,    -1,    50,    20,    21,    22,    -1,
      24,    -1,    -1,    27,    28,    -1,    -1,    14,    15,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    30,    31,    32,    50,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    30,    31,    32,    -1,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    30,    31,    32,    -1,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    14,    15,
      30,    31,    32,    -1,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    -1,    30,    31,    32,    -1,    34,    49,
      36,    37,    38,    39,    40,    41,    42,    14,    15,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    -1,    30,    31,    32,    -1,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    30,    31,    32,    -1,
      34,    48,    36,    37,    38,    39,    40,    41,    42,    14,
      15,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    15,    30,    31,    32,    -1,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    -1,    30,
      31,    32,    47,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    14,    15,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    15,    -1,    30,    31,
      32,    -1,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    30,    31,    32,    46,    34,    -1,    36,    37,    38,
      39,    40,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     8,     9,    11,    12,    13,    16,    17,
      20,    21,    22,    23,    24,    27,    28,    33,    34,    35,
      43,    44,    45,    50,    54,    58,    59,    60,    61,    63,
      64,    65,    66,    67,    68,    74,    78,    80,    81,    84,
      85,    86,    87,    45,    45,    45,    54,    54,    54,    61,
      61,    24,    24,    45,    45,    66,    68,    61,    66,    79,
      43,    61,    72,    75,    77,    61,    80,    24,     0,    59,
      14,    15,    30,    31,    32,    34,    36,    37,    38,    39,
      40,    41,    42,    54,    62,    29,    33,    35,    44,    45,
      51,    52,    69,    70,    71,    44,    45,    51,    61,    72,
      61,    54,    45,    24,    82,    80,    59,    61,    53,    73,
      47,    47,    53,    76,    48,    48,    61,    61,    61,    72,
      24,    24,    61,    72,    24,    48,    54,    48,    82,    53,
      83,    48,    48,    46,    49,    61,    77,    45,    47,    48,
      45,    47,    48,    60,    61,    60,    48,    24,    78,    61,
      73,    76,    72,    72,     7,    54,    78,    83,    46,    48,
      48,    60,    72,    48,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      65,    65,    65,    65,    65,    66,    66,    66,    66,    67,
      67,    67,    67,    68,    68,    68,    69,    69,    70,    71,
      72,    72,    73,    73,    74,    74,    75,    76,    76,    77,
      79,    78,    80,    80,    81,    81,    81,    81,    81,    81,
      82,    82,    83,    83,    84,    84,    85,    86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     3,
       1,     1,     1,     3,     1,     1,     2,     2,     1,     3,
       4,     3,     4,     4,     2,     6,     1,     1,     3,     5,
       2,     0,     3,     0,     3,     3,     2,     3,     0,     5,
       0,     4,     5,     6,     1,     1,     1,     1,     1,     1,
       2,     0,     3,     0,     5,     7,     5,     9,     2,     3
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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
#line 122 "syntax.y" /* yacc.c:1646  */
    { messageHandler("program", "statements");	}
#line 1507 "syntax.c" /* yacc.c:1646  */
    break;

  case 3:
#line 125 "syntax.y" /* yacc.c:1646  */
    { messageHandler("statements", "stmt statements");	}
#line 1513 "syntax.c" /* yacc.c:1646  */
    break;

  case 4:
#line 126 "syntax.y" /* yacc.c:1646  */
    { messageHandler("statements", "'e'");	}
#line 1519 "syntax.c" /* yacc.c:1646  */
    break;

  case 5:
#line 130 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "expr;");	}
#line 1525 "syntax.c" /* yacc.c:1646  */
    break;

  case 6:
#line 131 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "ifstmt");	}
#line 1531 "syntax.c" /* yacc.c:1646  */
    break;

  case 7:
#line 132 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "whilestmt");	}
#line 1537 "syntax.c" /* yacc.c:1646  */
    break;

  case 8:
#line 133 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "forstmt");	}
#line 1543 "syntax.c" /* yacc.c:1646  */
    break;

  case 9:
#line 134 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "returnstmt");	}
#line 1549 "syntax.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "break;");	}
#line 1555 "syntax.c" /* yacc.c:1646  */
    break;

  case 11:
#line 136 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "continue;");	}
#line 1561 "syntax.c" /* yacc.c:1646  */
    break;

  case 12:
#line 137 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "block");	}
#line 1567 "syntax.c" /* yacc.c:1646  */
    break;

  case 13:
#line 138 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "funcdef");	}
#line 1573 "syntax.c" /* yacc.c:1646  */
    break;

  case 14:
#line 139 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", ";");	}
#line 1579 "syntax.c" /* yacc.c:1646  */
    break;

  case 15:
#line 142 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "assignexpr");		}
#line 1585 "syntax.c" /* yacc.c:1646  */
    break;

  case 16:
#line 143 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr [operation] expr");	}
#line 1591 "syntax.c" /* yacc.c:1646  */
    break;

  case 17:
#line 144 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "term");			}
#line 1597 "syntax.c" /* yacc.c:1646  */
    break;

  case 31:
#line 162 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "(expr)"); }
#line 1603 "syntax.c" /* yacc.c:1646  */
    break;

  case 32:
#line 163 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "-expr");	}
#line 1609 "syntax.c" /* yacc.c:1646  */
    break;

  case 33:
#line 164 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "not expr");	}
#line 1615 "syntax.c" /* yacc.c:1646  */
    break;

  case 34:
#line 165 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "++yvalue");	}
#line 1621 "syntax.c" /* yacc.c:1646  */
    break;

  case 35:
#line 166 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "lvalue++");	}
#line 1627 "syntax.c" /* yacc.c:1646  */
    break;

  case 36:
#line 167 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "--lvalue");	}
#line 1633 "syntax.c" /* yacc.c:1646  */
    break;

  case 37:
#line 168 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "lvalue++");	}
#line 1639 "syntax.c" /* yacc.c:1646  */
    break;

  case 38:
#line 169 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "primary");	}
#line 1645 "syntax.c" /* yacc.c:1646  */
    break;

  case 39:
#line 172 "syntax.y" /* yacc.c:1646  */
    { messageHandler("assignexpr", "lvalue = expr");	}
#line 1651 "syntax.c" /* yacc.c:1646  */
    break;

  case 40:
#line 175 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "lvalue");		}
#line 1657 "syntax.c" /* yacc.c:1646  */
    break;

  case 41:
#line 176 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "call");		}
#line 1663 "syntax.c" /* yacc.c:1646  */
    break;

  case 42:
#line 177 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "objectdef");	}
#line 1669 "syntax.c" /* yacc.c:1646  */
    break;

  case 43:
#line 178 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "(funcdef)");	}
#line 1675 "syntax.c" /* yacc.c:1646  */
    break;

  case 44:
#line 179 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "const");		}
#line 1681 "syntax.c" /* yacc.c:1646  */
    break;

  case 45:
#line 182 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("lvalue", "identifier");

						/*Mpainei mesa otan eimaste global scope kai den yparxei hdh*/
						if (scope_lookup(yytext, scope) == 0 && scope == 0) {
							SymTable_put(oSymTable, yytext, 0, scope, yylineno, 1);
						}
						/*Error gia local scopes. An den yparxei mesa. Akoma kai na yparxei san global thelei ::*/
						else if (scope_lookup(yytext, scope) == 0 && scope > 0)
							printf("Error in line %d: Symbol '%s' not found in local scope %d.\n", yylineno, yytext, scope);

						printf("Searching [%s]\n", yytext);
						SymbolTableEntry* symbol = SymTable_get(oSymTable, yytext);
						if (symbol && symbol->type == 3)
							printf("Error in line %d: You cannot use a user defined function in assignment expresion.\n", yylineno);
						else if (symbol && symbol->type == 4)
							printf("Error in line %d: You cannot use a library function in assignment expresion.\n", yylineno);

						/*Den mpainei mesa se opoiodhpote scope. Prepei na paei apo LOCAL san Local*/
					}
#line 1705 "syntax.c" /* yacc.c:1646  */
    break;

  case 46:
#line 201 "syntax.y" /* yacc.c:1646  */
    { messageHandler("lvalue", "local_identifier"); }
#line 1711 "syntax.c" /* yacc.c:1646  */
    break;

  case 47:
#line 202 "syntax.y" /* yacc.c:1646  */
    { messageHandler("lvalue", ":: identifier");}
#line 1717 "syntax.c" /* yacc.c:1646  */
    break;

  case 48:
#line 203 "syntax.y" /* yacc.c:1646  */
    { messageHandler("lvalue", "member");		}
#line 1723 "syntax.c" /* yacc.c:1646  */
    break;

  case 49:
#line 206 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "lvalue.identifier");}
#line 1729 "syntax.c" /* yacc.c:1646  */
    break;

  case 50:
#line 207 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "lvalue[expr]");	}
#line 1735 "syntax.c" /* yacc.c:1646  */
    break;

  case 51:
#line 208 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "call.identifier");	}
#line 1741 "syntax.c" /* yacc.c:1646  */
    break;

  case 52:
#line 209 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "[expr]");		}
#line 1747 "syntax.c" /* yacc.c:1646  */
    break;

  case 53:
#line 212 "syntax.y" /* yacc.c:1646  */
    { messageHandler("call", "call(elist)");	}
#line 1753 "syntax.c" /* yacc.c:1646  */
    break;

  case 54:
#line 213 "syntax.y" /* yacc.c:1646  */
    { messageHandler("call", "lvalue callsuffix");	}
#line 1759 "syntax.c" /* yacc.c:1646  */
    break;

  case 55:
#line 214 "syntax.y" /* yacc.c:1646  */
    { messageHandler("call", "(funcdef)(elist)");	}
#line 1765 "syntax.c" /* yacc.c:1646  */
    break;

  case 56:
#line 217 "syntax.y" /* yacc.c:1646  */
    { messageHandler("callsuffix", "normcall");	}
#line 1771 "syntax.c" /* yacc.c:1646  */
    break;

  case 57:
#line 218 "syntax.y" /* yacc.c:1646  */
    { messageHandler("callsuffix", "methodcall");	}
#line 1777 "syntax.c" /* yacc.c:1646  */
    break;

  case 58:
#line 221 "syntax.y" /* yacc.c:1646  */
    { messageHandler("normcall", "(elist)");	}
#line 1783 "syntax.c" /* yacc.c:1646  */
    break;

  case 59:
#line 224 "syntax.y" /* yacc.c:1646  */
    { messageHandler("methodcall", "..identifier(elist)");	}
#line 1789 "syntax.c" /* yacc.c:1646  */
    break;

  case 60:
#line 227 "syntax.y" /* yacc.c:1646  */
    { messageHandler("elist", "expr comma-expressions");		}
#line 1795 "syntax.c" /* yacc.c:1646  */
    break;

  case 61:
#line 228 "syntax.y" /* yacc.c:1646  */
    { messageHandler("elist", "'e'");		}
#line 1801 "syntax.c" /* yacc.c:1646  */
    break;

  case 62:
#line 231 "syntax.y" /* yacc.c:1646  */
    { messageHandler("comma-expressions", ", expr comma-expressions");	}
#line 1807 "syntax.c" /* yacc.c:1646  */
    break;

  case 63:
#line 232 "syntax.y" /* yacc.c:1646  */
    { messageHandler("comma-expressions", "'e'");	}
#line 1813 "syntax.c" /* yacc.c:1646  */
    break;

  case 64:
#line 235 "syntax.y" /* yacc.c:1646  */
    { messageHandler("objectdef", "[elist]");	}
#line 1819 "syntax.c" /* yacc.c:1646  */
    break;

  case 65:
#line 236 "syntax.y" /* yacc.c:1646  */
    { messageHandler("objectdef", "[indexed]");	}
#line 1825 "syntax.c" /* yacc.c:1646  */
    break;

  case 66:
#line 239 "syntax.y" /* yacc.c:1646  */
    { messageHandler("indexed", "indexedelem commaindex");		}
#line 1831 "syntax.c" /* yacc.c:1646  */
    break;

  case 67:
#line 242 "syntax.y" /* yacc.c:1646  */
    { messageHandler("commaindex", ", indexedelem commaindex");		}
#line 1837 "syntax.c" /* yacc.c:1646  */
    break;

  case 68:
#line 243 "syntax.y" /* yacc.c:1646  */
    { messageHandler("commaindex", "'e'");		}
#line 1843 "syntax.c" /* yacc.c:1646  */
    break;

  case 69:
#line 246 "syntax.y" /* yacc.c:1646  */
    { messageHandler("indexedelem", "{expr:expr}");		}
#line 1849 "syntax.c" /* yacc.c:1646  */
    break;

  case 70:
#line 249 "syntax.y" /* yacc.c:1646  */
    {++scope;}
#line 1855 "syntax.c" /* yacc.c:1646  */
    break;

  case 71:
#line 250 "syntax.y" /* yacc.c:1646  */
    {
				hide(scope--); 
				messageHandler("block", "{stmts}"); 
			}
#line 1864 "syntax.c" /* yacc.c:1646  */
    break;

  case 72:
#line 256 "syntax.y" /* yacc.c:1646  */
    { messageHandler("funcdef", "function (idlist) block"); }
#line 1870 "syntax.c" /* yacc.c:1646  */
    break;

  case 73:
#line 257 "syntax.y" /* yacc.c:1646  */
    { messageHandler("funcdef", "function identifier (idlist) block");}
#line 1876 "syntax.c" /* yacc.c:1646  */
    break;

  case 74:
#line 260 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "real_value");	}
#line 1882 "syntax.c" /* yacc.c:1646  */
    break;

  case 75:
#line 261 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "integer_value");	}
#line 1888 "syntax.c" /* yacc.c:1646  */
    break;

  case 76:
#line 262 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "string");	}
#line 1894 "syntax.c" /* yacc.c:1646  */
    break;

  case 77:
#line 263 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "nil");	}
#line 1900 "syntax.c" /* yacc.c:1646  */
    break;

  case 78:
#line 264 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "true");	}
#line 1906 "syntax.c" /* yacc.c:1646  */
    break;

  case 79:
#line 265 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "false");	}
#line 1912 "syntax.c" /* yacc.c:1646  */
    break;

  case 80:
#line 268 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idlist", "identifier idwithcommas");	}
#line 1918 "syntax.c" /* yacc.c:1646  */
    break;

  case 81:
#line 269 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idlist", "'e'");		}
#line 1924 "syntax.c" /* yacc.c:1646  */
    break;

  case 82:
#line 272 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idwithcommas", ", identifier idwithcommas");		}
#line 1930 "syntax.c" /* yacc.c:1646  */
    break;

  case 83:
#line 273 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idwithcommas", "'e'");		}
#line 1936 "syntax.c" /* yacc.c:1646  */
    break;

  case 84:
#line 276 "syntax.y" /* yacc.c:1646  */
    { messageHandler("ifstmt", "if (expr) stmt");	}
#line 1942 "syntax.c" /* yacc.c:1646  */
    break;

  case 85:
#line 277 "syntax.y" /* yacc.c:1646  */
    { messageHandler("ifstmt", "if (expr) stmt else stmt");	}
#line 1948 "syntax.c" /* yacc.c:1646  */
    break;

  case 86:
#line 280 "syntax.y" /* yacc.c:1646  */
    { messageHandler("whilestmt", "while (exrpr) stmt");	}
#line 1954 "syntax.c" /* yacc.c:1646  */
    break;

  case 87:
#line 284 "syntax.y" /* yacc.c:1646  */
    { messageHandler("forstmt", "for (elist expr; expr; elist) stmt");	}
#line 1960 "syntax.c" /* yacc.c:1646  */
    break;

  case 88:
#line 287 "syntax.y" /* yacc.c:1646  */
    { messageHandler("returnstmt", "return;");		}
#line 1966 "syntax.c" /* yacc.c:1646  */
    break;

  case 89:
#line 288 "syntax.y" /* yacc.c:1646  */
    { messageHandler("returnstmt", "return expr;");		}
#line 1972 "syntax.c" /* yacc.c:1646  */
    break;


#line 1976 "syntax.c" /* yacc.c:1646  */
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
#line 290 "syntax.y" /* yacc.c:1906  */


int yyerror (char *yaccProvidedMessage)
{
	fprintf(stderr, "%s: at line %d, before token: '%s'\n", yaccProvidedMessage, yylineno, yytext);
	fprintf(stderr, "INPUT NOT VALID\n");

	return 0;
}

void messageHandler(const char *state1, const char *state2) {
/*
	char buffer[1024];
	memset(buffer,'\0', 1024);
	strcpy(buffer, "STATE: ");
	strcat(buffer, state1);
	strcat(buffer, "\t----->\tSTATE: ");
	strcat(buffer, state2);
	strcat(buffer,"\n");
	fprintf(yyout, buffer, 1024);
	*/
}



int main(int argc, char** argv) {

	oSymTable = SymTable_new();

	if (argc > 1) {
		if (!(yyin = fopen(argv[1], "r"))) {
			fprintf(stderr, "Cannot read file!\n");
			return 1;
		}
	}else
		yyin = stdin;

	yyout = stdout;
	yyparse();
	Print(oSymTable);
	printScopeLists();
	return 0;
}
