
#pragma once

struct sss {
	IOeTChain	*prev;
	IOeTChain	*next;
	_variant_t	contents;
};

class OeTChain :
	public CComObjectRoot,
	public CComCoClass<OeTChain, &CLSID_OeTChain>,
	public IDispatchImpl<IOeTChain, &IID_IOeTChain> {
public:
	OeTChain();
	virtual ~OeTChain();

public:
	STDMETHOD(get_contents)(VARIANT *ret);
	STDMETHOD(put_contents)(VARIANT newcontents);

	STDMETHOD(get_lengthP)(int *ret);
	STDMETHOD(get_lengthN)(int *ret);

	STDMETHOD(get_scm)(VARIANT_BOOL *ret);
	STDMETHOD(put_scm)(VARIANT_BOOL newscm);

	STDMETHOD(get_useFixedType)(VARIANT_BOOL *ret);
	STDMETHOD(put_useFixedType)(VARIANT_BOOL newBOOL);

	STDMETHOD(get_fixedType)(VARENUM *ret);
	STDMETHOD(put_fixedType)(VARENUM newType);

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
	BEGIN_COM_MAP(OeTChain)
		COM_INTERFACE_ENTRY2(IDispatch, IOeTChain)
		COM_INTERFACE_ENTRY(IOeTChain)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeT0)
	DECLARE_NOT_AGGREGATABLE(OeTChain)

protected:
	sss			m_chain;

	BOOL			m_scm;
	BOOL			m_useFixedType;
	VARTYPE			m_fixedType;

};
