
#pragma once

#ifndef IN
#	define IN
#endif
#ifndef OUT
#	define OUT
#endif

#pragma pack(push, 4)

struct DISK_ADDR {
	enum {
		mode_chs,
		mode_lba,
		mode_linear,
	} mode;
	struct {
		u64_t cylinder;
		int head;
		int sector;
	};
	u64_t lba;
	u64_t linear;
};

enum PART_SYSTEM {
	ps_unused		= 0,
	ps_fat_12		= 1,
	ps_xenix_root		= 2,
	ps_xenix_usr		= 3,
	ps_fat_16		= 4,	// 32M max
	ps_extended		= 5,	// DOS 3.3+
	ps_fat_16_large		= 6,	// DOS 3.31+
	ps_ntfs			= 7,	// (*) also OS/2 HPFS, QNX, windows IFS, advanced Unix.
	ps_os2_hpfs		= 0x70000,
	ps_ifs,
	ps_qnx,
	ps_advanced_unix,
	ps_os2			= 8,	// (*) also aix, commodore DOS, dell
	ps_aix_bootable		= 0x80000,
	ps_coherent		= 9,
	ps_os2boot_mgr		= 10,	// (*) also OPUS, Coherent swap
	ps_fat_32		= 11,
	ps_fat_32_lba		= 12,
	ps_lba_vfat_large	= 14,	// xint 13
	ps_lba_vfat		= 15,	// xint 13 extended
	ps_opus			= 0x10,
	ps_os2_bootmgr_hid_12	= 0x11,
	ps_os2_compaq_diag	= 0x12,
	ps_os2_bootmgr_sub32	= 0x14,
	ps_os2_bootmgr_over32	= 0x16,
	ps_hid_ntfs		= 0x17,
	ps_ast_swap		= 0x18,
	ps_willowtech_photon	= 0x19,
	ps_hid_fat_32		= 0x1b,
	ps_hid_fat_32_lba	= 0x1c,
	ps_hid_lba_vfat		= 0x1e,
	ps_ofs1			= 0x20,
	ps_fso2			= 0x21,
	ps_nec_msdos		= 0x24,	// NEC MS-DOS 3.x
	ps_theos		= 0x38,
	ps_pm_recovery		= 0x3c,	// PowerQuest PartitionMagic recovery partition
	ps_venix_286		= 0x40,
	ps_personal_risc_boot	= 0x41,	// (*) PowerPC boot partition
	ps_sfs			= 0x42,	// (Secure File System), (*)LDM
	ps_oberon		= 0x4f,
	ps_cp_m			= 0x52,	// (*) ms v386
	ps_ez_drive		= 0x55,
	ps_goldenbow		= 0x56,
	ps_priam		= 0x5c,
	ps_speedstor		= 0x61,
	ps_unix_sysv_ix		= 0x63,	// SysV/386, 386/ix; (*) Mach MtXinu BSD 4.3; GNU HURD
	ps_netware_286		= 0x64,	// (*) SpeedStore
	ps_netware_311		= 0x65,
	ps_disksecure_multiboot	= 0x70,
	ps_pcix			= 0x75,
	ps_f_i_x		= 0x7e,
	ps_minix_1		= 0x80,
	ps_linux		= 0x81,	// (*) Minix v1.4b+, Mitax Advanced Disk Manager
	ps_linux_swap		= 0x82,	// (*) Prime, Solaris
	ps_ext2			= 0x83,	// Linux native file system
	ps_os2_renumbered	= 0x84,
	ps_linux_ext		= 0x85,
	ps_fat16_nt		= 0x86,	// FAT16 volume/stripe set (Windows NT)
	ps_hpfs_fault_tol	= 0x87,	// (*) NTFS volume/stripe set
	ps_amoeba_fs		= 0x93,
	ps_amoeba_bbt		= 0x94,	// Amoeba bad block table
	ps_mylex_eisa_scsi	= 0x99,
	ps_save_to_disk		= 0xa0,	// Phoenix NoteBIOS Power Management "Save-to-Disk" partition
	ps_freebsd		= 0xa5,	// (*) BSD/386
	ps_openbsd		= 0xa6,
	ps_netbsd		= 0xa9,
	ps_bsdi			= 0xb7,	// (*) secondarily swap
	ps_bsdi_swap		= 0xb8,	// (*) secondarily file system
	ps_solaris_boot		= 0xbe,
	ps_novell_dos		= 0xc0,	// (*) CTOS
	ps_drdos_fat_12		= 0xc1,
	ps_drdos_fat_16		= 0xc4,
	ps_drdos_fat_16_large	= 0xc6,	// (*) corrupted fat-16 (NT)
	ps_syrinx_boot		= 0xc7,
	ps_mdos_fat_12		= 0xd0,	// Multiuser DOS
	ps_cp_m_86		= 0xd8,
	ps_cp_m_concurrent	= 0xdb,	// (*) CTOS (Convergent Technologies OS)
	ps_speedstor_fat_12_ext	= 0xe1,
	ps_dos_readonly		= 0xe2,
	ps_storage_dimensions	= 0xe3,	// (*) DOS read-only
	ps_beos_bfs		= 0xeb,	// BeOS BFS (BFS1)
	ps_storage_dimensions2	= 0xf1,
	ps_dos3_second		= 0xf2,
	ps_prologue		= 0xf5,
	ps_lanstep		= 0xfe,	// (*) IBM PS/2 IML
	ps_xenix_bbt		= 0xff,
};

struct PART_INFO {
	int		iPart;
	PART_SYSTEM	system_type;
	BOOL		bootable;
	DISK_ADDR	begin;
	DISK_ADDR	end;
	u64_t		sectors;
	void *		system;
	int		n_sub_parts;
	PART_INFO *	sub_parts;
	void *		boot_record;
	char *		label;
	u32_t		n_hidden_sectors;
};

struct DISK_INFO {
	IN int		iDisk;		// 0 for disk1, 1 for disk2, ...
	DWORD		media_type;
	u64_t		cylinders;
	int		heads;		// (track) per cylinder
	int		sectors;	// per track/head
	int		sector_size;
	u64_t		size;
	int		n_parts;
	PART_INFO *	parts;
	void *		boot_record;
};

struct GET_SECTOR_PARAM {
	DISK_ADDR	begin;
	DISK_ADDR	end;
	LPVOID		buffer;
	DWORD		crc32;

	enum ERR_CODE {
		err_ok = 0,
		err_cant_open,
		err_cant_read,
		err_cant_write,
		err_crc,
		err_bad_sector,
		err_index_error,
		err_sharing,
	};
	ERR_CODE	err;
	DWORD		syserr;
	double		duration;
};

#pragma pack(pop)

void _stdcall DestroyPartInfo(PART_INFO *pPI);
void _stdcall DestroyDiskInfo(DISK_INFO *pDI);
void _stdcall DestroyGetSectorParam(GET_SECTOR_PARAM *pGSP);
DWORD _stdcall OpenDisk(int disk);
BOOL _stdcall CloseDisk(DWORD hDisk);
BOOL _stdcall GetDiskInfo(DISK_INFO *pDI);
void _stdcall CalcAddr(DISK_INFO *pDI, DISK_ADDR *pDA, BOOL bAlign = FALSE);
BOOL _stdcall GetSector(DISK_INFO *pDI, GET_SECTOR_PARAM *pSectorParam);
BOOL _stdcall PutSector(DISK_INFO *pDI, GET_SECTOR_PARAM *pSectorParam);
