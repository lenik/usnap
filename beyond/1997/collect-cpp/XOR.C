#include <stdio.h>

int main(int argc, char **argv) {
  FILE *in, *out;
  unsigned char c;
  printf("general data file xorer	dansei/1999.3.17\n");
  if (argc < 4) {
    printf("xor <source> <dest> <password>\n");
    return 1;
  }
  if ((in = fopen(argv[1], "rb")) == NULL) {
    perror("error in openning source file");
    return 2;
  }
  if ((in = fopen(argv[2], "wb")) == NULL) {
    perror("error in openning dest file");
    return 3;
  }
  while ((c = fgetc(in)) != EOF) {
    fputc(c ^ 0xFF, out);
  }
  fclose(in);
  fclose(out);
  return 0;
}
