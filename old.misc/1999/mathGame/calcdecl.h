
#ifndef __SIMPLECALC_H

#define __SIMPLECALC_H

#include <math.h>

typedef double (*fncttype)(double);

struct symrec {
	char *name;
	int type;
	union {
		double var;
		fncttype fnctptr;
	} value;
	struct symrec *next;
};

typedef struct symrec	symrec;

extern double result;

extern symrec *sym_table;

struct initfnct {
	char *fname;
	fncttype fnct;
};
extern struct initfnct arith_fncts[];

struct initvar {
	char *varname;
	double value;
};
extern struct initvar buildin_vars[];

symrec *getsym(char *sym_name);
symrec *putsym(char *sym_name, int sym_type);

void listchain();

#ifdef cplusplus
//extern "C" {
#endif

int incalc();
void init_table();

#ifdef cplusplus
//}
#endif

#endif
