
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// 方法集合类
// CLSID: 00000000-4F45-0641-0002-486954656368

OeSOMethodsCollection::OeSOMethodsCollection() {}

OeSOMethodsCollection::~OeSOMethodsCollection() {}


STDMETHODIMP
OeSOMethodsCollection::get_name(BSTR *ret) {
	*ret	= m_name.copy();
	return S_OK;
}

STDMETHODIMP
OeSOMethodsCollection::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}


STDMETHODIMP
OeSOMethodsCollection::get_member(VARIANT whichmember, IOeSOMethod **ret) {
	return NOERROR;
}
