
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// 接口类描述一个接口。接口的实现在类类中。
// CLSID: 00000000-4F45-0611-0002-486954656368

OeSOInterface::OeSOInterface() {
	this->m_pInherits		= NULL;
	this->m_interfaces		= new COeSOInterfacesCollection;
	this->m_derives			= new COeSOInterfacesCollection;
	this->m_methods			= new COeSOMethodsCollection;
	this->m_events			= new COeSOEventsCollection;
}

OeSOInterface::~OeSOInterface() {
	if (this->m_pInherits != NULL) this->m_pInherits->Release();
	if (this->m_interfaces != NULL) delete this->m_interfaces;
	if (this->m_derives != NULL) delete this->m_derives;
	if (this->m_methods != NULL) delete this->m_methods;
	if (this->m_events != NULL) delete this->m_events;
}


STDMETHODIMP
OeSOInterface::get_name(BSTR *ret) {
	*ret	= m_name;
	return S_OK;
}

STDMETHODIMP
OeSOInterface::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}

STDMETHODIMP
OeSOInterface::get_methods_(IOeSOMethodsCollection **ret) {
	*ret	= (IOeSOMethodsCollection *)m_methods;
	return S_OK;
}

STDMETHODIMP
OeSOInterface::get_events_(IOeSOEventsCollection **ret) {
	*ret	= (IOeSOEventsCollection *)m_events;
	return S_OK;
}

STDMETHODIMP
OeSOInterface::get_inherits(IOeSOInterface **ret) {
	*ret	= (IOeSOInterface *)m_pInherits;
	return S_OK;
}

STDMETHODIMP
OeSOInterface::put_inherits(IOeSOInterface *newinherits) {
	m_pInherits	= (OeSOInterface *)newinherits;
	return S_OK;
}

STDMETHODIMP
OeSOInterface::get_interfaces(IOeSOInterfacesCollection **ret) {
	*ret	= (IOeSOInterfacesCollection *)m_interfaces;
	return S_OK;
}

STDMETHODIMP
OeSOInterface::get_derives(IOeSOInterfacesCollection **ret) {
	*ret	= (IOeSOInterfacesCollection *)m_derives;
	return S_OK;
}


// obsolute
STDMETHODIMP
OeSOInterface::put_methods_(IOeSOMethodsCollection *newmethods) {
	m_methods	= (COeSOMethodsCollection *)newmethods;
	return S_OK;
}

STDMETHODIMP
OeSOInterface::put_events_(IOeSOEventsCollection *newevents) {
	m_events	= (COeSOEventsCollection *)newevents;
	return S_OK;
}

STDMETHODIMP
OeSOInterface::put_interfaces(IOeSOInterfacesCollection *newinterfaces) {
	m_interfaces	= (COeSOInterfacesCollection *)newinterfaces;
	return S_OK;
}
