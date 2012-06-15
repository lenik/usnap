// MyCom2.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#define INITGUID
#include <objbase.h>
#include <winerror.h>

#include "MyCom2.h"

static ULONG	g_bLock		= 0;

class MyCom2_Class1_Interface1_Imp1 : public IMyCom2_Class1_Interface1 {
public:
	MyCom2_Class1_Interface1_Imp1();
public:
	STDMETHOD(QueryInterface)(REFIID, LPVOID *);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();

	STDMETHOD(Popup)();
protected:
	ULONG	m_cRef;
};

typedef MyCom2_Class1_Interface1_Imp1
	*PMyCom2_Class1_Interface1_Imp1,
	*LPMyCom2_Class1_Interface1_Imp1;

MyCom2_Class1_Interface1_Imp1::MyCom2_Class1_Interface1_Imp1() : m_cRef(0) {
}

STDMETHODIMP MyCom2_Class1_Interface1_Imp1::QueryInterface(REFIID riid, LPVOID *ppv) {
	if (riid == IID_IUnknown) {
		*ppv	= this;
	} else if (riid == IID_IMyCom2_Class1_Interface1) {
		*ppv	= this;
	} else {
		*ppv	= NULL;
		return E_NOINTERFACE;
	}
	((LPUNKNOWN)*ppv)->AddRef();
	return NOERROR;
}

STDMETHODIMP_(ULONG) MyCom2_Class1_Interface1_Imp1::AddRef() {
	m_cRef++;
	return m_cRef;
}

STDMETHODIMP_(ULONG) MyCom2_Class1_Interface1_Imp1::Release() {
	m_cRef--;
	if (m_cRef == 0) {
		delete this;
		return 0;
	}
	return m_cRef;
}

STDMETHODIMP MyCom2_Class1_Interface1_Imp1::Popup() {
	MessageBox(NULL, "MyCom2_Class1_Interface1_Imp1::Popup()", "Imp1", MB_OK);
	return NOERROR;
}

class MyCom2_Class1_Factory : public IClassFactory {
public:
	MyCom2_Class1_Factory();
public:
	STDMETHOD(QueryInterface)(REFIID, LPVOID *);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();
	STDMETHOD(CreateInstance)(LPUNKNOWN, REFIID, LPVOID *);
	STDMETHOD(LockServer)(BOOL);
protected:
	ULONG m_cRef;
};

typedef MyCom2_Class1_Factory
	*PMyCom2_Class1_Factory,
	*LPMyCom2_Class1_Factory;

MyCom2_Class1_Factory::MyCom2_Class1_Factory() : m_cRef(0) {
}

STDMETHODIMP MyCom2_Class1_Factory::QueryInterface(REFIID riid, LPVOID *ppv) {
	if (riid == IID_IUnknown) {
		*ppv	= this;
	} else if (riid == IID_IClassFactory) {
		*ppv	= this;
	} else {
		*ppv	= NULL;
		return E_NOINTERFACE;
	}
	((LPUNKNOWN)*ppv)->AddRef();
	return NOERROR;
}

STDMETHODIMP_(ULONG) MyCom2_Class1_Factory::AddRef() {
	return ++m_cRef;
}

STDMETHODIMP_(ULONG) MyCom2_Class1_Factory::Release() {
	m_cRef--;
	if (m_cRef == 0) {
		delete this;
		return 0;
	}
	return m_cRef;
}

STDMETHODIMP MyCom2_Class1_Factory::LockServer(BOOL bLock) {
	g_bLock	+= bLock ? 1 : -1;
	return NOERROR;
}

STDMETHODIMP MyCom2_Class1_Factory::CreateInstance(LPUNKNOWN pUnkOuter, REFIID riid, LPVOID *ppv) {
	if (pUnkOuter != NULL && riid != IID_IUnknown) {
		return CLASS_E_NOAGGREGATION;
	}

	if (riid == IID_IClassFactory) {
		LPCLASSFACTORY	pIClassFactory =
			(LPCLASSFACTORY)(new MyCom2_Class1_Factory);

		HRESULT	hr	= pIClassFactory->QueryInterface(riid, ppv);
		if (FAILED(hr)) {
			delete pIClassFactory;
			return hr;
		}
		return NOERROR;
	} else if (riid == IID_IDropTarget) {
		*ppv	= this;
	} else {
		LPMyCom2_Class1_Interface1_Imp1
			newInst	= new MyCom2_Class1_Interface1_Imp1;

		HRESULT	hr	= newInst->QueryInterface(riid, ppv);
		if (FAILED(hr)) {
			delete newInst;
			return hr;
		}
	}

	return NOERROR;
}

STDAPI	DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv) {
	HRESULT			hr;
	LPMyCom2_Class1_Factory	pClass1Factory	= NULL;

	if (rclsid != CLSID_MyCom2_Class1) {
		return E_FAIL;
	}

	pClass1Factory	= new MyCom2_Class1_Factory;
	hr		= pClass1Factory->QueryInterface(riid, ppv);

	if (FAILED(hr)) {
		delete pClass1Factory;
		return hr;
	}
	return NOERROR;
}

STDAPI	DllCanUnloadNow() {
	return g_bLock == 0 ? S_OK : S_FALSE;
}

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	return TRUE;
}
