
#include "StdAfx.h"

#include "resource.h"

#include "EasyDialog.h"
#include "CaEDSmalls.h"

CaEDSmalls::CaEDSmalls() {
	MessageBox(NULL, "DDD", "DDD", MB_OK);
}

CaEDSmalls::~CaEDSmalls() {}

STDMETHODIMP
CaEDSmalls::DoPrompt(int *ret) {
	//m_dlgHtmlViewer = new CHtmlViewerDialog;
	//CHtmlViewerDialog htmldlg;
	CPromptDialog promptdlg;
	*ret = promptdlg.DoModal();
	return NOERROR;
}

STDMETHODIMP
CaEDSmalls::get_Html(BSTR *ret) {
	return NOERROR;
}

STDMETHODIMP
CaEDSmalls::put_Html(BSTR *ret) {
	return NOERROR;
}

STDMETHODIMP
CaEDSmalls::DoModal(int *ret) {
	return NOERROR;
}
