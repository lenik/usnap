
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "calcdecl.h"

extern double result;

main() {
	int nWrong = 0;

	init_table();

	srand((unsigned int)time(NULL));

	for (; nWrong < 3;) {
		int rand_a = (double)rand() * 100L / RAND_MAX;
		int rand_b = (double)rand() * 100L / RAND_MAX;

		printf("\t%d + %d = ", rand_a, rand_b);

                if (incalc() == 0) {
			if ((int)result == rand_a + rand_b) {
				printf("good!\n");
			}
			else
			{
				printf("wrong!\n");
				nWrong++;
			}
		}
	}
	return 0;
}
