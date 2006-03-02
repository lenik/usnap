// Connection.cpp : Implementation of CConnection
#include "stdafx.h"
#include "Mapping.h"
#include "Connection.h"

/////////////////////////////////////////////////////////////////////////////
// CConnection

STDMETHODIMP CConnection::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_IConnection
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

// IConnection
STDMETHODIMP CConnection::get_Properties(Properties * * pVal)
{
	if (pVal == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::get_ConnectionString(BSTR * pbstr)
{
	if (pbstr == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::put_ConnectionString(BSTR pbstr)
{
	return E_NOTIMPL;
}
STDMETHODIMP CConnection::get_CommandTimeout(LONG * plTimeout)
{
	if (plTimeout == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::put_CommandTimeout(LONG plTimeout)
{
	return E_NOTIMPL;
}
STDMETHODIMP CConnection::get_ConnectionTimeout(LONG * plTimeout)
{
	if (plTimeout == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::put_ConnectionTimeout(LONG plTimeout)
{
	return E_NOTIMPL;
}
STDMETHODIMP CConnection::get_Version(BSTR * pbstr)
{
	if (pbstr == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::Close()
{
	return E_NOTIMPL;
}
STDMETHODIMP CConnection::Execute(BSTR CommandText, VARIANT * RecordsAffected, LONG Options, _Recordset * * ppiRset)
{
	if (RecordsAffected == NULL)
		return E_POINTER;

	if (ppiRset == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::BeginTrans(LONG * TransactionLevel)
{
	if (TransactionLevel == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::CommitTrans()
{
	return E_NOTIMPL;
}
STDMETHODIMP CConnection::RollbackTrans()
{
	return E_NOTIMPL;
}
STDMETHODIMP CConnection::Open(BSTR ConnectionString, BSTR UserID, BSTR Password, LONG Options)
{
	return E_NOTIMPL;
}
STDMETHODIMP CConnection::get_Errors(Errors * * ppvObject)
{
	if (ppvObject == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::get_DefaultDatabase(BSTR * pbstr)
{
	if (pbstr == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::put_DefaultDatabase(BSTR pbstr)
{
	return E_NOTIMPL;
}
STDMETHODIMP CConnection::get_IsolationLevel(IsolationLevelEnum * Level)
{
	if (Level == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::put_IsolationLevel(IsolationLevelEnum Level)
{
	return E_NOTIMPL;
}
STDMETHODIMP CConnection::get_Attributes(LONG * plAttr)
{
	if (plAttr == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::put_Attributes(LONG plAttr)
{
	return E_NOTIMPL;
}
STDMETHODIMP CConnection::get_CursorLocation(CursorLocationEnum * plCursorLoc)
{
	if (plCursorLoc == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::put_CursorLocation(CursorLocationEnum plCursorLoc)
{
	return E_NOTIMPL;
}
STDMETHODIMP CConnection::get_Mode(ConnectModeEnum * plMode)
{
	if (plMode == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::put_Mode(ConnectModeEnum plMode)
{
	return E_NOTIMPL;
}
STDMETHODIMP CConnection::get_Provider(BSTR * pbstr)
{
	if (pbstr == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::put_Provider(BSTR pbstr)
{
	return E_NOTIMPL;
}
STDMETHODIMP CConnection::get_State(LONG * plObjState)
{
	if (plObjState == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::OpenSchema(SchemaEnum Schema, VARIANT Restrictions, VARIANT SchemaID, _Recordset * * pprset)
{
	if (pprset == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CConnection::Cancel()
{
    return E_NOTIMPL;
}
