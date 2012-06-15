// Como1.h: Definition of the CComo1 class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMO1_H__66D4C9CE_A757_4F32_8797_10D06579B3D4__INCLUDED_)
#define AFX_COMO1_H__66D4C9CE_A757_4F32_8797_10D06579B3D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CComo1

class CComo1 :
	public IDispatchImpl<IComo1, &IID_IComo1, &LIBID_COMOLib>,
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CComo1,&CLSID_Como1>
{
public:
	CComo1() {}
BEGIN_COM_MAP(CComo1)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IComo1)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CComo1)
// Remove the comment from the line above if you don't want your object to
// support aggregation.

DECLARE_REGISTRY_RESOURCEID(IDR_Como1)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IComo1
public:
};

#endif // !defined(AFX_COMO1_H__66D4C9CE_A757_4F32_8797_10D06579B3D4__INCLUDED_)
