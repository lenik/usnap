
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// 属性集合类
// CLSID: 00000000-4F45-0640-0002-486954656368

OeSOAttributesCollection::OeSOAttributesCollection() {}

OeSOAttributesCollection::~OeSOAttributesCollection() {}


STDMETHODIMP
OeSOAttributesCollection::get_name(BSTR *ret) {
	*ret	= m_name.copy();
	return S_OK;
}

STDMETHODIMP
OeSOAttributesCollection::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}


STDMETHODIMP
OeSOAttributesCollection::get_member(VARIANT whichmember, IOeSOAttribute **ret) {
	return NOERROR;
}

STDMETHODIMP
OeSOAttributesCollection::put_member(VARIANT whichmember, IOeSOAttribute *newattr) {
	return NOERROR;
}
