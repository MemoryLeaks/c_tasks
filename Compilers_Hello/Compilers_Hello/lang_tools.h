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

SymTable_T SymTable_new(void);
void SymTable_free(SymTable_T oSymTable);
unsigned int SymTable_getLength(SymTable_T oSymTable);

/*Edw to type pairnei 0, 1, 2, 3, 4, kai tha ginei cast entos tou implementation*/
int SymTable_put(SymTable_T oSymTable, const char* name, int type, int scope, int lineno, int active);
SymbolTableEntry* SymTable_get(SymTable_T oSymTable, const char* name);
void Print(SymTable_T oSymTable);

/* Helpers */
char* getSymbolType(int x);


#endif
