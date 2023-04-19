
#include <sgp/parellel_binary_alg.h>

SGP_BEGIN

///////////////////////////////////////////////////////////////////////////////
//
// 并行二进制运算
//	使用一个机器运算操作单元实现对多个二进制单元并行处理。
//	每个单元占用的二进制位必须连续。
//	每个单元占用的位数必须至少是 2 位。
template<class _t>
bool parellel_binary_alg<_t>::initialize_masks(
	parellel_binary_alg<_t>::predefined_type _type) {
	switch (_type) {
	case by4:
		m_a = 0xFFFFFFFF;
		m_l = 0x01010101;
		m_h = 0x80808080;
		m_u[0] = 0x000000FF;
		m_u[1] = 0x0000FF00;
		m_u[2] = 0x00FF0000;
		m_u[3] = 0xFF000000;
		n_u = 4;
		break;
	case by4i:
		m_a = 0xFFFFFFFF;
		m_l = 0x01010101;
		m_h = 0x80808080;
		m_u[0] = 0xFF000000;
		m_u[1] = 0x00FF0000;
		m_u[2] = 0x0000FF00;
		m_u[3] = 0x000000FF;
		n_u = 4;
		break;
	case by4_3:
		m_a = 0x00FFFFFF;
		m_l = 0x00010101;
		m_h = 0x00808080;
		m_u[0] = 0x000000FF;
		m_u[1] = 0x0000FF00;
		m_u[2] = 0x00FF0000;
		n_u = 3;
		break;
	case by4_3i:
		m_a = 0x00FFFFFF;
		m_l = 0x00010101;
		m_h = 0x00808080;
		m_u[0] = 0x00FF0000;
		m_u[1] = 0x0000FF00;
		m_u[2] = 0x000000FF;
		n_u = 3;
		break;
	case by3:
		m_a = 0xFFFFFF;
		m_l = 0x010101;
		m_h = 0x808080;
		m_u[0] = 0x0000FF;
		m_u[1] = 0x00FF00;
		m_u[2] = 0xFF0000;
		n_u = 3;
		break;
	case by3i:
		m_a = 0xFFFFFF;
		m_l = 0x010101;
		m_h = 0x808080;
		m_u[0] = 0xFF0000;
		m_u[1] = 0x00FF00;
		m_u[2] = 0x0000FF;
		n_u = 3;
		break;
	case bi565:
		m_a = 0xFFFF;
		m_l = 0x2108;	// aaaaAbbb bbBccccC
		m_h = 0x1084;	// AaaaaBbb bbbCcccc
		m_u[0] = 0x00F8;
		m_u[1] = 0xE007;
		m_u[2] = 0x1F00;
		n_u = 3;
		break;
	case bi565i:
		m_a = 0xFFFF;
		m_l = 0x2108;	// ccccCbbb bbBaaaaA
		m_h = 0x1084;	// CccccBbb bbbAaaaa
		m_u[0] = 0x1F00;
		m_u[1] = 0xE007;
		m_u[2] = 0x00F8;
		n_u = 3;
		break;
	case bi555:
		m_a = 0xFF7F;
		m_l = 0x2104; 	// 0aaaaAbb bbBccccC
		m_h = 0x1042; 	// 0AaaaaBb bbbCcccc
		m_u[0] = 0x1F00;
		m_u[1] = 0xE003;
		m_u[2] = 0x007C;
		n_u = 3;
		break;
	case bi555i:
		m_a = 0xFF7F;
		m_l = 0x2104; 	// 0ccccCbb bbBaaaaA
		m_h = 0x1042; 	// 0CccccBb bbbAaaaa
		m_u[0] = 0x007C;
		m_u[1] = 0xE003;
		m_u[2] = 0x1F00;
		n_u = 3;
		break;
	default:
		return false;
	}
	m_ls = ~m_h & m_a;
	m_hs = ~m_l & m_a;
	return true;
}

template<class _t>
_t parellel_binary_alg<_t>::inc(_t a) {
	// a + m_l
	_t t1 = (a & m_ls) + m_l;
	_t t2 = (a & m_h);
	_t c = t1 ^ t2;
	return c;
}

template<class _t>
_t parellel_binary_alg<_t>::dec(_t a) {
	// a + ~m_l + 1
	_t t1 = (a & m_ls) + m_ls;
	_t t2 = (~a & m_a) & m_h;
	_t c = t1 ^ t2;
	return c;
}

template<class _t>
_t parellel_binary_alg<_t>::add(_t a, _t b) {
	// no possible carry, return sum immediately.
	if (!((a & b) && ((a | b) & m_h))) return a + b;

	_t t1 = (a & m_ls) + (b & m_ls);
	_t t2 = (a & m_h) ^ (b & m_h);
	_t c = t1 ^ t2;
	return c;
}

template<class _t>
_t parellel_binary_alg<_t>::sub(_t a, _t b) {
	// a + (~b + 1)
	b = add(~b & m_a, m_l);
	int c = add(a, b);
	return c;
}

template<class _t>
_t parellel_binary_alg<_t>::full_inc(_t a) {
	return full_add(a, m_l);
}

template<class _t>
_t parellel_binary_alg<_t>::full_dec(_t a) {
	return full_sub(a, m_l);
}

template<class _t>
_t parellel_binary_alg<_t>::full_add(_t a, _t b) {
	// no possible carry, return sum immediately.
	if (!((a & b) && ((a | b) & m_h))) return a + b;

	_t ah = a & m_h;
	_t bh = b & m_h;
	_t t1 = ah & bh;	// high bit addition carried?

	// if all units result in full, then return 0xFFFF... immediately
	if (t1 == m_h) return m_a;

	_t t2 = (a & m_ls) + (b & m_ls);
	_t t3 = ah ^ bh;	// high bit addition.
	_t t4 = ah | bh;	// a or b's high bit set.
	_t t5 = t2 & m_h;	// low bits addition carried?
	_t t6 = (t4 & t5) | t1; // each unit's high bit means full state
		// full state: (1) t1, of course;
		// (2) low bits addition carried and (ah or bh high bit set).
	_t t7 = t2 ^ t3;	// same as ::add

	_t c = 0;
	for (int i = 0; i < n_u; i++) {
		if (t6 & m_u[i]) {
			c |= m_u[i];
		} else {
			c |= t7 & m_u[i];
		}
	}
	return c;

	/*
	//another way
	_t c = 0;
	for (int i = 0; i < n_u; i++) {
		_t t1 = (a & m_u[i]) + (b & m_u[i]);
		if (t1 & ~m_u[i]) {
			c |= m_u[i];
		} else {
			c |= t1;
		}
	}
	return c;
	*/
}

template<class _t>
_t parellel_binary_alg<_t>::full_sub(_t a, _t b) {
	_t c = 0;
	for (int i = 0; i < n_u; i++) {
		_t ta = a & m_u[i];
		_t tb = b & m_u[i];
		if (ta > tb) {
			c |= ta - tb;
		} else {
			__assume(false);
			c |= 0;
		}
	}
	return c;
}

template<class _t>
_t parellel_binary_alg<_t>::diff(_t a, _t b) {
	_t c = 0;
	for (int i = 0; i < n_u; i++) {
		_t ta = a & m_u[i];
		_t tb = b & m_u[i];
		if (ta > tb) {
			c |= ta - tb;
		} else {
			c |= tb - ta;
		}
	}
	return c;
}

template<class _t>
_t parellel_binary_alg<_t>::cmp(_t a, _t b) {
	_t c = 0;
	for (int i = 0; i < n_u; i++) {
		_t tm = m_u[i];
		_t ta = a & tm;
		_t tb = b & tm;
		if (ta > tb) {
			c |= m_l & tm;
		} else {
			c |= m_h & tm;
		}
	}
	return c;
}

template<class _t>
_t parellel_binary_alg<_t>::se(_t a, _t b) {
	_t c = 0;
	for (int i = 0; i < n_u; i++) {
		_t tm = m_u[i];
		_t ta = a & tm;
		_t tb = b & tm;
		if (ta == tb) c |= tm;
	}
	return c;
}

template<class _t>
_t parellel_binary_alg<_t>::sne(_t a, _t b) {
	return (~se(a, b)) & m_a;
}

template<class _t>
_t parellel_binary_alg<_t>::sa(_t a, _t b) {
	_t c = 0;
	for (int i = 0; i < n_u; i++) {
		_t tm = m_u[i];
		_t ta = a & tm;
		_t tb = b & tm;
		if (ta > tb) c |= tm;
	}
	return c;
}

template<class _t>
_t parellel_binary_alg<_t>::sae(_t a, _t b) {
	return sa(a, b) | se(a, b);
}

template<class _t>
_t parellel_binary_alg<_t>::sb(_t a, _t b) {
	return (~sae(a, b)) & m_a;
}

template<class _t>
_t parellel_binary_alg<_t>::sbe(_t a, _t b) {
	return (~sa(a, b)) & m_a;
}

template<class _t>
_t parellel_binary_alg<_t>::sz(_t a) {
	return se(a, 0);
}

template<class _t>
_t parellel_binary_alg<_t>::snz(_t a) {
	return sne(a, 0);
}

template<class _t>
_t parellel_binary_alg<_t>::u(_t a, int i) {
	if (i < 0 || i >= n_u) return 0;
	_t r = a & m_u[i];
	r >>= _alg.r0s(m_u[i]);
	return r;
}

template<class _t>
_t parellel_binary_alg<_t>::u(_t a, int i, _t v) {
	if (i < 0 || i >= n_u) return 0;
	a &= ~m_u[i];
	return a | (v << _alg.r0s(m_u[i]));
}

template<class _t>
_t parellel_binary_alg<_t>::uv(int i, _t v) {
	if (i < 0 || i >= n_u) return 0;
	return v << _alg.r0s(m_u[i]);
}

template<class _t>
_t parellel_binary_alg<_t>::us(_t a, _t i) {
	_t c = 0;
	for (int j = 0; j < n_u; j++) {
		if (i & m_u[j]) {
			c |= a & m_u[j];
		}
	}
	return c;
}

template<class _t>
_t parellel_binary_alg<_t>::us(_t a, _t i, _t v) {
	for (int j = 0; j < n_u; j++) {
		_t m = m_u[j];
		if (i & m) {
			a = (a & ~m) | (v & m);
		}
	}
	return a;
}

template<class _t>
_t parellel_binary_alg<_t>::usp(_t a, _t i, _t v, _t p) {
	for (int j = 0; j < n_u; j++) {
		_t tm = m_u[j];
		if (i & tm) {
			int shifts = _alg.r0s(tm);
			_t ta = (a & tm) >> shifts;
			_t tv = (v & tm) >> shifts;
			_t tp = (p & tm) >> shifts;
			_t tms = tm >> shifts;
			//if (_cache_div256) ...
			double ct = (double)tms;
			double pp = (double)tp / (double)ct;
			_t pv = (_t)(tv * pp + ta * (1 - pp));
			pv = pv << shifts;
			a = (a & ~tm) | (pv & tm);
		}
	}
	return a;
}

template<class _t>
_t parellel_binary_alg<_t>::usp(_t a, _t i, _t v, double p, bool mix) {
	for (int j = 0; j < n_u; j++) {
		_t tm = m_u[j];
		if (i & tm) {
			int shifts = _alg.r0s(tm);
			_t ta = (a & tm) >> shifts;
			_t tv = (v & tm) >> shifts;
			_t tms = tm >> shifts;
			_t pv = (_t)(tv * p + ta * (mix ? (1 - p) : 1));
			pv = pv << shifts;
			a = (a & ~tm) | (pv & tm);
		}
	}
	return a;
}

template<class _t>
_t parellel_binary_alg<_t>::usp(_t a, _t i, _t v, double *pp, bool mix) {
	for (int j = 0; j < n_u; j++) {
		_t tm = m_u[j];
		if (i & tm) {
			int shifts = _alg.r0s(tm);
			_t ta = (a & tm) >> shifts;
			_t tv = (v & tm) >> shifts;
			_t tms = tm >> shifts;
			_t pv = (_t)(tv * pp[j] + ta * (mix ? (1 - pp[j]) : 1));
			pv = pv << shifts;
			a = (a & ~tm) | (pv & tm);
		}
	}
	return a;
}

template<class _t>
_t parellel_binary_alg<_t>::sum(_t a) {
	_t c = 0;

	for (int i = 0; i < n_u; i++) {
		_t ta = a & m_u[i];
		c += ta >> _alg.r0s(m_u[i]);
	}
	return c;
}

template<class _t>
_t parellel_binary_alg<_t>::sump(_t a, _t p) {
	_t c = 0;

	for (int i = 0; i < n_u; i++) {
		_t tm = m_u[i];
		int shifts = _alg.r0s(tm);
		_t ta = (a & tm) >> shifts;
		_t tp = (p & tm) >> shifts;
		_t tms = tm >> shifts;
		//if (_cache_div256) ...
		double ct = (double)tms;
		c += (_t)((double)ta * (double)tp / (double)ct);
	}
	return c;
}

SGP_END
