// c1.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "..\\a1\\IFace.h"
#include "Registry.h"

void trace(const char *msg) {
	cout << msg << endl;
}

static HMODULE g_hModule	= NULL;
static long g_cComponents	= 0;
static long g_cServerLocks	= 0;

const char g_szFriendlyName[]	= "Inside COM, Chapter 7 Example";
const char g_szVerIndProgID[]	= "InsideCOM.Chap07";
const char g_szProgID[]			= "InsideCOM.Chap07.1";

class CA : public IX, public IY {
public:
	virtual HRESULT _stdcall QueryInterface(REFIID riid, LPVOID *ppv);
	virtual ULONG _stdcall AddRef();
	virtual ULONG _stdcall Release();

	virtual void _stdcall Fx() { cout << "Fx" << endl; }
	virtual void _stdcall Fy() { m_pIY->Fy(); }

	HRESULT Init();

	CA();
	~CA();
private:
	long m_cRef;
	IY *m_pIY;
};

CA::CA() : m_cRef(1), m_pIY(NULL) {
	InterlockedIncrement(&g_cComponents);
}

CA::~CA() {
	InterlockedDecrement(&g_cComponents);
	trace("Component: \t\tDestroy self. ");
	if (m_pIY != NULL) {
		m_pIY->Release();
	}
}

HRESULT CA::Init() {
	trace("Create Contained component");
	HRESULT hr = CoCreateInstance(
		CLSID_Component1,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IY,
		(void **)&m_pIY);
	if (FAILED(hr)) {
		trace("Could not create contained component.");
		return E_FAIL;
	} else {
		return S_OK;
	}
}

HRESULT _stdcall CA::QueryInterface(REFIID riid, LPVOID *ppv) {
	if (riid == IID_IUnknown) {
		*ppv = static_cast<IX *>(this);
	} else if (riid == IID_IX) {
		*ppv = static_cast<IX *>(this);
		trace("Component: \t\tReturn pointer to IX. ");
	} else if (riid == IID_IY) {
		*ppv = static_cast<IY *>(this);
		trace("Component: \t\tReturn pointer to IY. ");
	} else {
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	reinterpret_cast<IUnknown *>(*ppv)->AddRef();
	return S_OK;
}

ULONG _stdcall CA::AddRef() {
	return InterlockedIncrement(&m_cRef);
}

ULONG _stdcall CA::Release() {
	InterlockedDecrement(&m_cRef);
	if (m_cRef == 0) {
		delete this;
		return 0;
	}
	return m_cRef;
}

class CFactory : public IClassFactory {
public:
	virtual HRESULT _stdcall QueryInterface(REFIID riid, LPVOID *ppv);
	virtual ULONG _stdcall AddRef();
	virtual ULONG _stdcall Release();

	virtual HRESULT _stdcall CreateInstance(LPUNKNOWN pUnknownOuter, REFIID riid, LPVOID *ppv);
	virtual HRESULT _stdcall LockServer(BOOL bLock);

	CFactory() : m_cRef(1) {}
	~CFactory() { trace("Class factory: \t\tDestroy self. "); }
private:
	long m_cRef;
};

HRESULT _stdcall CFactory::QueryInterface(REFIID riid, LPVOID *ppv) {
	if (riid == IID_IUnknown || riid == IID_IClassFactory) {
		*ppv = static_cast<IClassFactory *>(this);
	} else {
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	reinterpret_cast<IUnknown *>(*ppv)->AddRef();
	return S_OK;
}

ULONG _stdcall CFactory::AddRef() {
	return InterlockedIncrement(&m_cRef);
}

ULONG _stdcall CFactory::Release() {
	InterlockedDecrement(&m_cRef);
	if (m_cRef == 0) {
		delete this;
		return 0;
	}
	return m_cRef;
}

HRESULT _stdcall CFactory::CreateInstance(LPUNKNOWN pUnknownOuter, REFIID riid, LPVOID *ppv) {
	trace("Class factory: \t\tCreate component. ");

	if (pUnknownOuter != NULL) {
		return CLASS_E_NOAGGREGATION;
	}

	CA *pA = new CA;
	if (pA == NULL) return E_OUTOFMEMORY;

	HRESULT hr = pA->Init();
	if (FAILED(hr)) {
		pA->Release();
		return hr;
	}

	hr = pA->QueryInterface(riid, ppv);
	pA->Release();

	return hr;
}

HRESULT _stdcall CFactory::LockServer(BOOL bLock) {
	if (bLock) {
		InterlockedIncrement(&g_cServerLocks);
	} else {
		InterlockedDecrement(&g_cServerLocks);
	}
	return S_OK;
}

STDAPI DllCanUnloadNow() {
	if ((g_cComponents == 0) && (g_cServerLocks == 0)) {
		return S_OK;
	} else {
		return S_FALSE;
	}
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv) {
	trace("DllGetClassObject: \tCreate class factory. ");

	if (rclsid != CLSID_Component1) {
		return CLASS_E_CLASSNOTAVAILABLE;
	}

	CFactory *pFactory = new CFactory;
	if (pFactory == NULL) return E_OUTOFMEMORY;

	HRESULT hr = pFactory->QueryInterface(riid, ppv);
	pFactory->Release();

	return hr;
}

STDAPI DllRegisterServer() {
	return RegisterServer(
		g_hModule,
		CLSID_Component1,
		g_szFriendlyName,
		g_szVerIndProgID,
		g_szProgID
	);
}

STDAPI DllUnregisterServer() {
	return UnregisterServer(CLSID_Component1, g_szVerIndProgID, g_szProgID);
}

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			g_hModule = (HMODULE)hModule;
			break;
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}
