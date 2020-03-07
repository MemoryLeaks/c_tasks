#ifndef _LANG_TOOLS_H
#define _LANG_TOOLS_H

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

alpha_token_t *token_keeper;
alpha_token_t *token_tail;

unsigned int line_cnt;

/*Insertion Synarthsh enos token.*/
int alpha_token_insert(unsigned int line, const char* value, const char *type);
/*Deletion Synarthsh enos token.*/
int alpha_token_delete(unsigned int position);

/*Search synarthsh enos token.*/
struct alpha_token *alpha_token_search(unsigned int position);

/*Synartisi pou printarei ola ta tokens*/
void print_alpha_tokens(void);

/*Free synarthsh listas*/
int alpha_token_free();

#endif
