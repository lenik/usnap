
%{
#include <stdio.h>
#include <math.h>
#include "calc.h"
%}

%union {
	double val;
	symrec *tptr;
}

%token <val>	NUM
%token <tptr>	VAR FNCT
%type  <val>	exp

%right	'='
%left	'+' '-'
%left	'*' '/'
%left	NEG
%right	'^'

%%

input:
	| input line
;

line:
	'\n'
	| exp '\n'	{ printf("\t%.10g\n", $1); }
	| error '\n'	{ printf("error occured!\n"); yyerrok; }
;

exp:
	NUM		{ $$ = $1; }
	| VAR		{ $$ = $1->value.var; }
	| VAR '=' exp	{ $$ = $3; $1->value.var = $3; }
	| FNCT '(' exp ')'
			{ $$ = (*($1->value.fnctptr))($3); }
	| exp '+' exp	{ $$ = $1 + $3; }
	| exp '-' exp	{ $$ = $1 - $3; }
	| exp '*' exp	{ $$ = $1 * $3; }
	| exp '/' exp 	{ $$ = $1 / $3; }
	| '-' exp %prec NEG
			{ $$ = -$2; }
	| exp '^' exp	{ $$ = pow($1, $3); }
	| '(' exp ')'	{ $$ = $2; }
	| '$'		{ listchain(); }
;

%%

yyerror(char *s) {
	printf("%s\n", s);
}

int init_table() {
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

	return 0;
}

#include <ctype.h>

int yylex() {
	int c;

	while ((c = getchar()) == ' ' || c == '\t') ;

	if (c == EOF) return 0;

	if (c == '.' || isdigit(c)) {
		ungetc(c, stdin);
		scanf("%lf", &yylval.val);
		return NUM;
	}

	if (isalpha(c)) {
		symrec *s;
		static char *symbuf = 0;
		static int length = 0;
		int i;

		if (length == 0) {
			length = 40;
			symbuf = (char *)malloc(length + 1);
		}

		i = 0;
		do {
			if (i == length) {
				length *= 2;
				symbuf = (char *)realloc(symbuf, length + 1);
			}
			symbuf[i++] = c;
			c = getchar();
		} while (c != EOF && isalnum(c));

		ungetc(c, stdin);
		symbuf[i] = '\0';
		s = getsym(symbuf);
		if (s == 0)
			/* if the symbol doesn't exist in symbol table,
			   just added it and return the symbol new created.
			*/
			s = putsym(symbuf, VAR);
		yylval.tptr = s;
		return s->type;
	}

	return c;
}
