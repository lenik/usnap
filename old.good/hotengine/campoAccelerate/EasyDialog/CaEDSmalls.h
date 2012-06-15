
#pragma once

#include "PromptDialog.h"

class CaEDSmalls :
	public CComObjectRoot,
	public CComCoClass<CaEDSmalls, &CLSID_CaEDSmalls>,
	public ICaEDSmalls, public ICaEDViewer
	{
public:
	CaEDSmalls();
	virtual ~CaEDSmalls();

public:
	STDMETHOD(DoPrompt)(int *ret);

	STDMETHOD(get_Html)(BSTR *ret);
	STDMETHOD(put_Html)(BSTR *htmlcode);
	STDMETHOD(DoModal)(int *ret);

public:
	BEGIN_COM_MAP(CaEDSmalls)
		COM_INTERFACE_ENTRY(ICaEDSmalls)
		COM_INTERFACE_ENTRY(ICaEDViewer)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaEDSmalls)
	DECLARE_NOT_AGGREGATABLE(CaEDSmalls);

protected:

};

typedef CaEDSmalls	*PCAEDSMALLS, *LPCAEDSMALLS;
