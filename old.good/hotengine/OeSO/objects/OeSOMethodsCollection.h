
#pragma once

// 方法集合类
// CLSID: 00000000-4F45-0641-0002-486954656368
class OeSOMethodsCollection :
	public CComObjectRoot,
	public CComCoClass<OeSOMethodsCollection, &CLSID_OeSOMethodsCollection>,
	public IOeSOCollectionImpl<IOeSOMethodsCollection, &IID_IOeSOMethodsCollection> {
public:
	OeSOMethodsCollection();
	virtual ~OeSOMethodsCollection();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

	STDMETHOD(get_member)(VARIANT whichmember, IOeSOMethod **ret);

public:
	BEGIN_COM_MAP(OeSOMethodsCollection)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOMethodsCollection)
		COM_INTERFACE_ENTRY(IOeSOMethodsCollection)
		COM_INTERFACE_ENTRY(IOeSOCollection)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOMethodsCollection)
	DECLARE_NOT_AGGREGATABLE(OeSOMethodsCollection)

public:
	_bstr_t			m_name;
};

typedef CComObject<OeSOMethodsCollection>	COeSOMethodsCollection;
