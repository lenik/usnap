// OeT.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL,
//      run nmake -f OeTps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "OeT.h"

#include "OeT_i.c"

#include "OeT_types.h"

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
	OBJECT_ENTRY(CLSID_OeTVariant,		OeTVariant)
	OBJECT_ENTRY(CLSID_OeTString,		OeTString)
	OBJECT_ENTRY(CLSID_OeTArray,		OeTArray)
	OBJECT_ENTRY(CLSID_OeTChain,		OeTChain)
	OBJECT_ENTRY(CLSID_OeTQueue,		OeTQueue)
	OBJECT_ENTRY(CLSID_OeTStack,		OeTStack)
	OBJECT_ENTRY(CLSID_OeTSet,		OeTSet)
	OBJECT_ENTRY(CLSID_OeTTable,		OeTTable)
	OBJECT_ENTRY(CLSID_OeTHash,		OeTHash)
	OBJECT_ENTRY(CLSID_OeTTree2,		OeTTree2)
	OBJECT_ENTRY(CLSID_OeTTree,		OeTTree)
	OBJECT_ENTRY(CLSID_OeTGraph,		OeTGraph)
	OBJECT_ENTRY(CLSID_OeTCodedStream,	OeTCodedStream)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, hInstance, &LIBID_OeTLib);
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
