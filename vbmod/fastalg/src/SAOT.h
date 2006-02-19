// SAOT.h : Declaration of the CSAOT

#ifndef __SAOT_H_
#define __SAOT_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSAOT
class ATL_NO_VTABLE CSAOT :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSAOT, &CLSID_SAOT>,
	public IDispatchImpl<ISAOT, &IID_ISAOT, &LIBID_FastAlgLib>
{
public:
	CSAOT()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SAOT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSAOT)
	COM_INTERFACE_ENTRY(ISAOT)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// ISAOT
public:
};

#endif //__SAOT_H_
