// Product2.h : Declaration of the CProduct2

#ifndef __PRODUCT2_H_
#define __PRODUCT2_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CProduct2
class ATL_NO_VTABLE CProduct2 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CProduct2, &CLSID_Product2>,
	public IDispatchImpl<IProduct2, &IID_IProduct2, &LIBID_ATL01Lib>
{
public:
	CProduct2()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PRODUCT2)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CProduct2)
	COM_INTERFACE_ENTRY(IProduct2)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IProduct2
public:
};

#endif //__PRODUCT2_H_
