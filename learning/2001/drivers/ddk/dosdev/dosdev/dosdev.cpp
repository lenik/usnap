// dosdev.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
	DWORD returnBytes;
	char buf[16384];
	returnBytes = QueryDosDevice(NULL, buf, sizeof(buf));

	for (DWORD i = 0; i < returnBytes; i++) {
		putchar(buf[i]);
		if (!buf[i]) putchar('\n');
	}
	return 0;
}
