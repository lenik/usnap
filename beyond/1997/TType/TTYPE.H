#ifndef __TTYPE_H

#define __TTYPE_H

#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <dos.h>
#include <conio.h>

const DWord NoEntry	=0xFFFFFFFFL;
const DWord TTID	=0x78542F04L;	// '/Tx'
const Byte ControlChar	=0x04;	// ''
const Byte EnhancedChar	=0x2F;	// '/'
const DWord BreakKey	=0x00;
const char BeginingString[]	="   Begin of file %s ¯ ¯ ¯";
const char TrailingString[]	="® ® ® Trail of file %s   ";

class CTTypeVars{
public:
  enum {InColor, InMono} DisplayMode;
  enum {NoPaging, Pagine} Page;
  enum {EOFGoOn, EOFStop} EOFTreat;
  enum {IsTT, NotTT} DoTT;
  enum {NoDump, AsDump} MakeDump;
  enum {DumpWithAddress, DumpWithoutAddress} DumpAddress;
  Byte DumpBytesOneLine;
  enum {Noise, Silent} SoundSwitch;
  enum {Titled, NoTitle} TitleSwitch;
public:
  Byte ForeColor;
  Byte BackColor;
  Byte BackGround;
  DWord EntryTable[512];
  enum {Enabled, Disabled} Status;
  enum {On, Off} Screen;
public:
  CTTypeVars();
};

int FileIn=0;
long CurPos=0, Length=0;
Word DelayCount=0;
Byte KeyPressed=0;
Word MiscKey=0x3F; // Default misc key as '?'
CTTypeVars TTypeVars;
TArgs *TTArgs=NULL;

inline Byte cton(char c) {return (c<='9')?c&0xF:(c&0xF)+9;}

void Title(void);
void FewArguments(void);
void InitVars(TArgs _a);
void InitInts(void);
void TTEnd(void);
void BackSound(Word Freq);
void WaitForKeyPress(void);

void interrupt (*OldKeyInt)(...);
void interrupt NewKeyInt(...); // ^C if Entry[3]==NoEntry
void interrupt (*OldCtrlBreakInt)(...);
void interrupt NewCtrlBreakInt(...);

#endif