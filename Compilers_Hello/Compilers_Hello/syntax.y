%{
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

%token  MY_ID
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

stmts	: stmt { temp_counter = 0; } stmts	{ messageHandler("statements", "stmt statements");	}
		| /*empty*/		{ messageHandler("statements", "'e'");	}
		;


stmt		: expr MY_SEMICOLON		{ messageHandler("stmt", "expr;");	}
		| ifstmt			{ messageHandler("stmt", "ifstmt");	}
		| whilestmt			{ messageHandler("stmt", "whilestmt");	}
		| forstmt			{ messageHandler("stmt", "forstmt");	}
		| returnstmt			{ messageHandler("stmt", "returnstmt");	}
		| MY_BREAK MY_SEMICOLON		{ messageHandler("stmt", "break;");	}
		| MY_CONTINUE MY_SEMICOLON	{ messageHandler("stmt", "continue;");	}
		| block				{ messageHandler("stmt", "block");	}
		| funcdef			{ messageHandler("stmt", "funcdef");
							  quads[total] = emit(21, NULL, NULL, $1, yylineno, total++);
							}
		| MY_SEMICOLON			{ messageHandler("stmt", ";");	}
		;

expr	: assignexpr 		{ messageHandler("expr", "assignexpr");		}
		| expr MY_PLUS expr	{ 
								messageHandler("expr", "expr + expr");
								tempIncreaseAndUse();
								$$ = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
								quads[total] = emit(1, $1, $3, $$, (unsigned) yylineno, (unsigned) total++);

							}
		| expr MY_MINUS expr	{ 
									messageHandler("expr", "expr - expr");
									tempIncreaseAndUse();
									$$ = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
									quads[total] = emit(2, $1, $3, $$, (unsigned) yylineno, (unsigned) total++);
								}
		| expr MY_MUL expr	{ 
								messageHandler("expr", "expr * expr"); 
								tempIncreaseAndUse();
								$$ = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
								quads[total] = emit(3, $1, $3, $$, (unsigned) yylineno, (unsigned) total++);
							}
		| expr MY_DIV expr	{
								messageHandler("expr", "expr * expr"); 
								tempIncreaseAndUse();
								$$ = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
								quads[total] = emit(4, $1, $3, $$, (unsigned) yylineno, (unsigned) total++);
								messageHandler("expr", "expr / expr");
							}
		| expr MY_MOD expr	{ 
								messageHandler("expr", "expr % expr");
								tempIncreaseAndUse();
								$$ = NewExpr(4, SymTable_get(oSymTable, currentTemp), 0, NULL, 0);
								quads[total] = emit(5, $1, $3, $$, (unsigned) yylineno, (unsigned) total++);
								messageHandler("expr", "expr / expr");
							}
		| expr MY_G expr	{ messageHandler("expr", "expr > expr"); }
		| expr MY_GE expr	{ messageHandler("expr", "expr >= expr"); }
		| expr MY_L expr	{ messageHandler("expr", "expr < expr"); }
		| expr MY_LE expr	{ messageHandler("expr", "expr <= expr"); }
		| expr MY_EQUAL expr	{ messageHandler("expr", "expr == expr"); }
		| expr MY_NEQUAL expr	{ messageHandler("expr", "expr != expr"); }
		| expr MY_AND expr	{ messageHandler("expr", "expr AND expr"); }
		| expr MY_OR expr	{ messageHandler("expr", "expr OR expr"); }
		| term					{ messageHandler("expr", "term");	}
		;

term		: MY_OPEN_PAR expr MY_CLOSE_PAR		{ messageHandler("term", "(expr)");  $$ = $2;}
		| MY_MINUS expr	%prec UNARY_MINUS		{	messageHandler("term", "-expr");	
													if ($2->boolConst == 'T')
														$2->boolConst = 'F';
													else
														$2->boolConst = 'T';

													$$ = $2;
												}
		| MY_NOT expr				{	messageHandler("term", "not expr");
										if ($2->boolConst == 'T')
											$2->boolConst = 'F';
										else
											$2->boolConst = 'T';

										$$ = $2;
									}
		| MY_INC lvalue				{
										SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
										if (symbol && symbol->type == 3)
											printf("Error in line %d: You cannot increase left a user defined function (%s).\n", yylineno, yylval.stringValue);
										else if (symbol && symbol->type == 4)
											printf("Error in line %d: You cannot increase left a library function (%s).\n", yylineno, yylval.stringValue);
										messageHandler("term", "++yvalue");

										$2->numConst++;
										$$ = $2;

									}
		| lvalue {
						SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
						if (symbol && symbol->type == 3)
							printf("Error in line %d: You cannot increase right a user defined function (%s).\n", yylineno, yylval.stringValue);
						else if (symbol && symbol->type == 4)
							printf("Error in line %d: You cannot increase right a library function (%s).\n", yylineno, yylval.stringValue);
				 } MY_INC				{
											messageHandler("term", "lvalue++");
											$1->numConst++;
											$$ = $1;
										}
		| MY_DEC lvalue				{ 
										SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
										if (symbol && symbol->type == 3)
											printf("Error in line %d: You cannot decrease left a user defined function (%s).\n", yylineno, yylval.stringValue);
										else if (symbol && symbol->type == 4)
											printf("Error in line %d: You cannot decrease left a library function (%s).\n", yylineno, yylval.stringValue);
										
										$2->numConst--;
										$$ = $2;
										messageHandler("term", "--lvalue");	
									}
		| lvalue {
						SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
						if (symbol && symbol->type == 3)
							printf("Error in line %d: You cannot decrease right a user defined function (%s).\n", yylineno, yylval.stringValue);
						else if (symbol && symbol->type == 4)
							printf("Error in line %d: You cannot decrease right a library function (%s).\n", yylineno, yylval.stringValue);
				 } MY_DEC				{	messageHandler("term", "lvalue++");	
											$1->numConst--;
											$$ = $1;
										}
		| primary
				{ 
					messageHandler("term", "primary");
					/* Periptwsi gia pinaka GET */
					if ($$->index != NULL && $$->type == 0) {
						table_stack_trace_index = -1;
						total++;
						$$ = emit_if_table($$, 23, oSymTable, scope, yylineno, NULL, (unsigned) yylineno, &total, quads);
					}
				}
		;

assignexpr	: lvalue {
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
					 } MY_ASSIGN expr 
					 { 
						messageHandler("assignexpr", "lvalue = expr");

						/* Periptwsi anathesis metablitis se metabliti */
						if (syntax_error == 0 && $4->type == 0) {
							$$->sym = $1->sym;
							quads[total] = emit(0, $4, NULL, $$, (unsigned) yylineno, (unsigned) total++);
						}

						/* Periptwsi aplis anathesis const rvalue*/
						if (syntax_error == 0 && ($4->type == 8 || $4->type == 10)) {
							$$ = $1;
							$$->type = 6;
							if ($4-> type == 8) $$->numConst = $4->numConst;
							else	$$->strConst = _strdup($4->strConst);

							quads[total] = emit(0, $4, NULL, $$, (unsigned) yylineno, (unsigned) total++);
						}

						/*Periptwsi pou to rvalue htan arithmetic*/
						if (syntax_error == 0 && $4->type == 4) {
							$$ = $1;
							$$->type = 6;
							/* set_result($$, $4); Edw gia tin 5h fash mallon tha thelei result */
							quads[total] = emit(0, $4, NULL, $$, (unsigned) yylineno, (unsigned) total++);
						}

						/*Periptwsi pou to rvalue htan  ena table*/
						if (syntax_error == 0 && $4->type == 7) {
							$$ = $1;
							$$->boolConst = 'T';
							$$->type = 7;
							$$->next = $4->next; /* O deiktis ousiastika deixnei ston pinaka */
							quads[total] = emit(22, $4, NULL, $$, (unsigned) yylineno, (unsigned) total++);
						}


						/* Periptwsi pou to rvalue einai indexed apo table  */
						if (syntax_error == 0 && $4->type == 23) {
							table_stack_trace_index = -1;
							quads[total] = emit(0, $4, NULL, $$, (unsigned) yylineno, (unsigned) total++);
						}

						/*Periptwsi poy to lvalue einai index emelent kai prepei na ginei set*/
						if (syntax_error == 0 && $$->index != NULL) {
							table_stack_trace_index = -1;
							total++;
							$$ = emit_if_table($$, 24, oSymTable, scope, yylineno, $4, (unsigned) yylineno, &total, quads);
							quads[total] = emit(24, $$, NewExpr(1, NULL, 0, $$->strConst, 'T'), $4, (unsigned) yylineno, (unsigned) total++);
						}

					 }
			;

primary		: lvalue		{  messageHandler("primary", "lvalue");	}
		| call			{ messageHandler("primary", "call");		}
		| objectdef		{ messageHandler("primary", "objectdef");	}
		| MY_OPEN_PAR funcdef MY_CLOSE_PAR	{ messageHandler("primary", "(funcdef)");	}
		| const					{ messageHandler("primary", "const");		}
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
									if (symbol && symbol->type == 4)
										printf("Error in line %d: You cannot use a library function name as a local variable.\n", yylineno);
									else
										SymTable_put(oSymTable, yylval.stringValue, 1, scope, yylineno, 1);
								}

								messageHandler("lvalue", "local_identifier"); 
							}
		| MY_DOT_STREAM MY_ID	{
									if (scope_lookup(yylval.stringValue, 0) == 0) {
										printf("Error in line %d: Not found global symbol with name [%s].\n", yylineno, yylval.stringValue);
									}
									messageHandler("lvalue", ":: identifier");
								}
		| member		{ messageHandler("lvalue", "member");		}
		;

member		: lvalue MY_DOT_SIMPLE MY_ID		
			  {		messageHandler("member", "lvalue.identifier");
					if (table_stack_trace_index == -1) {
						$$ = NewExpr(0, $1->sym, 0, NULL, 'T');
						$$->index = NewExpr(1, NULL, 0, yylval.stringValue, 'T');
						table_stack_trace_index++;
					}
					else if (table_stack_trace_index == 0) {
						$$ = push_index_back($$, NewExpr(1, NULL, 0, yylval.stringValue, 'T'));
					}
			  }
		| lvalue MY_OPEN_BRA expr MY_CLOSE_BRA  
		  { messageHandler("member", "lvalue[expr]");
			if (table_stack_trace_index == -1) {
				$$ = NewExpr(0, $1->sym, 0, NULL, 'T');
				$$->index = NewExpr(1, NULL, 0, yylval.stringValue, 'T');
				table_stack_trace_index++;
			}
			else if (table_stack_trace_index == 0) {
				$$ = push_index_back($$, NewExpr(1, NULL, 0, yylval.stringValue, 'T'));
			}
		  }
		| call MY_DOT_SIMPLE MY_ID		{ messageHandler("member", "call.identifier");	}
		| call MY_OPEN_BRA expr MY_CLOSE_BRA	{ messageHandler("member", "[expr]");		}
		;

call		: call MY_OPEN_PAR elist MY_CLOSE_PAR	{ messageHandler("call", "call(elist)");	}
		| lvalue callsuffix			{ messageHandler("call", "lvalue callsuffix");	}
		| MY_OPEN_PAR funcdef MY_CLOSE_PAR MY_OPEN_PAR elist MY_CLOSE_PAR { messageHandler("call", "(funcdef)(elist)");	}
		;

callsuffix	: normcall	{ messageHandler("callsuffix", "normcall");	}
		| methodcall	{ messageHandler("callsuffix", "methodcall");	}
		;

normcall	: MY_OPEN_PAR elist MY_CLOSE_PAR	{ messageHandler("normcall", "(elist)");	}
		;

methodcall	: MY_DOT_DOUBLE MY_ID MY_OPEN_PAR elist MY_CLOSE_PAR { messageHandler("methodcall", "..identifier(elist)");	}
		;

elist		: expr commaexprs	{
									messageHandler("elist", "expr comma-expressions");
									$1->type = 1;
									table_stack[table_stack_index] = push_back(table_stack[table_stack_index], $1);
									printf("To do emmit in table: %s.\n", getExpressionValue($1));
								}
		| /*empty*/		{ messageHandler("elist", "'e'");		}
		;

commaexprs	: MY_COMMA expr commaexprs { 
					messageHandler("comma-expressions", ", expr comma-expressions");
					$2->type = 1;
					table_stack[table_stack_index] = push_back(table_stack[table_stack_index], $2);
					printf("To do emmit in table: %s.\n", getExpressionValue($2));
			}
		| /*empty*/		   { messageHandler("comma-expressions", "'e'");	}
		;

objectdef	: MY_OPEN_BRA {table_stack_index++;} elist MY_CLOSE_BRA	
			  {
					messageHandler("objectdef", "[elist]");
					$$ = NewExpr(7, NULL, 0, NULL, 'F');
					$$->next = table_stack[table_stack_index];
					table_stack[table_stack_index--] = NULL;
			  }
		| MY_OPEN_BRA {table_stack_index++;} indexed MY_CLOSE_BRA	
			{	
				messageHandler("objectdef", "[indexed]");
				$$ = NewExpr(7, NULL, 0, NULL, 'F');
				$$->next = table_stack[table_stack_index];
				table_stack[table_stack_index--] = NULL;
			}
		;

indexed		: indexedelem commaindex	{ messageHandler("indexed", "indexedelem commaindex");		}
		;

commaindex	: MY_COMMA indexedelem commaindex	{ messageHandler("commaindex", ", indexedelem commaindex");		}
		| /*empty*/				{ messageHandler("commaindex", "'e'");		}
		;

indexedelem	: MY_OPEN_ANG expr MY_DOT_UD expr MY_CLOSE_ANG		
			 {
				messageHandler("indexedelem", "{expr:expr}");
				$2->type = 1;
				table_stack[table_stack_index] = push_back(table_stack[table_stack_index], $2);
				$2->index = $4;
				printf("To do emmit in table {%s : %s}.\n", getExpressionValue($2), getExpressionValue($4));
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
								function_expression[scope] = NewExpr(2, symbol, 666 + all_func_counter, NULL, 'T');
								quads[total] = emit(20, NULL, NULL, function_expression[scope], yylineno, total++);
								all_func_counter++;
						  } 
			  MY_OPEN_PAR idlist MY_CLOSE_PAR funblock   
						  {		messageHandler("funcdef", "function (idlist) funblock");
								function_expression[scope] += func_locals_sum[scope];
								$$ = function_expression[scope];
								/*Prepei na parei to symbolo tis anonymous function. Na synipologizontai ta locals. Pou tha kratiountai?*/
						  }
		| MY_FUNCTION MY_ID {
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
		  MY_OPEN_PAR idlist MY_CLOSE_PAR funblock {	messageHandler("funcdef", "function identifier (idlist) funblock");
														function_expression[scope] += func_locals_sum[scope];
														$$ = function_expression[scope];
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
		| MY_NIL	{ messageHandler("const", "nil");	}
		| MY_TRUE	{ messageHandler("const", "true");	}
		| MY_FALSE	{ messageHandler("const", "false");	}
		;

idlist		: MY_ID {
						/* Theloume na anevasoume to scope apo twra. Giati tha anhkoun sto body ths synarthshs */
						/* To prwto mpainei panta ektos ama einai library */
						SymbolTableEntry* symbol = SymTable_get(oSymTable, yylval.stringValue);
						if (symbol && symbol->type == 4) {
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
										printf("Error in line %d: Formal Argument name collision with Library function [%s].\n", yylineno, yylval.stringValue);
									} else if (scope_lookup(yylval.stringValue, scope + 1) == 1) {
										printf("Error in line %d: Formal Argument redefinition [%s].\n", yylineno, yylval.stringValue);
									} else {
										SymTable_put(oSymTable, yylval.stringValue, 2, scope + 1, yylineno, 1);
									}
								 } 
				  idwithcommas	{ messageHandler("idwithcommas", ", identifier idwithcommas");		}
				| /*empty*/			{ messageHandler("idwithcommas", "'e'");		}
				;

ifstmt          : MY_IF MY_OPEN_PAR expr MY_CLOSE_PAR stmt		{ messageHandler("ifstmt", "if (expr) stmt");	}
				| MY_IF MY_OPEN_PAR expr MY_CLOSE_PAR stmt MY_ELSE stmt { messageHandler("ifstmt", "if (expr) stmt else stmt");	}
				;

whilestmt	: MY_WHILE MY_OPEN_PAR expr MY_CLOSE_PAR stmt		{ messageHandler("whilestmt", "while (exrpr) stmt");	}
		;

forstmt		: MY_FOR MY_OPEN_PAR elist MY_SEMICOLON expr MY_SEMICOLON elist MY_CLOSE_PAR stmt 
			{ messageHandler("forstmt", "for (elist expr; expr; elist) stmt");	}
		;

returnstmt	: MY_RETURN MY_SEMICOLON	{ messageHandler("returnstmt", "return;");		}
		| MY_RETURN expr MY_SEMICOLON	{ messageHandler("returnstmt", "return expr;");		}
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
