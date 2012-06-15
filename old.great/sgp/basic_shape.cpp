
#include <sgp/basic_shape.h>

SGP_BEGIN

///////////////////////////////////////////////////////////////////////////////
//
// rect
//
template<class _t, class _rt, class _it>
rect<_t, _rt, _it>::rect() {
	_x0 = _y0 = _x1 = _y1 = 0;
	_concept = auto_adjust;
}

template<class _t, class _rt, class _it>
rect<_t, _rt, _it>::rect(_t x0, _t y0, _t x1, _t y1) {
	_x0 = x0;
	_y0 = y0;
	_x1 = x1;
	_y1 = y1;
	_concept = auto_adjust;
}

template<class _t, class _rt, class _it> _t& rect<_t, _rt, _it>::x0() {
	adjust_to_concept();
	return _x0;
}
template<class _t, class _rt, class _it> _t& rect<_t, _rt, _it>::y0() {
	adjust_to_concept();
	return _y0;
}
template<class _t, class _rt, class _it> _t& rect<_t, _rt, _it>::x1() {
	adjust_to_concept();
	return _x1;
}
template<class _t, class _rt, class _it> _t& rect<_t, _rt, _it>::y1() {
	adjust_to_concept();
	return _y1;
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::left() const {
	return x0();
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::top() const {
	return y0();
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::width() const {
	return x1() - x0() + 1;
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::height() const {
	return y1() - y0() + 1;
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::center_x() const {
	return (x0() + x1()) / 2;
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::center_y() const {
	return (y0() + y1()) / 2;
}

template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::left() {
	adjust_to_concept();
	return x0();
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::top() {
	adjust_to_concept();
	return y0();
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::width() {
	adjust_to_concept();
	return x1() - x0() + 1;
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::height() {
	adjust_to_concept();
	return y1() - y0() + 1;
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::center_x() {
	adjust_to_concept();
	return (x0() + x1()) / 2;
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::center_y() {
	adjust_to_concept();
	return (y0() + y1()) / 2;
}

template<class _t, class _rt, class _it> void rect<_t, _rt, _it>::left(_t v) {
	_x1 = _x1 + v - _x0;
	_x0 = v;
	adjust_to_concept();
}
template<class _t, class _rt, class _it> void rect<_t, _rt, _it>::top(_t v) {
	_y1 = _y1 + v - _y0;
	_y0 = v;
	adjust_to_concept();
}
template<class _t, class _rt, class _it> void rect<_t, _rt, _it>::width(_t v) {
	_x1 = _x0 + v - 1;
	adjust_to_concept();
}
template<class _t, class _rt, class _it> void rect<_t, _rt, _it>::height(_t v) {
	_y1 = _y0 + v - 1;
	adjust_to_concept();
}
template<class _t, class _rt, class _it> void rect<_t, _rt, _it>::center_x(_t v) {
	_t hw = width() / 2;
	_x0 = v - hw;
	_x1 = v + hw;
	adjust_to_concept();
}
template<class _t, class _rt, class _it> void rect<_t, _rt, _it>::center_y(_t v) {
	_t hh = height() / 2;
	_y0 = v - hh;
	_y1 = v + hh;
	adjust_to_concept();
}

template<class _t, class _rt, class _it> _it rect<_t, _rt, _it>::go_x0() {
	adjust_to_concept();
	return _lle<_t, _it>(_x0);
}
template<class _t, class _rt, class _it> _it rect<_t, _rt, _it>::go_y0() {
	adjust_to_concept();
	return _lle<_t, _it>(_y0);
}
template<class _t, class _rt, class _it> _it rect<_t, _rt, _it>::go_x1() {
	adjust_to_concept();
	return _sge<_t, _it>(_x1) - 1;
}
template<class _t, class _rt, class _it> _it rect<_t, _rt, _it>::go_y1() {
	adjust_to_concept();
	return _sge<_t, _it>(_y1) - 1;
}
template<class _t, class _rt, class _it> _it rect<_t, _rt, _it>::go_width() {
	adjust_to_concept();
	return go_x1() - go_x0() + 1;
}
template<class _t, class _rt, class _it> _it rect<_t, _rt, _it>::go_height() {
	adjust_to_concept();
	return go_y1() - go_y0() + 1;
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::go_ls() {
	adjust_to_concept();
	return _x0 - go_x0();
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::go_ts() {
	adjust_to_concept();
	return _y0 - go_y0();
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::go_rs() {
	adjust_to_concept();
	return go_x1() + 1 - _x1;
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::go_bs() {
	adjust_to_concept();
	return go_y1() + 1 - _y1;
}
template<class _t, class _rt, class _it> _it rect<_t, _rt, _it>::gi_x0() {
	adjust_to_concept();
	return _sge<_t, _it>(_x0);
}
template<class _t, class _rt, class _it> _it rect<_t, _rt, _it>::gi_y0() {
	adjust_to_concept();
	return _sge<_t, _it>(_y0);
}
template<class _t, class _rt, class _it> _it rect<_t, _rt, _it>::gi_x1() {
	adjust_to_concept();
	return _lle<_t, _it>(_x1) - 1;
}
template<class _t, class _rt, class _it> _it rect<_t, _rt, _it>::gi_y1() {
	adjust_to_concept();
	return _lle<_t, _it>(_y1) - 1;
}
template<class _t, class _rt, class _it> _it rect<_t, _rt, _it>::gi_width() {
	adjust_to_concept();
	return gi_x1() - gi_x0() + 1;
}
template<class _t, class _rt, class _it> _it rect<_t, _rt, _it>::gi_height() {
	adjust_to_concept();
	return gi_y1() - gi_y0() + 1;
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::gi_ls() {
	adjust_to_concept();
	return 1 - (_x0 - gi_x0());
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::gi_ts() {
	adjust_to_concept();
	return 1 - (_y0 - gi_y0());
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::gi_rs() {
	adjust_to_concept();
	// 1 - (gi_x1() + 1 - _x1)
	return _x1 - gi_x1();
}
template<class _t, class _rt, class _it> _t rect<_t, _rt, _it>::gi_bs() {
	adjust_to_concept();
	// 1 - (gi_y1() + 1 - _y1)
	return _y1 - gi_y1();
}
template<class _t, class _rt, class _it> _rt rect<_t, _rt, _it>::g_percent(_it x, _it y) {
	adjust_to_concept();
	_it _ix0 = gi_x0();
	_it _ix1 = gi_x1();
	_it _iy0 = gi_y0();
	_it _iy1 = gi_y1();
	if (x >= _ix0 && x <= _ix1 && y >= _iy0 && y <= _iy1) return 1;
	_it _ox0 = go_x0();
	_it _ox1 = go_x1();
	_it _oy0 = go_y0();
	_it _oy1 = go_y1();
	if (x < _ox0 || x > _ox1 || y < _oy0 || y > _oy1) return 0;
	_rt ret;
	// there a transform from _t to _rt, because g_percent is a calc
	// needs much precise, and gi_ & go_ is designed for _t.
	if (y >= _oy0 && y < _iy0) {
		ret = (_rt)gi_ts();
	} else if (y >= _iy0 && y < _iy1) {
		ret = (_rt)1;
	} else if (y >= _iy1 && y <+ _oy1) {
		ret = (_rt)gi_bs();
	}
	if (x >= _ox0 && x < _ix0) {
		ret *= (_rt)gi_ls();
	} else if (x >= _ix0 && x < _ix1) {
		ret *= (_rt)1;
	} else if (x >= _ix1 && x <= _ox1) {
		ret *= (rt)gi_rs();
	}
	return ret;
}

template<class _t, class _rt, class _it>
void rect<_t, _rt, _it>::adjust_to_concept() {
	if (_concept == numeric) return;
	if (_x1 >= _x0 && _y1 >= _y0) return;
	switch (_concept) {
	case auto_adjust:
		adjust_ltrb();
		break;
	case normal:
		if (_x1 < _x0) _x1 = _x0;
		if (_y1 < _y0) _y1 = _y0;
		break;
	}
}

template<class _t, class _rt, class _it>
void rect<_t, _rt, _it>::adjust_ltrb() {
	_t _x;
	if (_x1 < _x0) {
		_x = _x1;
		_x1 = _x0;
		_x0 = _x;
	}
	if (_y1 < _y0) {
		_x = _y1;
		_y1 = _y0;
		_y0 = _x;
	}
}

template<class _t, class _rt, class _it, class _dest_t, class _dest_rt, class _dest_it>
bool rect<_t, _rt, _it>::_union(rect<_dest_t, _dest_rt, _dest_it>& o) {
	adjust_to_concept(), o.adjust_to_concept();
	if ((_t)o._x0 < _x0) _x0 = (_t)o._x0;
	if ((_t)o._x1 > _x1) _x1 = (_t)o._x1;
	if ((_t)o._y0 < _y0) _y0 = (_t)o._y0;
	if ((_t)o._y1 > _y1) _y1 = (_t)o._y1;
	return true;
}

template<class _t, class _rt, class _it, class _dest_t, class _dest_rt, class _dest_it>
bool rect<_t, _rt, _it>::_intersect(rect<_dest_t, _dest_rt, _dest_it>& o) {
	adjust_to_concept(), o.adjust_to_concept();
	if ((_t)o._x0 > _x0) _x0 = (_t)o._x0;
	if ((_t)o._x1 < _x1) _x1 = (_t)o._x1;
	if ((_t)o._y0 > _y0) _y0 = (_t)o._y0;
	if ((_t)o._y1 < _y1) _y1 = (_t)o._y1;
	return true;
}

template<class _t, class _rt, class _it, class _dest_t, class _dest_rt, class _dest_it>
bool rect<_t, _rt, _it>::_subtract(rect<_dest_t, _dest_rt, _dest_it>& o, bool shrink) {
	adjust_to_concept(), o.adjust_to_concept();
	if (_auto_adjust) adjust_ltrb();
	if (shrink) {
		// prefer to smaller
	} else {
		// prefer to bigger
	}
	// 相减时参数有：大优先、小优先、挖空不算、等等，
	// 这是一个非常复杂的分析过程。 xor 也同理。值得以后仔细研究
	return true;
}

template<class _t, class _rt, class _it, class _dest_t, class _dest_rt, class _dest_it>
bool rect<_t, _rt, _it>::_xor(rect<_dest_t, _dest_rt, _dest_it>& o) {
	adjust_to_concept(), o.adjust_to_concept();
	return true;
}

template<class _t, class _rt, class _it>
bool rect<_t, _rt, _it>::inflate(_t l, _t t, _t r, _t b) {
	_x0 -= l;
	_y0 -= t;
	_x1 += r;
	_y1 += b;
	adjust_to_concept();
	return true;
}

template<class _t, class _rt, class _it>
bool rect<_t, _rt, _it>::deflate(_t l, _t t, _t r, _t b) {
	_x0 += l;
	_y0 += t;
	_x1 -= r;
	_y1 -= b;
	adjust_to_concept();
	return true;
}

template<class _t, class _rt, class _it>
bool rect<_t, _rt, _it>::expand(_t v) {
	_x0 -= v;
	_y0 -= v;
	_x1 += v;
	_y1 += v;
	adjust_to_concept();
	return true;
}

template<class _t, class _rt, class _it>
bool rect<_t, _rt, _it>::shrink(_t v) {
	_x0 += v;
	_y0 += v;
	_x1 -= v;
	_y1 -= v;
	adjust_to_concept();
	return true;
}

template<class _t, class _rt, class _it>
bool rect<_t, _rt, _it>::offset(_t dx, _t dy) {
	_x0 += dx;
	_y0 += dy;
	_x1 += dx;
	_y1 += dy;
	//adjust_to_concept();
	return true;
}

template<class _t, class _rt, class _it>
bool rect<_t, _rt, _it>::base_width(_t bx, _t v) {
	adjust_to_concept();
	if (bx == 0) {
		width(v);
	} else {
		_rt kscale = (_rt)v / (_rt)width();
		_x0 = bx + kscale * (_x0 - bx);
		_x1 = bx + kscale * (_x1 - bx);
	}
	return true;
}

template<class _t, class _rt, class _it>
bool rect<_t, _rt, _it>::base_height(_t by, _t v) {
	adjust_to_concept();
	if (by == 0) {
		height(v);
	} else {
		_rt kscale = (_rt)v / (_rt)height();
		_y0 = by + kscale * (_y0 - by);
		_y1 = by + kscale * (_y1 - by);
	}
	return true;
}

template<class _t, class _rt, class _it>
bool rect<_t, _rt, _it>::contain(_t x, _t y) {
	adjust_to_concept();
	if (x >= _x0 && x <= _x1 && y >= _y0 && y <= _y1) {
		return true;
	}
	return false;
}

template<class _t, class _rt, class _it>
bool rect<_t, _rt, _it>::isempty() {
	return _x0 == _x1 || _y0 == _y1;
}

template<class _t, class _rt, class _it> _rt rect<_t, _rt, _it>::xyaspect() const {
	return (_rt)height() / (_rt)width();
}

template<class _t, class _rt, class _it> _rt rect<_t, _rt, _it>::area() const {
	return (_rt)height() * (_rt)width();
}



///////////////////////////////////////////////////////////////////////////////
//
// rects
//
template<class _t, class _rt, class _it>
rects<_t, _rt, _it>::rects() {
	_sort_lock = false;
}

template<class _t, class _rt, class _it>
void rects<_t, _rt, _it>::update_bounds() {
	rects_type::iterator it;
	for (it = _rects.begin(); it != _rects.end(); ++it) {
		it->adjust_to_concept();
		if (it == _rects.begin()) {
			_x0 = it->_x0;
			_y0 = it->_y0;
			_x1 = it->_x1;
			_y1 = it->_y1;
		} else {
			_union(*it);
		}
	}
}

template<class _t, class _rt, class _it>
bool rects<_t, _rt, _it>::contains(_t x, _t y) {
	bool r = true;
	rects_type::iterator it;
	for (it = _rects.begin(); it != _rects.end(); ++it) {
		r = r && it->contain(x, y);
	}
	return r;
}

template<class _t, class _rt, class _it, class _dest_t, class _dest_rt, class _dest_it>
bool rects<_t, _rt, _it>::_union(rects<_dest_t, _dest_rt, _dest_it>& o) {
	//
	// src[i] --> dest[j]:
	//	s[i] & s[j],
	//
}

template<class _t, class _rt, class _it, class _dest_t, class _dest_rt, class _dest_it>
bool rects<_t, _rt, _it>::_intersect(rects<_dest_t, _dest_rt, _dest_it>& o) {
	//
}

template<class _t, class _rt, class _it, class _dest_t, class _dest_rt, class _dest_it>
bool rects<_t, _rt, _it>::_subtract(rects<_dest_t, _dest_rt, _dest_it>& o, bool shrink) {
	return false;
}

template<class _t, class _rt, class _it, class _dest_t, class _dest_rt, class _dest_it>
bool rects<_t, _rt, _it>::_xor(rects<_dest_t, _dest_rt, _dest_it>& o) {
	return false;
}

template<class _t, class _rt, class _it>
bool rects<_t, _rt, _it>::invert() {
	return false;
}

template<class _t, class _rt, class _it>
bool rects<_t, _rt, _it>::resplit() {
	return false;
}

template<class _t, class _rt, class _it>
bool rects<_t, _rt, _it>::sort(int direction, bool x_prior, bool block) {
	if (block) {
		// wait_for_sort_lock
		if (_sort_lock) return false;
	}

	typedef rect_type *prect_type;
	_sortdata = new prect_type[_rects.size()];

	int i = 0;
	rects_type::iterator it;
	for (it = _rects.begin(); it != _rects.end(); ++it) {
		_sortdata[i] = &*it;
	}

	_sort_lock = true;
	_sort_direction = direction;
	_sort_x_prior = x_prior;
	qsort(_sortdata, _rects.size(), sizeof(prect_type), sort_compare);
	_sort_lock = false;

	rects_type _newrects;
	while (i) {
		_newrects.push_front(*(_sortdata[i]));
		i--;
	}

	_rects.swap(_newrects);
	_newrects.clear();

	return true;
}

template<class _t, class _rt, class _it>
int __cdecl rects<_t, _rt, _it>::sort_compare(const void *a, const void *b) {
	int dx = __d_dx(_sort_direction);
	int dy = __d_dy(_sort_direction);

	rect_type *ra = (rect_type *)a;
	rect_type *rb = (rect_type *)b;

	int r = 0;
	if (_sort_x_prior) {
		r = _sgn(ra->_x0, rb->_x0) * dx;
		if (r == 0) {
			r = _sgn(ra->_y0, rb->_y0) * dy;
		}
	} else {
		r = _sgn(ra->_y0, rb->_y0) * dy;
		if (r == 0) {
			r = _sgn(ra->_x0, rb->_x0) * dx;
		}
	}
	return r;
}



///////////////////////////////////////////////////////////////////////////////
//
// rot_rect
//


SGP_END
