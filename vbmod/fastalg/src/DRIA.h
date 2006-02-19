// DRIA.h : Declaration of the CDRIA

#ifndef __DRIA_H_
#define __DRIA_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDRIA
class ATL_NO_VTABLE CDRIA :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDRIA, &CLSID_DRIA>,
	public IDispatchImpl<IDRIA, &IID_IDRIA, &LIBID_FastAlgLib>
{
public:
	CDRIA()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DRIA)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDRIA)
	COM_INTERFACE_ENTRY(IDRIA)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IDRIA
public:
};

#endif //__DRIA_H_
