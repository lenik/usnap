// Globals.h : Declaration of the CGlobals

#ifndef __GLOBALS_H_
#define __GLOBALS_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGlobals
class ATL_NO_VTABLE CGlobals :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CGlobals, &CLSID_Globals>,
	public IDispatchImpl<IGlobals, &IID_IGlobals, &LIBID_ADOMapping>
{
public:
	CGlobals()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_GLOBALS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CGlobals)
	COM_INTERFACE_ENTRY(IGlobals)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IGlobals
public:
	STDMETHOD(ExportCommand)(/*[in]*/ICommand *impl, /*[out, retval]*/_Command **result);
	STDMETHOD(ExportRecordset)(/*[in]*/IRecordset *impl, /*[out, retval]*/_Recordset **result);
	STDMETHOD(ExportConnection)(/*[in]*/IConnection *impl, /*[out, retval]*/_Connection **result);
};

#endif //__GLOBALS_H_
