#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
int	tolower(int ch);
#ifdef __cplusplus
}
#endif

#define TRUE	1
#define FALSE	0

#define MAXSTR	3000
char s[3100], d[3100];

int ignorecase = FALSE;
int silent = FALSE;

void about();
void makestr(char *s, char r[]);
int charequal(char, char);
int rmatch(FILE *f, char *s);
void copyto(FILE *f, char *destname, int over, char *errstr);

FILE *fopenx(char *, char *);
FILE *openx(int mode) {
  FILE *f;
  int os = silent;
  silent = TRUE;
  f = fopenx("FREPLTMP.$$$", mode == 0 ? "wb" : "rb");
  silent = os;
  return f;
}

int main(int argc, char **argv) {
  int i, count = 0, self = FALSE;
  FILE *f, *fo;

  if (argc >= 2) {
    if ((argv[1][0] == '-') || (argv[1][0] == '/')) {
      if (strchr(argv[1], '?') != NULL) {
	about();
	return 0;
      }
      if (strchr(argv[1], 's') != NULL) { silent = TRUE; }
      if (strchr(argv[1], 'i') != NULL) { ignorecase = TRUE; }
      if (strchr(argv[1], 'm') != NULL) { self = TRUE; }
      argv[1] = argv[0];
      argv++;
      argc--;
    }
  }
  if (argc < 4) {
    fprintf(stderr, "frepl [-?sim] <src> <dest> <infile> [<outfile>]\n");
    return 1;
  } else {
    if ((self == TRUE) || (argc >= 5)) {
      if ((fo = openx(0)) == NULL) {
	perror("error in opening temp file FREPLTMP.$$$");
	return 10;
      }
    } else { fo = stdout; }
  }

  makestr(argv[1], s);
  makestr(argv[2], d);
  if (silent == FALSE) { fprintf(stderr, "Source string = \"%s\"\nDest string = \"%s\"\n", s, d); }

  if ((f = fopenx(argv[3], "rb")) == NULL) {
    if (silent == FALSE) { perror("error in opening source file"); }
    return 2;
  }

  for (;;) {
    if ((i = fgetc(f)) == EOF) {
      break;
    }
    if (charequal(i, s[0]) == TRUE) {	/* 1st matched */
      if (rmatch(f, s + 1) == TRUE) {
	if (silent == FALSE) { fprintf(stderr, "\rCount = %04d   ", ++count); }
	fputs(d, fo);
      } else {
	fputc(i, fo);
      }
    } else {
      fputc(i, fo);
    }
  }
  fclose(f);
  fclose(fo);

  if (silent == FALSE) { fprintf(stderr, "\n"); }

  if ((self == TRUE) || (argc >= 5)) {
    if ((f = openx(1)) == NULL) {
      if (silent == FALSE) { perror("error in preparing to read temp file FREPLTMP.$$$"); }
      return 21;
    }
    if (silent == FALSE) { fprintf(stderr, "rewrite file...\n"); }
    if (self == TRUE) { copyto(f, argv[3], TRUE, "error in preparing to write infile"); }
    if (argc >= 5) { copyto(f, argv[4], FALSE, "error in preparing to write outfile"); }
    fclose(f);
    if (silent == FALSE) { fprintf(stderr, "deleting temp file...\n"); }
    remove("FREPLTMP.$$$");
  }

  return 0;
}

void about() {
  fprintf(stderr, "\
file replace	version 2.00\n\
topcroak software - author: dansei - 1999.4.1 - zhejiang china\n\
frepl [-sim] <[@]src(file)> <[@]dest(file)> <infile> [<outfile>]\n\
	-s	silent mode\n\
	-i	ignore case\n\
	-m	(my) write to self (default write to standard out)\n\
	[@]	get from file\n\
src/dest string can contain some translating chars, as \\n, \\t, \\x34, \\063\n\
for example, dd.dat is a file has only \"you are\", and type:\n\
> frepl -sm i\\x20am @dd.dat intro.txt\n\
will replace \"i am\" in file intro.txt to \"you are\", no error displayed.\n");
}

FILE *fopenx(char *filename, char *mode) {
  FILE *tf;
  if (strchr(mode, 'w') != NULL) {
    if ((tf = fopen(filename, "r")) != NULL) {
      fclose(tf);
      if (silent == FALSE) {
	fprintf(stderr, "file %s has already exist, overwrite it? ", filename);
	if (tolower(getc(stdin)) != 'y') { return NULL; }
      }
    }
  }
  return (tf = fopen(filename, mode));
}

void makestr(char *s, char r[]) {
  char n[5];
  int p = 0, pi, i;
  FILE *df;

  if ((s[0] == 0) || ((s[0] == '\\') && (s[1] == '0'))) {
    r[0] = '\0';
    return;
  }

  if (s[0] == '@') {
    if ((df = fopenx(s + 1, "rb")) == NULL) {
      if (silent == FALSE) { perror("error in opening param. file"); }
    }
    for (;p < MAXSTR;p++) {
      if ((i = fgetc(df)) == EOF) { break; }
      r[p] = i;
    }
    r[p] = '\0';
    fclose(df);
    return;
  }

  while ((*s != '\0') && (p < MAXSTR)) {
    if (*s != '\\') {
      r[p++] = *s++;
    } else {
      s++;
      switch (*s) {
	case '\\':	r[p++] = '\\'; s++; break;
	case 'a':	r[p++] = '\a'; s++; break;
	case 'b':	r[p++] = '\b'; s++; break;
	case 'n':	r[p++] = '\n'; s++; break;
	case 't':	r[p++] = '\t'; s++; break;
	default:
	  if ((*s >= '0') && (*s <= '7')) {
	    for (pi = 0;(*s >= '0') && (*s <= '7');pi++) {
	      n[pi] = *s++;
	      if (pi >= 2) {
		break;
	      }
	    }
	    n[pi + 1] = '\0';
	    r[p++] = (char)strtol(n, (char **)NULL, 8);
	  } else {
	    if (tolower(*s) == 'x') {
	      s++;
	      for (pi = 0;;pi++) {
		if ((tolower(*s) >= 'a' && tolower(*s) <= 'f') || ( (*s >= '0') && (*s <= '9'))) {
		  n[pi] = *s++;
		  if (pi >= 1) {
		    break;
		  }
		} else {
		  break;
		}
	      }
	      n[pi + 1] = '\0';
	      r[p++] = (char)strtol(n, (char **)NULL, 16);
	    }
	    else {
	      r[p++] = *s;
	    } /* is a numeric trans */
	  }
      } /* switch (*s) */
    } /* if '\\' */
  } /* while *s */
}

int charequal(char a, char b) {
  if (ignorecase != TRUE) {
    return a == b ? TRUE : FALSE;
  } else {
    return tolower(a) == tolower(b) ? TRUE : FALSE;
  }
}

int rmatch(FILE *f, char *s) {
  int i;
  long sp = ftell(f);
  while (*s != '\0') {
    i = fgetc(f);
    if ((i == EOF) || (charequal(i, *s) != TRUE)) {
      fseek(f, sp, SEEK_SET);
      return FALSE;
    }
    s++;
  }
  return TRUE;
}

void copyto(FILE *f, char *destname, int over, char *errstr) {
  int i;
  FILE *fo;
  int osilent = silent;
  silent = over;
  fo = fopenx(destname, "wb");
  silent = osilent;
  if (fo == NULL) {
    if (silent == FALSE) { perror(errstr); }
    return;
  }
  for (;;) {
    i = fgetc(f);
    if (i == EOF) {
      break;
    }
    fputc(i, fo);
  }
  fclose(fo);
}