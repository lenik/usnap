// LAc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "helper.h"
#include "StateHelper.h"

void compile() {

// 1, lexical analyse for .L files
}


FILE *fa, *fl;
char word[10][100], t[100];

void compile();

int main(int argc, char* argv[])
{
	printf("Lexical by Automation compiler\n");
	if (argc < 3) {
		printf("syntax: LAc <lexical> <automation>\n");
		return 0;
	}

	fl = fopen(argv[1], "r");
	fa = fopen(argv[2], "w");

	if (!fa || !fl) {
		printf("error open\n");
		return 0;
	}

	compile();

	fclose(fa);
	fclose(fl);
	return 0;
}
