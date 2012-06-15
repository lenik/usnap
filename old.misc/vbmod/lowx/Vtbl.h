// Vtbl.h : Declaration of the CVtbl

#ifndef __VTBL_H_
#define __VTBL_H_

#include "resource.h"       // main symbols

#define _HIWORD(x) ((x) >> 16)
#define _LOWORD(x) ((x) & 0xFFFF)

/////////////////////////////////////////////////////////////////////////////
// CVtbl
class ATL_NO_VTABLE CVtbl :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CVtbl, &CLSID_Vtbl>,
	public IDispatchImpl<IVtbl, &IID_IVtbl, &LIBID_LowXRuntime>
{
public:
	CVtbl()
	{
		m_pObj = NULL;
		m_nUnbindAction = -1;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_VTBL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CVtbl)
	COM_INTERFACE_ENTRY(IVtbl)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IVtbl
public:
	STDMETHOD(get_Item)(int Index, POINTER_TYPE *ret);
	STDMETHOD(put_Item)(int Index, POINTER_TYPE newVal);
	STDMETHOD(Bind)(/*[in]*/POINTER_TYPE pObject, /*[in,default_value(1)]*/int BindActionIndex, /*[in,default_value(2)]*/int UnbindActionIndex);
	STDMETHOD(Unbind)();

public:
	POINTER_TYPE	m_pObj;
	int		m_nUnbindAction;

	void *GetVtblItem(void *pThis, int Index);
	void *SetVtblItem(void *pThis, int Index, void *newVal);

	int InvokeThiscall(void *pThis, void *pProc);
	int InvokeThiscallByIndex(void *pThis, int index);
};

#endif //__VTBL_H_
