// Stringizable.h : Declaration of the CStringizable

#ifndef __STRINGIZABLE_H_
#define __STRINGIZABLE_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStringizable
class ATL_NO_VTABLE CStringizable :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CStringizable, &CLSID_Stringizable>,
	public IDispatchImpl<IStringizable, &IID_IStringizable, &LIBID_BasTypeLib>
{
public:
	CStringizable()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STRINGIZABLE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CStringizable)
	COM_INTERFACE_ENTRY(IStringizable)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IStringizable
public:
};

#endif //__STRINGIZABLE_H_
