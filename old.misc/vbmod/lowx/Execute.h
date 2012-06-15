// Execute.h : Declaration of the CExecute

#ifndef __EXECUTE_H_
#define __EXECUTE_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExecute
class ATL_NO_VTABLE CExecute :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CExecute, &CLSID_Execute>,
	public IDispatchImpl<IExecute, &IID_IExecute, &LIBID_LowXRuntime>
{
public:
	CExecute()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_EXECUTE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CExecute)
	COM_INTERFACE_ENTRY(IExecute)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IExecute
public:
	STDMETHOD(get_Version)(/*[out, retval]*/ long *pVal);
};

#endif //__EXECUTE_H_
