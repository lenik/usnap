// Recordset.h : Declaration of the CRecordset

#ifndef __RECORDSET_H_
#define __RECORDSET_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRecordset
class ATL_NO_VTABLE CRecordset :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRecordset, &CLSID_P_Recordset>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CRecordset>,
	public IDispatchImpl<IRecordset, &IID_IRecordset, &LIBID_ADOMapping>
{
public:
	CRecordset()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RECORDSET)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRecordset)
	COM_INTERFACE_ENTRY(IRecordset)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CRecordset)
END_CONNECTION_POINT_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IRecordset
public:
};

#endif //__RECORDSET_H_
