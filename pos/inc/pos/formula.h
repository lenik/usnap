//
// POS.Formula
//

//
// yy-mm-dd	...
// yy-mm-dd	history 2
// 2003-6-26	start

#pragma once


#define _NS_BEGIN		namespace pos { namespace formula {
#define _NS_END			}}

// forward declaration
_NS_BEGIN

// UTF-8 style coding:
//	7  0,7F			0xxxxxxx
//	11 80,7FF		110xxxxx 10xxxxxx
//	16 800,FFFF		1110xxxx 10xxxxxx 10xxxxxx
//	21 10000,1FFFFF		11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
//	26 200000,3FFFFFF	111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
//	31 4000000,7FFFFFFF	1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx

// Formula coding:
//	Constant: 00 Sign Type Len		S1 T3 L2
//	Variable: 01 Extend Index		X1 I5
//	Operator: 10
//	Noodle:   11
//
//	S1: + -
//	T3: Z Q R C V M M2 X
//	L2:
//		Z: u8 u16 u32 u*n(256-order)	| n32
//		Q: (Z/Z)			| ..
//		R: r32 r64 r*n BCD-num		| n32 | BCD: align(n32,2)/2 * bytes
//		C: (R+iR)			| ..
//		V: 2 3 4 n*			| n32
//		M: VxV				| n32
//		M2: 1*n n*1 n*m (r)		| n32 | m32
//		X: Inf NaN (r) (r)
//

enum formula_code {
	fc_
};

_NS_END

#include <pos/config.h>
#include <pos/noodle.h>

_NS_BEGIN

#pragma pack(push, 4)

//	struct ...

#pragma pack(pop)

// additional implementation...

_NS_END