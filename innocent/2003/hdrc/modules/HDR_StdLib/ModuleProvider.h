// ModuleProvider.h : Declaration of the CModuleProvider

#ifndef __MODULEPROVIDER_H_
#define __MODULEPROVIDER_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CModuleProvider
class ATL_NO_VTABLE CModuleProvider :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CModuleProvider, &CLSID_ModuleProvider>,
	public ISupportErrorInfo,
	public IDispatchImpl<IModuleProvider, &IID_IModuleProvider, &LIBID_HDR_StdLib>
{
public:
	CModuleProvider()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MODULEPROVIDER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CModuleProvider)
	COM_INTERFACE_ENTRY(IModuleProvider)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IModuleProvider
public:
};

#endif //__MODULEPROVIDER_H_
