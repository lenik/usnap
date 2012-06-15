
#pragma once

class OeTCodedStream :
	public CComObjectRoot,
	public CComCoClass<OeTCodedStream, &CLSID_OeTCodedStream>,
	public IDispatchImpl<IOeTCodedStream, &IID_IOeTCodedStream> {
public:
	OeTCodedStream();
	virtual ~OeTCodedStream();

public:
	STDMETHOD(get_contents)(BSTR *ret);
	STDMETHOD(put_contents)(BSTR newcontents);

	STDMETHOD(get_part)(VARIANT whichpart, BSTR *ret);
	STDMETHOD(put_part)(VARIANT whichpart, BSTR newpart);

	STDMETHOD(get_part_)(VARIANT whichpart, BSTR *ret);
	STDMETHOD(put_part_)(VARIANT whichpart, BSTR newpart_);

	STDMETHOD(get_parthcode)(BSTR *ret);
	STDMETHOD(put_parthcode)(BSTR newparthcode);

	STDMETHOD(get_partlcode)(BSTR *ret);
	STDMETHOD(put_partlcode)(BSTR newpartlcode);

public:
	BEGIN_COM_MAP(OeTCodedStream)
		COM_INTERFACE_ENTRY2(IDispatch, IOeTCodedStream)
		COM_INTERFACE_ENTRY(IOeTCodedStream)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeT2)
	DECLARE_NOT_AGGREGATABLE(OeTCodedStream)

protected:
	_bstr_vector_t	m_members;
	_bstr_t		m_parthcode;
	_bstr_t		m_partlcode;
};
