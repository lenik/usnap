
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// 事件类用于建立事件映射。
// CLSID: 00000000-4F45-0622-0002-486954656368

OeSOEvent::OeSOEvent() {}

OeSOEvent::~OeSOEvent() {}


STDMETHODIMP
OeSOEvent::get_name(BSTR *ret) {
	*ret	= m_name.copy();
	return S_OK;
}

STDMETHODIMP
OeSOEvent::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}
