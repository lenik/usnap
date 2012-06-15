// Redeclare.h: Definition of the CRedeclare class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REDECLARE_H__E1FC9E46_27C4_4626_9657_A6C588B53560__INCLUDED_)
#define AFX_REDECLARE_H__E1FC9E46_27C4_4626_9657_A6C588B53560__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRedeclare

class CRedeclare :
	public IDispatchImpl<IRedeclare, &IID_IRedeclare, &LIBID_IDL_LABLib>,
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CRedeclare,&CLSID_Redeclare>
{
public:
	CRedeclare() {}
BEGIN_COM_MAP(CRedeclare)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IRedeclare)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CRedeclare)
// Remove the comment from the line above if you don't want your object to
// support aggregation.

DECLARE_REGISTRY_RESOURCEID(IDR_Redeclare)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IRedeclare
public:
//	STDMETHOD(f1)(IRedeclare *p1);
	STDMETHOD(f1)(IDispatch *p1);
};

#endif // !defined(AFX_REDECLARE_H__E1FC9E46_27C4_4626_9657_A6C588B53560__INCLUDED_)
