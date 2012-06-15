
#pragma once

#include <sgp/sgpdef.h>
#include <sgp/binary_alg.h>

SGP_BEGIN

///////////////////////////////////////////////////////////////////////////////
//
// ���ж���������
//	ʹ��һ���������������Ԫʵ�ֶԶ�������Ƶ�Ԫ���д���
//	ÿ����Ԫռ�õĶ�����λ����������
//	ÿ����Ԫռ�õ�λ������������ 2 λ��
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

	inline _t full_inc(_t a);		// ��������
	inline _t full_dec(_t a);		// ���ͼ���
	inline _t full_add(_t a, _t b);		// ���ͼӷ�
	inline _t full_sub(_t a, _t b);		// ���ͼ���

	inline _t diff(_t a, _t b);		// ��ֵ����
	inline _t cmp(_t a, _t b);		// �Ƚ�, 0���, ���λa<b, ���λa>b

	inline _t se(_t a, _t b);		// �Ƚ��Ƿ����
	inline _t sne(_t a, _t b);		// �Ƚ��Ƿ����
	inline _t sa(_t a, _t b);		// �Ƚ��Ƿ����
	inline _t sae(_t a, _t b);		// �Ƚ��Ƿ���ڵ���
	inline _t sb(_t a, _t b);		// �Ƚ��Ƿ�С��
	inline _t sbe(_t a, _t b);		// �Ƚ��Ƿ�С�ڵ���
	inline _t sz(_t a);			// �Ƚ��Ƿ�Ϊ0
	inline _t snz(_t a);			// �Ƚ��Ƿ�Ϊ0

	inline _t u(_t a, int i);		// ��ȡ��Ԫ
	inline _t u(_t a, int i, _t v);		// ���õ�Ԫ
	inline _t uv(int i, _t v);		// Ԥ�㵥Ԫֵ
	inline _t us(_t a, _t i);		// ��ȡָ����Ԫ��
	inline _t us(_t a, _t i, _t v);		// ����ָ����Ԫ��
	inline _t usp(_t a, _t i, _t v, _t p);	// ��Ȩֵ����ָ����Ԫ��
	inline _t usp(_t a, _t i, _t v,
		double p, bool mix);		// ��������Ȩֵ����ָ����Ԫ��
	inline _t usp(_t a, _t i, _t v,
		double *pp, bool mix);		// ��������Ȩֵ��������ָ����Ԫ��

	inline _t sum(_t a);			// ��Ԫ�ۻ�
	inline _t sump(_t a, _t p);		// ��Ԫ��Ȩֵ�ۻ�

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
