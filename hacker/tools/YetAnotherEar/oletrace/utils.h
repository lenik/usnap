

#pragma once


#define _initialize(name)					\
	class __initialize_##name {				\
	public:							\
		inline bool _init_();				\
		__initialize_##name() { _init_(); }		\
	} __g_initialize_obj_##name;				\
	inline bool __initialize_##name::_init_()

#define _initialize_local	_initialize(local)
