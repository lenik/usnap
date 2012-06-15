//
// POS Kernel Vars (Part 2)
//

//
// 2003.5.15	split from util.h
// 2003.5.15	vars_t -> v32_t/v64_t/v128_t, and add PVT into each v*_t.
// 2003.4.17	started


#pragma once

namespace pos {
	struct v16_t;
	struct v32_t;
	struct v64_t;
	struct v128_t;
}


#include <pos/config.h>
#include <pos/variant.h>


namespace pos {
#	pragma pack(push, 4)

	struct v16_t {		// 16-bytes
		union {
			struct {
				word_t	_w;
				app_t	_s;
				arith_t	_a;
				res_t	_r;
			};
			struct {
				i32_t	_, __, a, b;
			};
			i8_t	i1[16];
			i16_t	i2[8];
			i32_t	i4[4];
			u8_t	u1[16];
			u16_t	u2[8];
			u32_t	u4[4];
			r16_t	r2[8];
			r32_t	r4[4];
			c16_t	c2[4];
			c32_t	c4[1];
			struct {
				var_t		hdr;
				var_t::_vt	body;
			};
		};
	};
	struct v32_t {		// 32-bytes
		union {
			struct {
				u32_t	_1, _2, A, B;
				word_t	_w;
				app_t	_s;
				arith_t	_a;
				res_t	_r;
			};
			struct {
				i32_t	_, __, a, b, ___, ____, _____, ______;
			};
			i8_t	i1[32];
			i16_t	i2[16];
			i32_t	i4[8];
			u8_t	u1[32];
			u16_t	u2[16];
			u32_t	u4[8];
			r16_t	r2[16];
			r32_t	r4[8];
			c16_t	c2[8];
			c32_t	c4[2];
			struct {
				var_t		hdr;
				var_t::_vt	body;
			};
		};
	};
	struct v64_t {		// 64-bytes
		union {
			struct {
				u32_t	_1, _2, A, B, C, D, E, F;
				u32_t	G, H, I, J;
				word_t	_w;
				app_t	_s;
				arith_t	_a;
				res_t	_r;
			};
			struct {
				i32_t	_, __, a, b, c, d, e, f;
				i32_t	g, h, i, j, ___, ____, _____, ______;
			};
			i8_t	i1[64];
			i16_t	i2[32];
			i32_t	i4[16];
			u8_t	u1[64];
			u16_t	u2[32];
			u32_t	u4[16];
			r16_t	r2[32];
			r32_t	r4[16];
			c16_t	c2[16];
			c32_t	c4[4];
			struct {
				var_t		hdr;
				var_t::_vt	body;
			};
		};
	};
	struct v128_t {		// 128-bytes
		union {
			struct {
				u32_t	_1, _2, A, B, C, D, E, F;
				u32_t	G, H, I, J, K, L, M, N;
				u32_t	O, P, Q, R, S, T, U, V;
				u32_t	W, X, Y, Z;
				word_t	_w;
				app_t	_s;
				arith_t	_a;
				res_t	_r;
			};
			struct {
				i32_t	_, __, a, b, c, d, e, f;
				i32_t	g, h, i, j, k, l, m, n;
				i32_t	o, p, q, r, s, t, u, v;
				i32_t	w, x, y, z, ___, ____, _____, ______;
			};
			i8_t	i1[128];
			i16_t	i2[64];
			i32_t	i4[32];
			u8_t	u1[128];
			u16_t	u2[64];
			u32_t	u4[32];
			r16_t	r2[64];
			r32_t	r4[32];
			c16_t	c2[32];
			c32_t	c4[8];
			struct {
				var_t		hdr;
				var_t::_vt	body;
			};
		};
	};

#	pragma pack(pop)

} // namespace pos