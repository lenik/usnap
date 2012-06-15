// DRIA.h : Declaration of the CDRIA

#ifndef __DRIA_H_
#define __DRIA_H_

#include "resource.h"       // main symbols
#include "kernel.h"

/////////////////////////////////////////////////////////////////////////////
// CDRIA
class ATL_NO_VTABLE CDRIA :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDRIA, &CLSID_DRIA>,
	public IDispatchImpl<IDRIA, &IID_IDRIA, &LIBID_FastAlgLib>
{
    dria m_dria;

public:
	CDRIA()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DRIA)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDRIA)
	COM_INTERFACE_ENTRY(IDRIA)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IDRIA
public:
	STDMETHOD(get_RangeUpper)(/*[in]*/int index, /*[out, retval]*/ long *pVal);
	STDMETHOD(get_RangeLower)(/*[in]*/int index, /*[out, retval]*/ long *pVal);
	STDMETHOD(get_Count)(/*[out, retval]*/ int *pVal);
	STDMETHOD(Remove)(/*[in]*/long x, /*[out, retval]*/BOOL *retval);
	STDMETHOD(Add)(/*[in]*/long x, /*[out, retval]*/BOOL *retval);
	STDMETHOD(RemoveRange)(/*[in]*/long lower, /*[in]*/long upper, /*[out, retval]*/BOOL *retval);
	STDMETHOD(AddRange)(/*[in]*/long lower, /*[in]*/long upper, /*[out, retval]*/BOOL *retval);
	STDMETHOD(Floor)(/*[in]*/long x, /*[out, retval]*/int *retval);
	STDMETHOD(Ceil)(/*[in]*/long x, /*[out, retval]*/int *retval);
	STDMETHOD(Clear)();
};

#endif //__DRIA_H_
