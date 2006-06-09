// InputBuffer.h : Declaration of the CInputBuffer

#ifndef __INPUTBUFFER_H_
#define __INPUTBUFFER_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CInputBuffer
class ATL_NO_VTABLE CInputBuffer :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CInputBuffer, &CLSID_InputBuffer>,
    public IDispatchImpl<IInputBuffer, &IID_IInputBuffer, &LIBID_XnetCodec>
{

    ByteArrayInput m_Buf;

public:
    CInputBuffer()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_INPUTBUFFER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CInputBuffer)
    COM_INTERFACE_ENTRY(IInputBuffer)
    COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IInputBuffer
public:
    STDMETHOD(GetStatement)(/*[out, retval]*/IStatement **ppStatement);
    STDMETHOD(StatementReady)(/*[out, retval]*/VARIANT_BOOL *ret);
    STDMETHOD(AddBytes)(/*[in]*/SAFEARRAY *bytes);
};

#endif //__INPUTBUFFER_H_
