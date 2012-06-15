// Vector.h : Declaration of the CVector

#ifndef __VECTOR_H_
#define __VECTOR_H_

#include "resource.h"       // main symbols

#include <vector>
typedef std::vector<VARIANT> varvec;

/////////////////////////////////////////////////////////////////////////////
// CVector
class ATL_NO_VTABLE CVector :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CVector, &CLSID_Vector>,
	public IDispatchImpl<IVector, &IID_IVector, &LIBID_BasTypeLib>
{
    varvec m_vars;
public:
	CVector();
    ~CVector();

DECLARE_REGISTRY_RESOURCEID(IDR_VECTOR)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CVector)
	COM_INTERFACE_ENTRY(IVector)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IVector
public:
	STDMETHOD(remove)(/*[in]*/long index);
	STDMETHOD(insert)(/*[in]*/long index, /*[in]*/VARIANT *var);
	STDMETHOD(get_item)(/*[in]*/long index, /*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_item)(/*[in]*/long index, /*[in]*/ VARIANT *newVal);
	STDMETHOD(iterator)(/*[out, retval]*/IIterator **result);
	STDMETHOD(shift)(/*[out, retval]*/VARIANT *var);
	STDMETHOD(unshift)(/*[in]*/VARIANT *var);
	STDMETHOD(pop)(/*[out, retval]*/VARIANT *var);
	STDMETHOD(push)(/*[in]*/VARIANT *var);
	STDMETHOD(get_size)(/*[out, retval]*/ long *pVal);
};

#endif //__VECTOR_H_
