
/*****************************************
	batch files modifier
		by dansei
******************************************/

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <dir.h>
#include <string.h>
#include <errno.h>

#define TRUE		1
#define FALSE		0

/*
 * modify a byte within the specified file
 * parameters ignored:
 */

int modifyByte(const char *filename, long pos, unsigned char byte) {
	FILE *f = fopen(filename, "rb+");

	if (f == NULL) {
		fprintf(stderr, "open file %s", filename);
		perror("");
		return FALSE;
	}

	if (fseek(f, pos, SEEK_SET) != 0) {
		fprintf(stderr, "seek file %s error", filename);
		perror("");
		fclose(f);
		return FALSE;
	}

	if (fwrite(&byte, 1, 1, f) != 1) {
		fprintf(stderr, "write data of file %s", filename);
		perror("");
		fclose(f);
		return FALSE;
	}

	fclose(f);

	return TRUE;
}

int processlistfile(const char *listfile) {
	FILE *lf = fopen(listfile, "rt");
	char filenamebuf[1024];
	long pos = 0;
	unsigned char byte = 0;
	int bHasError = FALSE;

	if (lf == NULL) {
		fprintf(stderr, "error open modify-list file %s", listfile);
		perror("");
		return FALSE;
	}

	do {
		filenamebuf[0] = '\0';
		fscanf(lf, "%s", filenamebuf);

		if (access(filenamebuf, 0) == 0) {
			printf("\t> %s...\n", filenamebuf);
			do {
				char buf[1024], *pBuf = buf;

				fscanf(lf, "%s", buf);
				if (strchr(buf, '*')) break;

				pos = strtol(pBuf, &pBuf, 0);
				pBuf++;
				byte = (unsigned char)strtol(pBuf, &pBuf, 0);

				if (pos < 0) break;

				if (modifyByte(filenamebuf, pos, byte) == FALSE)
					bHasError = TRUE;

			} while (!feof(lf));
		}
	} while (!feof(lf));

	fclose(lf);

	return !bHasError;

}

void main(int argc, char **argv) {
	struct ffblk ff;

	int r, c = 0;

	printf("batch files modifier by dansei\n\n");

	while (argc > 1) {

		for (r = findfirst(argv[1], &ff, 0x1F); r == 0; r = findnext(&ff), c++) {

			printf("> %s\n", ff.ff_name);

			if (processlistfile(ff.ff_name) != TRUE) {

				printf("\terror when process file: %s\n", ff.ff_name);

			}

		}

		argc--;
		argv++;

	}

	printf("\nprocess finished, total %d files\n", c);

}