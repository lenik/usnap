
#pragma once

#include "HtmlViewerDialog.h"

class CaEDViewer :
	public CComObjectRoot,
	public CComCoClass<CaEDViewer, &CLSID_CaEDViewer>,
	public ICaEDViewer {
public:
	CaEDViewer();
	virtual ~CaEDViewer();

public:
	STDMETHOD(get_Html)(BSTR *ret);
	STDMETHOD(put_Html)(BSTR *htmlcode);
	STDMETHOD(DoModal)(int *ret);

public:
	BEGIN_COM_MAP(CaEDViewer)
		COM_INTERFACE_ENTRY(ICaEDViewer)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaEDViewer)
	DECLARE_NOT_AGGREGATABLE(CaEDViewer);

protected:
	CHtmlViewerDialog *m_dlgHtmlViewer;

};

typedef CaEDViewer	*PCAEDVIEWER, *LPCAEDVIEWER;
