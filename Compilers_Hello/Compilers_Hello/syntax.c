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

	SymTable_T oSymTable;
	int scope;

	tesseract* quads = (tesseract*) 0;
	unsigned total = 0;
	unsigned int currQuad = 0;

	char currentTemp[8];
	int temp_counter = 0;

	void tempIncreaseAndUse(){
		memset(currentTemp, '\0', 8);
		strcpy(currentTemp, "_t");

		char tmp[3];
		memset(tmp, '\0', 3);
		sprintf(tmp, "%d", temp_counter++);

		strcat(currentTemp, tmp);

		if (scope == 0 && SymTable_get(oSymTable, currentTemp) == NULL)
			SymTable_put(oSymTable, currentTemp, 0, scope, yylineno, 1);
		else if (scope >= 1 && SymTable_get(oSymTable, currentTemp) == NULL)
			SymTable_put(oSymTable, currentTemp, 1, scope, yylineno, 1);
	}

	int syntax_error = 0;
	
	int yyerror (char* yaccProvideMessage);
	int yylex (void);
	void messageHandler(const char *state1, const char *state2);

	int function_flag = 0;
	char funcName[8];
	int function_counter = 0;



#line 114 "syntax.c" /* yacc.c:339  */

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
    MY_INTEGER = 258,
    MY_REAL = 259,
    MY_STRING = 260,
    MY_MULTILINE_COMMENTS = 261,
    MY_SIMPLE_COMMENTS = 262,
    MY_IF = 263,
    MY_ELSE = 264,
    MY_FOR = 265,
    MY_WHILE = 266,
    MY_DO = 267,
    MY_CONTINUE = 268,
    MY_BREAK = 269,
    MY_RETURN = 270,
    MY_AND = 271,
    MY_OR = 272,
    MY_NOT = 273,
    MY_LOCAL = 274,
    MY_GLOBAL = 275,
    MY_STATIC = 276,
    MY_NIL = 277,
    MY_TRUE = 278,
    MY_FALSE = 279,
    MY_FUNCTION = 280,
    MY_ID = 281,
    MY_BLANK = 282,
    MY_NL = 283,
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
#define MY_INTEGER 258
#define MY_REAL 259
#define MY_STRING 260
#define MY_MULTILINE_COMMENTS 261
#define MY_SIMPLE_COMMENTS 262
#define MY_IF 263
#define MY_ELSE 264
#define MY_FOR 265
#define MY_WHILE 266
#define MY_DO 267
#define MY_CONTINUE 268
#define MY_BREAK 269
#define MY_RETURN 270
#define MY_AND 271
#define MY_OR 272
#define MY_NOT 273
#define MY_LOCAL 274
#define MY_GLOBAL 275
#define MY_STATIC 276
#define MY_NIL 277
#define MY_TRUE 278
#define MY_FALSE 279
#define MY_FUNCTION 280
#define MY_ID 281
#define MY_BLANK 282
#define MY_NL 283
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
#line 56 "syntax.y" /* yacc.c:355  */

		char *stringValue;
		int integerValue;
		double realValue;
		expression *expressionValue;

#line 273 "syntax.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 288 "syntax.c" /* yacc.c:358  */

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
#define YYLAST   596

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

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
       0,   160,   160,   163,   163,   164,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   180,   181,   188,   194,
     200,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   219,   220,   221,   222,   230,   230,   237,   245,   245,
     252,   255,   255,   276,   277,   278,   279,   280,   283,   314,
     328,   334,   337,   338,   339,   340,   343,   344,   345,   348,
     349,   352,   355,   358,   359,   362,   363,   366,   367,   370,
     373,   374,   377,   380,   380,   387,   387,   395,   395,   408,
     408,   425,   431,   437,   438,   439,   440,   443,   443,   454,
     457,   457,   469,   472,   473,   476,   479,   483,   484
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MY_INTEGER", "MY_REAL", "MY_STRING",
  "MY_MULTILINE_COMMENTS", "MY_SIMPLE_COMMENTS", "MY_IF", "MY_ELSE",
  "MY_FOR", "MY_WHILE", "MY_DO", "MY_CONTINUE", "MY_BREAK", "MY_RETURN",
  "MY_AND", "MY_OR", "MY_NOT", "MY_LOCAL", "MY_GLOBAL", "MY_STATIC",
  "MY_NIL", "MY_TRUE", "MY_FALSE", "MY_FUNCTION", "MY_ID", "MY_BLANK",
  "MY_NL", "MY_ASSIGN", "MY_EQUAL", "MY_NEQUAL", "MY_PLUS", "MY_INC",
  "MY_MINUS", "MY_DEC", "MY_MUL", "MY_DIV", "MY_MOD", "MY_L", "MY_LE",
  "MY_G", "MY_GE", "MY_OPEN_ANG", "MY_OPEN_BRA", "MY_OPEN_PAR",
  "MY_CLOSE_ANG", "MY_CLOSE_BRA", "MY_CLOSE_PAR", "MY_DOT_UD",
  "MY_DOT_STREAM", "MY_DOT_SIMPLE", "MY_DOT_DOUBLE", "MY_COMMA",
  "MY_SEMICOLON", "MY_OTHER", "UNARY_MINUS", "$accept", "program", "stmts",
  "$@1", "stmt", "expr", "term", "$@2", "$@3", "assignexpr", "$@4",
  "primary", "lvalue", "member", "call", "callsuffix", "normcall",
  "methodcall", "elist", "commaexprs", "objectdef", "indexed",
  "commaindex", "indexedelem", "block", "$@5", "funblock", "$@6",
  "funcdef", "$@7", "$@8", "const", "idlist", "$@9", "idwithcommas",
  "$@10", "ifstmt", "whilestmt", "forstmt", "returnstmt", YY_NULL
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

#define YYPACT_NINF -135

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-135)))

#define YYTABLE_NINF -42

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-42)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     131,  -135,  -135,  -135,   -37,   -35,   -28,   -51,   -22,   164,
     263,    12,  -135,  -135,  -135,    23,  -135,    -8,   263,    -8,
    -135,   197,   230,    48,  -135,    77,  -135,  -135,    62,  -135,
    -135,  -135,   160,  -135,    -4,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,   263,   263,   263,  -135,  -135,  -135,   284,
    -135,  -135,  -135,    37,    58,    36,    -4,  -135,    36,   131,
     263,   338,    42,    43,    31,   392,    47,  -135,  -135,   131,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,  -135,   263,   263,    65,    79,    73,    74,
      85,  -135,  -135,  -135,   263,   263,    82,   419,    70,   446,
    -135,    83,   103,    84,    87,   365,   263,  -135,  -135,  -135,
      88,  -135,  -135,    93,  -135,   -11,   -11,    81,    81,     8,
       8,  -135,  -135,  -135,    18,    18,    18,    18,   473,    99,
    -135,   106,  -135,  -135,   263,   500,   100,  -135,   131,   263,
     131,   103,  -135,   104,    93,  -135,   263,   338,    31,   263,
    -135,  -135,   263,   554,  -135,  -135,   149,   311,  -135,   112,
     108,   119,   527,  -135,  -135,   115,   122,   131,   263,   119,
     145,  -135,  -135,  -135,  -135,  -135,  -135,  -135,   124,  -135,
    -135,   131,   131,   108,   127,  -135,  -135,  -135
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    82,    81,    83,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    85,    86,    77,    48,     0,     0,     0,
      73,    64,     0,     0,    15,     0,     2,     3,     0,    30,
      16,    40,    43,    51,    44,    45,    13,    14,    47,     7,
       8,     9,    10,     0,    64,     0,    12,    11,    97,     0,
      33,    49,    79,     0,     0,    34,     0,    32,    37,     5,
       0,    66,     0,     0,    71,     0,     0,    50,     1,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     0,    64,     0,     0,     0,     0,
       0,    57,    59,    60,     0,    64,     0,     0,     0,     0,
      98,     0,    89,     0,     0,     0,     0,    63,    67,    68,
       0,    69,    31,    46,     4,    28,    29,    26,    27,    17,
      18,    19,    20,    21,    24,    25,    22,    23,     0,     0,
      52,     0,    36,    39,     0,     0,     0,    54,     0,     0,
       0,    89,    87,     0,     0,    74,     0,    66,    71,    64,
      53,    61,    64,    42,    55,    56,    93,     0,    95,     0,
      92,     0,     0,    65,    70,     0,     0,     0,    64,     0,
       0,    88,    75,    78,    72,    58,    62,    94,     0,    80,
      90,     5,     0,    92,     0,    96,    91,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,   -54,  -135,  -134,    -9,  -135,  -135,  -135,  -135,
    -135,  -135,    -3,  -135,     5,  -135,  -135,  -135,   -42,    30,
    -135,  -135,    32,    68,  -135,  -135,    10,  -135,   -15,  -135,
    -135,  -135,    50,  -135,     1,  -135,  -135,  -135,  -135,  -135
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    69,    27,    28,    29,    88,    89,    30,
      90,    31,    32,    33,    34,    91,    92,    93,    62,   107,
      35,    63,   111,    64,    36,    59,   173,   181,    37,    53,
     101,    38,   143,   160,   171,   183,    39,    40,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    50,    98,    46,   156,   104,   158,    66,    43,    57,
      44,    11,    61,    65,    55,   114,    58,    45,    16,    72,
      73,    74,    56,    75,    56,    76,    77,    78,    79,    80,
      81,    82,    47,   177,    97,    61,    99,    54,    51,   103,
      94,    95,    23,   129,    76,    77,    78,    96,   185,    52,
      74,   105,    75,   136,    76,    77,    78,   -42,   -42,   -42,
     -42,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    67,   128,    61,    68,    70,    71,
      84,    85,   102,    15,   110,   135,    61,    86,    87,   108,
     109,   130,    72,    73,    74,   113,    75,   147,    76,    77,
      78,    79,    80,    81,    82,   131,   132,   165,   137,   133,
     166,   -42,   -42,    74,   134,    75,    83,    76,    77,    78,
      79,    80,    81,    82,   139,   153,   178,   184,   141,   142,
     157,    60,   144,   145,     1,     2,     3,   162,   149,     4,
      61,     5,     6,    61,     7,     8,     9,   151,   155,    10,
      11,   152,   161,    12,    13,    14,    15,    16,   167,    61,
     169,   170,   172,   175,    17,    18,    19,     1,     2,     3,
     176,   180,   182,   187,    20,    21,    22,   163,   148,   179,
     164,    23,    10,    11,   186,    24,    12,    13,    14,   -41,
      16,   159,     0,   -35,     0,   -38,     0,    17,    18,    19,
       1,     2,     3,     0,    84,    85,     0,     0,    21,    22,
       0,    86,    87,     0,    23,    10,    11,     0,    48,    12,
      13,    14,     0,    16,     0,     0,     0,     0,     0,     0,
      17,    18,    19,     1,     2,     3,     0,     0,     0,     0,
      60,    21,    22,     0,     0,     0,     0,    23,    10,    11,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,     0,     0,    17,    18,    19,     1,     2,     3,     0,
       0,     0,     0,     0,    21,    22,     0,     0,     0,     0,
      23,    10,    11,     0,     0,    12,    13,    14,     0,    16,
       0,     0,     0,     0,     0,     0,    17,    18,    19,     0,
      70,    71,     0,     0,     0,     0,     0,    21,    22,     0,
       0,     0,     0,    23,    72,    73,    74,     0,    75,     0,
      76,    77,    78,    79,    80,    81,    82,    70,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
       0,    72,    73,    74,     0,    75,     0,    76,    77,    78,
      79,    80,    81,    82,    70,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   168,     0,     0,    72,    73,
      74,     0,    75,     0,    76,    77,    78,    79,    80,    81,
      82,    70,    71,     0,     0,     0,     0,     0,     0,     0,
       0,   106,     0,     0,     0,    72,    73,    74,     0,    75,
       0,    76,    77,    78,    79,    80,    81,    82,    70,    71,
       0,     0,     0,     0,   146,     0,     0,     0,     0,     0,
       0,     0,    72,    73,    74,     0,    75,     0,    76,    77,
      78,    79,    80,    81,    82,    70,    71,     0,     0,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,    74,     0,    75,     0,    76,    77,    78,    79,    80,
      81,    82,    70,    71,     0,     0,     0,   138,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    73,    74,     0,
      75,     0,    76,    77,    78,    79,    80,    81,    82,    70,
      71,     0,     0,     0,   140,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    73,    74,     0,    75,     0,    76,
      77,    78,    79,    80,    81,    82,    70,    71,     0,     0,
     150,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    73,    74,     0,    75,     0,    76,    77,    78,    79,
      80,    81,    82,    70,    71,     0,     0,   154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    73,    74,
       0,    75,     0,    76,    77,    78,    79,    80,    81,    82,
      70,    71,     0,   174,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,    74,     0,    75,     0,
      76,    77,    78,    79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
       9,    10,    44,    54,   138,    59,   140,    22,    45,    18,
      45,    19,    21,    22,    17,    69,    19,    45,    26,    30,
      31,    32,    17,    34,    19,    36,    37,    38,    39,    40,
      41,    42,    54,   167,    43,    44,    45,    45,    26,    54,
      44,    45,    50,    85,    36,    37,    38,    51,   182,    26,
      32,    60,    34,    95,    36,    37,    38,    39,    40,    41,
      42,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    26,    84,    85,     0,    16,    17,
      44,    45,    45,    25,    53,    94,    95,    51,    52,    47,
      47,    26,    30,    31,    32,    48,    34,   106,    36,    37,
      38,    39,    40,    41,    42,    26,    33,   149,    26,    35,
     152,    30,    31,    32,    29,    34,    54,    36,    37,    38,
      39,    40,    41,    42,    54,   134,   168,   181,    45,    26,
     139,    43,    48,    46,     3,     4,     5,   146,    45,     8,
     149,    10,    11,   152,    13,    14,    15,    48,    48,    18,
      19,    45,    48,    22,    23,    24,    25,    26,     9,   168,
      48,    53,    43,    48,    33,    34,    35,     3,     4,     5,
      48,    26,    48,    46,    43,    44,    45,   147,   110,   169,
     148,    50,    18,    19,   183,    54,    22,    23,    24,    29,
      26,   141,    -1,    33,    -1,    35,    -1,    33,    34,    35,
       3,     4,     5,    -1,    44,    45,    -1,    -1,    44,    45,
      -1,    51,    52,    -1,    50,    18,    19,    -1,    54,    22,
      23,    24,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,     3,     4,     5,    -1,    -1,    -1,    -1,
      43,    44,    45,    -1,    -1,    -1,    -1,    50,    18,    19,
      -1,    -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      50,    18,    19,    -1,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,
      16,    17,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    50,    30,    31,    32,    -1,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    30,    31,    32,    -1,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    30,    31,
      32,    -1,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    30,    31,    32,    -1,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    16,    17,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    -1,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    16,    17,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    -1,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    16,    17,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    16,
      17,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    -1,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    16,    17,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    -1,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    16,    17,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      -1,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      16,    17,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    -1,    34,    -1,
      36,    37,    38,    39,    40,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     8,    10,    11,    13,    14,    15,
      18,    19,    22,    23,    24,    25,    26,    33,    34,    35,
      43,    44,    45,    50,    54,    58,    59,    61,    62,    63,
      66,    68,    69,    70,    71,    77,    81,    85,    88,    93,
      94,    95,    96,    45,    45,    45,    54,    54,    54,    62,
      62,    26,    26,    86,    45,    69,    71,    62,    69,    82,
      43,    62,    75,    78,    80,    62,    85,    26,     0,    60,
      16,    17,    30,    31,    32,    34,    36,    37,    38,    39,
      40,    41,    42,    54,    44,    45,    51,    52,    64,    65,
      67,    72,    73,    74,    44,    45,    51,    62,    75,    62,
      54,    87,    45,    85,    59,    62,    53,    76,    47,    47,
      53,    79,    48,    48,    59,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    75,
      26,    26,    33,    35,    29,    62,    75,    26,    48,    54,
      48,    45,    26,    89,    48,    46,    49,    62,    80,    45,
      47,    48,    45,    62,    47,    48,    61,    62,    61,    89,
      90,    48,    62,    76,    79,    75,    75,     9,    54,    48,
      53,    91,    43,    83,    46,    48,    48,    61,    75,    83,
      26,    84,    48,    92,    59,    61,    91,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    60,    59,    59,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    62,    62,
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
       0,     2,     1,     0,     3,     0,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
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
#line 160 "syntax.y" /* yacc.c:1646  */
    { messageHandler("program", "statements");	}
#line 1565 "syntax.c" /* yacc.c:1646  */
    break;

  case 3:
#line 163 "syntax.y" /* yacc.c:1646  */
    { temp_counter = 0; }
#line 1571 "syntax.c" /* yacc.c:1646  */
    break;

  case 4:
#line 163 "syntax.y" /* yacc.c:1646  */
    { messageHandler("statements", "stmt statements");	}
#line 1577 "syntax.c" /* yacc.c:1646  */
    break;

  case 5:
#line 164 "syntax.y" /* yacc.c:1646  */
    { messageHandler("statements", "'e'");	}
#line 1583 "syntax.c" /* yacc.c:1646  */
    break;

  case 6:
#line 168 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "expr;");	}
#line 1589 "syntax.c" /* yacc.c:1646  */
    break;

  case 7:
#line 169 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "ifstmt");	}
#line 1595 "syntax.c" /* yacc.c:1646  */
    break;

  case 8:
#line 170 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "whilestmt");	}
#line 1601 "syntax.c" /* yacc.c:1646  */
    break;

  case 9:
#line 171 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "forstmt");	}
#line 1607 "syntax.c" /* yacc.c:1646  */
    break;

  case 10:
#line 172 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "returnstmt");	}
#line 1613 "syntax.c" /* yacc.c:1646  */
    break;

  case 11:
#line 173 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "break;");	}
#line 1619 "syntax.c" /* yacc.c:1646  */
    break;

  case 12:
#line 174 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "continue;");	}
#line 1625 "syntax.c" /* yacc.c:1646  */
    break;

  case 13:
#line 175 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "block");	}
#line 1631 "syntax.c" /* yacc.c:1646  */
    break;

  case 14:
#line 176 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "funcdef");	}
#line 1637 "syntax.c" /* yacc.c:1646  */
    break;

  case 15:
#line 177 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", ";");	}
#line 1643 "syntax.c" /* yacc.c:1646  */
    break;

  case 16:
#line 180 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "assignexpr");		}
#line 1649 "syntax.c" /* yacc.c:1646  */
    break;

  case 17:
#line 181 "syntax.y" /* yacc.c:1646  */
    { 
								messageHandler("expr", "expr + expr");
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
								emit(1, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), (yyval.expressionValue));

							}
#line 1661 "syntax.c" /* yacc.c:1646  */
    break;

  case 18:
#line 188 "syntax.y" /* yacc.c:1646  */
    { 
									messageHandler("expr", "expr - expr");
									tempIncreaseAndUse();
									(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
									emit(2, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), (yyval.expressionValue));
								}
#line 1672 "syntax.c" /* yacc.c:1646  */
    break;

  case 19:
#line 194 "syntax.y" /* yacc.c:1646  */
    { 
								messageHandler("expr", "expr * expr"); 
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
								emit(3, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), (yyval.expressionValue));
							}
#line 1683 "syntax.c" /* yacc.c:1646  */
    break;

  case 20:
#line 200 "syntax.y" /* yacc.c:1646  */
    {
								messageHandler("expr", "expr * expr"); 
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
								emit(4, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), (yyval.expressionValue));
								messageHandler("expr", "expr / expr");
							}
#line 1695 "syntax.c" /* yacc.c:1646  */
    break;

  case 21:
#line 207 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr % expr"); }
#line 1701 "syntax.c" /* yacc.c:1646  */
    break;

  case 22:
#line 208 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr > expr"); }
#line 1707 "syntax.c" /* yacc.c:1646  */
    break;

  case 23:
#line 209 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr >= expr"); }
#line 1713 "syntax.c" /* yacc.c:1646  */
    break;

  case 24:
#line 210 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr < expr"); }
#line 1719 "syntax.c" /* yacc.c:1646  */
    break;

  case 25:
#line 211 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr <= expr"); }
#line 1725 "syntax.c" /* yacc.c:1646  */
    break;

  case 26:
#line 212 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr == expr"); }
#line 1731 "syntax.c" /* yacc.c:1646  */
    break;

  case 27:
#line 213 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr != expr"); }
#line 1737 "syntax.c" /* yacc.c:1646  */
    break;

  case 28:
#line 214 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr AND expr"); }
#line 1743 "syntax.c" /* yacc.c:1646  */
    break;

  case 29:
#line 215 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr OR expr"); }
#line 1749 "syntax.c" /* yacc.c:1646  */
    break;

  case 30:
#line 216 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "term");			}
#line 1755 "syntax.c" /* yacc.c:1646  */
    break;

  case 31:
#line 219 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "(expr)"); }
#line 1761 "syntax.c" /* yacc.c:1646  */
    break;

  case 32:
#line 220 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "-expr");	}
#line 1767 "syntax.c" /* yacc.c:1646  */
    break;

  case 33:
#line 221 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "not expr");	}
#line 1773 "syntax.c" /* yacc.c:1646  */
    break;

  case 34:
#line 222 "syntax.y" /* yacc.c:1646  */
    {
										SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
										if (symbol && symbol->type == 3)
											printf("Error in line %d: You cannot increase left a user defined function (%s).\n", yylineno, yylval.stringValue);
										else if (symbol && symbol->type == 4)
											printf("Error in line %d: You cannot increase left a library function (%s).\n", yylineno, yylval.stringValue);
										messageHandler("term", "++yvalue");	
									}
#line 1786 "syntax.c" /* yacc.c:1646  */
    break;

  case 35:
#line 230 "syntax.y" /* yacc.c:1646  */
    {
						SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
						if (symbol && symbol->type == 3)
							printf("Error in line %d: You cannot increase right a user defined function (%s).\n", yylineno, yylval.stringValue);
						else if (symbol && symbol->type == 4)
							printf("Error in line %d: You cannot increase right a library function (%s).\n", yylineno, yylval.stringValue);
				 }
#line 1798 "syntax.c" /* yacc.c:1646  */
    break;

  case 36:
#line 236 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "lvalue++");	}
#line 1804 "syntax.c" /* yacc.c:1646  */
    break;

  case 37:
#line 237 "syntax.y" /* yacc.c:1646  */
    { 
										SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
										if (symbol && symbol->type == 3)
											printf("Error in line %d: You cannot decrease left a user defined function (%s).\n", yylineno, yylval.stringValue);
										else if (symbol && symbol->type == 4)
											printf("Error in line %d: You cannot decrease left a library function (%s).\n", yylineno, yylval.stringValue);
										messageHandler("term", "--lvalue");	
									}
#line 1817 "syntax.c" /* yacc.c:1646  */
    break;

  case 38:
#line 245 "syntax.y" /* yacc.c:1646  */
    {
						SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
						if (symbol && symbol->type == 3)
							printf("Error in line %d: You cannot decrease right a user defined function (%s).\n", yylineno, yylval.stringValue);
						else if (symbol && symbol->type == 4)
							printf("Error in line %d: You cannot decrease right a library function (%s).\n", yylineno, yylval.stringValue);
				 }
#line 1829 "syntax.c" /* yacc.c:1646  */
    break;

  case 39:
#line 251 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "lvalue++");	}
#line 1835 "syntax.c" /* yacc.c:1646  */
    break;

  case 40:
#line 252 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "primary");	}
#line 1841 "syntax.c" /* yacc.c:1646  */
    break;

  case 41:
#line 255 "syntax.y" /* yacc.c:1646  */
    {
						/* printf("Checking if [%s] is a library function or function\n", yylval.stringValue); */
						SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
						if (symbol && symbol->type == 3) { 
							syntax_error = 1;
							printf("Error in line %d: You cannot use a user defined function in assignment expresion.\n", yylineno);
						}
						else if (symbol && symbol->type == 4) {
							syntax_error = 1;
							printf("Error in line %d: You cannot use a library function in assignment expresion.\n", yylineno);
						}
					 }
#line 1858 "syntax.c" /* yacc.c:1646  */
    break;

  case 42:
#line 267 "syntax.y" /* yacc.c:1646  */
    { 
						messageHandler("assignexpr", "lvalue = expr");
						(yyval.expressionValue) = NewExpr(6, SymTable_get(oSymTable, currentTemp), 0, NULL, 'F');
						if (syntax_error == 0) {
							emit(0, (yyvsp[0].expressionValue), NULL, (yyvsp[-3].expressionValue));
						}
					 }
#line 1870 "syntax.c" /* yacc.c:1646  */
    break;

  case 43:
#line 276 "syntax.y" /* yacc.c:1646  */
    {  messageHandler("primary", "lvalue");	}
#line 1876 "syntax.c" /* yacc.c:1646  */
    break;

  case 44:
#line 277 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "call");		}
#line 1882 "syntax.c" /* yacc.c:1646  */
    break;

  case 45:
#line 278 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "objectdef");	}
#line 1888 "syntax.c" /* yacc.c:1646  */
    break;

  case 46:
#line 279 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "(funcdef)");	}
#line 1894 "syntax.c" /* yacc.c:1646  */
    break;

  case 47:
#line 280 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "const");		}
#line 1900 "syntax.c" /* yacc.c:1646  */
    break;

  case 48:
#line 283 "syntax.y" /* yacc.c:1646  */
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
							int check = inside_out_lookup(yylval.stringValue, scope);
							
							/* ERROR: giati yparxei se prohgoymena LOCAL SCOPES */
							if (check > 0 && check < scope && function_flag && (ScopeListGetSymbolAt(yylval.stringValue, check)->type < 3)) {
								syntax_error = 1;
								printf("Error: Can't be accessed! Current scope: %d. Same active local variable symbol %s found in scope %d.\n",scope, yylval.stringValue, check);
							}

							if (check == -1)	/* Dhladh ama den yparxei pouthena */
								SymTable_put(oSymTable, yylval.stringValue, 1, scope, yylineno, 1);
						}

						if (syntax_error == 0){
							(yyval.expressionValue) = NewExpr(0, SymTable_get(oSymTable, yylval.stringValue), 0, NULL, 'F');
						}

						messageHandler("lvalue", "identifier"); 
					}
#line 1936 "syntax.c" /* yacc.c:1646  */
    break;

  case 49:
#line 314 "syntax.y" /* yacc.c:1646  */
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
#line 1955 "syntax.c" /* yacc.c:1646  */
    break;

  case 50:
#line 328 "syntax.y" /* yacc.c:1646  */
    {
									if (scope_lookup(yylval.stringValue, 0) == 0) {
										printf("Error in line %d: Not found global symbol with name [%s].\n", yylineno, yylval.stringValue);
									}
									messageHandler("lvalue", ":: identifier");
								}
#line 1966 "syntax.c" /* yacc.c:1646  */
    break;

  case 51:
#line 334 "syntax.y" /* yacc.c:1646  */
    { messageHandler("lvalue", "member");		}
#line 1972 "syntax.c" /* yacc.c:1646  */
    break;

  case 52:
#line 337 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "lvalue.identifier");}
#line 1978 "syntax.c" /* yacc.c:1646  */
    break;

  case 53:
#line 338 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "lvalue[expr]");	}
#line 1984 "syntax.c" /* yacc.c:1646  */
    break;

  case 54:
#line 339 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "call.identifier");	}
#line 1990 "syntax.c" /* yacc.c:1646  */
    break;

  case 55:
#line 340 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "[expr]");		}
#line 1996 "syntax.c" /* yacc.c:1646  */
    break;

  case 56:
#line 343 "syntax.y" /* yacc.c:1646  */
    { messageHandler("call", "call(elist)");	}
#line 2002 "syntax.c" /* yacc.c:1646  */
    break;

  case 57:
#line 344 "syntax.y" /* yacc.c:1646  */
    { messageHandler("call", "lvalue callsuffix");	}
#line 2008 "syntax.c" /* yacc.c:1646  */
    break;

  case 58:
#line 345 "syntax.y" /* yacc.c:1646  */
    { messageHandler("call", "(funcdef)(elist)");	}
#line 2014 "syntax.c" /* yacc.c:1646  */
    break;

  case 59:
#line 348 "syntax.y" /* yacc.c:1646  */
    { messageHandler("callsuffix", "normcall");	}
#line 2020 "syntax.c" /* yacc.c:1646  */
    break;

  case 60:
#line 349 "syntax.y" /* yacc.c:1646  */
    { messageHandler("callsuffix", "methodcall");	}
#line 2026 "syntax.c" /* yacc.c:1646  */
    break;

  case 61:
#line 352 "syntax.y" /* yacc.c:1646  */
    { messageHandler("normcall", "(elist)");	}
#line 2032 "syntax.c" /* yacc.c:1646  */
    break;

  case 62:
#line 355 "syntax.y" /* yacc.c:1646  */
    { messageHandler("methodcall", "..identifier(elist)");	}
#line 2038 "syntax.c" /* yacc.c:1646  */
    break;

  case 63:
#line 358 "syntax.y" /* yacc.c:1646  */
    { messageHandler("elist", "expr comma-expressions");		}
#line 2044 "syntax.c" /* yacc.c:1646  */
    break;

  case 64:
#line 359 "syntax.y" /* yacc.c:1646  */
    { messageHandler("elist", "'e'");		}
#line 2050 "syntax.c" /* yacc.c:1646  */
    break;

  case 65:
#line 362 "syntax.y" /* yacc.c:1646  */
    { messageHandler("comma-expressions", ", expr comma-expressions");	}
#line 2056 "syntax.c" /* yacc.c:1646  */
    break;

  case 66:
#line 363 "syntax.y" /* yacc.c:1646  */
    { messageHandler("comma-expressions", "'e'");	}
#line 2062 "syntax.c" /* yacc.c:1646  */
    break;

  case 67:
#line 366 "syntax.y" /* yacc.c:1646  */
    { messageHandler("objectdef", "[elist]");	}
#line 2068 "syntax.c" /* yacc.c:1646  */
    break;

  case 68:
#line 367 "syntax.y" /* yacc.c:1646  */
    { messageHandler("objectdef", "[indexed]");	}
#line 2074 "syntax.c" /* yacc.c:1646  */
    break;

  case 69:
#line 370 "syntax.y" /* yacc.c:1646  */
    { messageHandler("indexed", "indexedelem commaindex");		}
#line 2080 "syntax.c" /* yacc.c:1646  */
    break;

  case 70:
#line 373 "syntax.y" /* yacc.c:1646  */
    { messageHandler("commaindex", ", indexedelem commaindex");		}
#line 2086 "syntax.c" /* yacc.c:1646  */
    break;

  case 71:
#line 374 "syntax.y" /* yacc.c:1646  */
    { messageHandler("commaindex", "'e'");		}
#line 2092 "syntax.c" /* yacc.c:1646  */
    break;

  case 72:
#line 377 "syntax.y" /* yacc.c:1646  */
    { messageHandler("indexedelem", "{expr:expr}");		}
#line 2098 "syntax.c" /* yacc.c:1646  */
    break;

  case 73:
#line 380 "syntax.y" /* yacc.c:1646  */
    {++scope; if (function_flag == 1) function_flag = 0;}
#line 2104 "syntax.c" /* yacc.c:1646  */
    break;

  case 74:
#line 381 "syntax.y" /* yacc.c:1646  */
    {
				hide(scope--); 
				messageHandler("block", "{stmts}"); 
			}
#line 2113 "syntax.c" /* yacc.c:1646  */
    break;

  case 75:
#line 387 "syntax.y" /* yacc.c:1646  */
    {++scope; function_flag = 1;}
#line 2119 "syntax.c" /* yacc.c:1646  */
    break;

  case 76:
#line 388 "syntax.y" /* yacc.c:1646  */
    {
				hide(scope--); 
				function_flag = 0;
				messageHandler("funblock", "{stmts}"); 
			}
#line 2129 "syntax.c" /* yacc.c:1646  */
    break;

  case 77:
#line 395 "syntax.y" /* yacc.c:1646  */
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
#line 2146 "syntax.c" /* yacc.c:1646  */
    break;

  case 78:
#line 407 "syntax.y" /* yacc.c:1646  */
    { messageHandler("funcdef", "function (idlist) funblock");}
#line 2152 "syntax.c" /* yacc.c:1646  */
    break;

  case 79:
#line 408 "syntax.y" /* yacc.c:1646  */
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
#line 2171 "syntax.c" /* yacc.c:1646  */
    break;

  case 80:
#line 422 "syntax.y" /* yacc.c:1646  */
    { messageHandler("funcdef", "function identifier (idlist) funblock");}
#line 2177 "syntax.c" /* yacc.c:1646  */
    break;

  case 81:
#line 425 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("const", "real_value");
							if ((yyvsp[0].realValue) == 0)
								(yyval.expressionValue) = NewExpr(8, NULL, (yyvsp[0].realValue), NULL, 'F');
							else
								(yyval.expressionValue) = NewExpr(8, NULL, (yyvsp[0].realValue), NULL, 'T');
						}
#line 2188 "syntax.c" /* yacc.c:1646  */
    break;

  case 82:
#line 431 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("const", "integer_value");
							if ((yyvsp[0].integerValue) == 0)
								(yyval.expressionValue) = NewExpr(8, NULL, (yyvsp[0].integerValue), NULL, 'F');
							else
								(yyval.expressionValue) = NewExpr(8, NULL, (yyvsp[0].integerValue), NULL, 'T');
						}
#line 2199 "syntax.c" /* yacc.c:1646  */
    break;

  case 83:
#line 437 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "string");	}
#line 2205 "syntax.c" /* yacc.c:1646  */
    break;

  case 84:
#line 438 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "nil");	}
#line 2211 "syntax.c" /* yacc.c:1646  */
    break;

  case 85:
#line 439 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "true");	}
#line 2217 "syntax.c" /* yacc.c:1646  */
    break;

  case 86:
#line 440 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "false");	}
#line 2223 "syntax.c" /* yacc.c:1646  */
    break;

  case 87:
#line 443 "syntax.y" /* yacc.c:1646  */
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
#line 2238 "syntax.c" /* yacc.c:1646  */
    break;

  case 88:
#line 453 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idlist", "identifier idwithcommas");	}
#line 2244 "syntax.c" /* yacc.c:1646  */
    break;

  case 89:
#line 454 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idlist", "'e'");		}
#line 2250 "syntax.c" /* yacc.c:1646  */
    break;

  case 90:
#line 457 "syntax.y" /* yacc.c:1646  */
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
#line 2266 "syntax.c" /* yacc.c:1646  */
    break;

  case 91:
#line 468 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idwithcommas", ", identifier idwithcommas");		}
#line 2272 "syntax.c" /* yacc.c:1646  */
    break;

  case 92:
#line 469 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idwithcommas", "'e'");		}
#line 2278 "syntax.c" /* yacc.c:1646  */
    break;

  case 93:
#line 472 "syntax.y" /* yacc.c:1646  */
    { messageHandler("ifstmt", "if (expr) stmt");	}
#line 2284 "syntax.c" /* yacc.c:1646  */
    break;

  case 94:
#line 473 "syntax.y" /* yacc.c:1646  */
    { messageHandler("ifstmt", "if (expr) stmt else stmt");	}
#line 2290 "syntax.c" /* yacc.c:1646  */
    break;

  case 95:
#line 476 "syntax.y" /* yacc.c:1646  */
    { messageHandler("whilestmt", "while (exrpr) stmt");	}
#line 2296 "syntax.c" /* yacc.c:1646  */
    break;

  case 96:
#line 480 "syntax.y" /* yacc.c:1646  */
    { messageHandler("forstmt", "for (elist expr; expr; elist) stmt");	}
#line 2302 "syntax.c" /* yacc.c:1646  */
    break;

  case 97:
#line 483 "syntax.y" /* yacc.c:1646  */
    { messageHandler("returnstmt", "return;");		}
#line 2308 "syntax.c" /* yacc.c:1646  */
    break;

  case 98:
#line 484 "syntax.y" /* yacc.c:1646  */
    { messageHandler("returnstmt", "return expr;");		}
#line 2314 "syntax.c" /* yacc.c:1646  */
    break;


#line 2318 "syntax.c" /* yacc.c:1646  */
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
#line 486 "syntax.y" /* yacc.c:1906  */


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
