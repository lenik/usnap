
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// 类集合类
// CLSID: 00000000-4F45-0632-0002-486954656368

OeSOClassesCollection::OeSOClassesCollection() {}

OeSOClassesCollection::~OeSOClassesCollection() {}


STDMETHODIMP
OeSOClassesCollection::get_name(BSTR *ret) {
	*ret	= m_name.copy();
	return S_OK;
}

STDMETHODIMP
OeSOClassesCollection::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}


STDMETHODIMP
OeSOClassesCollection::get_member(VARIANT whichmember, IOeSOClass **ret) {
	return S_OK;
}
