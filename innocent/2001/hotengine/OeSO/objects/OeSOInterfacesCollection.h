
#pragma once

// 接口集合类
// CLSID: 00000000-4F45-0631-0002-486954656368
class OeSOInterfacesCollection :
	public CComObjectRoot,
	public CComCoClass<OeSOInterfacesCollection, &CLSID_OeSOInterfacesCollection>,
	public IOeSOCollectionImpl<IOeSOInterfacesCollection, &IID_IOeSOInterfacesCollection> {
public:
	OeSOInterfacesCollection();
	virtual ~OeSOInterfacesCollection();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

	STDMETHOD(get_member)(VARIANT whichmember, IOeSOInterface **ret);

public:
	BEGIN_COM_MAP(OeSOInterfacesCollection)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOInterfacesCollection)
		COM_INTERFACE_ENTRY(IOeSOInterfacesCollection)
		COM_INTERFACE_ENTRY(IOeSOCollection)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOInterfacesCollection)
	DECLARE_NOT_AGGREGATABLE(OeSOInterfacesCollection)

public:
	_bstr_t			m_name;
};
