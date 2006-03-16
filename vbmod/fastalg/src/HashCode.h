// HashCode.h : Declaration of the CHashCode

#ifndef __HASHCODE_H_
#define __HASHCODE_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHashCode
class ATL_NO_VTABLE CHashCode :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHashCode, &CLSID_HashCode>,
	public IDispatchImpl<IHashCode, &IID_IHashCode, &LIBID_FastAlgLib>
{
public:
	CHashCode()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HASHCODE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CHashCode)
	COM_INTERFACE_ENTRY(IHashCode)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IHashCode
public:
	STDMETHOD(hcVariant)(/*[in]*/VARIANT *var, /*[out, retval]*/long *result);
};

#endif //__HASHCODE_H_
