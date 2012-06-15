// RawExporter.h : Declaration of the CRawExporter

#ifndef __RAWEXPORTER_H_
#define __RAWEXPORTER_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRawExporter
class ATL_NO_VTABLE CRawExporter :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRawExporter, &CLSID_RawExporter>,
	public IDispatchImpl<IRawExporter, &IID_IRawExporter, &LIBID_HEXEDITCTLLib>
{
public:
	CRawExporter()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RAWEXPORTER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRawExporter)
	COM_INTERFACE_ENTRY(IRawExporter)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IRawExporter
public:
};

#endif //__RAWEXPORTER_H_
