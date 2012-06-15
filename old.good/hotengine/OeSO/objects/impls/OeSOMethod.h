
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// ��������������һ��������������������ͨ����д�򵥴��롢���ýű������ӳ�䵽�������ϡ�
// CLSID: 00000000-4F45-0621-0002-486954656368

OeSOMethod::OeSOMethod() {}

OeSOMethod::~OeSOMethod() {}


STDMETHODIMP
OeSOMethod::get_name(BSTR *ret) {
	*ret	= m_name.copy();
	return S_OK;
}

STDMETHODIMP
OeSOMethod::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}
