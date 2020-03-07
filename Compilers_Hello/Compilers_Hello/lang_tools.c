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

