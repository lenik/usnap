// Connection.h : Declaration of the CConnection

#ifndef __CONNECTION_H_
#define __CONNECTION_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CConnection
class ATL_NO_VTABLE CConnection :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CConnection, &CLSID_P_Connection>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CConnection>,
	public IDispatchImpl<IConnection, &IID_IConnection, &LIBID_ADOMapping>
{
public:
	CConnection()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CONNECTION)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CConnection)
	COM_INTERFACE_ENTRY(IConnection)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CConnection)
END_CONNECTION_POINT_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IConnection
public:
};

#endif //__CONNECTION_H_
