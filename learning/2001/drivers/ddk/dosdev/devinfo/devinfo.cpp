
//

#include "..\\enumdev\\stdafx.h"

#include <stdio.h>


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

template<class T>
PTCHAR nstr(T i) {
	static TCHAR buf[1024];
	static int p = 0;
	if (p > 800) p = 0;
	switch (sizeof(T)) {
	case 2:
	case 4:
		sprintf(buf + p, "%d'%x", i, i); break;
	}
	p += 100;
	return buf + p - 100;
}

template<class T>
PTCHAR nfstr(T i) {
	static TCHAR buf[1024];
	static int p = 0;
	if (p > 800) p = 0;
	switch (sizeof(T)) {
	case 2:
	case 4:
		sprintf(buf + p, "%8d'0x%08x", i, i); break;
	}
	p += 100;
	return buf + p - 100;
}

int showVeryDetail = 0;
PTCHAR veryDetail(LPSTR devID) {
	HANDLE hF;
	TCHAR detailBuf[16384];
	hF = CreateFile(
		devID,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	CloseHandle(hF);
	return detailBuf;
}

BOOL showID = FALSE;
PTCHAR IDStr(DEVINST devinst) {
	static TCHAR buf[1024];
	static TCHAR sbuf[1024];
	CONFIGRET cr;
	sprintf(sbuf, "%s", nfstr(devinst));
	if (showID) {
		ULONG len[2];
		len[0] = sizeof(buf);
		len[1] = strlen(sbuf);
		cr = CM_Get_Device_ID(devinst, buf, len[0], 0);
		if (cr == CR_SUCCESS) {
			sprintf(sbuf + len[1], "(%s)", buf);
		} else {
			sprintf(sbuf + len[1], "(Err:%s)", nstr(cr));
		}
	}
	return sbuf;
}
PTCHAR IDStrOnly(DEVINST devinst) {
	static TCHAR buf[1024];
	static TCHAR sbuf[1024];
	CONFIGRET cr;
	if (showID) {
		ULONG len[2];
		len[0] = sizeof(buf);
		len[1] = 0;
		cr = CM_Get_Device_ID(devinst, buf, len[0], 0);
		if (cr == CR_SUCCESS) {
			sprintf(sbuf + len[1], "(%s)", buf);
		} else {
			sprintf(sbuf + len[1], "(Err:%s)", nstr(cr));
		}
	} else {
		sprintf(sbuf, "%s", nfstr(devinst));
	}
	return sbuf;
}

CONFIGRET GetTopDevNode(PDEVINST pdevinst) {
	CONFIGRET cr;
	cr = CM_Locate_DevNode(pdevinst, NULL, CM_LOCATE_DEVNODE_NORMAL);
	return cr;
}

void GetChildren(DEVINST devinst) {
	DEVINST i2;
	CONFIGRET cr;

	cr = CM_Get_Child(&i2, devinst, 0);
	if (cr == CR_SUCCESS) {
		printf("the children of %s\n", IDStr(devinst));
		do {
			printf("\t%s\n", IDStr(i2));
			devinst = i2;
			cr = CM_Get_Sibling(&i2, devinst, 0);
		} while (cr == CR_SUCCESS);
	} else {
		printf("could not get the first child of %s:\n", IDStr(devinst));
		printf("\tCR \t= %s\n", nstr(cr));
	}
	return;
}

void PrintIndent(int Level) { for (int i = 0; i < Level; i++) printf("\t"); }
void GetTree(DEVINST devinst, int Level) {
	DEVINST i2;
	CONFIGRET cr;

	cr = CM_Get_Child(&i2, devinst, 0);
	if (cr == CR_SUCCESS) {
		PrintIndent(Level);
			printf("%s\n", IDStrOnly(devinst));
		do {
			PrintIndent(Level + 1);
				printf("%s\n", IDStrOnly(i2));
			GetTree(i2, Level + 1);

			devinst = i2;
			cr = CM_Get_Sibling(&i2, devinst, 0);
		} while (cr == CR_SUCCESS);
	} else {
		PrintIndent(Level + 1);
			printf("----NO_CHILD----\n");
	}
	return;
}

int main(int argc, char **argv) {
	int devfn;
	DEVINST devinst;

	ULONG status, problemnum;
	CONFIGRET cr;

	//ULONG len[10]; // 10 number for operations relative to length

	if (argc < 3) {
		printf("devinfo <fn> <devinst>\n"
			"fn=0	get status\n"
			"fn=2	dump children\n"
			"fn=4	dump tree\n"
			"fn=100	get top node\n"
			"fn=102	get device path\n"
		);
		return 0;
	}

	devfn = atol(argv[1]);
	devinst = atol(argv[2]);

	if (devfn % 2) showID = TRUE;
	devfn = (devfn | 1) - 1;
	if (devfn > 1000) {
		showVeryDetail = 1;
		devfn -= 1000;
	}

	HDEVINFO hDevInfoList;
	printf("get device info lists...\n");
	hDevInfoList = SetupDiGetClassDevs(
		NULL,
		NULL,
		NULL,
		DIGCF_ALLCLASSES);
	printf("destroy list...\n");
	SetupDiDestroyDeviceInfoList(hDevInfoList);

	switch (devfn) {
	case 0:
		status = problemnum = 0;
		cr = CM_Get_DevNode_Status(&status, &problemnum, devinst, 0);
		if (cr == CR_SUCCESS) {
			printf("success get status of %s: \n", IDStr(devinst));
			printf("\tstatus\t= %s\n\tprobnum\t= %s\n", nstr(status), nstr(problemnum));
		} else {
			printf("error get status of %s: \n", IDStr(devinst));
			printf("\tCR \t= %s\n\tprobnum\t= %s\n", nstr(cr), nstr(problemnum));
		}
		break;
	case 2:
		GetChildren(devinst);
		break;
	case 4:
		printf("Tree List of %s\n\n", IDStr(devinst));
		GetTree(devinst, 0);
		break;
	case 100:
		DEVINST topdev;
		cr = GetTopDevNode(&topdev);
		if (cr == CR_SUCCESS) {
			printf("the top device in device tree is : \n");
			printf("\t%s\n", IDStr(topdev));
			//printf("\t%s\n", IDStr(devinst));
		} else {
			printf("could not get the top device: \n");
			printf("\t%s\n", nstr(cr));
		}
		break;
	case 102:
		// Get Device Path of DEVINST
/*		SetupDiGetDeviceInterfaceDetail(
			hDevInfoList,
*/
	default:
		printf("The <fn=%s> specified doesn't supported now. \n", nstr(devfn));
		;
	}
	return 0;
}
