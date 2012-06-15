//	LOW KEYBOARD CONTROLLER 8042 PROGRAMMING
//	DANSEI	1998.11.26

#ifndef __TLKEYBRD_H

  #define __TLKEYBRD_H

  #ifndef TLK_STATUSREGISTER			// Port 64h, Read
    #define TLK_STATUSREGISTER		0x64
    #define TLK_STATUS_OUTREGHASDATA	0x01
    #define TLK_STATUS_INREGHASDATA	0x02
    #define TLK_STATUS_SYSTEMFLAG	0x04
    #define TLK_STATUS_INREGDATATYPE	0x08	// Data / Command
    #define TLK_STATUS_KEYBOARDENABLED	0x10	// Disabled / Enabled
    #define TLK_STATUS_TRANSMITTIMEOUT	0x20	// 1 = Transmit timeout (Data transmit not complete)
    #define TLK_STATUS_RECEIVETIMEOUT	0x40	// 1 = Receive timeout (Data transmit not complete)
    #define TLK_STATUS_PARITY		0x80	// 1 = Even parity rec'd, 0 = Odd parity rec'd (Should be odd)
  #endif

  #define TLK_COMMANDREGISTER		0x64	// Port 64h, Write, 8042 command register
	// Writing this port sets Bit 3 of the status register to 1 and	the
	// byte is treated as a controller command. Devices attached to the
	// 8042 should be disabled before issuing commands that return data
	// since data in the output register will be overwritten.
  #define TLK_OUTPUTREG			0x60	// Read - Should only be read if Bit 0 of status port is set to 1
  #define TLK_DATAREGISTER		0x60	// Write - Data should only be written if Bit 1 of status port is zero (Register is empty)
						// When this port is written Bit 3 of the status register is set to zero
						// and the byte is treated as a data. The 8042 uses this byte if it's expecting data for a
						// previous command, otherwise the data is written directly to the keyboard
  #ifndef TLK_COMMAND
    #define TLK_COMMAND			0x64
    #define TLK_COMMAND_READCOMMAND	0x20    // Cur. 8042 command byte is placed in port 60h
    #define TLK_COMMAND_WRITECOMMAND	0x60	// Next data byte written to port 60h is placed in 8042 command regiester
      struct TLK_COMMAND_BYTE {
	int OutRegFullIntr: 1;			// = 1 Enable
	int Unued: 1;
	int SetStatusRegister: 1;		// 1 = Set, 0 = Clear
	int KeyBrdInhibit: 1;			// 1 = Override, 0 = Allow
	int DisableKeyboard: 1;			// Disable keyboard I/O by driving clock line low
	int DisableAuxDevice: 1;		// Disable auxiliary device, drives clock line low
	int ScancodeTranslation: 1;		// 0 = AT, 1 = PC/XT
	int Reserved: 1;
      };	// 8042 Command Register
    #define TLK_COMMAND_TESTPASSWORD	0xA4	// Returned data in port 60h : FA = Installed, F1 = No password
    #define TLK_COMMAND_LOADSECURITY	0xA5	// Bytes written to port 60h will be read until a null (0) is found
    #define TLK_COMMAND_ENABLESECURITY	0xA6	// Works only if a password is already loaded
    #define TLK_COMMAND_DISABLEAUXINTERFACE \
					0xA7	// Sets Bit 5 of command register
						// Stopping auxiliary I/O by driving the clock line low
    #define TLK_COMMAND_ENABLEAUXINTERFACE \
					0xA8	// Clears Bit 5 of command register
    #define TLK_COMMAND_TESTAUXINTERFACE \
					0xA9	// Clock and data lines are tested
						// Results placed at port 60h
      enum TLK_COMMAND_TESTAUXINTERFACE_RESULT {
	NoError = 0,
	KeyBrdClockLine_StuckLow,
	KeyBrdClockLine_StuckHigh,
	KeyBrdDataLine_StuckLow,
	KeyBrdDataLine_StuckHigh
      };
    #define TLK_COMMAND_SELFTEST	0xAA	// Diagnostic result placed at port 60h
      #define TLK_COMMAND_SELFTEST_OK	0x55	// 55h = Diag. OK
    #define TLK_COMMAND_TESTKEYBRDINTERFACE \
					0xAB	// See TLK_COMMAND_TESTAUXINTERFACE
    #define TLK_COMMAND_DIAGDUMP	0xAC	// Sends 16 bytes of 8042's RAM, Current input/output port state
						// and 8042 program status word to port 60h in scan-code format
    #define TLK_COMMAND_DISABLEKEYBRD	0xAD	// Sets Bit 4 of command register
						// Stopping keyboard I/O by driving the clock line low
    #define TLK_COMMAND_ENABLEKEYBRD	0xAE	// Clears Bit 4 of command register
						// Enabling keyboard interface
    #define TLK_COMMAND_READINPUTPORT	0xC0	// Data is read from its input port (which is inaccessible to the data bus)
						// and written to output register at port 60h
						// Output register should be empty before call
      struct TLK_INPUTPORT {
	int Undefined: 4;
	int Enable2nd256k: 1;			// 1 = Enable 2nd 256K of motherboard RAM
	int ManuJumperNotInstalled: 1;		// 1 = Manufacturing jumper not installed, 0 = Installed
	int PrimaryDisplay: 1;			// 1 = MDA, 0 = CGA
	int KeyBrdNotInhibited: 1;		// 1 = Keyboard not inhibited, 0 = Keyboard inhibited
      };
    #define TLK_COMMAND_POLLINPUTPORT_LOWBITS \
					0xC1	// Bits 0 - 3 of port 1 placed in status Bits 4 - 7
    #define TLK_COMMAND_POLLINPUTPORT_HIGHBITS \
					0xC2	// Bits 4 - 7 of port 1 placed in status Bits 4 - 7
    #define TLK_COMMAND_READOUTPUTPORT	0xD0	// Data is read from 8042 output port (which is inaccessible to the data bus)
						// and placed in output register
						// Output register should be empty before call
    #define TLK_COMMAND_WRITEOUTPUTPORT	0xD1	// Next byte written to port 60h is placed in the 8042 output port
      struct TLK_OUTPUTPORT {
	int SystemResetLine: 1;
	int GateA20: 1;
	int Undefined: 2;
	int OutputBufFull: 1;
	int InputBufEmpty: 1;
	int KeyboardClock: 1;
	int KeyboardData: 1;
      };
    #define TLK_COMMAND_WRITEOUTREG	0xD2	// On PS/2 systems the next data byte written to port 60h input register is written to port 60h output register as if initiated by a device; invokes interrupt if enabled
    #define TLK_COMMAND_WRITEAUXOUTREG	0xD3	// On PS/2 systems the next data byte written to port 60h input register is written to port 60h output register as if initiated by a device; invokes interrupt if enabled
    #define TLK_COMMAND_WRITEAUXDEVICE	0xD4	// on PS/2 systems the next data byte written to input register a port at 60h is sent to the auxiliary device
    #define TLK_COMMAND_READTESTINPUTS	0xE0	// 8042 reads its T0 and T1 inputs; data is placed in output register, Bit 0, 1 = T0, T1
      struct TLK_TESTINPUTPORT {
	int KeyboardClock: 1;
	int KeyboardData: 1;
      };
    #define TLK_COMMAND_PULSEOUTPUTPORT 0xF0	// 0FxH = Pulse Output Port
	// Bits 0-3 of the 8042 output port can be pulsed low for 6 æs;
	// Bits 0-3 of command indicate which Bits should be pulsed;
	// 0=pulse, 1=don't pulse; pulsing Bit 0 results in CPU reset
	// since it is connected to system reset line.
  #endif	// TLK_COMMAND

#endif	// __TLKEYBRD_H