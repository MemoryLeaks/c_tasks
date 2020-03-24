#include "lang_tools.h"



void print_alpha_tokens(void){
	
	if (token_tail == NULL) return;

	printf("Number of tokens: %d, Number of lines %d. List of tokes below:\n", token_tail->position, line_cnt);
	alpha_token_t *traverser;
	for (traverser = token_keeper; traverser != NULL; traverser = traverser->next){
		printf("%d:\t #%d\t |%s|\t |%s|\n", traverser->line, traverser->position, traverser->value, traverser->type);
	}
}

int alpha_token_insert(unsigned int line, const char* value, const char *type){

	if(strcmp(value,"\n") == 0){
			line_cnt++;
			return 0;
	}
	/*AXRHSTO META APO ENA SHMEIO: Tsekarei ama exei mpei kati mesa me \n*/
	//assert(strstr(value,"\n") == NULL);

	alpha_token_t *cell = malloc(sizeof(alpha_token_t));
	if (cell == NULL){
		perror("Error in alpha_token_insert: Out of memory.");
		return 0;
	}

	cell->line = line;
	cell->value = _strdup(value);
	cell->type = _strdup(type);
	cell->next = NULL;

	if (token_keeper == NULL) {
		cell->position = 1;
		token_keeper = cell;
		token_tail = cell;
	}else{
		cell->position = token_tail->position + 1;
		token_tail->next = cell;
		token_tail = token_tail->next;
	}
	printf("Inserted %s...\n", token_tail->value);
	return 1;
}


static unsigned int SymTable_hash(const char* pcKey)
{
	size_t ui;
	unsigned int uiHash = 0U;
	for (ui = 0U; pcKey[ui] != '\0'; ui++)
		uiHash = uiHash * HASH_MULTIPLIER + pcKey[ui];
	return uiHash%SIZE;
}

SymTable_T SymTable_new()
{
	int i;
	SymTable_T t = malloc(sizeof(struct SymTable));
	t->size = 0;

	/*initializing the array*/
	for (i = 0; i < SIZE; t->BUCKETS[i] = NULL, i++);

	/* Initializing the first Library functions */
	SymTable_put(t, "print", 4, 0, 0, 1);
	SymTable_put(t, "input", 4, 0, 0, 1);
	SymTable_put(t, "objectmemberkeys", 4, 0, 0, 1);
	SymTable_put(t, "objecttotalmembers", 4, 0, 0, 1);
	SymTable_put(t, "objectcopy", 4, 0, 0, 1);
	SymTable_put(t, "totalarguments", 4, 0, 0, 1);
	SymTable_put(t, "argument", 4, 0, 0, 1);
	SymTable_put(t, "typeof", 4, 0, 0, 1);
	SymTable_put(t, "strtonum", 4, 0, 0, 1);
	SymTable_put(t, "sqrt", 4, 0, 0, 1);
	SymTable_put(t, "cos", 4, 0, 0, 1);
	SymTable_put(t, "sin", 4, 0, 0, 1);
	return t;
}

void SymTable_free(SymTable_T oSymTable)
{
	int i;
	assert(oSymTable);
	for (i = 0; i < SIZE; i++)
	{
		if (oSymTable->BUCKETS[i] != NULL)
			free(oSymTable->BUCKETS[i]);
	}
	free(oSymTable);
}

unsigned int SymTable_getLength(SymTable_T oSymTable)
{
	assert(oSymTable);
	return oSymTable->size;
}


int SymTable_put(SymTable_T oSymTable, const char* name, int type, int scope, int lineno, int active)
{
	SymbolTableEntry* p;
	assert(oSymTable);
	/* printf("Inserting %s with hash %d.\n",name,  SymTable_hash(name)); */
	assert(SymTable_hash(name) <= 509);

	/*H krisimi synthiki, se ligo tha ginei lookup */
	//if (SymTable_contains(oSymTable, name) == TRUE) {
	//	return FALSE;
	//}

	p = malloc(sizeof(SymbolTableEntry));
	p->next = NULL;
	
	/*Function Creation Case*/
	if (type > 2) {
		Function* fun = malloc(sizeof(Function));
		fun->name = _strdup(name);
		fun->scope = scope;
		fun->line = lineno;

		p->varVal = NULL;
		p->isActive = active;
		p->type = type;
		p->funcVal = fun;
	}
	/*Variable Creation Case*/
	else {
		Variable* var = malloc(sizeof(Variable));
		var->name = _strdup(name);
		var->scope = scope;
		var->line = lineno;

		p->funcVal = NULL;
		p->isActive = active;
		p->type = type;
		p->varVal = var;
	}

	
	if (oSymTable->BUCKETS[SymTable_hash(name)] == NULL)
		oSymTable->BUCKETS[SymTable_hash(name)] = p;
	else {
		p->next = oSymTable->BUCKETS[SymTable_hash(name)];
		oSymTable->BUCKETS[SymTable_hash(name)] = p;

	}

	scopeListAdd(p);
	oSymTable->size++;
	return TRUE;

}

SymbolTableEntry* SymTable_get(SymTable_T oSymTable, const char* name) {
	int i = SymTable_hash(name);
	int type = 0;
	SymbolTableEntry * tmp = oSymTable->BUCKETS[i];
	while (tmp != NULL) {
		/*Variable Case*/
		if (tmp->funcVal == NULL && strcmp(tmp->varVal->name, name) ==0) {
			return tmp;
		}
		/*Function Case*/
		else if (tmp->varVal == NULL && strcmp(tmp->funcVal->name, name) == 0) {
			return tmp;
		}

		tmp = tmp->next;
	}

	return NULL;
}

void Print(SymTable_T oSymTable)
{

	assert(oSymTable);
	unsigned int i = 0;
	printf("Symbol Table contains the following %d symbols:\n", oSymTable->size);
	for (i = 0; i < SIZE; i++) {
		SymbolTableEntry* tmp = oSymTable->BUCKETS[i];
		while (tmp != NULL) {
			/*Variable Case*/
			if (tmp->funcVal == NULL) {
				printf("Symbol [Name: %s],\t[Type:%s],\t[Line: %d],\t[Scope: %d],\t[Active: %d].\n",
					tmp->varVal->name, getSymbolType(tmp->type), tmp->varVal->line, tmp->varVal->scope, tmp->isActive);
			}
			/*Function Case*/
			else {
				printf("Symbol [Name: %s],\t[Type:%s],\t[Line: %d],\t[Scope: %d],\t[Active: %d].\n",
					tmp->funcVal->name, getSymbolType(tmp->type), tmp->funcVal->line, tmp->funcVal->scope, tmp->isActive);
			}

			tmp = tmp->next;
		}
	}

	printf("\n");
}


/* ---------------------------- SCOPE LIST AND ARGUMENTS KOLPA ----------------------------------------------- */

void scopeListAdd(SymbolTableEntry *symbolon) {
	int i;
	/* Periptwsh synarthshs */
	if (symbolon->varVal == NULL)
		i = symbolon->funcVal->scope;
	else 
		i = symbolon->varVal->scope;

	ScopeList *cell = malloc(sizeof(ScopeList));
	cell->symbol = symbolon;
	cell->next = NULL;

	if (scopeHead[i] == NULL) {
		scopeHead[i] = cell;
	}
	else {
		cell->next = scopeHead[i];
		scopeHead[i] = cell;
	}

}

void printScopeLists() {
	ScopeList* traverser;
	int i;
	printf("Printing the Scope Lists:\n");
	for (i = 0; i < 72; i++) {
		traverser = scopeHead[i];
		if (traverser)
			printf("\nScope List # [%d]:\n", i);

		while (traverser != NULL) {
			if (traverser->symbol->varVal == NULL)
				printf("Function: [name= %s], [line number= %d], [scope= %d], ",
					traverser->symbol->funcVal->name, traverser->symbol->funcVal->line, traverser->symbol->funcVal->scope);
			else if (traverser->symbol->funcVal == NULL)
				printf("Variable: [name= %s], [line number= %d], [scope= %d], ",
					traverser->symbol->varVal->name, traverser->symbol->varVal->line, traverser->symbol->varVal->scope);
			printf("[Special Type= %s], [Activeness: %d].\n", getSymbolType(traverser->symbol->type), traverser->symbol->isActive);
			traverser = traverser->next;

		}
	}
	printf("\n");
}

void hide(int scope) {
	ScopeList* traverser = scopeHead[scope];
	while (traverser != NULL) {
		traverser->symbol->isActive = 0;
		traverser = traverser->next;
	}
	return;
}


int scope_lookup(char *symbol, int scope) {
	ScopeList* traverser = scopeHead[scope];
	while (traverser != NULL) {
		if (traverser->symbol->isActive == 1) {
			if (traverser->symbol->varVal == NULL && (strcmp(traverser->symbol->funcVal->name, symbol) == 0)) {
				/*Same token found in this scope*/
				/* printf("Brethike idio name synartisis!\n"); */
				return TRUE;
			}
			else if (traverser->symbol->funcVal == NULL && (strcmp(traverser->symbol->varVal->name, symbol) == 0)) {
				/*Same token found in this scope*/
				/* printf("Brethike idio name metablitis!\n"); */
				return TRUE;
			}
		}
		traverser = traverser->next;
	}
	/*If not found in this scope we return FALSE, so you can add a new symbol in symbol table*/
	return FALSE;
}

/*[EPISTREFEI SCOPE] Synarthsh h opoia psaxnei se OLA ta scopes. */
int catholic_lookup(char* symbol) {
	int scope = 0;
	for (scope = 0; scope < 72; scope++) {
		ScopeList* traverser = scopeHead[scope];
		while (traverser != NULL) {
			if (traverser->symbol->isActive == 1) {
				if (traverser->symbol->varVal == NULL && (strcmp(traverser->symbol->funcVal->name, symbol) == 0)) {
					/*Same token found in this scope*/
					/* printf("Catholic: Brethike idio name synartisis!\n"); */
					return scope;
				}
				else if (traverser->symbol->funcVal == NULL && (strcmp(traverser->symbol->varVal->name, symbol) == 0)) {
					/*Same token found in this scope*/
					/* printf("Catholic: Brethike idio name metablitis!\n"); */
					return scope;
				}
			}
			traverser = traverser->next;
		}
	}

	return -1; /*To -1 shmainei den brethike*/
}

/*-------------------------------------------------------------------------------------------------------------*/

char* getSymbolType(int x) {
	if (x == 0)
		return "GLOBAL";
	else if (x == 1)
		return "LOCAL";
	else if (x == 2)
		return "FORMAL";
	else if (x == 3)
		return "USERFUNC";
	else
		return "LIBFUNC";

}