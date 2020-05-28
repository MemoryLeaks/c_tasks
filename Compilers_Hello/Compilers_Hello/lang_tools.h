#ifndef _LANG_TOOLS_H
#define _LANG_TOOLS_H

#define TRUE 1
#define FALSE 0
#define SIZE 509
#define HASH_MULTIPLIER 2


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* Apla syndedemenh lista me pointer sto telos tis listas*/
struct alpha_token {
	unsigned int line;
	const char *value;
	unsigned int position;
	const char *type;
	const char *sub_type;
	struct alpha_token *next;
};

typedef struct alpha_token alpha_token_t;
alpha_token_t* token_keeper;
alpha_token_t* token_tail;
unsigned int line_cnt;
/*Insertion Synarthsh enos token.*/
int alpha_token_insert(unsigned int line, const char* value, const char* type);

/*Synartisi pou printarei ola ta tokens*/
void print_alpha_tokens(void);


/* ------------------------------------------------------------------------------------------------------------------------------------------ */
/* ---------------------------------------------------------~  2nd Phase  ~------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------ */



typedef struct Variable { 
	const char* name;  
	unsigned int scope;  
	unsigned int line; 
} Variable;

typedef struct Function {
	const char* name;  
	//List of arguments
	unsigned int scope;  
	unsigned int line; 
} Function;

enum SymbolType { GLOBAL, LOCAL, FORMAL, USERFUNC, LIBFUNC };

typedef struct SymbolTableEntry {
	int isActive;
	Variable* varVal;
	Function* funcVal;
	enum SymbolType type;
	struct SymbolTableEntry* next;
} SymbolTableEntry;

struct SymTable
{
	SymbolTableEntry* BUCKETS[SIZE];
	unsigned int size;
};

typedef struct SymTable* SymTable_T;

typedef struct scopeList {
	SymbolTableEntry* symbol;
	struct scopeList *next;
} ScopeList;


ScopeList* scopeHead[72];
void scopeListAdd(SymbolTableEntry* symbolon);
void printScopeLists();
void hide(int scope);
int scope_lookup(char *symbol, int scope);
int catholic_lookup(char* symbol);
int inside_out_lookup(char* symbol, int scope);
SymbolTableEntry* ScopeListGetSymbolAt(char* symbol, int scope);


SymTable_T SymTable_new(void);
void SymTable_free(SymTable_T oSymTable);
unsigned int SymTable_getLength(SymTable_T oSymTable);

/*Edw to type pairnei 0, 1, 2, 3, 4, kai tha ginei cast entos tou implementation*/
int SymTable_put(SymTable_T oSymTable, const char* name, int type, int scope, int lineno, int active);
SymbolTableEntry* SymTable_get(SymTable_T oSymTable, const char* name);
void Print(SymTable_T oSymTable);

/* Helpers */
char* getSymbolType(int x);

/*Gia thn 4-5h fash*/
unsigned getSymbolOffset(char* symbol);

/* ------------------------------------------------------------------------------------------------------------------------------------------ */
/* ---------------------------------------------------------~  3rd Phase  ~------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------ */

enum iopcode {
	assign,			add,			sub,
	mul,			divide,			mod,
	uminus,			iand,			ior,
	inot,			if_eq,			if_noteq,
	if_lesseq,		if_greatereq,	if_less,
	if_greater,		call,			param,
	ret,			getretval,		funcstart,
	funcend,		tablecreate,
	tablegetelem,	tablesetelem,	jump
};


enum expr_t {
	var_e,
	tableitem_e,
	programfunc_e,
	libraryfunc_e,
	arithexpr_e,
	boolexpr_e,
	assignexpr_e,
	newtable_e,
	constnum_e,
	constbool_e,
	conststring_e,
	nil_e
};

struct expr {
	enum expr_t	type;
	SymbolTableEntry *sym;
	struct expr *index;
	double numConst;
	char *strConst;
	unsigned char boolConst;
	struct expr *next;
};

struct quad {
	enum iopcode op;
	struct expr *result;
	struct expr *arg1;
	struct expr *arg2;
	unsigned label;
	unsigned line;
};

struct breakList {
	struct quad* jump_quad;
	struct breakList* next;
};

struct continueList {
	struct quad* jump_quad;
	struct continueList* next;
};

typedef struct breakList BreakList;
typedef struct continueList ContinueList;

#define EXPAND_SIZE 1024
#define CURR_SIZE (total * sizeof(struct quad))
#define NEW_SIZE (EXPAND_SIZE * sizeof(struct quad) + CURR_SIZE)

typedef struct expr expression;
typedef struct quad tesseract;

expression* NewExpr(enum expr_t type, SymbolTableEntry* symbol, double numConst, char* strConst, unsigned char boolConst);
tesseract emit(enum iopcode type, expression* expr1, expression* expr2, expression* expr3, unsigned line, unsigned offset);

char* getIOpcodeName(enum iopcode type);
char* getExpressionValue(expression* expr);

expression* push_back(expression* header, expression* p);
expression* push_index_back(expression* header, expression* p);


expression* emit_if_table(expression* e, enum iopcode type, SymTable_T oSymTable, int scope, int yylineno, expression* set_val, unsigned line, unsigned *offset, tesseract* qt, int *temp_counter);

BreakList* push_BreakList(BreakList* head, tesseract* q);
ContinueList* push_ContinueList(ContinueList* head, tesseract *q);

#endif
