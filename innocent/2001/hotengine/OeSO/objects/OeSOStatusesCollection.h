
#pragma once

// ×´Ì¬¼¯ºÏÀà
// CLSID: 00000000-4F45-0633-0002-486954656368
class OeSOStatusesCollection :
	public CComObjectRoot,
	public CComCoClass<OeSOStatusesCollection, &CLSID_OeSOStatusesCollection>,
	public IOeSOCollectionImpl<IOeSOStatusesCollection, &IID_IOeSOStatusesCollection> {
public:
	OeSOStatusesCollection();
	virtual ~OeSOStatusesCollection();

public:
	STDMETHOD(get_name)(BSTR *ret);
	STDMETHOD(put_name)(BSTR newname);

public:
	BEGIN_COM_MAP(OeSOStatusesCollection)
		COM_INTERFACE_ENTRY2(IDispatch, IOeSOStatusesCollection)
		COM_INTERFACE_ENTRY(IOeSOStatusesCollection)
		COM_INTERFACE_ENTRY(IOeSOCollection)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeSOStatusesCollection)
	DECLARE_NOT_AGGREGATABLE(OeSOStatusesCollection)

public:
	_bstr_t			m_name;
};

typedef CComObject<OeSOStatusesCollection>	COeSOStatusesCollection;
