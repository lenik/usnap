
//
// POS.hfvc (Version 1)
//

//
// 2003.5.11	HFVC_FIX_D1_MEMBER macro
// 2003.5.10	started


#pragma once

/*
	hfvc defines
*/


namespace pos {

	template<typename _fix_ty>
	inline _fix_ty& hfvc_fix_d1(_fix_ty *_hfvc, _fix_ty _bit_selector) {
		register _fix_ty F = *_hfvc;
		register _fix_ty f = _bit_selector;
		while (F & f) {
			F ^= ~F + 1;
			_hfvc++;
		}
		return *_hfvc;
	}

	template<typename _fix_ty, int _index>
	inline _fix_ty& hfvc_fix_d4(_fix_ty *_hfvc) {
		register _fix_ty F = *_hfvc >> (_index * 4);
		return _hfvc + F;
	}
	template<typename _fix_ty>
	inline _fix_ty& hfvc_fix_d4(_fix_ty *_hfvc, _fix_ty _bit_selector) {
		register _fix_ty _4s = 0xF;
		register _fix_ty F = *_hfvc;
		register _fix_ty f = _bit_selector;
		while (!(_4s & f)) {
			F >>= 4;
			f >>= 4;
		}
		return _hfvc + (F & _4s);
	}


#ifdef __POS__USE_PROPERTY
#define HFVC_MEMBER_AS_PROPERTY(type, name)					\
	__declspec(property(get=_get_hfvc_##name, put=_put_hfvc_##name))	\
	type hfvc_##name;
#else
#define HFVC_MEMBER_AS_PROPERTY(type, name)
#endif

#define HFVC_FIX_D1_MEMBER(type, bit, name)					\
	type m_##name;								\
	HFVC_MEMBER_AS_PROPERTY(type,name)					\
	inline type& _get_hfvc_##name() {					\
		return (type &)hfvc_fix_d1<u32_t>((u32_t *)this, bit);		\
	}									\
	inline void _put_hfvc_##name(type& val) {				\
		_get_hfvc_##name() = val;					\
	}

} // namespace pos
