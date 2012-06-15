// hello.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int buf[100];
	int *a = &buf[10];
	int *b = &buf[20];
	int n = b - a;
	printf("%d", n);
	return 0;
}
