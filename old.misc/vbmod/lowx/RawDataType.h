// RawDataType.h : Declaration of the CRawDataType

#ifndef __RAWDATATYPE_H_
#define __RAWDATATYPE_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRawDataType
class ATL_NO_VTABLE CRawDataType :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRawDataType, &CLSID_RawDataType>,
	public IDispatchImpl<IRawDataType, &IID_IRawDataType, &LIBID_LowXRuntime>
{
public:
	CRawDataType()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RAWDATATYPE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRawDataType)
	COM_INTERFACE_ENTRY(IRawDataType)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IRawDataType
public:
	STDMETHOD(fPow)(double a, double b, /*[out, retval]*/double *pRet);
	STDMETHOD(fDiv)(double a, double b, /*[out, retval]*/double *pRet);
	STDMETHOD(fMul)(double a, double b, /*[out, retval]*/double *pRet);
	STDMETHOD(fSub)(double a, double b, /*[out, retval]*/double *pRet);
	STDMETHOD(fAdd)(double a, double b, /*[out, retval]*/double *pRet);
	STDMETHOD(Not)(long a, /*[out, retval]*/long *pRet);
	STDMETHOD(Xor)(long a, long b, /*[out, retval]*/long *pRet);
	STDMETHOD(Or)(long a, long b, /*[out, retval]*/long *pRet);
	STDMETHOD(And)(long a, long b, /*[out, retval]*/long *pRet);
	STDMETHOD(Shift)(long a, long b, /*[out, retval]*/long *pRet);
	STDMETHOD(Pow)(long a, long b, /*[out, retval]*/long *pRet);
	STDMETHOD(Div)(long a, long b, /*[out, retval]*/long *pRet);
	STDMETHOD(Mul)(long a, long b, /*[out, retval]*/long *pRet);
	STDMETHOD(Sub)(long a, long b, /*[out, retval]*/long *pRet);
	STDMETHOD(Add)(long a, long b, /*[out, retval]*/long *pRet);
};

#endif //__RAWDATATYPE_H_
