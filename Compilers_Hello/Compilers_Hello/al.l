%{
	#include "lang_tools.h"
	#include "syntax.h"
	/* #define YY_DECL int alpha_yylex (void* ylval) */
%}

%option noyywrap
%option yylineno

multiline_comment		("/*")
line_comment			("//")
str			["]{1}

IF			("if")
ELSE		("else")
FOR			("for")
WHILE		("while")
DO			("do")
CONT		("continue")
BREAK		("break")
RET			("return")
AND			("and")
OR			("or")
NOT			("not")

TYPE_LOCAL		("local")
TYPE_GLOBAL		("global")
TYPE_STATIC		("static")
TYPE_NIL		("nil")
TRUE			("true")
FALSE			("false")
FUNCTION		("function")

identifier		[a-zA-Z][_a-zA-Z0-9]*
newline			"\n"
blank			[' '\t\r\v]*
integer			[0-9]+
real			[0-9]+"."[0-9]+

OPERATOR_ASSIGN		("=")
OPERATOR_EQUAL		("==")
OPERATOR_NEQUAL		("!=")
OPERATOR_PLUS		("+")
OPERATOR_INC		("++")
OPERATOR_MINUS		("-")
OPERATOR_DEC		("--")
OPERATOR_MUL		("*")
OPERATOR_DIV		("/")
OPERATOR_MOD		("%")
OPERATOR_L			("<")
OPERATOR_LE			("<=")
OPERATOR_G			(">")
OPERATOR_GE			(">=")

OPEN_ANG		"{"
OPEN_BRA		"["
OPEN_PAR		"("
CLOSE_ANG		"}"
CLOSE_BRA		"]"
CLOSE_PAR		")"
DOT_UP_DOWN		":"
DOT_STREAM		"::"
DOT_SIMPLE		"."
DOT_DOUBLE		".."
COMMA			","
SEMICOLON		";"

%%

{IF}			{ return MY_IF; }
{ELSE}			{ return MY_ELSE; }
{FOR}           { return MY_FOR; }
{WHILE}			{ return MY_WHILE; }
{DO}			{ return MY_DO;	}
{CONT}			{ return MY_CONTINUE; }
{BREAK}			{ return MY_BREAK; }
{RET}			{ return MY_RETURN;	}

{AND}			{ return MY_AND; }
{OR}			{ return MY_OR;	}
{NOT}			{ return MY_NOT; }

{TYPE_LOCAL}	{ return MY_LOCAL; }
{TYPE_GLOBAL}   { return MY_GLOBAL;	}
{TYPE_STATIC}   { return MY_STATIC;	}
{TYPE_NIL}      { return MY_NIL; }
{TRUE}	        { return MY_TRUE; }
{FALSE}         { return MY_FALSE; }
{FUNCTION}      { return MY_FUNCTION; }



{identifier}	{ 
					yylval.string = _strdup(yytext);
					return MY_ID;		
				}

{newline}		{ }
{blank}			{ }

{integer}	{
				yylval.integer = atoi(yytext);
				return MY_INTEGER;    
			}

{real}	    {
				yylval.real = atof(yytext);
				return MY_REAL;
			}



{OPERATOR_ASSIGN}	{ return MY_ASSIGN;	}
{OPERATOR_EQUAL}	{ return MY_EQUAL;	}
{OPERATOR_NEQUAL}	{ return MY_NEQUAL;	}
{OPERATOR_PLUS}     { return MY_PLUS;	}
{OPERATOR_MINUS}    { return MY_MINUS;	}
{OPERATOR_MUL}      { return MY_MUL;	}
{OPERATOR_DIV}      { return MY_DIV;	}
{OPERATOR_MOD}      { return MY_MOD;	}
{OPERATOR_L}        { return MY_L;		}
{OPERATOR_LE}       { return MY_LE;		}
{OPERATOR_G}        { return MY_G;		}
{OPERATOR_GE}       { return MY_GE;		}
{OPERATOR_INC}	    { return MY_INC;	}
{OPERATOR_DEC}	    { return MY_DEC;	}

{OPEN_ANG}      { return MY_OPEN_ANG;	}
{OPEN_BRA}      { return MY_OPEN_BRA;	}
{OPEN_PAR}      { return MY_OPEN_PAR;	}
{CLOSE_ANG}     { return MY_CLOSE_ANG;	}
{CLOSE_BRA}     { return MY_CLOSE_BRA;	}
{CLOSE_PAR}     { return MY_CLOSE_PAR;	}
{DOT_UP_DOWN}	{ return MY_DOT_UD;		}
{DOT_STREAM}    { return MY_DOT_STREAM; }
{DOT_SIMPLE}    { return MY_DOT_SIMPLE; }
{DOT_DOUBLE}    { return MY_DOT_DOUBLE;	}
{COMMA}         { return MY_COMMA;		}
{SEMICOLON}     { return MY_SEMICOLON;	}



{str}		{

	int special_character_flag = 0;	/* Checks if the special character is valid or not */
	int warning_case = 0;			/* to idio me panw alla kathorizei to ama mpei h oxi */
	int string_format_flag = 0;  /* Checks if the string format is valid or not (endless string) */
	unsigned int i = 1;
	int found_in = yylineno;
	char c = '\0';
	char *buffer = malloc(sizeof(char)*2);

	buffer[0] = '\"';
	buffer[1] = '\0';
	assert(strcmp(yytext,"\"") == 0);
	
	while(c = input()) 
	{	

		if (c == EOF){
			string_format_flag = 0;
			break;
		}

		if (c == '\"') 
		{
			string_format_flag = 1;
			break; /* Exit case */
		}

		i++;

		if (c == '\\') {
			c = input();

			if (c == '\\')
				c = '\\';
			else if (c == 'n')
				c = '\n';
			else if (c == 't')
				c = '\t';
			else if (c == '\"'){
				//i--;
				c = '\"';
			}
			else{
				special_character_flag = 1;
				warning_case = 1;
			}
		}

		/* printf("O METRHTHS EINAI [%d] O XARAKTHRAS EINAI [%c] \n", i, c); */

		buffer = realloc(buffer, (i + 1)*sizeof(char));
		buffer[i - 1] = c;
		buffer[i] = '\0';

		/* Check for invalid special character */
		if(special_character_flag){
			printf("Warning: String contains invalid escape character %c \n", c);
			special_character_flag = 0; /* Reset flag variable */
		}

	}

	if (warning_case == 1) {
		printf("String contains illegal space characters and cannot be inserted!\n");
	}
	else if (string_format_flag == 0) {								
		printf("Error: Illegal string! String is endless and cannot be inserted\n");
		/* alpha_token_insert(yylineno, error_buf, "ENDLESS_STRING"); */
	}else{									
		char *fin_buf = malloc(i * sizeof(char) + 10);
		fin_buf = strcpy(fin_buf, buffer);
		fin_buf = strcat(fin_buf, "\"\0");
		alpha_token_insert(found_in, fin_buf, "STRING");  /* LATHOS EDW */
		return MY_STRING;
	}
	
}



{multiline_comment}		{
	int nested_comments = 0;
	int comment_format = 0;
	unsigned int nested = 0;	/* pleon xrisimeuei kai san header sti stoiba */

	int line_keeper[20];	/* Pinakas pou krataei tin grammi emfanisis kathe eidous sxoliou, paizei san stoiba */
	int i = 0;
	for (int i = 0; i < 20; i++)
		line_keeper[i] = 0;
	
	i = yylineno;	/*as xrisimopoiehthei o index ws h grammh emfanhshs tou prwtou sxoleiou */

	char c = '\0';
	while((c = input())) {

		if (c == EOF){
			/* gia kapoio logo opws kai panw to c input den termatizei gia EOF sta windows */
			break;
		}

		/* Periptwsh kleisimatos sxoliou */
		if (c == '*') {
			c = input();
			if ((c == '/') && (nested == 0)){
				/* An den yparxoun alla nested stamataw */
				comment_format = 1;
				break;
			}
			else if ((c == '/') && (nested > 0)) {	/* An yparxoun akoma nested anoigmena apla to meiwnw    */
				alpha_token_insert(line_keeper[--nested], "COMMENT", "NESTED COMMENT");
				nested_comments++;
				continue;
			}		
		}

		/* Periptwsh anoigmatos sxoliou */
		if (c =='/') {
			if ((c = input()) == '*') {
				line_keeper[nested++] = yylineno;					/* An nai tote auksanw ton arithmo twn nested */
				continue;
			}

			unput(c);
		}

	}

	printf("Found %d nested comments\n", nested_comments);

	/* Check comment format */
	if (comment_format == 0) {
		printf("Error: Endless Comment.. Comment didn't close properly...\n");
		exit(1);
	}
	else {
		alpha_token_insert(i, "COMMENT", "MULTILINE COMMENT");
	}

}

{line_comment} {
	char c = '\0';
	int i = yylineno;
	while((c = input()) != EOF) {
		
		if (c == '\n')
			break;
	}

	alpha_token_insert(i, "COMMENT", "ONE LINE COMMENT");
}


.			{	printf("Error: Found UNDEFINED TOKEN: %s in line: %d.", yytext, yylineno);
				exit(1);
			}


%%

/*
int main(int argc, char **argv){
	if (argc == 1) {
		printf("Type your input with keyboard: \n");
		yyin=stdin;
	} else if (argc == 2) {
		FILE *tmp = fopen(argv[1],"r");
		if (!tmp) {
			perror("Input file not found...\n");
			return 0;
		}
		yyin = tmp;
	}else {
		perror("Error: Invalid Input.\n");
		exit(0);
	}

	alpha_yylex(NULL);
	print_alpha_tokens();
	return 0;
}

*/