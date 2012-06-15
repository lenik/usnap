
#include <sgp/binary_alg.h>

SGP_BEGIN

///////////////////////////////////////////////////////////////////////////////
//
// word_binary_alg implementation
//
template<class _t>
int word_binary_alg<_t>::_0s(_t a) {
	int c = 0;
	while (a) {
		a = a & (a - 1);
		c++;
	}
	return c;
}

template<class _t>
int word_binary_alg<_t>::_1s(_t a) {
	return _0s(~a);
}

template<class _t>
int word_binary_alg<_t>::lc1s(_t a) {
	int c = 0;
	while (a) {
		a <<= 1;
		c++;
	}
	return c;
}

template<class _t>
int word_binary_alg<_t>::rc1s(_t a) {
	int c = 0;
	while (a) {
		a >>= 1;
		c++;
	}
	return c;
}

template<class _t>
int word_binary_alg<_t>::l0s(_t a) {
	// return r0s(reverse(a));
	return l1s(~a);
}

template<class _t>
int word_binary_alg<_t>::l1s(_t a) {
	// return r1s(reverse(a));
	int c = 0;
	_t h = ~(~0u >> 1);
	while (a & h) {
		a <<= 1;
		c++;
	}
	return c;
}

template<class _t>
int word_binary_alg<_t>::r0s(_t a) {
	// rc1s(a ^ (a - 1)) - 1 error at 0.
	return r1s(~a);
}

template<class _t>
int word_binary_alg<_t>::r1s(_t a) {
	// rc1s(a ^ (a + 1)) - 1 error at 111..1
	int c = 0;
	while (a & 1) {
		a >>= 1;
		c++;
	}
	return c;
}

template<class _t>
_t word_binary_alg<_t>::reverse(_t a) {
	_t r = 0;
	int c = sizeof(_t) * 8;
	for (; c > 0; c--) {
		r = (r | (a & 1)) << 1;
		a >>= 1;
	}
	return r;
}



///////////////////////////////////////////////////////////////////////////////
//
// mask_word_binary_alg implementation
//
template<class _t>
int mask_word_binary_alg<_t>::m__0s() {
	return agg_mask._0s(m_a);
}

template<class _t>
int mask_word_binary_alg<_t>::m__1s() {
	return agg_mask._1s(m_a);
}

template<class _t>
int mask_word_binary_alg<_t>::m_lc1s() {
	return agg_mask.lc1s(m_a);
}

template<class _t>
int mask_word_binary_alg<_t>::m_rc1s() {
	return agg_mask.rc1s(m_a);
}

template<class _t>
int mask_word_binary_alg<_t>::m_l0s() {
	return agg_mask.l0s(m_a);
}

template<class _t>
int mask_word_binary_alg<_t>::m_l1s() {
	return agg_mask.l1s(m_a);
}

template<class _t>
int mask_word_binary_alg<_t>::m_r0s() {
	return agg_mask.r0s(m_a);
}

template<class _t>
int mask_word_binary_alg<_t>::m_r1s() {
	return agg_mask.r1s(m_a);
}

template<class _t>
_t mask_word_binary_alg<_t>::m_reverse() {
	return agg_mask.reverse(m_a);
}

template<class _t>
int mask_word_binary_alg<_t>::_0s(_t a) {
	return 0;
}

template<class _t>
int mask_word_binary_alg<_t>::_1s(_t a) {
	return 0;
}

template<class _t>
int mask_word_binary_alg<_t>::lc1s(_t a) {
	return 0;
}

template<class _t>
int mask_word_binary_alg<_t>::rc1s(_t a) {
	return 0;
}

template<class _t>
int mask_word_binary_alg<_t>::l0s(_t a) {
	return 0;
}

template<class _t>
int mask_word_binary_alg<_t>::l1s(_t a) {
	return 0;
}

template<class _t>
int mask_word_binary_alg<_t>::r0s(_t a) {
	return 0;
}

template<class _t>
int mask_word_binary_alg<_t>::r1s(_t a) {
	return 0;
}

template<class _t>
_t mask_word_binary_alg<_t>::reverse(_t a) {
	return 0;
}

SGP_END
