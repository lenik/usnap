
#include <Windows.h>

#include "SNum.h"

Flag::Flag() {
	CF = AF = OF = LF = PF = rF = ZF = SF = 0;
}

HPNum::HPNum() {
	m_sData = NULL;
	m_nLength = m_nDL = 0;
}

void _HPBaseArith::Shift(HPNum *hn, int i) {
	int t, nIL = hn.m_nLength - hn.m_nDL;	// integer width
	if (i == 0) { return; }
	if (i > 0) {		// shift right, smaller
		if (nIL >= i) {	// pointer in bound
			hn.m_nDL += i;
			//i = 0;
		} else {
			i -= nIL;
			while (i--) {	// pad zero on left
				hn.m_sData[hn.m_nLength++] = 0;
			}
			hn.m_nDL = hn.m_nLength;
		}
	} else {	// shift left, bigger
		i = -i;
		if (hn.m_nDL >= i) {	// pointer in bound
			hn.m_nDL -= i;
			// i = 0;
		} else {
			i -= hn.m_nDL;
			hn.m_nDL = 0;
			for (t = hn.m_nLength - 1; t >= 0; t--) {
				hn.m_sData[t + i] = hs.m_sData[t];
			}
			for (t = 0; t < i; t++) {
				hn.m_sData[t] = 0;
			}
			hn.m_nLength += i;
		}
	}
}

void _HPBaseArith::AddI(HPNum &hn, UINT nPos, UINT nI) {
	UINT nCarry = nI;
	while (nCarry && nPos < hn.m_nLength) {
		nCarry = hn.m_sData[nPos] + nCarry;
		if (nCarry < hn.m_nRadix) {
			hn.m_sData[nPos] = nCarry;
			nCarry = 0;
		} else {
			hn.m_sData[nPos] = nCarry % hn.m_nRadix;
			nCarry /= hn.m_nRadix;
		}
		nPos++;
	}
	while (nCarry) {
		if (nCarry < hn.m_nRadix) {
			hn.m_sData[hn.m_nLength++] = nCarry;
			nCarry = 0;
		} else {
			hn.m_sData[hn.m_nLength++] = nCarry % hn.m_nRadix;
			nCarry /= hn.m_nRadix;
		}
	}
}

void _HPBaseArith::SubI(HPNum &hn, UINT nPos, UINT nI) {
	UINT nCarry = nI;
	while (nCarry && nPos < hn.m_nLength) {
		nCarry = hn.m_sData[nPos] + nCarry;
		if (nCarry < hn.m_nRadix) {
			hn.m_sData[nPos] = nCarry;
			nCarry = 0;
		} else {
			hn.m_sData[nPos] = nCarry % hn.m_nRadix;
			nCarry /= hn.m_nRadix;
		}
		nPos++;
	}
	while (nCarry) {
		if (nCarry < hn.m_nRadix) {
			hn.m_sData[hn.m_nLength++] = nCarry;
			nCarry = 0;
		} else {
			hn.m_sData[hn.m_nLength++] = nCarry % hn.m_nRadix;
			nCarry /= hn.m_nRadix;
		}
	}
}

void _HPBaseArith::Adjust(HPNum &hn, int nIL, int nDL) {
	int t;
	int delta;
	delta = nDL - hn.m_nDL;	// inc decimal width
	if (delta != 0) {
		if (delta > 0) {	// move right, fill 0
			for (t = hn.m_nLength - 1; t >= 0; t--) {
				hn.m_sData[delta + t] = hn.m_sData[t];
			}
			for (t = 0; t < delta; t++) {
				hn.m_sData[t] = 0;
			}
		} else {	// Cut and round decimals
			int nKeepBegin = -delta;
			if (hn.m_sData[nKeepBegin - 1] >= hn.m_nRadix / 2) {	// Round
				AddI(hn, nKeepBegin, 1);
			}
			for (t = nKeepBegin; t < hn.m_nLength; t++) {
				hn.m_sData[t - nKeepBegin] = hn.m_sData[t];
			}
		}
		hn.m_nLength += delta;
		hn.m_nDL += delta;
	}
	delta = nIL - (hn.m_nLength - hn.m_nDL);	// inc integer width
	if (delta != 0) {
		if (delta > 0) {	// pad 0
			while (delta--) {
				hn.m_sData[hn.m_nLength++] = 0;
			}
		} else {
			while (delta++) {
				if (hn.m_sData[hn.m_nLength - 1] != 0) { break; }
				hn.m_nLength--;
			}
		}
		// delta != 0
	}
}

void _SNumClass::add(SNum &b, SNum a) {
  int t, d, s, carry = 0;
  d = b.p - a.p;		 // b.d[d] += a.d[0]
  if (b.l < a.l) { b.l = a.l; }
  for (t = 0; t < a.l; t++) {
    s = (b.d + d)[t] + a.d[t] + carry;
    carry = s / Radix;
    (b.d + d)[t] = s % Radix;
  }
  while (carry > 0 && d + t < b.l) {
    s = (b.d + d)[t] + carry;
    carry = s / Radix;
    (b.d + d)[t] = s % Radix;
    t++;
  }
  if (carry > 0) {
    b.d[b.l++] = carry;
  }
}

void _SNumClass::sub(SNum &b, SNum a) {
  int t, d, s, borrow = 0;
  d = b.p - a.p;		 // b.d[d] -= a.d[0]
  for (t = 0; t < a.l; t++) {
    s = (b.d + d)[t] - a.d[t] + borrow;
    borrow = s / Radix;
    (b.d + d)[t] = (s + Radix) % Radix;
  }
  while (borrow < 0 && d + t < b.l) {
    s = (b.d + d)[t] + borrow;
    borrow = s / Radix;
    (b.d + d)[t] = (s + Radix) & Radix;
    t++;
  }
  if (borrow < 0) {
    b.d[b.l++] = Radix + borrow;
  }
}

void _SNumClass::mul(SNum &c, SNum b, SNum a) {
  int t1, t2, m, s, carry = 0;
  c.l = c.p = r->p = 0;
  for (t1 = a.l - 1; t1 >= 0; t1--) {	// from left to right
    m = a.d[t1];
    r->l = b.l;
    for (t2 = 0; t2 < b.l; t2++) {	// nums mul num
      s = b.d[t2] * m + carry;
      carry = s / Radix;
      r->d[t2] = s % Radix;
    }
    while (carry > 0) {	        // put reminder
      r->d[r->l++] = carry % Radix;
      carry /= Radix;
    }
    add(c, *r);
    if (t1 != 0) {		// not the last
      shift(c, -1);
    }
  }
  c.p = a.p + b.p;
}

void _SNumClass::div(SNum &c, SNum b, SNum a) {

}

// Copy
