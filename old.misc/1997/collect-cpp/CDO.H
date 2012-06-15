
#ifndef __CDO_H

#define __CDO_H

#include <dos.h>
#include <mem.h>

#define CDROM_SECTOR_SIZE	2048

#ifndef NULL
#	define NULL		(void *)0
#endif

#ifndef TRUE
#	define TRUE		1
#endif

#ifndef FALSE
#	define FALSE		0
#endif

typedef unsigned char	BYTE;
typedef BYTE *		LPBYTE;
typedef int		BOOL;
typedef unsigned	WORD;
typedef unsigned long	DWORD;

class CLowCdrom {
	REGS	r;
	SREGS	s;
private:
	BYTE	ndxDisk;
	LPBYTE	lpBuffer;
	BYTE	nBufferSize;
	BOOL	bufferLocked;
	int	error;
private:
	BOOL	absoluteReadOneSector(DWORD sector, LPBYTE buf);
public:
	BYTE	getDisk() { return ndxDisk; }
	BYTE	getBufferSize() { return nBufferSize; }
	int	getError() { return error; }
public:
	BOOL	setBufferSize(int nBufSectors);
	BOOL	absoluteReadSector(DWORD sector);
	BOOL	absoluteRead(long address);
	LPBYTE	LockBuffer();
	void	UnlockBuffer();

public:
	BOOL	init();
public:
		CLowCdrom();
		CLowCdrom(int nBufSectors);
		~CLowCdrom();
};

BOOL CLowCdrom::init() {
	ndxDisk 	= 0;
	lpBuffer	= NULL;
	nBufferSize	= 0;
	bufferLocked	= FALSE;
	error		= 0;

	r.x.ax	= 0x1500;
	r.x.bx	= 0;
	int86(0x2F, &r, &r);		// get driver states
	if (r.x.cx) {
		ndxDisk		= r.x.cx;
		return TRUE;
	}

	return FALSE;
}

CLowCdrom::CLowCdrom() {
	if (init())
		setBufferSize(1);
}

CLowCdrom::CLowCdrom(int nBufSectors) {
	if (init())
		setBufferSize(nBufSectors);
}

CLowCdrom::~CLowCdrom() {
	if (lpBuffer != NULL) delete[] lpBuffer;
}

BOOL CLowCdrom::setBufferSize(int nBufSectors) {
	if (bufferLocked) return FALSE;
	if (nBufSectors > 0) {
		if (lpBuffer != NULL) delete[] lpBuffer;
		// reserved 1 sector for internal using.
		lpBuffer = new BYTE[CDROM_SECTOR_SIZE * (nBufSectors + 1)];
		if (lpBuffer != NULL) {
			nBufferSize	= nBufSectors;
			return TRUE;
		}
	}
	return FALSE;
}

BOOL CLowCdrom::absoluteReadOneSector(DWORD sector, LPBYTE buf) {
	r.x.ax	= 0x1500;
	r.x.bx	= FP_OFF((void far *)buf);
	r.x.cx	= ndxDisk;
	r.x.dx	= 1;
	r.x.si	= sector >> 16;
	r.x.di	= sector & 0xFFFF;

	s.es	= FP_SEG((void far *)buf);

	int86x(0x2F, &r, &r, &s);

	return r.h.al == 0;
}

BOOL CLowCdrom::absoluteReadSector(DWORD sector) {
	if (bufferLocked) return FALSE;

	bufferLocked = TRUE;
	for (int i = 0; i < nBufferSize; i++) {
		if (!absoluteReadOneSector(sector + i, lpBuffer + CDROM_SECTOR_SIZE * i)) {
			bufferLocked = FALSE;
			return FALSE;
		}
	}
	bufferLocked = FALSE;

	return TRUE;
}

BOOL CLowCdrom::absoluteRead(long address) {
	WORD	wSector		= address / CDROM_SECTOR_SIZE;
	WORD	wOffsetInSector	= address % CDROM_SECTOR_SIZE;

	if (bufferLocked) return FALSE;
	if (address < 0) return FALSE;

	if (absoluteReadSector(wSector)) {
		if (wOffsetInSector != 0) {
			int r;
			bufferLocked = TRUE;
			r = absoluteReadOneSector(wSector + 1, lpBuffer + CDROM_SECTOR_SIZE * (wSector + 1));
			memmove(lpBuffer + wOffsetInSector, lpBuffer, CDROM_SECTOR_SIZE * nBufferSize);
			bufferLocked = FALSE;
			return r;
		}
		return TRUE;
	}

	return FALSE;

}

LPBYTE	CLowCdrom::LockBuffer() {
	if (bufferLocked) return NULL;

	bufferLocked = TRUE;
	return lpBuffer;
}

void	CLowCdrom::UnlockBuffer() {
	bufferLocked = FALSE;
}

#endif
