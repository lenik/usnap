// folder.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	CoInitialize(NULL);

	TCHAR	pdn[MAX_PATH];		// display name
	TCHAR	folder[MAX_PATH];	// path name

	BROWSEINFO bi;
	LPITEMIDLIST	pidl;

	bi.hwndOwner		= NULL;
	bi.pidlRoot		= NULL;
	bi.pszDisplayName	= pdn;
	bi.lpszTitle		= "select a directory: ";
	bi.ulFlags		= BIF_EDITBOX; //BIF_USENEWUI;
	bi.lpfn			= 0;
	bi.lParam		= 0;
	bi.iImage		= 0;

	pidl	= SHBrowseForFolder(&bi);

	if (pidl) {
		SHGetPathFromIDList(pidl, folder);

		IMalloc	*pMalloc = NULL;
		if (SUCCEEDED(SHGetMalloc(&pMalloc))) {
			pMalloc->Free(pidl);
			pMalloc->Release();
		}
	}

	CoUninitialize();

	return pidl != NULL;
}
