// Memory.h : Declaration of the CMemory

#ifndef __MEMORY_H_
#define __MEMORY_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMemory
class ATL_NO_VTABLE CMemory :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMemory, &CLSID_Memory>,
	public IDispatchImpl<IMemory, &IID_IMemory, &LIBID_LowXRuntime>
{
public:
	CMemory()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MEMORY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CMemory)
	COM_INTERFACE_ENTRY(IMemory)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IMemory
public:
	STDMETHOD(get_TestValid)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_TestValid)(/*[in]*/ VARIANT_BOOL newVal);
	BOOL m_bTestValid;
	STDMETHOD(CopyBytes)(long pDest, long pSrc, long cBytes);
};

#endif //__MEMORY_H_
