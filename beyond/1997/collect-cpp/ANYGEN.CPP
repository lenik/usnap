#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <bios.h>

#define ERROR_PARAM	1
#define ERROR_LENOVER	2
#define ERROR_TABLE	3

char *at_num	= "0123456789";
char *at_lowasc	= "abcdefghijklmnopqrstuvwxyz";
char *at_upasc	= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *at_alpha	= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *at_lvl1	= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,. ";
char *at_max	= " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

struct sasc {
  int num;
  char *asctable;
} ca, sa[6] = {
  {10, at_num},		/* 0x30 - 0x39 */
  {26, at_lowasc},      /* 0x61 - 0x7A */
  {26, at_upasc},       /* 0x41 - 0x5A */
  {52, at_alpha},       /* 0x41 - 0x5A 0x61 - 0x7A */
  {65, at_lvl1},        /* 0x30 - 0x39 0x61 - 0x7A 0x30 - 0x39 0x20 0x2C 0x2E */
  {94, at_max}          /* 0x20 - 0x7E */
};

#define MAXLENGTH	256

int length;
int speclen;
int table;

int bRandom = 0;
char strrec[MAXLENGTH + 1];

void usage(char *filename);
void dicout(int len);

int main(int argc, char **argv) {
  long lenc;

  fprintf(stderr, "\
AnyGen Utility	Version 0.01	Author : DanSei\n\
Copyright TopCroak Software	All rights reserved.\n\n");

  if (argc < 3) {
    usage(argv[0]);
    return ERROR_PARAM;
  }
  if (stricmp(argv[1], "-r") == 0) {
	bRandom = 1;
	argc--, argv++;
  }
  if (argc < 3) {
    usage(argv[-1]);
    return ERROR_PARAM;
  }
  length = strtol(argv[1], NULL, 10);
  if (length > MAXLENGTH) {
    fprintf(stderr, "Length Over!\n");
    return ERROR_LENOVER;
  }
  table = (unsigned)strtol(argv[2], NULL, 10) - 1;
  if (table >= 6) {
    fprintf(stderr, "Table select error.\n");
    return ERROR_TABLE;
  }

  ca.asctable = sa[table].asctable;
  ca.num = strlen(sa[table].asctable);

  if (bRandom) {
	double maxloop = log(10000000L);
	double base = log(ca.num);
	double maxpower = maxloop / base;
	long total = (long)pow(ca.num, length > maxpower ? maxpower : length);

	for (lenc = 0; lenc < total; lenc++) {
		char buf[MAXLENGTH + 1];
		for (int i = 0; i < length; i++) {
			buf[i] = ca.asctable[random(ca.num)];
		}
		buf[i] = '\0';
		printf("%s\n", buf);
		/* check if key pressed */
		if (bioskey(_KEYBRD_READY)) break;
	}
  } else {
	  for (lenc = 1; lenc <= length; lenc++) {
	    speclen = lenc;
	    strrec[lenc] = '\x0';
	    dicout(1);
	  }
  }

  return 0;
}

void usage(char *filename) {
  fprintf(stderr, "\
Syntax:\n\
	%s [-r] <length> <table>\n\
Where:  -r		random output\n\
	length:		max length generating\n\
	table		chars table selection: \n\
	1	Numeric Chars\n\
	2	Lower Chars\n\
	3	Upper Chars\n\
	4	Latin Chars\n\
	5	Alpha, \" \", \",\", \".\"\n\
	6	All printable chars\n", filename);
}

void dicout(int len) {
  int serial;
  for (serial = 0; serial < ca.num; serial++) {
    strrec[len - 1] = ca.asctable[serial];
    if (len < speclen) dicout(len + 1);
    else printf("%s\n", strrec);
  }
}