
///////////////////////////////////////////////////////////////////////////////
//
// a_layout - designed for application
// -----------------------------------
// dansei@hitech, 2002.7.6
//
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <sgp/sgpdef.h>
#include <sgp/basic_shape.h>

SGP_BEGIN

template<class _t> struct _clip_type;
template<class _t> class layout;
template<class _t, class _layer_prop> class layered_layout;

///////////////////////////////////////////////////////////////////////////////
//
// (_clip_type), layout
//
template<class _t>
struct _clip_type {
	typedef rect<_t, double, int> rect_type;
	typedef rect_type::coordinate_type coordinate_type;
	typedef rect_type::real_type real_type;
	typedef rect_type::grid_type grid_type;

	rect_type src;	// src rect
	rect_type dest;	// dest rect
	bool visible;
	void *data;

	inline _clip_type();
};

template<class _t>
class layout {
public:
	typedef rect<_t, double, int> rect_type;
	typedef rect_type::coordinate_type coordinate_type;
	typedef rect_type::real_type real_type;
	typedef rect_type::grid_type grid_type;
	typedef _clip_type<_t> clip_type;
	typedef std::list<clip_type *> cliplist_type;
	typedef cliplist_type::iterator clipitem_type;
	typedef cliplist_type::const_iterator const_clipitem_type;

public:
	inline void enum_reset();
	inline clip_type *enum_next();
	inline bool enum_next(clipitem_type *pclipitem);
	inline int count() const;
	inline clip_type *item(const int);
	inline bool item(const int, clipitem_type *pclipitem);

	// infinite if int < 0
	inline bool push(clipitem_type *, int layers = 1, bool save = true);
	inline bool pull(clipitem_type *, int layers = 1, bool save = true);

	inline bool offset(_t dx, _t dy);
	inline bool resize(_t w, _t h, bool scaled = false, int layout_direction = 0);

	inline clip_type *select(_t x, _t y, int thru = 0);
	inline bool select(_t x, _t y, clipitem_type *pclipitem, int thru = 0);

public:
	rect_type _rect;
	cliplist_type _clips;
	bool _acs;	// absolute coordinate system

	typedef std::vector<clip_type *> pclip_vector_type;
	pclip_vector_type __index_pclip;
	clipitem_type __pnext;

	inline layout();
};



///////////////////////////////////////////////////////////////////////////////
//
// layered_layout
//
template<class _t, class _layer_prop = __void>
class layered_layout {
public:
	typedef layout<_t> layout_type;
	typedef layout_type::rect_type rect_type;
	typedef layout_type::coordinate_type coordinate_type;
	typedef layout_type::real_type real_type;
	typedef layout_type::grid_type grid_type;
	typedef layout_type::clip_type clip_type;
	typedef _layer_prop layer_properties_type;

	struct _layout_properties {
		// ��ת͸����clip����֮������ɲ�͸����
		bool invert_transparency;
		// �̳�͸���򣬽��ò��͸���򴫵�������һ�㣨������λ��ǰ�棩��
		bool inherit_transparency;
		inline _layout_properties() : invert_transparency(false) {}
	};
	class layer : public layout<_t>,
		public _layout_properties,
		public _layer_prop {
	public:
		_t __reserved;
	};
	typedef std::vector<layer *> layers_type;

	struct opaque_rect : public rect_type {
		layer *player;
		inline opaque_rect() : player(0) {}
	};
	typedef std::list<opaque_rect *> opaque_list_type;

public:
	bool build_opaque_list();

	layer *position(_t x, _t y);
	// precise ģʽ�����ݲ���clip��(x,y)�ص��̶ȷ��ز㣬
	// ��(x,y)clip�߽紦ʱ���ǳ����á�
	layer *position_by_grid(grid_type x, grid_type y, bool precise = false);


public:
	layers_type _layers;
	opaque_list_type _opaque_list;

	layered_layout();
};

SGP_END

#include <sgp/a_layout.cpp>
