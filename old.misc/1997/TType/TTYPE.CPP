#include "TopType.cpp"
#include "TArgs.cpp"
#include "TDVideoA.cpp"

#include "TType.h"

void main(int iargc, char **iargv) {
  DWord IDCheck=0, StartPos=0;
  Byte ReadByte=0, LastReadByte=0;
  TTArgs=new TArgs(iargc-1, iargv+1);
  InitVars(*TTArgs);
  if (TTypeVars.TitleSwitch==TTypeVars.Titled) Title();
  if (TTArgs->argc<1) {
    FewArguments();
    return;
  }
  if ((FileIn=open(TTArgs->argv[0], O_RDONLY|O_BINARY))==-1) {
    textattr(12);cprintf("[%2X] open file error!", errno);
    textattr(7); cprintf("\r\n");
    return;
  }
  InitInts();
  if ((TTypeVars.TitleSwitch==TTypeVars.Titled)&&(TTypeVars.DoTT==TTypeVars.NotTT)) {
    textattr(3); cprintf(BeginingString, TTArgs->argv[0]);
    textattr(7); cprintf("\r\n");
  }
  Length=filelength(FileIn);
  if (Length>=4) read(FileIn, &IDCheck, 4);
  if (IDCheck!=TTID) {
    lseek(FileIn, 0, SEEK_SET);
    TTypeVars.DoTT=TTypeVars.NotTT;
  } else StartPos=4;
  for (CurPos=StartPos; CurPos<Length; CurPos++) {
    read(FileIn, &ReadByte, 1);
    if (TTypeVars.DoTT==TTypeVars.IsTT) {
      if (ReadByte==ControlChar) {
	read(FileIn, &ReadByte, 1);
	CurPos++;
	switch (ReadByte) {
	  case 'e': TTypeVars.Status=TTypeVars.Disabled;
		    continue;
	  case 'E': TTypeVars.Status=TTypeVars.Enabled;
		    continue;
	  case 'd': TTypeVars.Screen=TTypeVars.On;
		    continue;
	  case 'D': TTypeVars.Screen=TTypeVars.Off;
		    continue;
	  case 'c': read(FileIn, &ReadByte, 1);
		    if ((TTypeVars.DisplayMode==TTypeVars.InColor)&&(TTypeVars.Status==TTypeVars.Enabled)) {
		      TTypeVars.ForeColor=cton(ReadByte);
		      textcolor(TTypeVars.ForeColor);
		    }
		    break;
	  case 'C': read(FileIn, &ReadByte, 1);
		    if ((TTypeVars.DisplayMode==TTypeVars.InColor)&&(TTypeVars.Status==TTypeVars.Enabled)) {
		      TTypeVars.BackColor=cton(ReadByte);
		      textbackground(TTypeVars.BackColor);
		    }
		    break;
	  case 'B': read(FileIn, &ReadByte, 1);
		    if ((TTypeVars.DisplayMode==TTypeVars.InColor)&&(TTypeVars.Status==TTypeVars.Enabled))
		      TTypeVars.BackGround=cton(ReadByte);
		    break;
	  case 's': nosound();
		    continue;
	  case 'S': read(FileIn, &ReadByte, 1);
		    if ((TTypeVars.SoundSwitch==TTypeVars.Noise)&&(TTypeVars.Status==TTypeVars.Enabled))
		      BackSound(ReadByte*0x100);
		    break;
	  case 'P': if (TTypeVars.Status==TTypeVars.Enabled)
		      WaitForKeyPress();
		    continue;
	  case 'p': read(FileIn, &ReadByte, 1);
		    if (TTypeVars.Status==TTypeVars.Enabled)
		      delay(ReadByte*0x40);
		    break;
	  case 'm': read(FileIn, &ReadByte, 1);
		    if (TTypeVars.Status==TTypeVars.Enabled) {
		      TTypeVars.EntryTable[ReadByte]=(tell(FileIn)<Length-1)?tell(FileIn):Length-1;
		    }
		    break;
	  case 'M': read(FileIn, &ReadByte, 1);
		    if (TTypeVars.Status==TTypeVars.Enabled) {
		      TTypeVars.EntryTable[0x100+ReadByte]=(tell(FileIn)<Length-1)?tell(FileIn):Length-1;
		    }
		    break;
	  case 'u': read(FileIn, &ReadByte, 1);
		    if (TTypeVars.Status==TTypeVars.Enabled) {
		      TTypeVars.EntryTable[ReadByte]=NoEntry;
		    }
		    break;
	  case 'U': read(FileIn, &ReadByte, 1);
		    if (TTypeVars.Status==TTypeVars.Enabled) {
		      TTypeVars.EntryTable[0x100+ReadByte]=NoEntry;
		    }
		    break;
	  case 'o': read(FileIn, &ReadByte, 1);
		    if (TTypeVars.Status==TTypeVars.Enabled) {
		      MiscKey=ReadByte;
		    }
		    break;
	  case 'O': read(FileIn, &ReadByte, 1);
		    if (TTypeVars.Status==TTypeVars.Enabled) {
		      MiscKey=0x100+ReadByte;
		    }
		    break;
	  case 'b': if (TTypeVars.Status==TTypeVars.Enabled) {
		      TTypeVars.EntryTable[BreakKey]=(tell(FileIn)<Length-1)?tell(FileIn):Length-1;
		    }
		    break;
	  case 'x': read(FileIn, &ReadByte, 1);
		    if ((ReadByte&0x40)&&(TTypeVars.Screen==TTypeVars.On))
		      gotoxy(wherex()+ReadByte&0x3F, wherey());
		    else gotoxy(wherex()-ReadByte&0x3F, wherey());
		    break;
	  case 'y': read(FileIn, &ReadByte, 1);
		    if ((ReadByte&0x40)&&(TTypeVars.Screen==TTypeVars.On))
		      gotoxy(wherex(), wherey()+ReadByte&0x3F);
		    else gotoxy(wherex(), wherey()-ReadByte&0x3F);
		    break;
	  case 'X': read(FileIn, &ReadByte, 1);
		    if (TTypeVars.Screen==TTypeVars.On)
		      gotoxy((ReadByte&0x7F)%80+1, wherey());
		    break;
	  case 'Y': read(FileIn, &ReadByte, 1);
		    if (TTypeVars.Screen==TTypeVars.On)
		      gotoxy(wherex(), (ReadByte&0x1F)%25+1);
		    break;
	  case 'T':
		    break; // Internal Font select
	  case 'F': Byte FontData[16]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		    read(FileIn, &ReadByte, 1);
		    read((Word)FileIn, FontData, 16);
		    if (TTypeVars.Screen==TTypeVars.On)
		      TSetCharMap(ReadByte, 1, FontData);
		    CurPos+=17; continue;
	  case 'f': if (TTypeVars.Screen==TTypeVars.On)
		      TResetCharMap();
		    continue;
	  case 'z': if (TTypeVars.Screen==TTypeVars.On)
		      goto LabelTTEnd;
		    continue;
	  case EnhancedChar:
		    read(FileIn, &ReadByte, 1);
		    CurPos++;
		    switch(ReadByte) {
		      case 'i': // include another	->'\x0'
				break;
		      case 'D': // Dos Shell		->'\x0'
				break;
		      case 'd': // Assembler		->'\x0'->size,
				//			->read size bytes of machine codes
				//			->append ret
				//			->call codes
		      default: ;
		    }
		    break;
	  case ControlChar: goto DisplayChar;
	}
	CurPos++;
	continue;
      } // switch
    } // if tt
DisplayChar:
    if (TTypeVars.Screen==TTypeVars.On) {
      if (ReadByte&0x10) putch(ReadByte);
      else {
	int FromX=wherex()-1;
	switch (ReadByte) {
	  case '\n': if (LastReadByte!='\r') putch(ReadByte);
		     break;
	  case '\r': textbackground(TTypeVars.BackGround);
		     for (Byte LineFeedCount=FromX; LineFeedCount<80; LineFeedCount++)
		       putch(' ');
		     textbackground(TTypeVars.BackColor);
		     break;
	  case 9:    for (Byte TableCount=FromX; TableCount<=(FromX|0x7); TableCount++)
		       putch(' ');
		     break;
	  default:   putch(ReadByte);
	} // switch
      } // if readbyte>'r',else
    }
    LastReadByte=ReadByte;
  } // for curpos
LabelTTEnd:
  if ((TTypeVars.TitleSwitch==TTypeVars.Titled)&&(TTypeVars.DoTT==TTypeVars.NotTT)) {
    textattr(3); cprintf(TrailingString, TTArgs->argv[0]);
    textattr(7); cprintf("\r\n");
  }
  TTEnd();
}

CTTypeVars::CTTypeVars() {
  DisplayMode=InColor;
  Page=NoPaging;
  EOFTreat=EOFGoOn;
  DoTT=IsTT;
  MakeDump=NoDump;
  DumpAddress=DumpWithAddress;
  DumpBytesOneLine=16;
  SoundSwitch=Noise;
  TitleSwitch=Titled;
  BackGround=0;
  Status=Enabled;
  Screen=On;
  for (int n=0; n<512; n++) EntryTable[n]=NoEntry;
}

void Title(void) {
  textattr(14);cprintf("Topcroak ¯ Text Yare Publishing Exhibition ® version x");
  textattr(7); cprintf("\r\n");
  textattr(15);cprintf("Topcroak Software - Author - DanSei - 98 - CHINA");
  textattr(7); cprintf("\r\n");
}

void FewArguments(void) {
  textattr(10);cprintf("TTYPE <Filename> [/pmznbst]");
  textattr(7); cprintf("\r\n");

  textattr(11);cprintf("p");
  textattr(9); cprintf(" Paging");
  textattr(3); cprintf("-");
  textattr(11);cprintf("m");
  textattr(9); cprintf(" Mono");
  textattr(3); cprintf("-");
  textattr(11);cprintf("z");
  textattr(9); cprintf(" end on ^Z");
  textattr(3); cprintf("-");
  textattr(11);cprintf("n");
  textattr(9); cprintf(" Normal type");
  textattr(3); cprintf("-");
  textattr(11);cprintf("b");
  textattr(9); cprintf(" dump Bin");
  textattr(3); cprintf("-");
  textattr(11);cprintf("s");
  textattr(9); cprintf(" Silent");
  textattr(3); cprintf("-");
  textattr(11);cprintf("t");
  textattr(9); cprintf(" no Title");

  textattr(7); cprintf("\r\n");
}

void InitVars(TArgs _a) {
  char *chr;
  for (int n=0; n<_a.argc; n++) {
    if (strchr(_a.argv[n], '/')!=NULL) {
      if ((strchr(_a.argv[n], 'p')!=NULL)||(strchr(_a.argv[n], 'P')!=NULL))
	TTypeVars.Page=TTypeVars.Pagine;
      if ((strchr(_a.argv[n], 'm')!=NULL)||(strchr(_a.argv[n], 'M')!=NULL))
	TTypeVars.DisplayMode=TTypeVars.InMono;
      if ((strchr(_a.argv[n], 'z')!=NULL)||(strchr(_a.argv[n], 'Z')!=NULL))
	TTypeVars.EOFTreat=TTypeVars.EOFStop;
      if ((strchr(_a.argv[n], 'n')!=NULL)||(strchr(_a.argv[n], 'N')!=NULL))
	TTypeVars.DoTT=TTypeVars.NotTT;
      if (((chr=strchr(_a.argv[n], 'b')+1)!=NULL)||((chr=strchr(_a.argv[n], 'B')+1)!=NULL)) {
	TTypeVars.MakeDump=TTypeVars.AsDump;
	TTypeVars.DumpAddress=(*(chr-1)=='b')?TTypeVars.DumpWithoutAddress:TTypeVars.DumpWithAddress;
	TTypeVars.DumpBytesOneLine=cton(*chr)+1;
      }
      if ((strchr(_a.argv[n], 's')!=NULL)||(strchr(_a.argv[n], 'S')!=NULL))
	TTypeVars.SoundSwitch=TTypeVars.Silent;
      if ((strchr(_a.argv[n], 't')!=NULL)||(strchr(_a.argv[n], 'T')!=NULL))
	TTypeVars.TitleSwitch=TTypeVars.NoTitle;
    }
  }
}

void InitInts(void) {
  OldKeyInt=getvect(0x09);
  setvect(0x09, NewKeyInt);
  OldCtrlBreakInt=getvect(0x23);
  setvect(0x23, NewCtrlBreakInt);
}

void TTEnd(void) {
  close(FileIn);
  setvect(0x09, OldKeyInt);
  setvect(0x23, OldCtrlBreakInt);
}

void BackSound(Word Freq) {
  sound(Freq);
}

void WaitForKeyPress(void) {
  KeyPressed=0;
  while (!KeyPressed) ;
}

void interrupt NewKeyInt(...) {
  Byte ScanCode=0, CharAscii=0;
  DWord ChangeEntry=0;
  asm {
    push ax
    pushf
    mov ah, 1	// Check if key pressed ( needn't ?! )
    int 0x16
    jz _nki_nokeypress
    mov KeyPressed, 1
    xor ah, ah  // Read if key pressed
    int 0x16
    mov ScanCode, ah
    mov CharAscii, al
  }
_nki_nokeypress:
  asm {
    popf
    pop ax
  }
  (*OldKeyInt)();
  if (!KeyPressed) return;
  if ((!CharAscii)&&(!ScanCode)) { // append some fun code here for buf full
    return;
  }
  ChangeEntry=TTypeVars.EntryTable[(CharAscii)?CharAscii:0x100+ScanCode];
  if (ChangeEntry!=NoEntry) {
    CurPos=lseek(FileIn, ChangeEntry, SEEK_SET);
  }
  else if (TTypeVars.EntryTable[MiscKey] != NoEntry) {
    CurPos=lseek(FileIn, TTypeVars.EntryTable[MiscKey], SEEK_SET);
  }
}

void interrupt NewCtrlBreakInt(...) {
  if (TTypeVars.EntryTable[BreakKey] != NoEntry) {
    CurPos=lseek(FileIn, TTypeVars.EntryTable[BreakKey], SEEK_SET);
  } else {
    CurPos=Length;
    *(char *)(TrailingString + 6) = 'B';
    *(char *)(TrailingString + 7) = 'r';
    *(char *)(TrailingString + 8) = 'e';
    *(char *)(TrailingString + 9) = 'a';
    *(char *)(TrailingString + 10) = 'k';
  }
  NewKeyInt();
}

/*
  LineCount
  DisplayInTTMode(Filename)
  DisplayInDumpMode(Filename, show bin, show char)
*/