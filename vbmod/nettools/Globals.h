// Globals.h : Declaration of the CGlobals

#ifndef __GLOBALS_H_
#define __GLOBALS_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGlobals
class ATL_NO_VTABLE CGlobals :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CGlobals, &CLSID_Globals>,
	public IDispatchImpl<IGlobals, &IID_IGlobals, &LIBID_NetToolsLib>
{
public:
	CGlobals()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_GLOBALS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CGlobals)
	COM_INTERFACE_ENTRY(IGlobals)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IGlobals
public:
	STDMETHOD(CreateRemoteFSO)(/*[in]*/BSTR Server, /*[in]*/int Port, /*[out, retval]*/IFileSystem **FSO);
};

#endif //__GLOBALS_H_
