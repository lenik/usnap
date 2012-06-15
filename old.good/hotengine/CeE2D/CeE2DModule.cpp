
#include "StdAfx.h"

#include "resource.h"

#include "CeE2D.h"
#include "CeE2DModule.h"

#include "CeE2DBase.h"

HRESULT _stdcall CreateCeE2D(HWND hMainWnd, ICeE2DBase **ret) {
	ICeE2DBase	*pbase;
	HRESULT hr;

	pbase	= new CCeE2DBase;
	pbase->AddRef();

	hr = ((CeE2DBase *)pbase)->init(hMainWnd);
	if (FAILED(hr)) {
		pbase->Release();
		return hr;
	}

	*ret	= pbase;
	return NOERROR;
}
