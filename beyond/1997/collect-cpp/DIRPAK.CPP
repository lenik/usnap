#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <dos.h>
#include <dir.h>
#include <errno.h>

#define ERROR_PARAM	1
#define ERROR_FIND	2
#define ERROR_OPEN	3
#define ERROR_WRITE	5
#define ERROR_EXIST	6

inline void usage(char *progname);
inline void errorfind(char *filename);
inline void erroropen(char *filename);
inline void errorwrite(char *filename);
inline void errorexist(char *filename);

int main(int argc, char **argv) {
  int i;
  FILE *in, *out;
  ffblk *ff, *ffobj;
  char basepath[256];
  char fullname[256];
  char searchname[256];

  fprintf(stderr, "\
DirPak Utility	Version 0.01	Author : DanSei\n\
TopCroak Software	All rights reserved.\n");

  if (argc < 2) {
    usage(argv[0]);
    return ERROR_PARAM;
  }

  if (! findfirst(argv[1], ff, FA_ARCH)) {
    while (1) {
      fprintf (stderr, "File %s exist, overwrite/append or quit ? (o/a/q) ", argv[1]);
      switch (getch() | 0x20) {
	case 'o':
	  if ((out = fopen(argv[1], "wb")) == NULL) {
	    erroropen(argv[1]);
	    return ERROR_OPEN;
	  } break;
	case 'a':
	  if ((out = fopen(argv[1], "ab")) == NULL) {
	    erroropen(argv[1]);
	    return ERROR_OPEN;
	  } break;
	case 'q':
	  errorexist(argv[1]);
	  return ERROR_EXIST;
	default:
	  fputc('\n', stderr);
	  continue;
      }
      break;
    }
  } else {	/* if not found argv[1] */
    if ((out = fopen(argv[1], "wb")) == NULL) {
      erroropen(argv[1]);
      return ERROR_OPEN;
    }
  }
  if (findfirst(argv[1], ffobj, FA_ARCH | FA_RDONLY | FA_HIDDEN | FA_SYSTEM)) {
    errorfind(argv[1]);
    return ERROR_FIND;
  }
  strcpy(searchname, (argc > 2) ? argv[2] : "*.*");
  if (findfirst(searchname, ff, FA_ARCH | FA_RDONLY)) {
    errorfind(searchname);
    return ERROR_FIND;
  }	/* if not found source files */

  strcpy(basepath, ".\\");
  if ((argc > 2) && strrchr(argv[2], '\\')) {
    strcpy(basepath, argv[2]);
    *(strrchr(basepath, '\\') + 1) = '\x0';
  }

  do {
    strcpy(fullname, basepath);
    strcat(fullname, ff->ff_name);
    fputs(fullname, stderr);
    if (! strcmp(ff->ff_name, ffobj->ff_name)) {
      fputs(" Skipped.\n", stderr);
      continue;
    }
    fputc('\n', stderr);
    fputs(fullname, out);
    fputc('\n', out);
    if ((in = fopen(fullname, "rb")) == NULL) {
      erroropen(fullname);
      return ERROR_OPEN;
    }
    while ((i = fgetc(in))!= EOF) {
      if (i == 0x1A) break;	/* EOF */
      fputc(i, out);
    }
    fclose(in);
  } while (! findnext(ff));	/* loop until find no more files */

  fclose(out);
  return 0;
}

inline void usage(char *progname) {
  char filename[30];
  fnsplit(progname, NULL, NULL, filename, NULL);
  fprintf(stderr, "\nSyntax: %s <PacketFilename> [<SearchPattern>]\n", filename);
  fprintf(stderr, "\tSearchPattern: Contain source files, as x:\w*.*\n");
}

inline void errorfind(char *filename) {
  fprintf(stderr, "\nError occur in finding file: %s\n", filename);
}

inline void erroropen(char *filename) {
  fprintf(stderr, "\nError occur in opening file: %s\n", filename);
}

inline void errorwrite(char *filename) {
  fprintf(stderr, "\nError occur in writing file: %s\n", filename);
}

inline void errorexist(char *filename) {
}