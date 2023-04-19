
#pragma once

// 属性类保存一个属性.
// CLSID: 00000000-4F45-0620-0002-486954656368
class OeSOAttribute :
	public CComObjectRoot,
	public CComCoClass<OeSOAttribute, &CLSID_OeSOAttribute>,
	public IDispatchImpl<IOeSOAttribute, &IID_IOeSOAttribute>,
	public IConnectionPointContainerImpl<OeSOAttribute>,
	public IConnectionPointImpl<OeSOAttribute, &DIID_IOeSOAttributeEvents> {
public:
	OeSOAttribute();
	virtual ~OeSOAttribute();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

	STDMETHOD(get_value)(VARIANT *ret);
	STDMETHOD(put_value)(VARIANT newvalue);

public:
	STDMETHOD_(void, Fire_onChanged)();

public:
	BEGIN_COM_MAP(OeSOAttribute)
		COM_INTERFACE_ENTRY(IOeSOAttribute)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOAttribute)
		COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(OeSOAttribute)
		CONNECTION_POINT_ENTRY(DIID_IOeSOAttributeEvents)
	END_CONNECTION_POINT_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOAttribute)
	DECLARE_NOT_AGGREGATABLE(OeSOAttribute)

public:
	_bstr_t		m_name;
	_variant_t	m_value;
};

typedef CComObject<OeSOAttribute>	COeSOAttribute;
