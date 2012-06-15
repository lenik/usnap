#include <stdio.h>

void main() {
  char *a, *b;
  printf("a = %04x\tb = %04x\n", a, b);
  a = new char[2];
  b = new char[0];
  printf("a = %04x\tb = %04x\n", a, b);
  a[0] = a[1] = 'HA';
  delete a;
  delete b;
}
