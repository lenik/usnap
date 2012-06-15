#include "hexedit.h"

main() {
	char buf[2000];
	int i[1024];
	int c;
	gets(buf);
	getparams(buf, i);
	printf("Parameters count: %d\n", i[0]);
	for (c = 0; c <= i[0]; c++)
		printf("--> [%4d]: %ld\n", c, i[c]);
	return 0;
}
