
%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calcdecl.h"
%}

%union {
	double	val;
	symrec	*tptr;
}

%token <val>	NUM
%token <tptr>	VAR FNCT
%type  <val>	compexp exp

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
	| compexp	{
				printf("\t%.10g\n", $1);
				result = $1;
				YYACCEPT;
			}
	| error '\n'	{ printf("error occured!\n"); yyerrok; }
;

compexp:
	exp '\n'
	| exp ',' compexp
			{ $$ = $3; }
;

exp:
	NUM
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
