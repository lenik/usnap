
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// 事件集合类
// CLSID: 00000000-4F45-0642-0002-486954656368

OeSOEventsCollection::OeSOEventsCollection() {}

OeSOEventsCollection::~OeSOEventsCollection() {}


STDMETHODIMP
OeSOEventsCollection::get_name(BSTR *ret) {
	*ret	= m_name.copy();
	return S_OK;
}

STDMETHODIMP
OeSOEventsCollection::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}


STDMETHODIMP
OeSOEventsCollection::get_member(VARIANT whichmember, IOeSOEvent **ret) {
	return NOERROR;
}
