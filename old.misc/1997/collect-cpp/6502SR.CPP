#include <stdio.h>
#include <stdlib.h>

#include "TC6502.Cpp"

void main (int argc, char **argv) {

  TC6502 CPU6502;
  FILE *BinMap;
  Word Length;

  printf ("6502 Sourcer		Author / DanSei 98.12.19\n");

  if (argc < 2) {
    printf ("Usage: 6502SR <6502 Map File> [Start Address (Hex)]\n");
    return;
  }

  CPU6502.Regs.PC = (argc > 2) ? (Word) strtol (argv[2], NULL, 0x10) : 0;

  if ((BinMap = fopen (argv[1], "rb")) == NULL) {
    printf ("Can't open file %s. ", argv[1]);
    perror ("");
    return;
  }
  fseek (BinMap, 0, SEEK_END);
  Length = (Word) ftell (BinMap);

  if ((CPU6502.MemoryMap = (Byte *) malloc (Length)) == NULL) {
    printf ("Memory out!\n");
    return;
  }
  CPU6502.MapSize = Length;

  if (fread (CPU6502.MemoryMap, Length, 1, BinMap) != Length) {
    printf ("Read file %s error. ", argv[1]);
    perror ("");
    return;
  }

  fclose (BinMap);
