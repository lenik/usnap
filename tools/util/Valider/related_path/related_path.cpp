// related_path.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <gmsg.h>

int main(int argc, char* argv[])
{
	TCHAR buf[4096];
	if (argc < 3) {
		printf("related_path <base> <obj>");
	} else {
		printf("%s\n", related_path(argv[2], argv[1], buf));
	}
	return 0;
}
