// InputBuffer.h : Declaration of the CInputBuffer

#ifndef __INPUTBUFFER_H_
#define __INPUTBUFFER_H_

#include "resource.h"       // main symbols

#include "Statement.h"

#include "array.h"
#include "kernel.h"

/////////////////////////////////////////////////////////////////////////////
// CInputBuffer
class ATL_NO_VTABLE CInputBuffer :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CInputBuffer, &CLSID_InputBuffer>,
    public IDispatchImpl<IInputBuffer, &IID_IInputBuffer, &LIBID_XnetCodec>
{

    ByteArrayInput m_Buf;
    Decoder *nextParam;
    CStatementObject *nextStmt;
    int stmt_ok;

public:
    CInputBuffer()
    {
        nextParam = 0;
        nextStmt = 0;
        stmt_ok = 0;
    }

    ~CInputBuffer() {
        if (nextParam)
            delete nextParam;
        if (nextStmt)
            delete nextStmt;
    }

DECLARE_REGISTRY_RESOURCEID(IDR_INPUTBUFFER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CInputBuffer)
    COM_INTERFACE_ENTRY(IInputBuffer)
    COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IInputBuffer
public:
    STDMETHOD(get_UnreadSize)(/*[out, retval]*/ long *pVal);
    STDMETHOD(get_UsedSize)(/*[out, retval]*/ long *pVal);
    STDMETHOD(get_AllocatedSize)(/*[out, retval]*/ long *pVal);
    STDMETHOD(GetStatement)(/*[out, retval]*/IStatement **ppStatement);
    STDMETHOD(StatementReady)(/*[out, retval]*/VARIANT_BOOL *ret);
    STDMETHOD(AddBytes)(/*[in]*/SAFEARRAY **bytes);
};

#endif //__INPUTBUFFER_H_
