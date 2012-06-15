
#include "StdAfx.h"

#include "resource.h"

#include "OeSO.h"
#include "OeSODeclares.h"

// 对象类存放一个具体的对象。
// CLSID: 00000000-4F45-0610-0002-486954656368

OeSOObject::OeSOObject() {
	this->~OeSOObject();
}
//<comdef.h>
OeSOObject::~OeSOObject() {
	this->m_inited		= FALSE;
	this->m_name		= (LPCTSTR)NULL;
	this->m_attributes	= NULL;
	this->m_methods		= NULL;
	this->m_events		= NULL;
	this->m_pOfclass	= NULL;
}


STDMETHODIMP
OeSOObject::get_name(BSTR *ret) {
	if (this->m_inited) {
		*ret	= m_name.copy();
		return S_OK;
	} else {
		return E_FAIL;
	}
}

STDMETHODIMP
OeSOObject::put_name(BSTR newname) {
	this->m_name	= newname;
	this->m_inited	= newname != NULL;
	return S_OK;
}

/*
 * attributes(属性集)是类属性集和对象属性集的全集, 必须动态生成.
 * 而且是只读的.
 */
STDMETHODIMP
OeSOObject::get_attributes(IOeSOAttributesCollection **ret) {
	IOeSOAttributesCollection *pAllAttributes;
	pAllAttributes	= new COeSOAttributesCollection;
	pAllAttributes->AddRef();
	//pAllAttributes->combine(m_pOfclass->m_pAttributes);
	pAllAttributes->combine(this->m_attributes);
	*ret	= pAllAttributes;
	return S_OK;
}

STDMETHODIMP
OeSOObject::get_attributesObject(IOeSOAttributesCollection **ret) {
	*ret	= (IOeSOAttributesCollection *)m_attributes;
	return S_OK;
}

STDMETHODIMP
OeSOObject::put_attributesObject(IOeSOAttributesCollection *newattributes) {
	m_attributes	= (COeSOAttributesCollection *)newattributes;
	return S_OK;
}

STDMETHODIMP
OeSOObject::get_methods_(IOeSOMethodsCollection **ret) {
	*ret	= (IOeSOMethodsCollection *)m_methods;
	return S_OK;
}

STDMETHODIMP
OeSOObject::put_methods_(IOeSOMethodsCollection *newmethods) {
	m_methods	= (COeSOMethodsCollection *)newmethods;
	return S_OK;
}

STDMETHODIMP
OeSOObject::get_events_(IOeSOEventsCollection **ret) {
	*ret	= (IOeSOEventsCollection *)m_events;
	return S_OK;
}

STDMETHODIMP
OeSOObject::put_events_(IOeSOEventsCollection *newevents) {
	m_events	= (COeSOEventsCollection *)newevents;
	return S_OK;
}

STDMETHODIMP
OeSOObject::get_ofclass(IOeSOClass **ret) {
	*ret	= (IOeSOClass *)m_pOfclass;
	return S_OK;
}

STDMETHODIMP
OeSOObject::put_ofclass(IOeSOClass *newclass) {
	m_pOfclass	= (OeSOClass *)newclass;
	return S_OK;
}
