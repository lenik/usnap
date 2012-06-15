#include <stdio.h>
#include <string.h>

FILE *outdev;

void dump(FILE *f) {
	int c;
	while (!feof(f)) {
		c = fgetc(f);
		if (c == EOF) break;
		fputc(c, outdev);
	}
}

int main(int argc, char **argv) {
	FILE *lead, *tail;
	int i, j;
	int tailln = 0;
	char tmp[16384];
	int dumptofile = 0;

	outdev = stdout;

	strcpy(tmp, argv[0]);
	strlwr(tmp);
	if (strstr(tmp, "echof") != NULL) {
		outdev = fopen("dumpfile.ecf", "a");
		if (outdev == NULL) {
			perror(argv[0]);
			return -1;
		}
		dumptofile = 1;
	}

	if ((lead = fopen("echolead.txt", "rt")) != NULL) {
		dump(lead);
		fclose(lead);
	}

	i = 0;
	for (j = 0; j < strlen(argv[0]); j++) {
		char c = argv[0][j];
		if (c > 'A' && c < 'Z') {
			i++;
			tailln = 1;
		}
		else break;
	}

	for (; i < argc; i++) {
		fprintf(outdev, "%s", argv[i]);
		if (i != argc - 1) fprintf(outdev, " ");
	}

	if ((tail = fopen("echotail.txt", "rt")) != NULL) {
		dump(tail);
		fclose(tail);
	}

	if (tailln) fprintf(outdev, "\n");

	if (dumptofile) {
		fclose(outdev);
	}

	return 0;
}
