
/*
 * 标准图形处理 Standard Graphics Process
 *
 * 桃壳高科技 2001
 */

#pragma once

#pragma warning(disable: 4786)		// 调试符号名称太长
#pragma warning(disable: 4519)		// 缺省模版参数只能用在模版类声明中

///////////////////////////////////////////////////////////////////////////////
//
// sgp architecture
//
#define SGP_BEGIN	namespace sgp {
#define SGP_END		};




///////////////////////////////////////////////////////////////////////////////
//
// basic data types
//
#include <sgp/base_types.h>

#define _char		sgp::_i8
#define _short		sgp::_i16
#define _int		sgp::_i32
#define _long		sgp::_i32
// can't do this
// #define long long	sgp::_i64
#define _byte		sgp::_b8
#define _word		sgp::_b16
#define _dword		sgp::_b32
#define _qword		sgp::_b64
#define _float		sgp::_f32
#define _double		sgp::_f64

#ifdef __pure
#define char		_char
#define short		_short
#define int		_int
#define long		_long
#define __int8		_i8
#define __int16		_i16
#define __int32		_i32
#define __int64		_i64
#define float		_f32
#define double		_f64
#define bool		_bool
#endif

#include <vector>
#include <list>
#include <utility>




///////////////////////////////////////////////////////////////////////////////
//
// basic constant
//
#define __d_lt		-4
#define __d_t		-3
#define __d_rt		-2
#define __d_l		-1
#define __d_		0
#define __d_r		1
#define __d_lb		2
#define __d_b		3
#define __d_rb		4

#define __D_lt		0
#define __D_t		1
#define __D_rt		2
#define __D_l		3
#define __D_		4
#define __D_r		5
#define __D_lb		6
#define __D_b		7
#define __D_rb		8

#define __d_dx(d)	( (int)(d + 4) % 3 - 1)
#define __d_dy(d)	( (int)(d + 4) / 3 - 1)
#define __D_dx(d)	( (int)(d) % 3)
#define __D_dy(d)	( (int)(d) / 3)
