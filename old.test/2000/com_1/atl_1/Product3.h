// Product3.h : Declaration of the CProduct3

#ifndef __PRODUCT3_H_
#define __PRODUCT3_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CProduct3
class ATL_NO_VTABLE CProduct3 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CProduct3, &CLSID_Product2>,
	public IDispatchImpl<IProduct3, &IID_IProduct3, &LIBID_ATL01Lib>
{
public:
	CProduct3()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PRODUCT3)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CProduct3)
	COM_INTERFACE_ENTRY(IProduct3)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IProduct3
public:
};

#endif //__PRODUCT3_H_
