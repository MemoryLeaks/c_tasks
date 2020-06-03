#ifndef _AVM_TOOLS_H
#define _AVM_TOOLS_H

#include "lang_tools.h"

enum vmarg_t {
	label_a,
	global_a,
	local_a,
	formal_a,
	number_a,
	string_a,
	bool_a,
	userfunction_a,
	libfunction_a,
	retval_a,
	table_a,
	table_element_a,
	nil_a
};

enum vmopcode {
	vm_assign,			vm_add,				vm_sub,
	vm_mul,				vm_divide,			vm_mod,
	vm_uminus,			vm_and,				vm_or,
	vm_not,				vm_if_eq,			vm_if_noteq,
	vm_if_lesseq,		vm_if_greatereq,	vm_if_less,
	vm_if_greater,		vm_call,			vm_param,
	vm_ret,				vm_getretval,		vm_funcstart,
	vm_funcend,			vm_tablecreate,
	vm_tablegetelem,	vm_tablesetelem,	
	vm_jump,			vm_nop
};

struct _vmarg
{
	enum vmarg_t type; 
	unsigned val;
};

struct _instruction {
	enum vmopcode opcode;
	struct _vmarg result;
	struct _vmarg arg1;
	struct _vmarg arg2;
	unsigned offset;
	unsigned srcLine;
};

typedef struct _vmarg vmarg;
typedef struct _instruction instruction;

/* Sysxetistikoi Pinakes */
char* str_const_table[256];
double num_const_table[256];
char* lib_fnc_table[256];
SymbolTableEntry* usr_var_table[256];
SymbolTableEntry* usr_fnc_table[256];

int glob_cnt;
int local_cnt;
int local_accumulator;

instruction instructionTable[1024];
unsigned a_pc;

/* Synartiseis sysxetistikwn pinakwn */
unsigned consts_new_string(char* s);
unsigned consts_new_number(double d);
unsigned user_new_var(SymbolTableEntry *symbol);
unsigned user_new_fnc(SymbolTableEntry* symbol);
unsigned libr_new_function(char* fnc);

/* Genesis Functions */
/*E: eisodos, VM_E: exodos */
vmarg make_operant(expression* e, vmarg arg);

/* Kanei generate to katalilo opcode gia to alithino quad */
void generate(enum vmarg_t op, tesseract quad);
void generate_AND(tesseract q);
void generate_OR(tesseract q);
void generate_NOT(tesseract q);


/* Metatrepei to Operation se Text */
char* getAOP_text(enum iopcode type);

/* Elegxos an h timi einai ok kai printarisma */
const char* getValue(vmarg arg);

/* Bazei to instruction sto Instruction Table */
void a_emit(instruction t);

/* Transforms the Quad table to Instruction Tables */
void transform(tesseract quad_table[]);
void final_code();

#endif // !_AVM_TOOLS_H
