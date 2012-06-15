// OeSO.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL,
//      run nmake -f OeSOps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "OeSO.h"

#include "OeSO_i.c"

#include "OeSODeclares.h"

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
	OBJECT_ENTRY(CLSID_OeSOParser,			OeSOParser)
	OBJECT_ENTRY(CLSID_OeSOCompiler,		OeSOCompiler)
	OBJECT_ENTRY(CLSID_OeSOEvaluator,		OeSOEvaluator)

	OBJECT_ENTRY(CLSID_OeSOObject,			OeSOObject)
	OBJECT_ENTRY(CLSID_OeSOInterface,		OeSOInterface)
	OBJECT_ENTRY(CLSID_OeSOClass,			OeSOClass)
	OBJECT_ENTRY(CLSID_OeSOStatus,			OeSOStatus)
	OBJECT_ENTRY(CLSID_OeSOAttribute,		OeSOAttribute)
	OBJECT_ENTRY(CLSID_OeSOMethod,			OeSOMethod)
	OBJECT_ENTRY(CLSID_OeSOEvent,			OeSOEvent)

	OBJECT_ENTRY(CLSID_OeSOObjectsCollection,	OeSOObjectsCollection)
	OBJECT_ENTRY(CLSID_OeSOInterfacesCollection,	OeSOInterfacesCollection)
	OBJECT_ENTRY(CLSID_OeSOClassesCollection,	OeSOClassesCollection)
	OBJECT_ENTRY(CLSID_OeSOStatusesCollection,	OeSOStatusesCollection)
	OBJECT_ENTRY(CLSID_OeSOAttributesCollection,	OeSOAttributesCollection)
	OBJECT_ENTRY(CLSID_OeSOMethodsCollection,	OeSOMethodsCollection)
	OBJECT_ENTRY(CLSID_OeSOEventsCollection,	OeSOEventsCollection)

	OBJECT_ENTRY(CLSID_OeSOApplication,		OeSOApplication)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, hInstance, &LIBID_OeSOLib);
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
