// agc2.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "..\\a1\\IFace.h"
#include "Registry.h"

void trace(LPCTSTR msg) { cout << "Component 2: \t" << msg << endl; }

static HMODULE g_hModule			= NULL;
static LONG g_cComponents			= 0;
static LONG g_cServerLocks			= 0;

const char g_szFriendlyName[]		= "Inside COM, Chapter 8 Example 2, Component 2";
const char g_szVerIndProgID[]		= "InsideCOM.Chap08.Ex02.Cmpnt2";
const char g_szProgID[]				= "InsideCOM.Chap08.Ex02.Cmpnt2.1";

struct INondelegatingUnknown {
	virtual HRESULT _stdcall NondelegatingQueryInterface(REFIID riid, LPVOID *ppv) = 0;
	virtual ULONG _stdcall NondelegatingAddRef() = 0;
	virtual ULONG _stdcall NondelegatingRelease() = 0;
};

class CB : public IY, public INondelegatingUnknown {
public:
	virtual HRESULT _stdcall QueryInterface(REFIID riid, LPVOID *ppv) {
		trace("Delegate QueryInterface");
		return m_pUnknownOuter->QueryInterface(riid, ppv);
	}
	virtual ULONG _stdcall AddRef() {
		trace("Delegate AddRef");
		return m_pUnknownOuter->AddRef();
	}
	virtual ULONG _stdcall Release() {
		trace("Delegate Release");
		return m_pUnknownOuter->Release();
	}

	virtual HRESULT _stdcall NondelegatingQueryInterface(REFIID riid, LPVOID *ppv);
	virtual ULONG _stdcall NondelegatingAddRef();
	virtual ULONG _stdcall NondelegatingRelease();

	virtual void _stdcall Fy() { cout << "Fy" << endl; }

	CB(IUnknown *pUnknownOuter);
	~CB();

private:
	long m_cRef;
	IUnknown *m_pUnknownOuter;
};

HRESULT CB::NondelegatingQueryInterface(REFIID riid, LPVOID *ppv) {
	if (riid == IID_IUnknown) {
		*ppv = static_cast<INondelegatingUnknown *>(this);
	} else if (riid == IID_IY) {
		*ppv = static_cast<IY *>(this);
	} else {
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	reinterpret_cast<IUnknown *>(*ppv)->AddRef();
	return S_OK;
}

ULONG CB::NondelegatingAddRef() {
	return InterlockedIncrement(&m_cRef);
}

ULONG CB::NondelegatingRelease() {
	InterlockedDecrement(&m_cRef);
	if (m_cRef == 0) {
		delete this;
		return 0;
	}
	return m_cRef;
}

CB::CB(IUnknown *pUnknownOuter) {
	::InterlockedIncrement(&g_cComponents);

	if (pUnknownOuter == NULL) {
		trace("Not aggregating; delegate to nondelegating IUnknonwn. ");
		m_pUnknownOuter = reinterpret_cast<IUnknown *>
			(static_cast<INondelegatingUnknown *>(this));
	} else {
		trace("Aggregating; delegate to outer IUnknown. ");
		m_pUnknownOuter = pUnknownOuter;
	}
}

CB::~CB() {
	::InterlockedDecrement(&g_cComponents);
	trace("Destory self. ");
}

class CFactory : public IClassFactory {
public:
	virtual HRESULT _stdcall QueryInterface(REFIID riid, LPVOID *ppv);
	virtual ULONG _stdcall AddRef();
	virtual ULONG _stdcall Release();

	virtual HRESULT _stdcall CreateInstance(IUnknown *pUnknownOuter, REFIID riid, LPVOID *ppv);
	virtual HRESULT _stdcall LockServer(BOOL bLock);

	CFactory() : m_cRef(1) {}
	~CFactory() {}
private:
	long m_cRef;
};

HRESULT _stdcall CFactory::QueryInterface(REFIID riid, LPVOID *ppv) {

	if (riid != IID_IUnknown && riid != IID_IClassFactory) {
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	*ppv = static_cast<IClassFactory *>(this);

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

HRESULT _stdcall CFactory::CreateInstance(IUnknown *pUnkOuter, REFIID riid, LPVOID *ppv) {
	if (pUnkOuter != NULL && riid != IID_IUnknown) {
		return CLASS_E_NOAGGREGATION;
	}

	CB *pB = new CB(pUnkOuter);
	if (pB == NULL) {
		return E_OUTOFMEMORY;
	}

	HRESULT hr = pB->NondelegatingQueryInterface(riid, ppv);
	pB->NondelegatingRelease();

	return hr;
}

HRESULT CFactory::LockServer(BOOL bLock) {
	if (bLock) {
		InterlockedIncrement(&g_cServerLocks);
	} else {
		InterlockedDecrement(&g_cServerLocks);
	}
	return S_OK;
}

STDAPI DllCanUnloadNow() {
	if (g_cServerLocks != 0 || g_cComponents != 0) {
		return S_FALSE;
	}
	return S_OK;
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv) {
	if (rclsid != CLSID_Component2) {
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
		CLSID_Component2,
		g_szFriendlyName,
		g_szVerIndProgID,
		g_szProgID);
}

STDAPI DllUnregisterServer() {
	return UnregisterServer(
		CLSID_Component2,
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
