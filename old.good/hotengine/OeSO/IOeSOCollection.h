
#pragma once

template <typename T, const IID *piid, const GUID *plibid = &CComModule::m_libid, WORD wMajor = 1, WORD wMinor = 0, typename tihclass = CComTypeInfoHolder>
class IOeSOCollectionImpl :
	public IDispatchImpl<T, piid, plibid, wMajor, wMinor, tihclass> {
public:
	IOeSOCollectionImpl() {
		this->m_array.CreateInstance(OeTLib::CLSID_OeTArray);

	}
	virtual ~IOeSOCollectionImpl() {
		this->m_array	= NULL;
	}

// IOeSOCollection
public:
	STDMETHOD(clear)() {
		return this->m_array->clear();
	}
	STDMETHOD(combine)(IOeSOCollection *anothercollection) {
		int length;
		anothercollection->get_count(&length);
		for (int i = 0; i < length; i++) {
			IDispatch *anothermember;
			anothercollection->get_member(i, &anothermember);
			this->add(anothermember, -1);
		}
		return S_OK;
	}
	STDMETHOD(add)(IDispatch *addobject, int insertindex) {
		// _variant_t::_variant_t() --> addobject->AddRef()
		return this->m_array->add(_variant_t(addobject), insertindex, 1);
	}
	STDMETHOD(remove)(int removeindex, int removecount) {
		// _variant_t::~_variant_t() --> addobject->Release()
		return this->m_array->remove(removeindex, removecount);
	}

	STDMETHOD(get_count)(int *ret) {
		return this->m_array->count;
	}
	STDMETHOD(get_member)(int index, IDispatch **ret) {
		*ret	= this->m_array->member[index].pdispVal;
		return S_OK;
	}
	STDMETHOD(put_member)(int index, IDispatch *newdisp) {
		this->m_array->member[index]	= _variant_t(newdisp);
		return S_OK;
	}

public:
	_variant_array_t	m_array;
};

/*
template <typename T, const IID *piid, const GUID *plibid = &CComModule::m_libid, WORD wMajor = 1, WORD wMinor = 0, typename tihclass = CComTypeInfoHolder>
typedef CComObject<IOeSOCollectionImpl<T, piid, plibid, wMajor, wMinor, tihclass>>	CIOeSOCollectionImpl;
*/
