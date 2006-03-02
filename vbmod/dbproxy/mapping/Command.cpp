// Command.cpp : Implementation of CCommand
#include "stdafx.h"
#include "Mapping.h"
#include "Command.h"

/////////////////////////////////////////////////////////////////////////////
// CCommand

STDMETHODIMP CCommand::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_ICommand
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
STDMETHODIMP CCommand::get_Properties(Properties * * pVal)
{
	if (pVal == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CCommand::get_ActiveConnection(_Connection * * ppvObject)
{
	if (ppvObject == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CCommand::putref_ActiveConnection(_Connection * ppvObject)
{
	return E_NOTIMPL;
}
STDMETHODIMP CCommand::put_ActiveConnection(VARIANT ppvObject)
{
	return E_NOTIMPL;
}
STDMETHODIMP CCommand::get_CommandText(BSTR * pbstr)
{
	if (pbstr == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CCommand::put_CommandText(BSTR pbstr)
{
	return E_NOTIMPL;
}
STDMETHODIMP CCommand::get_CommandTimeout(LONG * pl)
{
	if (pl == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CCommand::put_CommandTimeout(LONG pl)
{
	return E_NOTIMPL;
}
STDMETHODIMP CCommand::get_Prepared(VARIANT_BOOL * pfPrepared)
{
	if (pfPrepared == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CCommand::put_Prepared(VARIANT_BOOL pfPrepared)
{
	return E_NOTIMPL;
}
STDMETHODIMP CCommand::Execute(VARIANT * RecordsAffected, VARIANT * Parameters, LONG Options, _Recordset * * ppiRs)
{
	if (RecordsAffected == NULL)
		return E_POINTER;

	if (ppiRs == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CCommand::CreateParameter(BSTR Name, DataTypeEnum Type, ParameterDirectionEnum Direction, ADO_LONGPTR Size, VARIANT Value, _Parameter * * ppiprm)
{
	if (ppiprm == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CCommand::get_Parameters(Parameters * * ppvObject)
{
	if (ppvObject == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CCommand::put_CommandType(CommandTypeEnum plCmdType)
{
	return E_NOTIMPL;
}
STDMETHODIMP CCommand::get_CommandType(CommandTypeEnum * plCmdType)
{
	if (plCmdType == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CCommand::get_Name(BSTR * pbstrName)
{
	if (pbstrName == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CCommand::put_Name(BSTR pbstrName)
{
	return E_NOTIMPL;
}
STDMETHODIMP CCommand::get_State(LONG * plObjState)
{
	if (plObjState == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CCommand::Cancel()
{
	return E_NOTIMPL;
}
STDMETHODIMP CCommand::putref_CommandStream(IUnknown * pvStream)
{
	return E_NOTIMPL;
}
STDMETHODIMP CCommand::get_CommandStream(VARIANT * pvStream)
{
	if (pvStream == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CCommand::put_Dialect(BSTR pbstrDialect)
{
	return E_NOTIMPL;
}
STDMETHODIMP CCommand::get_Dialect(BSTR * pbstrDialect)
{
	if (pbstrDialect == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CCommand::put_NamedParameters(VARIANT_BOOL pfNamedParameters)
{
	return E_NOTIMPL;
}
STDMETHODIMP CCommand::get_NamedParameters(VARIANT_BOOL * pfNamedParameters)
{
	if (pfNamedParameters == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
