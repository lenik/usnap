#include <stdio.h>
#include "TopArgs.cpp"

void main(int argc, char **argv){
  TopArgs tat(argc, argv);
  printf("\n");
  for (int n=0; n<tat.argc; n++)
    printf("tat.argv[%d]=\"%s\"\n", n, tat.argv[n]);
}
