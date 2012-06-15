// makeSS.cpp : Defines the entry point for the console application.
//

// 本程序将指定的目录及子目录转换成SS（复合文档）

// 谢继雷, 2001.3.11

#include "stdafx.h"
#include "gwin.h"

#include "makeSS.h"

void	Find(LPCTSTR basePath, int level, IStorage *pStg) {
	HANDLE		h;
	BOOL		b;
	WIN32_FIND_DATA	wfd;
	TCHAR		baseFind[MAX_PATH];

	lstrcpy(baseFind, basePath);
	lstrcat(baseFind, _T("\\*.*"));
	h	= FindFirstFile(baseFind, &wfd);

	if (h != INVALID_HANDLE_VALUE) {
		b	= TRUE;
		while (b) {
			printf("%s%s\n", spaces(level), wfd.cFileName);
			if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
				if (wfd.cFileName[0] != (TCHAR)'.') {
					TCHAR	enter[MAX_PATH];
					lstrcpy(enter, basePath);
					lstrcat(enter, _T("\\"));
					lstrcat(enter, wfd.cFileName);
					IStorage	*pEnterStg;
					HRESULT		hr;
					hr	= pStg->CreateStorage(
						towcs(wfd.cFileName),
						(STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE),
						0, 0, &pEnterStg);
					if (SUCCEEDED(hr)) {
						pStg->Commit(STGC_DEFAULT);
						Find(enter, level + 1, pEnterStg);
					} else {
						PrintError(GetLastError());
					}
				}
			} else {
				saveFile(pStg, basePath, wfd.cFileName);
			}
			b	= FindNextFile(h, &wfd);
		}
		FindClose(h);
	}
	pStg->Release();
}

int main(int argc, char* argv[])
{
	LPTSTR	startPos	= ".";

	if (argc > 1 && strstr(argv[1], "/?") != NULL) {
		fprintf(stderr, "makeSS [<init dir>]\n");
		return -1;
	}

	if (argc >= 2) startPos	= (LPTSTR)argv[1];

	fprintf(stderr, "startpos: %s\n", startPos);


	TCHAR		tempPath[MAX_PATH];

	GetTempPath(MAX_PATH, tempPath);
	lstrcat(tempPath, "makeSS");

	IStorage	*pStg	= NULL;
	HRESULT		hr;

	hr	= StgCreateDocfile(
		towcs(tempPath),
		(STGM_CREATE | STGM_READWRITE | STGM_TRANSACTED | STGM_SHARE_DENY_NONE),
		0, &pStg);
	if (SUCCEEDED(hr)) {
		Find(startPos, 0, pStg);
	} else {
		PrintError(GetLastError());
	}

	return 0;
}

/*

// Document::DocDataObject::GetData(
//		LPFORMATETC	pformatetcIn,
//		LPSTGMEDIUM	pmedium) {
STDMETHODIMP	GetData(
			LPFORMATETC	pformatetcIn,
			LPSTGMEDIUM	pmedium) {

	HRESULT		hErr	= NOERROR;

	pmedium->pUnkForRelease		= NULL;
	pmedium->tymed			= NULL;
	pmedium->hGlobal		= NULL;

	if (pformatetcIn->cfFormat == CF_METAFILEPICT) {
		if (pformatetcIn->dwAspect & (
			DVASPECT_CONTENT | DVASPECT_DOCPRINT)) {
			pmedium->tymed		= TYMED_MFPICT;
			pmedium->hGlobal	= ::CreateMetaFilePict(); //...
			if (pmedium->hGlobal == NULL) {
				hErr	= ResultFromScode(DATA_E_FORMATETC);
			}
		} else {
			hErr	= ResultFromScode(DATA_E_FORMATETC);
		}
	} else if (pformatetcIn->cfFormat == CF_BITMAP) {
		if (pformatetcIn->dwAspect & (
			DVASPECT_CONTENT | DVASPECT_DOCPRINT)) {
			pmedium->tymed		= TYMED_GDI;
			pmedium->hGlobal	= ::CreateBitmap(); //...
			if (pmedium->hGlobal == NULL) {
				hErr	= ResultFromScode(DATA_E_FORMATETC);
			}
		} else {
			hErr	= ResultFromScode(DATA_E_FORMATETC);
		}
	} else if (pformatetcIn->cfFormat ==
		RegisterClipboardFormat(CF_EMBEDSOURCE)) {
		pmedium->tymed		= TYMED_ISTORAGE;
		pmedium->pstg		= OleStdCreateStorageOnHGlobal(NULL, TRUE, STGM_SALL);
		if (pmedium->pstg != NULL) {
			hErr	= ::m_pStorage.Save(pmedium->pstg, FALSE);
		} else {
			hErr	= ResultFromScode(E_OUTOFMEMORY);
		}
	} else if (pformatetcIn->cfFormat ==
		RegisterClipboardFormat(CF_OBJECTDESCRIPTOR)) {
		SIZE		sizel;
		POINT		pointl;
		RECT		rect;

		::m_pDoc->GetMaximumRect(&rect);
		sizel.cx	= rect.right;
		sizel.cy	= rect.bottom;
		pointl.x	= 0;
		pointl.y	= 0;
		pmedium->tymed		= TYMED_HGLOBAL;
		pmedium->hGlobal	= OleStdGetObjectDescriptorData(
			CLSID_OleDraw,		// ...
			DVASPECT_CONTENT,
			sizel, pointl,
			0,
			"OLE Draw",
			NULL);
		if (pmedium->hGlobal == NULL) {
			hErr	= ResultFromScode(E_OUTOFMEMORY);
		}
	} else {
		hErr	= ResultFromScode(DATA_E_FORMATETC);
	}

	return hErr;
}

// ...
STDMETHODIMP	GetDataHere(
			    LPFORMATETC	pformatetc,
			    LPSTGMEDIUM	pmedium) {
	HRESULT		hErr;

	if (pformatetc->cfFormat == RegisterClipboardFormat(CF_EMBEDSOURCE)) {
		if (pmedium->pstg != NULL &&
			pmedium->tymed == TYMED_ISTORAGE) {
			hErr	= m_pDoc->m_pStorage.Save(pmedium->pstg, FALSE);
		} else {
			hErr	= ResultFromScode(E_UNEXPECTED);
		}
	} else {
		hErr	= ResultFromScode(DATA_E_FORMATETC);
	}

	return hErr;
}

STDMETHODIMP	QueryGetData(LPFORMATETC pformatetc) {
	if (!(
		pformatetc->cfFormat	== CF_METAFILEPICT ||
		pformatetc->cfFormat	== CF_BITMAP ||
		pformatetc->cfFormat	== RegisterClipboardFormat(CF_EMBEDSOURCE) ||
		pformatetc->cfFormat	== RegisterClipboardFormat(CF_OBJECTDESCRIPTOR)
		) {
		return ResultFromScode(DATA_E_FORMATETC);
	}

	return NOERROR;
}

STDMETHODIMP	GetCanonicalFormatEtc(
				      LPFORMATETC	pformatetc,
				      LPFORMATETC	pformatetcOut) {
	return ResultFromScode(DATA_S_SAMEFORMATETC);
}
// ...

*/