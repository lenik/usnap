// STG1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#ifdef A
int main(int argc, char* argv[])
{

	HRESULT	hErr;
	LPVOID	memPtr;
	HGLOBAL	hMem;
	LPSTORAGE	pStg;
	LPLOCKBYTES	pLckBytes;

	CoInitialize(NULL);

	hErr	= CreateILockBytesOnHGlobal(NULL, TRUE, &pLckBytes);
	if (SUCCEEDED(hErr)) {
		hErr	= StgCreateDocfile(pLckBytes,
			STGM_CREATE | STGM_DIRECT | STGM_READWRITE | STGM_SHARE_EXCLUSIVE,
			NULL,
			&pStg);
		if (SUCCEEDED(hErr)) {
			pStg->Release();
		}
		GetHGlobalFromILockBytes(pLckBytes, &hMem);
		memPtr	= GlobalLock(hMem);
		// save...
		GlobalUnlock(hMem);
		pLckBytes->Release();
		hErr	= CreateILockBytesOnHGlobal(hMem, FALSE, &pLckBytes);
		if (SUCCEEDED(hErr)) {
			hErr	= StgOpenStorage(pLckBytes, NULL,
					STGM_DIRECT | STGM_READWRITE | STGM_DIRECT | STGM_SHARE_EXCLUSIVE,
					NULL, 0,
					&pStg);
			if (SUCCEEDED(hErr)) {
				// ...
				pStg->Release();
			}
			pLckBytes->Release();
			GlobalFree(hMem);
		}
	}

	CoUninitialize();

	printf("Hello World!\n");
	return 0;
}
#endif

#ifndef XX
void main() {
	ULONG i;
	char s[1024];
	for (i = 0; i < 0xFFFF; i++) {
		if (GetClipboardFormatName(i, s, 1024)) {
			printf("%4d = [%s]\n", i, s);
		}
	}

}
#endif
