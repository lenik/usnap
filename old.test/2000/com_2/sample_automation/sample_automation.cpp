// sample_automation.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#define INITGUID
#include <objbase.h>
#include <winerror.h>

//DEFINE_GUID(IID_NULL, 0x00000000, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
DEFINE_GUID(IID_NULL, 0,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0);


class CComVariant : public VARIANT {
public:
	CComVariant() {};
	CComVariant(VARIANT v) : VARIANT(v) {};
	CComVariant(BSTR bstr) {
		vt	= VT_BSTR;
		bstrVal	= bstr;
	};
};

class Automation {
public:
	HRESULT		hresult;
	LPDISPATCH	pdisp;
	EXCEPINFO	excepinfo;
	UINT		uArgErr;

	Automation();
	Automation(const Automation &rhs);
	virtual ~Automation();

	Automation &	operator = (const Automation &rhs);

	HRESULT		CreateObject(WCHAR *str);
	HRESULT		GetObject(WCHAR *str);

	CComVariant	Invoke(WCHAR *str, VARIANT *var = NULL,
				unsigned int cArgs = 0);
	CComVariant	Get(WCHAR *str);

	HRESULT		Put(WCHAR *str, CComVariant &var);
};

inline	Automation::Automation() : pdisp(NULL), hresult(S_OK) {}
inline	Automation::Automation(const Automation &rhs) : pdisp(rhs.pdisp), hresult(rhs.hresult) {
	if (pdisp == NULL) {
		hresult	= DISP_E_EXCEPTION;
	}
	pdisp->AddRef();
}

inline	Automation::~Automation() {
	if (pdisp != NULL) {
		pdisp->Release();
		pdisp	= NULL;
	}
}

inline Automation &	Automation::operator = (const Automation &rhs) {
	if (pdisp != NULL) {
		pdisp->Release();
		pdisp	= NULL;
	}
	pdisp	= rhs.pdisp;
	hresult	= rhs.hresult;
	pdisp->AddRef();
	return *this;
}

inline HRESULT	Automation::GetObject(WCHAR *str) {
	if (pdisp != NULL) {
		pdisp->Release();
		pdisp	= NULL;
	}
	CLSID	clsid;
	hresult	= CLSIDFromProgID(str, &clsid);
	if (hresult) {
		return hresult;
	}

	LPUNKNOWN	punk;
	hresult	= ::GetActiveObject(clsid, NULL, &punk);
	if (hresult) {
		return hresult;
	}

	hresult	= punk->QueryInterface(IID_IDispatch, (LPVOID *)&pdisp);
	if (hresult) {
		return hresult;
	}

	hresult	= punk->Release();
	return hresult;
}

inline HRESULT	Automation::CreateObject(WCHAR *str) {
	if (pdisp != NULL) {
		pdisp->Release();
		pdisp	= NULL;
	}

	CLSID	clsid;
	hresult	= CLSIDFromProgID(str, &clsid);
	if (hresult) {
		return hresult;
	}

	LPUNKNOWN	punk;
	hresult	= CoCreateInstance(clsid, NULL,
		CLSCTX_SERVER, IID_IUnknown, (LPVOID *)&punk);
	if (hresult) {
		return hresult;
	}

	hresult	= punk->QueryInterface(IID_IDispatch, (LPVOID *)&pdisp);

	if (hresult) {
		return hresult;
	}

	hresult	= punk->Release();
	return hresult;
}

inline	CComVariant	Automation::Get(WCHAR *str) {
	if (pdisp == NULL) {
		hresult	= DISP_E_EXCEPTION;
		return CComVariant();
	}

	DISPID	dispid;
	hresult	= pdisp->GetIDsOfNames(
		IID_NULL, &str, 1,
		LOCALE_USER_DEFAULT, &dispid);
	if (hresult) {
		return CComVariant();
	}

	DISPPARAMS	dispparams	= { 0 };
	VARIANTARG	variantarg;
	VariantInit(&variantarg);
	memset(&excepinfo, 0, sizeof(EXCEPINFO));
	uArgErr		= 0;
	hresult		= pdisp->Invoke(dispid, IID_NULL,
				LOCALE_USER_DEFAULT,
				DISPATCH_PROPERTYGET,
				&dispparams, &variantarg,
				&excepinfo, &uArgErr);
	if (hresult) {
		return CComVariant();
	}

	return CComVariant(variantarg);
}

inline	HRESULT Automation::Put(WCHAR *str, CComVariant &var) {
	if (pdisp == NULL) {
		hresult	= DISP_E_EXCEPTION;
		return hresult;
	}

	DISPID	dispid;
	hresult	= pdisp->GetIDsOfNames(IID_NULL, &str, 1, LOCALE_USER_DEFAULT, &dispid);

	if (hresult) {
		return hresult;
	}

	DISPPARAMS	dispparams	= { 0 };
	DISPID		x		= DISPID_PROPERTYPUT;
	dispparams.rgvarg		= &var;
	dispparams.rgdispidNamedArgs	= &x;
	dispparams.cArgs		= 1;
	dispparams.cNamedArgs		= 1;
	VARIANTARG	variantarg;
	VariantInit(&variantarg);
	memset(&excepinfo, 0, sizeof(EXCEPINFO));
	uArgErr		= 0;

	if (var.vt == VT_UNKNOWN || var.vt == VT_DISPATCH ||
		(var.vt & VT_ARRAY) || (var.vt & VT_BYREF)) {
		hresult	= pdisp->Invoke(
				dispid,
				IID_NULL,
				LOCALE_USER_DEFAULT,
				DISPATCH_PROPERTYPUTREF,
				&dispparams,
				&variantarg,
				&excepinfo,
				&uArgErr);
		if (SUCCEEDED(hresult)) {
			return hresult;
		}
	}

	hresult	= pdisp->Invoke(
				dispid,
				IID_NULL,
				LOCALE_USER_DEFAULT,
				DISPATCH_PROPERTYPUT,
				&dispparams,
				&variantarg,
				&excepinfo,
				&uArgErr);
	return hresult;
}

inline	CComVariant	Automation::Invoke(WCHAR *str, VARIANT *var, unsigned int cArgs) {
	if (pdisp == NULL) {
		hresult	= DISP_E_EXCEPTION;
		return CComVariant();
	}
	DISPID	dispid;
	hresult	= pdisp->GetIDsOfNames(IID_NULL, &str, 1,
				LOCALE_USER_DEFAULT,
				&dispid);
	if (hresult) {
		return CComVariant();
	}

	DISPPARAMS	dispparams	= { 0 };
	VARIANTARG	variantarg;
	dispparams.rgvarg	= var;
	dispparams.cArgs	= cArgs;
	VariantInit(&variantarg);
	memset(&excepinfo, 0, sizeof(EXCEPINFO));
	uArgErr		= 0;
	hresult		= pdisp->Invoke(
					dispid,
					IID_NULL,
					LOCALE_USER_DEFAULT,
					DISPATCH_METHOD,
					&dispparams,
					&variantarg,
					&excepinfo,
					&uArgErr);
	if (hresult) {
		return CComVariant();
	}

	return CComVariant(variantarg);
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	CoInitialize(NULL);

	Automation	ob;
	ob.CreateObject(L"MyAutomationServer.MyAutomationObject");
	long	l	= ob.Get(L"Hello").lVal;

	CoUninitialize();

	return 0;
}
