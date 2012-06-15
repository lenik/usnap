
#pragma once

#include "EventByrefCP.h"

class CaEventByref:
	public CComObjectRoot,
	public CComCoClass<CaEventByref, &CLSID_CaEventByref>,
	public IDispatchImpl<ICaEventByref, &IID_ICaEventByref>,
	public CProxyICaEventByrefEvents< CaEventByref >,
	public IConnectionPointContainerImpl<CaEventByref>
{
public:
	CaEventByref();
	virtual ~CaEventByref();

public:
	STDMETHOD(get_prop1)(long *ret);
	STDMETHOD(put_prop1)(long newval);
	STDMETHOD(makeEventTest)();
	STDMETHOD(makeEvent1)();
	STDMETHOD(makeEvent2)();

public:
	BEGIN_COM_MAP(CaEventByref)
		COM_INTERFACE_ENTRY(ICaEventByref)
		COM_INTERFACE_ENTRY2(IDispatch, ICaEventByref)
		COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CaEventByref)
		CONNECTION_POINT_ENTRY(DIID_ICaEventByrefEvents)
	END_CONNECTION_POINT_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaEventByref)
	DECLARE_NOT_AGGREGATABLE(CaEventByref)

protected:
	long	m_prop1;

};
