
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define UNIT_BYTE	'b'
#define UNIT_WORD	'w'
#define UNIT_VALUE	'v'

#define NONEWLINE	-1

#define OUT(val)	{ \
	if (unitperline != NONEWLINE && unitscount % unitperline == 0) { \
		for (int indenti = 0; indenti < indent; indenti++) \
			fprintf(out, "\t"); \
	} \
	fprintf(out, destFormat, val); \
	unitscount++; \
	if (unitperline != NONEWLINE && unitscount % unitperline == 0) { \
		fprintf(out, "\n"); \
	} \
}

FILE *in 		= stdin;
FILE *out 		= stdout;

int sourceFormat	= UNIT_BYTE;

char *destFormat	= "%3d, ";

int indent		= 1; 		// unit by tab
int unitperline		= 16;
int unitscount		= 0;

void tran();
void tranv();

void main(int argc, char **argv) {
	int bHasRun = 0;
	while (argc > 1) {
		if (argv[1][0] != '-') {
			FILE *fin = fopen(argv[1], "rb");
			if (fin == NULL) {
				fprintf(stderr, "error open file %s", argv[1]);
				perror("");
			} else {
				in = fin;
				tran();
				in = stdin;
				fclose(fin);
				bHasRun = 1;
			}
		} else {
			switch (tolower(argv[1][1])) {
			case 'f':
				destFormat = argv[2];
				argc--, argv++;
				break;
			case 'i':
				indent = strtol(argv[2], NULL, 0);
				argc--, argv++;
				break;
			case 'l':
				unitperline = strtol(argv[2], NULL, 0);
				if (unitperline <= 0) unitperline = NONEWLINE;
				argc--; argv++;
				break;
			case 'o':
				{
					FILE *fout = fopen(argv[2], "w");
					if (fout == NULL) {
						fprintf(stderr, "error open file %s for output", argv[2]);
						perror("");
					} else
						out = fout;
				}
				break;
			case 'b':
				sourceFormat = UNIT_BYTE;
				break;
			case 'w':
				sourceFormat = UNIT_WORD;
				break;
			case 'v':
				sourceFormat = UNIT_VALUE;
				break;
			case 'h':
			case '?':
				fprintf(stderr, "\
data expression translator	ver 1.00	author: dansei	\n\
			topcroak software			\n\
	exptran [-f <format>] [-i <indent>] [-b|w|v]	\n\
		[-o output] [-l <units per line>]	\n\
		sources...				\n\
		(sources must be at last.)		\n\
\n\
	-b	byte					\n\
	-w	word					\n\
	-v	value					\n\
"
				);
				break;
			default:
				;
			} // switch option char
		} // if argv[][] != '-'
		argc--, argv++;
	} // while argc > 1
	if (!bHasRun) tran();
	if (out != stdout) fclose(out);
	if (in != stdin) fclose(in);
}

void tran() {
	int borw; 		// byte or word
	unitscount = 0;

	if (sourceFormat == UNIT_VALUE) {
		tranv();
		return;
	}

	while (!feof(in)) {
		int meetend = 0;
		switch (sourceFormat) {
		case UNIT_BYTE:
			borw = fgetc(in);
			if (borw < 0) meetend = 1;
			else OUT(borw);
			if (feof(in)) meetend = 1;
			break;
		case UNIT_WORD:
			borw = fread(&borw, sizeof(unsigned int), 1, in);
			if (borw == 0) meetend = 1;
			else OUT(borw);
			if (feof(in)) meetend = 1;
			break;
		}
		if (meetend) return;
	}
}

#define BUFLEN		1024
#define SAFEWIDTH	8

void tranv() {
	char buf[BUFLEN + 1], *endptr;
	int left = 0, right = -1;
	size_t reads, actreads;
	int bLastBlock = 0; 		// if it's last block,
					// no right-left>saftwidth check needed.
	long value;

	for (;;) {
		if (right >= left) {
			for (int i = left; i <= right; i++)
				buf[i - left] = buf[i];
			right -= left;
			left = 0;
		}
		reads = BUFLEN - right - 1;	// space left for fill
		actreads = fread(buf, sizeof(char), reads, in);
		if (actreads != reads) bLastBlock = 1;
		if (actreads == 0) bLastBlock = 1;
		right += reads;

		buf[right + 1] = '\0';
		while (bLastBlock || right - left + 1 >= SAFEWIDTH) {
			char *endptr = buf + left;

			value = strtol(buf + left, &endptr, 0);
			left = (int)(endptr - buf);

			OUT(value);
			if (left >= right) break;
		}
		if (bLastBlock) break;	// jump out of the infinite loop
	} // infinite loop
}
