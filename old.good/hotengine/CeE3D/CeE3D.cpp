// CeE3D.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL,
//      run nmake -f CeE3Dps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"

#include "CeE3D.h"

#include "CeE3DAux.h"
#include "CeE3DBase.h"
#include "CeE3DModel.h"
#include "CeE3DUtil.h"
#include "CeE3DEnv.h"
#include "CeE3DRender.h"
#include "CeE3DControl.h"

#include <initguid.h>
#include "CeE3D_i.c"
#include "CeE3DControlIdl_i.c"

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
	OBJECT_ENTRY(CLSID_CeE3DAux,		CeE3DAux)
	OBJECT_ENTRY(CLSID_CeE3DBase,		CeE3DBase)
	OBJECT_ENTRY(CLSID_CeE3DModel,		CeE3DModel)
	OBJECT_ENTRY(CLSID_CeE3DUtil,		CeE3DUtil)
	OBJECT_ENTRY(CLSID_CeE3DEnv,		CeE3DEnv)
	OBJECT_ENTRY(CLSID_CeE3DRender,		CeE3DRender)
	OBJECT_ENTRY(CLSID_CeE3DControl,	CeE3DControl)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, hInstance, &LIBID_CeE3DLib);
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
    //MessageBox(NULL, "正在注册组件, 请稍后...", "草原图形图像引擎 - 草原随意三维 1.1", MB_OK);
    return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
    return _Module.UnregisterServer(TRUE);
}

void main() {}
