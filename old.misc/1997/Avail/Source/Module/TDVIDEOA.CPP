#include "TDVideoA.h"

#ifdef __DOS_H
#define TFP_SEG( fp )FP_SEG( fp )
#define TFP_OFF( fp )FP_OFF( fp )
#else
#define TFP_SEG( fp )( (unsigned )( void _seg * )( void far * )( fp ))
#define TFP_OFF( fp )( (unsigned )( fp ))
#endif

void TGetCharMap(Word CharBegin, Word CharCount, Byte *FontStartAddr, Byte InfoDesire=6) {
  Word FontStartAddrSeg=TFP_SEG(FontStartAddr), FontStartAddrOff=TFP_OFF(FontStartAddr);
  Word LengthOffset=CharBegin*((InfoDesire==2)?14:16);
  Word CopyLength=CharCount*((InfoDesire==2)?14:16);
  asm {
    push ax
    push cx
    push bx
    push si
    push di
    push bp
    push es
    push ds
    mov ax, 0x1130	// Get current character generator information
    mov bh, InfoDesire
    xor bl, bl
    int 0x10
    push es
    pop ds
    mov si, bp
    add si, LengthOffset
    mov cx, FontStartAddrSeg
    mov es, cx
    mov di, FontStartAddrOff
    mov cx, CopyLength
    rep movsb
    pop ds
    pop es
    pop bp
    pop di
    pop si
    pop bx
    pop cx
    pop ax
  }
}

void TSetCharMap(Word CharBegin, Word CharCount, Byte *FontStartAddr) {
  Word FontStartAddrSeg=TFP_SEG(FontStartAddr), FontStartAddrOff=TFP_OFF(FontStartAddr);
  asm {
    push ax
    push cx
    push dx
    push bx
    push es
    push bp
    mov ax, 0x1100	// User character load
    mov bx, 0x1000	// BH=number of bytes per character BL=table in character generator RAM
    mov cx, CharCount
    mov dx, CharBegin
    mov es, FontStartAddrSeg
    mov bp, FontStartAddrOff
    int 0x10
    pop bp
    pop es
    pop bx
    pop dx
    pop cx
    pop ax
  }
}

void TResetCharMap(void) {
  asm {
    push ax
    push bx
    mov ax, 0x1104
    mov bx, 0
    int 0x10
    pop bx
    pop ax
  }
}

void TChineseFont16(Byte Font[16][2], Byte StartAscii) {
  Byte Temp[16];
  for (Byte m=0; m<2; m++) {
    for (Byte n=0; n<16; n++)
      Temp[n]=Font[n][m];
    TSetCharMap(StartAscii, 1, Temp);
  }
}

void TChineseFont32(Byte Font[16][8], Byte StartAscii) {
  Byte Temp[16];
  for (Byte m=0; m<8; m++) {
    for (Byte n=0; n<16; n++)
      Temp[n]=Font[n][m];
    TSetCharMap(StartAscii, 1, Temp);
  }
}

void TChineseFont48(Byte Font[16][18], Byte StartAscii) {
  Byte Temp[16];
  for (Byte m=0; m<18; m++) {
    for (Byte n=0; n<16; n++)
      Temp[n]=Font[n][m];
    TSetCharMap(StartAscii, 1, Temp);
  }
}

#undef TFP_SEG
#undef TFP_OFF