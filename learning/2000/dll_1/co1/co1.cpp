// co1.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#define INITGUID
#include <objbase.h>
#include <winerror.h>

#include "co1.h"

static ULONG numberBeepObjects = 0;

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

class BeepObject: public IBeep {
	ULONG	refCount;
public:
	BeepObject();
	~BeepObject();

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID *ppvObject);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	STDMETHOD(DoBeep)(THIS_ UINT uAlert);
};

BeepObject::BeepObject() {
	refCount	= 0;
	numberBeepObjects++;
}

BeepObject::~BeepObject() {
	numberBeepObjects--;
}

STDMETHODIMP	BeepObject::QueryInterface(REFIID riid, LPVOID *ppvObject) {
	if (riid == IID_IUnknown || riid == IID_IBeep) {
		*ppvObject	= this;
		AddRef();
		return NOERROR;
	}

	*ppvObject = NULL;
	return ResultFromScode(E_NOINTERFACE);
}

STDMETHODIMP_(ULONG)	BeepObject::AddRef() {
	return ++refCount;
}

STDMETHODIMP_(ULONG)	BeepObject::Release() {
	if (--refCount == 0) {
		delete this;
		return 0;
	}
	return refCount;
}

STDMETHODIMP		BeepObject::DoBeep(UINT uAlert) {
	MessageBeep(uAlert);
	return NOERROR;
}

class BeepClassFactory : public IClassFactory {
public:
	ULONG	refCount;

	BeepClassFactory() { refCount = 0; }

	STDMETHOD(QueryInterface)(REFIID riid, LPVOID *ppvObj);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();

	STDMETHOD(CreateInstance)(LPUNKNOWN pUnkOuter, REFIID riid, LPVOID *ppvObject);
	STDMETHOD(LockServer)(THIS_ BOOL fLock);
};

static BeepClassFactory classFactory;

STDMETHODIMP BeepClassFactory::QueryInterface(REFIID riid, LPVOID *ppvObject) {
	if (riid == IID_IUnknown || riid == IID_IClassFactory) {
		*ppvObject = this;
		AddRef();
		return NOERROR;
	}

	*ppvObject = NULL;
	return ResultFromScode(E_NOINTERFACE);
}

STDMETHODIMP_(ULONG)	BeepClassFactory::AddRef() {
	return ++refCount;
}

STDMETHODIMP_(ULONG)	BeepClassFactory::Release() {
	if (--refCount == 0) {
		//delete this;
		return 0;
	}
	return refCount;
}

STDMETHODIMP	BeepClassFactory::CreateInstance(LPUNKNOWN pUnkOuter, REFIID riid, LPVOID *ppvObject) {
	if (pUnkOuter != NULL) {
		return ResultFromScode(CLASS_E_NOAGGREGATION);
	}

	LPBEEP	pBeep = NULL;
	pBeep	= new BeepObject;
	if (pBeep == NULL) {
		return ResultFromScode(E_OUTOFMEMORY);
	}
	HRESULT hErr = pBeep->QueryInterface(riid, ppvObject);
	if (FAILED(GetScode(hErr))) {
		delete pBeep;
		return ResultFromScode(hErr);
	}

	return NOERROR;
}

STDMETHODIMP	BeepClassFactory::LockServer(BOOL fLock) {
	if (fLock) numberBeepObjects++;
	else numberBeepObjects--;
	return NOERROR;
}

STDAPI	DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv) {
	*ppv = NULL;
	if (rclsid != CLSID_IBeep) return ResultFromScode(E_FAIL);
	if (riid != IID_IUnknown && riid != IID_IClassFactory)
		return ResultFromScode(E_NOINTERFACE);
	*ppv = &classFactory;
	classFactory.AddRef();
	return NOERROR;
}

STDAPI	DllCanUnloadNow() {
	if (numberBeepObjects == 0 && classFactory.refCount == 0)
		return ResultFromScode(S_OK);
	return ResultFromScode(S_FALSE);
}