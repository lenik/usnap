
#pragma once

#include <sgp/sgpdef.h>

SGP_BEGIN


///////////////////////////////////////////////////////////////////////////////

//
template<class _t> inline _t _min(_t a, _t b);
template<class _t> inline _t _max(_t a, _t b);
template<class _t> inline int _cmp(_t a, _t b);
template<class _t> inline int _sgn(_t a);

// real --> integer
template<class _rt = double, class _it = int>
inline _it _lle(_rt a);		// largest & less equal

template<class _rt = double, class _it = int>
inline _it _sge(_rt a);		// smallest & greater equal

template<class _rt = double, class _it = int>
inline _it _ll(_rt a);		// largest & less

template<class _rt = double, class _it = int>
inline _it _sg(_rt a);		// smallest & greater



///////////////////////////////////////////////////////////////////////////////
//
// implementation
//
//
template<class _t> inline _t _min(_t a, _t b) {
	return a < b ? a : b;
}
template<class _t> inline _t _max(_t a, _t b) {
	return a > b ? a : b;
}
template<class _t> inline int _cmp(_t a, _t b) {
	return _sgn(a - b);
}
template<class _t> inline int _sgn(_t a) {
	if (a > 0) {
		return 1;
	} else if (a < 0) {
		return -1;
	}
	return 0;
}

template<class _rt = double, class _it = int>
inline _it _lle(_rt a) {
	return floor(a);
}

template<class _rt = double, class _it = int>
inline _it _sge(_rt a) {
	return ceil(a);
	return -_lle(-a);	//
}

template<class _rt = double, class _it = int>
inline _it _ll(_rt a) {
	return _sge<_rt, _it>(a) - 1;
	return -_lle(-a) - 1;	//
}

template<class _rt = double, class _it = int>
inline _it _sg(_rt a) {
	return _lle(x + 1);
}



SGP_END
