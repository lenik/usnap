// Shapes.h : Declaration of the CShapes

#ifndef __SHAPES_H_
#define __SHAPES_H_

#include "resource.h"       // main symbols

#include "Lines.h"

/////////////////////////////////////////////////////////////////////////////
// CShapes
class ATL_NO_VTABLE CShapes :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CShapes, &CLSID_Shapes>,
	public IDispatchImpl<IShapes, &IID_IShapes, &LIBID_GlyphsLib>
{
    ILines *m_pLines;

public:
	CShapes();
    ~CShapes();

DECLARE_REGISTRY_RESOURCEID(IDR_SHAPES)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CShapes)
	COM_INTERFACE_ENTRY(IShapes)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IShapes
public:
	STDMETHOD(get_Lines)(/*[out, retval]*/ ILines * *pVal);
};

#endif //__SHAPES_H_
