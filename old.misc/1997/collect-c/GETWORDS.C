
/*
 * get words from any files
 *
 * dansei, 2001.1.30 first ver
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>

#define OPENMODE		"rb"

int bDupable = 0;
int minlen = 1, maxlen = 6;

char *outfmt = "%s\n";
char buf[256], *p;
FILE *outdev = stdout;

int ischar(int c) {
	if (c >= 'a' && c <= 'z') return -1;
	if (c >= 'A' && c <= 'Z') return -1;
	if (c >= '0' && c <= '9') return -1;
	if (c == '_' || c == '-') return -1;
	return 0;
}

char *strdel(char *s, int p) {
	int l = strlen(s);
	int i;
	for (i = p; i < l; i++) s[i] = s[i + 1];
	return s + p;
}

void outword(char *word) {
	int l = strlen(word);
	if (l >= minlen) {
		fprintf(outdev, outfmt, word);
	}
}

int file_main(FILE *f) {
	int curlen = 0;
	int c;
	p = buf;
	while ((c = fgetc(f)) != EOF) {
		if (ischar(c)) {
			p[curlen++] = c;
			p[curlen] = '\0';
			if (bDupable) outword(p);
			while (curlen > maxlen) {
				if (bDupable) {
					outword(p);
					strdel(p, 0);
					curlen--;
				} else {
					outword(p);
					curlen = 0;
				}
			}
		} else {
			if (curlen != 0) outword(p);
			p[curlen = 0] = '\0';
		}
	}
	return 0;
}

void main(int argc, char **argv) {
	struct ffblk ffblk;
	if (argc < 2) {
		printf("getwords /d(duplicate is ok) /m<minlen> /M<maxlen> /f<fmt> <files...>\n");
		return;
	}

	while (argc > 1) {
		int r;

		if (argv[1][0] == '/') {
			switch (argv[1][1]) {
			case 'd': bDupable = 1; break;
			case 'f': outfmt = argv[1] + 2; break;
			case 'm': minlen = (int)strtol(argv[1] + 2, NULL, 0); break;
			case 'M': maxlen = (int)strtol(argv[1] + 2, NULL, 0); break;
			}
		} else {
			r = findfirst(argv[1], &ffblk, 0xFF);
			while (r == 0) {
				FILE *f = fopen(ffblk.ff_name, OPENMODE);
				if (f == NULL) {
					printf("open file %s: ", ffblk.ff_name);
					perror("");
					return;
				}
				file_main(f);
				fclose(f);

				r = findnext(&ffblk);
			}
		}
		argc--;
		argv++;
	}
	return;
}
