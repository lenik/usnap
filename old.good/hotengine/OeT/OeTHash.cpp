
#include "StdAfx.h"
#include "resource.h"
#include "OeT_types.h"


OeTHash::OeTHash() {
	this->m_default	= "--empty--";
}

OeTHash::~OeTHash() {}

STDMETHODIMP
OeTHash::get_value(VARIANT key, BSTR *ret) {
	*ret	= this->m_default.copy();
	if (key.vt & VT_BSTR) {
		int	length = this->m_members.size();
		for (int i = 0; i < length; i++) {
			if (m_members[i].first == (_bstr_t)key.bstrVal) {
				*ret	= m_members[i].second.copy();
				break;
			}
		}
	} else {
		_variant_t	var(key);
		try {
			var.ChangeType(VT_I4);
			if (var.lVal >= this->m_members.size()) {
				return E_FAIL;
			}
			*ret	= m_members[var.lVal].second.copy();
		} catch (_com_error *e) {
			return e->Error();
		}
	}
	return S_OK;
}

STDMETHODIMP
OeTHash::put_value(VARIANT key, BSTR value) {
	bool	bexist = FALSE;
	int	length = this->m_members.size();
	if (key.vt & VT_BSTR) {
		for (int i = 0; i < length; i++) {
			if (m_members[i].first == (_bstr_t)key.bstrVal) {
				m_members[i].second = value;
				bexist	= TRUE;
				break;
			}
		}
		if (!bexist) {
			m_members.resize(length + 1);
			m_members[length].first		= key;
			m_members[length].second	= value;
		}
	} else {
		_variant_t	var(key);
		try {
			var.ChangeType(VT_I4);
			if (var.lVal >= length) {
				if (var.lVal == length) {
					// 索引值处于边界则自动扩展
					this->m_members.resize(length + 1);
					this->m_members[length].first	= "autoname";
					BSTR	autoindex;
					VarBstrFromI4(rand(), 0, 0, &autoindex);
					this->m_members[length].first	+= autoindex;
					this->m_members[length].second	= value;
				} else {
					return E_FAIL;
				}
			} else {
				m_members[var.lVal].second	= value;
			}
		} catch (_com_error *e) {
			return e->Error();
		}
	}
	return S_OK;
}

STDMETHODIMP
OeTHash::get_key(VARIANT key, BSTR *ret) {
	int	length = this->m_members.size();
	*ret	= this->m_default.copy();

	if (key.vt & VT_BSTR) {
		for (int i = 0; i < length; i++) {
			if (m_members[i].first == (_bstr_t)key.bstrVal) {
				*ret	= m_members[i].first.copy();
				break;
			}
		}
	} else {
		_variant_t	var(key);
		try {
			var.ChangeType(VT_I4);
			if (var.lVal < length) {
				*ret	= this->m_members[var.lVal].first.copy();
			}
		} catch (_com_error *e) {
			return e->Error();
		}
	}
	return S_OK;
}

STDMETHODIMP
OeTHash::put_key(VARIANT key, BSTR newkey) {
	bool	bexist = FALSE;
	int	length = this->m_members.size();
	if (key.vt & VT_BSTR) {
		for (int i = 0; i < length; i++) {
			if (m_members[i].first == (_bstr_t)key.bstrVal) {
				m_members[i].first	= newkey;
				bexist	= TRUE;
				break;
			}
		}
		if (!bexist) {
			m_members.resize(length + 1);
			m_members[length].first		= key;
			m_members[length].second	= this->m_default;
		}
	} else {
		_variant_t	var(key);
		try {
			var.ChangeType(VT_I4);
			if (var.lVal >= length) {
				if (var.lVal == length) {
					// 索引值处于边界则自动扩展
					this->m_members.resize(length + 1);
					this->m_members[length].first	= newkey;
					this->m_members[length].second	= this->m_default;
				} else {
					return E_FAIL;
				}
			} else {
				m_members[var.lVal].first	= newkey;
			}
		} catch (_com_error *e) {
			return e->Error();
		}
	}
	return S_OK;
}

STDMETHODIMP
OeTHash::get_count(int *ret) {
	*ret	= this->m_members.size();
	return S_OK;
}

STDMETHODIMP
OeTHash::get_coded(VARIANT key, BSTR *ret) {
	_bstr_t	name;
	BSTR	value1;
	_bstr_t	value;

	HRESULT	hr = this->get_value(key, &value1);
	if (FAILED(hr)) {
		return hr;
	}

	value	= value1;

	if (key.vt & VT_BSTR) {
		name	= key.bstrVal;
	} else {
		try {
			_variant_t	k(key);
			k.ChangeType(VT_I4);
			name	= this->m_members[k.lVal].first;
		} catch (_com_error *e) {
			return e->Error();
		}
	}

	name	= (_bstr_t)"#" + //(_bstr_t)((_variant_t)value.length()) +
			(_bstr_t)"," + name;
	value	= (_bstr_t)"#" + //(_bstr_t)((_variant_t)value.length()) +
			(_bstr_t)"," + value;
	name	+= value;
	*ret	= name.copy();
	return S_OK;
}

STDMETHODIMP
OeTHash::get_def(BSTR *ret) {
	*ret	= this->m_default.copy();
	return S_OK;
}

STDMETHODIMP
OeTHash::put_def(BSTR newdef) {
	this->m_default	= newdef;
	return S_OK;
}


STDMETHODIMP
OeTHash::clear() {
	this->m_members.clear();
	return S_OK;
}

STDMETHODIMP
OeTHash::set(BSTR setstring, BSTR sep) {
	return S_OK;
}

STDMETHODIMP
OeTHash::search(BSTR value, BSTR *ret) {
	return S_OK;
}

STDMETHODIMP
OeTHash::interprete(BSTR text, BSTR prefix, BSTR *ret) {
	return S_OK;
}
