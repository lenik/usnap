// Ut1.h : Declaration of the CUt1

#ifndef __UT1_H_
#define __UT1_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CUt1
class ATL_NO_VTABLE CUt1 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CUt1, &CLSID_Ut1>,
	public IDispatchImpl<IUt1, &IID_IUt1, &LIBID_UtLib_Files>
{
public:
	CUt1()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_UT1)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CUt1)
	COM_INTERFACE_ENTRY(IUt1)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IUt1
public:
	STDMETHOD(GetDragFileNamesCount)(/*[in]*/IDataObject *pData, /*[out,retval]*/int *pVal);
	STDMETHOD(GetDragFileNames)(/*[in]*/IDataObject *pData, /*[in]*/int Index, /*[out,retval]*/BSTR *pName);
};

#endif //__UT1_H_
