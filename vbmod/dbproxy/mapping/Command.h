// Command.h : Declaration of the CCommand

#ifndef __COMMAND_H_
#define __COMMAND_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCommand
class ATL_NO_VTABLE CCommand :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCommand, &CLSID_P_Command>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CCommand>,
	public IDispatchImpl<ICommand, &IID_ICommand, &LIBID_ADOMapping>
{
public:
	CCommand()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_COMMAND)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCommand)
    COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ICommand)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CCommand)
END_CONNECTION_POINT_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ICommand
public:
	STDMETHOD(get_Properties)(Properties * * pVal);
	STDMETHOD(put_ActiveConnection)(VARIANT ppvObject);
	STDMETHOD(get_CommandText)(BSTR * pbstr);
	STDMETHOD(put_CommandText)(BSTR pbstr);
	STDMETHOD(get_CommandTimeout)(LONG * pl);
	STDMETHOD(put_CommandTimeout)(LONG pl);
	STDMETHOD(get_Prepared)(VARIANT_BOOL * pfPrepared);
	STDMETHOD(put_Prepared)(VARIANT_BOOL pfPrepared);
	STDMETHOD(Execute)(VARIANT * RecordsAffected, VARIANT * Parameters, LONG Options, _Recordset * * ppiRs);
	STDMETHOD(CreateParameter)(BSTR Name, DataTypeEnum Type, ParameterDirectionEnum Direction, long Size, VARIANT Value, _Parameter * * ppiprm);
	STDMETHOD(get_Parameters)(Parameters * * ppvObject);
	STDMETHOD(put_CommandType)(CommandTypeEnum plCmdType);
	STDMETHOD(get_CommandType)(CommandTypeEnum * plCmdType);
	STDMETHOD(get_Name)(BSTR * pbstrName);
	STDMETHOD(put_Name)(BSTR pbstrName);
	STDMETHOD(get_State)(LONG * plObjState);
	STDMETHOD(Cancel)();
	STDMETHOD(putref_CommandStream)(IUnknown * pvStream);
	STDMETHOD(get_CommandStream)(VARIANT * pvStream);
	STDMETHOD(put_Dialect)(BSTR pbstrDialect);
	STDMETHOD(get_Dialect)(BSTR * pbstrDialect);
	STDMETHOD(put_NamedParameters)(VARIANT_BOOL pfNamedParameters);
	STDMETHOD(get_NamedParameters)(VARIANT_BOOL * pfNamedParameters);
	STDMETHOD(get_ActiveConnection)(_Connection * * ppvObject);
	STDMETHOD(putref_ActiveConnection)(_Connection * ppvObject);
};

#endif //__COMMAND_H_
