
#include "StdAfx.h"

#include "resource.h"

#include "ComTool.h"
#include "CaCTools.h"

CaCTools::CaCTools() {}

CaCTools::~CaCTools() {}

STDMETHODIMP
CaCTools::get_progid(BSTR *ret) {
	LPOLESTR s;
	HRESULT hr = ProgIDFromCLSID(m_clsid, &s);
	if (SUCCEEDED(hr)) {
		*ret	= SysAllocString(s);
	} else {
		*ret	= NULL;
	}
	return hr;
}
STDMETHODIMP
CaCTools::put_progid(BSTR progid) {
	return CLSIDFromProgID((LPCOLESTR)progid, &m_clsid);
}

STDMETHODIMP
CaCTools::get_clsid(BSTR *ret) {
	LPOLESTR s;
	HRESULT hr = StringFromCLSID(m_clsid, &s);
	if (SUCCEEDED(hr)) {
		*ret	= SysAllocString(s);
	} else {
		*ret	= NULL;
	}
	return hr;
}
STDMETHODIMP
CaCTools::put_clsid(BSTR clsid) {
	return CLSIDFromString((LPOLESTR)clsid, &m_clsid);
}

STDMETHODIMP
CaCTools::get_iid(BSTR *ret) {
	LPOLESTR s;
	HRESULT hr = StringFromIID(m_iid, &s);
	if (SUCCEEDED(hr)) {
		*ret	= SysAllocString(s);
	} else {
		*ret	= NULL;
	}
	return hr;
}
STDMETHODIMP
CaCTools::put_iid(BSTR iface) {
	return IIDFromString((LPOLESTR)iface, &m_iid);
}


STDMETHODIMP
CaCTools::createObject(BOOL forceCreate, IDispatch **ret) {
	HRESULT	hr;
	hr = CoCreateInstance(m_clsid, NULL, CLSCTX_ALL, IID_IDispatch, (LPVOID *)ret);
	return forceCreate ? NOERROR : hr;
}

STDMETHODIMP
CaCTools::createObject2(BOOL forceCreate, IDispatch **ret) {
	HRESULT	hr;
	hr = CoCreateInstance(m_clsid, NULL, CLSCTX_ALL, m_iid, (LPVOID *)ret);
	return forceCreate ? NOERROR : hr;
}


STDMETHODIMP
CaCTools::createObjectByProgid(BSTR strProgid, BOOL forceCreate, IDispatch **ret) {
	HRESULT	hr;
	CLSID	clsid;
	hr = CLSIDFromProgID((LPOLESTR)strProgid, &clsid);
	if (FAILED(hr)) return hr;
	hr = CoCreateInstance(clsid, NULL, CLSCTX_ALL, IID_IDispatch, (LPVOID *)ret);
	return forceCreate ? NOERROR : hr;
}

STDMETHODIMP
CaCTools::createObjectByProgid2(BSTR strProgid, BSTR strIid, BOOL forceCreate, IDispatch **ret) {
	HRESULT	hr;
	CLSID	clsid;
	IID	iid;
	hr = CLSIDFromProgID((LPOLESTR)strProgid, &clsid);
	if (FAILED(hr)) return hr;
	hr = IIDFromString((LPOLESTR)strIid, &iid);
	hr = CoCreateInstance(clsid, NULL, CLSCTX_ALL, iid, (LPVOID *)ret);
	return forceCreate ? NOERROR : hr;
}


STDMETHODIMP
CaCTools::createObjectByClsid(BSTR strClsid, BOOL forceCreate, IDispatch **ret) {
	HRESULT	hr;
	CLSID	clsid;
	hr = CLSIDFromString((LPOLESTR)strClsid, &clsid);
	if (FAILED(hr)) return hr;
	hr = CoCreateInstance(clsid, NULL, CLSCTX_ALL, IID_IDispatch, (LPVOID *)ret);
	return forceCreate ? NOERROR : hr;
}

STDMETHODIMP
CaCTools::createObjectByClsid2(BSTR strClsid, BSTR strIid, BOOL forceCreate, IDispatch **ret) {
	HRESULT	hr;
	CLSID	clsid;
	IID	iid;
	hr = CLSIDFromString((LPOLESTR)strClsid, &clsid);
	if (FAILED(hr)) return hr;
	hr = IIDFromString((LPOLESTR)strIid, &iid);
	hr = CoCreateInstance(clsid, NULL, CLSCTX_ALL, iid, (LPVOID *)ret);
	return forceCreate ? NOERROR : hr;
}

STDMETHODIMP
CaCTools::get_reference(IUnknown *obj, LONG *ret) {
	if (obj != NULL) {
		obj->AddRef();
		*ret	= (LONG)obj->Release();
	} else {
		*ret	= 0;
		//return E_FAIL;
	}
	return S_OK;
}

STDMETHODIMP
CaCTools::forceAddRef(IUnknown *obj, LONG *ret) {
	if (obj == NULL) return E_FAIL;
	*ret	= obj->AddRef();
	return S_OK;
}

STDMETHODIMP
CaCTools::forceRelease(IUnknown *obj, LONG *ret) {
	if (obj == NULL) return E_FAIL;
	*ret	= obj->Release();
	return S_OK;
}

STDMETHODIMP
CaCTools::forceQueryInterface(IUnknown *obj, BSTR iid, IUnknown **ppv, HRESULT *ret) {
	IID	riid;
	HRESULT	hr;
	if (obj == NULL) return E_FAIL;
	hr	= IIDFromString(iid, &riid);
	if (FAILED(hr)) return hr;

	*ret	= obj->QueryInterface(riid, (LPVOID *)ppv);
	return S_OK;
}

STDMETHODIMP
CaCTools::forceGetTypeInfoCount(IDispatch *obj, LONG *ret) {
	if (obj == NULL) return E_FAIL;
	return obj->GetTypeInfoCount((UINT *)ret);
}

STDMETHODIMP
CaCTools::forceGetTypeInfo(IDispatch *obj, LONG iTInfo, LONG lcid, IDispatch **ret) {
	if (obj == NULL) return E_FAIL;
	return obj->GetTypeInfo(iTInfo, lcid, (ITypeInfo **)ret);
}

STDMETHODIMP
CaCTools::forceGetIDsOfNames(IDispatch *obj, BSTR iid, BSTR *rgszNames, LONG cNames, LONG lcid, LONG *ret) {
	*ret	= 0;
	return E_NOTIMPL;
}

STDMETHODIMP
CaCTools::forceGetIDOfName(IDispatch *obj, BSTR iid, BSTR szName, LONG lcid, LONG *ret) {
	UINT	cNames = 1;
	IID	riid;
	HRESULT	hr;
	DISPID	rgDispId;

	if (obj == NULL) return E_FAIL;
	hr	= IIDFromString(iid, &riid);
	if (FAILED(hr)) return hr;

	hr	= obj->GetIDsOfNames(riid, &szName, cNames, lcid, &rgDispId);
	if (FAILED(hr)) {
		*ret	= -1;
		return E_FAIL;
	}
	*ret	= (LONG)rgDispId;
	return S_OK;
}
