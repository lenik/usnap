
#include "StdAfx.h"
#include "resource.h"
#include "OeT_types.h"


OeTCodedStream::OeTCodedStream() {
	this->m_parthcode	= L"#";
	this->m_partlcode	= L"#1,(#1,)";
}

OeTCodedStream::~OeTCodedStream() {}

STDMETHODIMP
OeTCodedStream::get_contents(BSTR *ret) {
	*ret	= L"#5,hello";
	return S_OK;
}

STDMETHODIMP
OeTCodedStream::put_contents(BSTR newcontents) {
	//...
	return S_OK;
}

STDMETHODIMP
OeTCodedStream::get_part(VARIANT whichpart, BSTR *ret) {
	return S_OK;
}

STDMETHODIMP
OeTCodedStream::put_part(VARIANT whichpart, BSTR newpart) {
	return S_OK;
}

STDMETHODIMP
OeTCodedStream::get_part_(VARIANT whichpart, BSTR *ret) {
	return S_OK;
}

STDMETHODIMP
OeTCodedStream::put_part_(VARIANT whichpart, BSTR newpart_) {
	return S_OK;
}

STDMETHODIMP
OeTCodedStream::get_parthcode(BSTR *ret) {
	*ret	= this->m_parthcode.copy();
	return S_OK;
}

STDMETHODIMP
OeTCodedStream::put_parthcode(BSTR newparthcode) {
	this->m_parthcode	= newparthcode;
	return S_OK;
}

STDMETHODIMP
OeTCodedStream::get_partlcode(BSTR *ret) {
	*ret	= this->m_partlcode.copy();
	return S_OK;
}

STDMETHODIMP
OeTCodedStream::put_partlcode(BSTR newpartlcode) {
	this->m_partlcode	= newpartlcode;
	return S_OK;
}
