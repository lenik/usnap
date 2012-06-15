// CaBomb.h: Definition of the CCaBomb class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CABOMB_H__17296A65_713F_4991_BC4D_93C652401D40__INCLUDED_)
#define AFX_CABOMB_H__17296A65_713F_4991_BC4D_93C652401D40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCaBomb

class CCaBomb :
	public IDispatchImpl<ICaBomb, &IID_ICaBomb, &LIBID_CaDogCatLib>,
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CCaBomb,&CLSID_CaBomb>,
	public IDispatchImpl<ICaCat, &IID_ICaCat, &LIBID_CaDogCatLib>,
	public IDispatchImpl<ICaDog, &IID_ICaDog, &LIBID_CaDogCatLib>
{
public:
	CCaBomb() {}
BEGIN_COM_MAP(CCaBomb)
//DEL 	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ICaBomb)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY2(IDispatch, ICaBomb)
	COM_INTERFACE_ENTRY(ICaCat)
	COM_INTERFACE_ENTRY(ICaDog)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CCaBomb)
// Remove the comment from the line above if you don't want your object to
// support aggregation.

DECLARE_REGISTRY_RESOURCEID(IDR_CaBomb)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ICaBomb
public:
	STDMETHOD(get_p1)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_p1)(/*[in]*/ long newVal);
	STDMETHOD(bomb)();
// ICaCat
	STDMETHOD(shout)()
	{
		return E_NOTIMPL;
	}
	STDMETHOD(bornDog)(ICaDog **ret) {
		return E_NOTIMPL;
	}
	STDMETHOD(bornCat)(ICaCat **ret)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(catshout)()
	{
		return E_NOTIMPL;
	}
// ICaDog
};

#endif // !defined(AFX_CABOMB_H__17296A65_713F_4991_BC4D_93C652401D40__INCLUDED_)
