
//
// POSIC: type operators
//		(for built-in types, so programminc in C easier.)
//

//
// 2003-6-23	start

#pragma once


#define _NS_BEGIN		namespace pos { namespace posic {
#define _NS_END			}}

// forward declaration
_NS_BEGIN

_NS_END


#include <pos/config.h>
#include <pos/typeimp.h>

_NS_BEGIN

	// operators: , ! != % %= &(and) &(address) &= () * *(ptr) *=
	// + +(unary) ++ += - -(unary) -- -= -> ->* / /=
	// < << <<= <= = == > >= >> >>= [] ^ ^= | |= || ~
	// new delete (type-cast)


	bcd8_t	bcd16_t	bcd32_t	bcd64_t
	b8_t	b16_t	b32_t	b64_t
	r16_t
	c128_t	c16_t	c32_t	c64_t
	pv_2t	pv_3t	pv_4t	pv_22t		pv_33t		pv_44t
	u8_2t	u8_3t	u8_4t	u8_22t		u8_33t		u8_44t
	u16_2t	u16_3t	u16_4t	u16_22t		u16_33t		u16_44t
	u32_2t	u32_3t	u32_4t	u32_22t		u32_33t		u32_44t
	u64_2t	u64_3t	u64_4t	u64_22t		u64_33t		u64_44t
	i8_2t	i8_3t	i8_4t	i8_22t		i8_33t		i8_44t
	i16_2t	i16_3t	i16_4t	i16_22t		i16_33t		i16_44t
	i32_2t	i32_3t	i32_4t	i32_22t		i32_33t		i32_44t
	i64_2t	i64_3t	i64_4t	i64_22t		i64_33t		i64_44t
	r128_2t	r128_3t	r128_4t	r128_22t	r128_33t	r128_44t
	r16_2t	r16_3t	r16_4t	r16_22t		r16_33t		r16_44t
	r32_2t	r32_3t	r32_4t	r32_22t		r32_33t		r32_44t
	r64_2t	r64_3t	r64_4t	r64_22t		r64_33t		r64_44t
	c128_2t	c128_3t	c128_4t	c128_22t	c128_33t	c128_44t
	c16_2t	c16_3t	c16_4t	c16_22t		c16_33t		c16_44t
	c32_2t	c32_3t	c32_4t	c32_22t		c32_33t		c32_44t
	c64_2t	c64_3t	c64_4t	c64_22t		c64_33t		c64_44t
	rel8_t	rel16_t	rel32_t	rel64_t
	fourcc32_t	posid128_t	cid_t	guid128_t	corbaid128_t
	a_t	uc16_t	uc8_t
	asz_t	asz_ct	ucsz16_t	ucsz16_ct	ucsz8_t	ucsz8_ct	bstr_t

// additional implementation...

_NS_END