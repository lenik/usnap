// Base64.h : Declaration of the CBase64

#ifndef __BASE64_H_
#define __BASE64_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBase64
class ATL_NO_VTABLE CBase64 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CBase64, &CLSID_Base64>,
	public IDispatchImpl<IBase64, &IID_IBase64, &LIBID_BinariesLib>
{
public:
	CBase64()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_BASE64)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CBase64)
	COM_INTERFACE_ENTRY(IBase64)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IBase64
public:
	STDMETHOD(DecodeFile)(/*[in]*/BSTR base64, /*[in]*/BSTR outputFileName);
	STDMETHOD(EncodeFile)(/*[in]*/BSTR fileName, /*[out, retval]*/BSTR *ret);
	STDMETHOD(DecodeData)(/*[in]*/BSTR base64, /*[out, retval]*/VARIANT *data);
	STDMETHOD(EncodeData)(/*[in]*/VARIANT *data, /*[out]*/BSTR *ret);
	STDMETHOD(DecodeString)(/*[in]*/BSTR base64, /*[out, retval]*/BSTR *ret);
	STDMETHOD(EncodeString)(/*[in]*/BSTR string, /*[out, retval]*/BSTR *ret);
};

#endif //__BASE64_H_
