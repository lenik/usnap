// A.h: Definition of the CA class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_A_H__0A6684DA_029B_41C4_8EE5_1CB9447CF313__INCLUDED_)
#define AFX_A_H__0A6684DA_029B_41C4_8EE5_1CB9447CF313__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CA

class CA :
	public IDispatchImpl<IA, &IID_IA, &LIBID_CLASSUSAGELib>,
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CA,&CLSID_A>
{
public:
	CA() {}
BEGIN_COM_MAP(CA)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IA)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CA)
// Remove the comment from the line above if you don't want your object to
// support aggregation.

DECLARE_REGISTRY_RESOURCEID(IDR_A)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IA
public:
	STDMETHOD(run)();
};

class CAu :
public CComObjectRoot,
public CComCoClass<CAu>,
public IDispatchImpl<IA, &IID_IA>
{
public:
//#define R1

	#ifdef R0

		STDMETHOD_(ULONG, AddRef)()
			#ifdef R1
					{ return 0; }
			#else
					= 0;
					STDMETHOD_(ULONG, AddRef) {}
			#endif

		STDMETHOD_(ULONG, Release)()
			#ifdef R1
					{ return 0; }
			#else
					= 0;
			#endif

		STDMETHOD(QueryInterface)(REFIID riid, LPVOID *ppvObject)
			#ifdef R1
					{ return NOERROR; }
			#else
					= 0;
			#endif

	#endif

};

#endif // !defined(AFX_A_H__0A6684DA_029B_41C4_8EE5_1CB9447CF313__INCLUDED_)
