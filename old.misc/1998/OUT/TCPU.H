/***********************************
   TOPCROAK CPU EMULATOR
   DANSEI / 1998.12.18
   ALL RIGHTS RESERVED.
***********************************/

#ifndef __TCPU_H

  #define __TCPU_H

  #include "TCMacode.h"

  class TCPU {
  protected:
    Byte		WordBits;
    TCMacodeStruct	*MacodeTable;
  };

#endif