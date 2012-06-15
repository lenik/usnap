// Call.h : Declaration of the CCall

#ifndef __CALL_H_
#define __CALL_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCall
class ATL_NO_VTABLE CCall :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCall, &CLSID_Call>,
	public IDispatchImpl<ICall, &IID_ICall, &LIBID_LowXRuntime>
{
public:
	CCall()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CALL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCall)
	COM_INTERFACE_ENTRY(ICall)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// ICall
public:
	STDMETHOD(Dispatch)(IDispatch *pObject, BSTR method, SAFEARRAY *pParams, VARIANT *pRetVal);
	STDMETHOD(Call0)(long pCallback, long *pRet);
	STDMETHOD(Call1)(long pCallback, long lParam1, long *pRet);
	STDMETHOD(Call2)(long pCallback, long lParam1, long lParam2, long *pRet);
	STDMETHOD(Call3)(long pCallback, long lParam1, long lParam2, long lParam3, long *pRet);
	STDMETHOD(Call4)(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long *pRet);
	STDMETHOD(Call5)(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long *pRet);
	STDMETHOD(Call6)(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long *pRet);
	STDMETHOD(Call7)(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long *pRet);
	STDMETHOD(Call8)(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long *pRet);
	STDMETHOD(Call9)(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long *pRet);
	STDMETHOD(Call10)(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long lParam10, long *pRet);
	STDMETHOD(Call11)(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long lParam10, long lParam11, long *pRet);
	STDMETHOD(Call12)(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long lParam10, long lParam11, long lParam12, long *pRet);
	STDMETHOD(Call13)(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long lParam10, long lParam11, long lParam12, long lParam13, long *pRet);
	STDMETHOD(Call14)(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long lParam10, long lParam11, long lParam12, long lParam13, long lParam14, long *pRet);
	STDMETHOD(Call15)(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long lParam10, long lParam11, long lParam12, long lParam13, long lParam14, long lParam15, long *pRet);
	STDMETHOD(Call16)(long pCallback, long lParam1, long lParam2, long lParam3, long lParam4, long lParam5, long lParam6, long lParam7, long lParam8, long lParam9, long lParam10, long lParam11, long lParam12, long lParam13, long lParam14, long lParam15, long lParam16, long *pRet);

	STDMETHOD(Pascal)(long pCallback, long cParameters, long cExtraReleases, long pParameters, /*[out, retval]*/long *pRet);
	STDMETHOD(C)(long pCallback, long cParameters, long cExtraReleases, long pParameters, /*[out, retval]*/long *pRet);
	STDMETHOD(ThisPascal)(long pCallback, long pThis, long cParameters, long cExtraReleases, long pParameters, /*[out, retval]*/long *pRet);
	STDMETHOD(ThisC)(long pCallback, long pThis, long cParameters, long cExtraReleases, long pParameters, /*[out, retval]*/long *pRet);
};

#endif //__CALL_H_
