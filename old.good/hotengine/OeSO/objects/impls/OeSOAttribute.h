
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "objects/OeSOAttribute.h"

// 属性类保存一个属性.
// CLSID: 00000000-4F45-0620-0002-486954656368

OeSOAttribute::OeSOAttribute() {}

OeSOAttribute::~OeSOAttribute() {}


STDMETHODIMP
OeSOAttribute::get_name(BSTR *ret) {
	*ret	= m_name.copy();
	return S_OK;
}

STDMETHODIMP
OeSOAttribute::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}

STDMETHODIMP
OeSOAttribute::get_value(VARIANT *ret) {
	*ret	= m_value;
	return S_OK;
}

STDMETHODIMP
OeSOAttribute::put_value(VARIANT value) {
	m_value	= value;
	Fire_onChanged();
	return S_OK;
}


STDMETHODIMP_(void)
OeSOAttribute::Fire_onChanged() {
	int i, n = m_vec.GetSize();
	for (i = 0; i < n; i++) {
		CComPtr<IUnknown> sp = m_vec.GetAt(n);
		IDispatch *pDispatch = (IDispatch *)sp.p;
		if (pDispatch != NULL) {
			DISPPARAMS disp = { NULL, NULL, 0, 0 };
			pDispatch->Invoke(
				DISPID_IOeSOAttribute_onChanged,
				IID_NULL,
				LOCALE_USER_DEFAULT,
				DISPATCH_METHOD,
				&disp, NULL, NULL, NULL);
		}
	}
}
