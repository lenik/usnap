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
	STDMETHOD(get_Properties)(Properties * * pVal);
	STDMETHOD(get_ConnectionString)(BSTR * pbstr);
	STDMETHOD(put_ConnectionString)(BSTR pbstr);
	STDMETHOD(get_CommandTimeout)(LONG * plTimeout);
	STDMETHOD(put_CommandTimeout)(LONG plTimeout);
	STDMETHOD(get_ConnectionTimeout)(LONG * plTimeout);
	STDMETHOD(put_ConnectionTimeout)(LONG plTimeout);
	STDMETHOD(get_Version)(BSTR * pbstr);
	STDMETHOD(Close)();
	STDMETHOD(Execute)(BSTR CommandText, VARIANT * RecordsAffected, LONG Options, _Recordset * * ppiRset);
	STDMETHOD(BeginTrans)(LONG * TransactionLevel);
	STDMETHOD(CommitTrans)();
	STDMETHOD(RollbackTrans)();
	STDMETHOD(Open)(BSTR ConnectionString, BSTR UserID, BSTR Password, LONG Options);
	STDMETHOD(get_Errors)(Errors * * ppvObject);
	STDMETHOD(get_DefaultDatabase)(BSTR * pbstr);
	STDMETHOD(put_DefaultDatabase)(BSTR pbstr);
	STDMETHOD(get_IsolationLevel)(IsolationLevelEnum * Level);
	STDMETHOD(put_IsolationLevel)(IsolationLevelEnum Level);
	STDMETHOD(get_Attributes)(LONG * plAttr);
	STDMETHOD(put_Attributes)(LONG plAttr);
	STDMETHOD(get_CursorLocation)(CursorLocationEnum * plCursorLoc);
	STDMETHOD(put_CursorLocation)(CursorLocationEnum plCursorLoc);
	STDMETHOD(get_Mode)(ConnectModeEnum * plMode);
	STDMETHOD(put_Mode)(ConnectModeEnum plMode);
	STDMETHOD(get_Provider)(BSTR * pbstr);
	STDMETHOD(put_Provider)(BSTR pbstr);
	STDMETHOD(get_State)(LONG * plObjState);
	STDMETHOD(OpenSchema)(SchemaEnum Schema, VARIANT Restrictions, VARIANT SchemaID, _Recordset * * pprset);
    STDMETHOD(Cancel)();
};

#endif //__CONNECTION_H_
