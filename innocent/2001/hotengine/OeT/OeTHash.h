
#pragma once

class OeTHash :
	public CComObjectRoot,
	public CComCoClass<OeTHash, &CLSID_OeTHash>,
	public IDispatchImpl<IOeTHash, &IID_IOeTHash> {
public:
	OeTHash();
	virtual ~OeTHash();

public:
	STDMETHOD(get_value)(VARIANT key, BSTR *ret);
	STDMETHOD(put_value)(VARIANT key, BSTR value);

	STDMETHOD(get_key)(VARIANT key, BSTR *ret);
	STDMETHOD(put_key)(VARIANT key, BSTR newkey);

	STDMETHOD(get_count)(int *ret);

	STDMETHOD(get_def)(BSTR *ret);
	STDMETHOD(put_def)(BSTR newdef);

	STDMETHOD(get_coded)(VARIANT key, BSTR *ret);

	STDMETHOD(clear)();
	STDMETHOD(set)(BSTR setstring, BSTR sep);
	STDMETHOD(search)(BSTR value, BSTR *ret);
	STDMETHOD(interprete)(BSTR text, BSTR prefix, BSTR *ret);

public:
	BEGIN_COM_MAP(OeTHash)
		COM_INTERFACE_ENTRY2(IDispatch, IOeTHash)
		COM_INTERFACE_ENTRY(IOeTHash)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeT0)
	DECLARE_NOT_AGGREGATABLE(OeTHash)

protected:
	_hash_bstr_vector_t	m_members;
	_bstr_t			m_default;
};
