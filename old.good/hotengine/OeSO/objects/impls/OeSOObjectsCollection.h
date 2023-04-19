
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// 对象集合类
// CLSID: 00000000-4F45-0630-0002-486954656368

OeSOObjectsCollection::OeSOObjectsCollection() {}

OeSOObjectsCollection::~OeSOObjectsCollection() {}


STDMETHODIMP
OeSOObjectsCollection::get_name(BSTR *ret) {
	*ret	= m_name.copy();
	return S_OK;
}

STDMETHODIMP
OeSOObjectsCollection::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}


STDMETHODIMP
OeSOObjectsCollection::get_member(VARIANT whichmember, IOeSOObject **ret) {
	return NOERROR;
}
