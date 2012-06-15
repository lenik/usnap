
#include <sgp/a_layout.h>

SGP_BEGIN

///////////////////////////////////////////////////////////////////////////////
//
// layout
//
template<class _t>
_clip_type<_t>::_clip_type() {
	visible = false;
	data = 0;
}

template<class _t>
layout<_t>::layout() {
	// : _clips(), __index_pclip()
	__pnext = _clips.begin();
	_acs = true; // absolute coordinate system by default.
}

template<class _t>
void layout<_t>::enum_reset() {
	__pnext = _clips.begin();
}

template<class _t>
layout<_t>::clip_type *layout<_t>::enum_next() {
	if (__pnext == _clips.end()) return 0;
	clip_type *ret = *__pnext;
	++__pnext;
	return ret;
}

template<class _t>
bool layout<_t>::enum_next(layout<_t>::clipitem_type *pclipitem) {
	if (__pnext == clips.end()) return false;
	*pclipitem = __pnext;
	++__pnext;
	return true;
}

template<class _t>
int layout<_t>::count() const {
	return _clips.size();
}

template<class _t>
layout<_t>::clip_type *layout<_t>::item(const int i) {
	if (i < 0 || i >= count()) return 0;
	// rebuild the index table
	__index_pclip.resize(count());
	enum_reset();
	clip_type *pc;
	int _i = 0;
	while (pc = enum_next()) {
		__index_pclip[_i++] = pc;
	}

	return __index_pclip[i];
}

template<class _t>
bool layout<_t>::item(const int i, layout<_t>::clipitem_type *pclipitem) {
	if (i < 0 || i >= count()) return false;
	enum_reset();
	clipitem_type it;
	while (enum_next(&it) && i--);
	*pclipitem = it;
	return true;
}

template<class _t>
bool layout<_t>::push(clipitem_type *pit, int n, bool save) {
	if (n == 0) return true;
	clipitem_type it_before;
	clipitem_type it_ret;
	if (n > 0) {
		it_before = *pit;
		while (n-- > 0) {
			if (it_before == _clips.begin()) {
				return false;
			}
			--it_before;
		}
	} else {
		it_before = _clips.begin();
	}
	it_ret = _clips.insert(it_before, **pit);
	_clips.erase(*pit);

	if (save) *pit = it_ret;
	return true;
}

template<class _t>
bool layout<_t>::pull(clipitem_type *pit, int n, bool save) {
	if (n == 0) return true;
	clipitem_type it_before;
	clipitem_type it_ret;
	if (n > 0) {
		it_before = *pit;
		while (n-- >= 0) {
			if (it_before == _clips.end()) {
				return false;
			}
			++it_before;
		}
	} else {
		it_before = _clips.end();
	}
	it_ret = _clips.insert(it_before, **pit);
	_clips.erase(*pit);

	if (save) *pit = it_ret;
	return true;
}

template<class _t>
bool layout<_t>::offset(_t dx, _t dy) {
	clip_type *pc;
	enum_reset();
	while (pc = enum_next()) {
		pc->dest.offset(dx, dy);
	}
	_rect.offset(dx, dy);
	return true;
}

template<class _t>
bool layout<_t>::resize(_t w, _t h, bool scaled, int layout_direction) {
	// resize only affected to dest_
	int ldx = __d_dx(layout_direction);
	int ldy = __d_dy(layout_direction);

	clip_type *pc;

	_t lw = _rect.width();
	_t lh = _rect.height();

	if (!scaled) {
		// offset will be taken even in relative coordinate system.
		// ignore !ldx && !ldy for efficiency
		if (ldx || ldy) {
			_t dx = w - lw;
			_t dy = h - lh;
			dx = dx * (ldx + 1) / 2;
			dy = dy * (ldy + 1) / 2;

			enum_reset();
			while (pc = enum_next()) {
				pc->dest.offset(dx, dy);
			}
		}
	} else if (w != lw || h != lh) {
		// scale mode don't use layout_direction, instead,
		// it calculate the scale base point in _acs.
		_t bx = 0;
		_t by = 0;
		real_type kw = (real_type)w / (real_type)lw;
		real_type kh = (real_type)h / (real_type)lh;
		if (_acs) {
			bx = _rect._x0;
			by = _rect._y0;
		}
		enum_reset();
		while (pc = enum_next()) {
			_t sw = pc->dest.width();
			_t sh = pc->dest.height();
			pc->dest.base_width(bx, (_t)(sw * kw));
			pc->dest.base_height(by, (_t)(sh * kh));
		}
	}
	_rect.width(w);
	_rect.height(h);
	return true;
}

template<class _t>
layout<_t>::clip_type *layout<_t>::select(_t x, _t y, int thru) {
	clipitem_type it;
	if (select(x, y, &it)) {
		return &*it;
	}
	return 0;
}

template<class _t>
bool layout<_t>::select(_t x, _t y, clipitem_type *pclipitem, int thru) {
	cliplist_type::reverse_iterator it;
	for (it = _clips.rbegin(); it != _clips.rend(); ++it) {
		clip_type *pc = (*it);
		if (pc->dest.contain(x, y)) {
			if (thru-- > 0) continue;
			// NOTE: reverse_iterator::operator* { return *--current }
			*pclipitem = --it.base();
			return true;
		}
	}
	return false;
}



///////////////////////////////////////////////////////////////////////////////
//
// layered_layout
//
template<class _t, class _layer_prop>
layered_layout<_t, _layer_prop>::layered_layout() {
}

template<class _t, class _layer_prop>
bool layered_layout<_t, _layer_prop>::build_opaque_list() {
	// 0. current entire rect = top_layer._rect
	// 1. sort current transparency rects by y-axis
	// 2. build cut-list
	// 3. build rect-list according to cut-list
	// 4. sort rect-list by x-axis
	// 5. union unionable rects
	// 6. loop.

	_opaque_list.clear();

	typedef std::list<rect_type> rects_type;
	rects_type transparencys;

	layers_type::iterator layer_it = _layers.begin();
	if (layer_it == _layers.end()) return true;

	// 看起来就像在层顶端罩着一层透明的层。
	transparencys.push_back((*layer_it)->_rect);
/*
	for (; layer_it != _layers.end(); ++layer_it) {
		//
		rects_type new_trans;
		layer::clip_type *pc;
		(*layer_it)->enum_reset();
		while (pc = (*layer_it)->enum_next()) {
			rects_type::iterator rect_it;
			rect_type r;
			for (rect_it = transparencys.begin(); rect_it !=
				transparencys.end(); ++rect_it) {
				r = *rect_it;
				r._intersect(pc->dest);
				if (!r.isempty()) {
					new_trans.push_back(r);
				}


			transparencys.push_back(pc->dest);
		}
	}
*/
	return true;
}

template<class _t, class _layer_prop>
layered_layout<_t, _layer_prop>::layer *
layered_layout<_t, _layer_prop>::position(_t x, _t y) {
	return 0;
}

template<class _t, class _layer_prop>
layered_layout<_t, _layer_prop>::layer *
layered_layout<_t, _layer_prop>::position_by_grid(
	layered_layout<_t, _layer_prop>::grid_type x,
	layered_layout<_t, _layer_prop>::grid_type y, bool precise) {
	return 0;
}

//
SGP_END
