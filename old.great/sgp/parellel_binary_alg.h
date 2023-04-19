
#pragma once

#include <sgp/sgpdef.h>
#include <sgp/binary_alg.h>

SGP_BEGIN

///////////////////////////////////////////////////////////////////////////////
//
// 并行二进制运算
//	使用一个机器运算操作单元实现对多个二进制单元并行处理。
//	每个单元占用的二进制位必须连续。
//	每个单元占用的位数必须至少是 2 位。
template<class _t = unsigned __int32>
class parellel_binary_alg {
public:
	typedef _t binary_type;

	_t	m_a;			// available bits mask
	_t	m_l;			// lowest bit mask
	_t	m_h;			// highest bit mask
	_t	m_ls;			// low bits mask
	_t	m_hs;			// high bits mask

	_t	m_u[32];		// units' mask
	int	n_u;

public:
	word_binary_alg<_t> _alg;

public:
	inline _t inc(_t a);
	inline _t dec(_t a);
	inline _t add(_t a, _t b);
	inline _t sub(_t a, _t b);

	inline _t full_inc(_t a);		// 饱和增加
	inline _t full_dec(_t a);		// 饱和减少
	inline _t full_add(_t a, _t b);		// 饱和加法
	inline _t full_sub(_t a, _t b);		// 饱和减法

	inline _t diff(_t a, _t b);		// 差值减法
	inline _t cmp(_t a, _t b);		// 比较, 0相等, 最高位a<b, 最低位a>b

	inline _t se(_t a, _t b);		// 比较是否相等
	inline _t sne(_t a, _t b);		// 比较是否不相等
	inline _t sa(_t a, _t b);		// 比较是否大于
	inline _t sae(_t a, _t b);		// 比较是否大于等于
	inline _t sb(_t a, _t b);		// 比较是否小于
	inline _t sbe(_t a, _t b);		// 比较是否小于等于
	inline _t sz(_t a);			// 比较是否为0
	inline _t snz(_t a);			// 比较是否不为0

	inline _t u(_t a, int i);		// 提取单元
	inline _t u(_t a, int i, _t v);		// 设置单元
	inline _t uv(int i, _t v);		// 预算单元值
	inline _t us(_t a, _t i);		// 提取指定单元集
	inline _t us(_t a, _t i, _t v);		// 设置指定单元集
	inline _t usp(_t a, _t i, _t v, _t p);	// 带权值设置指定单元集
	inline _t usp(_t a, _t i, _t v,
		double p, bool mix);		// 带浮点数权值设置指定单元集
	inline _t usp(_t a, _t i, _t v,
		double *pp, bool mix);		// 带浮点数权值数组设置指定单元集

	inline _t sum(_t a);			// 单元累积
	inline _t sump(_t a, _t p);		// 单元带权值累积

public:
	enum predefined_type {
		by4 = 0,		// 4 bytes, from high to low
		by4i,			// 4 bytes, from low to high
		by4_3,			// 4 bytes but used 3, from high to low
		by4_3i,			// 4 bytes but used 3, from low to high
		by3,			// 3 bytes, from high to low
		by3i,			// 3 bytes, from low to high
		bi565,			// 16 bits, from high to low
		bi565i,			// 16 bits, from low to high
		bi555,			// 15 bits, from high to low, highest unused.
		bi555i			// 15 bits, from low to high, highest unused.
	};
	inline bool initialize_masks(predefined_type);

};

SGP_END

#include <sgp/parellel_binary_alg.cpp>
