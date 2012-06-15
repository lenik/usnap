
// Portable Executable-file Analysor
//	peAna (c) '00 dansei, z.j.

#include <stdio.h>
#include <conio.h>

#define u1	unsigned char
#define u2	unsigned
#define u4	unsigned long

struct peHeader {
	u4	signStamp;
	u2	cpuType;
	u2	nObjects;
	u4	timeStamp;
	u4	_r01;
	u4	_r02;
	u2	sizeNT_Hdr;
	u2	flags;
	u2	_r03;
	u2	lMajor, lMinor;
	u2	_r04;
	u4	_r05, _r06;
	u4	rvaEntryPoint;
	u4	_r07;
	u4	_r08;
	u4	baseImage;
	u4	alignObject;
	u4	alignFile;
	u2	osMajor;
	u2	osMinor;
	u2	userMajor;
	u2	userMinor;
	u2	subMajor;
	u2	subMinor;
	u4	_r08a;
	u4	sizeImage;
	u4	sizeHeader;
	u4	chksumFile;
	u2	subSystem;
	u2	flagsDll;
	u4	sizeStackRes, sizeStackCommit;
	u4	sizeHeapRes, sizeHeapCommit;
	u4	_r09;
	u4	nInteresting;
	u4	rvaExportTable;
	u4	sizeExportData;
	u4	rvaImportTable;
	u4	sizeImportData;
	u4	rvaResourceTable;
	u4	sizeResourceData;
	u4	rvaExceptionTable;
	u4	sizeExceptionData;
	u4	rvaSecurityTable;
	u4	sizeSecurityData;
	u4	rvaFixupTable;
	u4	sizeFixupData;
	u4	rvaDebugTable;
	u4	sizeDebugData;
	u4	rvaImageDescription;
	u4	sizeImageDescription;
	u4	rvaMachineSpecific;
	u4	sizeMachineSpecific;
	u4	rvaThreadLocalStorage;
	u4	sizeThreadLocalStorage;
};

class oPEana {
public:
	peHeader *pehdr;

public:
	void printHeader();

public:
	oPEana();
	~oPEana();
};

oPEana::oPEana() {
	pehdr = new peHeader;
}

oPEana::~oPEana() {
	if (pehdr) delete pehdr;
}

void oPEana::printHeader() {
	printf("\n\
u4	signStamp	 	= %08lx\n\
u2	cpuType	 		= %04x\n\
u2	nObjects	 	= %04x\n\
u4	timeStamp	 	= %08lx\n\
u2	sizeNT_Hdr	 	= %04x\n\
u2	flags	 		= %04x\n\
u2	lMajor, lMinor	 	= %04x, %04x\n\
u4	rvaEntryPoint	 	= %08lx\n\
u4	baseImage	 	= %08lx\n\
u4	alignObject	 	= %08lx\n\
u4	alignFile	 	= %08lx\n\
u2	osMajor, osMinor     	= %04x, %04x\n\
u2	userMajor, userMinor	= %04x, %04x\n\
u2	subMajor, subMinor	= %04x, %04x\n\
u4	sizeImage	 	= %08lx\n\
u4	sizeHeader	 	= %08lx\n\
u4	chksumFile	 	= %08lx\n\
u2	subSystem	 	= %04x\n\
u2	flagsDll	 	= %04x\n\
u4	sizeStackRes		= %08lx\n\
u4	sizeStackCommit	 	= %08lx\n\
u4	sizeHeapRes		= %08lx\n\
u4	sizeHeapCommit	 	= %08lx\n\
press any key to continue...",
		pehdr->signStamp,
		pehdr->cpuType,
		pehdr->nObjects,
		pehdr->timeStamp,
		pehdr->sizeNT_Hdr,
		pehdr->flags,
		pehdr->lMajor, pehdr->lMinor,
		pehdr->rvaEntryPoint,
		pehdr->baseImage,
		pehdr->alignObject,
		pehdr->alignFile,
		pehdr->osMajor, pehdr->osMinor,
		pehdr->userMajor, pehdr->userMinor,
		pehdr->subMajor, pehdr->subMinor,

		pehdr->sizeImage,
		pehdr->sizeHeader,
		pehdr->chksumFile,
		pehdr->flagsDll,
		pehdr->sizeStackRes,
		pehdr->sizeStackCommit,
		pehdr->sizeHeapRes,
		pehdr->sizeHeapCommit);

	getch();
	printf("\
u4	nInteresting	 	= %08lx\n\
u4	rvaExportTable	 	= %08lx\n\
u4	sizeExportData	 	= %08lx\n\
u4	rvaImportTable	 	= %08lx\n\
u4	sizeImportData	 	= %08lx\n\
u4	rvaResourceTable	= %08lx\n\
u4	sizeResourceData	= %08lx\n\
u4	rvaExceptionTable	= %08lx\n\
u4	sizeExceptionData	= %08lx\n\
u4	rvaSecurityTable	= %08lx\n\
u4	sizeSecurityData	= %08lx\n\
u4	rvaFixupTable	 	= %08lx\n\
u4	sizeFixupData	 	= %08lx\n\
u4	rvaDebugTable		= %08lx\n\
u4	sizeDebugData		= %08lx\n\
u4	rvaImageDescription	= %08lx\n\
u4	sizeImageDescription	= %08lx\n\
u4	rvaMachineSpecific	= %08lx\n\
u4	sizeMachineSpecific	= %08lx\n\
u4	rvaThreadLocalStorage	= %08lx\n\
u4	sizeThreadLocalStorage	= %08lx\n\
press any key to continue...",
		pehdr->nInteresting,
		pehdr->rvaExportTable,
		pehdr->sizeExportData,
		pehdr->rvaImportTable,
		pehdr->sizeImportData,
		pehdr->rvaResourceTable,
		pehdr->sizeResourceData,
		pehdr->rvaExceptionTable,
		pehdr->sizeExceptionData,
		pehdr->rvaSecurityTable,
		pehdr->sizeSecurityData,
		pehdr->rvaFixupTable,
		pehdr->sizeFixupData,
		pehdr->rvaDebugTable,
		pehdr->sizeDebugData,
		pehdr->rvaImageDescription,
		pehdr->sizeImageDescription,
		pehdr->rvaMachineSpecific,
		pehdr->sizeMachineSpecific,
		pehdr->rvaThreadLocalStorage,
		pehdr->sizeThreadLocalStorage);
	// print anything else...
	getch();
	return;
}

void main(int argc, char **argv) {

	FILE *f = fopen(argv[1], "rb");
	oPEana pe;
	u4 peOff;
	u4 r;

	if (!f) {
		perror("open file");
		return;
	}

	r = fseek(f, 0x3C, SEEK_SET);
	r = fread(&peOff, 4, 1, f);
	r = fseek(f, peOff, SEEK_SET);
	r = fread(pe.pehdr, sizeof(peHeader), 1, f);
	r = fclose(f);
	pe.printHeader();

}
