// ConnectionAdapter.h : Declaration of the CConnectionAdapter

#ifndef __CONNECTIONADAPTER_H_
#define __CONNECTIONADAPTER_H_

#include "resource.h"       // main symbols
#include "msado15CP.h"

/////////////////////////////////////////////////////////////////////////////
// CConnectionAdapter
class ATL_NO_VTABLE CConnectionAdapter :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CConnectionAdapter, &CLSID_ConnectionAdapter>,
	public IDispatchImpl<IConnectionAdapter, &IID_IConnectionAdapter, &LIBID_ADOMapping>,
	public IDispatchImpl<_Connection, &IID__Connection, &LIBID_ADODB>,
	public IDispatchImpl<_ADO, &IID__ADO, &LIBID_ADODB>,
	public IDispatchImpl<Connection15, &IID_Connection15, &LIBID_ADODB>,
	public ConnectionEventsVt,
	public CProxyConnectionEvents< CConnectionAdapter >,
	public IConnectionPointContainerImpl<CConnectionAdapter>
{
    IConnection *m_Impl;

public:
    CConnectionAdapter() : m_Impl(NULL) {}
    CConnectionAdapter(IConnection *impl) {
        setImpl(impl);
    }
    ~CConnectionAdapter() {
        SAFE_RELEASE(m_Impl);
    }
    void setImpl(IConnection *impl) {
        _assert_(impl);
        m_Impl = impl;
        m_Impl->AddRef();
    }

DECLARE_REGISTRY_RESOURCEID(IDR_CONNECTIONADAPTER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CConnectionAdapter)
	COM_INTERFACE_ENTRY(IConnectionAdapter)
//DEL 	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IConnectionAdapter)
	COM_INTERFACE_ENTRY(_Connection)
	COM_INTERFACE_ENTRY2(_ADO, _Connection)
	COM_INTERFACE_ENTRY2(Connection15, _Connection)
	COM_INTERFACE_ENTRY(ConnectionEventsVt)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

// IConnectionAdapter
public:
// _Connection
	STDMETHOD(Cancel)()
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->Cancel();
	}
// _ADO
	STDMETHOD(get_Properties)(Properties * * ppvObject)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (ppvObject == NULL)
			return E_POINTER;
		return m_Impl->get_Properties(ppvObject);
	}
// _Connection
// Connection15
	STDMETHOD(get_ConnectionString)(BSTR * pbstr)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (pbstr == NULL)
			return E_POINTER;
		return m_Impl->get_ConnectionString(pbstr);
	}
	STDMETHOD(put_ConnectionString)(BSTR pbstr)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_ConnectionString(pbstr);
	}
	STDMETHOD(get_CommandTimeout)(LONG * plTimeout)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (plTimeout == NULL)
			return E_POINTER;
		return m_Impl->get_CommandTimeout(plTimeout);
	}
	STDMETHOD(put_CommandTimeout)(LONG plTimeout)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_CommandTimeout(plTimeout);
	}
	STDMETHOD(get_ConnectionTimeout)(LONG * plTimeout)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (plTimeout == NULL)
			return E_POINTER;
		return m_Impl->get_ConnectionTimeout(plTimeout);
	}
	STDMETHOD(put_ConnectionTimeout)(LONG plTimeout)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_ConnectionTimeout(plTimeout);
	}
	STDMETHOD(get_Version)(BSTR * pbstr)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (pbstr == NULL)
			return E_POINTER;
		return m_Impl->get_Version(pbstr);
	}
	STDMETHOD(Close)()
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->Close();
	}
	STDMETHOD(Execute)(BSTR CommandText, VARIANT * RecordsAffected, LONG Options, _Recordset * * ppiRset)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (RecordsAffected == NULL)
			return E_POINTER;
		if (ppiRset == NULL)
			return E_POINTER;
		return m_Impl->Execute(CommandText, RecordsAffected, Options, ppiRset);
	}
	STDMETHOD(BeginTrans)(LONG * TransactionLevel)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (TransactionLevel == NULL)
			return E_POINTER;
        return m_Impl->BeginTrans(TransactionLevel);
	}
	STDMETHOD(CommitTrans)()
    {
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->CommitTrans();
    }
	STDMETHOD(RollbackTrans)()
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->RollbackTrans();
    }
	STDMETHOD(Open)(BSTR ConnectionString, BSTR UserID, BSTR Password, LONG Options)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->Open(ConnectionString, UserID, Password, Options);
    }
	STDMETHOD(get_Errors)(Errors * * ppvObject)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (ppvObject == NULL)
			return E_POINTER;

        return m_Impl->get_Errors(ppvObject);
    }
	STDMETHOD(get_DefaultDatabase)(BSTR * pbstr)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (pbstr == NULL)
			return E_POINTER;

        return m_Impl->get_DefaultDatabase(pbstr);
    }
	STDMETHOD(put_DefaultDatabase)(BSTR pbstr)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_DefaultDatabase(pbstr);
    }
	STDMETHOD(get_IsolationLevel)(IsolationLevelEnum * Level)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (Level == NULL)
			return E_POINTER;

        return m_Impl->get_IsolationLevel(Level);
    }
	STDMETHOD(put_IsolationLevel)(IsolationLevelEnum Level)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_IsolationLevel(Level);
    }
	STDMETHOD(get_Attributes)(LONG * plAttr)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (plAttr == NULL)
			return E_POINTER;

        return m_Impl->get_Attributes(plAttr);
    }
	STDMETHOD(put_Attributes)(LONG plAttr)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_Attributes(plAttr);
    }
	STDMETHOD(get_CursorLocation)(CursorLocationEnum * plCursorLoc)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (plCursorLoc == NULL)
			return E_POINTER;

        return m_Impl->get_CursorLocation(plCursorLoc);
    }
	STDMETHOD(put_CursorLocation)(CursorLocationEnum plCursorLoc)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_CursorLocation(plCursorLoc);
    }
	STDMETHOD(get_Mode)(ConnectModeEnum * plMode)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (plMode == NULL)
			return E_POINTER;

        return m_Impl->get_Mode(plMode);
    }
	STDMETHOD(put_Mode)(ConnectModeEnum plMode)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_Mode(plMode);
    }
	STDMETHOD(get_Provider)(BSTR * pbstr)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (pbstr == NULL)
			return E_POINTER;

        return m_Impl->get_Provider(pbstr);
    }
	STDMETHOD(put_Provider)(BSTR pbstr)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_Provider(pbstr);
    }
	STDMETHOD(get_State)(LONG * plObjState)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (plObjState == NULL)
			return E_POINTER;

        return m_Impl->get_State(plObjState);
    }
	STDMETHOD(OpenSchema)(SchemaEnum Schema, VARIANT Restrictions, VARIANT SchemaID, _Recordset * * pprset)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		if (pprset == NULL)
			return E_POINTER;

        return m_Impl->OpenSchema(Schema, Restrictions, SchemaID, pprset);
    }
// ConnectionEventsVt
    STDMETHOD(InfoMessage)(ADODB::Error * pError, EventStatusEnum * adStatus, _Connection * pConnection)
	{
		if (adStatus == NULL)
			return E_POINTER;

        return Fire_InfoMessage(pError, adStatus, pConnection);
    }
	STDMETHOD(BeginTransComplete)(LONG TransactionLevel, ADODB::Error * pError, EventStatusEnum * adStatus, _Connection * pConnection)
	{
		if (adStatus == NULL)
			return E_POINTER;

        return Fire_BeginTransComplete(TransactionLevel, pError, adStatus, pConnection);
    }
	STDMETHOD(CommitTransComplete)(ADODB::Error * pError, EventStatusEnum * adStatus, _Connection * pConnection)
	{
		if (adStatus == NULL)
			return E_POINTER;

        return Fire_CommitTransComplete(pError, adStatus, pConnection);
    }
	STDMETHOD(RollbackTransComplete)(ADODB::Error * pError, EventStatusEnum * adStatus, _Connection * pConnection)
	{
		if (adStatus == NULL)
			return E_POINTER;

        return Fire_RollbackTransComplete(pError, adStatus, pConnection);
    }
	STDMETHOD(WillExecute)(BSTR * Source, CursorTypeEnum * CursorType, LockTypeEnum * LockType, LONG * Options, EventStatusEnum * adStatus, _Command * pCommand, _Recordset * pRecordset, _Connection * pConnection)
	{
		if (Source == NULL)
			return E_POINTER;

		if (CursorType == NULL)
			return E_POINTER;

		if (LockType == NULL)
			return E_POINTER;

		if (Options == NULL)
			return E_POINTER;

		if (adStatus == NULL)
			return E_POINTER;

        return Fire_WillExecute(Source, CursorType, LockType, Options, adStatus, pCommand, pRecordset, pConnection);
    }
	STDMETHOD(ExecuteComplete)(LONG RecordsAffected, ADODB::Error * pError, EventStatusEnum * adStatus, _Command * pCommand, _Recordset * pRecordset, _Connection * pConnection)
	{
		if (adStatus == NULL)
			return E_POINTER;

        return Fire_ExecuteComplete(RecordsAffected, pError, adStatus, pCommand, pRecordset, pConnection);
    }
	STDMETHOD(WillConnect)(BSTR * ConnectionString, BSTR * UserID, BSTR * Password, LONG * Options, EventStatusEnum * adStatus, _Connection * pConnection)
	{
		if (ConnectionString == NULL)
			return E_POINTER;

		if (UserID == NULL)
			return E_POINTER;

		if (Password == NULL)
			return E_POINTER;

		if (Options == NULL)
			return E_POINTER;

		if (adStatus == NULL)
			return E_POINTER;

        return Fire_WillConnect(ConnectionString, UserID, Password, Options, adStatus, pConnection);
    }
	STDMETHOD(ConnectComplete)(ADODB::Error * pError, EventStatusEnum * adStatus, _Connection * pConnection)
	{
		if (adStatus == NULL)
			return E_POINTER;

        return Fire_ConnectComplete(pError, adStatus, pConnection);
    }
	STDMETHOD(Disconnect)(EventStatusEnum * adStatus, _Connection * pConnection)
	{
		if (adStatus == NULL)
			return E_POINTER;

        return Fire_Disconnect(adStatus, pConnection);
    }
public :

BEGIN_CONNECTION_POINT_MAP(CConnectionAdapter)
	CONNECTION_POINT_ENTRY(DIID_ConnectionEvents)
END_CONNECTION_POINT_MAP()

};

typedef CComObject<CConnectionAdapter> CConnectionAdapterObject;

#endif //__CONNECTIONADAPTER_H_
