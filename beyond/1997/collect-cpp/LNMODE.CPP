#include <stdio.h>

#define ERROR_PARAM	1
#define ERROR_OPEN	2

void usage(char *filename);
void openerror(char *filename);

int main(int argc, char **argv) {
  FILE *in, *out;
  int i;
  char mode = 'd';

  if (argc < 3) {
    usage(*argv);
    return ERROR_PARAM;
  }

  if ((argc > 3) && (*argv[3] == '-')) mode = argv[3][1] | 0x20;

  if ((in = fopen(argv[1], "rb")) == NULL) {
    openerror(argv[1]);
    return ERROR_OPEN;
  }

  if ((out = fopen(argv[2], "wb")) == NULL) {
    openerror(argv[2]);
    return ERROR_OPEN;
  }

  while ((i = fgetc(in)) != EOF) {
    if ((i != 0x0A) && (i != 0x0D)) {
      fputc(i, out);
      continue;
    }
    if (i != 0x0D) {
      switch (mode) {
	case 'd':
	  fputs("\x0D\x0A", out);
	  break;
	case 'u':
	  fputc('\x0A', out);
	  break;
	case 'e':
	  fputs("\x0A\x0D", out);
	  continue;
	default:
	  fputc(mode, out);
      }
    }
  }
  fclose(in);
  return 0;
}

void usage(char *filename) {
  fprintf(stderr, "\
LiNeMODE Utility\tVersion 0.01\tAuthor : DanSei\n\
TopCroak Software\tAll rights reserved.\n\
\n\
usage: \n\
\t%s <src file> <dest file> [-u|-d]\n\
\t\t-u: unix mode,\tnewline: 0Ah\n\
\t\t-d: dos mode,\tnewline: 0Dh 0Ah\t(Default.)\n\
\t\t-e: extend mode,\tnewline: 0Ah 0Dh\n\
\t\t-?: any other will used to be the line separator.\n", filename);
}

void openerror(char *filename) {
  fprintf(stderr, "error occured in opening file: %s\n", filename);
}
