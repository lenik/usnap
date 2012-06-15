// winenv.cpp : Defines the entry point for the console application.
//

// windows GUI 层环境变量设置

#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern "C" int _stdcall MessageBoxA(void *, char *, char *, unsigned);
extern "C" int _stdcall SetEnvironmentVariableA(char *name, char *val);

#define MessageBox	MessageBoxA
#define MB_OK		0
#define SetEnv		SetEnvironmentVariableA

int main(int argc, char* argv[])
{
	if (argc < 2) {
		MessageBox(NULL, "winenv <dupenv setting file>", "winenv syntax", MB_OK);
		return 1;
	}

	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		MessageBox(NULL, "could not open the file specified. ", NULL, MB_OK);
		return 2;
	}

	char buf[1024];
	while (!feof(f)) {
		int p = 0;
		char *pe;
		for (; p < 1024 && !feof(f); p++) {
			int c = fgetc(f);
			if (c == EOF) break;
			if (c == '\n') break;
			buf[p] = c;
		}
		buf[p] = '\0';
		pe = strchr(buf, '=');
		if (pe == NULL) {
			MessageBox(NULL, buf, "syntax error. ", MB_OK);
			continue;
		}
		*(pe++) = '\0';
		printf("%s = [%s]\n", buf, pe);
		if (!SetEnv(buf, pe)) {
			*(--pe) = '=';
			MessageBox(NULL, buf, "could not setting follow envvar. ", MB_OK);
		}
	}
	fclose(f);
	return 0;
}
