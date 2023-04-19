
#pragma once

// 属性集合类
// CLSID: 00000000-4F45-0640-0002-486954656368
class OeSOAttributesCollection :
	public CComObjectRoot,
	public CComCoClass<OeSOAttributesCollection, &CLSID_OeSOAttributesCollection>,
	public IOeSOCollectionImpl<IOeSOAttributesCollection, &IID_IOeSOAttributesCollection> {
public:
	OeSOAttributesCollection();
	virtual ~OeSOAttributesCollection();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

	STDMETHOD(get_member)(VARIANT whichmember, IOeSOAttribute **ret);
	STDMETHOD(put_member)(VARIANT whichmember, IOeSOAttribute *newmember);

public:
	BEGIN_COM_MAP(OeSOAttributesCollection)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOAttributesCollection)
		COM_INTERFACE_ENTRY(IOeSOAttributesCollection)
		COM_INTERFACE_ENTRY(IOeSOCollection)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOAttributesCollection)
	DECLARE_NOT_AGGREGATABLE(OeSOAttributesCollection)

public:
	_bstr_t			m_name;
};

typedef CComObject<OeSOAttributesCollection>	COeSOAttributesCollection;
