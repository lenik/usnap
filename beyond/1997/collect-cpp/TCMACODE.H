/**********************************
  TOPCROAK CPU MACHINE CODE TOOLS
  DANSEI / 1998.12.18
  ALL RIGHTS RESERVED.
**********************************/

#ifndef __TCMACODE_H

  #define __TCMACODE_H

  #include "TType.h"

  /* Opcode Struct:
	Opcode's Attribution:
	  Bit	Desc.
	  31-30	Addressing Type:
				00 / Registers Addressing
				01 / Immediate Addressing
				10 / Mem Direct
				11 / Mem Indirect
		  Note: The Mem Indirect is Only Append an Immed. to Direct's.
	  29-26	Type Detail:
		For Registers Addressing:
		  Bit 29:	Register is Hiddened in Opcode
		  Bit 28-27:	Hidden Registers Counter - 1
		For Memory Addressing Counter
		  Bit 29:	Contains Immediate if This Bit Set
		  Bit 28-27:	Base Registers Counter
		  Bit 26:       (Only Valid in Memory Indirect Addressing)
				Effect Base Regs After Getting Mem Address
	  25-24	Width Specification
		  Opcode's Width = (Bits[25..24] + 1) * Byte
	  23-8	Register Detail:
		For Registers Addressing:
		  Bit 23-20:	Hidden Register Index 4
		  Bit 19-16:	Hidden Register Index 3
		  Bit 15-12:	Hidden Register Index 2
		  Bit 11-8:	Hidden Register Index 1
		For Memory Addressing:
		  Bit 23-20:	Base Register Index 4 (Reserved)
		  Bit 19-16:	Base Register Index 3
		  Bit 15-12:	Base Register Index 2
		  Bit 11-8:	Base Register Index 1
	   7-4	Addressing Modifier:
		  Bit 7:	Immediate Relative to Instruction Pointer
		  Bit 6-4:	Immediate Number * (Bits[6..4] + 1)
				(General 000)
	   3-0	Reserved
  */

  struct TCMacodeOpcodeStruct {
    int OpcodeNum	: 2;	// Total Opcodes' Number (0~3)
    int Reserved	: 14;
    DWord Opcode[3];		// Opcodes' Attribution
  };

  struct TCMacodeStruct {
    Byte Code;		// Machine Code	[ Used in a simple machine code ]
    Byte Flag;		// Base Flag Effection
    Byte FlagX[3];	// Extends Flag Effection
    TCMacodeOpcodeStruct Append;	// Opcode
    char *Desc;		// Phrase Description of This Machine Code
    void *Func;		// A Function Reference Reserved for Applications
  };

  struct TCMacodeFixRegisterStruct {
    Byte RegisterIndex;
    char *Name;
  };

  struct TCMacodeRegisterStruct {
    int ByteCount;
    TCMacodeFixRegisterStruct *RegByte;
    int WordCount;
    TCMacodeFixRegisterStruct *RegWord;
    int Word2Count;
    TCMacodeFixRegisterStruct *RegWord2;
    int DWordCount;
    TCMacodeFixRegisterStruct *RegDWord;
  };

  Byte TCMacodeLength (TCMacodeStruct tcmsInstance);

  // char *TCMacodeGeneralSource (DWord CurIP, TCMacodeStruct tcms, Byte *MemoryMap, char *SourceBuffer, Word BufferLength);

#endif