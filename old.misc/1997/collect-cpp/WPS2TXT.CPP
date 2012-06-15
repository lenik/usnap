#include <stdio.h>
#include <dos.h>
#include <dir.h>
#include <string.h>
#include "WT.cpp"

int trans(char *p, char *n) {
  char drive[5], path[256];
  char fn[512], fn2[512];

  WpsFile f1;
  FILE *f2;

  fnsplit(p, drive, path, NULL, NULL);
  strcpy(fn, drive);
  strcat(fn, path);
  strcpy(fn2, fn);
  strcat(fn, n);
  strcat(fn2, "TRAN.TMP");

  printf("[%s] ", fn);
  if (OpenWpsFile(&f1, fn, "rb") != 0) {
    printf("error in opening file %s for read\n", fn);
    perror("");
    return 1;
  }
  if (f1.wpsfile == 1) {
    if ((f2 = fopen(fn2, "wb")) == NULL) {
      printf("error in opening temp file %s\n", fn2);
      CloseWpsFile(&f1);
      return 1;
    } else {
      if (ConvertToText(f1, f2) != 0) {
	printf("error during convertion.\n");
	fclose(f2);
	CloseWpsFile(&f1);
	return 1;
      }
      fclose(f2);
    }
  } else {
    printf("not a wps file.\n");
    CloseWpsFile(&f1);
    return 1;
  }

  CloseWpsFile(&f1);
  printf("refresh file %s\n", fn);
  remove(fn);
  rename(fn2, fn);
  return 0;
}

void main(int argc, char **argv) {
  ffblk f;

  printf("Transfer WPS files to text files	Version 1.00\nTopCroak Software	Author / DanSei	1999.4.30\n");

  if (argc < 2) {
    printf("\nsyntax: wps2txt <files...>\n");
    return;
  }

  if (findfirst(argv[1], &f, FA_ARCH) == 0) {
    trans(argv[1], f.ff_name);
    while (findnext(&f) == 0) {
      trans(argv[1], f.ff_name);
    }
  }
  printf("done!\n");
}
