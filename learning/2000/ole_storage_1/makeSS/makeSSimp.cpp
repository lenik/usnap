
#include "stdafx.h"

LPCTSTR	spaces(int level) {
	static TCHAR	c[256];
	int	p = 0;
	for (int i = 0; i < level; i++) {
		c[p++]	= ' ';
		c[p++]	= ' ';
	}
	c[p]	= 0;
	return c;
}

OLECHAR	*towcs(LPCTSTR mbs) {
	static OLECHAR	wcs[256];
	if (sizeof(TCHAR) == 1) {
		MultiByteToWideChar(
			CP_ACP, MB_PRECOMPOSED,
			mbs, lstrlen(mbs) + 1,
			wcs, 256);
			return wcs;
	} else {
		return (OLECHAR *)mbs;
	}
}

LPCTSTR	tombs(OLECHAR *wcs) {
	static TCHAR	mbs[256];
	if (sizeof(TCHAR) == 1) {
		WideCharToMultiByte(
			CP_ACP, 0,
			wcs, lstrlenW(wcs) + 1,
			mbs, 256,
			NULL, NULL);
		return mbs;
	} else {
		return (LPCTSTR)wcs;
	}
}

void	saveFile(IStorage *pStg, LPCTSTR basePath, LPCTSTR fileName) {
	TCHAR fullname[MAX_PATH];
	lstrcpy(fullname, basePath);
	lstrcat(fullname, _T("\\"));
	lstrcat(fullname, fileName);
	OLECHAR		*pwcs = towcs(fileName);

	HRESULT	hr;
	IStream	*pStream;
	hr	= pStg->CreateStream(pwcs,
		(STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE),
		0, 0, &pStream);
	if (SUCCEEDED(hr)) {
		HANDLE		hF;
		hF	= CreateFile(
			fullname, GENERIC_READ,
			0, NULL,
			OPEN_EXISTING,
			0,
			NULL);
		BYTE	*data;
		DWORD	l, l2;
		if (hF != INVALID_HANDLE_VALUE) {
			if ((l = GetFileSize(hF, NULL)) > 0) {
				data	= new BYTE[l];
				if (ReadFile(hF, (LPVOID)data, l, &l2, NULL)) {
					hr = pStream->Write((LPVOID)data, l2, NULL);
					hr = pStream->Commit(STGC_DEFAULT);
				}
			}
			CloseHandle(hF);
		}
		pStream->Release();
	}
}
