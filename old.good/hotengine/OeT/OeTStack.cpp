
#include "StdAfx.h"
#include "resource.h"
#include "OeT_types.h"


OeTStack::OeTStack() {}

OeTStack::~OeTStack() {}


// IOeTStack implementation
STDMETHODIMP
OeTStack::push(VARIANT data) {
	return this->m_pqueue->put_outputF(data);
}

STDMETHODIMP
OeTStack::pop(VARIANT *ret) {
	return this->m_pqueue->get_inputF(ret);
}

STDMETHODIMP
OeTStack::get_length(int *ret) {
	return this->m_pqueue->get_length(ret);
}


STDMETHODIMP
OeTStack::get_scm(VARIANT_BOOL *ret) {
	return S_OK;
}

STDMETHODIMP
OeTStack::put_scm(VARIANT_BOOL newscm) {
	return S_OK;
}

STDMETHODIMP
OeTStack::get_useFixedType(VARIANT_BOOL *ret) {
	return S_OK;
}

STDMETHODIMP
OeTStack::put_useFixedType(VARIANT_BOOL newBOOL) {
	return S_OK;
}

STDMETHODIMP
OeTStack::get_fixedType(VARENUM *ret) {
	return S_OK;
}

STDMETHODIMP
OeTStack::put_fixedType(VARENUM newType) {
	return S_OK;
}

STDMETHODIMP
OeTStack::destroy() {
	return this->m_pqueue->destroy();
}


// IOeTQueue implementation
STDMETHODIMP
OeTStack::put_outputF(VARIANT newnode) {
	return this->m_pqueue->put_outputF(newnode);
}

STDMETHODIMP
OeTStack::put_outputB(VARIANT newnode) {
	return this->m_pqueue->put_outputB(newnode);
}

STDMETHODIMP
OeTStack::get_inputF(VARIANT *ret) {
	return this->m_pqueue->get_inputF(ret);
}

STDMETHODIMP
OeTStack::get_inputB(VARIANT *ret) {
	return this->m_pqueue->get_inputB(ret);
}

STDMETHODIMP
OeTStack::get_lockInput(VARIANT_BOOL *ret) {
	return this->m_pqueue->get_lockInput(ret);
}

STDMETHODIMP
OeTStack::put_lockInput(VARIANT_BOOL newlock) {
	return this->m_pqueue->put_lockInput(newlock);
}

// IOeTChain implementation
STDMETHODIMP
OeTStack::get_contents(VARIANT *ret) {
	return this->m_pchain->get_contents(ret);
}

STDMETHODIMP
OeTStack::put_contents(VARIANT newcontents) {
	return this->m_pchain->put_contents(newcontents);
}

STDMETHODIMP
OeTStack::get_lengthP(int *ret) {
	return this->m_pchain->get_lengthP(ret);
}

STDMETHODIMP
OeTStack::get_lengthN(int *ret) {
	return this->m_pchain->get_lengthN(ret);
}

STDMETHODIMP
OeTStack::get_p(IOeTChain **ret) {
	return this->m_pchain->get_p(ret);
}

STDMETHODIMP
OeTStack::put_p(IOeTChain *newprev) {
	return this->m_pchain->put_p(newprev);
}

STDMETHODIMP
OeTStack::get_n(IOeTChain **ret) {
	return this->m_pchain->get_n(ret);
}

STDMETHODIMP
OeTStack::put_n(IOeTChain *newnext) {
	return this->m_pchain->put_n(newnext);
}

STDMETHODIMP
OeTStack::get_begin(IOeTChain **ret) {
	return this->m_pchain->get_begin(ret);
}

STDMETHODIMP
OeTStack::get_end(IOeTChain **ret) {
	return this->m_pchain->get_end(ret);
}

STDMETHODIMP
OeTStack::find(VARIANT node, IOeTChain **ret) {
	return this->m_pchain->find(node, ret);
}

STDMETHODIMP
OeTStack::next(IOeTChain **ret) {
	return this->m_pchain->next(ret);
}

STDMETHODIMP
OeTStack::swapBefore() {
	return this->m_pchain->swapBefore();
}

STDMETHODIMP
OeTStack::swapAfter() {
	return this->m_pchain->swapAfter();
}

STDMETHODIMP
OeTStack::remove() {
	return this->m_pchain->remove();
}

STDMETHODIMP
OeTStack::insert(VARIANT newnode) {
	return this->m_pchain->insert(newnode);
}

STDMETHODIMP
OeTStack::append(VARIANT newnode) {
	return this->m_pchain->append(newnode);
}

STDMETHODIMP
OeTStack::removeChain(IOeTChain *first, IOeTChain *last) {
	return this->m_pchain->removeChain(first, last);
}

STDMETHODIMP
OeTStack::insertChain(IOeTChain *chain) {
	return this->m_pchain->insertChain(chain);
}

STDMETHODIMP
OeTStack::appendChain(IOeTChain *chain) {
	return this->m_pchain->appendChain(chain);
}
