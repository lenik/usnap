
#include "stdafx.h"
#include <winioctl.h>
#include <pos/pos.h>
using namespace pos;
#include "dump_sector.h"
__std;

#include "dump_sector_util.h"

static BOOL GetCHS(char *szCHS, u64_t *pCy, int *pHeads, int *pSectors) {
	char *tok;
	int iCHS = 0;
	tok = strtok(szCHS, ":");
	while (tok != NULL) {
		switch (iCHS) {
		case 0:
			*pCy = strtol64(szCHS, &szCHS, 0);
			break;
		case 1:
			*pHeads = strtol(szCHS, &szCHS, 0);
			break;
		case 2:
			*pSectors = strtol(szCHS, &szCHS, 0);
			break;
		}
		iCHS++;
		/*
			while (isspace(*szCHS)) szCHS++;
			if (*szCHS == ':') szCHS++;
			while (isspace(*szCHS)) szCHS++;
		*/
		tok = strtok(NULL, ":");
	}
	return iCHS == 3;
}


int main(int argc, char* argv[])
{
	/*
	for (;;) {
		char buf[10000], *se;
		scanf("%s", buf);
		u64_t n = strtol64(buf, &se, 0);
		output_u64(n, 10);
		printf(" (");
		output_u64(n, 16);
		printf("h)  --> \"%s\" \n", se);
	}
	*/

	BOOL			b;
	DISK_INFO		di;
	GET_SECTOR_PARAM	gsp;
	BOOL			bWriteMode = false;
	BOOL			b_dump_info = false;
	BOOL			b_LBA = true;
	BOOL			bRandom = false;
	char			szFile[_MAX_PATH];

	u64_t			len_Cylinders = 0;
	int			len_Heads = 0;
	int			len_Sectors = 1;
	int			len_LBA_Blocks = 1;

	__zero(di);
	di.iDisk = 0;		// default drive 0

	__zero(gsp);
	gsp.begin.mode = DISK_ADDR::mode_lba;
	gsp.begin.lba = 1;	// default to read MBR (the first sector).
	strcpy(szFile, "con");

	while (argc > 1) {
		argc--;
		argv++;
		if (argv[0][0] == '-') {
			if (!strcmp(argv[0], "-lba")) b_LBA = true;
			else if (!strcmp(argv[0], "-chs")) b_LBA = false;
			else {
				switch (argv[0][1]) {
				case 'a':
					b_dump_info = true;
					break;
				case 'd':
					if (argc < 2) {
						cerr << "-d: you haven't specified the disk. " << endl;
					} else {
						di.iDisk = strtol(argv[1], NULL, 0);
						argc--;
						argv++;
					}
					break;
				case 'l':
					if (b_LBA) {
						len_LBA_Blocks = strtol(argv[1], NULL, 0);
					} else {
						// C:H:S
						if (!GetCHS(argv[1], &len_Cylinders, &len_Heads, &len_Sectors)) {
							cerr << "you must enter as cylinders:heads:sectors format!" << endl;
							return -1;
						}
						argc--;
						argv++;
					}
					break;
				case 'f':
					if (argc < 2) {
						cerr << "-f: you haven't specified the path. " << endl;
					} else {
						strcpy(szFile, argv[1]);
						argc--;
						argv++;
					}
					break;
				case 'w':
					bWriteMode = true;
					break;
				case 'r':
					bRandom = true;
					break;
				case '?':
				case 'h':
					cout	<<
					"dump sector [options] address\n"
					"---------------------------------------------------------------------------\n"
					"-a		dump the disk drive and partition information\n"
					"-chs		using CHS address mode\n"
					"-lba		using LBA address mode (default)\n"
					"-l c:h:s (or) -l n\n"
					"		the end sector (CHS) or LBA block to dump\n"
					"-d <disk>	disk may be 0,1,... for physical drive 0, 1, ...\n"
					"-f <file name>	output to the file. (defulat is stdout)\n"
					"-w		write file to sector (WARNING: take care of this function!)\n"
					"-r		random data\n"
					;
				default:
					cerr << "unknown option: " << argv[0] << endl;
					break;
				}
			} // if "-lba"
		} else {
			// all that doesn't start with '-' is treated as "starting address"
			if (b_LBA) {
				gsp.begin.lba = strtol64(argv[0], NULL, 0);
			} else {
				if (!GetCHS(argv[0], &gsp.begin.cylinder, &gsp.begin.head, &gsp.begin.sector)) {
					cerr << "you must enter as cylinders:heads:sectors format!" << endl;
					return -1;
				}
			}
		}
	}

	b = GetDiskInfo(&di);
	if (!b) {
		cerr	<< "can't get disk info!" << endl;
		return -1;
	}
	if (b_dump_info) {
		// ... dump ...
		cout	<< "Disk Size: "; output_u64(di.size, 10); cout << endl
			;
		for (int i = 0; i < di.n_parts; i++) {
			PART_INFO *pi = di.parts + i;
			cout	<< "Partition " << i << ": ";
			switch (pi->system_type) {
			case ps_unused:		cout << "not used"; break;
			case ps_ntfs:		cout << "NTFS"; break;
			case ps_fat_16:		cout << "FAT-16"; break;
			case ps_fat_32:		cout << "FAT-32"; break;
			case ps_fat_32_lba:	cout << "FAT-32 (LBA)"; break;
			case ps_ext2:		cout << "Linux ext2"; break;
			case ps_linux_swap:	cout << "Linux swap"; break;
			default:		cout << "type " << (int)pi->system_type; break;
			}
			if (pi->system_type != ps_unused) {
				if (pi->bootable) cout << " (boot)";
				cout	<< endl
					<< "	(LBA/";
					output_u64(pi->begin.lba, 10);
				cout	<< ") cy ";
					output_u64(pi->begin.cylinder, 10);
				cout	<< " hd " << pi->begin.head << " sec " << pi->begin.sector
					<< " => cy";
					output_u64(pi->end.cylinder, 10);
				cout	<< " hd " << pi->end.head << " sec " << pi->end.sector
					<< " (LBA/";
					output_u64(pi->end.lba, 10);
				cout	<< ")";
			}
			cout	<< endl;
		}
	}

	CalcAddr(&di, &gsp.begin, TRUE);
	gsp.end = gsp.begin;
	if (b_LBA) {
		gsp.end.mode = DISK_ADDR::mode_lba;
		gsp.end.lba = gsp.begin.lba + len_LBA_Blocks - 1;
	} else {
		DISK_ADDR _len;
		_len.mode	= DISK_ADDR::mode_chs;
		_len.cylinder	= len_Cylinders;
		_len.head	= len_Heads;
		_len.sector	= len_Sectors;
		CalcAddr(&di, &_len, TRUE);
		gsp.end.mode = DISK_ADDR::mode_lba;
		len_LBA_Blocks = _len.lba;
		gsp.end.lba = gsp.begin.lba + _len.lba - 1;
	}
	CalcAddr(&di, &gsp.end, TRUE);

	if (gsp.end.linear >= di.size) {
		cerr << "out of the disk!!!" << endl;
		return -1;
	}

	/*
	u64_t rest_blocks = len_LBA_Blocks;
	const BLOCK_ONCE = 8192;	// 8192 * 512 = 4M
	while (rest_blocks > 0) {
		gsp.begin.lba = gsp.end + 1;
		int getq = rest_blocks % BLOCK_ONCE;
		if (getq == 0) getq = BLOCK_ONCE;
		rest_blocks -= geqt;
		gsp.end.lba = gsp.begin.lba + getq;
	*/

	gsp.buffer = new BYTE[di.sector_size * len_LBA_Blocks];
	b = FALSE;
	if (bWriteMode) {
		if (bRandom) {
		}
		HANDLE hf = CreateFile(szFile, GENERIC_READ, 0, NULL, OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL, NULL);
		if (hf != INVALID_HANDLE_VALUE) {
			DWORD fsLow, fsHigh;
			fsLow = GetFileSize(hf, &fsHigh);
			u64_t filesize = fsLow + (fsHigh << 32);
			DWORD cbRead;

			// not consider 64-bit, in following code.
			b = ReadFile(hf, gsp.buffer, fsLow, &cbRead, NULL);
			if (b) {
				b = PutSector(&di, &gsp);
				if (!b) {
					switch (gsp.err) {
					case GET_SECTOR_PARAM::err_cant_open:
						cerr	<< "can't open the disk! " << gsp.syserr << endl;
						break;
					case GET_SECTOR_PARAM::err_cant_write:
						cerr	<< "can't write the sectors! " << gsp.syserr << endl;
						break;
					case GET_SECTOR_PARAM::err_crc:
						cerr	<< "crc error! " << gsp.syserr << endl;
						break;
					case GET_SECTOR_PARAM::err_bad_sector:
						cerr	<< "bad sectors occured! " << gsp.syserr << endl;
						break;
					case GET_SECTOR_PARAM::err_index_error:
						cerr	<< "index out of the disk! " << gsp.syserr << endl;
						break;
					case GET_SECTOR_PARAM::err_sharing:
						cerr	<< "sharing volitale! " << gsp.syserr << endl;
						break;
					}
				}
			}
			CloseHandle(hf);
		}
	} else {
		b = GetSector(&di, &gsp);
		if (!b) {
			switch (gsp.err) {
			case GET_SECTOR_PARAM::err_cant_open:
				cerr	<< "can't open the disk! " << gsp.syserr << endl;
				break;
			case GET_SECTOR_PARAM::err_cant_read:
				cerr	<< "can't read the sectors! " << gsp.syserr << endl;
				break;
			case GET_SECTOR_PARAM::err_crc:
				cerr	<< "crc error! " << gsp.syserr << endl;
				break;
			case GET_SECTOR_PARAM::err_bad_sector:
				cerr	<< "bad sectors occured! " << gsp.syserr << endl;
				break;
			case GET_SECTOR_PARAM::err_index_error:
				cerr	<< "index out of the disk! " << gsp.syserr << endl;
				break;
			case GET_SECTOR_PARAM::err_sharing:
				cerr	<< "sharing volitale! " << gsp.syserr << endl;
				break;
			}
			return gsp.err;
		}

		//DumpBytes(gsp.buffer, di.sector_size * len_LBA_Blocks);
		FILE *pf = fopen(szFile, "wb");
		if (pf) {
			fwrite(gsp.buffer, di.sector_size, len_LBA_Blocks, pf);
			fclose(pf);
		}
	}

	DestroyDiskInfo(&di);
	DestroyGetSectorParam(&gsp);
	return 0;
}

void _stdcall DestroyPartInfo(PART_INFO *pPI) {
	if (pPI->label) delete pPI->label;
	if (pPI->boot_record) delete pPI->boot_record;
	if (pPI->system) delete pPI->system;
	if (pPI->n_sub_parts) {
		for (int i = 0; i < pPI->n_sub_parts; i++) {
			DestroyPartInfo(pPI->sub_parts + i);
		}
		delete[] pPI->sub_parts;
	}
}

void _stdcall DestroyDiskInfo(DISK_INFO *pDI) {
	if (pDI->n_parts > 0 && pDI->parts) {
		for (int i = 0; i < pDI->n_parts; i++) {
			DestroyPartInfo(pDI->parts + i);
		}
	}
	delete[] pDI->parts;
}

void _stdcall DestroyGetSectorParam(GET_SECTOR_PARAM *pGSP) {
	if (pGSP->buffer) delete[] pGSP->buffer;
}

DWORD _stdcall OpenDisk(int disk) {
	char szDiskPath[_MAX_PATH];
	sprintf(szDiskPath, "\\\\.\\PHYSICALDRIVE%d", disk);

	HANDLE hFile;
	hFile = CreateFile(szDiskPath, GENERIC_READ | GENERIC_WRITE, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) return 0;
	return (DWORD)hFile;
}

BOOL _stdcall CloseDisk(DWORD hDisk) {
	return CloseHandle((HANDLE)hDisk);
}

BOOL _stdcall GetDiskInfo(DISK_INFO *pDI) {
	HANDLE hDisk = (HANDLE)OpenDisk(pDI->iDisk);
	if (hDisk == 0) return FALSE;

	BOOL b;
	DWORD cbRead = 0;

	DISK_GEOMETRY_EX geox;
	b = DeviceIoControl(hDisk, IOCTL_DISK_GET_DRIVE_GEOMETRY_EX, NULL, 0,
		&geox, sizeof(geox), &cbRead, NULL);
	if (!b) return FALSE;

	//
	DISK_PARTITION_INFO *pDPI;
	DISK_DETECTION_INFO *pDDI;
	pDPI = DiskGeometryGetPartition(&geox);
	pDDI = DiskGeometryGetDetect(&geox);

	pDI->cylinders	= geox.Geometry.Cylinders.QuadPart;
	pDI->heads	= geox.Geometry.TracksPerCylinder;
	pDI->sectors	= geox.Geometry.SectorsPerTrack;
	pDI->sector_size = geox.Geometry.BytesPerSector;
	pDI->media_type = geox.Geometry.MediaType;
	pDI->size	= geox.DiskSize.QuadPart;

	BYTE dlix_buf[sizeof(DRIVE_LAYOUT_INFORMATION_EX) +
			sizeof(PARTITION_INFORMATION_EX) * 16];
	DRIVE_LAYOUT_INFORMATION_EX *pdlix =
		(DRIVE_LAYOUT_INFORMATION_EX *)dlix_buf;
	b = DeviceIoControl(hDisk, IOCTL_DISK_GET_DRIVE_LAYOUT_EX, NULL, 0,
		pdlix, sizeof(dlix_buf), &cbRead, NULL);

	pDI->n_parts = pdlix->PartitionCount;
	pDI->parts = new PART_INFO[pDI->n_parts];
	for (int i = 0; i < pdlix->PartitionCount; i++) {
		PARTITION_INFORMATION_EX *ppix = pdlix->PartitionEntry + i;
		PART_INFO *pi	= pDI->parts + i;
		__zero(*pi);
		pi->iPart	= ppix->PartitionNumber;
		pi->system_type	= (PART_SYSTEM)ppix->Mbr.PartitionType;
		pi->bootable	= ppix->Mbr.BootIndicator;
		pi->n_hidden_sectors = ppix->Mbr.HiddenSectors;
		pi->begin.mode	= DISK_ADDR::mode_linear;
		pi->begin.linear= ppix->StartingOffset.QuadPart;
		pi->end.mode	= DISK_ADDR::mode_linear;
		pi->end.linear	= ppix->PartitionLength.QuadPart;

		CalcAddr(pDI, &pi->begin, FALSE);
		CalcAddr(pDI, &pi->end, FALSE);

		// read boot sector
		b = SetFilePointerEx(hDisk, (LARGE_INTEGER&)pi->begin.linear, NULL, NULL);
		if (b) {
			cbRead = pDI->sector_size * 2;
			pi->boot_record	= new BYTE[cbRead];
			b = ReadFile(hDisk, pi->boot_record, cbRead, &cbRead, NULL);
			if (!b) delete[] pi->boot_record;
		}
		if (!b) pi->boot_record = NULL;

	}

	return CloseDisk((DWORD)hDisk);
}

void _stdcall CalcAddr(DISK_INFO *pDI, DISK_ADDR *pDA, BOOL bAlign) {
	switch (pDA->mode) {
	case DISK_ADDR::mode_chs:
		pDA->lba = (pDA->cylinder * pDI->heads + pDA->head) * pDI->sectors +
			pDA->sector - 1;
		pDA->linear = pDA->lba * pDI->sector_size;
		break;
	case DISK_ADDR::mode_lba:
		pDA->linear = (pDA->lba - 1) * pDI->sector_size;
	case DISK_ADDR::mode_linear:
		{
			if (bAlign) {
				// align to sector-size.
				pDA->linear += pDI->sector_size - 1;
				pDA->linear -= pDA->linear % pDI->sector_size;
			}
			pDA->lba = pDA->linear / pDI->sector_size;

			int s = pDA->lba;			// sectors
			pDA->sector = s % pDI->sectors;
			s = (s - pDA->sector) / pDI->sectors;	// heads
			pDA->head = s % pDI->heads;
			s = (s - pDA->head) / pDI->heads;	// cylinders
			pDA->cylinder = s;

			pDA->sector++;	// chs sector is 1-based
			pDA->lba++;	// lba is 1-based
		}
		break;
	}
}

BOOL _stdcall GetSector(DISK_INFO *pDI, GET_SECTOR_PARAM *param) {
	param->err = GET_SECTOR_PARAM::err_ok;

	HANDLE hDisk = (HANDLE)OpenDisk(pDI->iDisk);
	if (hDisk == 0) {
		param->err = GET_SECTOR_PARAM::err_cant_open;
		return FALSE;
	}

	CalcAddr(pDI, &param->begin, TRUE);
	CalcAddr(pDI, &param->end, TRUE);

	BOOL b;
	DWORD cbRead;
	DWORD cbRet;

	b = SetFilePointerEx(hDisk, (LARGE_INTEGER&)param->begin.linear, NULL, NULL);
	if (!b) {
		param->err = GET_SECTOR_PARAM::err_index_error;
		CloseDisk((DWORD)hDisk);
		return FALSE;
	}

	cbRead = param->end.linear - param->begin.linear
		+ pDI->sector_size;	// user enter [from,to], if not add the extra sector, the result is [from,to)
	b = ReadFile(hDisk, param->buffer, cbRead, &cbRet, NULL);
	if (!b || cbRet < cbRead) {
		param->err = GET_SECTOR_PARAM::err_cant_read;
		param->syserr = GetLastError();
		switch (param->syserr) {
		case ERROR_CRC:
			param->err = GET_SECTOR_PARAM::err_crc;
			break;
		case ERROR_SECTOR_NOT_FOUND:
			param->err = GET_SECTOR_PARAM::err_index_error;
			break;
		case ERROR_READ_FAULT:
			param->err = GET_SECTOR_PARAM::err_cant_read;
			break;
		case ERROR_SHARING_VIOLATION:
		case ERROR_LOCK_VIOLATION:
			param->err = GET_SECTOR_PARAM::err_sharing;
			break;
		}
		CloseDisk((DWORD)hDisk);
		return FALSE;
	}

	return CloseDisk((DWORD)hDisk);
}



BOOL _stdcall PutSector(DISK_INFO *pDI, GET_SECTOR_PARAM *param) {
	param->err = GET_SECTOR_PARAM::err_ok;

	HANDLE hDisk = (HANDLE)OpenDisk(pDI->iDisk);
	if (hDisk == 0) {
		param->err = GET_SECTOR_PARAM::err_cant_open;
		return FALSE;
	}

	CalcAddr(pDI, &param->begin, TRUE);
	CalcAddr(pDI, &param->end, TRUE);

	BOOL b;
	DWORD cbWrite;
	DWORD cbRet;

	b = SetFilePointerEx(hDisk, (LARGE_INTEGER&)param->begin.linear, NULL, NULL);
	if (!b) {
		param->err = GET_SECTOR_PARAM::err_index_error;
		CloseDisk((DWORD)hDisk);
		return FALSE;
	}

	cbWrite = param->end.linear - param->begin.linear
		+ pDI->sector_size;	// user enter [from,to], if not add the extra sector, the result is [from,to)
	b = WriteFile(hDisk, param->buffer, cbWrite, &cbRet, NULL);
	if (!b || cbRet < cbWrite) {
		param->err = GET_SECTOR_PARAM::err_cant_write;
		param->syserr = GetLastError();
		switch (param->syserr) {
		case ERROR_CRC:
			param->err = GET_SECTOR_PARAM::err_crc;
			break;
		case ERROR_SECTOR_NOT_FOUND:
			param->err = GET_SECTOR_PARAM::err_index_error;
			break;
		case ERROR_READ_FAULT:
			param->err = GET_SECTOR_PARAM::err_cant_write;
			break;
		case ERROR_SHARING_VIOLATION:
		case ERROR_LOCK_VIOLATION:
			param->err = GET_SECTOR_PARAM::err_sharing;
			break;
		}
		CloseDisk((DWORD)hDisk);
		return FALSE;
	}

	return CloseDisk((DWORD)hDisk);
}
