
#pragma once

// 对象集合类
// CLSID: 00000000-4F45-0630-0002-486954656368
class OeSOObjectsCollection :
	public CComObjectRoot,
	public CComCoClass<OeSOObjectsCollection, &CLSID_OeSOObjectsCollection>,
	public IOeSOCollectionImpl<IOeSOObjectsCollection, &IID_IOeSOObjectsCollection> {
public:
	OeSOObjectsCollection();
	virtual ~OeSOObjectsCollection();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

	STDMETHOD(get_member)(VARIANT whichmember, IOeSOObject **ret);

public:
	BEGIN_COM_MAP(OeSOObjectsCollection)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOObjectsCollection)
		COM_INTERFACE_ENTRY(IOeSOObjectsCollection)
		COM_INTERFACE_ENTRY(IOeSOCollection)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOObjectsCollection)
	DECLARE_NOT_AGGREGATABLE(OeSOObjectsCollection)

public:
	_bstr_t			m_name;
};

typedef CComObject<OeSOObjectsCollection>	COeSOObjectsCollection;
