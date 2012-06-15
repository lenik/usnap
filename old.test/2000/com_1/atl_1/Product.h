// Product.h : Declaration of the CProduct

#ifndef __PRODUCT_H_
#define __PRODUCT_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CProduct
class ATL_NO_VTABLE CProduct :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CProduct, &CLSID_Product>,
	public IDispatchImpl<IProduct, &IID_IProduct, &LIBID_ATL01Lib>
{
public:
	CProduct()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PRODUCT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CProduct)
	COM_INTERFACE_ENTRY(IProduct)
	COM_INTERFACE_ENTRY(IProduct2)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IProduct
public:
};

#endif //__PRODUCT_H_
