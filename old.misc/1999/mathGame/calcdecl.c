
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calcdecl.h"
#include "incalc.h"

double result;

symrec *sym_table;

struct initfnct arith_fncts[] = {
	"sin", sin,
	"cos", cos,
	"atan", atan,
	"ln", log,
	"exp", exp,
	"sqrt", sqrt,
	0, 0
};

struct initvar buildin_vars[] = {
	"pi", 3.1415926535897,
	"five", 5,
	"ten", 10,
	"hund", 100,
	0, 0
};

symrec *getsym(char *sym_name) {
	symrec *ptr;
	for (ptr = sym_table; ptr != (symrec *)0; ) {
		if (strcmp(ptr->name, sym_name) == 0) {
			return ptr;
		}
		ptr = (symrec *)ptr->next;
	}
	return 0;
}

symrec *putsym(char *sym_name, int sym_type) {
	symrec *ptr = (symrec *)malloc(sizeof(symrec));
	ptr->name = (char *)malloc(strlen(sym_name) + 1);
	strcpy(ptr->name, sym_name);
	ptr->type = sym_type;
	ptr->value.var = 0;
	ptr->next = (struct symrec *)sym_table;
	sym_table = ptr;
	return ptr;
}

void init_table() {
	int i = 0;
	symrec *ptr;

	for (i = 0; buildin_vars[i].varname != 0; i++) {
		ptr = putsym(buildin_vars[i].varname, VAR);
		ptr->value.var = buildin_vars[i].value;
	}

	for (i = 0; arith_fncts[i].fname != 0; i++) {
		ptr = putsym(arith_fncts[i].fname, FNCT);
		ptr->value.fnctptr = arith_fncts[i].fnct;
	}
}

void listchain() {
	symrec *ptr;
	for (ptr = sym_table; ptr != (symrec *)0; ptr = (symrec *)ptr->next) {
		printf("\t%-20s   type: %-10s   value: %.10g\n",
			ptr->name,
			ptr->type == VAR ? "VAR" : "FUNCTION",
			ptr->value.var
		);
	}
}
