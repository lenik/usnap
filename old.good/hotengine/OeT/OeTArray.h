
#pragma once

class OeTArray :
	public CComObjectRoot,
	public CComCoClass<OeTArray, &CLSID_OeTArray>,
	public IDispatchImpl<IOeTArray, &IID_IOeTArray>,
	public IDispatchImpl<IOeTChain, &IID_IOeTChain> {
public:
	OeTArray();
	virtual ~OeTArray();

// IOeTArray
public:
	STDMETHOD(get_member)(int index, VARIANT *ret);
	STDMETHOD(put_member)(int index, VARIANT newVARIANT);

	STDMETHOD(get_count)(int *ret);

	STDMETHOD(get_scm)(VARIANT_BOOL *ret);
	STDMETHOD(put_scm)(VARIANT_BOOL newscm);

	STDMETHOD(get_useFixedType)(VARIANT_BOOL *ret);
	STDMETHOD(put_useFixedType)(VARIANT_BOOL newbool);

	STDMETHOD(get_fixedType)(VARENUM *ret);
	STDMETHOD(put_fixedType)(VARENUM newfixedtype);

	STDMETHOD(add)(VARIANT newVARIANT, int insertindex, int insertduplicates);
	STDMETHOD(remove)(int removeindex, int removecount, int *ret_removedcount);
	STDMETHOD(clear)();

// IOeTArrayEvents
public:

// IOeTChain
public:
	STDMETHOD(get_contents)(VARIANT *ret);
	STDMETHOD(put_contents)(VARIANT newcontents);

	STDMETHOD(get_lengthP)(int *ret);
	STDMETHOD(get_lengthN)(int *ret);

	STDMETHOD(get_p)(IOeTChain **ret);
	STDMETHOD(put_p)(IOeTChain *newprev);

	STDMETHOD(get_n)(IOeTChain **ret);
	STDMETHOD(put_n)(IOeTChain *newnext);

	STDMETHOD(get_begin)(IOeTChain **ret);

	STDMETHOD(get_end)(IOeTChain **ret);

	STDMETHOD(find)(VARIANT node, IOeTChain **ret);
	STDMETHOD(next)(IOeTChain **ret);

	STDMETHOD(swapBefore)();
	STDMETHOD(swapAfter)();

	STDMETHOD(remove)();
	STDMETHOD(insert)(VARIANT newnode);
	STDMETHOD(append)(VARIANT newnode);

	STDMETHOD(removeChain)(IOeTChain *first, IOeTChain *last);
	STDMETHOD(insertChain)(IOeTChain *chain);
	STDMETHOD(appendChain)(IOeTChain *chain);

	STDMETHOD(destroy)();

public:
	BEGIN_COM_MAP(OeTArray)
		COM_INTERFACE_ENTRY2(IDispatch, IOeTArray)
		COM_INTERFACE_ENTRY(IOeTArray)
		COM_INTERFACE_ENTRY(IOeTChain)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeT0)
	DECLARE_NOT_AGGREGATABLE(OeTArray)

protected:
	_variant_vector_t	m_members;
	BOOL			m_scm;
	BOOL			m_useFixedType;
	VARTYPE			m_fixedType;

	// working...
	OeTChain *		m_pchain;
};
