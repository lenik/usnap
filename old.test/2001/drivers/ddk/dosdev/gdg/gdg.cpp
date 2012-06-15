// gdg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <winioctl.h>
#include <stdio.h>

BOOL GetDriveGeometry(LPTSTR lpDevName, DISK_GEOMETRY *pdg)
{
    HANDLE hDevice;
    BOOL fResult;
    DWORD cb;

	hDevice = CreateFile(
		lpDevName,
		0,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);
	if (hDevice == NULL) return FALSE;

	fResult = DeviceIoControl(
		hDevice,
		IOCTL_DISK_GET_DRIVE_GEOMETRY,
		NULL,
		0,
		pdg,
		sizeof(DISK_GEOMETRY),
		&cb,
		(LPOVERLAPPED)NULL
		);
	CloseHandle(hDevice);

	if (fResult == FALSE) return FALSE;
	return TRUE;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("gdg <devicename>\n");
		return 0;
	}
	DISK_GEOMETRY dg;
	if (GetDriveGeometry(argv[1], &dg) == FALSE) {
		perror("Error when opening device");
		return -1;
	} else {
		printf("MediaType: \t");
			switch (dg.MediaType) {
			case Unknown: 			printf(" Format is unknown "); break;
			case F5_1Pt2_512: 		printf(" 5.25\", 1.2MB,  512 bytes/sector "); break;
			case F3_1Pt44_512: 		printf(" 3.5\",  1.44MB, 512 bytes/sector "); break;
			case F3_2Pt88_512: 		printf(" 3.5\",  2.88MB, 512 bytes/sector "); break;
			case F3_20Pt8_512: 		printf(" 3.5\",  20.8MB, 512 bytes/sector "); break;
			case F3_720_512: 		printf(" 3.5\",  720KB,  512 bytes/sector "); break;
			case F5_360_512: 		printf(" 5.25\", 360KB,  512 bytes/sector "); break;
			case F5_320_512: 		printf(" 5.25\", 320KB,  512 bytes/sector "); break;
			case F5_320_1024: 		printf(" 5.25\", 320KB,  1024 bytes/sector "); break;
			case F5_180_512: 		printf(" 5.25\", 180KB,  512 bytes/sector "); break;
			case F5_160_512: 		printf(" 5.25\", 160KB,  512 bytes/sector "); break;
			case RemovableMedia: 	printf(" Removable media other than floppy "); break;
			case FixedMedia:		printf(" Fixed hard disk media "); break;
			default:				printf(" ??? "); break;
			}
		printf("\nCylinders: \t%d\nTracks/Cyl: \t%d\nSectors/Trk: \t%d\nBytes/Sec: \t%d\n",
			(int)dg.Cylinders.QuadPart, dg.TracksPerCylinder, dg.SectorsPerTrack, dg.BytesPerSector);
		printf("\n");
		return 0;
	}
}
