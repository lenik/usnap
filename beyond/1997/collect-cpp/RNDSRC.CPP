#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char **argv) {
	long minlen = 1, maxlen = 0;
	unsigned long reptimes;
	char *src;
	long srcl, i;

	if (argc < 3) {
		fprintf(stderr, "RNDSRC <rep-times> <src-string> [<min-length> [<max-length>]\n");
		return;
	}

	src = argv[2];
	srcl = strlen(src);
	reptimes = strtoul(argv[1], NULL, 0);
	if (argc >= 4) {
		minlen = strtol(argv[3], NULL, 0);
		if (argc >= 5) {
			maxlen = strtol(argv[4], NULL, 0);
		}
	}

	randomize();
	while (reptimes-- > 0) {
		i = 1;
		for (i = 1; maxlen == 0 || maxlen != 0 && i <= maxlen; i++) {
			fputc(src[random(srcl)], stdout);
			if (i >= minlen || maxlen == 0) {
				if (rand() < RAND_MAX / 3) { break; }
			}
		}
		fputc(' ', stdout);
	}
	fputc('\n', stdout);
}
