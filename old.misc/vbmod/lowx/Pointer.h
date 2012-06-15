// Pointer.h : Declaration of the CPointer

#ifndef __POINTER_H_
#define __POINTER_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPointer
class ATL_NO_VTABLE CPointer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPointer, &CLSID_Pointer>,
	public IDispatchImpl<IPointer, &IID_IPointer, &LIBID_LowXRuntime>
{
public:
	CPointer()
	{
		m_lBase = 0;
		m_bTestValid = TRUE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_POINTER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CPointer)
	COM_INTERFACE_ENTRY(IPointer)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IPointer
public:
	STDMETHOD(get_TestValid)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_TestValid)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_AutoReferenceManagement)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_AutoReferenceManagement)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Base)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Base)(/*[in]*/ long newVal);

	STDMETHOD(Eval)(long val, /*[out, retval]*/long *pRet);

	STDMETHOD(ppDisp)(LPDISPATCH *refData, /*[out, retval]*/long *pRet);
	STDMETHOD(pDisp)(LPDISPATCH refData, /*[out, retval]*/long *pRet);
	STDMETHOD(ppUnk)(LPUNKNOWN *refData, /*[out, retval]*/long *pRet);
	STDMETHOD(pUnk)(LPUNKNOWN refData, /*[out, retval]*/long *pRet);
	STDMETHOD(pFunc)(long refData, /*[out, retval]*/long *pRet);
	STDMETHOD(ppStr)(BSTR *refData, /*[out, retval]*/long *pRet);
	STDMETHOD(pStr)(BSTR refData, /*[out, retval]*/long *pRet);
	STDMETHOD(pDword)(long *refData, /*[out, retval]*/long *pRet);
	STDMETHOD(pWord)(short *refData, /*[out, retval]*/long *pRet);
	STDMETHOD(pByte)(BYTE *refData, /*[out, retval]*/long *pRet);
	STDMETHOD(pAny)(VARIANT *refData, /*[out, retval]*/long *pRet);

	STDMETHOD(get_Byte)(long lOffset, /*[out, retval]*/ BYTE *pVal);
	STDMETHOD(put_Byte)(long lOffset, /*[in]*/ BYTE newVal);
	STDMETHOD(get_Word)(long lOffset, /*[out, retval]*/ short *pVal);
	STDMETHOD(put_Word)(long lOffset, /*[in]*/ short newVal);
	STDMETHOD(get_Dword)(long lOffset, /*[out, retval]*/ long *pVal);
	STDMETHOD(put_Dword)(long lOffset, /*[in]*/ long newVal);
	STDMETHOD(get_Float)(long lOffset, /*[out, retval]*/ float *pVal);
	STDMETHOD(put_Float)(long lOffset, /*[in]*/ float newVal);
	STDMETHOD(get_Double)(long lOffset, /*[out, retval]*/ double *pVal);
	STDMETHOD(put_Double)(long lOffset, /*[in]*/ double newVal);
	STDMETHOD(get_Unk)(long lOffset, /*[out, retval]*/ LPUNKNOWN *pVal);
	STDMETHOD(put_Unk)(long lOffset, /*[in]*/ LPUNKNOWN newVal);
	STDMETHOD(get_Disp)(long lOffset, /*[out, retval]*/ LPDISPATCH *pVal);
	STDMETHOD(put_Disp)(long lOffset, /*[in]*/ LPDISPATCH newVal);

	long m_lBase;
	BOOL m_bTestValid;
	BOOL m_bAutoRef;
};

#endif //__POINTER_H_
