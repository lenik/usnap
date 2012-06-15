// Lines.h : Declaration of the CLines

#ifndef __LINES_H_
#define __LINES_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLines
class ATL_NO_VTABLE CLines :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CLines, &CLSID_Lines>,
	public IDispatchImpl<ILines, &IID_ILines, &LIBID_GlyphsLib>
{
public:
	CLines()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_LINES)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CLines)
	COM_INTERFACE_ENTRY(ILines)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// ILines
public:
	STDMETHOD(Arrow)(/*[in]*/long hDC, /*[in]*/ArrowTypeConstants type, /*[in]*/long x0, /*[in]*/long y0, /*[in]*/long x1, /*[in]*/long y1);
};

typedef CComObject<CLines> CLinesObject;

#endif //__LINES_H_
