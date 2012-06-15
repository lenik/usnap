
#pragma once

#include <sgp/sgpdef.h>

SGP_BEGIN

enum rect_concept_type {
	auto_adjust, 	// auto adjust_ltrb
	normal,		// null-rect for invalid rect
	numeric,	// force calculation
};

///////////////////////////////////////////////////////////////////////////////
//
// rect: rectangle
//
// _t: coordinate type; _rt: real type for calc, _it: integer type for grid
template<class _t, class _rt, class _it>
class rect {
public:
	typedef rect<_t, _rt, _it> rect_type;
	typedef _t coordinate_type;
	typedef _rt real_type;
	typedef _it grid_type;

	inline _t& x0();
	inline _t& y0();
	inline _t& x1();
	inline _t& y1();

	inline _t left() const;
	inline _t top() const;
	inline _t width() const;
	inline _t height() const;
	inline _t center_x() const;
	inline _t center_y() const;

	inline _t left();
	inline _t top();
	inline _t width();
	inline _t height();
	inline _t center_x();
	inline _t center_y();

	inline void left(_t);
	inline void top(_t);
	inline void width(_t);
	inline void height(_t);
	inline void center_x(_t);
	inline void center_y(_t);

	inline _it go_x0();
	inline _it go_y0();
	inline _it go_x1();
	inline _it go_y1();
	inline _it go_width();
	inline _it go_height();
	inline _t go_ls();
	inline _t go_ts();
	inline _t go_rs();
	inline _t go_bs();
	inline _it gi_x0();
	inline _it gi_y0();
	inline _it gi_x1();
	inline _it gi_y1();
	inline _it gi_width();
	inline _it gi_height();
	inline _t gi_ls();
	inline _t gi_ts();
	inline _t gi_rs();
	inline _t gi_bs();
	inline _rt g_percent(_it x, _it y);

public:
	inline void adjust_to_concept();
	// adjust left,top,right,bottom to normal mode(right>left, bottom>top)
	inline void adjust_ltrb();

	template<class _dest_t, class _dest_rt, class _dest_it>
	inline bool _union(rect<_dest_t, _dest_rt, _dest_it>&);
	template<class _dest_t, class _dest_rt, class _dest_it>
	inline bool _intersect(rect<_dest_t, _dest_rt, _dest_it>&);
	template<class _dest_t, class _dest_rt, class _dest_it>
	inline bool _subtract(rect<_dest_t, _dest_rt, _dest_it>&, bool shrink = true);
	template<class _dest_t, class _dest_rt, class _dest_it>
	inline bool _xor(rect<_dest_t, _dest_rt, _dest_it>&);

	inline bool inflate(_t l, _t t, _t r, _t b);
	inline bool deflate(_t l, _t t, _t r, _t b);
	inline bool expand(_t);
	inline bool shrink(_t);
	inline bool offset(_t, _t);
	inline bool base_width(_t bx, _t v);
	inline bool base_height(_t by, _t v);

	inline bool contain(_t, _t);
	inline bool isempty();

	inline _rt xyaspect() const;
	inline _rt area() const;

public:
	_t _x0;
	_t _y0;
	_t _x1;
	_t _y1;
	rect_concept_type _concept;

	inline rect();
	inline rect(_t, _t, _t, _t);
};



///////////////////////////////////////////////////////////////////////////////
//
// rects: rectangles
//
template<class _t, class _rt, class _it>
class rects : public rect<_t, _rt, _it> {
public:
	//typedef std::vector<rect_type *> prects_type;
	typedef std::vector<rect_type> rects_type;

	void update_bounds();

	// !! ∏¥‘”!! ∏¥‘”!!
	bool invert();

	bool resplit();

	template<class _dest_t, class _dest_rt, class _dest_it>
	inline bool _union(rects<_dest_t, _dest_rt, _dest_it>&);
	template<class _dest_t, class _dest_rt, class _dest_it>
	inline bool _intersect(rects<_dest_t, _dest_rt, _dest_it>&);
	template<class _dest_t, class _dest_rt, class _dest_it>
	inline bool _subtract(rects<_dest_t, _dest_rt, _dest_it>&, bool shrink = true);
	template<class _dest_t, class _dest_rt, class _dest_it>
	inline bool _xor(rects<_dest_t, _dest_rt, _dest_it>&);

	inline bool contains(_t, _t);

	// default sort: ascend y, then ascend x
	inline bool sort(int direction = 4, bool x_prior = false, bool block = true);
	static int __cdecl sort_compare(const void *a, const void *b);

public:
	rects_type _rects;

	// rects::sort will block when sort_lock.
	bool _sort_lock;
	int _sort_direction;
	bool _sort_x_prior;

	rects();
};



///////////////////////////////////////////////////////////////////////////////
//
// rot_rect: rotatable rectangle
//
// _t is used for both rect coordinate and rotate angle.
template<class _t, class _rt, class _it>
class rot_rect {
public:
	typedef _t coordinate_type;
	typedef _t angle_type;
	typedef _rt real_type;
	typedef _it grid_type;

/*
	inline go_rect();
	inline gi_rect();
	inline go_grids();
	inline gi_grids();
*/

public:
	_t _xlt;		// top-left
	_t _ylt;
	_t _xrt;		// top-right
	_t _yrt;
	_t _xlb;		// bottom-left
	_t _ylb;
	_t _xrb;		// bottom-right
	_t _yrb;
	_t _a0x0;		// origin rect(no rotation)'s x0,y0-x1,y1
	_t _a0y0;
	_t _a0x1;
	_t _a0y1;
	_t _w;			// a0-rect width
	_t _h;			// a0-rect height
	_t _a_h;		// rotation angle (xlt-xrt ^ a0x0-a0x1)
	_t _a_v;		// rotation angle (ylt-ylb ^ a0x0-a0x1)
	_t _bx;			// rotation base x
	_t _by;			// rotation base y

	rect_concept_type _concept;

	inline rot_rect(_t xlt, _t ylt, _t xrt, _t yrt, _t h);
	inline rot_rect(_t xlt, _t ylt, _t xrt, _t yrt, _t xlb, _t ylb);
	inline rot_rect(_t xlt, _t ylt, _t xrt, _t yrt, _t xlb, _t ylb, _t xrb, _t yrb);
	//inline rot_rect(_t a0x0, _t a0y0, _t a0x1, _t a0y1, _t a_h);
};

SGP_END

#include <sgp/basic_shape.cpp>
