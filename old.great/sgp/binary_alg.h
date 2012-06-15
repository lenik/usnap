
#pragma once

#include <sgp/sgpdef.h>

SGP_BEGIN

///////////////////////////////////////////////////////////////////////////////
//
// 基本单元二进制算法
//
template<class _t = unsigned __int32>
class word_binary_alg {
public:
	typedef _t binary_type;

	inline int _0s(_t a);	// total bits of 0's
	inline int _1s(_t a);	// total bits of 1's
	inline int lc1s(_t a);	// continuous 1's at left
	inline int rc1s(_t a);	// continuous 1's at right
	inline int l0s(_t a);	// 0's at left
	inline int l1s(_t a);	// 1's at left
	inline int r0s(_t a);	// 0's at right
	inline int r1s(_t a);	// 1's at right

	inline _t reverse(_t a);
};




///////////////////////////////////////////////////////////////////////////////
//
// 带描述屏蔽位的基本单元二进制算法
// 内部按屏蔽后重组单元对待
//
template<class _t = unsigned __int32>
class mask_word_binary_alg {
public:
	typedef _t binary_type;

	_t	m_a;		// available bits mask
	// alg for mask only.
	word_binary_alg<_t> agg_mask;
	inline int m__0s();	// total bits of mask's 0's
	inline int m__1s();	// total bits of mask's 1's
	inline int m_lc1s();	// continuous 1's at mask's left
	inline int m_rc1s();	// continuous 1's at mask's right
	inline int m_l0s();	// 0's at mask's left
	inline int m_l1s();	// 1's at mask's left
	inline int m_r0s();	// 0's at mask's right
	inline int m_r1s();	// 1's at mask's right
	inline _t m_reverse();

	inline int _0s(_t a);	// total bits of 0's
	inline int _1s(_t a);	// total bits of 1's
	inline int lc1s(_t a);	// continuous 1's at left
	inline int rc1s(_t a);	// continuous 1's at right
	inline int l0s(_t a);	// 0's at left
	inline int l1s(_t a);	// 1's at left
	inline int r0s(_t a);	// 0's at right
	inline int r1s(_t a);	// 1's at right

	inline _t reverse(_t a);
};

SGP_END

#include <sgp/binary_alg.cpp>
