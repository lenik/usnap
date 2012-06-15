#include <stdio.h>

int main(int argc, char **argv){
	int i;

	printf("argc = %d\n", argc);

	for (i = 0; i < argc; i++) {
		printf("argv[%2d] = \"", i);
		printf(argv[i]);
		printf("\"\n");
	}

	return 0;
}
