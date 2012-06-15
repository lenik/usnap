

#pragma once


#include <pos/variant.h>
#include <pos/bdt.h>
using namespace pos;

struct c_type;
typedef bdt::list_t<c_type *> c_types;

struct c_type {
	asz_t	_dispname;
	union {
		u32_t	flags;
		struct {
			int bByref: 1;
			int bConst: 1;
			int bVolatile: 1;
			int bStatic: 1;
		};
	};
	enum {
		key_void,
		key_structure,
		key_enum,
		key_class,
		key_int,
		key_short,
		key_long,
		key_longlong,
		key_uint,
		key_ushort,
		key_ulong,
		key_ulonglong,
		key_i8,
		key_i16,
		key_i32,
		key_i64,
		key_u8,
		key_u16,
		key_u32,
		key_u64,
		key_float,
		key_double,
		key_longdouble,
		key_char,
		key_uchar,
		key_wchar,
	} type;

	enum {
		proto_cdecl,
		proto_pascal,
		proto_stdcall,
		proto_class,
		proto_fastcall,
		proto_unknown
	} proto;

	c_types *_params;

	int ptr_level;
};


