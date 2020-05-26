#include "avm_tools.h"

unsigned consts_new_string(char* s) {
	static unsigned i = 0;
	str_const_table[i] = s;
	i++;

	return i - 1;
}

unsigned consts_new_number(double d) {
	static unsigned i = 0;
	num_const_table[i] = d;
	i++;

	return i - 1;
}

unsigned user_new_var(SymbolTableEntry* symbol) {
	static unsigned i = 0;
	usr_var_table[i] = symbol;
	i++;

	return i - 1;
}

unsigned user_new_fnc(SymbolTableEntry* symbol) {
	static unsigned i = 0;
	usr_fnc_table[i] = symbol;
	i++;

	return i - 1;
}

unsigned libr_new_function(char* fnc) {
	static unsigned i = 0;
	lib_fnc_table[i] = fnc;
	i++;

	return i - 1;
}

vmarg make_operant(expression* e, vmarg arg) {

	/* Variables: Ti tha ginei me to table item? */
	if (e) {
		switch (e->type) {
		case var_e:
		case arithexpr_e:
		case boolexpr_e:
		case tableitem_e:
		case newtable_e: {
			if (e->sym) {
				arg.val = user_new_var(e->sym);
				switch (e->sym->varVal->scope) {
					case GLOBAL: { arg.type = global_a; return arg; }
					case LOCAL: { arg.type = local_a; if (e->sym->type == FORMAL) { arg.type = formal_a; } return arg; }
					case FORMAL: { arg.type = formal_a; return arg; }
					default: assert(0);
				}
			}
			else {
				if (e->strConst == NULL) {
					arg.type = number_a;
					arg.val = consts_new_number(e->numConst);
				}
				else if (e->numConst == 0) {
					arg.type = string_a;
					arg.val = consts_new_string(e->strConst);
				}
				else if (e->boolConst == 'T') {
					arg.type = bool_a;
					arg.val = consts_new_number(1);
				}
				else {
					arg.type = bool_a;
					arg.val = consts_new_number(0);
				}
				return arg;
			}
		}

		/* Constants */
		case constbool_e: {
			if (e->boolConst == 'T')
				arg.val = consts_new_number(1);
			else
				arg.val = consts_new_number(0);

			arg.type = bool_a;
			return arg;
		}

		case conststring_e: {
			arg.val = consts_new_string(e->strConst);
			arg.type = string_a;
			return arg;
		}

		case constnum_e: {
			arg.val = consts_new_number(e->numConst);
			arg.type = number_a;
			return arg;
		}

		case nil_e: {
			arg.type = nil_a;
			return arg;
		}

		/* About functions */
		case programfunc_e: {
			arg.type = userfunction_a;
			arg.val  = user_new_fnc(e->sym);
			return arg;
		}

		case libraryfunc_e: {
			arg.type = libfunction_a;
			arg.val = libr_new_function((char*)e->sym->funcVal->name);
			return arg;
		}

		default: { printf("Congratulations %d!\n", e->type); }
		}
	}

	return arg;
}

void generate(enum vmart_t op, tesseract quad) {
	instruction t = { 0, {0, 0}, {0, 0}, {0,0}, 0, 0 };
	t.opcode = op;

	if (op == 6) {
		t.opcode = vm_mul;
		quad.arg2 = NewExpr(8, NULL, -1, NULL, 'T');
	}


	t.arg1 = make_operant(quad.arg1, t.arg1);
	t.arg2 = make_operant(quad.arg2, t.arg2);
	t.result = make_operant(quad.result, t.result);
	t.srcLine = quad.line;
	t.offset = a_pc;

	if (op == vm_jump || op == vm_if_greater || op == vm_if_greatereq || op == vm_if_less || op == vm_if_lesseq || op == vm_if_eq 
	|| op == vm_if_noteq ) {
		t.result.type = label_a;
		t.result.val = (unsigned int) quad.result->numConst;
	}


	a_emit(t);
}

char* getAOP_text(enum iopcode type) {
	if (type == 0)
		return "assign";
	else if (type == 1)
		return "add";
	else if (type == 2)
		return "sub";
	else if (type == 3)
		return "mul";
	if (type == 4)
		return "div";
	else if (type == 5)
		return "mod";
	else if (type == 6)
		return "uminus";
	else if (type == 7)
		return "and";
	if (type == 8)
		return "or";
	else if (type == 9)
		return "not";
	else if (type == 10)
		return "jeq";
	else if (type == 11)
		return "jneq";
	if (type == 12)
		return "jleq";
	else if (type == 13)
		return "jgreq";
	else if (type == 14)
		return "jle";
	else if (type == 15)
		return "jgr";
	if (type == 16)
		return "call";
	else if (type == 17)
		return "pusharg";
	else if (type == 18)
		return "return";
	else if (type == 19)
		return "geretval";
	if (type == 20)
		return "enterfunc";
	else if (type == 21)
		return "exitfunc";
	else if (type == 22)
		return "tablecreate";
	else if (type == 23)
		return "tablegetelem";
	else if (type == 24)
		return "tablesetelem";
	else if (type == 25)
		return "jump";
	else
		return "missingno";
}

const char* getValue(vmarg arg) {
	if (arg.type == 0 && arg.val > 0) {
		char* valName = malloc(sizeof(char) * 16);
		assert(valName);
		memset(valName, '\0', 16);
		sprintf(valName, "%d", (unsigned int) arg.val);
		return valName;
	}
	if (arg.type == 1) {
		return usr_var_table[arg.val]->varVal->name;
	}
	else if (arg.type == 2) {
		return usr_var_table[arg.val]->varVal->name;
	}
	else if (arg.type == 3) {
		return usr_var_table[arg.val]->varVal->name;
	}
	else if (arg.type == 4) {
		char* valName = malloc(sizeof(char) * 16);
		assert(valName);
		memset(valName, '\0', 16);
		if ((int) num_const_table[arg.val] == num_const_table[arg.val])
			sprintf(valName, "%d", (int) num_const_table[arg.val]);
		else
			sprintf(valName, "%f", num_const_table[arg.val]);

		return valName;
	}
	else if (arg.type == 5) {
		return str_const_table[arg.val];
	}
	else if (arg.type == 6) {
		if (num_const_table[arg.val] == 0) return "0";   // false
		else  return "1";								 // true
	}
	else if (arg.type == 7) {
		if (usr_fnc_table[arg.val]->funcVal)
			return usr_fnc_table[arg.val]->funcVal->name;
		else
			return usr_var_table[arg.val]->varVal->name;
	}
	else if (arg.type == 8) {
		return lib_fnc_table[arg.val];
	}
	else if (arg.type == 11) {
		return usr_var_table[arg.val]->varVal->name;
	}
	else if (arg.type == 12) {
		return "nill";
	}
	else
		return "";
}

void a_emit(instruction t) {
	instructionTable[a_pc++] = t;
}

void transform(tesseract quad_table[]) {
	for (int i = 1; i < 1024; i++) {
		generate(quad_table[i].op, quad_table[i]);
	}
}



void final_code() {
	FILE* fptr = fopen("assembly.txt", "w");
	if (fptr == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}

	fprintf(fptr, "340666%d\n", a_pc);
	for (int i = 1; i < 1024; i++) {
		if (instructionTable[i].srcLine != 0) {
			fprintf(stdout, "%d:\t%s\t", instructionTable[i].offset, getAOP_text(instructionTable[i].opcode));

			if (instructionTable[i].arg1.type != 0 || strcmp(getValue(instructionTable[i].arg1), "") != 0)
				fprintf(stdout, "(%d)%s\t", instructionTable[i].arg1.type, getValue(instructionTable[i].arg1));

			if (instructionTable[i].arg2.type != 0 || strcmp(getValue(instructionTable[i].arg2), "") != 0)
				fprintf(stdout, "(%d)%s\t", instructionTable[i].arg2.type, getValue(instructionTable[i].arg2));

			if (instructionTable[i].result.type != 0 || strcmp(getValue(instructionTable[i].result), "") != 0)
				fprintf(stdout, "(%d)%s\n", instructionTable[i].result.type, getValue(instructionTable[i].result));


			fprintf(fptr, "%d:\t%s\t", instructionTable[i].offset, getAOP_text(instructionTable[i].opcode));

			if (instructionTable[i].arg1.type != 0 || strcmp(getValue(instructionTable[i].arg1), "") != 0)
				fprintf(fptr, "(%d)%s\t", instructionTable[i].arg1.type, getValue(instructionTable[i].arg1));

			if (instructionTable[i].arg2.type != 0 || strcmp(getValue(instructionTable[i].arg2), "") != 0)
				fprintf(fptr, "(%d)%s\t", instructionTable[i].arg2.type, getValue(instructionTable[i].arg2));

			if (instructionTable[i].result.type != 0 || strcmp(getValue(instructionTable[i].result), "") != 0)
				fprintf(fptr, "(%d)%s\n", instructionTable[i].result.type, getValue(instructionTable[i].result));

		}
	}	

	fclose(fptr);
}