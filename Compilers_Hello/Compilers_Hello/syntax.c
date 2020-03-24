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
	char funcName[8];
	int function_counter = 0;

	int scope;
	SymTable_T oSymTable;


#line 88 "syntax.c" /* yacc.c:339  */

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
#line 30 "syntax.y" /* yacc.c:355  */

		char *stringValue;
		int integerValue;
		double realValue;

#line 246 "syntax.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 261 "syntax.c" /* yacc.c:358  */

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
#define YYLAST   514

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

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
       0,   125,   125,   128,   129,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   145,   146,   147,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   165,   166,   167,   168,   176,   176,   183,   191,   191,
     198,   201,   201,   212,   213,   214,   215,   216,   219,   245,
     259,   265,   268,   269,   270,   271,   274,   275,   276,   279,
     280,   283,   286,   289,   290,   293,   294,   297,   298,   301,
     304,   305,   308,   311,   311,   318,   318,   326,   326,   339,
     339,   356,   357,   358,   359,   360,   361,   364,   364,   375,
     378,   378,   390,   393,   394,   397,   400,   404,   405
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
  "stmt", "expr", "operator", "term", "$@1", "$@2", "assignexpr", "$@3",
  "primary", "lvalue", "member", "call", "callsuffix", "normcall",
  "methodcall", "elist", "commaexprs", "objectdef", "indexed",
  "commaindex", "indexedelem", "block", "$@4", "funblock", "$@5",
  "funcdef", "$@6", "$@7", "const", "idlist", "$@8", "idwithcommas", "$@9",
  "ifstmt", "whilestmt", "forstmt", "returnstmt", YY_NULL
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

#define YYPACT_NINF -123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define YYTABLE_NINF -42

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     130,  -123,   -38,   -37,   -32,   -36,   -28,   161,   227,     4,
    -123,  -123,  -123,     7,  -123,  -123,  -123,    -5,   227,    -5,
    -123,    47,   196,     8,  -123,    29,  -123,   130,    72,  -123,
    -123,  -123,    21,  -123,   -24,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,   227,   227,   227,  -123,  -123,  -123,   244,
    -123,  -123,  -123,   -15,    16,   -35,   -24,  -123,   -35,   130,
     227,   302,    -6,    -4,   -11,   345,    -2,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,   227,   227,   227,    20,    25,    18,
      23,    26,  -123,  -123,  -123,   227,   227,    35,   374,    22,
     387,  -123,    15,    37,    14,    24,   331,   227,  -123,  -123,
    -123,    40,  -123,  -123,    39,   472,   416,    45,  -123,    49,
    -123,  -123,   227,   430,    48,  -123,   130,   227,   130,    37,
    -123,    51,    39,  -123,   227,   302,   -11,   227,  -123,  -123,
     227,   472,  -123,  -123,    78,   273,  -123,    57,    42,    64,
     459,  -123,  -123,    68,    70,   130,   227,    64,    95,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,    73,  -123,  -123,   130,
     130,    42,    76,  -123,  -123,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    83,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,    86,    77,    48,    82,    81,     0,     0,     0,
      73,    64,     0,     0,    14,     0,     2,     4,     0,    17,
      15,    40,    43,    51,    44,    45,    12,    13,    47,     6,
       7,     8,     9,     0,    64,     0,    11,    10,    97,     0,
      33,    49,    79,     0,     0,    34,     0,    32,    37,     4,
       0,    66,     0,     0,    71,     0,     0,    50,     1,     3,
      29,    30,    27,    28,    18,    19,    20,    21,    22,    25,
      26,    23,    24,     5,     0,     0,    64,     0,     0,     0,
       0,     0,    57,    59,    60,     0,    64,     0,     0,     0,
       0,    98,     0,    89,     0,     0,     0,     0,    63,    67,
      68,     0,    69,    31,    46,    16,     0,     0,    52,     0,
      36,    39,     0,     0,     0,    54,     0,     0,     0,    89,
      87,     0,     0,    74,     0,    66,    71,    64,    53,    61,
      64,    42,    55,    56,    93,     0,    95,     0,    92,     0,
       0,    65,    70,     0,     0,     0,    64,     0,     0,    88,
      75,    78,    72,    58,    62,    94,     0,    80,    90,     4,
       0,    92,     0,    96,    91,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -123,  -123,   -25,  -122,    -7,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,     5,  -123,     6,  -123,  -123,  -123,   -39,   -12,
    -123,  -123,    -8,    13,  -123,  -123,   -26,  -123,   -19,  -123,
    -123,  -123,     0,  -123,   -46,  -123,  -123,  -123,  -123,  -123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    84,    29,    89,    90,    30,
      91,    31,    32,    33,    34,    92,    93,    94,    62,   108,
      35,    63,   112,    64,    36,    59,   161,   169,    37,    53,
     102,    38,   131,   148,   159,   171,    39,    40,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    50,    69,    66,   144,    99,   146,    43,    44,    85,
      86,    57,     9,    45,    61,    65,    87,    88,    46,    14,
      95,    96,    55,    56,    58,    56,    47,    97,    51,    68,
     103,    52,    67,   165,   105,   104,    98,    61,   100,    13,
      54,   109,   111,   110,   118,    23,   114,   117,   173,   119,
     -41,   120,     1,   106,   -35,   122,   -38,   124,   121,   125,
     129,   130,   132,     8,     9,    85,    86,    10,    11,    12,
     133,    14,    87,    88,    15,    16,   127,   115,   116,    61,
      17,    18,    19,    60,   137,   155,    70,    71,   123,    61,
      60,    21,    22,   139,   140,   158,   143,    23,   153,   149,
     135,   154,    72,    73,    74,   157,    75,   160,    76,    77,
      78,    79,    80,    81,    82,   141,   163,   166,   164,   168,
     145,   170,   175,   151,   136,   174,    83,   150,   152,   147,
      61,   167,     0,    61,     0,     1,     2,     0,     3,     4,
       0,     5,     6,     7,   172,     0,     8,     9,     0,    61,
      10,    11,    12,    13,    14,     0,     0,    15,    16,     0,
       0,     0,     0,    17,    18,    19,     1,     0,     0,     0,
       0,     0,     0,    20,    21,    22,     0,     8,     9,     0,
      23,    10,    11,    12,    24,    14,     0,     0,    15,    16,
       0,     0,     0,     0,    17,    18,    19,     0,     0,     0,
       0,     1,     0,     0,     0,    21,    22,     0,     0,     0,
       0,    23,     8,     9,     0,    48,    10,    11,    12,    13,
      14,     0,     0,    15,    16,     0,     0,     0,     0,    17,
      18,    19,     1,     0,     0,     0,     0,     0,     0,     0,
      21,    22,     0,     8,     9,     0,    23,    10,    11,    12,
       0,    14,     0,     0,    15,    16,     0,     0,    70,    71,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    22,     0,    72,    73,    74,    23,    75,     0,
      76,    77,    78,    79,    80,    81,    82,    70,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,     0,
       0,     0,     0,    72,    73,    74,     0,    75,     0,    76,
      77,    78,    79,    80,    81,    82,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   156,     0,     0,
       0,     0,    72,    73,    74,     0,    75,     0,    76,    77,
      78,    79,    80,    81,    82,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,    70,
      71,    72,    73,    74,     0,    75,     0,    76,    77,    78,
      79,    80,    81,    82,     0,    72,    73,    74,     0,    75,
     134,    76,    77,    78,    79,    80,    81,    82,    70,    71,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,    70,    71,     0,    72,    73,    74,     0,    75,     0,
      76,    77,    78,    79,    80,    81,    82,    72,    73,    74,
       0,    75,   126,    76,    77,    78,    79,    80,    81,    82,
      70,    71,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    71,    72,    73,    74,     0,
      75,     0,    76,    77,    78,    79,    80,    81,    82,     0,
      72,    73,    74,   138,    75,     0,    76,    77,    78,    79,
      80,    81,    82,    70,    71,     0,     0,   142,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,     0,    72,
      73,    74,     0,    75,     0,    76,    77,    78,    79,    80,
      81,    82,    72,    73,    74,   162,    75,     0,    76,    77,
      78,    79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
       7,     8,    27,    22,   126,    44,   128,    45,    45,    44,
      45,    18,    17,    45,    21,    22,    51,    52,    54,    24,
      44,    45,    17,    17,    19,    19,    54,    51,    24,     0,
      45,    24,    24,   155,    59,    54,    43,    44,    45,    23,
      45,    47,    53,    47,    24,    50,    48,    86,   170,    24,
      29,    33,     5,    60,    33,    29,    35,    96,    35,    24,
      45,    24,    48,    16,    17,    44,    45,    20,    21,    22,
      46,    24,    51,    52,    27,    28,    54,    84,    85,    86,
      33,    34,    35,    43,    45,     7,    14,    15,    95,    96,
      43,    44,    45,    48,    45,    53,    48,    50,   137,    48,
     107,   140,    30,    31,    32,    48,    34,    43,    36,    37,
      38,    39,    40,    41,    42,   122,    48,   156,    48,    24,
     127,    48,    46,   135,   111,   171,    54,   134,   136,   129,
     137,   157,    -1,   140,    -1,     5,     6,    -1,     8,     9,
      -1,    11,    12,    13,   169,    -1,    16,    17,    -1,   156,
      20,    21,    22,    23,    24,    -1,    -1,    27,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    -1,    16,    17,    -1,
      50,    20,    21,    22,    54,    24,    -1,    -1,    27,    28,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,     5,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    50,    16,    17,    -1,    54,    20,    21,    22,    23,
      24,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    16,    17,    -1,    50,    20,    21,    22,
      -1,    24,    -1,    -1,    27,    28,    -1,    -1,    14,    15,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    30,    31,    32,    50,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    30,    31,    32,    -1,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    30,    31,    32,    -1,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    14,
      15,    30,    31,    32,    -1,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    -1,    30,    31,    32,    -1,    34,
      49,    36,    37,    38,    39,    40,    41,    42,    14,    15,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    15,    -1,    30,    31,    32,    -1,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    30,    31,    32,
      -1,    34,    48,    36,    37,    38,    39,    40,    41,    42,
      14,    15,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    30,    31,    32,    -1,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    -1,
      30,    31,    32,    47,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    14,    15,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,    30,
      31,    32,    -1,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    30,    31,    32,    46,    34,    -1,    36,    37,
      38,    39,    40,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     8,     9,    11,    12,    13,    16,    17,
      20,    21,    22,    23,    24,    27,    28,    33,    34,    35,
      43,    44,    45,    50,    54,    58,    59,    60,    61,    63,
      66,    68,    69,    70,    71,    77,    81,    85,    88,    93,
      94,    95,    96,    45,    45,    45,    54,    54,    54,    61,
      61,    24,    24,    86,    45,    69,    71,    61,    69,    82,
      43,    61,    75,    78,    80,    61,    85,    24,     0,    59,
      14,    15,    30,    31,    32,    34,    36,    37,    38,    39,
      40,    41,    42,    54,    62,    44,    45,    51,    52,    64,
      65,    67,    72,    73,    74,    44,    45,    51,    61,    75,
      61,    54,    87,    45,    85,    59,    61,    53,    76,    47,
      47,    53,    79,    48,    48,    61,    61,    75,    24,    24,
      33,    35,    29,    61,    75,    24,    48,    54,    48,    45,
      24,    89,    48,    46,    49,    61,    80,    45,    47,    48,
      45,    61,    47,    48,    60,    61,    60,    89,    90,    48,
      61,    76,    79,    75,    75,     7,    54,    48,    53,    91,
      43,    83,    46,    48,    48,    60,    75,    83,    24,    84,
      48,    92,    59,    60,    91,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    64,    63,    63,    65,    63,
      63,    67,    66,    68,    68,    68,    68,    68,    69,    69,
      69,    69,    70,    70,    70,    70,    71,    71,    71,    72,
      72,    73,    74,    75,    75,    76,    76,    77,    77,    78,
      79,    79,    80,    82,    81,    84,    83,    86,    85,    87,
      85,    88,    88,    88,    88,    88,    88,    90,    89,    89,
      92,    91,    91,    93,    93,    94,    95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     2,     0,     3,     2,     0,     3,
       1,     0,     4,     1,     1,     1,     3,     1,     1,     2,
       2,     1,     3,     4,     3,     4,     4,     2,     6,     1,
       1,     3,     5,     2,     0,     3,     0,     3,     3,     2,
       3,     0,     5,     0,     4,     0,     4,     0,     6,     0,
       7,     1,     1,     1,     1,     1,     1,     0,     3,     0,
       0,     4,     0,     5,     7,     5,     9,     2,     3
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
#line 125 "syntax.y" /* yacc.c:1646  */
    { messageHandler("program", "statements");	}
#line 1519 "syntax.c" /* yacc.c:1646  */
    break;

  case 3:
#line 128 "syntax.y" /* yacc.c:1646  */
    { messageHandler("statements", "stmt statements");	}
#line 1525 "syntax.c" /* yacc.c:1646  */
    break;

  case 4:
#line 129 "syntax.y" /* yacc.c:1646  */
    { messageHandler("statements", "'e'");	}
#line 1531 "syntax.c" /* yacc.c:1646  */
    break;

  case 5:
#line 133 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "expr;");	}
#line 1537 "syntax.c" /* yacc.c:1646  */
    break;

  case 6:
#line 134 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "ifstmt");	}
#line 1543 "syntax.c" /* yacc.c:1646  */
    break;

  case 7:
#line 135 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "whilestmt");	}
#line 1549 "syntax.c" /* yacc.c:1646  */
    break;

  case 8:
#line 136 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "forstmt");	}
#line 1555 "syntax.c" /* yacc.c:1646  */
    break;

  case 9:
#line 137 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "returnstmt");	}
#line 1561 "syntax.c" /* yacc.c:1646  */
    break;

  case 10:
#line 138 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "break;");	}
#line 1567 "syntax.c" /* yacc.c:1646  */
    break;

  case 11:
#line 139 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "continue;");	}
#line 1573 "syntax.c" /* yacc.c:1646  */
    break;

  case 12:
#line 140 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "block");	}
#line 1579 "syntax.c" /* yacc.c:1646  */
    break;

  case 13:
#line 141 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "funcdef");	}
#line 1585 "syntax.c" /* yacc.c:1646  */
    break;

  case 14:
#line 142 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", ";");	}
#line 1591 "syntax.c" /* yacc.c:1646  */
    break;

  case 15:
#line 145 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "assignexpr");		}
#line 1597 "syntax.c" /* yacc.c:1646  */
    break;

  case 16:
#line 146 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr [operation] expr");	}
#line 1603 "syntax.c" /* yacc.c:1646  */
    break;

  case 17:
#line 147 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "term");			}
#line 1609 "syntax.c" /* yacc.c:1646  */
    break;

  case 31:
#line 165 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "(expr)"); }
#line 1615 "syntax.c" /* yacc.c:1646  */
    break;

  case 32:
#line 166 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "-expr");	}
#line 1621 "syntax.c" /* yacc.c:1646  */
    break;

  case 33:
#line 167 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "not expr");	}
#line 1627 "syntax.c" /* yacc.c:1646  */
    break;

  case 34:
#line 168 "syntax.y" /* yacc.c:1646  */
    {
										SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
										if (symbol && symbol->type == 3)
											printf("Error in line %d: You cannot increase left a user defined function (%s).\n", yylineno, yylval.stringValue);
										else if (symbol && symbol->type == 4)
											printf("Error in line %d: You cannot increase left a library function (%s).\n", yylineno, yylval.stringValue);
										messageHandler("term", "++yvalue");	
									}
#line 1640 "syntax.c" /* yacc.c:1646  */
    break;

  case 35:
#line 176 "syntax.y" /* yacc.c:1646  */
    {
						SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
						if (symbol && symbol->type == 3)
							printf("Error in line %d: You cannot increase right a user defined function (%s).\n", yylineno, yylval.stringValue);
						else if (symbol && symbol->type == 4)
							printf("Error in line %d: You cannot increase right a library function (%s).\n", yylineno, yylval.stringValue);
				 }
#line 1652 "syntax.c" /* yacc.c:1646  */
    break;

  case 36:
#line 182 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "lvalue++");	}
#line 1658 "syntax.c" /* yacc.c:1646  */
    break;

  case 37:
#line 183 "syntax.y" /* yacc.c:1646  */
    { 
										SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
										if (symbol && symbol->type == 3)
											printf("Error in line %d: You cannot decrease left a user defined function (%s).\n", yylineno, yylval.stringValue);
										else if (symbol && symbol->type == 4)
											printf("Error in line %d: You cannot decrease left a library function (%s).\n", yylineno, yylval.stringValue);
										messageHandler("term", "--lvalue");	
									}
#line 1671 "syntax.c" /* yacc.c:1646  */
    break;

  case 38:
#line 191 "syntax.y" /* yacc.c:1646  */
    {
						SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
						if (symbol && symbol->type == 3)
							printf("Error in line %d: You cannot decrease right a user defined function (%s).\n", yylineno, yylval.stringValue);
						else if (symbol && symbol->type == 4)
							printf("Error in line %d: You cannot decrease right a library function (%s).\n", yylineno, yylval.stringValue);
				 }
#line 1683 "syntax.c" /* yacc.c:1646  */
    break;

  case 39:
#line 197 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "lvalue++");	}
#line 1689 "syntax.c" /* yacc.c:1646  */
    break;

  case 40:
#line 198 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "primary");	}
#line 1695 "syntax.c" /* yacc.c:1646  */
    break;

  case 41:
#line 201 "syntax.y" /* yacc.c:1646  */
    {
						/* printf("Checking if [%s] is a library function or function\n", yylval.stringValue); */
						SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
						if (symbol && symbol->type == 3)
							printf("Error in line %d: You cannot use a user defined function in assignment expresion.\n", yylineno);
						else if (symbol && symbol->type == 4)
							printf("Error in line %d: You cannot use a library function in assignment expresion.\n", yylineno);

					 }
#line 1709 "syntax.c" /* yacc.c:1646  */
    break;

  case 42:
#line 209 "syntax.y" /* yacc.c:1646  */
    { messageHandler("assignexpr", "lvalue = expr");	}
#line 1715 "syntax.c" /* yacc.c:1646  */
    break;

  case 43:
#line 212 "syntax.y" /* yacc.c:1646  */
    {  messageHandler("primary", "lvalue");	}
#line 1721 "syntax.c" /* yacc.c:1646  */
    break;

  case 44:
#line 213 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "call");		}
#line 1727 "syntax.c" /* yacc.c:1646  */
    break;

  case 45:
#line 214 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "objectdef");	}
#line 1733 "syntax.c" /* yacc.c:1646  */
    break;

  case 46:
#line 215 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "(funcdef)");	}
#line 1739 "syntax.c" /* yacc.c:1646  */
    break;

  case 47:
#line 216 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "const");		}
#line 1745 "syntax.c" /* yacc.c:1646  */
    break;

  case 48:
#line 219 "syntax.y" /* yacc.c:1646  */
    {	
						/*Mpainei mesa otan eimaste global scope kai den yparxei hdh*/
						if (scope_lookup(yylval.stringValue, scope) == 0 && scope == 0) {
							SymTable_put(oSymTable, yylval.stringValue, 0, scope, yylineno, 1);
						}

						/*Periptwsh gia scope 1. Edw AN DEN yparxei topika h san GLOBAL mpainei san LOCAL*/
						if (scope_lookup(yylval.stringValue, scope) == 0 && scope_lookup(yylval.stringValue, scope - 1) == 0 && scope == 1) {
							SymTable_put(oSymTable, yylval.stringValue, 1, scope, yylineno, 1);
						}

						/* SE OLES TIS ALLES PERIPTWSEIS MAS NOIAZEI NA FAEI ERROR AMA YPHRXE SE PROHGOYMENO ANOIXTO SCOPE */
						if (scope > 1) {
							int check = catholic_lookup(yylval.stringValue);

							/* ERROR: giati yparxei se prohgoymena LOCAL SCOPES */
							if (check > 0 && check < scope && function_flag) {
								printf("Error: Can't be accessed! Current scope: %d. Same active local symbol %s found in scope %d.\n",scope, yylval.stringValue, check);
							}

							if (check == -1)	/* Dhladh ama den yparxei pouthena */
								SymTable_put(oSymTable, yylval.stringValue, 1, scope, yylineno, 1);
						}

						messageHandler("lvalue", "identifier"); 
					}
#line 1776 "syntax.c" /* yacc.c:1646  */
    break;

  case 49:
#line 245 "syntax.y" /* yacc.c:1646  */
    { 
								/* Periptwsh pou briskomaste sto Global Scope */
								if (scope_lookup(yylval.stringValue, scope) == 0 && scope == 0) {
									SymTable_put(oSymTable, yylval.stringValue, 0, scope, yylineno, 1);
								} else if (scope_lookup(yylval.stringValue, scope) == 0 && scope != 0) {
									SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
									if (symbol && symbol->type == 4)
										printf("Error in line %d: You cannot use a library function name as a local variable.\n", yylineno);
									else
										SymTable_put(oSymTable, yylval.stringValue, 1, scope, yylineno, 1);
								}

								messageHandler("lvalue", "local_identifier"); 
							}
#line 1795 "syntax.c" /* yacc.c:1646  */
    break;

  case 50:
#line 259 "syntax.y" /* yacc.c:1646  */
    {
									if (scope_lookup(yylval.stringValue, 0) == 0) {
										printf("Error in line %d: Not found global symbol with name [%s].\n", yylineno, yylval.stringValue);
									}
									messageHandler("lvalue", ":: identifier");
								}
#line 1806 "syntax.c" /* yacc.c:1646  */
    break;

  case 51:
#line 265 "syntax.y" /* yacc.c:1646  */
    { messageHandler("lvalue", "member");		}
#line 1812 "syntax.c" /* yacc.c:1646  */
    break;

  case 52:
#line 268 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "lvalue.identifier");}
#line 1818 "syntax.c" /* yacc.c:1646  */
    break;

  case 53:
#line 269 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "lvalue[expr]");	}
#line 1824 "syntax.c" /* yacc.c:1646  */
    break;

  case 54:
#line 270 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "call.identifier");	}
#line 1830 "syntax.c" /* yacc.c:1646  */
    break;

  case 55:
#line 271 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "[expr]");		}
#line 1836 "syntax.c" /* yacc.c:1646  */
    break;

  case 56:
#line 274 "syntax.y" /* yacc.c:1646  */
    { messageHandler("call", "call(elist)");	}
#line 1842 "syntax.c" /* yacc.c:1646  */
    break;

  case 57:
#line 275 "syntax.y" /* yacc.c:1646  */
    { messageHandler("call", "lvalue callsuffix");	}
#line 1848 "syntax.c" /* yacc.c:1646  */
    break;

  case 58:
#line 276 "syntax.y" /* yacc.c:1646  */
    { messageHandler("call", "(funcdef)(elist)");	}
#line 1854 "syntax.c" /* yacc.c:1646  */
    break;

  case 59:
#line 279 "syntax.y" /* yacc.c:1646  */
    { messageHandler("callsuffix", "normcall");	}
#line 1860 "syntax.c" /* yacc.c:1646  */
    break;

  case 60:
#line 280 "syntax.y" /* yacc.c:1646  */
    { messageHandler("callsuffix", "methodcall");	}
#line 1866 "syntax.c" /* yacc.c:1646  */
    break;

  case 61:
#line 283 "syntax.y" /* yacc.c:1646  */
    { messageHandler("normcall", "(elist)");	}
#line 1872 "syntax.c" /* yacc.c:1646  */
    break;

  case 62:
#line 286 "syntax.y" /* yacc.c:1646  */
    { messageHandler("methodcall", "..identifier(elist)");	}
#line 1878 "syntax.c" /* yacc.c:1646  */
    break;

  case 63:
#line 289 "syntax.y" /* yacc.c:1646  */
    { messageHandler("elist", "expr comma-expressions");		}
#line 1884 "syntax.c" /* yacc.c:1646  */
    break;

  case 64:
#line 290 "syntax.y" /* yacc.c:1646  */
    { messageHandler("elist", "'e'");		}
#line 1890 "syntax.c" /* yacc.c:1646  */
    break;

  case 65:
#line 293 "syntax.y" /* yacc.c:1646  */
    { messageHandler("comma-expressions", ", expr comma-expressions");	}
#line 1896 "syntax.c" /* yacc.c:1646  */
    break;

  case 66:
#line 294 "syntax.y" /* yacc.c:1646  */
    { messageHandler("comma-expressions", "'e'");	}
#line 1902 "syntax.c" /* yacc.c:1646  */
    break;

  case 67:
#line 297 "syntax.y" /* yacc.c:1646  */
    { messageHandler("objectdef", "[elist]");	}
#line 1908 "syntax.c" /* yacc.c:1646  */
    break;

  case 68:
#line 298 "syntax.y" /* yacc.c:1646  */
    { messageHandler("objectdef", "[indexed]");	}
#line 1914 "syntax.c" /* yacc.c:1646  */
    break;

  case 69:
#line 301 "syntax.y" /* yacc.c:1646  */
    { messageHandler("indexed", "indexedelem commaindex");		}
#line 1920 "syntax.c" /* yacc.c:1646  */
    break;

  case 70:
#line 304 "syntax.y" /* yacc.c:1646  */
    { messageHandler("commaindex", ", indexedelem commaindex");		}
#line 1926 "syntax.c" /* yacc.c:1646  */
    break;

  case 71:
#line 305 "syntax.y" /* yacc.c:1646  */
    { messageHandler("commaindex", "'e'");		}
#line 1932 "syntax.c" /* yacc.c:1646  */
    break;

  case 72:
#line 308 "syntax.y" /* yacc.c:1646  */
    { messageHandler("indexedelem", "{expr:expr}");		}
#line 1938 "syntax.c" /* yacc.c:1646  */
    break;

  case 73:
#line 311 "syntax.y" /* yacc.c:1646  */
    {++scope; if (function_flag == 1) function_flag = 0;}
#line 1944 "syntax.c" /* yacc.c:1646  */
    break;

  case 74:
#line 312 "syntax.y" /* yacc.c:1646  */
    {
				hide(scope--); 
				messageHandler("block", "{stmts}"); 
			}
#line 1953 "syntax.c" /* yacc.c:1646  */
    break;

  case 75:
#line 318 "syntax.y" /* yacc.c:1646  */
    {++scope; function_flag = 1;}
#line 1959 "syntax.c" /* yacc.c:1646  */
    break;

  case 76:
#line 319 "syntax.y" /* yacc.c:1646  */
    {
				hide(scope--); 
				function_flag = 0;
				messageHandler("funblock", "{stmts}"); 
			}
#line 1969 "syntax.c" /* yacc.c:1646  */
    break;

  case 77:
#line 326 "syntax.y" /* yacc.c:1646  */
    {
								/* Dhmiourgeia anonymous function */
								char tmp[3];
								memset(tmp, '\0', 3);
								memset(funcName, '\0', 8);
								strcpy(funcName, "@fnc");
								sprintf(tmp, "%d", function_counter++);
								strcat(funcName, tmp);
								/* printf("Undefined function create [%s]\n", funcName); */
								SymTable_put(oSymTable, funcName, 3, scope, yylineno, 1);

						  }
#line 1986 "syntax.c" /* yacc.c:1646  */
    break;

  case 78:
#line 338 "syntax.y" /* yacc.c:1646  */
    { messageHandler("funcdef", "function (idlist) funblock");}
#line 1992 "syntax.c" /* yacc.c:1646  */
    break;

  case 79:
#line 339 "syntax.y" /* yacc.c:1646  */
    {
								/* Kanoume tous antistoixous elegxous gia errors kai edw */
								/* printf("Checking if FUNCTION [%s] is allowed.\n", yylval.stringValue); */
								SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);

								if (scope_lookup(yylval.stringValue, scope) == 1)
									printf("Error in line %d: Redefinition of function symbol [%s].\n", yylineno, yylval.stringValue);
								else if (symbol && symbol->type == 4)
									printf("Error in line %d: User and Library Function name collision [%s].\n", yylineno, yylval.stringValue);
								else
									SymTable_put(oSymTable, yylval.stringValue, 3, scope, yylineno, 1);			


							}
#line 2011 "syntax.c" /* yacc.c:1646  */
    break;

  case 80:
#line 353 "syntax.y" /* yacc.c:1646  */
    { messageHandler("funcdef", "function identifier (idlist) funblock");}
#line 2017 "syntax.c" /* yacc.c:1646  */
    break;

  case 81:
#line 356 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "real_value");	}
#line 2023 "syntax.c" /* yacc.c:1646  */
    break;

  case 82:
#line 357 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "integer_value");	}
#line 2029 "syntax.c" /* yacc.c:1646  */
    break;

  case 83:
#line 358 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "string");	}
#line 2035 "syntax.c" /* yacc.c:1646  */
    break;

  case 84:
#line 359 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "nil");	}
#line 2041 "syntax.c" /* yacc.c:1646  */
    break;

  case 85:
#line 360 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "true");	}
#line 2047 "syntax.c" /* yacc.c:1646  */
    break;

  case 86:
#line 361 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "false");	}
#line 2053 "syntax.c" /* yacc.c:1646  */
    break;

  case 87:
#line 364 "syntax.y" /* yacc.c:1646  */
    {
						/* Theloume na anevasoume to scope apo twra. Giati tha anhkoun sto body ths synarthshs */
						/* To prwto mpainei panta ektos ama einai library */
						SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
						if (symbol && symbol->type == 4) {
							printf("Error in line %d: Formal Argument name collision with Library function [%s].\n", yylineno, yylval.stringValue);
						} else {
							SymTable_put(oSymTable, yylval.stringValue, 2, scope + 1, yylineno, 1);
						}
					}
#line 2068 "syntax.c" /* yacc.c:1646  */
    break;

  case 88:
#line 374 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idlist", "identifier idwithcommas");	}
#line 2074 "syntax.c" /* yacc.c:1646  */
    break;

  case 89:
#line 375 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idlist", "'e'");		}
#line 2080 "syntax.c" /* yacc.c:1646  */
    break;

  case 90:
#line 378 "syntax.y" /* yacc.c:1646  */
    {
									/* To idio kai edw alla tsekaroume kai gia idio name sto scope */
									SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
									if (symbol && symbol->type == 4) {
										printf("Error in line %d: Formal Argument name collision with Library function [%s].\n", yylineno, yylval.stringValue);
									} else if (scope_lookup(yylval.stringValue, scope + 1) == 1) {
										printf("Error in line %d: Formal Argument redefinition [%s].\n", yylineno, yylval.stringValue);
									} else {
										SymTable_put(oSymTable, yylval.stringValue, 2, scope + 1, yylineno, 1);
									}
								 }
#line 2096 "syntax.c" /* yacc.c:1646  */
    break;

  case 91:
#line 389 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idwithcommas", ", identifier idwithcommas");		}
#line 2102 "syntax.c" /* yacc.c:1646  */
    break;

  case 92:
#line 390 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idwithcommas", "'e'");		}
#line 2108 "syntax.c" /* yacc.c:1646  */
    break;

  case 93:
#line 393 "syntax.y" /* yacc.c:1646  */
    { messageHandler("ifstmt", "if (expr) stmt");	}
#line 2114 "syntax.c" /* yacc.c:1646  */
    break;

  case 94:
#line 394 "syntax.y" /* yacc.c:1646  */
    { messageHandler("ifstmt", "if (expr) stmt else stmt");	}
#line 2120 "syntax.c" /* yacc.c:1646  */
    break;

  case 95:
#line 397 "syntax.y" /* yacc.c:1646  */
    { messageHandler("whilestmt", "while (exrpr) stmt");	}
#line 2126 "syntax.c" /* yacc.c:1646  */
    break;

  case 96:
#line 401 "syntax.y" /* yacc.c:1646  */
    { messageHandler("forstmt", "for (elist expr; expr; elist) stmt");	}
#line 2132 "syntax.c" /* yacc.c:1646  */
    break;

  case 97:
#line 404 "syntax.y" /* yacc.c:1646  */
    { messageHandler("returnstmt", "return;");		}
#line 2138 "syntax.c" /* yacc.c:1646  */
    break;

  case 98:
#line 405 "syntax.y" /* yacc.c:1646  */
    { messageHandler("returnstmt", "return expr;");		}
#line 2144 "syntax.c" /* yacc.c:1646  */
    break;


#line 2148 "syntax.c" /* yacc.c:1646  */
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
#line 407 "syntax.y" /* yacc.c:1906  */


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

	printScopeLists();
	return 0;
}
