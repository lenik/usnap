
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// ״̬������һ��״̬��һ��״̬�ж��״ֵ̬��״ֵ̬����Ӧ��һ��״̬��ʾ�ࡣ
// CLSID: 00000000-4F45-0613-0002-486954656368

OeSOStatus::OeSOStatus() {}

OeSOStatus::~OeSOStatus() {}


STDMETHODIMP
OeSOStatus::get_name(BSTR *ret) {
	*ret	= m_name.copy();
	return S_OK;
}

STDMETHODIMP
OeSOStatus::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}
