
#include "StdAfx.h"

#include "resource.h"

#include "EasyDialog.h"
#include "CaEDViewer.h"

CaEDViewer::CaEDViewer() : m_dlgHtmlViewer(NULL) {}

CaEDViewer::~CaEDViewer() {}

STDMETHODIMP
CaEDViewer::get_Html(BSTR *ret) {
	return NOERROR;
}

STDMETHODIMP
CaEDViewer::put_Html(BSTR *ret) {
	return NOERROR;
}

STDMETHODIMP
CaEDViewer::DoModal(int *ret) {
	//m_dlgHtmlViewer = new CHtmlViewerDialog;
	CHtmlViewerDialog htmldlg;
	*ret = htmldlg.DoModal();
	return NOERROR;
}
