#include <stdio.h>

#define BYTE		unsigned char

#define TEMPFILE	"FOP$TEMP.$$$"

BYTE add(BYTE c, BYTE o) { return c + o; }
BYTE sub(BYTE c, BYTE o) { return c - o; }
BYTE rsub(BYTE c, BYTE o) { return o - c; }
BYTE and(BYTE c, BYTE o) { return c & o; }
BYTE or(BYTE c, BYTE o) { return c | o; }
BYTE xor(BYTE c, BYTE o) { return c ^ o; }
BYTE nmul(BYTE c, BYTE o) { return c * o; }
BYTE ndiv(BYTE c, BYTE o) { return c / o; }

int on = 0x01;
BYTE (*cfunc)(BYTE c, BYTE o) = xor;

void initparam(char *p) {
  switch (p[0]) {
    case 'p':
    case '+':
      cfunc = add; break;
    case 's':
    case '-':
      cfunc = sub; break;
    case 'r':
    case '_':
      cfunc = rsub; break;
    case 'a':
    case '&':
      cfunc = and; break;
    case 'o':
    case '|':
      cfunc = or; break;
    case '^':
    case 'x':
      cfunc = xor; break;
    case '*':
    case 'm':
      cfunc = nmul; break;
    case '/':
    case 'd':
      cfunc = ndiv; break;
  }
}

void usage() {
  fprintf(stderr, "\
File Operator	Version 1.00	Computer Security Assocation\n\
TopCroak Software	Author: DanSei	1999.3.30 Zhejiang, China\n\
\n\
fop [ -psraoxmd|-+-_&|^*/ [-<num>] ] <infile> [<outfile>] [<param file>]\n\
  p +	add		a &	binary and\n\
  s -	sub		o |	binary or\n\
  r _	reverse sub	x ^	binary xor\n\
  m *	multiple\n\
  d /	division	<num>	operator num\n\
  <paramfile>:	binary operator nums data file, instead of <num>\n\
  <outfile>:	results will write to <outfile>, instead of <infile>\n\
e.g.\n\
  fop -* -0x20 info.dat\n\
  fop -r secinfo.lib nul password.\n\n");
}

int main(int argc, char **argv) {
  FILE *fi = NULL, *fo = NULL, *fp = NULL;
  int i, x;

  if (argc >= 2 && argv[1][0] == '-' || argv[1][0] == '/') {
    initparam(argv[1] + 1);
    if (argc >= 3 && argv[2][0] == '-' || argv[2][0] == '/') {
      on = strtol(argv[2] + 1, NULL, 0);
      argv[2] = argv[0]; argv += 2; argc -= 2;
    } else {
      argv[1] = argv[0]; argv++; argc--;
    }
  }
  if (argc < 2) { usage(); return 1; }

  if ((fi = fopen(argv[1], "rb")) == NULL) {
    perror("error in opening source binary");
    return 2;
  }
  if ((fo = fopen(TEMPFILE, "wb")) == NULL) {
    fprintf(stderr, "error in opening temp file ");
    perror (TEMPFILE);
    return 3;
  }
  if (argc >= 4) {
    if ((fp = fopen(argv[3], "rb")) == NULL) {
      perror("error in opening parameter file");
      return 4;
    }
  }

  for (;;) {
    if ((i = fgetc(fi)) == EOF) { break; }
    if (fp != NULL) {
      if ((on = fgetc(fp)) == EOF) {
	fseek(fp, 0, SEEK_SET);
	on = fgetc(fp);
      }
    }
    x = (*cfunc)(i, on);
    fputc((BYTE)x, fo);
  }
  if (fp != NULL) { fclose(fp); }
  fclose(fo);
  fclose(fi);

  if ((fi = fopen(TEMPFILE, "rb")) == NULL) {
    fprintf(stderr, "error in opening temp file ");
    perror(TEMPFILE);
    return 11;
  }
  if ((fo = fopen(argc >= 3 ? argv[2] : argv[1], "wb")) == NULL) {
    perror("error in opening output file");
    return 12;
  }
  for (;;) {
    if ((i = fgetc(fi)) == EOF) { break; }
    fputc(i, fo);
  }
  fclose(fo);
  fclose(fi);
  remove(TEMPFILE);
  return 0;
}