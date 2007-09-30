// String.h : Declaration of the CString

#ifndef __STRING_H_
#define __STRING_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CString
class ATL_NO_VTABLE CString :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CString, &CLSID_String>,
	public IDispatchImpl<IString, &IID_IString, &LIBID_LowXRuntime>
{
public:
	CString()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STRING)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CString)
	COM_INTERFACE_ENTRY(IString)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IString
public:
	STDMETHOD(get_TestValid)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_TestValid)(/*[in]*/ VARIANT_BOOL newVal);
	BOOL m_bTestValid;
	STDMETHOD(LenM)(long pStr, /*[out, retval]*/long *pRet);
	STDMETHOD(LenW)(long pStr, /*[out, retval]*/long *pRet);
	STDMETHOD(LenA)(long pStr, /*[out, retval]*/long *pRet);
};

#endif //__STRING_H_
