// Base64.h : Declaration of the CBase64

#ifndef __BASE64_H_
#define __BASE64_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBase64
class ATL_NO_VTABLE CBase64 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CBase64, &CLSID_Base64>,
	public IDispatchImpl<IBase64, &IID_IBase64, &LIBID_BinaryLib>
{
    char *m_Raw;
    DWORD m_RawSize;
    BSTR m_Base64;
public:
	CBase64()
	{
        m_Raw = NULL;
        m_Base64 = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_BASE64)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CBase64)
	COM_INTERFACE_ENTRY(IBase64)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
    void clear();

// IBase64
public:
	STDMETHOD(GetString)(/*[in, optional("gb2312")]*/BSTR encoding, /*[out, retval]*/BSTR *string);
	STDMETHOD(GetStringB)(/*[out, retval]*/BSTR *stringB);
	STDMETHOD(GetBase64)(/*[out, retval]*/BSTR *base64);
	STDMETHOD(SetString)(/*[in]*/BSTR stringUnicode, /*[in, optional("gb2312")]*/BSTR encoding);
	STDMETHOD(SetStringB)(/*[in]*/BSTR string);
};

#endif //__BASE64_H_
