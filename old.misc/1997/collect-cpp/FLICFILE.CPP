#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <dos.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <graphics.h>

struct FLI_HEAD {
  unsigned long FLI_Size;
  unsigned int Magic;
  unsigned int FramesNumber;
  unsigned int ScreenWidth;
  unsigned int ScreenHeight;
  unsigned int Unused;
  unsigned int Flags;
  unsigned int Speed;
  unsigned long Next;
  unsigned long Frit;
  unsigned char FLI_Expand[102];
};

struct FRAMES_HEAD {
  unsigned long SizeFrame;
  unsigned int Magic;
  unsigned int Bs;
  unsigned char Expand[8];
};

struct CHUNK_HEAD {
  unsigned long SizeB;
  unsigned int TypeB;
};

struct FLC_HEAD {
  unsigned long FliSize;
  unsigned int Magic;
  unsigned int FramesNumber;
  unsigned int ScreenWidth;
  unsigned int ScreenHeight;
  unsigned int Depth;
  unsigned int Flags;
  unsigned int Speed;
  unsigned int Reserved_1;
  unsigned long CreateTime;
  unsigned long Creator;
  unsigned long UpdateTime;
  unsigned long Updater;
  unsigned int AspectX;
  unsigned int AspectY;
  unsigned char Reserved_2[0x26];
  unsigned long OffsetFrame1;
  unsigned long OffsetFrame2;
  unsigned char Reserved_3[0x28];
};

char Palette[768];
long NextFrameP, NextBP;

void VideoInit (int VideoMode) {
  asm {
    Mov AX, VideoMode
    Int 0x10
  }
}

void RWVGAPalette (int RW) {
  union REGS r;
  struct SREGS sr;
  r.x.ax=RW;
  r.x.bx=0;
  r.x.cx=256;
  r.x.dx=FP_OFF(Palette);
  sr.es=FP_SEG(Palette);
  int86x (0x10, &r, &r, &sr);
  /*
  asm {
    Mov BX, 0
    Mov CX, 256
    Mov DX, Palette
    Mov AX, (void _seg *)(void far *)Palette
    Mov ES, AX
    Mov AX, RW
    Int 0x10
  }
  */
}

void WrPixel (unsigned int DispLine, unsigned int DispCol, unsigned char ColorNum) {
  union REGS r;
  r.x.ax=0x0C00+ColorNum;
  r.x.bx=ColorNum;
  r.x.cx=DispCol;
  r.x.dx=DispLine;
  int86(0x10, &r, &r);
  /*
  asm {
    Mov AX, 0x0C00
    Add AX, (unsigned int)ColorNum
    Mov BX, 0
    Mov CX, DispCol
    Mov DX, DispLine
    Int 0x10
  }
  */
}

void DispFLICPic (int GraHandle) {
  FRAMES_HEAD FramesHMsg;
  CHUNK_HEAD BHMsg;
  unsigned int StartColorNumber;
  unsigned int ChangeColorNumber;
  unsigned char SmallBNum;
  char PixelNum;
  unsigned char ColorNum;
  unsigned char Temp;
  unsigned int DispLine, DispCol, ShowLine;
  lseek (GraHandle, NextFrameP, SEEK_SET);
  read (GraHandle, &FramesHMsg, sizeof (FramesHMsg));
  NextBP+=sizeof(FramesHMsg);
  NextFrameP+=FramesHMsg.SizeFrame;

  for (; FramesHMsg.Bs!=0; FramesHMsg.Bs--) {
    lseek (GraHandle, NextBP, SEEK_SET);
    read (GraHandle, &BHMsg, sizeof (BHMsg));
    NextBP=NextBP+BHMsg.SizeB;
    DispLine=0;
    DispCol=0;
    switch (BHMsg.TypeB) {
      case 0x04:
      case 0x0B:
	read (GraHandle, &StartColorNumber, sizeof (StartColorNumber));
	read (GraHandle, &ChangeColorNumber, sizeof (ChangeColorNumber));
	RWVGAPalette (0x1017);
	if (ChangeColorNumber== 0) {
	  read (GraHandle, (&Palette) +(StartColorNumber-1)*3, 256*3);
	} else {
	  read (GraHandle, (&Palette) +(StartColorNumber-1)*3, ChangeColorNumber*3);
	}
	RWVGAPalette (0x1012);
	break;
      case 0x07:
	sound (300);
	delay (20);
	break;
      case 0x0C:
	read (GraHandle, &DispLine, sizeof(DispLine));
	read (GraHandle, &ShowLine, sizeof(ShowLine));
	for (; ShowLine!=0; ShowLine--) {
	  read (GraHandle, &SmallBNum, sizeof (SmallBNum));
	  for (; SmallBNum!=0; SmallBNum--) {
	    read (GraHandle, &Temp, sizeof (Temp));
	    DispCol+=Temp;
	    read (GraHandle, &PixelNum, sizeof (PixelNum));
	    if (PixelNum>0) {
	      for (; PixelNum!=0; PixelNum--) {
		read (GraHandle, &ColorNum, sizeof (ColorNum));
		WrPixel (DispLine, DispCol, ColorNum) ;
		DispCol++;
	      }
	    }
	    else if (PixelNum<0) {
	      PixelNum=abs(PixelNum);
	      read (GraHandle, &ColorNum, sizeof(ColorNum));
	      for (; PixelNum!=0; PixelNum--) {
		WrPixel(DispLine, DispCol, ColorNum);
		DispCol++;
	      }
	    }
	  } // for
	  DispLine++;
	  DispCol=0;
	} // for
	break;
      case 0x0D:
	sound (600);
	delay (60);
	break;
      case 0x0F:
	while (DispLine<200) {
	  read (GraHandle, &SmallBNum, sizeof (SmallBNum));
	  for (; SmallBNum!=0; SmallBNum--) {
	    read (GraHandle, &PixelNum, sizeof(PixelNum));
	    if (PixelNum<0) {
	      PixelNum=abs(PixelNum);
	      for (; PixelNum!=0; PixelNum--) {
		read (GraHandle, &ColorNum, sizeof (ColorNum));
		WrPixel (DispLine, DispCol, ColorNum);
		DispCol++;
	      }
	    } else {
	      read (GraHandle, &ColorNum, sizeof (ColorNum));
	      for (; PixelNum != 0; PixelNum--) {
		WrPixel (DispLine, DispCol, ColorNum);
		DispCol++;
	      }
	    }
	  }
	  DispLine++;
	  DispCol=0;
	}
	break;
      case 0x10:
	sound (900);
	delay (150);
    }
  }
}

int main (void ) {
  int GraHandle;
  char GraBuf[0x256];
  char FileName[0x80];
  FLI_HEAD FliHMsg;
  FLC_HEAD FlcHMsg;
  int FlicFlag;  // =0 FLI =1 FLC
  printf ("Please input file name :");
  scanf ("%s", FileName);

  if ((GraHandle=open(FileName, O_RDONLY|O_BINARY))==-1) {
    perror ("Error:");
    return 1;
  };

  read (GraHandle, &FliHMsg, sizeof (FliHMsg));
  NextFrameP=sizeof (FliHMsg);
  NextBP=sizeof (FliHMsg);
  VideoInit(0x13);

  if (FliHMsg.Magic==0xAF12) {
    lseek (GraHandle, 0L, SEEK_SET);
    read (GraHandle, &FlcHMsg, sizeof(FlcHMsg));
    for (; FlcHMsg.FramesNumber!=0; FlcHMsg.FramesNumber--) {
      DispFLICPic(GraHandle);
    }
  } else {
    for (; FliHMsg.FramesNumber!=0; FliHMsg.FramesNumber--) {
      DispFLICPic(GraHandle);
    }
  }
  getch();
  VideoInit(0x3);
  close(GraHandle);
  return 0;
}