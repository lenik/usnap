// agc1.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "..\\a1\\IFace.h"
#include "Registry.h"

void trace(LPCTSTR msg) { cout << "Component1: \t" << msg << endl; }

static HMODULE g_hModule			= NULL;
static LONG g_cComponents			= 0;
static LONG g_cServerLocks			= 0;

const char g_szFriendlyName[]		= "Inside COM, Chapter 8 Example 2, component 1";
const char g_szVerIndProgID[]		= "InsideCOM.Chap08.Ex2.Cmpnt1";
const char g_szProgID[]				= "InsideCOM.Chap08.Ex2.Cmpnt1.1";

class CA : public IX {
public:
	virtual HRESULT _stdcall QueryInterface(REFIID riid, LPVOID *ppv);
	virtual ULONG _stdcall AddRef();
	virtual ULONG _stdcall Release();

	virtual void _stdcall Fx() { cout << "Fx" << endl; }

	virtual void _stdcall Fy() { m_pIY->Fy(); }

	CA();
	~CA();

	HRESULT _stdcall Init();

private:
	long m_cRef;

	// Pointer to the aggregated component's IY interface
	// (We do not have to retain an IY pointer, However, we
	// can use it in QueryInterface
	IY *m_pIY;
	// Pointer the inner component's IUnknown
	IUnknown *m_pUnknownInner;
};

CA::CA() : m_cRef(1), m_pUnknownInner(NULL) {
	InterlockedIncrement(&g_cComponents);
}

CA::~CA() {
	InterlockedIncrement(&g_cComponents);
	trace("Destroy self");

	// Prevent recursive destruction on next AddRef/Release pair.
	m_cRef = 1;

	// Counter the pUnknownOuter->Release in the Init method.
	IUnknown *pUnknownOuter = this;
	pUnknownOuter->AddRef();
	// Properly release the pointer; there may be per-interface
	// reference counts.
	m_pIY->Release();

	// Release contained component
	if (m_pUnknownInner != NULL) {
		m_pUnknownInner->Release();
	}
}

HRESULT _stdcall CA::Init() {
	// Get the pointer to the outer unknown
	// Since this component is not aggregated, the outer unknown
	// is the same as the this pointer
	IUnknown *pUnknownOuter = this;
	trace("Create inner component. ");
	HRESULT hr = ::CoCreateInstance(
		CLSID_Component2,
		pUnknownOuter,
		CLSCTX_INPROC_SERVER,
		IID_IUnknown,
		(LPVOID *)&m_pUnknownInner);
	if (FAILED(hr)) {
		trace("Could not create contained component");
		return E_FAIL;
	}

	// This call will cncrement the reference count on the outer component
	trace("Get the IY interface from the inner component. ");
	hr = m_pUnknownInner->QueryInterface(IID_IY, (LPVOID *)&m_pIY);
	if (FAILED(hr)) {
		trace("Inner component does not support interface IY. ");
		m_pUnknownInner->Release();
		return E_FAIL;
	}

	pUnknownOuter->Release();
	return S_OK;
}

HRESULT _stdcall CA::QueryInterface(REFIID riid, LPVOID *ppv) {
	if (riid == IID_IUnknown) {
		*ppv = static_cast<IUnknown *>(this);
	} else if (riid == IID_IX) {
		*ppv = static_cast<IX *>(this);
	} else if (riid == IID_IY) {
		trace("Return inner component's IY interface");
#ifndef _0
		return m_pUnknownInner->QueryInterface(riid, ppv);
#else
		*ppv = m_pIY;
#endif
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

//////////////////////////
// Class Factory
//////////////////////////

class CFactory : public IClassFactory {
public:
	virtual HRESULT _stdcall QueryInterface(REFIID riid, LPVOID *ppv);
	virtual ULONG _stdcall AddRef();
	virtual ULONG _stdcall Release();

	virtual HRESULT _stdcall CreateInstance(IUnknown *pUnkOuter, REFIID riid, LPVOID *ppv);
	virtual HRESULT _stdcall LockServer(BOOL bLock);

	CFactory() : m_cRef(1) {}
	~CFactory() {}
private:
	long m_cRef;
};

HRESULT _stdcall CFactory::QueryInterface(REFIID riid, LPVOID *ppv) {
	if (riid != IID_IClassFactory && riid != IID_IUnknown) {
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	// @N
	IUnknown *pI = static_cast<IClassFactory *>(this);
	pI->AddRef();
	*ppv = pI;
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

HRESULT _stdcall CFactory::CreateInstance(IUnknown *pUnkOuter, REFIID riid, LPVOID *ppv) {
	HRESULT hr;

	if (pUnkOuter != NULL) {
		return CLASS_E_NOAGGREGATION;
	}

	CA *pA = new CA;
	if (pA == NULL) {
		return E_OUTOFMEMORY;
	}

	hr = pA->Init();
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
	if (g_cComponents == 0 && g_cServerLocks == 0) {
		return S_OK;
	} else {
		return S_FALSE;
	}
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv) {
	if (rclsid != CLSID_Component1) {
		return CLASS_E_CLASSNOTAVAILABLE;
	}

	CFactory *pFactory = new CFactory;
	if (pFactory == NULL) {
		return E_OUTOFMEMORY;
	}

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
		g_szProgID);
}

STDAPI DllUnregisterServer() {
	return UnregisterServer(
		CLSID_Component1,
		g_szVerIndProgID,
		g_szProgID);
}

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		g_hModule = (HMODULE)hModule;
	}
    return TRUE;
}
