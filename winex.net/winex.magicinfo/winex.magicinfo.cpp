// winex.magicinfo.cpp : Implementation of DLL Exports.


#include "stdafx.h"
#include "resource.h"
#include "winexmagicinfo.h"


class CwinexmagicinfoModule : public CAtlDllModuleT< CwinexmagicinfoModule >
{
public :
	DECLARE_LIBID(LIBID_WinexMagicInfo)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_WINEXMAGICINFO, "{58AE0544-425A-48FE-BE94-5F802EA11850}")
};

CwinexmagicinfoModule _AtlModule;

class CwinexmagicinfoApp : public CWinApp
{
public:

// Overrides
    virtual BOOL InitInstance();
    virtual int ExitInstance();

    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CwinexmagicinfoApp, CWinApp)
END_MESSAGE_MAP()

CwinexmagicinfoApp theApp;

BOOL CwinexmagicinfoApp::InitInstance()
{
    return CWinApp::InitInstance();
}

int CwinexmagicinfoApp::ExitInstance()
{
    return CWinApp::ExitInstance();
}


// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return (AfxDllCanUnloadNow()==S_OK && _AtlModule.GetLockCount()==0) ? S_OK : S_FALSE;
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}
