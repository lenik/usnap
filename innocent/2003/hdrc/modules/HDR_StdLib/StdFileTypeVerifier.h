// StdFileTypeVerifier.h : Declaration of the CStdFileTypeVerifier

#ifndef __StdFileTypeVerifier_H_
#define __StdFileTypeVerifier_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStdFileTypeVerifier
class ATL_NO_VTABLE CStdFileTypeVerifier :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CStdFileTypeVerifier, &CLSID_StdFileTypeVerifier>,
	public IDispatchImpl<IFileTypeVerifier, &IID_IFileTypeVerifier, &LIBID_HDR_StdLib>
{
public:
	CStdFileTypeVerifier()
	{
	}


DECLARE_REGISTRY_RESOURCEID(IDR_STDFILETYPEVERIFIER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CStdFileTypeVerifier)
	COM_INTERFACE_ENTRY(IFileTypeVerifier)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IFileTypeVerifier
public:
	STDMETHOD(get_Extension)(/*[in]*/long Index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_ExtensionsCount)(/*[out, retval]*/ long *pVal);
};

#endif //__StdFileTypeVerifier_H_
