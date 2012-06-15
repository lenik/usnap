#include <stdio.h>

void main(int argc, char **argv) {
  FILE *f;
  int c, show = 1;

  printf ("; ASM Source File Pack Program   Author / DanSei\n");
  printf ("; TopCroak Software   1998.11.2 - CHINA\n");
  if (argc<2) {
    printf ("; Usage : PackA <.ASM Source Filename>\n");
    return;
  }

  if ( (f = fopen(argv[1], "rw")) == NULL ) {
    printf ("; Error occur opening file: %s\n", argv[1]);
    perror ("; For : ");
    return;
  }

  while ( (c = getc(f)) != EOF ) {
    switch (c) {
      case 0x0a: show = 1;
		 break;
      case ';':  show = 0;
		 break;
    }
    if (show) putchar (c);
  }

  fclose (f);

  printf ("; End of File\n");
  printf ("; TopCroak Software  All Rights Reserved.\n");
}
