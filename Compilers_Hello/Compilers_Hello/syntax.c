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

	tesseract quads[1024];
	unsigned total = 0;
	unsigned int currQuad = 0;

	char currentTemp[8];
	int temp_counter = 0;

	/* xeirourgio gia ta tables pou aforoun to initialize */
	expression *table_stack[8]; /* h stoiba xrisimopoieitai kata th dhmiourgeia tou pinaka */
	table_stack_index = -1;     /* autos einai o index gia tin stoiba */

	table_stack_trace_index = -1;     /* autos einai o index gia tin stoiba */

	/*xeirourgio gia tis synartiseis*/ 
	int func_locals_sum[72];
	expression *function_expression[72];
	int all_func_counter = 0;

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

	void printQuads() {
		for (unsigned i = 1; i < 1024; i++) {
			if (quads[i].result != NULL)
				printf("%u: %s %s %s %s.\n",quads[i].label, getIOpcodeName(quads[i].op), getExpressionValue(quads[i].arg1),
					getExpressionValue(quads[i].arg2), getExpressionValue(quads[i].result));
		}
	}


	int syntax_error = 0;
	
	int yyerror (char* yaccProvideMessage);
	int yylex (void);
	void messageHandler(const char *state1, const char *state2);

	int function_flag = 0;
	char funcName[8];
	int function_counter = 0;



#line 134 "syntax.c" /* yacc.c:339  */

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
#line 76 "syntax.y" /* yacc.c:355  */

		char *stringValue;
		int integerValue;
		double realValue;
		expression *expressionValue;

#line 293 "syntax.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 308 "syntax.c" /* yacc.c:358  */

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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   599

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

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
       0,   190,   190,   193,   193,   194,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   209,   212,   213,   220,   226,
     232,   239,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   257,   258,   266,   274,   290,   290,   305,   320,   320,
     334,   346,   346,   417,   418,   425,   426,   427,   430,   460,
     474,   480,   483,   494,   505,   506,   509,   524,   532,   549,
     557,   560,   565,   568,   574,   577,   582,   585,   585,   592,
     592,   601,   604,   605,   608,   618,   618,   625,   625,   633,
     633,   653,   653,   677,   683,   689,   696,   697,   698,   701,
     701,   712,   715,   715,   727,   730,   731,   734,   737,   741,
     742
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
  "methodcall", "elist", "commaexprs", "objectdef", "$@5", "$@6",
  "indexed", "commaindex", "indexedelem", "block", "$@7", "funblock",
  "$@8", "funcdef", "$@9", "$@10", "const", "idlist", "$@11",
  "idwithcommas", "$@12", "ifstmt", "whilestmt", "forstmt", "returnstmt", YY_NULL
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

#define YYPACT_NINF -114

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-114)))

#define YYTABLE_NINF -70

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-70)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     147,  -114,  -114,  -114,   -38,   -37,   -28,   -26,   -25,    84,
     213,     5,  -114,  -114,  -114,     7,  -114,    -5,   213,    -5,
    -114,    -4,   180,    17,  -114,    44,  -114,  -114,   234,  -114,
    -114,  -114,    -3,  -114,   -29,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,   213,   213,   213,  -114,  -114,  -114,   261,
    -114,  -114,  -114,     1,    22,   -33,   -29,  -114,   -33,   147,
     213,     9,   369,     2,  -114,  -114,   147,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
    -114,   213,   213,    31,    48,    42,    41,    49,  -114,  -114,
    -114,   213,   213,    51,   396,   315,    25,   423,  -114,    35,
      55,    36,    39,    43,   213,    45,    33,  -114,    46,  -114,
     544,   544,   557,   557,    18,    18,  -114,  -114,  -114,   356,
     356,   356,   356,   450,    50,  -114,    52,  -114,  -114,   213,
     477,    53,  -114,   147,   213,  -114,   213,   147,    55,  -114,
      56,    46,  -114,  -114,   342,  -114,     9,  -114,   213,  -114,
    -114,   213,   531,  -114,  -114,    85,   315,   288,  -114,    57,
      47,    66,   213,    33,    63,    64,   147,  -114,   213,    66,
      73,  -114,  -114,  -114,   504,  -114,  -114,  -114,  -114,    67,
    -114,  -114,   147,  -114,   147,    47,    68,  -114,  -114,  -114
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    84,    83,    85,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    79,    48,     0,     0,     0,
      75,    67,     0,     0,    15,     0,     2,     3,     0,    30,
      16,    40,    43,    51,    44,    45,    13,    14,    47,     7,
       8,     9,    10,     0,    64,     0,    12,    11,    99,     0,
      33,    49,    81,     0,     0,    34,     0,    32,    37,     5,
      64,     0,     0,     0,    50,     1,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,    64,     0,     0,     0,     0,     0,    57,    59,
      60,     0,    64,     0,     0,    66,     0,     0,   100,     0,
      91,     0,     0,     0,     0,     0,    73,    31,    46,     4,
      28,    29,    26,    27,    17,    18,    19,    20,    21,    24,
      25,    22,    23,     0,     0,    52,     0,    36,    39,     0,
       0,     0,    54,     0,     0,    63,     0,     0,    91,    89,
       0,     0,    76,    68,     0,    70,     0,    71,    64,    53,
      61,    64,    42,    55,    56,    95,    66,     0,    97,     0,
      94,     0,     0,    73,     0,     0,     0,    65,    64,     0,
       0,    90,    77,    80,     0,    72,    58,    62,    96,     0,
      82,    92,     5,    74,     0,    94,     0,    98,    93,    78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -114,  -114,   -56,  -114,  -113,    -9,  -114,  -114,  -114,  -114,
    -114,  -114,   -15,  -114,     6,  -114,  -114,  -114,   -55,   -40,
    -114,  -114,  -114,  -114,   -42,   -24,  -114,  -114,   -46,  -114,
     -16,  -114,  -114,  -114,   -14,  -114,   -54,  -114,  -114,  -114,
    -114,  -114
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    66,    27,    28,    29,    85,    86,    30,
      87,    31,    32,    33,    34,    88,    89,    90,    96,   135,
      35,    60,    61,   105,   147,   106,    36,    59,   173,   182,
      37,    53,    99,    38,   140,   160,   171,   185,    39,    40,
      41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    50,    55,   102,    58,   103,    63,    43,    44,    57,
     109,    81,    82,    62,    11,    91,    92,    45,    83,    84,
     155,    16,    93,    56,   158,    56,   -41,   124,    46,    47,
     -35,    51,   -38,    52,    94,    95,    97,   131,   101,   -69,
      54,    81,    82,    64,    65,    23,   100,    15,    83,    84,
     108,    95,   104,   178,    73,    74,    75,   125,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   187,   123,    95,   126,   127,   128,   132,   129,   136,
     138,   139,   130,    95,   141,   142,   146,     1,     2,     3,
     143,   148,   145,   164,   166,   144,   165,   151,   150,   181,
     170,   154,    10,    11,   161,   169,    12,    13,    14,   172,
      16,   176,   177,   179,   189,   184,   167,    17,    18,    19,
     152,   175,   163,   180,   159,   156,   186,   157,    21,    22,
       0,   188,     0,     0,    23,     0,     0,     0,    48,    95,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,   174,     0,     4,     0,     5,     6,    95,
       7,     8,     9,     0,     0,    10,    11,     0,     0,    12,
      13,    14,    15,    16,     0,     0,     0,     0,     0,     0,
      17,    18,    19,     1,     2,     3,     0,     0,     0,     0,
      20,    21,    22,     0,     0,     0,     0,    23,    10,    11,
       0,    24,    12,    13,    14,    15,    16,     0,     0,     0,
       0,     0,     0,    17,    18,    19,     1,     2,     3,     0,
       0,     0,     0,     0,    21,    22,     0,     0,     0,     0,
      23,    10,    11,     0,     0,    12,    13,    14,     0,    16,
       0,     0,     0,     0,     0,     0,    17,    18,    19,     0,
      67,    68,     0,     0,     0,     0,     0,    21,    22,     0,
       0,     0,     0,    23,    69,    70,    71,     0,    72,     0,
      73,    74,    75,    76,    77,    78,    79,    67,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,    69,    70,    71,     0,    72,     0,    73,    74,    75,
      76,    77,    78,    79,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,     0,     0,    69,    70,
      71,     0,    72,     0,    73,    74,    75,    76,    77,    78,
      79,    67,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   168,     0,     0,    69,    70,    71,     0,    72,
       0,    73,    74,    75,    76,    77,    78,    79,    67,    68,
       0,     0,     0,     0,     0,     0,     0,     0,   134,     0,
       0,     0,    69,    70,    71,     0,    72,     0,    73,    74,
      75,    76,    77,    78,    79,    67,    68,     0,    71,     0,
      72,   162,    73,    74,    75,   -70,   -70,   -70,   -70,    69,
      70,    71,     0,    72,     0,    73,    74,    75,    76,    77,
      78,    79,    67,    68,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    70,    71,     0,
      72,     0,    73,    74,    75,    76,    77,    78,    79,    67,
      68,     0,     0,     0,   133,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,    71,     0,    72,     0,    73,
      74,    75,    76,    77,    78,    79,    67,    68,     0,     0,
       0,   137,     0,     0,     0,     0,     0,     0,     0,     0,
      69,    70,    71,     0,    72,     0,    73,    74,    75,    76,
      77,    78,    79,    67,    68,     0,     0,   149,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,    71,
       0,    72,     0,    73,    74,    75,    76,    77,    78,    79,
      67,    68,     0,     0,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    70,    71,     0,    72,     0,
      73,    74,    75,    76,    77,    78,    79,    67,    68,     0,
     183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,     0,    72,     0,    73,    74,    75,
      76,    77,    78,    79,    69,    70,    71,     0,    72,     0,
      73,    74,    75,    76,    77,    78,    79,   -70,   -70,    71,
       0,    72,     0,    73,    74,    75,    76,    77,    78,    79
};

static const yytype_int16 yycheck[] =
{
       9,    10,    17,    59,    19,    60,    22,    45,    45,    18,
      66,    44,    45,    22,    19,    44,    45,    45,    51,    52,
     133,    26,    51,    17,   137,    19,    29,    82,    54,    54,
      33,    26,    35,    26,    43,    44,    45,    92,    54,    43,
      45,    44,    45,    26,     0,    50,    45,    25,    51,    52,
      48,    60,    43,   166,    36,    37,    38,    26,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,   184,    81,    82,    26,    33,    35,    26,    29,    54,
      45,    26,    91,    92,    48,    46,    53,     3,     4,     5,
      47,    45,    47,   148,     9,   104,   151,    45,    48,    26,
      53,    48,    18,    19,    48,    48,    22,    23,    24,    43,
      26,    48,    48,   168,    46,    48,   156,    33,    34,    35,
     129,   163,   146,   169,   138,   134,   182,   136,    44,    45,
      -1,   185,    -1,    -1,    50,    -1,    -1,    -1,    54,   148,
      -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,   162,    -1,     8,    -1,    10,    11,   168,
      13,    14,    15,    -1,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,     3,     4,     5,    -1,    -1,    -1,    -1,
      43,    44,    45,    -1,    -1,    -1,    -1,    50,    18,    19,
      -1,    54,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
      -1,    -1,    54,    -1,    -1,    30,    31,    32,    -1,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    30,    31,    32,    -1,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    16,    17,    -1,    32,    -1,
      34,    49,    36,    37,    38,    39,    40,    41,    42,    30,
      31,    32,    -1,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    16,    17,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    16,
      17,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    -1,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    16,    17,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    -1,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    16,    17,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      -1,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      16,    17,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    -1,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    16,    17,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    -1,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    30,    31,    32,    -1,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    30,    31,    32,
      -1,    34,    -1,    36,    37,    38,    39,    40,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     8,    10,    11,    13,    14,    15,
      18,    19,    22,    23,    24,    25,    26,    33,    34,    35,
      43,    44,    45,    50,    54,    58,    59,    61,    62,    63,
      66,    68,    69,    70,    71,    77,    83,    87,    90,    95,
      96,    97,    98,    45,    45,    45,    54,    54,    54,    62,
      62,    26,    26,    88,    45,    69,    71,    62,    69,    84,
      78,    79,    62,    87,    26,     0,    60,    16,    17,    30,
      31,    32,    34,    36,    37,    38,    39,    40,    41,    42,
      54,    44,    45,    51,    52,    64,    65,    67,    72,    73,
      74,    44,    45,    51,    62,    62,    75,    62,    54,    89,
      45,    87,    59,    75,    43,    80,    82,    48,    48,    59,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    75,    26,    26,    33,    35,    29,
      62,    75,    26,    48,    53,    76,    54,    48,    45,    26,
      91,    48,    46,    47,    62,    47,    53,    81,    45,    47,
      48,    45,    62,    47,    48,    61,    62,    62,    61,    91,
      92,    48,    49,    82,    75,    75,     9,    76,    54,    48,
      53,    93,    43,    85,    62,    81,    48,    48,    61,    75,
      85,    26,    86,    46,    48,    94,    59,    61,    93,    46
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
      72,    73,    74,    75,    75,    76,    76,    78,    77,    79,
      77,    80,    81,    81,    82,    84,    83,    86,    85,    88,
      87,    89,    87,    90,    90,    90,    90,    90,    90,    92,
      91,    91,    94,    93,    93,    95,    95,    96,    97,    98,
      98
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
       1,     3,     5,     2,     0,     3,     0,     0,     4,     0,
       4,     2,     3,     0,     5,     0,     4,     0,     4,     0,
       6,     0,     7,     1,     1,     1,     1,     1,     1,     0,
       3,     0,     0,     4,     0,     5,     7,     5,     9,     2,
       3
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
#line 190 "syntax.y" /* yacc.c:1646  */
    { messageHandler("program", "statements");	}
#line 1590 "syntax.c" /* yacc.c:1646  */
    break;

  case 3:
#line 193 "syntax.y" /* yacc.c:1646  */
    { temp_counter = 0; }
#line 1596 "syntax.c" /* yacc.c:1646  */
    break;

  case 4:
#line 193 "syntax.y" /* yacc.c:1646  */
    { messageHandler("statements", "stmt statements");	}
#line 1602 "syntax.c" /* yacc.c:1646  */
    break;

  case 5:
#line 194 "syntax.y" /* yacc.c:1646  */
    { messageHandler("statements", "'e'");	}
#line 1608 "syntax.c" /* yacc.c:1646  */
    break;

  case 6:
#line 198 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "expr;");	}
#line 1614 "syntax.c" /* yacc.c:1646  */
    break;

  case 7:
#line 199 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "ifstmt");	}
#line 1620 "syntax.c" /* yacc.c:1646  */
    break;

  case 8:
#line 200 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "whilestmt");	}
#line 1626 "syntax.c" /* yacc.c:1646  */
    break;

  case 9:
#line 201 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "forstmt");	}
#line 1632 "syntax.c" /* yacc.c:1646  */
    break;

  case 10:
#line 202 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "returnstmt");	}
#line 1638 "syntax.c" /* yacc.c:1646  */
    break;

  case 11:
#line 203 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "break;");	}
#line 1644 "syntax.c" /* yacc.c:1646  */
    break;

  case 12:
#line 204 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "continue;");	}
#line 1650 "syntax.c" /* yacc.c:1646  */
    break;

  case 13:
#line 205 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "block");	}
#line 1656 "syntax.c" /* yacc.c:1646  */
    break;

  case 14:
#line 206 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "funcdef");
							  quads[total] = emit(21, NULL, NULL, (yyvsp[0].expressionValue), yylineno, total++);
							}
#line 1664 "syntax.c" /* yacc.c:1646  */
    break;

  case 15:
#line 209 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", ";");	}
#line 1670 "syntax.c" /* yacc.c:1646  */
    break;

  case 16:
#line 212 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "assignexpr");		}
#line 1676 "syntax.c" /* yacc.c:1646  */
    break;

  case 17:
#line 213 "syntax.y" /* yacc.c:1646  */
    { 
								messageHandler("expr", "expr + expr");
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
								quads[total] = emit(1, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);

							}
#line 1688 "syntax.c" /* yacc.c:1646  */
    break;

  case 18:
#line 220 "syntax.y" /* yacc.c:1646  */
    { 
									messageHandler("expr", "expr - expr");
									tempIncreaseAndUse();
									(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
									quads[total] = emit(2, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
								}
#line 1699 "syntax.c" /* yacc.c:1646  */
    break;

  case 19:
#line 226 "syntax.y" /* yacc.c:1646  */
    { 
								messageHandler("expr", "expr * expr"); 
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
								quads[total] = emit(3, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
							}
#line 1710 "syntax.c" /* yacc.c:1646  */
    break;

  case 20:
#line 232 "syntax.y" /* yacc.c:1646  */
    {
								messageHandler("expr", "expr * expr"); 
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
								quads[total] = emit(4, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
								messageHandler("expr", "expr / expr");
							}
#line 1722 "syntax.c" /* yacc.c:1646  */
    break;

  case 21:
#line 239 "syntax.y" /* yacc.c:1646  */
    { 
								messageHandler("expr", "expr % expr");
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
								quads[total] = emit(5, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
								messageHandler("expr", "expr / expr");
							}
#line 1734 "syntax.c" /* yacc.c:1646  */
    break;

  case 22:
#line 246 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr > expr"); }
#line 1740 "syntax.c" /* yacc.c:1646  */
    break;

  case 23:
#line 247 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr >= expr"); }
#line 1746 "syntax.c" /* yacc.c:1646  */
    break;

  case 24:
#line 248 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr < expr"); }
#line 1752 "syntax.c" /* yacc.c:1646  */
    break;

  case 25:
#line 249 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr <= expr"); }
#line 1758 "syntax.c" /* yacc.c:1646  */
    break;

  case 26:
#line 250 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr == expr"); }
#line 1764 "syntax.c" /* yacc.c:1646  */
    break;

  case 27:
#line 251 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr != expr"); }
#line 1770 "syntax.c" /* yacc.c:1646  */
    break;

  case 28:
#line 252 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr AND expr"); }
#line 1776 "syntax.c" /* yacc.c:1646  */
    break;

  case 29:
#line 253 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "expr OR expr"); }
#line 1782 "syntax.c" /* yacc.c:1646  */
    break;

  case 30:
#line 254 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "term");	}
#line 1788 "syntax.c" /* yacc.c:1646  */
    break;

  case 31:
#line 257 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "(expr)");  (yyval.expressionValue) = (yyvsp[-1].expressionValue);}
#line 1794 "syntax.c" /* yacc.c:1646  */
    break;

  case 32:
#line 258 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("term", "-expr");	
													if ((yyvsp[0].expressionValue)->boolConst == 'T')
														(yyvsp[0].expressionValue)->boolConst = 'F';
													else
														(yyvsp[0].expressionValue)->boolConst = 'T';

													(yyval.expressionValue) = (yyvsp[0].expressionValue);
												}
#line 1807 "syntax.c" /* yacc.c:1646  */
    break;

  case 33:
#line 266 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("term", "not expr");
										if ((yyvsp[0].expressionValue)->boolConst == 'T')
											(yyvsp[0].expressionValue)->boolConst = 'F';
										else
											(yyvsp[0].expressionValue)->boolConst = 'T';

										(yyval.expressionValue) = (yyvsp[0].expressionValue);
									}
#line 1820 "syntax.c" /* yacc.c:1646  */
    break;

  case 34:
#line 274 "syntax.y" /* yacc.c:1646  */
    {
										SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
										if (symbol && symbol->type == 3)
											printf("Error in line %d: You cannot increase left a user defined function (%s).\n", yylineno, yylval.stringValue);
										else if (symbol && symbol->type == 4)
											printf("Error in line %d: You cannot increase left a library function (%s).\n", yylineno, yylval.stringValue);
										messageHandler("term", "++yvalue");

										tempIncreaseAndUse();
										(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
										(yyvsp[0].expressionValue)->numConst++;
										quads[total] = emit(1, NewExpr(8, NULL, 1, NULL, 'T'), (yyvsp[0].expressionValue), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
										quads[total] = emit(0, (yyval.expressionValue), NULL, (yyvsp[0].expressionValue), (unsigned) yylineno, (unsigned) total++);
										(yyval.expressionValue)->numConst = (yyvsp[0].expressionValue)->numConst;

									}
#line 1841 "syntax.c" /* yacc.c:1646  */
    break;

  case 35:
#line 290 "syntax.y" /* yacc.c:1646  */
    {
						SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
						if (symbol && symbol->type == 3)
							printf("Error in line %d: You cannot increase right a user defined function (%s).\n", yylineno, yylval.stringValue);
						else if (symbol && symbol->type == 4)
							printf("Error in line %d: You cannot increase right a library function (%s).\n", yylineno, yylval.stringValue);
				 }
#line 1853 "syntax.c" /* yacc.c:1646  */
    break;

  case 36:
#line 296 "syntax.y" /* yacc.c:1646  */
    {
											messageHandler("term", "lvalue++");
											tempIncreaseAndUse();
											(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
											(yyvsp[-2].expressionValue)->numConst++;
											quads[total] = emit(1, (yyvsp[-2].expressionValue), NewExpr(8, NULL, 1, NULL, 'T'), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
											quads[total] = emit(0, (yyval.expressionValue), NULL, (yyvsp[-2].expressionValue), (unsigned) yylineno, (unsigned) total++);
											(yyval.expressionValue)->numConst = (yyvsp[-2].expressionValue)->numConst;
										}
#line 1867 "syntax.c" /* yacc.c:1646  */
    break;

  case 37:
#line 305 "syntax.y" /* yacc.c:1646  */
    { 
										SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
										if (symbol && symbol->type == 3)
											printf("Error in line %d: You cannot decrease left a user defined function (%s).\n", yylineno, yylval.stringValue);
										else if (symbol && symbol->type == 4)
											printf("Error in line %d: You cannot decrease left a library function (%s).\n", yylineno, yylval.stringValue);
										
										tempIncreaseAndUse();
										(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
										(yyvsp[0].expressionValue)->numConst--;
										quads[total] = emit(2, (yyvsp[0].expressionValue), NewExpr(8, NULL, 1, NULL, 'T'), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
										quads[total] = emit(0, (yyval.expressionValue), NULL, (yyvsp[0].expressionValue), (unsigned) yylineno, (unsigned) total++);
										(yyval.expressionValue)->numConst = (yyvsp[0].expressionValue)->numConst;
										messageHandler("term", "--lvalue");	
									}
#line 1887 "syntax.c" /* yacc.c:1646  */
    break;

  case 38:
#line 320 "syntax.y" /* yacc.c:1646  */
    {
						SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
						if (symbol && symbol->type == 3)
							printf("Error in line %d: You cannot decrease right a user defined function (%s).\n", yylineno, yylval.stringValue);
						else if (symbol && symbol->type == 4)
							printf("Error in line %d: You cannot decrease right a library function (%s).\n", yylineno, yylval.stringValue);
				 }
#line 1899 "syntax.c" /* yacc.c:1646  */
    break;

  case 39:
#line 326 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("term", "lvalue++");	
											tempIncreaseAndUse();
											(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
											(yyvsp[-2].expressionValue)->numConst--;
											quads[total] = emit(2, (yyvsp[-2].expressionValue), NewExpr(8, NULL, 1, NULL, 'T'), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
											quads[total] = emit(0, (yyval.expressionValue), NULL, (yyvsp[-2].expressionValue), (unsigned) yylineno, (unsigned) total++);
											(yyval.expressionValue)->numConst = (yyvsp[-2].expressionValue)->numConst;
										}
#line 1912 "syntax.c" /* yacc.c:1646  */
    break;

  case 40:
#line 335 "syntax.y" /* yacc.c:1646  */
    { 
					messageHandler("term", "primary");
					/* Periptwsi gia pinaka GET */
					if ((yyval.expressionValue)->index != NULL && (yyval.expressionValue)->type == 0) {
						table_stack_trace_index = -1;
						total++;
						(yyval.expressionValue) = emit_if_table((yyval.expressionValue), 23, oSymTable, scope, yylineno, NULL, (unsigned) yylineno, &total, quads);
					}
				}
#line 1926 "syntax.c" /* yacc.c:1646  */
    break;

  case 41:
#line 346 "syntax.y" /* yacc.c:1646  */
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
#line 1943 "syntax.c" /* yacc.c:1646  */
    break;

  case 42:
#line 358 "syntax.y" /* yacc.c:1646  */
    { 
						messageHandler("assignexpr", "lvalue = expr");

						/* Periptwsi anathesis metablitis se metabliti */
						if (syntax_error == 0 && (yyvsp[0].expressionValue)->type == 0) {
							(yyval.expressionValue)->sym = (yyvsp[-3].expressionValue)->sym;
							quads[total] = emit(0, (yyvsp[0].expressionValue), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
						}

						/* Periptwsi aplis anathesis const rvalue*/
						if (syntax_error == 0 && ((yyvsp[0].expressionValue)->type == 8 || (yyvsp[0].expressionValue)->type == 10) && (yyval.expressionValue)->index == NULL) {
							(yyval.expressionValue) = (yyvsp[-3].expressionValue);
							(yyval.expressionValue)->type = 6;
							if ((yyvsp[0].expressionValue)-> type == 8) (yyval.expressionValue)->numConst = (yyvsp[0].expressionValue)->numConst;
							else	(yyval.expressionValue)->strConst = _strdup((yyvsp[0].expressionValue)->strConst);

							quads[total] = emit(0, (yyvsp[0].expressionValue), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
						}

						/*Periptwsi pou to rvalue htan arithmetic*/
						if (syntax_error == 0 && (yyvsp[0].expressionValue)->type == 4) {
							(yyval.expressionValue) = (yyvsp[-3].expressionValue);
							(yyval.expressionValue)->type = 6;
							/* set_result($$, $4); Edw gia tin 5h fash mallon tha thelei result */
							quads[total] = emit(0, (yyvsp[0].expressionValue), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
						}

						/*Periptwsi pou to rvalue htan  ena table*/
						if (syntax_error == 0 && (yyvsp[0].expressionValue)->type == 7) {
							(yyval.expressionValue) = (yyvsp[-3].expressionValue);
							(yyval.expressionValue)->boolConst = 'T';
							(yyval.expressionValue)->type = 7;
							(yyval.expressionValue)->next = (yyvsp[0].expressionValue)->next; /* O deiktis ousiastika deixnei ston pinaka */
							quads[total] = emit(22, (yyvsp[0].expressionValue), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
						}


						/* Periptwsi pou to rvalue einai indexed apo table  */
						if (syntax_error == 0 && (yyvsp[0].expressionValue)->type == 23) {
							table_stack_trace_index = -1;
							quads[total] = emit(0, (yyvsp[0].expressionValue), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
						}

						/*Periptwsi poy to lvalue einai index emelent kai prepei na ginei set*/
						if (syntax_error == 0 && (yyval.expressionValue)->index != NULL) {
							table_stack_trace_index = -1;
							total++;
							(yyval.expressionValue) = emit_if_table((yyval.expressionValue), 24, oSymTable, scope, yylineno, (yyvsp[0].expressionValue), (unsigned) yylineno, &total, quads);
							quads[total] = emit(24, (yyval.expressionValue), NewExpr(1, NULL, 0, (yyval.expressionValue)->strConst, 'T'), (yyvsp[0].expressionValue), (unsigned) yylineno, (unsigned) total++);
						}

						/* Periptwsi poy to rvalue einai func call */
						if (syntax_error == 0 && (yyvsp[0].expressionValue)->type == 2) {
							quads[total] = emit(0, (yyvsp[0].expressionValue), NULL, (yyvsp[-3].expressionValue), (unsigned) yylineno, (unsigned) total++);
							(yyval.expressionValue) = (yyvsp[-3].expressionValue);
						}
					 }
#line 2005 "syntax.c" /* yacc.c:1646  */
    break;

  case 43:
#line 417 "syntax.y" /* yacc.c:1646  */
    {  messageHandler("primary", "lvalue");	}
#line 2011 "syntax.c" /* yacc.c:1646  */
    break;

  case 44:
#line 418 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("primary", "call");
								if (syntax_error == 0 && (yyvsp[0].expressionValue)->type == 2) {
									quads[total] = emit(19, NULL, NULL, (yyvsp[0].expressionValue), (unsigned) yylineno, (unsigned) total++);
								}

								(yyval.expressionValue) = (yyvsp[0].expressionValue);
							}
#line 2023 "syntax.c" /* yacc.c:1646  */
    break;

  case 45:
#line 425 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "objectdef");	}
#line 2029 "syntax.c" /* yacc.c:1646  */
    break;

  case 46:
#line 426 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "(funcdef)");	}
#line 2035 "syntax.c" /* yacc.c:1646  */
    break;

  case 47:
#line 427 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "const");		}
#line 2041 "syntax.c" /* yacc.c:1646  */
    break;

  case 48:
#line 430 "syntax.y" /* yacc.c:1646  */
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

						/* Gia na paei sto assignexpr kai ekei tha parei ton teliko tou typo */
						(yyval.expressionValue) = NewExpr(0, SymTable_get(oSymTable, yylval.stringValue), 0, NULL, 'F');

						messageHandler("lvalue", "identifier"); 
					}
#line 2076 "syntax.c" /* yacc.c:1646  */
    break;

  case 49:
#line 460 "syntax.y" /* yacc.c:1646  */
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
#line 2095 "syntax.c" /* yacc.c:1646  */
    break;

  case 50:
#line 474 "syntax.y" /* yacc.c:1646  */
    {
									if (scope_lookup(yylval.stringValue, 0) == 0) {
										printf("Error in line %d: Not found global symbol with name [%s].\n", yylineno, yylval.stringValue);
									}
									messageHandler("lvalue", ":: identifier");
								}
#line 2106 "syntax.c" /* yacc.c:1646  */
    break;

  case 51:
#line 480 "syntax.y" /* yacc.c:1646  */
    { messageHandler("lvalue", "member");		}
#line 2112 "syntax.c" /* yacc.c:1646  */
    break;

  case 52:
#line 484 "syntax.y" /* yacc.c:1646  */
    {		messageHandler("member", "lvalue.identifier");
					if (table_stack_trace_index == -1) {
						(yyval.expressionValue) = NewExpr(0, (yyvsp[-2].expressionValue)->sym, 0, NULL, 'T');
						(yyval.expressionValue)->index = NewExpr(1, NULL, 0, yylval.stringValue, 'T');
						table_stack_trace_index++;
					}
					else if (table_stack_trace_index == 0) {
						(yyval.expressionValue) = push_index_back((yyval.expressionValue), NewExpr(1, NULL, 0, yylval.stringValue, 'T'));
					}
			  }
#line 2127 "syntax.c" /* yacc.c:1646  */
    break;

  case 53:
#line 495 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "lvalue[expr]");
			if (table_stack_trace_index == -1) {
				(yyval.expressionValue) = NewExpr(0, (yyvsp[-3].expressionValue)->sym, 0, NULL, 'T');
				(yyval.expressionValue)->index = NewExpr(1, NULL, 0, yylval.stringValue, 'T');
				table_stack_trace_index++;
			}
			else if (table_stack_trace_index == 0) {
				(yyval.expressionValue) = push_index_back((yyval.expressionValue), NewExpr(1, NULL, 0, yylval.stringValue, 'T'));
			}
		  }
#line 2142 "syntax.c" /* yacc.c:1646  */
    break;

  case 54:
#line 505 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "call.identifier");	}
#line 2148 "syntax.c" /* yacc.c:1646  */
    break;

  case 55:
#line 506 "syntax.y" /* yacc.c:1646  */
    { messageHandler("member", "[expr]");		}
#line 2154 "syntax.c" /* yacc.c:1646  */
    break;

  case 56:
#line 509 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("call", "call(elist)");
														quads[total] = emit(19, NULL, NULL, (yyvsp[-3].expressionValue), yylineno, total++);
														
														expression *tmp = (yyvsp[-1].expressionValue);
														while (tmp != NULL) {
															quads[total] = emit(17, NULL, NULL, tmp, yylineno, total++);
															tmp = tmp->next;
														}
														
														quads[total] = emit(16, NULL, NULL, (yyvsp[-3].expressionValue), yylineno, total++);
														tempIncreaseAndUse();
														SymbolTableEntry* symbol = SymTable_get(oSymTable, currentTemp);
														(yyvsp[-3].expressionValue)->sym = symbol;
														(yyval.expressionValue) = NewExpr(2, symbol, 0, NULL, 'F');
													}
#line 2174 "syntax.c" /* yacc.c:1646  */
    break;

  case 57:
#line 524 "syntax.y" /* yacc.c:1646  */
    {
										messageHandler("call", "lvalue callsuffix");
										quads[total] = emit(16, NULL, NULL, (yyvsp[-1].expressionValue), yylineno, total++);

										tempIncreaseAndUse();
										SymbolTableEntry* symbol = SymTable_get(oSymTable, currentTemp);
										(yyval.expressionValue) = NewExpr(2, symbol, 0, NULL, 'F');
									}
#line 2187 "syntax.c" /* yacc.c:1646  */
    break;

  case 58:
#line 533 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("call", "(funcdef)(elist)");
										quads[total] = emit(21, NULL, NULL, (yyvsp[-4].expressionValue), yylineno, total++);
										expression *tmp = (yyvsp[-1].expressionValue);
										while (tmp != NULL) {
											quads[total] = emit(17, NULL, NULL, tmp, yylineno, total++);
											tmp = tmp->next;
										}

										quads[total] = emit(16, NULL, NULL, (yyvsp[-4].expressionValue), yylineno, total++);

										tempIncreaseAndUse();
										SymbolTableEntry* symbol = SymTable_get(oSymTable, currentTemp);
										(yyval.expressionValue) = NewExpr(2, symbol, 0, NULL, 'F');
									}
#line 2206 "syntax.c" /* yacc.c:1646  */
    break;

  case 59:
#line 549 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("callsuffix", "normcall");	
							(yyval.expressionValue) = (yyvsp[0].expressionValue);
							expression *tmp = (yyvsp[0].expressionValue);
							while (tmp != NULL) {
								quads[total] = emit(17, NULL, NULL, tmp, yylineno, total++);
								tmp = tmp->next;
							}
						}
#line 2219 "syntax.c" /* yacc.c:1646  */
    break;

  case 60:
#line 557 "syntax.y" /* yacc.c:1646  */
    { messageHandler("callsuffix", "methodcall");	}
#line 2225 "syntax.c" /* yacc.c:1646  */
    break;

  case 61:
#line 560 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("normcall", "(elist)");	
													(yyval.expressionValue) = (yyvsp[-1].expressionValue);
												}
#line 2233 "syntax.c" /* yacc.c:1646  */
    break;

  case 62:
#line 565 "syntax.y" /* yacc.c:1646  */
    { messageHandler("methodcall", "..identifier(elist)");	}
#line 2239 "syntax.c" /* yacc.c:1646  */
    break;

  case 63:
#line 568 "syntax.y" /* yacc.c:1646  */
    {
									messageHandler("elist", "expr comma-expressions");
									(yyvsp[-1].expressionValue)->type = 1;
									table_stack[table_stack_index] = push_back(table_stack[table_stack_index], (yyvsp[-1].expressionValue));
									(yyval.expressionValue) = table_stack[table_stack_index];
								}
#line 2250 "syntax.c" /* yacc.c:1646  */
    break;

  case 64:
#line 574 "syntax.y" /* yacc.c:1646  */
    { messageHandler("elist", "'e'");	(yyval.expressionValue) = NULL;}
#line 2256 "syntax.c" /* yacc.c:1646  */
    break;

  case 65:
#line 577 "syntax.y" /* yacc.c:1646  */
    { 
					messageHandler("comma-expressions", ", expr comma-expressions");
					(yyvsp[-1].expressionValue)->type = 1;
					table_stack[table_stack_index] = push_back(table_stack[table_stack_index], (yyvsp[-1].expressionValue));
			}
#line 2266 "syntax.c" /* yacc.c:1646  */
    break;

  case 66:
#line 582 "syntax.y" /* yacc.c:1646  */
    { messageHandler("comma-expressions", "'e'");	}
#line 2272 "syntax.c" /* yacc.c:1646  */
    break;

  case 67:
#line 585 "syntax.y" /* yacc.c:1646  */
    {table_stack_index++;}
#line 2278 "syntax.c" /* yacc.c:1646  */
    break;

  case 68:
#line 586 "syntax.y" /* yacc.c:1646  */
    {
					messageHandler("objectdef", "[elist]");
					(yyval.expressionValue) = NewExpr(7, NULL, 0, NULL, 'F');
					(yyval.expressionValue)->next = table_stack[table_stack_index];
					table_stack[table_stack_index--] = NULL;
			  }
#line 2289 "syntax.c" /* yacc.c:1646  */
    break;

  case 69:
#line 592 "syntax.y" /* yacc.c:1646  */
    {table_stack_index++;}
#line 2295 "syntax.c" /* yacc.c:1646  */
    break;

  case 70:
#line 593 "syntax.y" /* yacc.c:1646  */
    {	
				messageHandler("objectdef", "[indexed]");
				(yyval.expressionValue) = NewExpr(7, NULL, 0, NULL, 'F');
				(yyval.expressionValue)->next = table_stack[table_stack_index];
				table_stack[table_stack_index--] = NULL;
			}
#line 2306 "syntax.c" /* yacc.c:1646  */
    break;

  case 71:
#line 601 "syntax.y" /* yacc.c:1646  */
    { messageHandler("indexed", "indexedelem commaindex");		}
#line 2312 "syntax.c" /* yacc.c:1646  */
    break;

  case 72:
#line 604 "syntax.y" /* yacc.c:1646  */
    { messageHandler("commaindex", ", indexedelem commaindex");		}
#line 2318 "syntax.c" /* yacc.c:1646  */
    break;

  case 73:
#line 605 "syntax.y" /* yacc.c:1646  */
    { messageHandler("commaindex", "'e'");		}
#line 2324 "syntax.c" /* yacc.c:1646  */
    break;

  case 74:
#line 609 "syntax.y" /* yacc.c:1646  */
    {
				messageHandler("indexedelem", "{expr:expr}");
				(yyvsp[-3].expressionValue)->type = 1;
				table_stack[table_stack_index] = push_back(table_stack[table_stack_index], (yyvsp[-3].expressionValue));
				(yyvsp[-3].expressionValue)->index = (yyvsp[-1].expressionValue);
				printf("To do emmit in table {%s : %s}.\n", getExpressionValue((yyvsp[-3].expressionValue)), getExpressionValue((yyvsp[-1].expressionValue)));
			 }
#line 2336 "syntax.c" /* yacc.c:1646  */
    break;

  case 75:
#line 618 "syntax.y" /* yacc.c:1646  */
    {++scope; if (function_flag == 1) function_flag = 0;}
#line 2342 "syntax.c" /* yacc.c:1646  */
    break;

  case 76:
#line 619 "syntax.y" /* yacc.c:1646  */
    {
				hide(scope--); 
				messageHandler("block", "{stmts}"); 
			}
#line 2351 "syntax.c" /* yacc.c:1646  */
    break;

  case 77:
#line 625 "syntax.y" /* yacc.c:1646  */
    {func_locals_sum[scope] = 0; ++scope; function_flag = 1;}
#line 2357 "syntax.c" /* yacc.c:1646  */
    break;

  case 78:
#line 626 "syntax.y" /* yacc.c:1646  */
    {
				hide(scope--); 
				function_flag = 0;
				messageHandler("funblock", "{stmts}"); 
			}
#line 2367 "syntax.c" /* yacc.c:1646  */
    break;

  case 79:
#line 633 "syntax.y" /* yacc.c:1646  */
    {		/* Dhmiourgeia anonymous function */
								char tmp[3];
								memset(tmp, '\0', 3);
								memset(funcName, '\0', 8);
								strcpy(funcName, "@fnc");
								sprintf(tmp, "%d", function_counter++);
								strcat(funcName, tmp);
								SymTable_put(oSymTable, funcName, 3, scope, yylineno, 1);

								SymbolTableEntry* symbol = SymTable_get(oSymTable, funcName);
								function_expression[scope] = NewExpr(2, symbol, 666 + all_func_counter, NULL, 'T');
								quads[total] = emit(20, NULL, NULL, function_expression[scope], yylineno, total++);
								all_func_counter++;
						  }
#line 2386 "syntax.c" /* yacc.c:1646  */
    break;

  case 80:
#line 648 "syntax.y" /* yacc.c:1646  */
    {		messageHandler("funcdef", "function (idlist) funblock");
								function_expression[scope] += func_locals_sum[scope];
								(yyval.expressionValue) = function_expression[scope];
								/*Prepei na parei to symbolo tis anonymous function. Na synipologizontai ta locals. Pou tha kratiountai?*/
						  }
#line 2396 "syntax.c" /* yacc.c:1646  */
    break;

  case 81:
#line 653 "syntax.y" /* yacc.c:1646  */
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
								
								symbol = SymTable_get(oSymTable, yylval.stringValue);
								function_expression[scope] = NewExpr(2, symbol, 666 + all_func_counter, NULL, 'T');
								quads[total] = emit(20, NULL, NULL, function_expression[scope], yylineno, total++);
								all_func_counter++;

							}
#line 2419 "syntax.c" /* yacc.c:1646  */
    break;

  case 82:
#line 671 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("funcdef", "function identifier (idlist) funblock");
														function_expression[scope] += func_locals_sum[scope];
														(yyval.expressionValue) = function_expression[scope];
												   }
#line 2428 "syntax.c" /* yacc.c:1646  */
    break;

  case 83:
#line 677 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("const", "real_value");
							if ((yyvsp[0].realValue) == 0)
								(yyval.expressionValue) = NewExpr(8, NULL, (yyvsp[0].realValue), NULL, 'F');
							else
								(yyval.expressionValue) = NewExpr(8, NULL, (yyvsp[0].realValue), NULL, 'T');
						}
#line 2439 "syntax.c" /* yacc.c:1646  */
    break;

  case 84:
#line 683 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("const", "integer_value");
							if ((yyvsp[0].integerValue) == 0)
								(yyval.expressionValue) = NewExpr(8, NULL, (yyvsp[0].integerValue), NULL, 'F');
							else
								(yyval.expressionValue) = NewExpr(8, NULL, (yyvsp[0].integerValue), NULL, 'T');
						}
#line 2450 "syntax.c" /* yacc.c:1646  */
    break;

  case 85:
#line 689 "syntax.y" /* yacc.c:1646  */
    { 
							messageHandler("const", "string");
							if (strcmp( (yyvsp[0].stringValue), "") == 0)
								(yyval.expressionValue) = NewExpr(10, NULL, 0, (yyvsp[0].stringValue), 'F');
							else
								(yyval.expressionValue) = NewExpr(10, NULL, 0, (yyvsp[0].stringValue), 'T');
						}
#line 2462 "syntax.c" /* yacc.c:1646  */
    break;

  case 86:
#line 696 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "nil");	(yyval.expressionValue) = NewExpr(11, NULL, 0, NULL, 'F');}
#line 2468 "syntax.c" /* yacc.c:1646  */
    break;

  case 87:
#line 697 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "true");	(yyval.expressionValue) = NewExpr(9, NULL, 0, NULL, 'T');}
#line 2474 "syntax.c" /* yacc.c:1646  */
    break;

  case 88:
#line 698 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "false");	(yyval.expressionValue) = NewExpr(9, NULL, 0, NULL, 'F');}
#line 2480 "syntax.c" /* yacc.c:1646  */
    break;

  case 89:
#line 701 "syntax.y" /* yacc.c:1646  */
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
#line 2495 "syntax.c" /* yacc.c:1646  */
    break;

  case 90:
#line 711 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idlist", "identifier idwithcommas");	}
#line 2501 "syntax.c" /* yacc.c:1646  */
    break;

  case 91:
#line 712 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idlist", "'e'");		}
#line 2507 "syntax.c" /* yacc.c:1646  */
    break;

  case 92:
#line 715 "syntax.y" /* yacc.c:1646  */
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
#line 2523 "syntax.c" /* yacc.c:1646  */
    break;

  case 93:
#line 726 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idwithcommas", ", identifier idwithcommas");		}
#line 2529 "syntax.c" /* yacc.c:1646  */
    break;

  case 94:
#line 727 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idwithcommas", "'e'");		}
#line 2535 "syntax.c" /* yacc.c:1646  */
    break;

  case 95:
#line 730 "syntax.y" /* yacc.c:1646  */
    { messageHandler("ifstmt", "if (expr) stmt");	}
#line 2541 "syntax.c" /* yacc.c:1646  */
    break;

  case 96:
#line 731 "syntax.y" /* yacc.c:1646  */
    { messageHandler("ifstmt", "if (expr) stmt else stmt");	}
#line 2547 "syntax.c" /* yacc.c:1646  */
    break;

  case 97:
#line 734 "syntax.y" /* yacc.c:1646  */
    { messageHandler("whilestmt", "while (exrpr) stmt");	}
#line 2553 "syntax.c" /* yacc.c:1646  */
    break;

  case 98:
#line 738 "syntax.y" /* yacc.c:1646  */
    { messageHandler("forstmt", "for (elist expr; expr; elist) stmt");	}
#line 2559 "syntax.c" /* yacc.c:1646  */
    break;

  case 99:
#line 741 "syntax.y" /* yacc.c:1646  */
    { messageHandler("returnstmt", "return;");		}
#line 2565 "syntax.c" /* yacc.c:1646  */
    break;

  case 100:
#line 742 "syntax.y" /* yacc.c:1646  */
    { messageHandler("returnstmt", "return expr;");		}
#line 2571 "syntax.c" /* yacc.c:1646  */
    break;


#line 2575 "syntax.c" /* yacc.c:1646  */
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
#line 744 "syntax.y" /* yacc.c:1906  */


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

	for (int i = 0; i < 8; i++) {
		table_stack[i] = NULL;
	}

	for (int i = 0; i < 72; i++) {
		func_locals_sum[i] = 0;
		function_expression[i] = NULL;
	}

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
	printQuads();

	return 0;
}
