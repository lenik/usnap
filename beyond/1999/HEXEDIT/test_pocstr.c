
#include <stdio.h>
#include "hexedit.h"

int main(int argc, char **argv) {
	char buf[3000];
	char *p;

	if (argc < 2) {
		gets(buf);
	} else {
		strcpy(buf, argv[1]);
	}

	printf("INPUT =   %X[%s]\n", buf, buf);
	p = pocstr(buf);
	printf("CONVERT = %X[%s]\n", buf, buf);
	printf("AFTER =   %X[%s]\n", p, p);
	return 0;
}
