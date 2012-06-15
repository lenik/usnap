// winc2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void s() {
	IStorage	*pStg;

	HRESULT		hErr;

	hErr	= StgCreateDocfile(L"test.dfl",
		STGM_CREATE | STGM_TRANSACTED | STGM_READWRITE,
		0,
		&pStg);
	if (FAILED(hErr)) {
		// ...
		return;
	}
	printf("succeeded in create docfile. \n");
	pStg->Release();
}

BOOL	s2() {
	LPMALLOC	pMalloc;
	LPSTORAGE	pStg;
	LPENUMSTATSTG	pEnum;
	STATSTG		statStg;
	HRESULT		hErr;

	hErr	= pStg->EnumElements(0, NULL, 0, &pEnum);
	if (FAILED(hErr)) {
		MessageBox(NULL, "IStorage::EnumElements() failed", NULL, MB_OK);
		return FALSE;
	}

	CoGetMalloc(MEMCTX_TASK, &pMalloc);
	hErr = S_OK;
	while (GetScode(hErr) == S_OK) {
		hErr	= pEnum->Next(1, &statStg, NULL);
		if (GetScode(hErr) == S_FALSE) break;
		if (statStg.pwcsName != NULL) {
			MessageBox(NULL, statStg.pwcsName, NULL, MB_OK);
			pMalloc->Free(statStg.pwcsName);
		}
	}

	pMalloc->Release();
	pEnum->Release();
	pStg->Release();
	return TRUE;
	IStorage::Commit();
	ULARGE_INTEGER u;
}

int main(int argc, char **argv) {
	s();
	return 0;
}
