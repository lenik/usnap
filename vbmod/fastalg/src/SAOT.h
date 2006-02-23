// SAOT.h : Declaration of the CSAOT

#ifndef __SAOT_H_
#define __SAOT_H_

#include "resource.h"       // main symbols
#include "kernel.h"
#include "fastalgCP.h"

/////////////////////////////////////////////////////////////////////////////
// CSAOT
class ATL_NO_VTABLE CSAOT :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSAOT, &CLSID_SAOT>,
	public IDispatchImpl<ISAOT, &IID_ISAOT, &LIBID_FastAlgLib>,
	public CProxy_ISAOTEvents< CSAOT >,
	public IConnectionPointContainerImpl<CSAOT>
{
    SAOTEventMaskConstants m_mask;
    saot m_saot;
public:
	CSAOT()
	{
        m_mask = (SAOTEventMaskConstants)-1;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SAOT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSAOT)
	COM_INTERFACE_ENTRY(ISAOT)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CSAOT)
	CONNECTION_POINT_ENTRY(DIID__ISAOTEvents)
END_CONNECTION_POINT_MAP()

// ISAOT
public:
	STDMETHOD(get_EventMask)(/*[out, retval]*/ SAOTEventMaskConstants *pVal);
	STDMETHOD(put_EventMask)(/*[in]*/ SAOTEventMaskConstants newVal);
	STDMETHOD(Append)(/*[in]*/long count, /*[out, retval]*/long *result);
	STDMETHOD(SortSlots)(/*[out, retval]*/VARIANT *SortedSlots);
	STDMETHOD(FindIndex)(/*[in]*/long Index, /*[out, retval]*/long *result);
	STDMETHOD(FindSlot)(/*[in]*/long Slot, /*[out, retval]*/long *result);
	STDMETHOD(Remove)(/*[in]*/long Index, /*[out, retval]*/long *result);
	STDMETHOD(Insert)(/*[in]*/long Index, /*[out, retval]*/long *result);
	STDMETHOD(Clear)();
	STDMETHOD(SlotRemove)(/*[in]*/long slot);
	STDMETHOD(SlotAdd)(/*[out, retval]*/long *result);
	STDMETHOD(get_Size)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_SlotAllocated)(/*[out, retval]*/ long *pVal);
};

#endif //__SAOT_H_
