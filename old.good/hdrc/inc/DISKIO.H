
struct DiskAddressPacket {
	BYTE	cbSize;
	BYTE	byReserved;
	WORD	nBlocks;
	PFAR	pTransferBuffer;
	INT64	nStartBlock;
};

#define DPF_DMA_ERROR		1
#define DPF_CHS_VALID		2
#define DPF_REMOVABLE		4
#define DPF_WRITE_VERIFY_SUPP	8
#define DPF_CHANGE_LINE_SUPP	16
#define DPF_CAN_BE_LOCKED	32
#define DPF_CHS_OVERFLOW	64
struct DriveParameters {
	WORD	cbSize;
	WORD	wFlags;		// DPF_
	DWORD	nCylinders;
	DWORD	nHeads;		//
	DWORD	nSectors; 	// per track
	INT64	nTotalSectors;
	WORD	nSectorSize;
	// IBM 2.0+
	PFAR	pEDDConfig;
	// IBM 3.0+
	WORD	wSign; 		// == BEDD if Device Path info existed.
	BYTE	cbDevicePathInfo;	// include this byte.
	BYTE	_res[3];
	BYTE	fccBus[4]; 	// "ISA" or "PCI"
	BYTE	xInterface[8];
	BYTE	xInterfacePath[8];
	BYTE	xDevicePath[8];
	BYTE	_res2;
	BYTE	Checksum;	// 256 - sum(1E~41h)
};

union InterfacePath {
	struct {
		WORD wBaseAddress;
		BYTE _res[6];
	} iso;
	struct {
		BYTE nBus;
		BYTE nDevice;
		BYTE nFunction;
		BYTE _res[5];
	} pci;
};

union DevicePath {
	struct {
		BYTE bSlave;
		BYTE _res[7];
	} ata;
	struct {
		BYTE bSlave;
		BYTE nLogicalUnit;
		BYTE _res[6];
	} atapi;
	struct {
		BYTE nLogicalUnit;
		BYTE _res[7];
	} scsi;
	struct {
		BYTE nToBeDetermined;
		BYTE _res[7];
	} usb;
	INT64	ieee1394_FireWire_GUID;
	INT64	fibre_WWN;
}; // Device Path


#define EDDF_SLAVE		0x10
#define EDDF_LBA_ENABLED	0x40

#define EDD_OPT_FAST_PIO	1
#define EDD_OPT_FAST_DMA	2
#define EDD_OPT_BLOCK_PIO	4
#define EDD_OPT_CHS		8
#define EDD_OPT_LBA		16
#define EDD_OPT_REMOVABLE	32
#define EDD_OPT_ATAPI		64	// CD-ROM
#define EDD_OPT_32_BIT		128
// EDD 1.1+
#define EDD_OPT_ATAPI_DRQ	0x100	// EDD_OPT_ATAPI must be set
#define EDD_OPT_TRANS_MASK	0x600	// 0 phoenix; 1 LBA; 3 proprietary
// EDD 3.0+
#define EDD_OPT_UDMA		0x800
struct EDD_Spec {
	WORD wIOBase;
	WORD wControlPort;
	BYTE Flags;
	BYTE Proprietary;
	BYTE IRQ;
	BYTE nMultiSectors;
	BYTE DMA;	// 7-4 type, [76] [54] each; 3-0 channel
	BYTE PIO;	// 3-0
	WORD wOptions;
	BYTE _res[2];
	BYTE nRevLevel;	// 7-4 major.3-0 minor
	BYTE Checksum; 	// 256 - sum(0-0Fh)
};

#define DIF_HARD_SECTORED	0x0002
#define DIF_SOFT_SECTORED	0x0004
#define DIF_NOT_MFM_ENCODED	0x0008
#define DIF_SLOW_HEAD_SWITCH	0x0010		// > 15 usec
#define DIF_IMP_SPINDLE_MOTOR	0x0020
#define DIF_FIXED		0x0040
#define DIF_REMOVABLE_CART	0x0080		// removable cartridge drive
#define DIF_LOW_DTR		0x0100		// Disk transfer rate <= 5Mbs
#define DIF_MIDDLE_DTR		0x0200		// DTR > 5Mbs, <= 10Mbs
#define DIF_HIGH_DTR		0x0400		// DTR > 10Mbs
#define DIF_HIGH_ROT_SPEED_TOL	0x0800		// rotational speed tolerance > 0.5%
#define DIF_DATA_STROBE_OFF	0x1000
#define DIF_TRACK_OFF		0x2000
#define DIF_FORMAT_TOL_GAP	0x4000		// format speed tolerance gap required
#define DIF_NON_MAGNETIC_DRIVE	0x8000
#define DIC_DMA_SUPPORTED	0x100
struct DriveInformation {
	WORD wFlags;			// DIF_...
	WORD nCylinders;
	WORD _res1;
	WORD nHeads;
	WORD nTrackSize;
	WORD nSectorSize;
	WORD nSectorsPerTrack;
	BYTE _vendor1[6];
	char szSerialNumber[20];
	WORD wBufferType;
	WORD nBufferSize512;
	WORD cbECC_RWLongCmds;
	char szFirmwareRev[8];
	char szModel[40];
	BYTE nMaxSectorsPerInt;
	BYTE _vendor2;
	WORD bDoublewordIO;
	WORD wCapabilities;		// DIC_...
	WORD _res2;
	BYTE _vendor3;
	BYTE timeCyclePIO;
	BYTE _vendor4;
	BYTE timeCycleDMA;
	WORD bTranslationModeValid;
	WORD nCurCylinders;
	WORD nCurSectorsPerTrack;
	DWORD nCurCapacityInSectors;
	WORD _res3;
	BYTE _res4[136];
	BYTE _vendor5[64];
	BYTE _res5[96];
};
