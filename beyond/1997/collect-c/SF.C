#include <stdio.h>
#include <stdlib.h>

void main(int argc, char **argv) {
  long size;
  int i;
  FILE *f, *f1, *f2;
  if (argc < 5) {
   printf("sf <size> mainfile head tail\n");
   return;
  }
  size = strtol(argv[1], NULL, 0);
  if (size <= 0) {
    printf("size error.\n");
    return;
  }
  if ((f = fopen(argv[2], "rb")) == NULL) { perror("error main"); return; }
  if ((f1 = fopen(argv[3], "wb")) == NULL) { perror("error head"); return; }
  if ((f2 = fopen(argv[4], "wb")) == NULL) { perror("error tail"); return; }
  while (size--) {
    i = fgetc(f);
    if ( i == EOF) break;
    fputc(i, f1);
  }
  while ((i = fgetc(f)) != EOF) {
    fputc(i, f2);
  }
  fclose(f);
  fclose(f1);
  fclose(f2);
  printf("well done!\n");
}
