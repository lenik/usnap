// cg_LR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "..\cg.c"

enum tokentype {
	NONE = 0,
	PLUS,
	MINUS,
	AST,
	SLASH,
	POWER,
	LEFTB,
	RIGHTB,
	NUM
};

struct token {
	tokentype type;
	char *content;
	token *next;
	token() {
		type = NONE;
		content = NULL;
		next = NULL;
	}
} *ptoken, *tokens;

void A_cg_calltype A_cg_ret_plus(state S1, state S2, character c, buffer& ab) {
	ptoken->type	= PLUS;
	ptoken->content	= NULL;
	ptoken->next	= new token;
	ptoken		= ptoken->next;
	ab.clear();
	return;
}

void A_cg_calltype A_cg_ret_minus(state S1, state S2, character c, buffer& ab) {
	ptoken->type	= MINUS;
	ptoken->content	= NULL;
	ptoken->next	= new token;
	ptoken		= ptoken->next;
	ab.clear();
	return;
}

void A_cg_calltype A_cg_ret_ast(state S1, state S2, character c, buffer& ab) {
	ptoken->type	= AST;
	ptoken->content	= NULL;
	ptoken->next	= new token;
	ptoken		= ptoken->next;
	ab.clear();
	return;
}

void A_cg_calltype A_cg_ret_slash(state S1, state S2, character c, buffer& ab) {
	ptoken->type	= SLASH;
	ptoken->content	= NULL;
	ptoken->next	= new token;
	ptoken		= ptoken->next;
	ab.clear();
	return;
}

void A_cg_calltype A_cg_ret_power(state S1, state S2, character c, buffer& ab) {
	ptoken->type	= POWER;
	ptoken->content	= NULL;
	ptoken->next	= new token;
	ptoken		= ptoken->next;
	ab.clear();
	return;
}

void A_cg_calltype A_cg_ret_leftb(state S1, state S2, character c, buffer& ab) {
	ptoken->type	= LEFTB;
	ptoken->content	= NULL;
	ptoken->next	= new token;
	ptoken		= ptoken->next;
	ab.clear();
	return;
}

void A_cg_calltype A_cg_ret_rightb(state S1, state S2, character c, buffer& ab) {
	ptoken->type	= RIGHTB;
	ptoken->content	= NULL;
	ptoken->next	= new token;
	ptoken		= ptoken->next;
	ab.clear();
	return;
}

void A_cg_calltype A_cg_ret_NUM(state S1, state S2, character c, buffer& ab) {
	ptoken->type	= NUM;
	ptoken->content	= new char[ab.size() + 1];
	buffer::iterator i;
	char *p = ptoken->content;
	for (i = ab.begin(); i != ab.end(); ++i) {
		*p++ = *i;
	}
	*p = 0;
	strrev(ptoken->content);
	ptoken->next	= new token;
	ptoken		= ptoken->next;
	ab.clear();
	return;
}

void A_cg_calltype A_cg_clearB(state S1, state S2, character c, buffer& ab) {
	ab.clear();
	return;
}

/*
character A_cg_calltype A_cg_getc() {
	return (character)fgetc(stdin);
}
*/

FILE *fi = stdin;
FILE *fo = stdout;

character A_cg_calltype A_cg_getc() {
	return (character)fgetc(fi);
}


// µÝ¹éÏÂ½µ·¨·ÖÎö: ------------------------------
/*
	exp:
		|
		NUM |
		exp '+' exp |
		exp '-' exp |
		exp '*' exp |
		exp '/' exp |
		exp '^' exp |
		'(' exp ')' |
		;
	??? ( )
	left + - * /
	right ^
*/


// ---------------------------------<<<<<<<<<<<<<

void outtokens();
int main(int argc, char* argv[])
{

	if (argc > 1) {
		fi = fopen(argv[1], "r");
		if (!fi) {
			perror("error open input file");
			return -1;
		}
	}

	ptoken = tokens = new token;
	A_cg_main();

	outtokens();

	if (argc > 2) {
		fo = fopen(argv[2], "w");
		if (!fo) {
			perror("error open output file");
			return -1;
		}
	}

	//
	return 0;
}

void outtokens() {
	for (ptoken = tokens; ptoken->next; ptoken = ptoken->next) {
		switch (ptoken->type) {
		case NONE:
			printf("an empty input!");
			break;
		case PLUS:
			printf("'+'");
			break;
		case MINUS:
			printf("'-'");
			break;
		case AST:
			printf("'*'");
			break;
		case SLASH:
			printf("'/'");
			break;
		case POWER:
			printf("'^'");
			break;
		case LEFTB:
			printf("'('");
			break;
		case RIGHTB:
			printf("')'");
			break;
		case NUM:
			printf("%4.1f", strtod(ptoken->content, NULL));
			break;
		default:
			printf("<ERR>");
			break;
		}
		printf(" ");
	}
}
