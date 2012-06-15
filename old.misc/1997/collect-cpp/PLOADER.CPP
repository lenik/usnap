#include <dos.h>
#include <stdio.h>

#ifndef BYTE
#define BYTE unsigned char
#endif
#ifndef WORD
#define WORD unsigned int
#endif
#ifndef DWORD
#define DWORD unsigned long
#endif

#define MINPARA	0x60

struct Parameter_AL00 {
  WORD EnvSeg;		/* AL = 1 */
  WORD CmdLineOffset;	/* Pass to PSP[82H] */
  WORD CmdLineSeg;	/* Pass to PSP[80H] */
  DWORD FCB1; 		/* Pass to PSP[5CH] */
  DWORD FCB2; 		/* Pass to PSP[6CH] */
};

WORD ProgramLoad(char *ProgName, char *Parameters) {
  char *LoadFile = ProgName;
  char *CmdLine = Parameters;
  union REGS r;
  struct SREGS s;

  WORD FreeMemorySize;
  WORD Stack_Seg = 0, Stack_Ptr = 0;

  struct Parameter_AL00 par_blk;
  par_blk.EnvSeg = 0;
  par_blk.CmdLineOffset = FP_OFF(CmdLine);
  par_blk.CmdLineSeg = FP_SEG(CmdLine);
  par_blk.FCB1 = par_blk.FCB2 = (DWORD)-1;

  r.h.ah = 0x48; r.x.bx = 0xFFFF; intdos(&r, &r);
  if (r.x.bx < MINPARA) { return 8; }

  Stack_Seg = _SS; Stack_Ptr = _SP;

  r.x.ax = 0x4B00; 	/* Load & Execute */
  r.x.dx = FP_OFF(LoadFile);
  r.x.bx = FP_OFF(&par_blk);
  s.es = s.ds = FP_SEG(LoadFile);
  intdosx(&r, &r, &s);
  if (r.x.flags & 1) { return r.x.ax; }
  disable();
  _SS = Stack_Seg; _SP = Stack_Ptr;
  enable();
  return 0;
}

void main() {
  ProgramLoad("c:basrun71.lib", "");
  printf("WELL");
}
