
#pragma once

#include <sgp/sgpdef.h>
#include <sgp/basic_shape.h>

SGP_BEGIN

template<class _t, class _mt = size_t>
class raster_plain {
public:
	typedef _t value_type;
	typedef _mt measure_type;
	typedef value_type *pointer_type;

	typedef size_t size_type;

	_t& pixel(size_type y, size_type x);

	template<class _rect_t = _mt>
	_t pick(rect<_rect_t, double, int>& part_rect, _t mix_pixel) const;

	template<class _rect_t = _mt>
	void mix(rect<_rect_t, double, int>& part_rect, _t mix_pixel);

	pointer_type _data;
	size_type _pitch;
	size_type _leader;
};

SGP_END

#include <sgp/raster_process.cpp>
