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
	public IDispatchImpl<ICommand, &IID_ICommand, &LIBID_ADOMapping>,
	public IDispatchImpl<_Command, &__uuidof(_Command), &LIBID_ADOMapping>
{
public:
	CCommand()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_COMMAND)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCommand)
	COM_INTERFACE_ENTRY(ICommand)
    COM_INTERFACE_ENTRY2(IDispatch, ICommand)
    //COM_INTERFACE_ENTRY2(IDispatch, _Command)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CCommand)
END_CONNECTION_POINT_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ICommand
public:
};

#endif //__COMMAND_H_
