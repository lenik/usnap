
#include "StdAfx.h"
#include "resource.h"
#include "OeT_types.h"


OeTQueue::OeTQueue() {
}

OeTQueue::~OeTQueue() {}

// IOeTQueue implementation
STDMETHODIMP
OeTQueue::put_outputF(VARIANT newnode) {
	return S_OK;
}

STDMETHODIMP
OeTQueue::put_outputB(VARIANT newnode) {
	return S_OK;
}

STDMETHODIMP
OeTQueue::get_inputF(VARIANT *ret) {
	return S_OK;
}

STDMETHODIMP
OeTQueue::get_inputB(VARIANT *ret) {
	return S_OK;
}

STDMETHODIMP
OeTQueue::get_length(int *ret) {
	return S_OK;
}

STDMETHODIMP
OeTQueue::get_scm(VARIANT_BOOL *ret) {
	return S_OK;
}

STDMETHODIMP
OeTQueue::put_scm(VARIANT_BOOL newscm) {
	return S_OK;
}

STDMETHODIMP
OeTQueue::get_useFixedType(VARIANT_BOOL *ret) {
	return S_OK;
}

STDMETHODIMP
OeTQueue::put_useFixedType(VARIANT_BOOL newBOOL) {
	return S_OK;
}

STDMETHODIMP
OeTQueue::get_fixedType(VARENUM *ret) {
	return S_OK;
}

STDMETHODIMP
OeTQueue::put_fixedType(VARENUM newType) {
	return S_OK;
}

STDMETHODIMP
OeTQueue::get_lockInput(VARIANT_BOOL *ret) {
	*ret	= (VARIANT_BOOL)this->m_lockInput;
	return S_OK;
}

STDMETHODIMP
OeTQueue::put_lockInput(VARIANT_BOOL newlock) {
	this->m_lockInput	= (BOOL)newlock;
	return S_OK;
}


STDMETHODIMP
OeTQueue::destroy() {
	return S_OK;
}


// IOeTChain implementation
STDMETHODIMP
OeTQueue::get_contents(VARIANT *ret) {
	return this->m_pchain->get_contents(ret);
}

STDMETHODIMP
OeTQueue::put_contents(VARIANT newcontents) {
	return this->m_pchain->put_contents(newcontents);
}


STDMETHODIMP
OeTQueue::get_lengthP(int *ret) {
	return this->m_pchain->get_lengthP(ret);
}

STDMETHODIMP
OeTQueue::get_lengthN(int *ret) {
	return this->m_pchain->get_lengthN(ret);
}

STDMETHODIMP
OeTQueue::get_p(IOeTChain **ret) {
	return this->m_pchain->get_p(ret);
}

STDMETHODIMP
OeTQueue::put_p(IOeTChain *newprev) {
	return this->m_pchain->put_p(newprev);
}

STDMETHODIMP
OeTQueue::get_n(IOeTChain **ret) {
	return this->m_pchain->get_n(ret);
}

STDMETHODIMP
OeTQueue::put_n(IOeTChain *newnext) {
	return this->m_pchain->put_n(newnext);
}

STDMETHODIMP
OeTQueue::get_begin(IOeTChain **ret) {
	return this->m_pchain->get_begin(ret);
}

STDMETHODIMP
OeTQueue::get_end(IOeTChain **ret) {
	return this->m_pchain->get_end(ret);
}

STDMETHODIMP
OeTQueue::find(VARIANT node, IOeTChain **ret) {
	return this->m_pchain->find(node, ret);
}

STDMETHODIMP
OeTQueue::next(IOeTChain **ret) {
	return this->m_pchain->next(ret);
}

STDMETHODIMP
OeTQueue::swapBefore() {
	return this->m_pchain->swapBefore();
}

STDMETHODIMP
OeTQueue::swapAfter() {
	return this->m_pchain->swapAfter();
}

STDMETHODIMP
OeTQueue::remove() {
	return this->m_pchain->remove();
}

STDMETHODIMP
OeTQueue::insert(VARIANT newnode) {
	return this->m_pchain->insert(newnode);
}

STDMETHODIMP
OeTQueue::append(VARIANT newnode) {
	return this->m_pchain->append(newnode);
}

STDMETHODIMP
OeTQueue::removeChain(IOeTChain *first, IOeTChain *last) {
	return this->m_pchain->removeChain(first, last);
}

STDMETHODIMP
OeTQueue::insertChain(IOeTChain *chain) {
	return this->m_pchain->insertChain(chain);
}

STDMETHODIMP
OeTQueue::appendChain(IOeTChain *chain) {
	return this->m_pchain->appendChain(chain);
}

/*
STDMETHODIMP
OeTQueue::destroy() {
	return this->m_pchain->destroy();
}
*/
