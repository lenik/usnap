// CommandAdapter.h : Declaration of the CCommandAdapter

#ifndef __COMMANDADAPTER_H_
#define __COMMANDADAPTER_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCommandAdapter
class ATL_NO_VTABLE CCommandAdapter :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCommandAdapter, &CLSID_CommandAdapter>,
	public IDispatchImpl<ICommandAdapter, &IID_ICommandAdapter, &LIBID_ADOMapping>,
	public IDispatchImpl<_ADO, &IID__ADO, &LIBID_ADODB>,
	public IDispatchImpl<_Command, &IID__Command, &LIBID_ADODB>,
	public IDispatchImpl<Command15, &IID_Command15, &LIBID_ADODB>,
	public IDispatchImpl<Command25, &IID_Command25, &LIBID_ADODB>
{
    ICommand *m_Impl;
public:
    CCommandAdapter() : m_Impl(NULL) {}
    CCommandAdapter(ICommand *impl) {
        setImpl(impl);
    }
    ~CCommandAdapter() {
        SAFE_RELEASE(m_Impl);
    }
    void setImpl(ICommand *impl) {
        _assert_(impl);
        m_Impl = impl;
        m_Impl->AddRef();
    }

DECLARE_REGISTRY_RESOURCEID(IDR_COMMANDADAPTER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCommandAdapter)
	COM_INTERFACE_ENTRY(ICommandAdapter)
//DEL 	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, ICommandAdapter)
	COM_INTERFACE_ENTRY(_Command)
	COM_INTERFACE_ENTRY2(_ADO, _Command)
	COM_INTERFACE_ENTRY2(Command15, _Command)
	COM_INTERFACE_ENTRY2(Command25, _Command)
END_COM_MAP()

// ICommandAdapter
public:
// _ADO
	STDMETHOD(get_Properties)(Properties * * ppvObject)
	{
		if (ppvObject == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
// _Command
	STDMETHOD(putref_CommandStream)(IUnknown * pvStream)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(get_CommandStream)(VARIANT * pvStream)
	{
		if (pvStream == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(put_Dialect)(BSTR pbstrDialect)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(get_Dialect)(BSTR * pbstrDialect)
	{
		if (pbstrDialect == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(put_NamedParameters)(VARIANT_BOOL pfNamedParameters)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(get_NamedParameters)(VARIANT_BOOL * pfNamedParameters)
	{
		if (pfNamedParameters == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
// Command15
	STDMETHOD(get_ActiveConnection)(_Connection * * ppvObject)
	{
		if (ppvObject == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(putref_ActiveConnection)(_Connection * ppvObject)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(put_ActiveConnection)(VARIANT ppvObject)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(get_CommandText)(BSTR * pbstr)
	{
		if (pbstr == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(put_CommandText)(BSTR pbstr)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(get_CommandTimeout)(LONG * pl)
	{
		if (pl == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(put_CommandTimeout)(LONG pl)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(get_Prepared)(VARIANT_BOOL * pfPrepared)
	{
		if (pfPrepared == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(put_Prepared)(VARIANT_BOOL pfPrepared)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(Execute)(VARIANT * RecordsAffected, VARIANT * Parameters, LONG Options, _Recordset * * ppiRs)
	{
		if (RecordsAffected == NULL)
			return E_POINTER;

		if (ppiRs == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(CreateParameter)(BSTR Name, DataTypeEnum Type, ParameterDirectionEnum Direction, ADO_LONGPTR Size, VARIANT Value, _Parameter * * ppiprm)
	{
		if (ppiprm == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(get_Parameters)(Parameters * * ppvObject)
	{
		if (ppvObject == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(put_CommandType)(CommandTypeEnum plCmdType)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(get_CommandType)(CommandTypeEnum * plCmdType)
	{
		if (plCmdType == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(get_Name)(BSTR * pbstrName)
	{
		if (pbstrName == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(put_Name)(BSTR pbstrName)
	{
		return E_NOTIMPL;
	}
// Command25
	STDMETHOD(get_State)(LONG * plObjState)
	{
		if (plObjState == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(Cancel)()
	{
		return E_NOTIMPL;
	}
};

typedef CComObject<CCommandAdapter> CCommandAdapterObject;

#endif //__COMMANDADAPTER_H_
