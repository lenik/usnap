// Iterator.h : Declaration of the CIterator

#ifndef __ITERATOR_H_
#define __ITERATOR_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CIterator

class IteratorImpl {
public:
    virtual HRESULT hasNext(VARIANT_BOOL *result) = 0;
    virtual HRESULT fetch(VARIANT *v) = 0;
    virtual HRESULT remove() = 0;
};

class ATL_NO_VTABLE CIterator :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CIterator, &CLSID_Iterator>,
	public IDispatchImpl<IIterator, &IID_IIterator, &LIBID_BasTypeLib>
{
    IteratorImpl *m_Impl;
public:
    CIterator() { m_Impl = NULL; }
    ~CIterator() { if (m_Impl) delete m_Impl; }

    void setImpl(IteratorImpl *impl) { m_Impl = impl; }

DECLARE_REGISTRY_RESOURCEID(IDR_ITERATOR)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CIterator)
	COM_INTERFACE_ENTRY(IIterator)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IIterator
public:
	STDMETHOD(remove)();
	STDMETHOD(fetch)(/*[out, retval]*/VARIANT *result);
	STDMETHOD(hasNext)(/*[out, retval]*/VARIANT_BOOL *result);
};

typedef CComObject<CIterator> CIteratorObject;

#endif //__ITERATOR_H_
