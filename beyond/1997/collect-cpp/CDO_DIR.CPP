
#include "cdo.h"

struct dirEntry_highsierra {
	BYTE length;
	BYTE lengthXAR;
	DWORD LBN_intel;
	DWORD LBN_motorola;
	DWORD lengthFile_intel;
	DWORD lengthFile_motorola;

	BYTE time[6];
	BYTE flags;
	BYTE reserved;

	BYTE interleaveSize;
	BYTE interleaveSkipFactor;
	WORD volumeSequence_intel;
	WORD volumeSequence_motorola;
	BYTE lengthName;
	BYTE filename_pad_systemdata[200]; 	// [N] var length
};

struct dirEntry_iso9660 {
	BYTE length;
	BYTE lengthXAR;
	DWORD LBN_intel;
	DWORD LBN_motorola;
	DWORD lengthFile_intel;
	DWORD lengthFile_motorola;

	BYTE time[7];
	BYTE flags;

	BYTE interleaveSize;
	BYTE interleaveSkipFactor;
	WORD volumeSequence_intel;
	WORD volumeSequence_motorola;
	BYTE lengthName;
	BYTE filename_pad_systemdata[200]; 	// [N] var length
};

struct dirEntry_canonicalized {
	BYTE length;
	DWORD startFile;
	WORD sizeDisk;
	DWORD lengthFile;
	BYTE time[7];
	BYTE flags;
	BYTE interleaveSize;
	BYTE interleaveSkipFactor;
	WORD volumeSequence;
	BYTE lengthName;
	BYTE filename[38];
	WORD fileVersion;
	BYTE numSystemData;
	BYTE systemData[220];
};

int GetDirectoryEntry(char *path, void *buf, int canonicalized = 1) {
	CLowCdrom cd;
	SREGS s;
	REGS r;

	r.x.ax = 0x150F;
	r.h.cl = cd.getDisk();
	r.h.ch = canonicalized ? 1 : 0;

	s.es = FP_SEG(path);
	r.x.bx = FP_OFF(path);
	r.x.si = FP_SEG(buf);
	r.x.di = FP_OFF(buf);
	int86x(0x2F, &r, &r, &s);

	// success: 0 = highsierra, -1 = iso9660, else error code
	return r.x.cflag ? r.x.ax : -r.x.ax;
}
