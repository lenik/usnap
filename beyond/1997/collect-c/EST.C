#include <stdio.h>

#define TRUE	1
#define FALSE	0

int rmatch(FILE *f, char *s);
int getsc(FILE *f, char *buf);

int charequal(char a, char b) { return a == b ? TRUE : FALSE; }

char sc[1024];

int main(int argc, char **argv) {
  FILE *t, *f;
  int i, i1 = '\0', j, j1 = '\0';
  if (argc < 3) {
    fprintf(stderr, "eastern shining text generator	version 1.00\ntopcroak software	author/dansei	1999.4.18\n\nest <template file> <context file>\n");
    return 1;
  }
  if ((t = fopen(argv[1], "rb")) == NULL) {
    perror("error occured when open template file");
    return 10;
  }

  for (;;) {
    if ((i = fgetc(t)) == EOF) { break; }
    if (i == '\\') { i1 = i; i = fgetc(t); }
    if ((i1 != '\\') && (i == '{')) {
      /*
	 1. if a tag in template, member it in a string {...}
	 2. find start tag in source {...}
	 3. print until end tag {/...}
      */
      sc[0] = '/';
      if (getsc(t, sc + 1) != 0) {	/* there is complete tag */
	if ((f = fopen(argv[2], "rb")) == NULL) {
	  perror("error occured when open context file");
	  return 10;
	}
	for (;;) {
	  if ((j = fgetc(f)) == EOF) { break; }
		/* 1. to find out context's reletion tag */
	  if (j == '\\') { j1 = j; j = fgetc(f); }
	  if ((j1 != '\\') && (j == '{')) {
	    if (rmatch(f, sc + 1) == TRUE) {
	      /* get position next to tag */
	      for (;;) {
		/* 2. replace until meet end tag */
		if ((j = fgetc(f)) == EOF) { break; }
		if (j == '\\') { j1 = j; j = fgetc(f); }
		if (j1 != '\\') {
		  if (j == '{') {
		    if (rmatch(f, sc) == TRUE) { break; }
		  }
		  if (j == '_') {
		    fputs("&nbsp;", stdout);
		  } else {
		    fputc(j, stdout);
		  }
		} /* not \\ char */
		j1 = j;
	      } /* file end or meet end tag */
	    } /* find tag */
	  } /* that's not tag, continue finding... */
	  j1 = j;
	} /* replaced or no tag found */
	fclose(f);
	continue; /* don't output template's tag string */
      } /* a complete tag in template file */
    } /* find the 1st char of a tag and no '\\' specified */
    i1 = i;
    /* not a tag */
    fputc(i, stdout);
  } /* main loop in template file */
  fclose(t);
  return 0;
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

int getsc(FILE *f, char *buf) {
  int i, i1, p = 0;
  long op = ftell(f);
  for (;;) {
    if (p > 256) { break; }
    if ((i = fgetc(f)) == EOF) { break; }
    if (i == '\\') { i1 = i; i = fgetc(f); }
    buf[p++] = i;
    if ((i1 != '\\') && (i == '}')) {
      buf[p] = '\x0';
      return 1;
    }
    i1 = i;
  }
  buf[0] = '\x0';
  fseek(f, op, SEEK_SET);
  return 0;
}
