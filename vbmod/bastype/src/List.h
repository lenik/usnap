// List.h : Declaration of the CList

#ifndef __LIST_H_
#define __LIST_H_

#include "resource.h"       // main symbols

#include <list>
typedef std::list<VARIANT> VARIANTS;

/////////////////////////////////////////////////////////////////////////////
// CList
class ATL_NO_VTABLE CList :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CList, &CLSID_List>,
	public IDispatchImpl<IList, &IID_IList, &LIBID_BasTypeLib>
{
    VARIANTS m_vars;

public:
	CList();
    ~CList();

DECLARE_REGISTRY_RESOURCEID(IDR_LIST)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CList)
	COM_INTERFACE_ENTRY(IList)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IList
public:
	STDMETHOD(shift)(/*[out, retval]*/VARIANT *var);
	STDMETHOD(unshift)(/*[in]*/VARIANT *var);
	STDMETHOD(pop)(/*[out, retval]*/VARIANT *var);
	STDMETHOD(push)(/*[in]*/VARIANT *var);
	STDMETHOD(get_size)(/*[out, retval]*/ long *pVal);
};

#endif //__LIST_H_
