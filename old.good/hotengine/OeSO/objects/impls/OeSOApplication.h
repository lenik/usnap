
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// 应用体类, 管理类和接口集合
// CLSID: 00000000-4F45-0660-0002-486954656368

OeSOApplication::OeSOApplication() {
	this->m_objects		= new COeSOObjectsCollection;
	this->m_interfaces	= new COeSOInterfacesCollection;
	this->m_classes		= new COeSOClassesCollection;
	this->m_statuses	= new COeSOStatusesCollection;
}

OeSOApplication::~OeSOApplication() {
	if (this->m_objects != NULL) delete this->m_objects;
	if (this->m_interfaces != NULL) delete this->m_interfaces;
	if (this->m_classes != NULL) delete this->m_classes;
	if (this->m_statuses != NULL) delete this->m_statuses;
}

STDMETHODIMP
OeSOApplication::get_name(BSTR *ret) {
	*ret	= m_name.copy();
	return S_OK;
}

STDMETHODIMP
OeSOApplication::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}

STDMETHODIMP
OeSOApplication::get_objects(VARIANT whichclass, IOeSOObjectsCollection **ret) {
	return S_OK;
}

STDMETHODIMP
OeSOApplication::get_interfaces(IOeSOInterfacesCollection **ret) {
	*ret	= (IOeSOInterfacesCollection *)m_interfaces;
	m_interfaces->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOApplication::get_classes(IOeSOClassesCollection **ret) {
	*ret	= (IOeSOClassesCollection *)m_classes;
	m_classes->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOApplication::get_statuses(IOeSOStatusesCollection **ret) {
	*ret	= (IOeSOStatusesCollection *)m_statuses;
	m_statuses->AddRef();
	return S_OK;
}
