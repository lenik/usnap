// enumdev.cpp : Defines the entry point for the console application.
//


#include "..\\enumdev\\stdafx.h"

#include <stdio.h>

#define INITGUID
#include <initguid.h>
DEFINE_GUID(IID_1,
			0x53f56307, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b
			);

LPTSTR StringFromGuid(LPGUID guid) {
	static TCHAR buf[256];
	sprintf(buf, "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
		guid->Data1, guid->Data2, guid->Data3,
		guid->Data4[0], guid->Data4[1],
		guid->Data4[2], guid->Data4[3], guid->Data4[4],
		guid->Data4[5], guid->Data4[6], guid->Data4[7]
	);
	return buf;
}

int main(int argc, char* argv[])
{

	DWORD DIGCFlags = DIGCF_ALLCLASSES;
	HDEVINFO i;
	SP_DEVINFO_LIST_DETAIL_DATA detailData;
	SP_DEVINFO_DATA data;
	SP_DEVICE_INTERFACE_DATA interfaceData;

	BOOLEAN r;

	if (argc > 1) {
		DIGCFlags = (DWORD)atol(argv[1]);
	}

	i = SetupDiGetClassDevs(
		NULL,
		NULL,
		NULL,
		DIGCFlags);

	printf("HDEVINFO returned by SetupDiGetClassDevs : \n\t\t%x\n", i);

	if (i == INVALID_HANDLE_VALUE) {
		printf("Could not get class device info: %d\n", GetLastError());
		return -1;
	}

	detailData.cbSize = sizeof(SP_DEVINFO_DATA);
	data.cbSize = sizeof(SP_DEVINFO_DATA);
	interfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

	r = SetupDiGetDeviceInfoListDetail(
		i,
		&detailData
		);

	if (r) {
		printf("ClassGuid: \t%s\nRemoteHandle: \t%d\nRemoteName: \t%s\n---------------\n",
			StringFromGuid(&detailData.ClassGuid),
			detailData.RemoteMachineHandle,
			detailData.RemoteMachineName);
	} else {
		printf("Could not get detail infos: %d\n", GetLastError());
	}


	for (int mi = 0; ; mi++) {
		r = SetupDiEnumDeviceInfo(
			i,
			mi,
			&data);
		if (!r) {
			if (GetLastError() != ERROR_NO_MORE_ITEMS) {
				printf("could not enum device info[%d]: %d\n", mi, GetLastError());
			}
			break;
		}
		printf("ClassGuid: \t%s\nDevInst: \t%d\n------\n",
			StringFromGuid(&data.ClassGuid),
			data.DevInst);
	}

	SetupDiDestroyDeviceInfoList(i);
	return 0;
}
