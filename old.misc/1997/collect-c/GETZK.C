
/*
 * ZK standard chinese(GB2312) font lib
 * font map getcher
 *
 *	author: dansei, 2001.1.23 z.j.
 *	all rights reserved.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BYTE	unsigned char
#define WORD	unsigned short

char *progname = NULL;

FILE *outfile = stdout;
int chr_size = 32; /* 16-point */
char *fmt_lead = "{ ", *fmt_tail = " }; ", *fmt_sep = ", ";
char *fmt_unit = "0x%02X";
int fmt_verbose = 0;

void out(char *str);
void outn(int n);
void error_chr_invalid(WORD chr);
void error_no_fontfile(char *str);
void zk_chr(WORD chr, int size);
void zk_str(BYTE *str);
void main(int, char**);

void out(char *str) {
	fprintf(outfile, str);
}

void outn(int n) {
	char strn[256];
	sprintf(strn, fmt_unit, n);
	out(strn);
}

void error_chr_invalid(WORD chr) {
	fprintf(outfile, "## invalid char %c%c ##", chr >> 8, chr & 0xFF);
}

void error_no_fontfile(char *filename) {
	fprintf(stderr, "font file \"%s\" could not find. \n", filename);
}

void zk_chr(WORD chr, int size) {
	char fontfilename[256];
	FILE *fontfile;
	long qm, wm;
	long pos;

	strcpy(fontfilename, progname);
	if (strchr(fontfilename, '\\') == NULL && strchr(fontfilename, '/') == NULL) {
		strcpy(fontfilename, "c:\\t\\soft\\");
		strcat(fontfilename, progname);
	}
	if (strrchr(fontfilename, '.')) strrchr(fontfilename, '.')[0] = '\0';
	strcat(fontfilename, ".fon");

	if ((fontfile = fopen(fontfilename, "rb")) == NULL) {
		error_no_fontfile(fontfilename);
		return;
	}

	qm = (chr >> 8) - 161;
	wm = (chr & 0xFF) - 161;
	if (qm < 0 || wm < 0) error_chr_invalid(chr);
	else {
		int i;
		out(fmt_lead);
		pos = (qm * 94 + wm) * size;
		if (fseek(fontfile, pos, SEEK_SET)) {
			error_chr_invalid(chr);
			goto cont;
		}
		for (i = 0; i < size; i++) {
			int c;
			if ((c = fgetc(fontfile)) == EOF) {
				error_chr_invalid(chr);
				goto cont;
			}
			outn(c);
			if (i + 1 < size) out(fmt_sep);
		}
	cont:
		out(fmt_tail);
	}

	fclose(fontfile);
}

void zk_str(BYTE *str) {
	int i, slen = strlen((char *)str);
	WORD eachchr;

	if (fmt_verbose) fprintf(outfile, "\"%s\": \n", str);

	for (i = 0; i < slen; i++) {
		int valid = str[i] != ' ' && str[i] != '\t' && str[i] != '\n';
		if (!valid) continue;
		eachchr = ((WORD)str[i] << 8) | str[i + 1];
		if (fmt_verbose) fprintf(outfile, "/*%c%c*/", str[i], str[i + 1]);

		zk_chr(eachchr, chr_size);
		out("\n");

		i++; /* extra incresement */
	}
}

void main(int argc, char **argv) {
	BYTE text[1024];
	FILE *textfile = NULL;

	progname = argv[0];

	while (argc > 1 && argv[1][0] == '/') {
		switch (argv[1][1] | 0x20) {
		case 'h':
		case '?':
			printf("%s\n\
		[/l<leadstr>] [/s<sepstr>] [/t<tailstr>] [/n<numfmt>] \n\
		[/v|verbose] [/f<progname force to use>]\n\
		[!<text>|<textfile> [<outfile>]] \n", progname);
			return;
		case 'l':
			fmt_lead = argv[1] + 2;
			break;
		case 's':
			fmt_sep = argv[1] + 2;
			break;
		case 't':
			fmt_tail = argv[1] + 2;
			break;
		case 'n':
			fmt_unit = argv[1] + 2;
			break;
		case 'v':
			fmt_verbose = 1;
			break;
		case 'f':
			progname = argv[1] + 2;
			break;
		default:
			fprintf(stderr, "warning: illegal control: '%s'\n", argv[1]);
		}
		argv++;
		argc--;
	}

	if (argc < 2) {
		printf("text: ");
		scanf("%s", text);
	} else {
		if (argv[1][0] == '!') {
			strcpy((char *)text, argv[1] + 1);
		} else {
			textfile = fopen(argv[1], "r");
			if (textfile == NULL) {
				perror("could not open file ");
				return;
			}
		}

		if (argc > 2) {
			outfile = fopen(argv[2], "w");
			if (outfile == NULL) {
				perror("coult not open file to write ");
				if (textfile != NULL) fclose(textfile);
				return;
			}
		}
	} /* if argc < 2 */

#define points_to_size(pn)	((pn) * (pn) / 8)
	if (strstr(progname, "16"))
		chr_size = points_to_size(16);
	else if (strstr(progname, "24"))
		chr_size = points_to_size(24);
	else if (strstr(progname, "32"))
		chr_size = points_to_size(32);
	else if (strstr(progname, "48"))
		chr_size = points_to_size(48);
	else if (strstr(progname, "64"))
		chr_size = points_to_size(64);

	if (textfile == NULL) {
		zk_str(text);
	} else {
		while (!feof(textfile)) {
			fscanf(textfile, "%s", text);
			zk_str(text);
		}
	}

	if (textfile != NULL) {
		fclose(textfile);
	}

}
