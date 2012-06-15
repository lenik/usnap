
#pragma once

#pragma warning(disable: 4519)

typedef unsigned __int8	_b8;
typedef unsigned __int16 _b16;
typedef unsigned __int32 _b32;


template<class _t> class rect;
template<class _t> class circle;



///////////////////////////////////////////////////////////////////////////////
//
// sgp::color_space
//
template<class _t, class _mt = double>
interface color_space {
public:
	typedef _t value_type;
	typedef _mt mixed_type;

	virtual _t& mix();
	virtual _t& red();
	virtual _t& green();
	virtual _t& blue();
	virtual _t& cyan();
	virtual _t& magenta();
	virtual _t& yellow();
	virtual _t& black();
	virtual _t& hue();
	virtual _t& saturation();
	virtual _t& intensity();
	virtual _t& alpha();

	virtual _mt mix_val() const;
	virtual _mt red_val() const;
	virtual _mt green_val() const;
	virtual _mt blue_val() const;
	virtual _mt cyan_val() const;
	virtual _mt magenta_val() const;
	virtual _mt yellow_val() const;
	virtual _mt black_val() const;
	virtual _mt hue_val() const;
	virtual _mt saturation_val() const;
	virtual _mt intensity_val() const;
	virtual _mt alpha_val() const;
};

class rgb24 : public color_space<_b8> {
public:
	value_type _r;
	value_type _g;
	value_type _b;

public:
	virtual value_type& red();
	virtual value_type& green();
	virtual value_type& blue();

	virtual mixed_type mix_val() const;
	virtual mixed_type red_val() const;
	virtual mixed_type green_val() const;
	virtual mixed_type blue_val() const;
};

class rgb32 : public color_space<_b8> {
public:
	value_type _r;
	value_type _g;
	value_type _b;
	value_type _a;

public:
	virtual value_type& red();
	virtual value_type& green();
	virtual value_type& blue();
	virtual value_type& alpha();

	virtual mixed_type mix_val() const;
	virtual mixed_type red_val() const;
	virtual mixed_type green_val() const;
	virtual mixed_type blue_val() const;
	virtual mixed_type alpha_val() const;
};




///////////////////////////////////////////////////////////////////////////////
//
// sgp::raster_plain
//
template<class _t, class _mt = size_t>
class raster_plain {
public:
	typedef _t value_type;
	typedef _mt measure_type;
	typedef value_type *pointer_type;

	typedef size_t size_type;

	_t& pixel(size_type y, size_type x);

	template<class _rect_t = _mt>
	_t pick(rect<_rect_t>& part_rect, _t mix_pixel) const;

	template<class _rect_t = _mt>
	void mix(rect<_rect_t>& part_rect, _t mix_pixel);

	pointer_type _data;
	size_type _pitch;
	size_type _leader;
};



///////////////////////////////////////////////////////////////////////////////
//
// sgp::rect
//
template<class _t>
class rect {
public:
	typedef _t value_type;

	_t& x0();
	_t& y0();
	_t& x1();
	_t& y1();

	_t left() const;
	_t top() const;
	_t width() const;
	_t height() const;
	_t center_x() const;
	_t center_y() const;

	void left(_t&);
	void top(_t&);
	void width(_t&);
	void height(_t&);
	void center_x(_t&);
	void center_y(_t&);

	// adjust left,top,right,bottom to normal mode(right>left, bottom>top)
	void adjust_ltrb();

	template<class _aspect_type = _t>
	_aspect_type xyaspect() const;

	template<class _area_t = _t>
	_area_t area() const;

	template<class _dest_t = _t>
	bool union_rect(rect<_dest_t>&, bool _auto_adjust = false);

	template<class _dest_t = _t>
	bool intersect_rect(rect<_dest_t>&, bool _auto_adjust = false);

	template<class _dest_t = _t>
	bool subtract_rect(rect<_dest_t>&, bool _auto_adjust = false);

	template<class _dest_t = _t>
	bool xor_rect(rect<_dest_t>&, bool _auto_adjust = false);

private:
	_t _x0;
	_t _y0;
	_t _x1;
	_t _y1;
};


template<class _t, class _a = _t>
class rot_rect {
public:
	typedef _t value_type;
	typedef _a angle_type;

	_t& x0();
	_t& y0();
	_t& x1();
	_t& y1();

	_t left() const;
	_t top() const;
	_t width() const;
	_t height() const;
	_t center_x() const;
	_t center_y() const;

	void left(_t&);
	void top(_t&);
	void width(_t&);
	void height(_t&);
	void center_x(_t&);
	void center_y(_t&);

	// adjust left,top,right,bottom to normal mode(right>left, bottom>top)
	void adjust_ltrb();

	template<class _aspect_type = _t>
	_aspect_type xyaspect() const;

	template<class _area_t = _t>
	_area_t area() const;

	template<class _dest_t = _t>
	bool union_rect(rect<_dest_t>&, bool _auto_adjust = false);

	template<class _dest_t = _t>
	bool intersect_rect(rect<_dest_t>&, bool _auto_adjust = false);

	template<class _dest_t = _t>
	bool subtract_rect(rect<_dest_t>&, bool _auto_adjust = false);

	template<class _dest_t = _t>
	bool xor_rect(rect<_dest_t>&, bool _auto_adjust = false);

private:
	_t _x0;
	_t _y0;
	_t _x1;
	_t _y1;
};


///////////////////////////////////////////////////////////////////////////////
//
// sgp::rot_rect
//

template<class _t>
class circle {
public:
	typedef _t value_type;
	_t x;
	_t y;
	_t radius;
};

namespace utility {
	template<class _src_t, class _dest_t>
	_dest_t convert(_src_t&);

	template<class _circle_t, class _rect_t>
	bool convert(circle<_circle_t>&, rect<_rect_t>&);
	template<class _rect_t, class _circle_t>
	bool convert(rect<_rect_t>&, circle<_circle_t>&);
}


template<class _pixel_t = int, class _rect_t = double>
bool scale(raster_plain<_pixel_t>& rp, rect<_rect_t>& src_rect,
	   rect<_rect_t>& dest_rect);

template<class _pixel_t = int, class _rot_rect_t = double>
bool rotate(raster_plain<_pixel_t>& rp, rot_rect<_rot_rect_t>& src_rect,
	    rot_rect<_rot_rect_t>& dest_rect);
