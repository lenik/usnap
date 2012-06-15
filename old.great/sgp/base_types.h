
#pragma once

#include <sgp/sgpdef.h>

SGP_BEGIN

typedef struct __i8	{ __int8		v; } _i8;
typedef struct __i16	{ __int16		v; } _i16;
typedef struct __i32	{ __int32		v; } _i32;
typedef struct __i64	{ __int64		v; } _i64;
typedef struct __b8	{ unsigned __int8	v; } _b8;
typedef struct __b16	{ unsigned __int16	v; } _b16;
typedef struct __b32	{ unsigned __int32	v; } _b32;
typedef struct __b64	{ unsigned __int64	v; } _b64;
typedef struct __f32	{ float			v; } _f32;
typedef struct __f64	{ double		v; } _f64;

typedef struct __bool	{ bool			v; } _bool;


struct __void {};

template<class _t> struct __scalar {
	typedef _t value_type;
	_t v;
};

SGP_END
