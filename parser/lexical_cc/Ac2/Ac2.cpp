// Ac2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void adderror(char *s) {
	fprintf(stderr, "Ac2 error: %s\n", s);
}

//#define USE_A_ac_FRAME
#include "ac.c"

int main(int argc, char* argv[])
{
	A_ac_main();
	return 0;
}
