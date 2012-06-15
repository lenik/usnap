// c1.h : Declaration of the Cc1

#ifndef __C1_H_
#define __C1_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Cc1
class ATL_NO_VTABLE Cc1 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<Cc1, &CLSID_c1>,
	public IDispatchImpl<Ic1, &IID_Ic1, &LIBID_ATL1Lib>
{
public:
	Cc1()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_C1)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(Cc1)
	COM_INTERFACE_ENTRY(Ic1)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// Ic1
public:
	STDMETHOD(f1)();
};

#endif //__C1_H_
