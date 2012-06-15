
#pragma once

class OeTSet :
	public CComObjectRoot,
	public CComCoClass<OeTSet, &CLSID_OeTSet>,
	public IDispatchImpl<IOeTSet, &IID_IOeTSet> {
public:
	OeTSet();
	virtual ~OeTSet();

public:
	STDMETHOD(get_elements)(IOeTArray **ret);
	STDMETHOD(put_elements)(IOeTArray *newelements);
	STDMETHOD(get_unis)(IOeTArray **ret);
	STDMETHOD(put_unis)(IOeTArray *newunis);
	STDMETHOD(get_contain)(VARIANT element, VARIANT_BOOL *ret);
	STDMETHOD(get_contains)(IOeTSet *another, VARIANT_BOOL *ret);

	STDMETHOD(comps)(IOeTSet **ret);
	STDMETHOD(ints)(IOeTSet *another, IOeTSet **ret);
	STDMETHOD(unions)(IOeTSet *another, IOeTSet **ret);
	STDMETHOD(xors)(IOeTSet *another, IOeTSet **ret);
	STDMETHOD(subs)(IOeTSet *another, IOeTSet **ret);
	STDMETHOD(remove)(VARIANT element, VARIANT_BOOL *ret);
	STDMETHOD(add)(VARIANT element, VARIANT_BOOL *ret);

public:
	BEGIN_COM_MAP(OeTSet)
		COM_INTERFACE_ENTRY2(IDispatch, IOeTSet)
		COM_INTERFACE_ENTRY(IOeTSet)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeT0)
	DECLARE_NOT_AGGREGATABLE(OeTSet)

protected:
	COeTArray *	m_universals;
	COeTArray *	m_elements;
};
