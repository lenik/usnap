#include <stdio.h>
#include <dir.h>

#undef MAXPATH
#define MAXPATH	200

#define TRUE	1
#define FALSE	0

char keystr[500];

int rmatch(FILE *f, char *s) {
  int i;
  long sp = ftell(f);
  while (*s != '\0') {
    i = fgetc(f);
    if ((i == EOF) || (i != *s)) {
      fseek(f, sp, SEEK_SET);
      return FALSE;
    }
    s++;
  }
  return TRUE;
}

void fileproc(char *fname, FILE *f) {
  int i;
  FILE *fo;

  fprintf(stderr, "unpacking: %s\n", fname);

  if ((fo = fopen(fname, "wb")) == NULL) {
    fprintf(stderr, "error in opening file %s", fname);
    perror("");
    for (;;) {
      if ((i = fgetc(f)) == EOF) { break; }
      if ((char)i == keystr[0]) {
	if (rmatch(f, keystr + 1) == TRUE) { break; }
      }
    }
    return;
  }

  for (;;) {
    if ((i = fgetc(f)) == EOF) { break; }
    if ((char)i == keystr[0]) {
      if (rmatch(f, keystr + 1) == TRUE) { break; }
    }
    fputc(i, fo);
  }
}

void dirproc(char *dname, FILE *f) {
  char _dname[MAXPATH];
  int i;
  strcpy(_dname, dname);
  if (_dname[strlen(_dname) - 1] == '\\') {
    _dname[strlen(_dname) - 1] = '\0';
  }
  fprintf(stderr, "creating directory/ %s ", _dname);
  mkdir(_dname);
  for (;;) {
    if ((i = fgetc(f)) == EOF) { break; }
    if ((char)i == keystr[0]) {
      if (rmatch(f, keystr + 1) == TRUE) { break; }
    }
    fputc(i, stderr);
  }
  fputc('\n', stderr);
}

void dounpack(FILE *f) {
  char fname[MAXPATH + 80];

  fscanf(f, "%s", fname);
  fgetc(f);
  if (fname[strlen(fname) - 1] == '\\') {
    dirproc(fname, f);
  } else {
    fileproc(fname, f);
  }
  return;
}

int main(int argc, char **argv) {
  int i;
  FILE *f;
  int fnp;

  if (argc < 2) {
    fprintf(stderr, "funpack <package name> ...\n");
    return 1;
  }
  argv++;

  for (fnp = 0; argv[fnp] != NULL; fnp++) {
    if ((f = fopen(argv[fnp], "rb")) == NULL) {
      perror("error in opening package file");
      continue;
    }
    fscanf(f, "%s", keystr);
    for (;;) {
      if ((i = fgetc(f)) == EOF) { break; }
      dounpack(f);
    }
    fclose(f);
  }

  return 0;
}
