
#pragma once

class OeTString :
	public CComObjectRoot,
	public CComCoClass<OeTString, &CLSID_OeTString>,
	public IDispatchImpl<IOeTString, &IID_IOeTString> {
public:
	OeTString();
	virtual ~OeTString();

public:
	STDMETHOD(get_contents)(BSTR *ret);
	STDMETHOD(put_contents)(BSTR newcontents);

	STDMETHOD(get_c)(int index, LONG *ret);
	STDMETHOD(put_c)(int index, LONG newc);

	STDMETHOD(get_length)(int *ret);

public:
	BEGIN_COM_MAP(OeTString)
		COM_INTERFACE_ENTRY2(IDispatch, IOeTString)
		COM_INTERFACE_ENTRY(IOeTString)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeT0)
	DECLARE_NOT_AGGREGATABLE(OeTString)

protected:
	_bstr_t		m_contents;
};

typedef CComObject<OeTString>	COetString;
