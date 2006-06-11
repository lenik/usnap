// Statement.h : Declaration of the CStatement

#ifndef __STATEMENT_H_
#define __STATEMENT_H_

#include "resource.h"       // main symbols

typedef std::vector<_variant_t> vars_t;

/////////////////////////////////////////////////////////////////////////////
// CStatement
class ATL_NO_VTABLE CStatement :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CStatement, &CLSID_Statement>,
    public IDispatchImpl<IStatement, &IID_IStatement, &LIBID_XnetCodec>
{

    vars_t m_Vars;

public:
    CStatement()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_STATEMENT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CStatement)
    COM_INTERFACE_ENTRY(IStatement)
    COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IStatement
public:
	STDMETHOD(Remove)(/*[in]*/int index);
    STDMETHOD(Encode)(/*[out, retval]*/ SAFEARRAY **pVal);
    STDMETHOD(get_Count)(/*[out, retval]*/ int *pVal);
    STDMETHOD(get_TypedItem)(/*[in]*/int index, /*[in]*/StatementItemTypeConstants type, /*[out, retval]*/VARIANT *ret);
    STDMETHOD(put_Item)(/*[in]*/int index, /*[in]*/VARIANT *newval);
    STDMETHOD(get_Item)(/*[in]*/int index, /*[out, retval]*/VARIANT *ret);
    STDMETHOD(Add)(/*[in]*/VARIANT *v);
    STDMETHOD(Add)(void *ps, int size);

};

typedef CComObject<CStatement> CStatementObject;

#endif //__STATEMENT_H_
