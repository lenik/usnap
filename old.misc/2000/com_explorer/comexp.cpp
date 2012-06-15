// comexp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void pstart(char *pstr = "[") {
	__p_str = pstr;
	__p_stepped = false;
}
void pstep(char *pstr = ",") {
	if (__p_str) printf(__p_str);
	__p_str = pstr;
	__p_stepped = true;
}
void pend(char *pstr = "]") {
	if (__p_stepped) {
		if (pstr) printf(pstr);
		__p_str = NULL;
	}
}

int main(int argc, char* argv[])
{
	if (argc < 2) {
		printf("comexp <binary filename>\n");
		return 0;
	}

	HRESULT hr;
	hr = CoInitialize(NULL);
	ASSERT(SUCCEEDED(hr));

	int filenamelen = lstrlen(argv[1]);
	WCHAR *wFilename = new WCHAR[filenamelen + 1];
	ITypeLib *pTL = NULL;
	mbstowcs(wFilename, argv[1], filenamelen + 1);

	hr = LoadTypeLib(wFilename, &pTL);
	SAFE_DELETE_ARRAY(wFilename);

	if (FAILED(hr)) {
		printf("can't load its typelib. \n");
		return 0;
	}

	TLIBATTR *plibattr = NULL;
	pTL->GetLibAttr(&plibattr);

	LPOLESTR pwsGuid = NULL;
	hr = StringFromIID(plibattr->guid, &pwsGuid);
	wprintf(L"GUID: %s", pwsGuid);
	CoTaskMemFree(pwsGuid);
	printf(" (Version: %d.%d) SysKind:%d/%s Flags: %08X\n", plibattr->wMajorVerNum, plibattr->wMinorVerNum,
		plibattr->syskind, plibattr->syskind == SYS_WIN32 ? "SYS_WIN32" : "SYS_WIN16 or other",
		plibattr->wLibFlags);

	pstart("LibFlags[");
		if (plibattr->wLibFlags & LIBFLAG_FRESTRICTED) { pstep(); printf("LIBFLAG_FRESTRICTED"); }
		if (plibattr->wLibFlags	& LIBFLAG_FCONTROL) { pstep(); printf("LIBFLAG_FCONTROL"); }
		if (plibattr->wLibFlags & LIBFLAG_FHIDDEN) { pstep(); printf("LIBFLAG_FHIDDEN"); }
		if (plibattr->wLibFlags & LIBFLAG_FHASDISKIMAGE) {pstep(); printf("LIBFLAG_FHADDISKIMAGE"); }
		//if (plibattr->wLibFlags & LIBFLAG_FORCELONG) { pstep(); printf("LIBFLAG_FORCELONG"); }
	pend("]\n");

	int count = pTL->GetTypeInfoCount();
	printf("TypeInfoCount=%d\n", count);

	for (int i = 0; i < count; i++) {
		ITypeInfo *pTI = NULL;
		hr = pTL->GetTypeInfo(i, &pTI);

		printf("TypeInfo[%d]: ", i);
		if (FAILED(hr)) {
			printf("can't get this TypeInfo!\n");
			continue;
		}

		DumpTypeInfo(pTI);

		SAFE_RELEASE(pTI);
	}

	SAFE_RELEASE(pTL);

	CoUninitialize();
	return 0;
}
