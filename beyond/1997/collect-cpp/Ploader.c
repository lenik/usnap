#include <dos.h>

#ifndef BYTE
#define BYTE unsigned char
#endif
#ifndef WORD
#define WORD unsigned int
#endif
#ifndef DWORD
#define DWORD unsigned long
#endif

class ExternalProgram {
protected:
	union REGS r;
	struct SREGS s;
protected:
	WORD wSS, wSP;
	WORD ErrorNo;
public:
	struct _Parameter_AL00 {
		WORD EnvSeg;	/* AL = 1 */
		WORD CmdLineOffset;	/* Pass to PSP[82H] */
		WORD CmdLineSeg;	/* Pass to PSP[80H] */
		DWORD FCB1; 	/* Pass to PSP[5CH] */
		DWORD FCB2; 	/* Pass to PSP[6CH] */
	} Parameter_AL00;
public:
	char *ProgramName;
	char *CmdLineParameters;
public:
	WORD LoadAndExecute();
	WORD GetError() { return ErrorNo; }
public:
	ExternalProgram();
	ExternalProgram(char *_n, char *_p) { ProgramName = _n; CmdLineParameters = _p; }
};

WORD ExternalProgram::LoadAndExecute() {
	Parameter_AL00.EnvSeg = 0;
	Parameter_AL00.CmdLineOffset = FP_OFF(CmdLineParameters - 1);
	Parameter_AL00.CmdLineSeg = FP_SEG(CmdLineParameters);
	Parameter_AL00.FCB1 = Parameter_AL00.FCB2 = (DWORD)-1;

	wSS = _SS;
	wSP = _SP;

	r.x.ax = 0x4B00; 	/* Load & Execute */
	s.es = s.ds = FP_SEG(ProgramName);
	r.x.dx = FP_OFF(ProgramName);
	r.x.bx = FP_OFF(&Parameter_AL00);
	intdosx(&r, &r, &s);
	ErrorNo = (r.x.flags & 1) ? r.x.ax : 0;
	disable();
	_SS = wSS;
	_SP = wSP;
	enable();
	return ErrorNo;
}
