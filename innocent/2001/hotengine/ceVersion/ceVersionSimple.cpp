
#include "StdAfx.h"

#include "resource.h"

#include "ceVersion.h"
#include "ceVersionSimple.h"

CeVersionSimple::CeVersionSimple() {}
CeVersionSimple::~CeVersionSimple() {}

STDMETHODIMP	CeVersionSimple::AboutBox() {
	MessageBox(NULL, _T("CeVersionSimple::AboutBox()"), _T("ceVersion"), MB_OK);
	return NOERROR;
}

STDMETHODIMP	CeVersionSimple::GetCurrentVersion(LONG *pVer) {
	*pVer	= 0x00010000;
	return NOERROR;
}
