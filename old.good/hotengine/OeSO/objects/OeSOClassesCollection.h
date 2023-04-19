
#pragma once

// 类集合类
// CLSID: 00000000-4F45-0632-0002-486954656368
class OeSOClassesCollection :
	public CComObjectRoot,
	public CComCoClass<OeSOClassesCollection, &CLSID_OeSOClassesCollection>,
	public IOeSOCollectionImpl<IOeSOClassesCollection, &IID_IOeSOClassesCollection> {
public:
	OeSOClassesCollection();
	virtual ~OeSOClassesCollection();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

	STDMETHOD(get_member)(VARIANT whichmember, IOeSOClass **ret);

public:
	BEGIN_COM_MAP(OeSOClassesCollection)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOClassesCollection)
		COM_INTERFACE_ENTRY(IOeSOClassesCollection)
		COM_INTERFACE_ENTRY(IOeSOCollection)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOClassesCollection)
	DECLARE_NOT_AGGREGATABLE(OeSOClassesCollection)

public:
	_bstr_t			m_name;
};

typedef CComObject<OeSOClassesCollection>	COeSOClassesCollection;
