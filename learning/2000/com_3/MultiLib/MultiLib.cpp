// MultiLib.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL,
//      run nmake -f MultiLibps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "MultiLib.h"

#include "MultiLib_i.c"

class CaMultiInt1 :
	public CComObjectRoot,
	public CComCoClass<CaMultiInt1, &CLSID_CaMultiInt1>,
	public ICaMultiInt1_1 {
public:
	CaMultiInt1() {}
	virtual ~CaMultiInt1() {}

public:
	STDMETHOD(AboutBox)() {
		MessageBox(NULL, "CaMultiInt1<ICaMultiInt1_1>::AboutBox", NULL, MB_OK);
		return NOERROR;
	}
public:
	BEGIN_COM_MAP(CaMultiInt1)
		COM_INTERFACE_ENTRY(ICaMultiInt1_1)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaMultiInt1)
	DECALRE_NOT_AGGREGATABLE(CaMultiInt1);

protected:
};


class CaMultiInt2 :
	public CComObjectRoot,
	public CComCoClass<CaMultiInt2, &CLSID_CaMultiInt2>,
	public ICaMultiInt2_1 {
public:
	CaMultiInt2() {}
	virtual ~CaMultiInt2() {}

public:
	STDMETHOD(AboutBox)() {
		MessageBox(NULL, "CaMultiInt1<ICaMultiInt1_1>::AboutBox", NULL, MB_OK);
		return NOERROR;
	}

public:
	BEGIN_COM_MAP(CaMultiInt2)
		COM_INTERFACE_ENTRY(ICaMultiInt2_1)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CaMultiInt2)
	DECALRE_NOT_AGGREGATABLE(CaMultiInt2);

protected:
};


CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
	OBJECT_ENTRY(CLSID_CaMultiInt1,	CaMultiInt1)
	OBJECT_ENTRY(CLSID_CaMultiInt2,	CaMultiInt2)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, hInstance, &LIBID_CaMultiIntLib);
        DisableThreadLibraryCalls(hInstance);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
        _Module.Term();
    return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
    return _Module.UnregisterServer(TRUE);
}
