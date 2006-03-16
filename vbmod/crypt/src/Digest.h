// Digest.h : Declaration of the CDigest

#ifndef __DIGEST_H_
#define __DIGEST_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDigest
class ATL_NO_VTABLE CDigest :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDigest, &CLSID_Digest>,
	public IDispatchImpl<IDigest, &IID_IDigest, &LIBID_CryptLib>
{
public:
	CDigest()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DIGEST)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDigest)
	COM_INTERFACE_ENTRY(IDigest)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IDigest
public:
	STDMETHOD(MD5_String)(/*[in]*/BSTR message, /*[out]*/long *a_msb, /*[out]*/long *b, /*[out]*/long *c, /*[out]*/long *d_lsb);
};

#endif //__DIGEST_H_
