
#pragma once

// 事件类用于建立事件映射。
// CLSID: 00000000-4F45-0622-0002-486954656368
class OeSOEvent :
	public CComObjectRoot,
	public CComCoClass<OeSOEvent, &CLSID_OeSOEvent>,
	public IDispatchImpl<IOeSOEvent, &IID_IOeSOEvent> {
public:
	OeSOEvent();
	virtual ~OeSOEvent();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

public:
	BEGIN_COM_MAP(OeSOEvent)
		COM_INTERFACE_ENTRY(IOeSOEvent)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOEvent)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOEvent)
	DECLARE_NOT_AGGREGATABLE(OeSOEvent)

public:
	_bstr_t		m_name;
};

typedef CComObject<OeSOEvent>	COeSOEvent;
