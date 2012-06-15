
#include <dos.h>
#include <stdio.h>

#define BYTE	unsigned char
#define WORD	unsigned int
#define DWORD	unsigned long

unsigned int checkCDROM() {
	BYTE bInstalled;

	asm {
		Push AX
		Mov AX, 0x1100		// MSCDEX Install check
		Push 0xDADA		// Subfn
		Int 0x2F
		Mov bInstalled, AL	// Return AL=0xFF if installed driver
		Pop AX			// Pop 0xADAD if installed MSCDEX
		Pop AX
	}

	return bInstalled;
}

unsigned int ReadSector(unsigned long *secno, unsigned char *buf) {
	union REGS r;
	struct SREGS s;

	r.x.ax = 0x1508; 		/* Absolute Read */
	r.x.si = FP_SEG(secno);        /* SI:DI -> starting sector no. */
	r.x.di = FP_OFF(secno);
	s.es = FP_SEG(buf);		/* ES:BX -> buffer */
	r.x.bx = FP_OFF(buf);
	r.x.cx = 0x4; 			/* Drive E */
	r.x.dx = 0x1; 			/* Num of secs */

	int86x(0x2F, &r, &r, &s);

	if (r.x.cflag) {
		switch (r.x.ax) {
		case 0xF:
			printf("Invalid drive!\n");
			break;
		case 0x15:
			printf("Drive not ready!\n");
			break;
		default:
			printf("Unknown error!\n");
		}
		return r.x.ax;
	} else
		printf("Success Read!\n");
	return 0;
}

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
	SREGS s;
	REGS r;

	r.x.ax = 0x150F;
	r.h.cl = 0x4; 			// drive E
	r.h.ch = canonicalized ? 1 : 0;

	s.es = FP_SEG(path);
	r.x.bx = FP_OFF(path);
	r.x.si = FP_SEG(buf);
	r.x.di = FP_OFF(buf);
	int86x(0x2F, &r, &r, &s);

	// success: 0 = highsierra, -1 = iso9660, else error code
	return r.x.cflag ? r.x.ax : -r.x.ax;
}

enum commandCode {
	c_INIT = 0,
	c_MEDIA_CHECK = 1,			// block
	c_BUILD_BPD = 2,			// block
	c_IOCTL_INPUT = 3,
	c_INPUT = 4,
	c_NONDESTRUCTIVE_INPUT = 5,         	// char
	c_INPUT_STATUS = 6, 			// char
	c_INPUT_FLUSH = 7,			// char
	c_OUTPUT = 8,
	c_OUTPUT_WITH_VERIFY = 9,
	c_OUTPUT_STATUS = 0x0A,			// char
	c_OUTPUT_FLUSH = 0x0B, 			// char
	c_IOCTL_OUTPUT = 0x0C,
	c_DEVICE_OPEN = 0x0D, 			// 		DOS 3+
	c_DEVICE_CLOSE = 0x0E, 			// 		DOS 3+
	c_REMOVABLE_MEDIA = 0x0F, 		// block	DOS 3+
	c_OUTPUT_UNTIL_BUSY = 0x10, 		// char		DOS 3+
	c_STOP_OUTPUT = 0x11, 			// console	European DOS 4
	c_RESTART_OUTPUT = 0x12, 		// console	European DOS 4
	c_GENERIC_IOCTL = 0x13, 		// 		DOS 3.2+
	c_RESET_UNCERTAIN_MEDIA_FLAG = 0x15, 	// 	European DOS 4
	c_GET_LOGICAL_DEVICE = 0x17,		// 		DOS 3.2+
	c_SET_LOGICAL_DEVICE = 0x18,		//		DOS 3.2+
	c_CHECK_GENERIC_IOCTL_SUPPORT = 0x19, 	//		DOS 5+
	c_READ_LONG = 0x80, 			// CD-ROM
	c_READ_LONG_PREFETCH = 0x82, 		// CD-ROM
	c_SEEK = 0x83, 				// CD-ROM
	c_PLAY_AUDIO = 0x84, 			// CD-ROM
	c_STOP_AUDIO = 0x85, 			// CD-ROM
	c_WRITE_LONG = 0x86, 			// CD-ROM
	c_WRITE_LONG_VERIFY = 0x87, 		// CD-ROM
	c_RESUME_AUDIO = 0x88			// CD-ROM
};

enum errorCode {
	e_WRITE_PROTECT_VIOLATION = 0,
	e_UNKNOWN_UNIT,
	e_DRIVE_NOT_READY,
	e_UNKNOWN_COMMAND,
	e_CRC_ERROR,
	e_BAD_DRIVE_REQUEST_STRUCTURE_LENGTH,
	e_SEEK_ERROR,
	e_UNKNOWN_MEDIA,
	e_SECTOR_NOT_FOUND,
	e_PRINTER_OUT_OF_PAPER,
	e_WRITE_FAULT,
	e_READ_FAULT,
	e_GENERAL_FAILURE,
	e_RESERVED,
	e_MEDIA_UNAVAILABLE,
	e_INVALID_DISK_CHANGE
};

struct deviceRequestHeader {
	BYTE length;
	BYTE subunitWithinDeviceDriver;
	BYTE commandCode;	// see commandCode enumlates
	WORD status; 		// be written

	BYTE reserved[4];
	DWORD pNextRequestHeader; 	// European DOS 4, otherwise reserved.
	// offset 0Dh ->
};

struct deviceRequestHeader_Init : public deviceRequestHeader {
	BYTE numberOfUnits;		// ret
	DWORD p1;
		// call: pointer past end of memory available to driver (DOS 5+)
		// ret:  address of first free byte following driver
	DWORD p2;
		// call: pointer to commandline arguments
		// ret:  pointer to BPB array (block drivers) or 0:0 (character drivers)
	BYTE driveNumber; 		// for first unit of block driver
	WORD errorflag; 		// error-message flag (DOS 5+), 0001h: display error msg on init failure
};

struct deviceRequestHeader_MediaCheck : public deviceRequestHeader {
	BYTE mediaDescriptor;
	BYTE mediaStatus;               // (ret) 00h don't know; 01h media hasn't changed; FFh media has been changed
	DWORD pPreviosVolumeID; 	// (ret) if the OPEN/CLOSE/RM bit in device header is set and disk changed
};

struct deviceRequestHeader_BuildBPD : public deviceRequestHeader {
	BYTE mediaDescriptor;
	DWORD transferAddress;
		// -> scratch sector if NON-IBM FORMAT bit in device header set
		// -> first FAT sector otherwise
	DWORD pBPD; 			// set by driver, see INT 21/AH=53h
};

struct deviceRequestHeader_IOCTL : public deviceRequestHeader {
	BYTE mediaDescriptor; 		// block
	DWORD transferAddress;
	WORD number;
		// call: number of bytes to read/write
		// ret:  Actual number of bytes read or written
};	// (see also INT 21/AX=4402h,INT 21/AX=4403h)

struct deviceRequestHeader_InputOutput : public deviceRequestHeader {
	BYTE mediaDescriptor; 		// block
	DWORD transferAddress;
	WORD count; 			// byte if char, sector if block
	WORD startSectorNumber;		// block
	DWORD pVolumeID; 		// if error 0Fh returned (DOS 3+)
	DWORD startSectorNumber32;	// if starting sector number above is FFFFh, see INT 21/AH=52h, DOS 4+)
}; // command codes 04h,08h,09h (except Compaq DOS 3.31, DR DOS 6)

struct deviceRequestHeader_InputOutput_Compaq : public deviceRequestHeader {
	BYTE mediaDescriptor; 		// block
	DWORD transferAddress;
	WORD count; 			// byte if char, sector if block
	DWORD startSectorNumber32;	// block
}; // command codes 04h,08h,09h (Compaq DOS 3.31, DR DOS 6)

struct deviceRequestHeader_NonDestructiveInput : public deviceRequestHeader {
	BYTE byteReadFromDevice; 	// if BUSY bit clear on return
};

struct deviceRequestHeader_Other : public deviceRequestHeader {
}; // command codes 06h,07h,0Ah,0Bh,0Dh,0Eh,0Fh,15h

struct deviceRequestHeader_OutputUntilBusy : public deviceRequestHeader {
	BYTE unused;
	DWORD transferAddress;
	WORD number;
		// call: number of bytes to write
		// ret:  actual number of bytes written
};

struct deviceRequestHeader_Stop_Or_Restart_Output : public deviceRequestHeader {
	BYTE reserved;
};

struct deviceRequestHeader_Generic_IOCTL : public deviceRequestHeader {
	BYTE categoryCode;
		// 00	unknown
		// 01	COMn:
		// 03	CON
		// 05	LPTn:
		// 07	mouse (Euroean DOS 4)
		// 08	disk
	BYTE functionCode;		// 00	MAC Bind request
	WORD copyof_DS_atcall; 		// unused in DOS 3.3
	WORD offsetDeviceDriverHeader;
	DWORD pParameterBlock; 		// from INT 21/AX=440Ch/440Dh
}; // command codes 13h,19h

struct deviceRequestHeader_cdrom_readlong {
	BYTE length;
	BYTE subunitWithinDeviceDriver;
	BYTE commandCode;	// see commandCode enumlates
	WORD status; 		// be written

	BYTE reserved[4];
	DWORD pNextRequestHeader; 	// European DOS 4, otherwise reserved.
	// offset 0Dh ->

	BYTE addressMode; 		// 00h HSG, 01h Phillips/Sony Red Book
	DWORD transferAddress; 		// ignored for command 82h
	WORD numberOfSectors;
		// if 0 for command 82h, request is an advisory seek
	DWORD startSectorNumber;
		// logical sector number in HSG mode
		// frame/second/minute/unused in Red Book mode
		// (HSG sector = minute * 4500 + second * 75 + frame - 150)
	BYTE dataReadMode;      	// 00 cooked(2k/frame) 01 raw (2353/frame, including EDC/ECC)
	BYTE interleaveSize; 		// number of sectors stored consecutively
	BYTE interleaveSkipFactor;	// number of sectors between consecutive portions
}; // command codes 80h,82h
/*
struct deviceRequestHeader_cdrom_readlong : public deviceRequestHeader {
	BYTE addressMode; 		// 00h HSG, 01h Phillips/Sony Red Book
	DWORD transferAddress; 		// ignored for command 82h
	WORD numberOfSectors;
		// if 0 for command 82h, request is an advisory seek
	DWORD startSectorNumber;
		// logical sector number in HSG mode
		// frame/second/minute/unused in Red Book mode
		// (HSG sector = minute * 4500 + second * 75 + frame - 150)
	BYTE dataReadMode;      	// 00 cooked(2k/frame) 01 raw (2353/frame, including EDC/ECC)
	BYTE interleaveSize; 		// number of sectors stored consecutively
	BYTE interleaveSkipFactor;	// number of sectors between consecutive portions
}; // command codes 80h,82h
*/
struct deviceRequestHeader_cdrom_seek : public deviceRequestHeader {
	BYTE addressMode;		// see above
	DWORD transferAddress; 		// ignored
	WORD numberOfSectors; 		// ignored
	DWORD startSectorNumber;	// see above
};

struct deviceRequestHeader_cdrom_playaudio : public deviceRequestHeader {
	BYTE addressMode; 		// see above
	DWORD startSectorNumber;	// see above
	DWORD numberOfSectorsToPlay;
};

struct deviceRequestHeader_cdrom_stopaudio : public deviceRequestHeader {
};

struct deviceRequestHeader_cdrom_writelong : public deviceRequestHeader {
	BYTE addressMode; 		// see above
	DWORD transferAddress; 		// ignored in write mode 0
	WORD numberSectors;
	DWORD startSectorNumber;	// see above
	BYTE writeMode;
		// 00h: mode 0: write all zeros
		// 01h: mode 1: 2k/sector	(default)
		// 02h: mode 2 form 1: 2k/sector
		// 03h: mode 2 form 2: 2336/sector
	BYTE interleaveSize; 		// number of sectors stored consecutively
	BYTE interleaveSkipFactor; 	// number of sectors between consecutive portions
};

struct deviceRequestHeader_cdrom_resumeaudio : public deviceRequestHeader {
};

BYTE DeviceDriverInstallCheck() {
	REGS r;

	r.x.ax = 0x0800;
	int86(0x2F, &r, &r);

	return r.h.al;
	    //00h not installed, OK to install
	    //01h not installed, not OK to install
	    //FFh installed
}

void ExecuteDeviceDriverRequest(deviceRequestHeader far *header) {
	SREGS s;
	REGS r;
	WORD w;

	r.x.ax = 0x0802;
	s.es = FP_SEG(header);
	r.x.bx = FP_OFF(header);
	int86x(0x2F, &r, &r, &s);

	asm Pop w;
}

void cdromrequest(deviceRequestHeader_cdrom_readlong &r) {
	WORD rseg = FP_SEG(&r);
	WORD roff = FP_OFF(&r);
	asm {
		PushA
		Push ES
		Mov AX, rseg
		Mov ES, AX
		Mov BX, roff
		Mov AX, 0x0802
		Int 0x2F
//		Pop AX
		PopA
	}
}

BYTE far buf[16384];

void main() {

	// Initialize...
	if (checkCDROM() != 0xFF) {
		printf("CD-ROM Driver hasn't installed!\n");
		return;
	}

	if (DeviceDriverInstallCheck() != 0xFF) {
		printf("it doesn't support Device Driver!\n");
		return;
	}

	// Read Long of CD-ROM testing...
	deviceRequestHeader_cdrom_readlong cdrom_readlong;
	cdrom_readlong.length = sizeof(deviceRequestHeader_cdrom_readlong);
	cdrom_readlong.subunitWithinDeviceDriver = 1;
	cdrom_readlong.commandCode = c_READ_LONG;
	*(DWORD *)cdrom_readlong.reserved = (DWORD)0;
	cdrom_readlong.pNextRequestHeader = 0;
	cdrom_readlong.addressMode = 0; 		// HSG
	cdrom_readlong.transferAddress = (DWORD)((BYTE far *)buf);
	cdrom_readlong.numberOfSectors = 1;
	cdrom_readlong.startSectorNumber = 0x48;
	cdrom_readlong.dataReadMode = 0;
	cdrom_readlong.interleaveSize = 0;
	cdrom_readlong.interleaveSkipFactor = 0;

	//	ExecuteDeviceDriverRequest((deviceRequestHeader *)&cdrom_readlong);
	cdromrequest(cdrom_readlong);
	return;
}
