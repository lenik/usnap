
#include "StdAfx.h"
#include "resource.h"
#include "OeT_types.h"


OeTChain::OeTChain() {}

OeTChain::~OeTChain() {}


STDMETHODIMP
OeTChain::get_contents(VARIANT *ret) {
	*ret	= _variant_t(this->m_chain.contents);
	return S_OK;
}

STDMETHODIMP
OeTChain::put_contents(VARIANT newcontents) {
	this->m_chain.contents	= newcontents;
	return S_OK;
}


STDMETHODIMP
OeTChain::get_lengthP(int *ret) {
	int		sum	= 0;
	IOeTChain *	pchain	= NULL;
	HRESULT		hr;

	pchain	= this->m_chain.prev;
	*ret	= -1;
	while (pchain != NULL) {
		sum++;
		hr	= pchain->get_p(&pchain);
		if (FAILED(hr)) {
			return hr;
		}
		pchain->Release();
	}

	*ret	= sum;
	return S_OK;
}

STDMETHODIMP
OeTChain::get_lengthN(int *ret) {
	int		sum	= 1;
	IOeTChain *	pchain	= NULL;
	HRESULT		hr;

	pchain	= this->m_chain.next;
	*ret	= -1;
	while (pchain != NULL) {
		sum++;
		hr	= pchain->get_n(&pchain);
		if (FAILED(hr)) {
			return hr;
		}
		pchain->Release();
	}

	*ret	= sum;
	return S_OK;
}


STDMETHODIMP
OeTChain::get_scm(VARIANT_BOOL *ret) {
	*ret	= (VARIANT_BOOL)this->m_scm;
	return S_OK;
}

STDMETHODIMP
OeTChain::put_scm(VARIANT_BOOL newscm) {
	this->m_scm	= (BOOL)newscm;
	return S_OK;
}

STDMETHODIMP
OeTChain::get_useFixedType(VARIANT_BOOL *ret) {
	*ret	= (VARIANT_BOOL)this->m_useFixedType;
	return S_OK;
}

STDMETHODIMP
OeTChain::put_useFixedType(VARIANT_BOOL newbool) {
	this->m_useFixedType	= (BOOL)newbool;
	if (this->m_useFixedType) {
/*		int	length = this->m_members.size();
		for (int i = 0; i < length; i++) {
			if (this->m_members[i].vt != this->m_fixedType) {
				this->m_members[i].ChangeType(this->m_fixedType);
			}
		}
*/	}
	return S_OK;
}

STDMETHODIMP
OeTChain::get_fixedType(VARENUM *ret) {
	*ret	= (VARENUM)this->m_fixedType;
	return S_OK;
}

STDMETHODIMP
OeTChain::put_fixedType(VARENUM newfixedtype) {
	this->m_fixedType	= (VARTYPE)newfixedtype;
	if (this->m_useFixedType) {
/*		int	length = this->m_members.size();
		for (int i = 0; i < length; i++) {
			if (this->m_members[i].vt != this->m_fixedType) {
				this->m_members[i].ChangeType(this->m_fixedType);
			}
		}
*/	}
	return S_OK;
}


STDMETHODIMP
OeTChain::get_p(IOeTChain **ret) {
	if (this->m_chain.prev != NULL) {
		*ret	= this->m_chain.prev;
		(*ret)->AddRef();
		return S_OK;
	}
	*ret	= NULL;
	return E_FAIL;
}

STDMETHODIMP
OeTChain::put_p(IOeTChain *newprev) {
	//
	return S_OK;
}

STDMETHODIMP
OeTChain::get_n(IOeTChain **ret) {
	if (this->m_chain.next != NULL) {
		*ret	= this->m_chain.next;
		(*ret)->AddRef();
		return S_OK;
	}
	*ret	= NULL;
	return E_FAIL;
}

STDMETHODIMP
OeTChain::put_n(IOeTChain *newnext) {
	return S_OK;
}


STDMETHODIMP
OeTChain::get_begin(IOeTChain **ret) {
	IOeTChain	*pchain;
	IOeTChain	*pchainp;
	HRESULT		hr;

	pchain	= (IOeTChain *)this;

	if (pchain != NULL) {
		pchainp	= pchain;
		for (;;) {
			hr	= pchainp->get_p(&pchainp);
			if (FAILED(hr)) {
				*ret	= NULL;
				return hr;
			}
			if (pchainp == NULL) {
				break;
			}
			pchain	= pchainp;
		}
		*ret	= pchain;
		(*ret)->AddRef();
	} else {
		*ret	= NULL;
	}

	return S_OK;
}

STDMETHODIMP
OeTChain::get_end(IOeTChain **ret) {
	return S_OK;
}


STDMETHODIMP
OeTChain::find(VARIANT node, IOeTChain **ret) {
	return S_OK;
}

STDMETHODIMP
OeTChain::next(IOeTChain **ret) {
	return S_OK;
}


STDMETHODIMP
OeTChain::swapBefore() {
	return S_OK;
}

STDMETHODIMP
OeTChain::swapAfter() {
	return S_OK;
}


STDMETHODIMP
OeTChain::remove() {
	return S_OK;
}

STDMETHODIMP
OeTChain::insert(VARIANT newnode) {
	return S_OK;
}

STDMETHODIMP
OeTChain::append(VARIANT newnode) {
	return S_OK;
}


STDMETHODIMP
OeTChain::removeChain(IOeTChain *first, IOeTChain *last) {
	return S_OK;
}

STDMETHODIMP
OeTChain::insertChain(IOeTChain *chain) {

	return S_OK;
}

STDMETHODIMP
OeTChain::appendChain(IOeTChain *chain) {
	return S_OK;
}


STDMETHODIMP
OeTChain::destroy() {
	return S_OK;
}
