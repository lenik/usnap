/**********************************
  TOPCROAK CPU MACHINE CODE TOOLS
  DANSEI / 1998.12.18
  ALL RIGHTS RESERVED.
**********************************/

#include "TCMacode.h"

Byte TCMacodeLength (TCMacodeStruct tcmsInstance) {
  Byte OpcodeCounter;
  Word EachOpcode;
  Byte TotalLength = 0;
  for (OpcodeCounter = 0; OpcodeCounter < tcmsInstance.Append.OpcodeNum; OpcodeCounter++) {
    EachOpcode = tcmsInstance.Append.Opcode[OpcodeCounter];
    switch (EachOpcode & 0xC000) {
      case 0x0000:
	TotalLength++;
	break;
      default:
	TotalLength += ((EachOpcode >> 8) & 0x03) + 1;
    }
  }
  return TotalLength;
}
