// getpart_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
__std;

//#include <ntddk.h>
#include <winioctl.h>

BYTE g_buf[1048576];

int main(int argc, char* argv[])
{
	BOOL b;
	DWORD cbRet = 0;

	DISK_GEOMETRY diskGeo;

	HANDLE hDisk = ::CreateFile("\\\\.\\PHYSICALDRIVE0", GENERIC_READ | GENERIC_WRITE, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hDisk == INVALID_HANDLE_VALUE) return -1;

	b = DeviceIoControl(hDisk, IOCTL_DISK_GET_DRIVE_GEOMETRY, 0, 0,
		&diskGeo, sizeof(diskGeo), &cbRet, NULL);

	if (b) {
		cout	<< "Cylinders:	" << (int)diskGeo.Cylinders.QuadPart << endl
			<< "Tracks:   	" << diskGeo.TracksPerCylinder << endl
			<< "Sectors:	" << diskGeo.SectorsPerTrack << endl
			<< "MediaType:	" << (int)(diskGeo.MediaType) << endl
			;
	}


	__zero(g_buf);

	LARGE_INTEGER mv, ret;
	mv.QuadPart =  40960;
	b = SetFilePointerEx(hDisk, mv, &ret, FILE_BEGIN);

	b = ReadFile(hDisk, g_buf, 512, &cbRet, NULL);


	if (b) {
		cout	<< "size: " << ret.u.HighPart << " " << ret.u.LowPart << endl;
	}

	CloseHandle(hDisk);
	return 0;
}
