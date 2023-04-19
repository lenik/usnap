
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// 类类描述一个类。一个类可以实现多个接口，但只能继承一个类。而且继承类与本类不能有重叠接口。类管理所有实例化的对象。
// CLSID: 00000000-4F45-0612-0002-486954656368

OeSOClass::OeSOClass() {
	this->m_pInherits	= NULL;
	this->m_derives		= new COeSOClassesCollection;
	this->m_interfaces	= new COeSOInterfacesCollection;
	this->m_attributes	= new COeSOAttributesCollection;
	this->m_objectAttributes= new COeSOAttributesCollection;
	this->m_methods		= new COeSOMethodsCollection;
	this->m_events		= new COeSOEventsCollection;
	this->m_instances	= new COeSOObjectsCollection;
}

OeSOClass::~OeSOClass() {
	if (this->m_derives != NULL) delete this->m_derives;
	if (this->m_interfaces != NULL) delete this->m_interfaces;
	if (this->m_attributes != NULL) delete this->m_attributes;
	if (this->m_objectAttributes != NULL) delete this->m_objectAttributes;
	if (this->m_methods != NULL) delete this->m_methods;
	if (this->m_events != NULL) delete this->m_events;
	if (this->m_instances != NULL) delete this->m_instances;
}


STDMETHODIMP
OeSOClass::get_name(BSTR *ret) {
	*ret	= m_name.copy();
	return S_OK;
}

STDMETHODIMP
OeSOClass::put_name(BSTR newname) {
	m_name	= newname;
	return S_OK;
}

STDMETHODIMP
OeSOClass::get_attributes(IOeSOAttributesCollection **ret) {
	*ret	 = (IOeSOAttributesCollection *)m_attributes;
	(*ret)->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOClass::get_attributesObject(IOeSOAttributesCollection **ret) {
	*ret	 = (IOeSOAttributesCollection *)m_objectAttributes;
	(*ret)->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOClass::get_methods_(IOeSOMethodsCollection **ret) {
	*ret	= (IOeSOMethodsCollection *)m_methods;
	(*ret)->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOClass::get_events_(IOeSOEventsCollection **ret) {
	*ret	= (IOeSOEventsCollection *)m_events;
	(*ret)->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOClass::get_inherits(IOeSOClass **ret) {
	*ret	= (IOeSOClass *)m_pInherits;
	(*ret)->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOClass::put_inherits(IOeSOClass *newinherits) {
	m_pInherits	= (IOeSOClass *)newinherits;
	newinherits->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOClass::get_derives(IOeSOClassesCollection **ret) {
	*ret	= (IOeSOClassesCollection *)m_derives;
	(*ret)->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOClass::get_interfaces(IOeSOInterfacesCollection **ret) {
	*ret	= (IOeSOInterfacesCollection *)m_interfaces;
	(*ret)->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOClass::get_instances(IOeSOObjectsCollection **ret) {
	*ret	= (IOeSOObjectsCollection *)m_instances;
	(*ret)->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOClass::createObject(BSTR objectname, IOeSOObject **ret) {
	/*
	IOeSOObject	*pObj = new COeSOObject;
	pObj->AddRef();
	pObj->put_name(objectname);
	pObj->attributes->combine(m_pObjectAttributes);
	m_pInstances->add(pObj);
	*ret	= pObj;
	*/
	return S_OK;
}


// obsoluted
STDMETHODIMP
OeSOClass::put_attributes(IOeSOAttributesCollection *newattributes) {
	m_attributes	= (COeSOAttributesCollection *)newattributes;
	newattributes->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOClass::put_attributesObject(IOeSOAttributesCollection *newattributes) {
	m_objectAttributes	= (COeSOAttributesCollection *)newattributes;
	newattributes->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOClass::put_methods_(IOeSOMethodsCollection *newmethods) {
	m_methods	= (COeSOMethodsCollection *)newmethods;
	newmethods->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOClass::put_events_(IOeSOEventsCollection *newevents) {
	m_events	= (COeSOEventsCollection *)newevents;
	newevents->AddRef();
	return S_OK;
}

STDMETHODIMP
OeSOClass::put_interfaces(IOeSOInterfacesCollection *newinterfaces) {
	m_interfaces	 = (COeSOInterfacesCollection *)newinterfaces;
	newinterfaces->AddRef();
	return S_OK;
}
