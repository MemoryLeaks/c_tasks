%{
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

%}




%start program


%union
{
		char *stringValue;
		int integerValue;
		double realValue;
}


%token MY_MULTILINE_COMMENTS
%token MY_SIMPLE_COMMENTS
%token  <string> MY_STRING

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
%token  MY_INTEGER
%token  MY_REAL

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

%expect 14 /* Einai to dangling IF kai ta OPERATORS*/


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

stmts	: stmt stmts	{ messageHandler("statements", "stmt statements");	}
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
		| funcdef			{ messageHandler("stmt", "funcdef");	}
		| MY_SEMICOLON			{ messageHandler("stmt", ";");	}
		;

expr	: assignexpr 		{ messageHandler("expr", "assignexpr");		}
		| expr operator expr	{ messageHandler("expr", "expr [operation] expr");	}
		| term					{ messageHandler("expr", "term");			}
		;

operator	: MY_PLUS
			| MY_MINUS
			| MY_MUL
			| MY_DIV
			| MY_MOD
			| MY_G
			| MY_GE
			| MY_L
			| MY_LE
			| MY_EQUAL
			| MY_NEQUAL
			| MY_AND
			| MY_OR
			;

term		: MY_OPEN_PAR expr MY_CLOSE_PAR		{ messageHandler("term", "(expr)"); }
		| MY_MINUS expr	%prec UNARY_MINUS		{ messageHandler("term", "-expr");	}
		| MY_NOT expr				{ messageHandler("term", "not expr");	}
		| MY_INC lvalue				{ messageHandler("term", "++yvalue");	}
		| lvalue MY_INC				{ messageHandler("term", "lvalue++");	}
		| MY_DEC lvalue				{ messageHandler("term", "--lvalue");	}
		| lvalue MY_DEC				{ messageHandler("term", "lvalue++");	}
		| primary				{ messageHandler("term", "primary");	}
		;

assignexpr	: lvalue MY_ASSIGN expr { messageHandler("assignexpr", "lvalue = expr");	}
			;

primary		: lvalue		{ messageHandler("primary", "lvalue");		}
		| call			{ messageHandler("primary", "call");		}
		| objectdef		{ messageHandler("primary", "objectdef");	}
		| MY_OPEN_PAR funcdef MY_CLOSE_PAR	{ messageHandler("primary", "(funcdef)");	}
		| const					{ messageHandler("primary", "const");		}
		;

lvalue		: MY_ID	{	messageHandler("lvalue", "identifier");

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
		| MY_LOCAL MY_ID	{ messageHandler("lvalue", "local_identifier"); }
		| MY_DOT_STREAM MY_ID	{ messageHandler("lvalue", ":: identifier");}
		| member		{ messageHandler("lvalue", "member");		}
		;

member		: lvalue MY_DOT_SIMPLE MY_ID		{ messageHandler("member", "lvalue.identifier");}
		| lvalue MY_OPEN_BRA expr MY_CLOSE_BRA  { messageHandler("member", "lvalue[expr]");	}
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

elist		: expr commaexprs	{ messageHandler("elist", "expr comma-expressions");		}
		| /*empty*/		{ messageHandler("elist", "'e'");		}
		;

commaexprs	: MY_COMMA expr commaexprs { messageHandler("comma-expressions", ", expr comma-expressions");	}
		| /*empty*/		   { messageHandler("comma-expressions", "'e'");	}
		;

objectdef	: MY_OPEN_BRA elist MY_CLOSE_BRA	{ messageHandler("objectdef", "[elist]");	}
		| MY_OPEN_BRA indexed MY_CLOSE_BRA	{ messageHandler("objectdef", "[indexed]");	}
		;

indexed		: indexedelem commaindex	{ messageHandler("indexed", "indexedelem commaindex");		}
		;

commaindex	: MY_COMMA indexedelem commaindex	{ messageHandler("commaindex", ", indexedelem commaindex");		}
		| /*empty*/				{ messageHandler("commaindex", "'e'");		}
		;

indexedelem	: MY_OPEN_ANG expr MY_DOT_UD expr MY_CLOSE_ANG		{ messageHandler("indexedelem", "{expr:expr}");		}
		;

block		: MY_OPEN_ANG {++scope;} stmts MY_CLOSE_ANG 
			{
				hide(scope--); 
				messageHandler("block", "{stmts}"); 
			}
		;

funcdef		: MY_FUNCTION MY_OPEN_PAR idlist MY_CLOSE_PAR block   { messageHandler("funcdef", "function (idlist) block"); }
		| MY_FUNCTION MY_ID MY_OPEN_PAR idlist MY_CLOSE_PAR block { messageHandler("funcdef", "function identifier (idlist) block");}
		;

const		: MY_REAL	{ messageHandler("const", "real_value");	}
		| MY_INTEGER	{ messageHandler("const", "integer_value");	}
		| MY_STRING	{ messageHandler("const", "string");	}
		| MY_NIL	{ messageHandler("const", "nil");	}
		| MY_TRUE	{ messageHandler("const", "true");	}
		| MY_FALSE	{ messageHandler("const", "false");	}
		;

idlist		: MY_ID idwithcommas	{ messageHandler("idlist", "identifier idwithcommas");	}
		| /*empty*/		{ messageHandler("idlist", "'e'");		}
		;

idwithcommas	: MY_COMMA MY_ID idwithcommas	{ messageHandler("idwithcommas", ", identifier idwithcommas");		}
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
