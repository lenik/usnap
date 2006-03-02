// Globals.cpp : Implementation of CGlobals
#include "stdafx.h"
#include "Mapping.h"
#include "Globals.h"

#include "ConnectionAdapter.h"
#include "RecordsetAdapter.h"
#include "CommandAdapter.h"

/////////////////////////////////////////////////////////////////////////////
// CGlobals


STDMETHODIMP CGlobals::ExportConnection(IConnection *impl, _Connection **result)
{
    if (impl == NULL)
        return E_INVALIDARG;
    if (result == NULL)
        return E_POINTER;
    CConnectionAdapterObject *adapter;
    adapter = new CConnectionAdapterObject();
    adapter->setImpl(impl);
    adapter->AddRef();
    *result = adapter;
	return S_OK;
}

STDMETHODIMP CGlobals::ExportRecordset(IRecordset *impl, _Recordset **result)
{
    if (impl == NULL)
        return E_INVALIDARG;
    if (result == NULL)
        return E_POINTER;
    CRecordsetAdapterObject *adapter;
    adapter = new CRecordsetAdapterObject();
    adapter->setImpl(impl);
    adapter->AddRef();
    *result = adapter;
	return S_OK;
}

STDMETHODIMP CGlobals::ExportCommand(ICommand *impl, _Command **result)
{
    if (impl == NULL)
        return E_INVALIDARG;
    if (result == NULL)
        return E_POINTER;
    CCommandAdapterObject *adapter;
    adapter = new CCommandAdapterObject(impl);
    adapter->AddRef();
    *result = adapter;
	return S_OK;
}
