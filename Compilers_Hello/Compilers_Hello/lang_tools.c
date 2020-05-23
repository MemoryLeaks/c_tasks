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

/*[EPISTREFEI SCOPE] Synarthsh h opoia psaxnei se OLA ta scopes.  Alla apo to scope pou eimaste pros ta ksw
  dhladh inside out.*/

int inside_out_lookup(char* symbol, int scope) {
	while (scope != 0) {
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

		scope--;
	}

	return -1; /*To -1 shmainei den brethike*/
}

/*Epistrefei ena SYMBOLO se sygkekrimeni SCOPE LIST */
SymbolTableEntry* ScopeListGetSymbolAt(char* symbol, int scope) {
	ScopeList* traverser = scopeHead[scope];
	while (traverser != NULL) {
		if (traverser->symbol->isActive == 1) {
			if (traverser->symbol->varVal == NULL && (strcmp(traverser->symbol->funcVal->name, symbol) == 0))
			{
				return traverser->symbol;
			}
			else if (traverser->symbol->funcVal == NULL && (strcmp(traverser->symbol->varVal->name, symbol) == 0)) {
				return traverser->symbol;
			}
		}
		traverser = traverser->next;
	}

	return NULL;
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


expression* NewExpr(enum expr_t type, SymbolTableEntry* symbol, double numConst, char* strConst, unsigned char boolConst) {
	expression* cell = malloc(sizeof(expression));
	assert(cell);
	cell->type = type;
	cell->sym = symbol;
	cell->index = NULL;
	cell->next = NULL;
	cell->numConst = numConst;
	cell->strConst = _strdup(strConst);
	cell->boolConst = boolConst;

	return cell;
}




tesseract emit(enum iopcode type, expression* expr1, expression* expr2, expression* expr3, unsigned line, unsigned offset) {
	tesseract quady;
	quady.arg1 = expr1;
	quady.arg2 = expr2;
	quady.result = expr3;
	quady.op = type;
	quady.line = line;
	quady.label = offset;

	//printf("Emmited %u: %s %s %s %s.\n",offset, getIOpcodeName(quady.op), getExpressionValue(quady.arg1), getExpressionValue(quady.arg2), getExpressionValue(quady.result));

	return quady;
}

char* getIOpcodeName(enum iopcode type) {
	if (type == 0)
		return "ASSIGN";
	else if (type == 1)
		return "ADD";
	else if (type == 2)
		return "SUB";
	else if (type == 3)
		return "MUL";
	if (type == 4)
		return "DIV";
	else if (type == 5)
		return "MOD";
	else if (type == 6)
		return "UMINUS";
	else if (type == 7)
		return "AND";
	if (type == 8)
		return "OR";
	else if (type == 9)
		return "NOT";
	else if (type == 10)
		return "IF_EQ";
	else if (type == 11)
		return "IF_NOTEQ";
	if (type == 12)
		return "IF_LESSEQ";
	else if (type == 13)
		return "IF_GREATEREQ";
	else if (type == 14)
		return "IF_LESS";
	else if (type == 15)
		return "IF_GREATER";
	if (type == 16)
		return "CALL";
	else if (type == 17)
		return "PARAM";
	else if (type == 18)
		return "RETURN";
	else if (type == 19)
		return "GETRETVAL";
	if (type == 20)
		return "FUNCSTART";
	else if (type == 21)
		return "FUNCEND";
	else if (type == 22)
		return "TABLECREATE";
	else if (type == 23)
		return "TABLEGETELEM";
	else if (type == 24)
		return "TABLESETELEM";
	else if (type == 25)
		return "JUMP";
	else
		return "MISSINGNO";
}

char* getExpressionValue(expression* expr) {

	if (expr == NULL)
		return "";

	if (expr->sym != NULL && expr->sym->funcVal != NULL) {
		return (char *) expr->sym->funcVal->name;
	}
	else if (expr->sym != NULL && expr->sym->varVal != NULL) {
		return (char*) expr->sym->varVal->name;
	}

	if (expr->numConst != 0) {
		char* buf = malloc(sizeof(char) * 20);
		assert(buf);
		memset(buf, '\0', 20);

		int tempy = (int)expr->numConst;

		if (tempy == expr->numConst)
			sprintf(buf, "%d", tempy);
		else
			sprintf(buf, "%f", expr->numConst);

		return buf;
	}
	else if (expr->strConst != NULL) {
		return expr->strConst;
	}
	else if ( expr->type == 7) {
		return "[...]";
	}
	else {
		if (expr->boolConst == 'T') return "TRUE";
		else if (expr->type == 8)  return "0";
		else if (expr->type == 11) return "nill";
		else return "FALSE";
	}
}

expression* push_back(expression* header, expression* p) {
	if (header == NULL) {
		header = p;
		header->next = NULL;
		return header;
	}

	expression* prev = NULL;
	expression* curr = header;
	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
	}

	p->next = NULL;
	prev->next = p;
	
	return header;
}

expression *emit_if_table(expression* e, enum iopcode type, SymTable_T oSymTable, int scope,  int yylineno, expression *set_val, unsigned line, unsigned *offset, tesseract *qt, int *temp_counter) {
	char currentTemp[8];
	SymbolTableEntry* previous_sym = NULL;
	SymbolTableEntry* symbol = NULL;
	expression* last_keeper = NULL;

	(*offset)--;
	assert(type == 23 || type == 24);

	expression* traverser = e;
	while (traverser != NULL) {

		memset(currentTemp, '\0', 8);
		strcpy(currentTemp, "_t");
		char tmp[3];
		memset(tmp, '\0', 3);
		sprintf(tmp, "%d", (*temp_counter)++);
		strcat(currentTemp, tmp);

		if (scope == 0 && SymTable_get(oSymTable, currentTemp) == NULL)
			SymTable_put(oSymTable, currentTemp, 0, scope, yylineno, 1);
		else if (scope >= 1 && SymTable_get(oSymTable, currentTemp) == NULL)
			SymTable_put(oSymTable, currentTemp, 1, scope, yylineno, 1);

		previous_sym = symbol;
		symbol = SymTable_get(oSymTable, currentTemp);

		last_keeper = NewExpr(1, symbol, 0, traverser->strConst, 'T');
		if (previous_sym == NULL){
			qt[*offset] = emit(23, traverser, traverser->index, last_keeper, line, (*offset)++);
		}
		else if (traverser->index != NULL){
			if (type == 24 && traverser->index->index == NULL) {
				last_keeper->type = 1;
				last_keeper->sym = previous_sym;
				last_keeper->numConst = traverser->index->numConst;
				last_keeper->strConst = traverser->index->strConst;
				return last_keeper;
			}
			qt[*offset] = emit(23, NewExpr(0, previous_sym, 0, traverser->strConst, 'T'), traverser->index, last_keeper, line, (*offset)++);
		}

		traverser = traverser->index;

	}

	assert(last_keeper);
	last_keeper->sym = previous_sym;

	return last_keeper;
}

expression* push_index_back(expression* header, expression* p) {
	
	if (header == NULL) {
		return header;
	}

	header->type = 1;

	if (header->index == NULL) {
		p->index = NULL;
		header->index = p;

		return header;
	}


	expression* prev = NULL;
	expression* curr = header->index;
	while (curr != NULL) {
		prev = curr;
		curr = curr->index;
	}

	if (prev)
		prev->index = p;

	return header;
}


BreakList* push_BreakList(BreakList* head, tesseract *q) {
	
	BreakList* tmp = malloc(sizeof(BreakList));
	assert(tmp);
	tmp->jump_quad = q;
	tmp->next = NULL;

	if (head == NULL) {
		head = tmp;
	}
	else {
		tmp->next = head;
		head = tmp;
	}

	return head;
}

ContinueList* push_ContinueList(ContinueList* head, tesseract *q) {

	ContinueList* tmp = malloc(sizeof(ContinueList));
	assert(tmp);
	tmp->jump_quad = q;
	tmp->next = NULL;

	if (head == NULL) {
		head = tmp;
	}
	else {
		tmp->next = head;
		head = tmp;
	}

	return head;
}
