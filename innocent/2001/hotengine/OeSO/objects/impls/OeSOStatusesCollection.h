
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// ×´Ì¬¼¯ºÏÀà
// CLSID: 00000000-4F45-0633-0002-486954656368

OeSOStatusesCollection::OeSOStatusesCollection() {}

OeSOStatusesCollection::~OeSOStatusesCollection() {}


STDMETHODIMP
OeSOStatusesCollection::get_name(BSTR *ret) {
	*ret	= m_name.copy();
	return S_OK;
}

STDMETHODIMP
OeSOStatusesCollection::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}
