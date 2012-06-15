#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dir.h>
#include <dos.h>
#include <time.h>

#undef MAXPATH
#define MAXPATH	256

int fa = FA_RDONLY | FA_ARCH;
int fcount = 0, dcount = 0;
char outname[40];
char curpath[MAXPATH];
FILE *fo;
char keystr[9];

int first(const char *filename, struct ffblk *ffblk, int attrib) {
  char nfilename[MAXPATH + 80];
  strcpy(nfilename, curpath);
  strcat(nfilename, filename);
  return findfirst(nfilename, ffblk, attrib);
}

void filefunc(char *fname) {
  FILE *f;
  int i;
  char nfilename[MAXPATH + 80];

  strcpy(nfilename, curpath);
  strcat(nfilename, fname);

  fprintf(stderr, "adding file: %s\n", nfilename);
  fprintf(fo, "%8s %s ", keystr, nfilename);
  if ((f = fopen(nfilename, "rb")) == NULL) {
    fprintf(stderr, "error in opening file %s", nfilename);
    perror("");
    fputc('\n', stderr);
    return;
  }
  for (;;) {
    if ((i = fgetc(f)) == EOF) { break; }
    fputc(i, fo);
  }
  fclose(f);
}

void dirfunc() {
  fprintf(stderr, "adding dir: %s\n", curpath);
  fprintf(fo, "%8s %s\r\n", keystr, curpath);
}

void searchdir(char **fns);

void s2(struct ffblk f, char **fns) {
  int opath;

  if (strcmpi(f.ff_name, outname) == 0) {
    if (strcmp(curpath, ".\\") == 0) { return; }
  }
  if ((f.ff_attrib & FA_DIREC) != 0) {
    if (strcmp(f.ff_name, ".") == 0 || strcmp(f.ff_name, "..") == 0) {
      return;
    }
    if (strlen(curpath) + strlen(f.ff_name) + 1< MAXPATH) {
      opath = strlen(curpath);
      strcat(curpath, f.ff_name);
      strcat(curpath, "\\");
      dirfunc();
      searchdir(fns);
      curpath[opath] = '\0';
    }
  } else {
    filefunc(f.ff_name);
  }
}

void searchdir(char **fns) {
  struct ffblk f;
  int fnp;
  int opath, fnoff;
  for (fnp = 0; fns[fnp] != NULL; fnp++) {
    opath = strlen(curpath);
    fnoff = 0;
    if (strchr(fns[fnp], '\\') != NULL) {
      if (strlen(curpath) + strlen(fns[fnp]) + 2 > MAXPATH) {
	continue;
      }
      strcat(curpath, fns[fnp]);
      strrchr(curpath, '\\')[1] = '\0';
      fnoff = strrchr(fns[fnp], '\\') - fns[fnp] + 1;
    }
    if (first(fns[fnp] + fnoff, &f, fa) == 0) { s2(f, fns); }
    while (findnext(&f) == 0) { s2(f, fns); }
    curpath[opath] = '\0';
  }
}

int main(int argc, char **argv) {
  int i;
  if ((argc >= 2) && (argv[1][0] == '-')) {
    if (strchr(argv[1], 'h') != NULL) { fa |= FA_HIDDEN | FA_SYSTEM; }
    if (strchr(argv[1], 'r') != NULL) { fa |= FA_DIREC; }
    argv++[1] = argv[0];
    argc--;
  }

  if (argc < 2) {
    fprintf(stderr, "fpack [-hr] <package name> [<files...>]\n\t-h: include hidden files\n\t-r: include directories\n");
    return 1;
  }
  if (argc == 2) {
    argv[2] = "*.*";
    argv[3] = NULL;
  }

  strcpy(outname,
    strrchr(argv[1], '\\') >= argv[1] ? strrchr(argv[1], '\\') + 1 : argv[1]);

  randomize();
  for (i = 0; i < 8; i++) {
    keystr[i] = 33 + (random(100) + argv[1][i % strlen(argv[1])]) % 94;
  }
  keystr[8] = '\0';

  if ((fo = fopen(argv[1], "wb")) == NULL) {
    perror("error in opening package file");
    return 2;
  }

  strcpy(curpath, ".\\");
  searchdir(argv + 2);
  return 0;
}