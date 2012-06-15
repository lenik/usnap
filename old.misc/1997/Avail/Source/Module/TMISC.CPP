#include <string.h>

#include "TMisc.h"

TSelfControl::TSelfControl(char *_EFName) {
  int _b;
  Byte _id[0xE] = {'S', 'R', 'B', 'H', 0xAD, 0xAD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  Byte _Buf[0xE];

  for (int c = 0; c < 0xE; c++) ++_id[c];

  Status = NoIDFound;
  ExecuteFile = _EFName;
  if ((Handle = fopen(ExecuteFile, "r+b")) == NULL) {
    Status = FileError;
    return;
  }
  while ((_b = fgetc(Handle)) != EOF) {
    if (_b == 0xAF)
      if (fgetc(Handle) == 0xAF) {
	fread (_Buf, 0xE, 1, Handle);
	if (! memcmp (_id, _Buf, 0xE)) {
	  Status = OK;
	  Pointer = ftell (Handle);
	  break;
	}
      }
  }
  return;
}

int TSelfControl::TReadSelfConfigByte(Word Offset) {
  fseek (Handle, Pointer + Offset, SEEK_SET);
  return fgetc (Handle);
}

int TSelfControl::TWriteSelfConfigByte(Word Offset, Byte _Byte) {
  fseek (Handle, Pointer + Offset, SEEK_SET);
  return fputc (_Byte, Handle);
}

int TSelfControl::TReadSelfConfig(Word Offset, Byte *WriteBuf, Word ReadSize) {
  fseek (Handle, Pointer + Offset, SEEK_SET);
  return fread (WriteBuf, ReadSize, 1, Handle);
}

int TSelfControl::TWriteSelfConfig(Word Offset, Byte *WriteData, Word WriteSize) {
  fseek (Handle, Pointer + Offset, SEEK_SET);
  return fwrite (WriteData, WriteSize, 1, Handle);
}
