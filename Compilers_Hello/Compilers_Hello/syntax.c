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
	#include "avm_tools.h"

	extern int yylineno;
	extern char *yyval;
	extern char *yytext;
	extern FILE *yyin;
	extern FILE *yyout;

	SymTable_T oSymTable;
	int scope;

	tesseract quads[1024];
	unsigned total = 1;
	unsigned int currQuad = 0;

	char currentTemp[8];
	int temp_counter = 0;

	/* xeirourgio gia tis synartiseis */ 
	int func_locals_sum[72];
	expression *function_expression[72];


	/* while, for stoiba xeirourgio */
	int loop_stack[72]; /* O arithmos twn total quads stin arxi tis loopas */
	int loop_i = 0;

	/* break, continue Lists, eksartwntai apo to loop_i */
	BreakList *b_list[72];
	ContinueList *c_list[72];

	void tempIncreaseAndUse(){
		memset(currentTemp, '\0', 8);
		strcpy(currentTemp, "_t");

		char tmp[3];
		memset(tmp, '\0', 3);
		sprintf(tmp, "%d", temp_counter++);

		strcat(currentTemp, tmp);
		
		if(SymTable_get(oSymTable, currentTemp) == NULL)
			SymTable_put(oSymTable, currentTemp, 0, 0, yylineno, 1);
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
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   548

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

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
       0,   200,   200,   203,   203,   204,   208,   209,   210,   211,
     212,   213,   230,   247,   248,   252,   255,   256,   263,   269,
     275,   282,   289,   311,   326,   341,   356,   372,   387,   408,
     427,   430,   431,   443,   466,   485,   485,   503,   520,   520,
     537,   549,   549,   632,   633,   642,   654,   659,   662,   692,
     708,   717,   723,   730,   737,   756,   776,   794,   857,   874,
     875,   878,   881,   895,   899,   902,   906,   909,   916,   925,
     930,   933,   936,   944,   944,   951,   951,   959,   959,   990,
     990,  1027,  1033,  1039,  1046,  1047,  1048,  1051,  1051,  1063,
    1066,  1066,  1080,  1083,  1098,  1103,  1103,  1121,  1121,  1151,
    1164,  1164,  1194,  1211
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
  "$@10", "ifinside", "ifstmt", "$@11", "whilestmt", "$@12", "forinside",
  "forstmt", "$@13", "returnstmt", YY_NULL
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

#define YYPACT_NINF -56

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-56)))

#define YYTABLE_NINF -42

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-42)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     144,   -56,   -56,   -56,   -35,   -31,   -56,   -51,   -29,   177,
     243,    -7,   -56,   -56,   -56,    17,   -56,    -8,   243,    -8,
     -56,    86,   210,    28,   -56,    38,   -56,   -56,   -10,   -56,
     -56,   -56,    49,   -56,   -28,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   243,   144,   243,   -35,   -56,   -56,   -56,
     264,   -56,   -56,   -56,    11,    32,    -5,   -28,   -56,    -5,
     144,   243,   291,    13,    14,     5,   345,    27,   -56,   -56,
     144,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   -56,   243,   243,    53,    54,    48,
      50,    59,   -56,   -56,   -56,   243,   243,    57,   372,    83,
      41,   144,   -56,    51,    71,    55,    52,   318,   243,   -56,
     -56,   -56,    63,   -56,   -56,    62,   -56,   493,   493,   506,
     506,    12,    12,   -56,   -56,   -56,   332,   332,   332,   332,
     399,    65,   -56,    70,   -56,   -56,   243,   426,    68,   -56,
     -56,   -56,   -56,   -56,    71,   -56,    74,    62,   -56,   243,
     291,     5,   243,   -56,   -56,   243,   480,   -56,   -56,   144,
     243,    75,    72,    81,   453,   -56,   -56,    78,    84,   -56,
     480,    64,    81,    76,   -56,   -56,   -56,   -56,   -56,   -56,
     243,   -56,   -56,   144,    85,    72,    88,   144,   -56,   -56,
     -56
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    82,    81,    83,     0,     0,    97,     0,     0,     0,
       0,     0,    84,    85,    86,    77,    48,     0,     0,     0,
      73,    64,     0,     0,    15,     0,     2,     3,     0,    30,
      16,    40,    43,    51,    44,    45,    13,    14,    47,     7,
       8,     9,    10,     0,     0,    64,     0,    12,    11,   102,
       0,    33,    49,    79,     0,     0,    34,     0,    32,    37,
       5,     0,    66,     0,     0,    71,     0,     0,    50,     1,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,    64,     0,     0,     0,
       0,     0,    57,    59,    60,     0,    64,     0,     0,    94,
       0,     0,   103,     0,    89,     0,     0,     0,     0,    63,
      67,    68,     0,    69,    31,    46,     4,    28,    29,    26,
      27,    17,    18,    19,    20,    21,    24,    25,    22,    23,
       0,     0,    52,     0,    36,    39,     0,     0,     0,    54,
      93,    95,   100,    98,    89,    87,     0,     0,    74,     0,
      66,    71,    64,    53,    61,    64,    42,    55,    56,     0,
       0,     0,    92,     0,     0,    65,    70,     0,     0,    96,
      99,     0,     0,     0,    88,    75,    78,    72,    58,    62,
      64,    80,    90,     5,     0,    92,     0,     0,    91,    76,
     101
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,   -55,   -56,   -42,    -9,   -56,   -56,   -56,   -56,
     -56,   -56,    16,   -56,    34,   -56,   -56,   -56,   -41,   -15,
     -56,   -56,   -13,    25,   -56,   -56,   -30,   -56,   -14,   -56,
     -56,   -56,    -3,   -56,   -32,   -56,    98,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    70,    27,    28,    29,    89,    90,    30,
      91,    31,    32,    33,    34,    92,    93,    94,    63,   109,
      35,    64,   113,    65,    36,    60,   176,   183,    37,    54,
     103,    38,   146,   162,   174,   185,    44,    39,   159,    40,
      46,   171,    41,   160,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    51,    99,    47,   100,   106,    71,    72,    67,    58,
      43,    11,    62,    66,    45,   116,    95,    96,    16,    52,
      73,    74,    75,    97,    76,    48,    77,    78,    79,    80,
      81,    82,    83,    56,    98,    59,    62,    55,    69,    85,
      86,   105,    23,    53,    84,   131,    87,    88,    77,    78,
      79,    57,   107,    57,    68,   138,   104,    15,   112,   143,
     110,   111,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   115,   130,    62,   -41,   132,
     133,   134,   -35,   139,   -38,   135,   137,    62,   136,     1,
       2,     3,   141,    85,    86,   142,   144,   145,   148,   150,
      87,    88,   182,   147,    10,    11,    61,   152,    12,    13,
      14,   167,    16,   154,   168,   155,   158,   169,   180,    17,
      18,    19,   163,   172,   175,   173,   178,   156,   186,    61,
      21,    22,   179,   187,   189,   165,    23,   151,   166,   184,
     164,   161,   181,    62,   101,   190,    62,     1,     2,     3,
       0,   170,     4,   188,     5,     6,     0,     7,     8,     9,
       0,     0,    10,    11,     0,     0,    12,    13,    14,    15,
      16,    62,     0,     0,     0,     0,     0,    17,    18,    19,
       1,     2,     3,     0,     0,     0,     0,    20,    21,    22,
       0,     0,     0,     0,    23,    10,    11,     0,    24,    12,
      13,    14,     0,    16,     0,     0,     0,     0,     0,     0,
      17,    18,    19,     1,     2,     3,     0,     0,     0,     0,
       0,    21,    22,     0,     0,     0,     0,    23,    10,    11,
       0,    49,    12,    13,    14,    15,    16,     0,     0,     0,
       0,     0,     0,    17,    18,    19,     1,     2,     3,     0,
       0,     0,     0,     0,    21,    22,     0,     0,     0,     0,
      23,    10,    11,     0,     0,    12,    13,    14,     0,    16,
       0,     0,     0,     0,     0,     0,    17,    18,    19,     0,
      71,    72,     0,     0,     0,     0,     0,    21,    22,     0,
       0,     0,     0,    23,    73,    74,    75,     0,    76,     0,
      77,    78,    79,    80,    81,    82,    83,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,     0,
       0,    73,    74,    75,     0,    76,     0,    77,    78,    79,
      80,    81,    82,    83,    71,    72,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,    73,    74,
      75,     0,    76,     0,    77,    78,    79,    80,    81,    82,
      83,    71,    72,     0,    75,     0,    76,   149,    77,    78,
      79,   -42,   -42,   -42,   -42,    73,    74,    75,     0,    76,
       0,    77,    78,    79,    80,    81,    82,    83,    71,    72,
       0,     0,     0,   114,     0,     0,     0,     0,     0,     0,
       0,     0,    73,    74,    75,     0,    76,     0,    77,    78,
      79,    80,    81,    82,    83,    71,    72,     0,     0,     0,
     140,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    75,     0,    76,     0,    77,    78,    79,    80,    81,
      82,    83,    71,    72,     0,     0,   153,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,    74,    75,     0,
      76,     0,    77,    78,    79,    80,    81,    82,    83,    71,
      72,     0,     0,   157,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,    75,     0,    76,     0,    77,
      78,    79,    80,    81,    82,    83,    71,    72,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,    75,     0,    76,     0,    77,    78,    79,    80,
      81,    82,    83,    73,    74,    75,     0,    76,     0,    77,
      78,    79,    80,    81,    82,    83,   -42,   -42,    75,     0,
      76,     0,    77,    78,    79,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
       9,    10,    44,    54,    45,    60,    16,    17,    22,    18,
      45,    19,    21,    22,    45,    70,    44,    45,    26,    26,
      30,    31,    32,    51,    34,    54,    36,    37,    38,    39,
      40,    41,    42,    17,    43,    19,    45,    45,     0,    44,
      45,    55,    50,    26,    54,    86,    51,    52,    36,    37,
      38,    17,    61,    19,    26,    96,    45,    25,    53,   101,
      47,    47,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    48,    85,    86,    29,    26,
      26,    33,    33,    26,    35,    35,    95,    96,    29,     3,
       4,     5,     9,    44,    45,    54,    45,    26,    46,   108,
      51,    52,    26,    48,    18,    19,    43,    45,    22,    23,
      24,   152,    26,    48,   155,    45,    48,   159,    54,    33,
      34,    35,    48,    48,    43,    53,    48,   136,   183,    43,
      44,    45,    48,    48,    46,   150,    50,   112,   151,   180,
     149,   144,   172,   152,    46,   187,   155,     3,     4,     5,
      -1,   160,     8,   185,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    18,    19,    -1,    -1,    22,    23,    24,    25,
      26,   180,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
       3,     4,     5,    -1,    -1,    -1,    -1,    43,    44,    45,
      -1,    -1,    -1,    -1,    50,    18,    19,    -1,    54,    22,
      23,    24,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    -1,    50,    18,    19,
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
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    30,    31,
      32,    -1,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    16,    17,    -1,    32,    -1,    34,    49,    36,    37,
      38,    39,    40,    41,    42,    30,    31,    32,    -1,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    16,    17,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    -1,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    16,    17,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    -1,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    16,    17,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    16,
      17,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    -1,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    16,    17,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    -1,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    30,    31,    32,    -1,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    30,    31,    32,    -1,
      34,    -1,    36,    37,    38,    39,    40,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     8,    10,    11,    13,    14,    15,
      18,    19,    22,    23,    24,    25,    26,    33,    34,    35,
      43,    44,    45,    50,    54,    58,    59,    61,    62,    63,
      66,    68,    69,    70,    71,    77,    81,    85,    88,    94,
      96,    99,   101,    45,    93,    45,    97,    54,    54,    54,
      62,    62,    26,    26,    86,    45,    69,    71,    62,    69,
      82,    43,    62,    75,    78,    80,    62,    85,    26,     0,
      60,    16,    17,    30,    31,    32,    34,    36,    37,    38,
      39,    40,    41,    42,    54,    44,    45,    51,    52,    64,
      65,    67,    72,    73,    74,    44,    45,    51,    62,    61,
      75,    93,    54,    87,    45,    85,    59,    62,    53,    76,
      47,    47,    53,    79,    48,    48,    59,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    75,    26,    26,    33,    35,    29,    62,    75,    26,
      48,     9,    54,    61,    45,    26,    89,    48,    46,    49,
      62,    80,    45,    47,    48,    45,    62,    47,    48,    95,
     100,    89,    90,    48,    62,    76,    79,    75,    75,    61,
      62,    98,    48,    53,    91,    43,    83,    46,    48,    48,
      54,    83,    26,    84,    75,    92,    59,    48,    91,    46,
      61
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
      92,    91,    91,    93,    94,    95,    94,    97,    96,    98,
     100,    99,   101,   101
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
       0,     4,     0,     3,     3,     0,     6,     0,     4,     1,
       0,    10,     2,     3
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
#line 200 "syntax.y" /* yacc.c:1646  */
    { messageHandler("program", "statements");	}
#line 1584 "syntax.c" /* yacc.c:1646  */
    break;

  case 3:
#line 203 "syntax.y" /* yacc.c:1646  */
    { if (function_flag == 0) temp_counter = 0; }
#line 1590 "syntax.c" /* yacc.c:1646  */
    break;

  case 4:
#line 203 "syntax.y" /* yacc.c:1646  */
    { messageHandler("statements", "stmt statements");	}
#line 1596 "syntax.c" /* yacc.c:1646  */
    break;

  case 5:
#line 204 "syntax.y" /* yacc.c:1646  */
    { messageHandler("statements", "'e'");	}
#line 1602 "syntax.c" /* yacc.c:1646  */
    break;

  case 6:
#line 208 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "expr;");	(yyval.expressionValue) = NewExpr(0, NULL, total, NULL, 'T');}
#line 1608 "syntax.c" /* yacc.c:1646  */
    break;

  case 7:
#line 209 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "ifstmt");	(yyval.expressionValue) = NewExpr(0, NULL, total, NULL, 'T');}
#line 1614 "syntax.c" /* yacc.c:1646  */
    break;

  case 8:
#line 210 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "whilestmt");	(yyval.expressionValue) = NewExpr(0, NULL, total, NULL, 'T');}
#line 1620 "syntax.c" /* yacc.c:1646  */
    break;

  case 9:
#line 211 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "forstmt");	(yyval.expressionValue) = NewExpr(0, NULL, total, NULL, 'T');}
#line 1626 "syntax.c" /* yacc.c:1646  */
    break;

  case 10:
#line 212 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "returnstmt");	}
#line 1632 "syntax.c" /* yacc.c:1646  */
    break;

  case 11:
#line 213 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("stmt", "break;");
									if (loop_i - 1 < 0) {
										printf("Error in line %d: Break found out of loop!\n", yylineno);
										syntax_error = 1;
									}
									else {
										/* Kanoume emit to unpatched Quad */
										expression *break_jump = NewExpr(8, NULL, -2, NULL, 'T');
										quads[total] = emit(25, NULL, NULL, break_jump, yylineno, total++);

										(yyval.expressionValue) = break_jump;
										//printf("What about %f ?\n", quads[total].result->numConst);

										/* Mpainei mesa to Break */
										b_list[loop_i - 1] = push_BreakList(b_list[loop_i - 1], &quads[total]);
									}
		}
#line 1654 "syntax.c" /* yacc.c:1646  */
    break;

  case 12:
#line 230 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("stmt", "continue;"); 
										if (loop_i - 1 < 0) {
											printf("Error in line %d: Continue found out of loop!\n", yylineno);
											syntax_error = 1;
										}
										else {
											/* Kanoume emit to unpatched Quad */
											expression *cont_jump = NewExpr(8, NULL, -2, NULL, 'T');
											quads[total] = emit(25, NULL, NULL, cont_jump, yylineno, total++);

											(yyval.expressionValue) = cont_jump;
											//printf("What about %f ?\n", quads[total].result->numConst);

											/* Mpainei mesa to Continue */
											c_list[loop_i - 1] = push_ContinueList(c_list[loop_i - 1], &quads[total]);
										}
		}
#line 1676 "syntax.c" /* yacc.c:1646  */
    break;

  case 13:
#line 247 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "block");	(yyval.expressionValue) = (yyvsp[0].expressionValue);}
#line 1682 "syntax.c" /* yacc.c:1646  */
    break;

  case 14:
#line 248 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", "funcdef");
							  quads[total] = emit(21, NULL, NULL, (yyvsp[0].expressionValue), yylineno, total++);
							  (yyval.expressionValue) = (yyvsp[0].expressionValue);
							}
#line 1691 "syntax.c" /* yacc.c:1646  */
    break;

  case 15:
#line 252 "syntax.y" /* yacc.c:1646  */
    { messageHandler("stmt", ";");	}
#line 1697 "syntax.c" /* yacc.c:1646  */
    break;

  case 16:
#line 255 "syntax.y" /* yacc.c:1646  */
    { messageHandler("expr", "assignexpr");	}
#line 1703 "syntax.c" /* yacc.c:1646  */
    break;

  case 17:
#line 256 "syntax.y" /* yacc.c:1646  */
    { 
								messageHandler("expr", "expr + expr");
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
								quads[total] = emit(1, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);

							}
#line 1715 "syntax.c" /* yacc.c:1646  */
    break;

  case 18:
#line 263 "syntax.y" /* yacc.c:1646  */
    { 
									messageHandler("expr", "expr - expr");
									tempIncreaseAndUse();
									(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
									quads[total] = emit(2, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
								}
#line 1726 "syntax.c" /* yacc.c:1646  */
    break;

  case 19:
#line 269 "syntax.y" /* yacc.c:1646  */
    { 
								messageHandler("expr", "expr * expr"); 
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
								quads[total] = emit(3, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
							}
#line 1737 "syntax.c" /* yacc.c:1646  */
    break;

  case 20:
#line 275 "syntax.y" /* yacc.c:1646  */
    {
								messageHandler("expr", "expr * expr"); 
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
								quads[total] = emit(4, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
								messageHandler("expr", "expr / expr");
							}
#line 1749 "syntax.c" /* yacc.c:1646  */
    break;

  case 21:
#line 282 "syntax.y" /* yacc.c:1646  */
    { 
								messageHandler("expr", "expr % expr");
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
								quads[total] = emit(5, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
								messageHandler("expr", "expr / expr");
							}
#line 1761 "syntax.c" /* yacc.c:1646  */
    break;

  case 22:
#line 289 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("expr", "expr > expr"); 
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
								
								expression *jump_val = NewExpr(8, NULL, total + 3, NULL, 'T');
								expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');

								/*[T1]: If Greater paw 2 grammes katw  na to kanw T*/
								quads[total] = emit(15, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), jump_val, (unsigned) yylineno, (unsigned) total++);
								
								/*[F1]: Den einai greater ara kanw ton kataxwriti FALSE */
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'F'), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
								
								/*[F2]: Kai kanw Jump me tin FALSE timi*/
								quads[total] = emit(25, NULL, NULL, jump_val2, (unsigned) yylineno, (unsigned) total++);

								/*[T2]: Hrtha edw epidi ontws einai TRUE. Ara bazw ston kataxwriti TRUE */
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'T'), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);

								/*Kai tha paw sto IF me ton kataxwriti o opoios exei kai timi. Stin if ginetai mono to patch */

							}
#line 1788 "syntax.c" /* yacc.c:1646  */
    break;

  case 23:
#line 311 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("expr", "expr >= expr");
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
								
								expression *jump_val = NewExpr(8, NULL, total + 3, NULL, 'T');
								expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');
								
								quads[total] = emit(13, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), jump_val, (unsigned) yylineno, (unsigned) total++);	
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'F'), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(25, NULL, NULL, jump_val2, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'T'), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);

								/*Kai tha paw sto IF me ton kataxwriti o opoios exei kai timi. Stin if ginetai mono to patch */

							}
#line 1808 "syntax.c" /* yacc.c:1646  */
    break;

  case 24:
#line 326 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("expr", "expr < expr");
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');

								expression *jump_val = NewExpr(8, NULL, total + 3, NULL, 'T');
								expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');
								
								quads[total] = emit(14, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), jump_val, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'F'), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(25, NULL, NULL, jump_val2, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'T'), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);

								/*Kai tha paw sto IF me ton kataxwriti o opoios exei kai timi. Stin if ginetai mono to patch */

							}
#line 1828 "syntax.c" /* yacc.c:1646  */
    break;

  case 25:
#line 341 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("expr", "expr <= expr");
								tempIncreaseAndUse();
								(yyval.expressionValue) = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');

								expression *jump_val = NewExpr(8, NULL, total + 3, NULL, 'T');
								expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');
								
								quads[total] = emit(12, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), jump_val, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'F'), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(25, NULL, NULL, jump_val2, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'T'), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);

								/*Kai tha paw sto IF me ton kataxwriti o opoios exei kai timi. Stin if ginetai mono to patch */

							}
#line 1848 "syntax.c" /* yacc.c:1646  */
    break;

  case 26:
#line 356 "syntax.y" /* yacc.c:1646  */
    { 
									messageHandler("expr", "expr == expr");
									tempIncreaseAndUse();
									(yyval.expressionValue) = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');

									expression *jump_val = NewExpr(8, NULL, total + 3, NULL, 'T');
									expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');
									
									quads[total] = emit(10, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), jump_val, (unsigned) yylineno, (unsigned) total++);
									quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'F'), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
									quads[total] = emit(25, NULL, NULL, jump_val2, (unsigned) yylineno, (unsigned) total++);
									quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'T'), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);

									/*Kai tha paw sto IF me ton kataxwriti o opoios exei kai timi. Stin if ginetai mono to patch */

								}
#line 1869 "syntax.c" /* yacc.c:1646  */
    break;

  case 27:
#line 372 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("expr", "expr != expr");
									tempIncreaseAndUse();
									(yyval.expressionValue) = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');

									expression *jump_val = NewExpr(8, NULL, total + 3, NULL, 'T');
									expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');
									
									quads[total] = emit(11, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue), jump_val, (unsigned) yylineno, (unsigned) total++);
									quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'F'), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
									quads[total] = emit(25, NULL, NULL, jump_val2, (unsigned) yylineno, (unsigned) total++);
									quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'T'), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);

									/*Kai tha paw sto IF me ton kataxwriti o opoios exei kai timi. Stin if ginetai mono to patch */

								}
#line 1889 "syntax.c" /* yacc.c:1646  */
    break;

  case 28:
#line 387 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("expr", "expr AND expr");
								tempIncreaseAndUse();
								
								/* Epembasi */ 
								SymbolTableEntry *result = SymTable_get(oSymTable, currentTemp);
								expression *jump_val = NewExpr(8, NULL, total + 4, NULL, 'T');
								expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');
								expression *jump_val3 = NewExpr(8, NULL, total + 5, NULL, 'T');
								expression *true_val = NewExpr(9, NULL, 0, NULL, 'T');
								expression *false_val = NewExpr(9, NULL, 0, NULL, 'F');
								(yyval.expressionValue) = NewExpr(5, result, 0, NULL, 'T');


								//quads[total] = emit(7, $1, $3, $$, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(10, (yyvsp[-2].expressionValue), false_val, jump_val, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(10, (yyvsp[0].expressionValue), false_val, jump_val2, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, true_val, NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(25, NULL, NULL, jump_val3, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, false_val, NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);

							}
#line 1915 "syntax.c" /* yacc.c:1646  */
    break;

  case 29:
#line 408 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("expr", "expr OR expr"); 
								tempIncreaseAndUse();
								/* Epembasi */ 
								SymbolTableEntry *result = SymTable_get(oSymTable, currentTemp);
								expression *jump_val = NewExpr(8, NULL, total + 4, NULL, 'T');
								expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');
								expression *jump_val3 = NewExpr(8, NULL, total + 5, NULL, 'T');
								expression *true_val = NewExpr(9, NULL, 0, NULL, 'T');
								expression *false_val = NewExpr(9, NULL, 0, NULL, 'F');
								(yyval.expressionValue) = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
								
								
								//quads[total] = emit(8, $1, $3, $$, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(10, (yyvsp[-2].expressionValue), true_val, jump_val, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(10, (yyvsp[0].expressionValue), true_val, jump_val2, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, false_val, NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(25, NULL, NULL, jump_val3, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, true_val, NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
							}
#line 1939 "syntax.c" /* yacc.c:1646  */
    break;

  case 30:
#line 427 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("expr", "term"); }
#line 1945 "syntax.c" /* yacc.c:1646  */
    break;

  case 31:
#line 430 "syntax.y" /* yacc.c:1646  */
    { messageHandler("term", "(expr)");  (yyval.expressionValue) = (yyvsp[-1].expressionValue);}
#line 1951 "syntax.c" /* yacc.c:1646  */
    break;

  case 32:
#line 431 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("term", "-expr");	
													if ((yyvsp[0].expressionValue)->boolConst == 'T')
														(yyvsp[0].expressionValue)->boolConst = 'F';
													else
														(yyvsp[0].expressionValue)->boolConst = 'T';

													/* $2->numConst = 0 - $2->numConst; */ 

													tempIncreaseAndUse();
													(yyval.expressionValue) = NewExpr((yyvsp[0].expressionValue)->type, SymTable_get(oSymTable, currentTemp), (yyvsp[0].expressionValue)->numConst,  (yyvsp[0].expressionValue)->strConst, (yyvsp[0].expressionValue)->boolConst);
													quads[total] = emit(6, (yyvsp[0].expressionValue), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
												}
#line 1968 "syntax.c" /* yacc.c:1646  */
    break;

  case 33:
#line 443 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("term", "not expr");
										if ((yyvsp[0].expressionValue)->boolConst == 'T')
											(yyvsp[0].expressionValue)->boolConst = 'F';
										else
											(yyvsp[0].expressionValue)->boolConst = 'T';

										tempIncreaseAndUse();
										/* Epembasi */ 
										SymbolTableEntry *result = SymTable_get(oSymTable, currentTemp);
										expression *jump_val = NewExpr(8, NULL, total + 3, NULL, 'T');
										expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');

										expression *true_val = NewExpr(9, NULL, 0, NULL, 'T');
										expression *false_val = NewExpr(9, NULL, 0, NULL, 'F');


										(yyval.expressionValue) = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
										//quads[total] = emit(9, $2, NULL, $$, (unsigned) yylineno, (unsigned) total++);
										quads[total] = emit(10, (yyvsp[0].expressionValue), false_val, jump_val, (unsigned) yylineno, (unsigned) total++);
										quads[total] = emit(0, false_val, NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
										quads[total] = emit(25, NULL, NULL, jump_val2, (unsigned) yylineno, (unsigned) total++);
										quads[total] = emit(0, true_val, NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
									}
#line 1996 "syntax.c" /* yacc.c:1646  */
    break;

  case 34:
#line 466 "syntax.y" /* yacc.c:1646  */
    {
										SymbolTableEntry* symbol = (yyvsp[0].expressionValue)->sym;
										if (symbol && symbol->type == 3) {
											printf("Error in line %d: You cannot increase left a user defined function (%s).\n", yylineno, yylval.stringValue);
											syntax_error = 1;
										} else if (symbol && symbol->type == 4) {
											printf("Error in line %d: You cannot increase left a library function (%s).\n", yylineno, yylval.stringValue);
											syntax_error = 1;
										}
										messageHandler("term", "++yvalue");

										tempIncreaseAndUse();
										(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
										(yyvsp[0].expressionValue)->numConst++;
										quads[total] = emit(1, NewExpr(8, NULL, 1, NULL, 'T'), (yyvsp[0].expressionValue), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
										quads[total] = emit(0, (yyval.expressionValue), NULL, (yyvsp[0].expressionValue), (unsigned) yylineno, (unsigned) total++);
										(yyval.expressionValue)->numConst = (yyvsp[0].expressionValue)->numConst;

									}
#line 2020 "syntax.c" /* yacc.c:1646  */
    break;

  case 35:
#line 485 "syntax.y" /* yacc.c:1646  */
    {
						SymbolTableEntry* symbol = (yyvsp[0].expressionValue)->sym;
						if (symbol && symbol->type == 3) {
							syntax_error = 1;
							printf("Error in line %d: You cannot increase right a user defined function (%s).\n", yylineno, yylval.stringValue);
						} else if (symbol && symbol->type == 4) {
							printf("Error in line %d: You cannot increase right a library function (%s).\n", yylineno, yylval.stringValue);
							syntax_error = 1;
						}
				 }
#line 2035 "syntax.c" /* yacc.c:1646  */
    break;

  case 36:
#line 494 "syntax.y" /* yacc.c:1646  */
    {
											messageHandler("term", "lvalue++");
											tempIncreaseAndUse();
											(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
											(yyvsp[-2].expressionValue)->numConst++;
											quads[total] = emit(1, (yyvsp[-2].expressionValue), NewExpr(8, NULL, 1, NULL, 'T'), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
											quads[total] = emit(0, (yyval.expressionValue), NULL, (yyvsp[-2].expressionValue), (unsigned) yylineno, (unsigned) total++);
											(yyval.expressionValue)->numConst = (yyvsp[-2].expressionValue)->numConst;
										}
#line 2049 "syntax.c" /* yacc.c:1646  */
    break;

  case 37:
#line 503 "syntax.y" /* yacc.c:1646  */
    { 
										SymbolTableEntry* symbol = (yyvsp[0].expressionValue)->sym;
										if (symbol && symbol->type == 3) {
											syntax_error = 1;
											printf("Error in line %d: You cannot decrease left a user defined function (%s).\n", yylineno, yylval.stringValue);
										} else if (symbol && symbol->type == 4) {
											syntax_error = 1;
											printf("Error in line %d: You cannot decrease left a library function (%s).\n", yylineno, yylval.stringValue);
										}
										tempIncreaseAndUse();
										(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
										(yyvsp[0].expressionValue)->numConst--;
										quads[total] = emit(2, (yyvsp[0].expressionValue), NewExpr(8, NULL, 1, NULL, 'T'), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
										quads[total] = emit(0, (yyval.expressionValue), NULL, (yyvsp[0].expressionValue), (unsigned) yylineno, (unsigned) total++);
										(yyval.expressionValue)->numConst = (yyvsp[0].expressionValue)->numConst;
										messageHandler("term", "--lvalue");	
									}
#line 2071 "syntax.c" /* yacc.c:1646  */
    break;

  case 38:
#line 520 "syntax.y" /* yacc.c:1646  */
    {
						SymbolTableEntry* symbol = (yyvsp[0].expressionValue)->sym;
						if (symbol && symbol->type == 3) {
							syntax_error = 1;
							printf("Error in line %d: You cannot decrease right a user defined function (%s).\n", yylineno, yylval.stringValue);
						} else if (symbol && symbol->type == 4) {
							printf("Error in line %d: You cannot decrease right a library function (%s).\n", yylineno, yylval.stringValue);
							syntax_error = 1;
						}
				 }
#line 2086 "syntax.c" /* yacc.c:1646  */
    break;

  case 39:
#line 529 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("term", "lvalue++");	
											tempIncreaseAndUse();
											(yyval.expressionValue) = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
											(yyvsp[-2].expressionValue)->numConst--;
											quads[total] = emit(2, (yyvsp[-2].expressionValue), NewExpr(8, NULL, 1, NULL, 'T'), (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
											quads[total] = emit(0, (yyval.expressionValue), NULL, (yyvsp[-2].expressionValue), (unsigned) yylineno, (unsigned) total++);
											(yyval.expressionValue)->numConst = (yyvsp[-2].expressionValue)->numConst;
										}
#line 2099 "syntax.c" /* yacc.c:1646  */
    break;

  case 40:
#line 538 "syntax.y" /* yacc.c:1646  */
    { 
					messageHandler("term", "primary");
					/* Periptwsi gia pinaka GET */
					if ((yyval.expressionValue)->index != NULL && (yyval.expressionValue)->type == 1) {
						total++;
						(yyval.expressionValue) = emit_if_table((yyval.expressionValue), 23, oSymTable, scope, yylineno, NULL, (unsigned) yylineno, &total, quads, &temp_counter);
					} else
						(yyval.expressionValue) = (yyvsp[0].expressionValue);
				}
#line 2113 "syntax.c" /* yacc.c:1646  */
    break;

  case 41:
#line 549 "syntax.y" /* yacc.c:1646  */
    {
						/* printf("Checking if [%s] is a library function or function\n", yylval.stringValue); */
						SymbolTableEntry* symbol = (yyvsp[0].expressionValue)->sym;
						if (symbol && symbol->type == 3) { 
							syntax_error = 1;
							printf("Error in line %d: You cannot use a user defined function in assignment expresion.\n", yylineno);
						}
						else if (symbol && symbol->type == 4) {
							syntax_error = 1;
							printf("Error in line %d: You cannot use a library function in assignment expresion.\n", yylineno);
						}
					 }
#line 2130 "syntax.c" /* yacc.c:1646  */
    break;

  case 42:
#line 561 "syntax.y" /* yacc.c:1646  */
    { 
						messageHandler("assignexpr", "lvalue = expr");

						/* Periptwsi anathesis metablitis se metabliti */
						if (syntax_error == 0 && (yyvsp[0].expressionValue)->type == 0 && (yyvsp[-3].expressionValue)->index == NULL) {
							(yyval.expressionValue)->sym = (yyvsp[-3].expressionValue)->sym;
							quads[total] = emit(0, (yyvsp[0].expressionValue), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
						}

						/* Periptwsi aplis anathesis const rvalue*/
						if (syntax_error == 0 && ((yyvsp[0].expressionValue)->type == 8 || (yyvsp[0].expressionValue)->type == 10) && (yyval.expressionValue)->index == NULL) {
							(yyval.expressionValue) = (yyvsp[-3].expressionValue);
							if ((yyvsp[0].expressionValue)->type == 8) {
								(yyval.expressionValue)->numConst = (yyvsp[0].expressionValue)->numConst;
							}
							else	{
								(yyval.expressionValue)->strConst = _strdup((yyvsp[0].expressionValue)->strConst);
							}

							quads[total] = emit(0, (yyvsp[0].expressionValue), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
						}

						/* Periptwsi aplis anathesis const boolean */
						if (syntax_error == 0 && (yyvsp[0].expressionValue)->type == 9 && (yyval.expressionValue)->index == NULL)
						{
							(yyval.expressionValue) = (yyvsp[-3].expressionValue);
							(yyval.expressionValue)->boolConst = (yyvsp[0].expressionValue)->boolConst;
							quads[total] = emit(0, (yyvsp[0].expressionValue), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
						}
						/*Periptwsi pou to rvalue htan arithmetic*/
						if (syntax_error == 0 && (yyvsp[0].expressionValue)->type == 4 && (yyvsp[-3].expressionValue)->index == NULL) {
							(yyval.expressionValue) = (yyvsp[-3].expressionValue);
							/* set_result($$, $4); Edw gia tin 5h fash mallon tha thelei result */
							quads[total] = emit(0, (yyvsp[0].expressionValue), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
						}

						/*Periptwsi pou to rvalue htan  ena table*/
						if (syntax_error == 0 && (yyvsp[0].expressionValue)->type == 7) {
							(yyval.expressionValue) = (yyvsp[-3].expressionValue);
							(yyval.expressionValue)->boolConst = 'T';
							(yyval.expressionValue)->index = (yyvsp[0].expressionValue)->index;
							quads[total] = emit(0, (yyvsp[0].expressionValue), NULL, (yyval.expressionValue), yylineno, total++);
						}

						/* Periptwsi pou to rvalue einai indexed apo table  */
						if (syntax_error == 0 && (yyvsp[0].expressionValue)->type == 1) {
							quads[total] = emit(0, (yyvsp[0].expressionValue), NULL, (yyval.expressionValue), (unsigned) yylineno, (unsigned) total++);
						}

						/*Periptwsi poy to lvalue einai index emelent kai prepei na ginei set*/
						if (syntax_error == 0 && (yyvsp[-3].expressionValue)->type == 1 && (yyval.expressionValue)->index != NULL) {
							total++;
							(yyval.expressionValue) = emit_if_table((yyval.expressionValue), 24, oSymTable, scope, yylineno, (yyvsp[0].expressionValue), (unsigned) yylineno, &total, quads, &temp_counter);
							quads[total] = emit(24, (yyval.expressionValue), NewExpr(1, NULL, (yyval.expressionValue)->numConst, (yyval.expressionValue)->strConst, 'T'), (yyvsp[0].expressionValue), (unsigned) yylineno, (unsigned) total++);
						}

						/* Periptwsi poy to rvalue einai func call */
						if (syntax_error == 0 && (yyvsp[0].expressionValue)->type == 2) {
							quads[total] = emit(0, (yyvsp[0].expressionValue), NULL, (yyvsp[-3].expressionValue), (unsigned) yylineno, (unsigned) total++);
							(yyval.expressionValue) = (yyvsp[-3].expressionValue);
						}

						/* Periptwsi poy to rvalue einai boolean expression */
						if (syntax_error == 0 && (yyvsp[0].expressionValue)->type == 5) {
							quads[total] = emit(0, (yyvsp[0].expressionValue), NULL, (yyvsp[-3].expressionValue), (unsigned) yylineno, (unsigned) total++);
							(yyval.expressionValue) = (yyvsp[-3].expressionValue);
						}

					 }
#line 2204 "syntax.c" /* yacc.c:1646  */
    break;

  case 43:
#line 632 "syntax.y" /* yacc.c:1646  */
    {  messageHandler("primary", "lvalue");	(yyval.expressionValue) = (yyvsp[0].expressionValue);}
#line 2210 "syntax.c" /* yacc.c:1646  */
    break;

  case 44:
#line 633 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("primary", "call");
								if (syntax_error == 0 && (yyvsp[0].expressionValue)->type == 2 || (yyvsp[0].expressionValue)->type == 3) {
									tempIncreaseAndUse();
									expression *ret_val = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
									quads[total] = emit(19, NULL, NULL, ret_val, (unsigned) yylineno, (unsigned) total++);
									(yyval.expressionValue) = ret_val;
								}else
									(yyval.expressionValue) = (yyvsp[0].expressionValue);
							}
#line 2224 "syntax.c" /* yacc.c:1646  */
    break;

  case 45:
#line 642 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("primary", "objectdef");
								quads[total] = emit(22, NULL, NULL, (yyvsp[0].expressionValue), (unsigned) yylineno, (unsigned) total++);
								expression *tmp = (yyvsp[0].expressionValue)->index;
								while (tmp != NULL) {
									if (tmp->index == NULL || tmp->type == 7)
										quads[total] = emit(24, (yyvsp[0].expressionValue), tmp, NewExpr(8, NULL, 0, 0, 'F'), yylineno, total++);
									else
										quads[total] = emit(24, (yyvsp[0].expressionValue), tmp, tmp->index, yylineno, total++);
									tmp = tmp->next;
								}
								(yyval.expressionValue) = (yyvsp[0].expressionValue);
							}
#line 2241 "syntax.c" /* yacc.c:1646  */
    break;

  case 46:
#line 654 "syntax.y" /* yacc.c:1646  */
    {
												messageHandler("primary", "(funcdef)");
												quads[total] = emit(21, NULL, NULL, (yyvsp[-1].expressionValue), yylineno, total++);
												(yyval.expressionValue) = (yyvsp[-1].expressionValue);
											}
#line 2251 "syntax.c" /* yacc.c:1646  */
    break;

  case 47:
#line 659 "syntax.y" /* yacc.c:1646  */
    { messageHandler("primary", "const");	(yyval.expressionValue) = (yyvsp[0].expressionValue);}
#line 2257 "syntax.c" /* yacc.c:1646  */
    break;

  case 48:
#line 662 "syntax.y" /* yacc.c:1646  */
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
#line 2292 "syntax.c" /* yacc.c:1646  */
    break;

  case 49:
#line 692 "syntax.y" /* yacc.c:1646  */
    { 
								/* Periptwsh pou briskomaste sto Global Scope */
								if (scope_lookup(yylval.stringValue, scope) == 0 && scope == 0) {
									SymTable_put(oSymTable, yylval.stringValue, 0, scope, yylineno, 1);
								} else if (scope_lookup(yylval.stringValue, scope) == 0 && scope != 0) {
									SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
									if (symbol && symbol->type == 4) {
										printf("Error in line %d: You cannot use a library function name as a local variable.\n", yylineno);
										syntax_error = 1;
									} else
										SymTable_put(oSymTable, yylval.stringValue, 1, scope, yylineno, 1);
								}

								(yyval.expressionValue) = NewExpr(0, SymTable_get(oSymTable, yylval.stringValue), 0, NULL, 'F');
								messageHandler("lvalue", "local_identifier"); 
							}
#line 2313 "syntax.c" /* yacc.c:1646  */
    break;

  case 50:
#line 708 "syntax.y" /* yacc.c:1646  */
    {
									if (scope_lookup(yylval.stringValue, 0) == 0) {
										syntax_error = 1;
										printf("Error in line %d: Not found global symbol with name [%s].\n", yylineno, yylval.stringValue);
									}

									(yyval.expressionValue) = NewExpr(0, SymTable_get(oSymTable, yylval.stringValue), 0, NULL, 'F');
									messageHandler("lvalue", ":: identifier");
								}
#line 2327 "syntax.c" /* yacc.c:1646  */
    break;

  case 51:
#line 717 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("lvalue", "member");
							(yyval.expressionValue) = (yyvsp[0].expressionValue);
							expression *temp = (yyvsp[0].expressionValue);
						}
#line 2336 "syntax.c" /* yacc.c:1646  */
    break;

  case 52:
#line 724 "syntax.y" /* yacc.c:1646  */
    {		messageHandler("member", "lvalue.identifier");
					if ((yyvsp[-2].expressionValue)->type == 0)
						(yyval.expressionValue) = push_index_back((yyvsp[-2].expressionValue), NewExpr(1, NULL, 0, yylval.stringValue, 'T'));
					else if ((yyvsp[-2].expressionValue)->type == 1)
						(yyval.expressionValue) = push_index_back((yyval.expressionValue), NewExpr(1, NULL, 0, yylval.stringValue, 'T'));
			  }
#line 2347 "syntax.c" /* yacc.c:1646  */
    break;

  case 53:
#line 731 "syntax.y" /* yacc.c:1646  */
    {		messageHandler("member", "lvalue[expr]");
					if ((yyvsp[-3].expressionValue)->type == 0)
						(yyval.expressionValue) = push_index_back((yyvsp[-3].expressionValue), (yyvsp[-1].expressionValue));
					else if ((yyvsp[-3].expressionValue)->type == 1)
						(yyval.expressionValue) = push_index_back((yyval.expressionValue), (yyvsp[-1].expressionValue));
			  }
#line 2358 "syntax.c" /* yacc.c:1646  */
    break;

  case 54:
#line 738 "syntax.y" /* yacc.c:1646  */
    {		messageHandler("member", "call.identifier");
					if ((yyvsp[-2].expressionValue)->type == 0)
						(yyval.expressionValue) = push_index_back((yyvsp[-2].expressionValue), NewExpr(1, NULL, 0, yylval.stringValue, 'T'));
					else if ((yyvsp[-2].expressionValue)->type == 1)
						(yyval.expressionValue) = push_index_back((yyval.expressionValue), NewExpr(1, NULL, 0, yylval.stringValue, 'T'));

					tempIncreaseAndUse();
					SymbolTableEntry* symbol = SymTable_get(oSymTable, currentTemp);
					expression *retval_keeper = NewExpr(2, symbol, 0, NULL, 'T');

					quads[total] = emit(19, NULL, NULL, retval_keeper, yylineno, total++);

					tempIncreaseAndUse();
					symbol = SymTable_get(oSymTable, currentTemp);
					expression *getter = NewExpr(1, symbol, 0, NULL, 'T');
					quads[total] = emit(23, retval_keeper, NewExpr(1, NULL, 0, yylval.stringValue, 'T'), getter, yylineno, total++);
					(yyvsp[-2].expressionValue)->sym = symbol;
			  }
#line 2381 "syntax.c" /* yacc.c:1646  */
    break;

  case 55:
#line 757 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("member", "[expr]");
					if ((yyvsp[-3].expressionValue)->type == 0)
						(yyval.expressionValue) = push_index_back((yyvsp[-3].expressionValue), (yyvsp[-1].expressionValue));
					else if ((yyvsp[-3].expressionValue)->type == 1)
						(yyval.expressionValue) = push_index_back((yyval.expressionValue), (yyvsp[-1].expressionValue));

					tempIncreaseAndUse();
					SymbolTableEntry* symbol = SymTable_get(oSymTable, currentTemp);
					expression *retval_keeper = NewExpr(2, symbol, 0, NULL, 'T');

					quads[total] = emit(19, NULL, NULL, retval_keeper, yylineno, total++);

					tempIncreaseAndUse();
					symbol = SymTable_get(oSymTable, currentTemp);
					expression *getter = NewExpr(1, symbol, 0, NULL, 'T');
					quads[total] = emit(23, retval_keeper, (yyvsp[-1].expressionValue), getter, yylineno, total++);
		}
#line 2403 "syntax.c" /* yacc.c:1646  */
    break;

  case 56:
#line 776 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("call", "call(elist)");

														tempIncreaseAndUse();
														SymbolTableEntry* symbol = SymTable_get(oSymTable, currentTemp);
														expression *retval_keeper = NewExpr(2, symbol, 0, NULL, 'T');

														quads[total] = emit(19, NULL, NULL, retval_keeper, yylineno, total++);
														
														expression *tmp = (yyvsp[-1].expressionValue);
														while (tmp != NULL) {
															quads[total] = emit(17, NULL, NULL, tmp, yylineno, total++);
															tmp = tmp->next;
														}
														
														quads[total] = emit(16, NULL, NULL, retval_keeper, yylineno, total++);

														(yyval.expressionValue) = retval_keeper;
													}
#line 2426 "syntax.c" /* yacc.c:1646  */
    break;

  case 57:
#line 794 "syntax.y" /* yacc.c:1646  */
    {
										messageHandler("call", "lvalue callsuffix");

										/* Periptwsi pou to lvalue htan member */
										// printf("Hello indexed element:%s with type %d.\n", $1->sym->varVal->name, $1->type);
										if ((yyvsp[-1].expressionValue)->index != NULL) {
											(yyvsp[-1].expressionValue) = emit_if_table((yyvsp[-1].expressionValue), 23, oSymTable, scope, yylineno, NULL, yylineno, &total, quads, &temp_counter);
										}



										if ((yyvsp[0].expressionValue) && (yyvsp[0].expressionValue)->type == 1 && (yyvsp[0].expressionValue)->sym->type != 3) {
											expression *tmp = (yyvsp[0].expressionValue);
											while (tmp != NULL) {
												quads[total] = emit(17, NULL, NULL, tmp, yylineno, total++);
												tmp = tmp->next;
											}

											quads[total] = emit(16, NULL, NULL, (yyvsp[-1].expressionValue), yylineno, total++);
										}
										else if ((yyvsp[0].expressionValue) && (yyvsp[0].expressionValue)->type == 1 && (yyvsp[0].expressionValue)->sym->type == 3) {
											tempIncreaseAndUse();
											SymbolTableEntry* symbol = SymTable_get(oSymTable, currentTemp);
											expression *last_keeper = NewExpr(2, symbol, 0, NULL, 'T');
											quads[total] = emit(23, (yyvsp[-1].expressionValue), (yyvsp[0].expressionValue), last_keeper, yylineno, total++);
											expression *tmp = (yyvsp[0].expressionValue); 
											tmp->sym = (yyvsp[-1].expressionValue)->sym; /* Edw settarw to symbolo tou prwtou stoixeiou stin elist na einai to onoma to table object */
											tmp->type = 2;
											while (tmp != NULL) {
												quads[total] = emit(17, NULL, NULL, tmp, yylineno, total++);
												tmp = tmp->next;
											}
											(yyvsp[-1].expressionValue) = last_keeper;
											quads[total] = emit(16, NULL, NULL, last_keeper, yylineno, total++);

										} else if ((yyvsp[0].expressionValue) && (yyvsp[0].expressionValue)->type != 1){
											expression *tmp = (yyvsp[0].expressionValue);
											while (tmp != NULL) {
												quads[total] = emit(17, NULL, NULL, tmp, yylineno, total++);
												tmp = tmp->next;
											}

											quads[total] = emit(16, NULL, NULL, (yyvsp[-1].expressionValue), yylineno, total++);
										} else {
											quads[total] = emit(16, NULL, NULL, (yyvsp[-1].expressionValue), yylineno, total++);
										}

										/*Prepei na doume ama yparxei h synartisi kai an yparxei na thesoume sto expression to katalilo sym */
										(yyval.expressionValue) = (yyvsp[-1].expressionValue);

										/* Periptwsi normal klisis */
										if ((yyval.expressionValue)->sym && (yyval.expressionValue)->sym->varVal && SymTable_get(oSymTable, (yyval.expressionValue)->sym->varVal->name)) {
											(yyval.expressionValue)->type = 2;
										} else if ((yyval.expressionValue)->sym && (yyval.expressionValue)->sym->funcVal && SymTable_get(oSymTable, (yyval.expressionValue)->sym->funcVal->name)) {
											/* Periptwsi lib */
											if (SymTable_get(oSymTable, (yyval.expressionValue)->sym->funcVal->name)->type == 4)
												(yyval.expressionValue)->type = 3;
											/* Periptwsi user function */
											else
												(yyval.expressionValue)->type = 2;
										}

									}
#line 2494 "syntax.c" /* yacc.c:1646  */
    break;

  case 58:
#line 858 "syntax.y" /* yacc.c:1646  */
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
#line 2513 "syntax.c" /* yacc.c:1646  */
    break;

  case 59:
#line 874 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("callsuffix", "normcall");	 (yyval.expressionValue) = (yyvsp[0].expressionValue); }
#line 2519 "syntax.c" /* yacc.c:1646  */
    break;

  case 60:
#line 875 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("callsuffix", "methodcall"); (yyval.expressionValue) = (yyvsp[0].expressionValue);  }
#line 2525 "syntax.c" /* yacc.c:1646  */
    break;

  case 61:
#line 878 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("normcall", "(elist)");	(yyval.expressionValue) = (yyvsp[-1].expressionValue); }
#line 2531 "syntax.c" /* yacc.c:1646  */
    break;

  case 62:
#line 882 "syntax.y" /* yacc.c:1646  */
    {
													SymbolTableEntry *symbol = SymTable_get(oSymTable, (yyvsp[-3].stringValue));
													if (symbol == NULL) {
														SymTable_put(oSymTable, (yyvsp[-3].stringValue), 3, scope, yylineno, 1);
														symbol = SymTable_get(oSymTable, (yyvsp[-3].stringValue));
													}
													messageHandler("methodcall", "..identifier(elist)");
													expression *key_expr = NewExpr(1, symbol, 0, NULL, 'T');
													key_expr->next = (yyvsp[-1].expressionValue);
													(yyval.expressionValue) = key_expr;
												}
#line 2547 "syntax.c" /* yacc.c:1646  */
    break;

  case 63:
#line 895 "syntax.y" /* yacc.c:1646  */
    {
									messageHandler("elist", "expr comma-expressions");
									(yyval.expressionValue) = push_back((yyvsp[0].expressionValue), (yyvsp[-1].expressionValue));
								}
#line 2556 "syntax.c" /* yacc.c:1646  */
    break;

  case 64:
#line 899 "syntax.y" /* yacc.c:1646  */
    { messageHandler("elist", "'e'");	(yyval.expressionValue) = NULL;}
#line 2562 "syntax.c" /* yacc.c:1646  */
    break;

  case 65:
#line 902 "syntax.y" /* yacc.c:1646  */
    { 
					messageHandler("comma-expressions", ", expr comma-expressions");
					(yyval.expressionValue) = push_back((yyvsp[0].expressionValue), (yyvsp[-1].expressionValue));
		}
#line 2571 "syntax.c" /* yacc.c:1646  */
    break;

  case 66:
#line 906 "syntax.y" /* yacc.c:1646  */
    { messageHandler("comma-expressions", "'e'");	(yyval.expressionValue) = NULL;}
#line 2577 "syntax.c" /* yacc.c:1646  */
    break;

  case 67:
#line 910 "syntax.y" /* yacc.c:1646  */
    {
					messageHandler("objectdef", "[elist]");
					tempIncreaseAndUse();
					(yyval.expressionValue) = NewExpr(7, SymTable_get(oSymTable, currentTemp), 0, NULL, 'F');
					(yyval.expressionValue)->index = (yyvsp[-1].expressionValue);
			  }
#line 2588 "syntax.c" /* yacc.c:1646  */
    break;

  case 68:
#line 917 "syntax.y" /* yacc.c:1646  */
    {	
				messageHandler("objectdef", "[indexed]");
				tempIncreaseAndUse();
				(yyval.expressionValue) = NewExpr(7, SymTable_get(oSymTable, currentTemp), 0, NULL, 'F');
				(yyval.expressionValue)->index = (yyvsp[-1].expressionValue);
			}
#line 2599 "syntax.c" /* yacc.c:1646  */
    break;

  case 69:
#line 925 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("indexed", "indexedelem commaindex");	
											(yyval.expressionValue) = push_back((yyvsp[0].expressionValue), (yyvsp[-1].expressionValue));
										}
#line 2607 "syntax.c" /* yacc.c:1646  */
    break;

  case 70:
#line 930 "syntax.y" /* yacc.c:1646  */
    { messageHandler("commaindex", ", indexedelem commaindex");
												  (yyval.expressionValue) = push_back((yyvsp[0].expressionValue), (yyvsp[-1].expressionValue));
		}
#line 2615 "syntax.c" /* yacc.c:1646  */
    break;

  case 71:
#line 933 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("commaindex", "'e'");	(yyval.expressionValue) = NULL;}
#line 2621 "syntax.c" /* yacc.c:1646  */
    break;

  case 72:
#line 937 "syntax.y" /* yacc.c:1646  */
    {
				messageHandler("indexedelem", "{expr:expr}");
				(yyvsp[-3].expressionValue)->index = (yyvsp[-1].expressionValue);
				(yyval.expressionValue) = (yyvsp[-3].expressionValue);
			 }
#line 2631 "syntax.c" /* yacc.c:1646  */
    break;

  case 73:
#line 944 "syntax.y" /* yacc.c:1646  */
    {++scope; if (function_flag == 1) function_flag = 0;}
#line 2637 "syntax.c" /* yacc.c:1646  */
    break;

  case 74:
#line 945 "syntax.y" /* yacc.c:1646  */
    {
				hide(scope--); 
				messageHandler("block", "{stmts}"); 
			}
#line 2646 "syntax.c" /* yacc.c:1646  */
    break;

  case 75:
#line 951 "syntax.y" /* yacc.c:1646  */
    {func_locals_sum[scope] = 0; ++scope; function_flag = 1;}
#line 2652 "syntax.c" /* yacc.c:1646  */
    break;

  case 76:
#line 952 "syntax.y" /* yacc.c:1646  */
    {
				hide(scope--); 
				function_flag = 0;
				messageHandler("funblock", "{stmts}"); 
			}
#line 2662 "syntax.c" /* yacc.c:1646  */
    break;

  case 77:
#line 959 "syntax.y" /* yacc.c:1646  */
    {		/* Dhmiourgeia anonymous function */
								char tmp[3];
								memset(tmp, '\0', 3);
								memset(funcName, '\0', 8);
								strcpy(funcName, "@fnc");
								sprintf(tmp, "%d", function_counter++);
								strcat(funcName, tmp);
								SymTable_put(oSymTable, funcName, 3, scope, yylineno, 1);

								SymbolTableEntry* symbol = SymTable_get(oSymTable, funcName);
								function_expression[scope] = NewExpr(2, symbol, total, NULL, 'T');

								/*Edw ftiaxnw to unupdated jump */
								function_expression[scope]->next = NewExpr(0, NULL, -1, NULL, 'T');
								quads[total] = emit(25, NULL, NULL, function_expression[scope]->next, yylineno, total++);
								quads[total] = emit(20, NULL, NULL, function_expression[scope], yylineno, total++);
						  }
#line 2684 "syntax.c" /* yacc.c:1646  */
    break;

  case 78:
#line 977 "syntax.y" /* yacc.c:1646  */
    {		messageHandler("funcdef", "function (idlist) funblock");

								(yyval.expressionValue) = function_expression[scope];
								function_expression[scope]->next->numConst = total + 1;
								expression *traverser = function_expression[scope]->next->next;
								while (traverser != NULL) {
									traverser->numConst = total;
									traverser = traverser->next;
								}

								(yyval.expressionValue)->next = NULL;
								/*Prepei na parei to symbolo tis anonymous function. Na synipologizontai ta locals. Pou tha kratiountai?*/
						  }
#line 2702 "syntax.c" /* yacc.c:1646  */
    break;

  case 79:
#line 990 "syntax.y" /* yacc.c:1646  */
    {
								/* Kanoume tous antistoixous elegxous gia errors kai edw */
								/* printf("Checking if FUNCTION [%s] is allowed.\n", yylval.stringValue); */
								SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);

								if (scope_lookup(yylval.stringValue, scope) == 1) {
									syntax_error = 1;
									printf("Error in line %d: Redefinition of function symbol [%s].\n", yylineno, yylval.stringValue);
								} else if (symbol && symbol->type == 4) {
									printf("Error in line %d: User and Library Function name collision [%s].\n", yylineno, yylval.stringValue);
									syntax_error = 1;
								}else
									SymTable_put(oSymTable, yylval.stringValue, 3, scope, yylineno, 1);
								
								symbol = SymTable_get(oSymTable, yylval.stringValue);

								function_expression[scope] = NewExpr(2, symbol, total, NULL, 'T');

								/*Edw ftiaxnw to unupdated jump */
								function_expression[scope]->next = NewExpr(0, NULL, -1, NULL, 'T');
								quads[total] = emit(25, NULL, NULL, function_expression[scope]->next, yylineno, total++);
								quads[total] = emit(20, NULL, NULL, function_expression[scope], yylineno, total++);

							}
#line 2731 "syntax.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1014 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("funcdef", "function identifier (idlist) funblock");
														(yyval.expressionValue) = function_expression[scope];
														function_expression[scope]->next->numConst = total + 1;
														expression *traverser = function_expression[scope]->next->next;
														while (traverser != NULL) {
															traverser->numConst = total;
															traverser = traverser->next;
														}

														(yyval.expressionValue)->next = NULL;
												   }
#line 2747 "syntax.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1027 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("const", "real_value");
							if ((yyvsp[0].realValue) == 0)
								(yyval.expressionValue) = NewExpr(8, NULL, (yyvsp[0].realValue), NULL, 'F');
							else
								(yyval.expressionValue) = NewExpr(8, NULL, (yyvsp[0].realValue), NULL, 'T');
						}
#line 2758 "syntax.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1033 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("const", "integer_value");
							if ((yyvsp[0].integerValue) == 0)
								(yyval.expressionValue) = NewExpr(8, NULL, (yyvsp[0].integerValue), NULL, 'F');
							else
								(yyval.expressionValue) = NewExpr(8, NULL, (yyvsp[0].integerValue), NULL, 'T');
						}
#line 2769 "syntax.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1039 "syntax.y" /* yacc.c:1646  */
    { 
							messageHandler("const", "string");
							if (strcmp( (yyvsp[0].stringValue), "") == 0)
								(yyval.expressionValue) = NewExpr(10, NULL, 0, (yyvsp[0].stringValue), 'F');
							else
								(yyval.expressionValue) = NewExpr(10, NULL, 0, (yyvsp[0].stringValue), 'T');
						}
#line 2781 "syntax.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1046 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "nil");	(yyval.expressionValue) = NewExpr(11, NULL, 0, NULL, 'F');}
#line 2787 "syntax.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1047 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "true");	(yyval.expressionValue) = NewExpr(9, NULL, 0, NULL, 'T');}
#line 2793 "syntax.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1048 "syntax.y" /* yacc.c:1646  */
    { messageHandler("const", "false");	(yyval.expressionValue) = NewExpr(9, NULL, 0, NULL, 'F');}
#line 2799 "syntax.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1051 "syntax.y" /* yacc.c:1646  */
    {
						/* Theloume na anevasoume to scope apo twra. Giati tha anhkoun sto body ths synarthshs */
						/* To prwto mpainei panta ektos ama einai library */
						SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
						if (symbol && symbol->type == 4) {
							syntax_error = 1;
							printf("Error in line %d: Formal Argument name collision with Library function [%s].\n", yylineno, yylval.stringValue);
						} else {
							SymTable_put(oSymTable, yylval.stringValue, 2, scope + 1, yylineno, 1);
						}
					}
#line 2815 "syntax.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1062 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idlist", "identifier idwithcommas");	}
#line 2821 "syntax.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1063 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idlist", "'e'");		}
#line 2827 "syntax.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1066 "syntax.y" /* yacc.c:1646  */
    {
									/* To idio kai edw alla tsekaroume kai gia idio name sto scope */
									SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
									if (symbol && symbol->type == 4) {
										syntax_error = 1;
										printf("Error in line %d: Formal Argument name collision with Library function [%s].\n", yylineno, yylval.stringValue);
									} else if (scope_lookup(yylval.stringValue, scope + 1) == 1) {
										syntax_error = 1;
										printf("Error in line %d: Formal Argument redefinition [%s].\n", yylineno, yylval.stringValue);
									} else {
										SymTable_put(oSymTable, yylval.stringValue, 2, scope + 1, yylineno, 1);
									}
								 }
#line 2845 "syntax.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1079 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idwithcommas", ", identifier idwithcommas");		}
#line 2851 "syntax.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1080 "syntax.y" /* yacc.c:1646  */
    { messageHandler("idwithcommas", "'e'");		}
#line 2857 "syntax.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1083 "syntax.y" /* yacc.c:1646  */
    {
					
				expression *true_val = NewExpr(9, NULL, 0, NULL, 'T');
				expression *true_jump = NewExpr(8, NULL, total + 2, NULL, 'T');

				quads[total] = emit(10, (yyvsp[-1].expressionValue), true_val, true_jump, yylineno, total++);	/* H TRUE periptwsi ok*/

				expression *false_jump = NewExpr(8, NULL, -1, NULL, 'T');				/*H FALSE tha ginei patch stin ifstmt*/
				quads[total] = emit(25, NULL, NULL, false_jump, yylineno, total++);

				(yyval.expressionValue) = false_jump;
			}
#line 2874 "syntax.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1098 "syntax.y" /* yacc.c:1646  */
    {						
																messageHandler("ifstmt", "if (expr) stmt");
																/* Update */
																(yyvsp[-1].expressionValue)->numConst = total;
															}
#line 2884 "syntax.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1103 "syntax.y" /* yacc.c:1646  */
    {
																expression *false_jump = NewExpr(8, NULL, -1, NULL, 'T'); 
																if (quads[currQuad].op == 25)
																	quads[currQuad].result->numConst = total;

																quads[total] = emit(25, NULL, NULL, false_jump, yylineno, total++);
																currQuad = total;
															}
#line 2897 "syntax.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1111 "syntax.y" /* yacc.c:1646  */
    {
																messageHandler("ifstmt", "if (expr) stmt else stmt");
																/* Update to jump pou pigainei sto else */
																(yyvsp[-4].expressionValue)->numConst = currQuad;

																/* Update to jump pou bgainei apo to if kai diapernaei to else */
																quads[currQuad].result->numConst = total;
															}
#line 2910 "syntax.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1121 "syntax.y" /* yacc.c:1646  */
    {loop_stack[loop_i++] = total;}
#line 2916 "syntax.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1121 "syntax.y" /* yacc.c:1646  */
    { 
				messageHandler("whilestmt", "while (exrpr) stmt");	

				/* Update */
				(yyvsp[-1].expressionValue)->numConst = total + 1;

				/* Update ta Breaks */
				for (BreakList *tmp = b_list[loop_i - 1]; tmp != NULL; tmp = tmp->next) {
					printf("Updating break!\n");
					tmp->jump_quad->result->numConst = total + 1;
				}

				/* Update ta Continues */
				for (ContinueList *tmp = c_list[loop_i - 1]; tmp != NULL; tmp = tmp->next) {
					printf("Updating continue!\n");
					tmp->jump_quad->result->numConst = loop_stack[loop_i - 1];
				}

				/* Clearing Break List */
				b_list[loop_i - 1] = NULL;

				/* Clearing Continue List */
				c_list[loop_i - 1] = NULL;

				/* Last Jump to loop beginner offset */
				(yyval.expressionValue) = NewExpr(0, NULL, loop_stack[--loop_i], NULL, 'T');
				quads[total] = emit(25, NULL, NULL, (yyval.expressionValue), yylineno, total++);
			 }
#line 2949 "syntax.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1151 "syntax.y" /* yacc.c:1646  */
    {
					expression *true_val = NewExpr(9, NULL, 0, NULL, 'T');
					expression *true_jump = NewExpr(8, NULL, total + 2, NULL, 'T');

					quads[total] = emit(10, (yyvsp[0].expressionValue), true_val, true_jump, yylineno, total++);	/* H TRUE periptwsi ok*/

					expression *false_jump = NewExpr(8, NULL, -1, NULL, 'T');				/*H FALSE tha ginei patch stin ifstmt*/
					quads[total] = emit(25, NULL, NULL, false_jump, yylineno, total++);

					(yyval.expressionValue) = false_jump;
			}
#line 2965 "syntax.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1164 "syntax.y" /* yacc.c:1646  */
    {loop_stack[loop_i++]= total;}
#line 2971 "syntax.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1165 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("forstmt", "for (elist expr; expr; elist) stmt");
				/* Update */
				(yyvsp[-4].expressionValue)->numConst = total + 1;

				/* Update ta Breaks */
				for (BreakList *tmp = b_list[loop_i - 1]; tmp != NULL; tmp = tmp->next) {
					printf("Updating break!\n");
					tmp->jump_quad->result->numConst = total + 1;
				}

				/* Update ta Continues */
				for (ContinueList *tmp = c_list[loop_i - 1]; tmp != NULL; tmp = tmp->next) {
					printf("Updating continue!\n");
					tmp->jump_quad->result->numConst = loop_stack[loop_i - 1];
				}

				/* Clearing Break List */
				b_list[loop_i - 1] = NULL;

				/* Clearing Continue List */
				c_list[loop_i - 1] = NULL;


				/* Last Jump to loop beginner offset */
				(yyval.expressionValue) = NewExpr(0, NULL, loop_stack[--loop_i], NULL, 'T');
				quads[total] = emit(25, NULL, NULL, (yyval.expressionValue), yylineno, total++);
			}
#line 3003 "syntax.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1194 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("returnstmt", "return;");

											/* Dhmiourgia incompleted Jump */
											expression *false_jump = NewExpr(8, NULL, -1, NULL, 'T');
											assert(function_expression[scope - 1]->next);

											/* Push sthn lista twn return tis function */
											if (function_expression[scope - 1] == NULL)
												function_expression[scope - 2]->next = push_back(function_expression[scope - 2]->next, false_jump);
											else
												function_expression[scope - 1]->next = push_back(function_expression[scope - 1]->next, false_jump);

											(yyval.expressionValue) = NewExpr(11, NULL, 0, NULL, 'F');
											
											quads[total] = emit(18, NULL, NULL, (yyval.expressionValue), yylineno, total++);
											quads[total] = emit(25, NULL, NULL, false_jump, yylineno, total++);
										}
#line 3025 "syntax.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1211 "syntax.y" /* yacc.c:1646  */
    {	messageHandler("returnstmt", "return expr;");

											/* Dhmiourgia incompleted Jump */
											expression *false_jump = NewExpr(8, NULL, -1, NULL, 'T');

											/* Push sthn lista twn return tis function */
											if (function_expression[scope - 1] == NULL)
												function_expression[scope - 2]->next = push_back(function_expression[scope - 2]->next, false_jump);
											else
												function_expression[scope - 1]->next = push_back(function_expression[scope - 1]->next, false_jump);
											(yyval.expressionValue) = (yyvsp[-1].expressionValue);
											
											quads[total] = emit(18, NULL, NULL, (yyval.expressionValue), yylineno, total++);
											quads[total] = emit(25, NULL, NULL, false_jump, yylineno, total++);
										}
#line 3045 "syntax.c" /* yacc.c:1646  */
    break;


#line 3049 "syntax.c" /* yacc.c:1646  */
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
#line 1227 "syntax.y" /* yacc.c:1906  */


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

	for (int i = 0; i < 72; i++) {
		func_locals_sum[i] = 0;
		function_expression[i] = NULL;
		b_list[i] = NULL;
		c_list[i] = NULL;
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

	if (syntax_error == 0) {
		//printQuads();
		transform(quads);
		final_code();
	}


	return 0;
}
