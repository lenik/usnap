// SAOT.h : Declaration of the CSAOT

#ifndef __SAOT_H_
#define __SAOT_H_

#include "resource.h"       // main symbols
#include "kernel.h"

/////////////////////////////////////////////////////////////////////////////
// CSAOT
class ATL_NO_VTABLE CSAOT :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSAOT, &CLSID_SAOT>,
	public IDispatchImpl<ISAOT, &IID_ISAOT, &LIBID_FastAlgLib>
{
    saot m_saot;
public:
	CSAOT()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SAOT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSAOT)
	COM_INTERFACE_ENTRY(ISAOT)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// ISAOT
public:
	STDMETHOD(Append)(/*[in]*/long count, /*[out, retval]*/long *result);
	STDMETHOD(SortSlots)(/*[out, retval]*/VARIANT *SortedSlots);
	STDMETHOD(FindIndex)(/*[in]*/long Index, /*[out, retval]*/long *result);
	STDMETHOD(FindSlot)(/*[in]*/long Slot, /*[out, retval]*/long *result);
	STDMETHOD(Remove)(/*[in]*/long Index, /*[out, retval]*/long *result);
	STDMETHOD(Insert)(/*[in]*/long Index, /*[out, retval]*/long *result);
	STDMETHOD(SlotClear)();
	STDMETHOD(SlotRemove)(/*[in]*/long slot);
	STDMETHOD(SlotAdd)(/*[out, retval]*/long *result);
	STDMETHOD(get_Size)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_SlotAllocated)(/*[out, retval]*/ long *pVal);
};

#endif //__SAOT_H_
