
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#ifdef __unix__
#	include <unistd.h>
#	include <sys/stat.h>
#	include <time.h>
#else
#	include <io.h>
#	include <fcntl.h>
#endif

#ifdef __MSDOS__
#	include <alloc.h>
#	include <mem.h>

#	define calloc	farcalloc
#	define free	farfree
#	define memset	_fmemset
#	define strcpy	_fstrcpy
#	define strlen	_fstrlen
#	define strchr	_fstrchr
#	define stricmp	_fstricmp
#	define strcat	_fstrcat
#	define strstr	_fstrstr
#endif

typedef unsigned char		CHAR;

#if defined (__unix__)
	typedef unsigned char *		PCHAR;
#elif defined (_WIN32)
	typedef unsigned char *		PCHAR;
#else
	typedef unsigned char far *	PCHAR;
#endif

#define HE_VERSION		"\nStandard HEX-EDIT for Linux\nVersion 1.00 release\n(C) Copyright DanSei - TopCroak Software\n\n"
#define MEM_UNIT		0x400l

#define PARA_LENGTH		0x100l

#define INBUFSIZE		0x400l

#define DUMP_BYTE		0x0000l
#define DUMP_WORD		0x0001l
#define DUMP_DWORD		0x0002l
#define DUMP_TWORD		0x0003l
#define DUMP_ASCIZ		0x0008l		/* "...", '\0' */
#define DUMP_STRING		0x0009l		/* nn, "....." */

#define DUMP_HEX		0x0000l
#define DUMP_DEC		0x0010l
#define DUMP_OCT		0x0020l
#define DUMP_BIN		0x0030l

#define DUMP_ADDRESS		0x1000l
#define DUMP_MASKCHAR		0x2000l

#ifdef __unix__
#define nonunix()
#else
#define nonunix(r) { \
	printf("warning: this function won't be work properly under non-unix operation systems. continue? (y/N) "); \
	if (tolower(getchar()) != 'y') return r; \
	printf("running forced. \n"); \
}
#endif

PCHAR buf = NULL;
char tmpdata[4096];

char filename[1024];
INT flen = 0;
INT memsize = 0x400; 		/* 4k * 1k = 4M */
INT curaddr = 0;
INT writeoffset = 0;
char maskchar = '.';
char inputbuf[INBUFSIZE], *ip;
INT inP[128];

INT dumpcontrol = (DUMP_BYTE | DUMP_HEX | DUMP_ADDRESS | DUMP_MASKCHAR);

void showhelp();
void showversion();

void analyse(char *anatype, char *param);

void dumpdata(PCHAR data, INT length, INT display_start);
INT editdata(PCHAR data, INT start_offset);

void dumpbytes(PCHAR data, INT length, INT showchar);

INT *getparams(char *params, INT buf[]);

INT getlen(FILE *f);
char *ltrim(char *s);

char *pocstr(char *linestr);
char *tobinary(INT l, char *buf, INT padsize);

char *strBool[2] = { "FALSE", "TRUE" };
#define C_NOP			' '
#define C_ANALYSE		'a'
#define C_DUMP			'd'
#define C_EDIT			'e'
#define C_WRITE			'w'
#define C_SEARCH		's'
#define C_FILL			'f'
#define C_VERSION		'v'
#define C_HELP			'?'
#define C_CONTROL		'c'
#define C_REPLACE		'r'
#define C_TRANSLATE		'.'
#define C_CALC			'+'
#define C_INIT			'i'
#define C_QUIT			'q'

void showhelp() {
	printf("\
HEX-EDIT	*shareware* tools for programmer\n\
		inline function helper\n\
--------\n\
a [modulename]	: data analyse, current support: \n\
		  ELF file	elf [32|64]\n\
		  EXT2 filsys	ext2\n\
		  Device/File	dev\n\
d [start] [end]	: dump data\n\
e [start]	: edit data\n\
w [filename]	: write to file\n\
c [bwdtzsfa82m#]\n\
		: control dump: Byte, Word, Dword, Tword, asciZ, String,  \n\
				hex:F, dec:A, oct:8, binary:2, Mask-char, \n\
				address:#\n\
r [pos]		: replace built-in vars: \n\
			p: working space pointer	o: write-Offset\n\
			s: change working-space size\n\
i [char]	: init memory with char [char]\n\
--------\n\
.n ordix translate	+-*/<>&|^ built-in calc\n\
help:?	status:??	version:v	quit:q\n\
");
}

void showversion() {
	printf("hexedit version 0.01alpha\n");
	printf("(c) copyright topcroak software\nall rights reserved. \n");
}

/*
 * Get input line to inputbuf[]
 * 	note : in unix, press control-d may make system damaged !!
 */
char *getin() {
	char *pt = inputbuf, *pc = inputbuf;
#ifdef __unix__
	strcpy(inputbuf, "NONCHANGE");
#endif
	fgets(inputbuf, INBUFSIZE, stdin);
#ifdef __unix__
	if (strcmp(inputbuf, "NONCHANGE") == 0) {
		printf("!! OPERATION FORBIDDEN !!\n");
		strcpy(inputbuf, "");
	}
#endif
	/* delete the tail \n and spaces */
	for (;strlen(inputbuf) > 0;) {
		char *lc = inputbuf + strlen(inputbuf) - 1;
		switch (*lc) {
		case ' ':
		case '\t':
		case '\n':
		case '\r':
			*lc = '\0';
			break;
		}
		if (*lc != '\0') break;
	}
	/* translate follow datas to parameters */
	getparams(inputbuf + 1, inP);
	return inputbuf;
}

INT getlen(FILE *f) {
	INT curp = ftell(f);
	INT length;
	fseek(f, 0, SEEK_END);
	length = ftell(f);
	fseek(f, curp, SEEK_SET);
	return length;
}

char *ltrim(char *s) {
	while (*s == ' ' || *s == '\t' || *s == '\r' || *s == '\n') s++;
	return s;
}

char *strrev(char *s) {
	INT l = strlen(s) - 1;
	INT i = l >> 1;
	char c;
	for (; i >= 0; i--) {
		c = s[l - i];
		s[l - i] = s[i];
		s[i] = c;
	}
	return s;
}

char *tobinary(INT l, char *buf, INT padsize) {
	INT i = 0;
	INT s = 0;
	if (l < 0) {
		l = -l;
		s = -1;
	}
	while (l > 0) {
		buf[i++] = '0' + (l & 1);
		l >>= 1;
	}
	if (i == 0) buf[i++] = '0';
	if (padsize != 0)
		for (; i < padsize; i++)
			buf[i] = '0';
	buf[i] = '\0';
	strrev(buf);
	return buf;
}

INT *getparams(char *params, INT buf[]) {
	buf[0] = 0;
	while (*params) {
		params = ltrim(params);
		buf[++buf[0]] = strtol(params, &params, 0);
		if (*params) params++;
	}
	return buf;
}

/*
 * function next:
 *	return the next <i>'s word, or left-trim s if <i> = 0
 *	return NULL if that didn't exist.
 */
char *next(char *s, INT i) {
	s = ltrim(s);
	for (; i > 0; i--, s = ltrim(s)) {
		if (*s == '\0') return NULL;
		while (*s && *s != ' ' && *s != '\t' && *s != '\r' && *s != '\n') s++;
	}
	return s;
}

/*
 * separate linestr into 2 part, the 1st part is a word, and return the
 * pointer to the 2nd part
 *
 * function percolates standard escape char and support double quoted
 * string
 *
 */
char *pocstr(char *linestr) {
	char *begin = linestr, *end, *pcur, *ptran;
	INT finished = 0, quoted = 0;

	for (;; linestr++) {
		switch (*linestr) {
		case '\\':
			if (quoted) {
				*linestr++ = '\0';
				switch (*linestr) {
				case 'n': *linestr = '\n'; break;
				case 'r': *linestr = '\r'; break;
				case 'a': *linestr = '\a'; break;
				case 'b': *linestr = '\b'; break;
				case '0':
					*linestr++ = (char)strtol(linestr, &pcur, 8);
					for (; linestr < pcur; linestr++) *linestr = '\0';
					linestr--; 		/* for it will be increased */
					break;
				case 'x':
					*linestr++ = (char)strtol(linestr + 1, &pcur, 16);
					for (; linestr < pcur; linestr++) *linestr = '\0';
					linestr--; 		/* for it will be increased */
					break;
				case 'v': *linestr = '\v'; break;
				}
			}
			break;
		case ' ':
		case '\t':
		case '\n':
		case '\r':
			if (quoted) break;
			*linestr = '\0';
			end = linestr + 1;
			finished = 1;
		case '\"':
			quoted = 1 - quoted;
			*linestr = '\0';
			break;
		case '\0':
			finished = 1;
			end = linestr;
			break;
		}
		if (finished) break;
	}

	/* defragment */
	for (ptran = pcur = begin; pcur < linestr; ptran++) {
		while (*pcur == '\0' && pcur < linestr) pcur++;
		*ptran = *pcur++;
	}
	*ptran = '\0';
	return end;
}

void listdir(char *pathname) {
	char commandbuf[1024];
#ifdef __unix__
	sprintf(commandbuf, "ls -FANo %s", pathname);
#else
	sprintf(commandbuf, "dir %s", pathname);
#endif
	system(commandbuf);
}
