
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// 接口集合类
// CLSID: 00000000-4F45-0631-0002-486954656368

OeSOInterfacesCollection::OeSOInterfacesCollection() {}

OeSOInterfacesCollection::~OeSOInterfacesCollection() {}


STDMETHODIMP
OeSOInterfacesCollection::get_name(BSTR *ret) {
	*ret	= m_name.copy();
	return S_OK;
}

STDMETHODIMP
OeSOInterfacesCollection::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}


STDMETHODIMP
OeSOInterfacesCollection::get_member(VARIANT whichmember, IOeSOInterface **ret) {
	return S_OK;
}
