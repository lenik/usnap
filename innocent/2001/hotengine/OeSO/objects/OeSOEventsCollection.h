
#pragma once

// 事件集合类
// CLSID: 00000000-4F45-0642-0002-486954656368
class OeSOEventsCollection :
	public CComObjectRoot,
	public CComCoClass<OeSOEventsCollection, &CLSID_OeSOEventsCollection>,
	public IOeSOCollectionImpl<IOeSOEventsCollection, &IID_IOeSOEventsCollection> {
public:
	OeSOEventsCollection();
	virtual ~OeSOEventsCollection();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

	STDMETHOD(get_member)(VARIANT whichmember, IOeSOEvent **ret);

public:
	BEGIN_COM_MAP(OeSOEventsCollection)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOEventsCollection)
		COM_INTERFACE_ENTRY(IOeSOEventsCollection)
		COM_INTERFACE_ENTRY(IOeSOCollection)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOEventsCollection)
	DECLARE_NOT_AGGREGATABLE(OeSOEventsCollection)

public:
	_bstr_t			m_name;
};

typedef CComObject<OeSOEventsCollection>	COeSOEventsCollection;
