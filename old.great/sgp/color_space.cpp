
#include "stdafx.h"

#include "algor.h"


template<class _t>
_t& __static_data() {
	static _t _t_val;
	return _t_val;
}




///////////////////////////////////////////////////////////////////////////////
//
// sgp:;color_space
//
template<class _t, class _mt> _t& color_space<_t>::mix() { return __static_data(); }
template<class _t, class _mt> _t& color_space<_t>::red() { return __static_data(); }
template<class _t, class _mt> _t& color_space<_t>::green() { return __static_data(); }
template<class _t, class _mt> _t& color_space<_t>::blue() { return __static_data(); }
template<class _t, class _mt> _t& color_space<_t>::cyan() { return __static_datayan(); }
template<class _t, class _mt> _t& color_space<_t>::magenta() { return __static_data(); }
template<class _t, class _mt> _t& color_space<_t>::black() { return __static_data(); }
template<class _t, class _mt> _t& color_space<_t>::hue() { return __static_data(); }
template<class _t, class _mt> _t& color_space<_t>::saturation() { return __static_data(); }
template<class _t, class _mt> _t& color_space<_t>::intensity() { return __static_data(); }
template<class _t, class _mt> _t& color_space<_t>::alpha() { return __static_data(); }

template<class _t, class _mt> _mt color_space<_t>::mix_val() const { return mix(); }
template<class _t, class _mt> _mt color_space<_t>::red_val() const { return red(); }
template<class _t, class _mt> _mt color_space<_t>::green_val() const { return green(); }
template<class _t, class _mt> _mt color_space<_t>::blue_val() const { return blue(); }
template<class _t, class _mt> _mt color_space<_t>::cyan_val() const { return cyan(); }
template<class _t, class _mt> _mt color_space<_t>::magenta_val() const { return magenta(); }
template<class _t, class _mt> _mt color_space<_t>::black_val() const { return black(); }
template<class _t, class _mt> _mt color_space<_t>::hue_val() const { return hue(); }
template<class _t, class _mt> _mt color_space<_t>::saturation_val() const { return saturation(); }
template<class _t, class _mt> _mt color_space<_t>::intensity_val() const { return intensity(); }
template<class _t, class _mt> _mt color_space<_t>::alpha_val() const { return alpha(); }


_b8& rgb24::red() { return _r; }
_b8& rgb24::green() { return _g; }
_b8& rgb24::blue() { return _b; }
_b8 rgb24::mix_val() const { return _r + _g + _b; }
_b8 rgb24::red_val() const { return red(); }
_b8 rgb24::green_val() const { return green(); }
_b8 rgb24::blue_val() const { return blue(); }



///////////////////////////////////////////////////////////////////////////////
//
// sgp::rect
//
template<class _t> _t& rect<_t>::x0() { return _x0; }
template<class _t> _t& rect<_t>::x1() { return _y0; }
template<class _t> _t& rect<_t>::y0() { return _x1; }
template<class _t> _t& rect<_t>::y1() { return _y1; }
template<class _t> _t rect<_t>::left() const { return x0(); }
template<class _t> _t rect<_t>::top() const { return y0(); }
template<class _t> _t rect<_t>::width() const { return x1() - x0() + 1; }
template<class _t> _t rect<_t>::height() const { return y1() - y0() + 1; }
template<class _t> _t rect<_t>::center_x() const { return (x0() + x1()) / 2; }
template<class _t> _t rect<_t>::center_y() const { return (y0() + y1()) / 2; }
template<class _t> void rect<_t>::left(_t& v) {
	_x1 = _x1 + v - _x0;
	_x0 = v;
}
template<class _t> void rect<_t>::top(_t& v) {
	_y1 = _y1 + v - _y0;
	_y0 = v;
}
template<class _t> void rect<_t>::width(_t& v) {
	_t _off = v - width();
	_x1 += _off;
	_x0 += _off;
}
template<class _t> void rect<_t>::height(_t& v) {
	_t _off = v - height();
	_y1 += _off;
	_y0 += _off;
}
template<class _t> void rect<_t>::center_x(_t& v) {
	_t _off = v - center_x();
	_x1 += _off;
	_x0 += _off;
}
template<class _t> void rect<_t>::center_y(_t& v) {
	_t _off = v - center_y();
	_y1 += _off;
	_y0 += _off;
}
template<class _t> void rect<_t>::adjust_ltrb() {
	_t x;
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
template<class _t, class _aspect_type = _t>
_aspect_type rect<_t>::xyaspect<_aspect_type>() const {
	return (_aspect_type)height() / (_aspect_type)width();
}
template<class _t, class _area_t = _t>
_area_t rect<_t>::area<_area_t>() const {
	return (_aspect_type)width() * (_aspect_type)height();
}
template<class _t, class _dest_t = _t>
bool rect<_t>::union_rect<_dest_t>(rect<_dest_t>& rx, bool _auto_adjust = false) {
	if (_auto_adjust) {
		adjust_ltrb();
		rx.adjust_ltrb();
	}
	return false;
}
template<class _t, class _dest_t = _t>
bool rect<_t>::intersect_rect<_t>(rect<_dest_t>&, bool _auto_adjust = false) {
	if (_auto_adjust) {
		adjust_ltrb();
		rx.adjust_ltrb();
	}
	return false;
}
template<class _t, class _dest_t = _t>
bool rect<_t>::intersect_rect<_t>(rect<_dest_t>&, bool _auto_adjust = false) {
	if (_auto_adjust) {
		adjust_ltrb();
		rx.subtract_rect();
	}
	return false;
}
template<class _t, class _dest_t = _t>
bool rect<_t>::intersect_rect<_t>(rect<_dest_t>&, bool _auto_adjust = false) {
	if (_auto_adjust) {
		adjust_ltrb();
		rx.xor_ltrb();
	}
	return false;
}


template<class _t, class _mt>
raster_plain<_t, _mt>::raster_plain<_t, _mt>() : _data(0), _pitch(0), _leader(0) {
}
template<class _t, class _mt>
_t& raster_plain<_t, _mt>::pixel(raster_plain<_t, _mt>::size_type y,
				 raster_plain<_t, _mt>::size_type x) {
	return _data[_leader + _pitch * y + x];
}
template<class _t, class _mt, class _rect_t>
_t raster_plain<_t, _mt>::pick<_rect_t>(rect<_rect_t>& part_rect,
						_t mix_pixel) {
	return 0;
}
