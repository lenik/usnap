#ifndef __TMISC_H

#define __TMISC_H

#include <stdio.h>

#include "TopType.h"

#define TGETIP(_VAR16)		\
	asm	db 0xE8;	\
	asm	dw 0x0000;	\
	asm	Push BX;	\
	asm	Mov BX, SP;	\
	asm	Push AX;	\
	asm	Mov AX, [BX+2];	\
	asm	Add AX, 0x0F;	\
	asm	Mov _VAR16, AX;	\
	asm	Pop AX;		\
	asm 	Pop BX		// Return _VAR16 with IP of following instruction

#define TDEFBYTESMIN(_LEN)	\
	asm 	db 0xEB, _LEN;	\
	asm	db		// Jmp Short $+_Len : DB _BYTES

#define TDEFBYTESMAX(_LEN)	\
	asm 	db 0xE9;	\
	asm	dw _LEN;	\
	asm	db 		// Jmp Near $+_Len : DB _BYTES

#define TSELFCONTROLID		\
	TDEFBYTESMIN(0x10) 0xAF, 0xAF, 'TSCI', 0xAE, 0xAE;	\
	asm	dw 0, 0, 0, 0;	// 8 Bytes Reserved

class TSelfControl {
  char *ExecuteFile;
  FILE *Handle;
public:
  enum {OK, FileError, NoIDFound} Status;
public:
  long Pointer;
public:
  TSelfControl(char *_EFName);
public:
  int TReadSelfConfigByte(Word Offset);
  int TWriteSelfConfigByte(Word Offset, Byte _Byte);
  int TReadSelfConfig(Word Offset, Byte *WriteBuf, Word ReadSize);
  int TWriteSelfConfig(Word Offset, Byte *WriteData, Word WriteSize);
};

#endif