
#pragma once

class OeTStack :
	public CComObjectRoot,
	public CComCoClass<OeTStack, &CLSID_OeTStack>,
	public IDispatchImpl<IOeTStack, &IID_IOeTStack>,
	public IDispatchImpl<IOeTQueue, &IID_IOeTQueue>,
	public IDispatchImpl<IOeTChain, &IID_IOeTChain> {
public:
	OeTStack();
	virtual ~OeTStack();

// IOeTStack
public:
	STDMETHOD(push)(VARIANT data);
	STDMETHOD(pop)(VARIANT *ret);

	STDMETHOD(get_length)(int *ret);

	STDMETHOD(get_scm)(VARIANT_BOOL *ret);
	STDMETHOD(put_scm)(VARIANT_BOOL newscm);

	STDMETHOD(get_useFixedType)(VARIANT_BOOL *ret);
	STDMETHOD(put_useFixedType)(VARIANT_BOOL newBOOL);

	STDMETHOD(get_fixedType)(VARENUM *ret);
	STDMETHOD(put_fixedType)(VARENUM newType);

	STDMETHOD(destroy)();

// IOeTQueue
public:
	STDMETHOD(put_outputF)(VARIANT newnode);
	STDMETHOD(put_outputB)(VARIANT newnode);
	STDMETHOD(get_inputF)(VARIANT *ret);
	STDMETHOD(get_inputB)(VARIANT *ret);

	// STDMETHOD(get_length)(int *ret);

	STDMETHOD(get_lockInput)(VARIANT_BOOL *ret);
	STDMETHOD(put_lockInput)(VARIANT_BOOL newlock);

	// STDMETHOD(destroy)();

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

public:
	BEGIN_COM_MAP(OeTStack)
		COM_INTERFACE_ENTRY2(IDispatch, IOeTStack)
		COM_INTERFACE_ENTRY(IOeTStack)
		COM_INTERFACE_ENTRY(IOeTQueue)
		COM_INTERFACE_ENTRY(IOeTChain)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_OeT0)
	DECLARE_NOT_AGGREGATABLE(OeTStack)

protected:
	OeTQueue *	m_pqueue;
	OeTChain *	m_pchain;
};
