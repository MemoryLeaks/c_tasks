/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 27 "syntax.y" /* yacc.c:1909  */

		char *stringValue;
		int integerValue;
		double realValue;

#line 172 "syntax.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_H_INCLUDED  */
