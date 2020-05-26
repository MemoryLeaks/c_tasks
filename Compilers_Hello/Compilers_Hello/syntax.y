%{
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
			SymTable_put(oSymTable, currentTemp, 0, scope, yylineno, 1);
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

%}




%start program


%union
{
		char *stringValue;
		int integerValue;
		double realValue;
		expression *expressionValue;
}

%token  <integerValue> MY_INTEGER
%token  <realValue> MY_REAL
%token <stringValue> MY_STRING

%type <expressionValue> expr
%type <expressionValue> assignexpr
%type <expressionValue> term
%type <expressionValue> lvalue
%type <expressionValue> const
%type <expressionValue> primary
%type <expressionValue> objectdef
%type <expressionValue> elist
%type <expressionValue> commaexprs
%type <expressionValue> indexed
%type <expressionValue> commaindex
%type <expressionValue> indexedelem
%type <expressionValue> member
%type <expressionValue> funcdef
%type <expressionValue> callsuffix
%type <expressionValue> normcall
%type <expressionValue> call
%type <expressionValue> stmt
%type <expressionValue> stmts
%type <expressionValue> block
%type <expressionValue> methodcall
%type <expressionValue> whilestmt
%type <expressionValue> forstmt
%type <expressionValue> ifinside
%type <expressionValue> forinside
%type <expressionValue> returnstmt


%token MY_MULTILINE_COMMENTS
%token MY_SIMPLE_COMMENTS

%token  MY_IF
%token	MY_ELSE
%token  MY_FOR
%token	MY_WHILE
%token	MY_DO
%token  MY_CONTINUE
%token  MY_BREAK
%token	MY_RETURN

%token  MY_AND
%token  MY_OR
%token  MY_NOT

%token	MY_LOCAL
%token  MY_GLOBAL
%token  MY_STATIC
%token  MY_NIL
%token  MY_TRUE
%token  MY_FALSE
%token  MY_FUNCTION

%token  <stringValue> MY_ID
%token  MY_BLANK
%token  MY_NL

%token  MY_ASSIGN
%token  MY_EQUAL
%token  MY_NEQUAL
%token  MY_PLUS
%token  MY_INC
%token  MY_MINUS
%token  MY_DEC
%token  MY_MUL
%token  MY_DIV
%token  MY_MOD
%token  MY_L
%token  MY_LE
%token  MY_G
%token  MY_GE

%token  MY_OPEN_ANG
%token  MY_OPEN_BRA
%token  MY_OPEN_PAR
%token  MY_CLOSE_ANG
%token  MY_CLOSE_BRA
%token  MY_CLOSE_PAR
%token  MY_DOT_UD
%token  MY_DOT_STREAM
%token  MY_DOT_SIMPLE
%token  MY_DOT_DOUBLE
%token  MY_COMMA
%token  MY_SEMICOLON

%token	MY_OTHER

%expect 1/* Einai to dangling IF kai ta OPERATORS*/


/*---------- Priorities	-----------*/

%right                  MY_ASSIGN

%left                   MY_OR MY_AND

%nonassoc               MY_EQUAL        MY_NEQUAL

%nonassoc               MY_G            MY_GE           MY_L            MY_LE

%left                   MY_PLUS         MY_MINUS

%left                   MY_MUL          MY_DIV          MY_MOD

%right                  MY_NOT          MY_INC          MY_DEC			UNARY_MINUS

%left                   MY_DOT_SIMPLE   MY_DOT_DOUBLE

%left                   MY_OPEN_BRA     MY_CLOSE_BRA

%right                  MY_OPEN_PAR     MY_CLOSE_PAR

%%

program		: stmts	{ messageHandler("program", "statements");	}
		;

stmts	: stmt { if (function_flag == 0) temp_counter = 0; } stmts	{ messageHandler("statements", "stmt statements");	}
		| /*empty*/		{ messageHandler("statements", "'e'");	}
		;


stmt		: expr MY_SEMICOLON		{ messageHandler("stmt", "expr;");	$$ = NewExpr(0, NULL, total, NULL, 'T');}
		| ifstmt			{ messageHandler("stmt", "ifstmt");	$$ = NewExpr(0, NULL, total, NULL, 'T');}
		| whilestmt			{ messageHandler("stmt", "whilestmt");	$$ = NewExpr(0, NULL, total, NULL, 'T');}
		| forstmt			{ messageHandler("stmt", "forstmt");	$$ = NewExpr(0, NULL, total, NULL, 'T');}
		| returnstmt			{ messageHandler("stmt", "returnstmt");	}
		| MY_BREAK MY_SEMICOLON	{	messageHandler("stmt", "break;");
									if (loop_i - 1 < 0) {
										printf("Error in line %d: Break found out of loop!\n", yylineno);
										syntax_error = 1;
									}
									else {
										/* Kanoume emit to unpatched Quad */
										expression *break_jump = NewExpr(8, NULL, -2, NULL, 'T');
										quads[total] = emit(25, NULL, NULL, break_jump, yylineno, total++);

										$$ = break_jump;
										//printf("What about %f ?\n", quads[total].result->numConst);

										/* Mpainei mesa to Break */
										b_list[loop_i - 1] = push_BreakList(b_list[loop_i - 1], &quads[total]);
									}
		}
		| MY_CONTINUE MY_SEMICOLON	{	messageHandler("stmt", "continue;"); 
										if (loop_i - 1 < 0) {
											printf("Error in line %d: Continue found out of loop!\n", yylineno);
											syntax_error = 1;
										}
										else {
											/* Kanoume emit to unpatched Quad */
											expression *cont_jump = NewExpr(8, NULL, -2, NULL, 'T');
											quads[total] = emit(25, NULL, NULL, cont_jump, yylineno, total++);

											$$ = cont_jump;
											//printf("What about %f ?\n", quads[total].result->numConst);

											/* Mpainei mesa to Continue */
											c_list[loop_i - 1] = push_ContinueList(c_list[loop_i - 1], &quads[total]);
										}
		}
		| block				{ messageHandler("stmt", "block");	$$ = $1;}
		| funcdef			{ messageHandler("stmt", "funcdef");
							  quads[total] = emit(21, NULL, NULL, $1, yylineno, total++);
							  $$ = $1;
							}
		| MY_SEMICOLON			{ messageHandler("stmt", ";");	}
		;

expr	: assignexpr 		{ messageHandler("expr", "assignexpr");	}
		| expr MY_PLUS expr	{ 
								messageHandler("expr", "expr + expr");
								tempIncreaseAndUse();
								$$ = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
								quads[total] = emit(1, $1, $3, $$, (unsigned) yylineno, (unsigned) total++);

							}
		| expr MY_MINUS expr	{ 
									messageHandler("expr", "expr - expr");
									tempIncreaseAndUse();
									$$ = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
									quads[total] = emit(2, $1, $3, $$, (unsigned) yylineno, (unsigned) total++);
								}
		| expr MY_MUL expr	{ 
								messageHandler("expr", "expr * expr"); 
								tempIncreaseAndUse();
								$$ = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
								quads[total] = emit(3, $1, $3, $$, (unsigned) yylineno, (unsigned) total++);
							}
		| expr MY_DIV expr	{
								messageHandler("expr", "expr * expr"); 
								tempIncreaseAndUse();
								$$ = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
								quads[total] = emit(4, $1, $3, $$, (unsigned) yylineno, (unsigned) total++);
								messageHandler("expr", "expr / expr");
							}
		| expr MY_MOD expr	{ 
								messageHandler("expr", "expr % expr");
								tempIncreaseAndUse();
								$$ = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
								quads[total] = emit(5, $1, $3, $$, (unsigned) yylineno, (unsigned) total++);
								messageHandler("expr", "expr / expr");
							}
		| expr MY_G expr	{	messageHandler("expr", "expr > expr"); 
								tempIncreaseAndUse();
								$$ = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
								
								expression *jump_val = NewExpr(8, NULL, total + 3, NULL, 'T');
								expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');

								/*[T1]: If Greater paw 2 grammes katw  na to kanw T*/
								quads[total] = emit(15, $1, $3, jump_val, (unsigned) yylineno, (unsigned) total++);
								
								/*[F1]: Den einai greater ara kanw ton kataxwriti FALSE */
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'F'), NULL, $$, (unsigned) yylineno, (unsigned) total++);
								
								/*[F2]: Kai kanw Jump me tin FALSE timi*/
								quads[total] = emit(25, NULL, NULL, jump_val2, (unsigned) yylineno, (unsigned) total++);

								/*[T2]: Hrtha edw epidi ontws einai TRUE. Ara bazw ston kataxwriti TRUE */
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'T'), NULL, $$, (unsigned) yylineno, (unsigned) total++);

								/*Kai tha paw sto IF me ton kataxwriti o opoios exei kai timi. Stin if ginetai mono to patch */

							}
		| expr MY_GE expr	{	messageHandler("expr", "expr >= expr");
								tempIncreaseAndUse();
								$$ = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
								
								expression *jump_val = NewExpr(8, NULL, total + 3, NULL, 'T');
								expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');
								
								quads[total] = emit(13, $1, $3, jump_val, (unsigned) yylineno, (unsigned) total++);	
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'F'), NULL, $$, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(25, NULL, NULL, jump_val2, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'T'), NULL, $$, (unsigned) yylineno, (unsigned) total++);

								/*Kai tha paw sto IF me ton kataxwriti o opoios exei kai timi. Stin if ginetai mono to patch */

							}
		| expr MY_L expr	{	messageHandler("expr", "expr < expr");
								tempIncreaseAndUse();
								$$ = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');

								expression *jump_val = NewExpr(8, NULL, total + 3, NULL, 'T');
								expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');
								
								quads[total] = emit(14, $1, $3, jump_val, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'F'), NULL, $$, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(25, NULL, NULL, jump_val2, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'T'), NULL, $$, (unsigned) yylineno, (unsigned) total++);

								/*Kai tha paw sto IF me ton kataxwriti o opoios exei kai timi. Stin if ginetai mono to patch */

							}
		| expr MY_LE expr	{	messageHandler("expr", "expr <= expr");
								tempIncreaseAndUse();
								$$ = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');

								expression *jump_val = NewExpr(8, NULL, total + 3, NULL, 'T');
								expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');
								
								quads[total] = emit(12, $1, $3, jump_val, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'F'), NULL, $$, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(25, NULL, NULL, jump_val2, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'T'), NULL, $$, (unsigned) yylineno, (unsigned) total++);

								/*Kai tha paw sto IF me ton kataxwriti o opoios exei kai timi. Stin if ginetai mono to patch */

							}
		| expr MY_EQUAL expr	{ 
									messageHandler("expr", "expr == expr");
									tempIncreaseAndUse();
									$$ = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');

									expression *jump_val = NewExpr(8, NULL, total + 3, NULL, 'T');
									expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');
									
									quads[total] = emit(10, $1, $3, jump_val, (unsigned) yylineno, (unsigned) total++);
									quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'F'), NULL, $$, (unsigned) yylineno, (unsigned) total++);
									quads[total] = emit(25, NULL, NULL, jump_val2, (unsigned) yylineno, (unsigned) total++);
									quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'T'), NULL, $$, (unsigned) yylineno, (unsigned) total++);

									/*Kai tha paw sto IF me ton kataxwriti o opoios exei kai timi. Stin if ginetai mono to patch */

								}
		| expr MY_NEQUAL expr	{	messageHandler("expr", "expr != expr");
									tempIncreaseAndUse();
									$$ = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');

									expression *jump_val = NewExpr(8, NULL, total + 3, NULL, 'T');
									expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');
									
									quads[total] = emit(11, $1, $3, jump_val, (unsigned) yylineno, (unsigned) total++);
									quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'F'), NULL, $$, (unsigned) yylineno, (unsigned) total++);
									quads[total] = emit(25, NULL, NULL, jump_val2, (unsigned) yylineno, (unsigned) total++);
									quads[total] = emit(0, NewExpr(9, NULL, 0, NULL, 'T'), NULL, $$, (unsigned) yylineno, (unsigned) total++);

									/*Kai tha paw sto IF me ton kataxwriti o opoios exei kai timi. Stin if ginetai mono to patch */

								}
		| expr MY_AND expr	{	messageHandler("expr", "expr AND expr");
								tempIncreaseAndUse();
								
								/* Epembasi */ 
								SymbolTableEntry *result = SymTable_get(oSymTable, currentTemp);
								expression *jump_val = NewExpr(8, NULL, total + 4, NULL, 'T');
								expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');
								expression *jump_val3 = NewExpr(8, NULL, total + 5, NULL, 'T');
								expression *true_val = NewExpr(9, NULL, 0, NULL, 'T');
								expression *false_val = NewExpr(9, NULL, 0, NULL, 'F');
								$$ = NewExpr(5, result, 0, NULL, 'T');


								//quads[total] = emit(7, $1, $3, $$, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(10, $1, false_val, jump_val, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(10, $3, false_val, jump_val2, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, true_val, NULL, $$, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(25, NULL, NULL, jump_val3, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, false_val, NULL, $$, (unsigned) yylineno, (unsigned) total++);

							}
		| expr MY_OR expr	{	messageHandler("expr", "expr OR expr"); 
								tempIncreaseAndUse();
								/* Epembasi */ 
								SymbolTableEntry *result = SymTable_get(oSymTable, currentTemp);
								expression *jump_val = NewExpr(8, NULL, total + 4, NULL, 'T');
								expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');
								expression *jump_val3 = NewExpr(8, NULL, total + 5, NULL, 'T');
								expression *true_val = NewExpr(9, NULL, 0, NULL, 'T');
								expression *false_val = NewExpr(9, NULL, 0, NULL, 'F');
								$$ = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
								
								
								//quads[total] = emit(8, $1, $3, $$, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(10, $1, true_val, jump_val, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(10, $3, true_val, jump_val2, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, false_val, NULL, $$, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(25, NULL, NULL, jump_val3, (unsigned) yylineno, (unsigned) total++);
								quads[total] = emit(0, true_val, NULL, $$, (unsigned) yylineno, (unsigned) total++);
							}
		| term				{	messageHandler("expr", "term"); }
		;

term		: MY_OPEN_PAR expr MY_CLOSE_PAR		{ messageHandler("term", "(expr)");  $$ = $2;}
		| MY_MINUS expr	%prec UNARY_MINUS		{	messageHandler("term", "-expr");	
													if ($2->boolConst == 'T')
														$2->boolConst = 'F';
													else
														$2->boolConst = 'T';

													/* $2->numConst = 0 - $2->numConst; */ 

													tempIncreaseAndUse();
													$$ = NewExpr($2->type, SymTable_get(oSymTable, currentTemp), $2->numConst,  $2->strConst, $2->boolConst);
													quads[total] = emit(6, $2, NULL, $$, (unsigned) yylineno, (unsigned) total++);
												}
		| MY_NOT expr				{	messageHandler("term", "not expr");
										if ($2->boolConst == 'T')
											$2->boolConst = 'F';
										else
											$2->boolConst = 'T';

										tempIncreaseAndUse();
										/* Epembasi */ 
										SymbolTableEntry *result = SymTable_get(oSymTable, currentTemp);
										expression *jump_val = NewExpr(8, NULL, total + 3, NULL, 'T');
										expression *jump_val2 = NewExpr(8, NULL, total + 4, NULL, 'T');

										expression *true_val = NewExpr(9, NULL, 0, NULL, 'T');
										expression *false_val = NewExpr(9, NULL, 0, NULL, 'F');


										$$ = NewExpr(5, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
										//quads[total] = emit(9, $2, NULL, $$, (unsigned) yylineno, (unsigned) total++);
										quads[total] = emit(10, $2, false_val, jump_val, (unsigned) yylineno, (unsigned) total++);
										quads[total] = emit(0, false_val, NULL, $$, (unsigned) yylineno, (unsigned) total++);
										quads[total] = emit(25, NULL, NULL, jump_val2, (unsigned) yylineno, (unsigned) total++);
										quads[total] = emit(0, true_val, NULL, $$, (unsigned) yylineno, (unsigned) total++);
									}
		| MY_INC lvalue				{
										SymbolTableEntry* symbol = $2->sym;
										if (symbol && symbol->type == 3) {
											printf("Error in line %d: You cannot increase left a user defined function (%s).\n", yylineno, yylval.stringValue);
											syntax_error = 1;
										} else if (symbol && symbol->type == 4) {
											printf("Error in line %d: You cannot increase left a library function (%s).\n", yylineno, yylval.stringValue);
											syntax_error = 1;
										}
										messageHandler("term", "++yvalue");

										tempIncreaseAndUse();
										$$ = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
										$2->numConst++;
										quads[total] = emit(1, NewExpr(8, NULL, 1, NULL, 'T'), $2, $$, (unsigned) yylineno, (unsigned) total++);
										quads[total] = emit(0, $$, NULL, $2, (unsigned) yylineno, (unsigned) total++);
										$$->numConst = $2->numConst;

									}
		| lvalue {
						SymbolTableEntry* symbol = $1->sym;
						if (symbol && symbol->type == 3) {
							syntax_error = 1;
							printf("Error in line %d: You cannot increase right a user defined function (%s).\n", yylineno, yylval.stringValue);
						} else if (symbol && symbol->type == 4) {
							printf("Error in line %d: You cannot increase right a library function (%s).\n", yylineno, yylval.stringValue);
							syntax_error = 1;
						}
				 } MY_INC				{
											messageHandler("term", "lvalue++");
											tempIncreaseAndUse();
											$$ = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
											$1->numConst++;
											quads[total] = emit(1, $1, NewExpr(8, NULL, 1, NULL, 'T'), $$, (unsigned) yylineno, (unsigned) total++);
											quads[total] = emit(0, $$, NULL, $1, (unsigned) yylineno, (unsigned) total++);
											$$->numConst = $1->numConst;
										}
		| MY_DEC lvalue				{ 
										SymbolTableEntry* symbol = $2->sym;
										if (symbol && symbol->type == 3) {
											syntax_error = 1;
											printf("Error in line %d: You cannot decrease left a user defined function (%s).\n", yylineno, yylval.stringValue);
										} else if (symbol && symbol->type == 4) {
											syntax_error = 1;
											printf("Error in line %d: You cannot decrease left a library function (%s).\n", yylineno, yylval.stringValue);
										}
										tempIncreaseAndUse();
										$$ = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
										$2->numConst--;
										quads[total] = emit(2, $2, NewExpr(8, NULL, 1, NULL, 'T'), $$, (unsigned) yylineno, (unsigned) total++);
										quads[total] = emit(0, $$, NULL, $2, (unsigned) yylineno, (unsigned) total++);
										$$->numConst = $2->numConst;
										messageHandler("term", "--lvalue");	
									}
		| lvalue {
						SymbolTableEntry* symbol = $1->sym;
						if (symbol && symbol->type == 3) {
							syntax_error = 1;
							printf("Error in line %d: You cannot decrease right a user defined function (%s).\n", yylineno, yylval.stringValue);
						} else if (symbol && symbol->type == 4) {
							printf("Error in line %d: You cannot decrease right a library function (%s).\n", yylineno, yylval.stringValue);
							syntax_error = 1;
						}
				 } MY_DEC				{	messageHandler("term", "lvalue++");	
											tempIncreaseAndUse();
											$$ = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
											$1->numConst--;
											quads[total] = emit(2, $1, NewExpr(8, NULL, 1, NULL, 'T'), $$, (unsigned) yylineno, (unsigned) total++);
											quads[total] = emit(0, $$, NULL, $1, (unsigned) yylineno, (unsigned) total++);
											$$->numConst = $1->numConst;
										}
		| primary
				{ 
					messageHandler("term", "primary");
					/* Periptwsi gia pinaka GET */
					if ($$->index != NULL && $$->type == 1) {
						total++;
						$$ = emit_if_table($$, 23, oSymTable, scope, yylineno, NULL, (unsigned) yylineno, &total, quads, &temp_counter);
					} else
						$$ = $1;
				}
		;

assignexpr	: lvalue {
						/* printf("Checking if [%s] is a library function or function\n", yylval.stringValue); */
						SymbolTableEntry* symbol = $1->sym;
						if (symbol && symbol->type == 3) { 
							syntax_error = 1;
							printf("Error in line %d: You cannot use a user defined function in assignment expresion.\n", yylineno);
						}
						else if (symbol && symbol->type == 4) {
							syntax_error = 1;
							printf("Error in line %d: You cannot use a library function in assignment expresion.\n", yylineno);
						}
					 } MY_ASSIGN expr 
					 { 
						messageHandler("assignexpr", "lvalue = expr");

						/* Periptwsi anathesis metablitis se metabliti */
						if (syntax_error == 0 && $4->type == 0 && $1->index == NULL) {
							$$->sym = $1->sym;
							quads[total] = emit(0, $4, NULL, $$, (unsigned) yylineno, (unsigned) total++);
						}

						/* Periptwsi aplis anathesis const rvalue*/
						if (syntax_error == 0 && ($4->type == 8 || $4->type == 10) && $$->index == NULL) {
							$$ = $1;
							if ($4->type == 8) {
								$$->numConst = $4->numConst;
							}
							else	{
								$$->strConst = _strdup($4->strConst);
							}

							quads[total] = emit(0, $4, NULL, $$, (unsigned) yylineno, (unsigned) total++);
						}

						/* Periptwsi aplis anathesis const boolean */
						if (syntax_error == 0 && $4->type == 9 && $$->index == NULL)
						{
							$$ = $1;
							$$->boolConst = $4->boolConst;
							quads[total] = emit(0, $4, NULL, $$, (unsigned) yylineno, (unsigned) total++);
						}
						/*Periptwsi pou to rvalue htan arithmetic*/
						if (syntax_error == 0 && $4->type == 4 && $1->index == NULL) {
							$$ = $1;
							/* set_result($$, $4); Edw gia tin 5h fash mallon tha thelei result */
							quads[total] = emit(0, $4, NULL, $$, (unsigned) yylineno, (unsigned) total++);
						}

						/*Periptwsi pou to rvalue htan  ena table*/
						if (syntax_error == 0 && $4->type == 7) {
							$$ = $1;
							$$->boolConst = 'T';
							$$->index = $4->index;
							quads[total] = emit(0, $4, NULL, $$, yylineno, total++);
						}

						/* Periptwsi pou to rvalue einai indexed apo table  */
						if (syntax_error == 0 && $4->type == 1) {
							quads[total] = emit(0, $4, NULL, $$, (unsigned) yylineno, (unsigned) total++);
						}

						/*Periptwsi poy to lvalue einai index emelent kai prepei na ginei set*/
						if (syntax_error == 0 && $1->type == 1 && $$->index != NULL) {
							total++;
							$$ = emit_if_table($$, 24, oSymTable, scope, yylineno, $4, (unsigned) yylineno, &total, quads, &temp_counter);
							quads[total] = emit(24, $$, NewExpr(1, NULL, $$->numConst, $$->strConst, 'T'), $4, (unsigned) yylineno, (unsigned) total++);
						}

						/* Periptwsi poy to rvalue einai func call */
						if (syntax_error == 0 && $4->type == 2) {
							quads[total] = emit(0, $4, NULL, $1, (unsigned) yylineno, (unsigned) total++);
							$$ = $1;
						}

						/* Periptwsi poy to rvalue einai boolean expression */
						if (syntax_error == 0 && $4->type == 5) {
							quads[total] = emit(0, $4, NULL, $1, (unsigned) yylineno, (unsigned) total++);
							$$ = $1;
						}

					 }
			;

primary		: lvalue		{  messageHandler("primary", "lvalue");	$$ = $1;}
		| call				{	messageHandler("primary", "call");
								if (syntax_error == 0 && $1->type == 2 || $1->type == 3) {
									tempIncreaseAndUse();
									expression *ret_val = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 'T');
									quads[total] = emit(19, NULL, NULL, ret_val, (unsigned) yylineno, (unsigned) total++);
									$$ = ret_val;
								}else
									$$ = $1;
							}
		| objectdef			{	messageHandler("primary", "objectdef");
								quads[total] = emit(22, NULL, NULL, $1, (unsigned) yylineno, (unsigned) total++);
								expression *tmp = $1->index;
								while (tmp != NULL) {
									if (tmp->index == NULL || tmp->type == 7)
										quads[total] = emit(24, $1, tmp, NewExpr(8, NULL, 0, 0, 'F'), yylineno, total++);
									else
										quads[total] = emit(24, $1, tmp, tmp->index, yylineno, total++);
									tmp = tmp->next;
								}
								$$ = $1;
							}
		| MY_OPEN_PAR funcdef MY_CLOSE_PAR	{
												messageHandler("primary", "(funcdef)");
												quads[total] = emit(21, NULL, NULL, $2, yylineno, total++);
												$$ = $2;
											}
		| const					{ messageHandler("primary", "const");	$$ = $1;}
		;

lvalue		: MY_ID	{	
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
						$$ = NewExpr(0, SymTable_get(oSymTable, yylval.stringValue), 0, NULL, 'F');

						messageHandler("lvalue", "identifier"); 
					}
		| MY_LOCAL MY_ID	{ 
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

								$$ = NewExpr(0, SymTable_get(oSymTable, yylval.stringValue), 0, NULL, 'F');
								messageHandler("lvalue", "local_identifier"); 
							}
		| MY_DOT_STREAM MY_ID	{
									if (scope_lookup(yylval.stringValue, 0) == 0) {
										syntax_error = 1;
										printf("Error in line %d: Not found global symbol with name [%s].\n", yylineno, yylval.stringValue);
									}

									$$ = NewExpr(0, SymTable_get(oSymTable, yylval.stringValue), 0, NULL, 'F');
									messageHandler("lvalue", ":: identifier");
								}
		| member		{	messageHandler("lvalue", "member");
							$$ = $1;
							expression *temp = $1;
						}
		;

member		: lvalue MY_DOT_SIMPLE MY_ID		
			  {		messageHandler("member", "lvalue.identifier");
					if ($1->type == 0)
						$$ = push_index_back($1, NewExpr(1, NULL, 0, yylval.stringValue, 'T'));
					else if ($1->type == 1)
						$$ = push_index_back($$, NewExpr(1, NULL, 0, yylval.stringValue, 'T'));
			  }
		| lvalue MY_OPEN_BRA expr MY_CLOSE_BRA  
			  {		messageHandler("member", "lvalue[expr]");
					if ($1->type == 0)
						$$ = push_index_back($1, $3);
					else if ($1->type == 1)
						$$ = push_index_back($$, $3);
			  }
		| call MY_DOT_SIMPLE MY_ID		
			  {		messageHandler("member", "call.identifier");
					if ($1->type == 0)
						$$ = push_index_back($1, NewExpr(1, NULL, 0, yylval.stringValue, 'T'));
					else if ($1->type == 1)
						$$ = push_index_back($$, NewExpr(1, NULL, 0, yylval.stringValue, 'T'));

					tempIncreaseAndUse();
					SymbolTableEntry* symbol = SymTable_get(oSymTable, currentTemp);
					expression *retval_keeper = NewExpr(2, symbol, 0, NULL, 'T');

					quads[total] = emit(19, NULL, NULL, retval_keeper, yylineno, total++);

					tempIncreaseAndUse();
					symbol = SymTable_get(oSymTable, currentTemp);
					expression *getter = NewExpr(1, symbol, 0, NULL, 'T');
					quads[total] = emit(23, retval_keeper, NewExpr(1, NULL, 0, yylval.stringValue, 'T'), getter, yylineno, total++);
					$1->sym = symbol;
			  }
		| call MY_OPEN_BRA expr MY_CLOSE_BRA
				{	messageHandler("member", "[expr]");
					if ($1->type == 0)
						$$ = push_index_back($1, $3);
					else if ($1->type == 1)
						$$ = push_index_back($$, $3);

					tempIncreaseAndUse();
					SymbolTableEntry* symbol = SymTable_get(oSymTable, currentTemp);
					expression *retval_keeper = NewExpr(2, symbol, 0, NULL, 'T');

					quads[total] = emit(19, NULL, NULL, retval_keeper, yylineno, total++);

					tempIncreaseAndUse();
					symbol = SymTable_get(oSymTable, currentTemp);
					expression *getter = NewExpr(1, symbol, 0, NULL, 'T');
					quads[total] = emit(23, retval_keeper, $3, getter, yylineno, total++);
		}
		;

call		: call MY_OPEN_PAR elist MY_CLOSE_PAR	{	messageHandler("call", "call(elist)");

														tempIncreaseAndUse();
														SymbolTableEntry* symbol = SymTable_get(oSymTable, currentTemp);
														expression *retval_keeper = NewExpr(2, symbol, 0, NULL, 'T');

														quads[total] = emit(19, NULL, NULL, retval_keeper, yylineno, total++);
														
														expression *tmp = $3;
														while (tmp != NULL) {
															quads[total] = emit(17, NULL, NULL, tmp, yylineno, total++);
															tmp = tmp->next;
														}
														
														quads[total] = emit(16, NULL, NULL, retval_keeper, yylineno, total++);

														$$ = retval_keeper;
													}
		| lvalue callsuffix			{
										messageHandler("call", "lvalue callsuffix");

										/* Periptwsi pou to lvalue htan member */
										// printf("Hello indexed element:%s with type %d.\n", $1->sym->varVal->name, $1->type);
										if ($1->index != NULL) {
											$1 = emit_if_table($1, 23, oSymTable, scope, yylineno, NULL, yylineno, &total, quads, &temp_counter);
										}



										if ($2 && $2->type == 1 && $2->sym->type != 3) {
											expression *tmp = $2;
											while (tmp != NULL) {
												quads[total] = emit(17, NULL, NULL, tmp, yylineno, total++);
												tmp = tmp->next;
											}

											quads[total] = emit(16, NULL, NULL, $1, yylineno, total++);
										}
										else if ($2 && $2->type == 1 && $2->sym->type == 3) {
											tempIncreaseAndUse();
											SymbolTableEntry* symbol = SymTable_get(oSymTable, currentTemp);
											expression *last_keeper = NewExpr(2, symbol, 0, NULL, 'T');
											quads[total] = emit(23, $1, $2, last_keeper, yylineno, total++);
											expression *tmp = $2; 
											tmp->sym = $1->sym; /* Edw settarw to symbolo tou prwtou stoixeiou stin elist na einai to onoma to table object */
											tmp->type = 2;
											while (tmp != NULL) {
												quads[total] = emit(17, NULL, NULL, tmp, yylineno, total++);
												tmp = tmp->next;
											}
											$1 = last_keeper;
											quads[total] = emit(16, NULL, NULL, last_keeper, yylineno, total++);

										} else if ($2 && $2->type != 1){
											expression *tmp = $2;
											while (tmp != NULL) {
												quads[total] = emit(17, NULL, NULL, tmp, yylineno, total++);
												tmp = tmp->next;
											}

											quads[total] = emit(16, NULL, NULL, $1, yylineno, total++);
										} else {
											quads[total] = emit(16, NULL, NULL, $1, yylineno, total++);
										}

										/*Prepei na doume ama yparxei h synartisi kai an yparxei na thesoume sto expression to katalilo sym */
										$$ = $1;

										/* Periptwsi normal klisis */
										if ($$->sym && $$->sym->varVal && SymTable_get(oSymTable, $$->sym->varVal->name)) {
											$$->type = 2;
										} else if ($$->sym && $$->sym->funcVal && SymTable_get(oSymTable, $$->sym->funcVal->name)) {
											/* Periptwsi lib */
											if (SymTable_get(oSymTable, $$->sym->funcVal->name)->type == 4)
												$$->type = 3;
											/* Periptwsi user function */
											else
												$$->type = 2;
										}

									}
		| MY_OPEN_PAR funcdef MY_CLOSE_PAR MY_OPEN_PAR elist MY_CLOSE_PAR 
									{	messageHandler("call", "(funcdef)(elist)");
										quads[total] = emit(21, NULL, NULL, $2, yylineno, total++);
										expression *tmp = $5;
										while (tmp != NULL) {
											quads[total] = emit(17, NULL, NULL, tmp, yylineno, total++);
											tmp = tmp->next;
										}

										quads[total] = emit(16, NULL, NULL, $2, yylineno, total++);

										tempIncreaseAndUse();
										SymbolTableEntry* symbol = SymTable_get(oSymTable, currentTemp);
										$$ = NewExpr(2, symbol, 0, NULL, 'F');
									}
		;

callsuffix	: normcall	{	messageHandler("callsuffix", "normcall");	 $$ = $1; }
		|	methodcall	{	messageHandler("callsuffix", "methodcall"); $$ = $1;  }
		;

normcall	: MY_OPEN_PAR elist MY_CLOSE_PAR	{	messageHandler("normcall", "(elist)");	$$ = $2; }
		;

methodcall	: MY_DOT_DOUBLE MY_ID MY_OPEN_PAR elist MY_CLOSE_PAR 
												{
													SymbolTableEntry *symbol = SymTable_get(oSymTable, $2);
													if (symbol == NULL) {
														SymTable_put(oSymTable, $2, 3, scope, yylineno, 1);
														symbol = SymTable_get(oSymTable, $2);
													}
													messageHandler("methodcall", "..identifier(elist)");
													expression *key_expr = NewExpr(1, symbol, 0, NULL, 'T');
													key_expr->next = $4;
													$$ = key_expr;
												}
		;

elist		: expr commaexprs	{
									messageHandler("elist", "expr comma-expressions");
									$$ = push_back($2, $1);
								}
		| /*empty*/		{ messageHandler("elist", "'e'");	$$ = NULL;}
		;

commaexprs	: MY_COMMA expr commaexprs { 
					messageHandler("comma-expressions", ", expr comma-expressions");
					$$ = push_back($3, $2);
		}
		| /*empty*/		   { messageHandler("comma-expressions", "'e'");	$$ = NULL;}
		;

objectdef	: MY_OPEN_BRA elist MY_CLOSE_BRA	
			  {
					messageHandler("objectdef", "[elist]");
					tempIncreaseAndUse();
					$$ = NewExpr(7, SymTable_get(oSymTable, currentTemp), 0, NULL, 'F');
					$$->index = $2;
			  }
		| MY_OPEN_BRA indexed MY_CLOSE_BRA	
			{	
				messageHandler("objectdef", "[indexed]");
				tempIncreaseAndUse();
				$$ = NewExpr(7, SymTable_get(oSymTable, currentTemp), 0, NULL, 'F');
				$$->index = $2;
			}
		;

indexed		: indexedelem commaindex	{	messageHandler("indexed", "indexedelem commaindex");	
											$$ = push_back($2, $1);
										}
		;

commaindex	: MY_COMMA indexedelem commaindex	{ messageHandler("commaindex", ", indexedelem commaindex");
												  $$ = push_back($3, $2);
		}
		| /*empty*/				{	messageHandler("commaindex", "'e'");	$$ = NULL;}
		;

indexedelem	: MY_OPEN_ANG expr MY_DOT_UD expr MY_CLOSE_ANG		
			 {
				messageHandler("indexedelem", "{expr:expr}");
				$2->index = $4;
				$$ = $2;
			 }
		;

block		: MY_OPEN_ANG {++scope; if (function_flag == 1) function_flag = 0;} stmts MY_CLOSE_ANG 
			{
				hide(scope--); 
				messageHandler("block", "{stmts}"); 
			}
		;

funblock	: MY_OPEN_ANG {func_locals_sum[scope] = 0; ++scope; function_flag = 1;} stmts MY_CLOSE_ANG 
			{
				hide(scope--); 
				function_flag = 0;
				messageHandler("funblock", "{stmts}"); 
			}
		;

funcdef		: MY_FUNCTION {		/* Dhmiourgeia anonymous function */
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
			  MY_OPEN_PAR idlist MY_CLOSE_PAR funblock   
						  {		messageHandler("funcdef", "function (idlist) funblock");

								$$ = function_expression[scope];
								function_expression[scope]->next->numConst = total + 1;
								expression *traverser = function_expression[scope]->next->next;
								while (traverser != NULL) {
									traverser->numConst = total;
									traverser = traverser->next;
								}

								$$->next = NULL;
								/*Prepei na parei to symbolo tis anonymous function. Na synipologizontai ta locals. Pou tha kratiountai?*/
						  }
		| MY_FUNCTION MY_ID {
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
		  MY_OPEN_PAR idlist MY_CLOSE_PAR funblock {	messageHandler("funcdef", "function identifier (idlist) funblock");
														$$ = function_expression[scope];
														function_expression[scope]->next->numConst = total + 1;
														expression *traverser = function_expression[scope]->next->next;
														while (traverser != NULL) {
															traverser->numConst = total;
															traverser = traverser->next;
														}

														$$->next = NULL;
												   }
		;

const		: MY_REAL	{	messageHandler("const", "real_value");
							if ($1 == 0)
								$$ = NewExpr(8, NULL, $1, NULL, 'F');
							else
								$$ = NewExpr(8, NULL, $1, NULL, 'T');
						}
		| MY_INTEGER	{	messageHandler("const", "integer_value");
							if ($1 == 0)
								$$ = NewExpr(8, NULL, $1, NULL, 'F');
							else
								$$ = NewExpr(8, NULL, $1, NULL, 'T');
						}
		| MY_STRING		{ 
							messageHandler("const", "string");
							if (strcmp( $1, "") == 0)
								$$ = NewExpr(10, NULL, 0, $1, 'F');
							else
								$$ = NewExpr(10, NULL, 0, $1, 'T');
						}
		| MY_NIL	{ messageHandler("const", "nil");	$$ = NewExpr(11, NULL, 0, NULL, 'F');}
		| MY_TRUE	{ messageHandler("const", "true");	$$ = NewExpr(9, NULL, 0, NULL, 'T');}
		| MY_FALSE	{ messageHandler("const", "false");	$$ = NewExpr(9, NULL, 0, NULL, 'F');}
		;

idlist		: MY_ID {
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
			  idwithcommas	{ messageHandler("idlist", "identifier idwithcommas");	}
		| /*empty*/		{ messageHandler("idlist", "'e'");		}
		;

idwithcommas	: MY_COMMA MY_ID {
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
				  idwithcommas	{ messageHandler("idwithcommas", ", identifier idwithcommas");		}
				| /*empty*/			{ messageHandler("idwithcommas", "'e'");		}
				;

ifinside	:	MY_OPEN_PAR expr MY_CLOSE_PAR {
					
				expression *true_val = NewExpr(9, NULL, 0, NULL, 'T');
				expression *true_jump = NewExpr(8, NULL, total + 2, NULL, 'T');

				quads[total] = emit(10, $2, true_val, true_jump, yylineno, total++);	/* H TRUE periptwsi ok*/

				expression *false_jump = NewExpr(8, NULL, -1, NULL, 'T');				/*H FALSE tha ginei patch stin ifstmt*/
				quads[total] = emit(25, NULL, NULL, false_jump, yylineno, total++);

				$$ = false_jump;
			}
			;


ifstmt          : MY_IF ifinside stmt	{						
																messageHandler("ifstmt", "if (expr) stmt");
																/* Update */
																$2->numConst = total;
															}
				| MY_IF ifinside stmt MY_ELSE {
																expression *false_jump = NewExpr(8, NULL, -1, NULL, 'T'); 
																if (quads[currQuad].op == 25)
																	quads[currQuad].result->numConst = total;

																quads[total] = emit(25, NULL, NULL, false_jump, yylineno, total++);
																currQuad = total;
															} 
															stmt {
																messageHandler("ifstmt", "if (expr) stmt else stmt");
																/* Update to jump pou pigainei sto else */
																$2->numConst = currQuad;

																/* Update to jump pou bgainei apo to if kai diapernaei to else */
																quads[currQuad].result->numConst = total;
															}
				;

whilestmt	: MY_WHILE {loop_stack[loop_i++] = total;} ifinside stmt { 
				messageHandler("whilestmt", "while (exrpr) stmt");	

				/* Update */
				$3->numConst = total + 1;

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
				$$ = NewExpr(0, NULL, loop_stack[--loop_i], NULL, 'T');
				quads[total] = emit(25, NULL, NULL, $$, yylineno, total++);
			 }
		;

forinside	:	expr {
					expression *true_val = NewExpr(9, NULL, 0, NULL, 'T');
					expression *true_jump = NewExpr(8, NULL, total + 2, NULL, 'T');

					quads[total] = emit(10, $1, true_val, true_jump, yylineno, total++);	/* H TRUE periptwsi ok*/

					expression *false_jump = NewExpr(8, NULL, -1, NULL, 'T');				/*H FALSE tha ginei patch stin ifstmt*/
					quads[total] = emit(25, NULL, NULL, false_jump, yylineno, total++);

					$$ = false_jump;
			}
			;		 

forstmt		: MY_FOR MY_OPEN_PAR elist MY_SEMICOLON {loop_stack[loop_i++]= total;} forinside MY_SEMICOLON elist MY_CLOSE_PAR stmt 
			{	messageHandler("forstmt", "for (elist expr; expr; elist) stmt");
				/* Update */
				$6->numConst = total + 1;

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
				$$ = NewExpr(0, NULL, loop_stack[--loop_i], NULL, 'T');
				quads[total] = emit(25, NULL, NULL, $$, yylineno, total++);
			}
		;

returnstmt	: MY_RETURN MY_SEMICOLON	{	messageHandler("returnstmt", "return;");

											/* Dhmiourgia incompleted Jump */
											expression *false_jump = NewExpr(8, NULL, -1, NULL, 'T');
											assert(function_expression[scope - 1]->next);

											/* Push sthn lista twn return tis function */
											if (function_expression[scope - 1] == NULL)
												function_expression[scope - 2]->next = push_back(function_expression[scope - 2]->next, false_jump);
											else
												function_expression[scope - 1]->next = push_back(function_expression[scope - 1]->next, false_jump);

											$$ = NewExpr(11, NULL, 0, NULL, 'F');
											
											quads[total] = emit(18, NULL, NULL, $$, yylineno, total++);
											quads[total] = emit(25, NULL, NULL, false_jump, yylineno, total++);
										}
		| MY_RETURN expr MY_SEMICOLON	{	messageHandler("returnstmt", "return expr;");

											/* Dhmiourgia incompleted Jump */
											expression *false_jump = NewExpr(8, NULL, -1, NULL, 'T');

											/* Push sthn lista twn return tis function */
											if (function_expression[scope - 1] == NULL)
												function_expression[scope - 2]->next = push_back(function_expression[scope - 2]->next, false_jump);
											else
												function_expression[scope - 1]->next = push_back(function_expression[scope - 1]->next, false_jump);
											$$ = $2;
											
											quads[total] = emit(18, NULL, NULL, $$, yylineno, total++);
											quads[total] = emit(25, NULL, NULL, false_jump, yylineno, total++);
										}
		;
%%

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
