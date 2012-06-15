
#include "StdAfx.h"
#include "resource.h"
#include "OeT_types.h"

OeTArray::OeTArray() {
	this->~OeTArray();
}

OeTArray::~OeTArray() {
	this->m_scm		= FALSE;
	this->m_useFixedType	= FALSE;
	this->m_fixedType	= VT_BSTR;
}


STDMETHODIMP
OeTArray::get_member(int index, VARIANT *ret) {
	if (index < 0 || index >= this->m_members.size()) {
		return E_FAIL;
	}
	// >>  *(new _variant_t)  VS  (VARIANT)
	// >>  remember _variant_t inherits from tagVARIANT
	// *ret = *(new _variant_t(this->m_members[index]));
	*ret	= _variant_t(this->m_members[index]);
	return S_OK;
}

STDMETHODIMP
OeTArray::put_member(int index, VARIANT newVARIANT) {
	if (index < 0 || index >= this->m_members.size()) {
		return E_FAIL;
	}
	// >> here, = newVARIANT will allocate space because there exists
	// >> an operator = (tagVARIANT), so do not above.
	this->m_members[index] = newVARIANT;
	if (this->m_useFixedType) {
		this->m_members[index].ChangeType(this->m_fixedType);
	}
	return S_OK;
}

STDMETHODIMP
OeTArray::get_count(int *ret) {
	*ret	= this->m_members.size();
	return S_OK;
}

STDMETHODIMP
OeTArray::get_scm(VARIANT_BOOL *ret) {
	*ret	= (VARIANT_BOOL)this->m_scm;
	return S_OK;
}

STDMETHODIMP
OeTArray::put_scm(VARIANT_BOOL newscm) {
	this->m_scm	= (BOOL)newscm;
	return S_OK;
}

STDMETHODIMP
OeTArray::get_useFixedType(VARIANT_BOOL *ret) {
	*ret	= (VARIANT_BOOL)this->m_useFixedType;
	return S_OK;
}

STDMETHODIMP
OeTArray::put_useFixedType(VARIANT_BOOL newbool) {
	this->m_useFixedType	= (BOOL)newbool;
	if (this->m_useFixedType) {
		int	length = this->m_members.size();
		for (int i = 0; i < length; i++) {
			if (this->m_members[i].vt != this->m_fixedType) {
				this->m_members[i].ChangeType(this->m_fixedType);
			}
		}
	}
	return S_OK;
}

STDMETHODIMP
OeTArray::get_fixedType(VARENUM *ret) {
	*ret	= (VARENUM)this->m_fixedType;
	return S_OK;
}

STDMETHODIMP
OeTArray::put_fixedType(VARENUM newfixedtype) {
	this->m_fixedType	= (VARTYPE)newfixedtype;
	if (this->m_useFixedType) {
		int	length = this->m_members.size();
		for (int i = 0; i < length; i++) {
			if (this->m_members[i].vt != this->m_fixedType) {
				this->m_members[i].ChangeType(this->m_fixedType);
			}
		}
	}
	return S_OK;
}

STDMETHODIMP
OeTArray::add(VARIANT newVARIANT, int insertindex, int insertduplicates) {
	HRESULT hr	= S_OK;

	if (insertindex < 0) insertindex = this->m_members.size();
	if (insertindex > this->m_members.size()) {
		return E_FAIL;
	}

	/* if insert manually */
	/*
		this->m_members.resize(this->m_members.size() + 1);
		// move part to right, so that a space will appeared in the array
		_variant_vector_t::iterator	movefirst =
			this->m_members.begin() + insertindex;
		_variant_vector_t::iterator	movelast =
			this->m_members.end();
		_variant_vector_t::iterator	it;
		for (it = movefirst; it < movelast; it++) {
			// [movefirst,movelast)
			// ...
		}
	*//* else */
		this->m_members.insert(
			(_variant_vector_t::iterator)
				(this->m_members.begin() + insertindex) ,
			(_variant_vector_t::size_type)
				insertduplicates,
			_variant_t()
			);

	for (int i = 0; i < insertduplicates; i++) {
		HRESULT hr1 = this->put_member(insertindex + i, newVARIANT);
		// return the first error if there exists errors
		if (FAILED(hr1) && SUCCEEDED(hr)) {
			hr	= hr1;
		}
	}

	return hr;
}

STDMETHODIMP
OeTArray::remove(int removeindex, int removecount, int *ret_removedcount) {
	*ret_removedcount	= 0;
	if (removeindex < 0 || removeindex >= this->m_members.size()) {
		return E_FAIL;
	}
	if (removecount < 0) return S_OK;
	if (removeindex + removecount > this->m_members.size()) {
		// >> erase: [first, last)
		removecount	= this->m_members.size() - removeindex + 1;
	}
	_variant_vector_t::iterator	first	=
		this->m_members.begin() + removeindex;
	// >> erase: [first, last)
	_variant_vector_t::iterator	last	=
		this->m_members.begin() + (removeindex + removecount);
	this->m_members.erase(first, last);
	*ret_removedcount	= removecount;
	return S_OK;
}

STDMETHODIMP
OeTArray::clear() {
	int	length = this->m_members.size();
	for (int i = 0; i < length; i++) {
		this->m_members[i].Clear();
	}
	this->m_members.clear();
	return S_OK;
}

////////////////////////////////////////////////////////////////////
//
// IOeTChain implementation
//
//
STDMETHODIMP
OeTArray::get_contents(VARIANT *ret) {
	return this->m_pchain->get_contents(ret);
}

STDMETHODIMP
OeTArray::put_contents(VARIANT newcontents) {
	return this->m_pchain->put_contents(newcontents);
}

STDMETHODIMP
OeTArray::get_lengthP(int *ret) {
	return this->m_pchain->get_lengthP(ret);
}

STDMETHODIMP
OeTArray::get_lengthN(int *ret) {
	return this->m_pchain->get_lengthN(ret);
}

STDMETHODIMP
OeTArray::get_p(IOeTChain **ret) {
	return this->m_pchain->get_p(ret);
}

STDMETHODIMP
OeTArray::put_p(IOeTChain *newprev) {
	return this->m_pchain->put_p(newprev);
}

STDMETHODIMP
OeTArray::get_n(IOeTChain **ret) {
	return this->m_pchain->get_n(ret);
}

STDMETHODIMP
OeTArray::put_n(IOeTChain *newnext) {
	return this->m_pchain->put_n(newnext);
}

STDMETHODIMP
OeTArray::get_begin(IOeTChain **ret) {
	return this->m_pchain->get_begin(ret);
}

STDMETHODIMP
OeTArray::get_end(IOeTChain **ret) {
	return this->m_pchain->get_end(ret);
}

STDMETHODIMP
OeTArray::find(VARIANT node, IOeTChain **ret) {
	return this->m_pchain->find(node, ret);
}

STDMETHODIMP
OeTArray::next(IOeTChain **ret) {
	return this->m_pchain->next(ret);
}

STDMETHODIMP
OeTArray::swapBefore() {
	return this->m_pchain->swapBefore();
}

STDMETHODIMP
OeTArray::swapAfter() {
	return this->m_pchain->swapAfter();
}

STDMETHODIMP
OeTArray::remove() {
	return this->m_pchain->remove();
}

STDMETHODIMP
OeTArray::insert(VARIANT newnode) {
	return this->m_pchain->insert(newnode);
}

STDMETHODIMP
OeTArray::append(VARIANT newnode) {
	return this->m_pchain->append(newnode);
}

STDMETHODIMP
OeTArray::removeChain(IOeTChain *first, IOeTChain *last) {
	return this->m_pchain->removeChain(first, last);
}

STDMETHODIMP
OeTArray::insertChain(IOeTChain *chain) {
	return this->m_pchain->insertChain(chain);
}

STDMETHODIMP
OeTArray::appendChain(IOeTChain *chain) {
	return this->m_pchain->appendChain(chain);
}

STDMETHODIMP
OeTArray::destroy() {
	return this->m_pchain->destroy();
}

// debug...
#ifdef __OeTArray_debug
STDMETHODIMP
OeTArray::check() {
	_bstr_t d;
	_bstr_t di;
	int i;
	for (i = 0; i < this->m_count; i++) {
		di	= this->m_members[i];
		d	+= di;
		d	+= _T("\n");
	}
	MessageBox(NULL, d, NULL, 0);
	return S_OK;
}
#endif
