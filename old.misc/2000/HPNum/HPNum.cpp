#include "NHead.h"

#include "HPNum.h"
#include "TBlock.cpp"

Flag::Flag() {
	CF = AF = OF = LF = PF = rF = ZF = SF = 0;
}

HPNum::HPNum() {
	m_sData.SetSize(0, 16);
	m_nLength = m_nDL = 0;
}

HPNum::~HPNum() {
	ASSERT_VALID(this);
	SetLength(0);
}

UINT HPNum::Trim() {
	// 整理数值, 1.清除属于整数的首端零 2.清除属于小数的末端零
	UINT nZeros = 0;
	UINT nIndex = m_sData.GetSize() - 1;
	while (m_sData[nIndex--] == 0) { nZeros++; }	// 最右端零的个数 (属于整数)
	if (nZeros != 0) { m_sData.SetSize(nIndex + 1); }
	nIndex = 0;
	while (m_sData[nIndex++] == 0) { nZeros++; }	// 最左端零的个数 (属于小数)
	if (nIndex > 0) { m_sData.RemoveAt(0, nIndex); }
	return (nZeros);
}

#ifdef _DEBUG
void HPNum::AssertValid() {
	ASSERT(GetDL() <= m_nLength);
}
#endif

void _HPBaseArith::Shift(HPNum &hn, int i) {
	UINT nNum = i > 0 ? i : -i;
	if (i == 0) { return; }
	if (i > 0) {		// shift right, smaller 右移, 小数位数增多, 变小
		if (hn.GetIL() >= nNum) {	// pointer in bound 小数点未超界
			hn.SetDL(hn.GetDL() + nNum);
			// nNum = 0;
		} else {	// append zeros 小数点超界, 往右边补零
			nNum -= hn.GetIL();
			hn.SetDL(hn += nNum);
		}
	} else {	// shift left, bigger 左移, 小数位数减少, 变大
		if (hn.GetDL() >= nNum) {	// pointer in bound 小数点未超界
			hn.SetDL(hn.GetDL() - nNum);
			// nNum = 0;
		} else {	// insert zeros at head 小数点超界
			nNum -= hn.GetDL();
			hn.SetDL(0);
			hn.m_sData.InsertAt(0, 0, nNum);		// 向左边插i个零
		}
	}
}

void _HPBaseArith::AddI(HPNum &hn, UINT nIndex, UINT nI) {
	nCarry = nI;
	while (nCarry && nIndex < hn.m_nLength) {
		nCarry += hn[nIndex];
		if (nCarry < hn.GetRadix()) { // 无进位产生, 加速
			hn[nIndex] = nCarry;
			nCarry = 0;
		} else {
			hn[nIndex] = nCarry % hn.GetRadix();
			nCarry /= hn.GetRadix();
		}
		nIndex++;
	}
	while (nCarry) {	// 主要是考虑 nI 大于进制数, 结果增加了>=1 位
		if (nCarry < hn.GetRadix()) {	// 无进位产生, 加速
			hn[hn.m_nLength] = nCarry;
			++hn;
			nCarry = 0;
		} else {
			hn.m_sData[hn.m_nLength] = nCarry % hn.GetRadix();
			++hn;
			nCarry /= hn.GetRadix();
		}
	}
}

int _HPBaseArith::CmpI(HPNum &hn, UINT nIndex, UINT nI) {
	int nCmp = 0;
	nCarry = 0;
	UINT t = nIndex, nRadix = hn.GetRadix();
	// while (--t > nIndex) if (hn[t] != 0) /* hn'有效位 > nIndex, 大于 */ return 1;
	if (hn[nIndex] < nI) { // 相应位 hn' < nI'
		while (t < hn.m_nLength) {	// 比较 最高位..相应位hn'组合数 与 nI
			if (nI == 0) { break; }	// nI比尽
			if ((hn[t] + nCarry) % nRadix != nI % nRadix) {
				nCmp = _cmp((hn[t] + nCarry) % nRadix, nI % nRadix);
			}
			nCarry = (hn[t] + nCarry) / nRadix;
			t++;
		}
		if (nCarry > 0) { nCmp = 1; }	// same as if (t >= hn.m_nLength) { nCmp = 1; }
	}
	return nCmp;
}

int _HPBaseArith::SubI(HPNum &hn, UINT nIndex, UINT nI) {
	UINT nCarry = nI, nBorrow = nI;
	UINT t = nIndex, nRadix = hn.GetRadix();
	BOOL bInvert = FALSE;

	bInvert = CmpI(hn, nIndex, nI);
	if (CmpI(hn, nIndex, nI) < 0) { // 结果位负数, 应该反减
		// 1.指定为右侧非零最低位取反 2.指定最高位于非零最低位之间取补 3.nI减指定最高位
		/*
			A. 单位反减, 被减数指定位后皆为零, 寻找减数中非零最低位即是寻找大于相应被减数最低位.
			如果这个最低位还不及指定位说明被减数那部分小于减数那部分, 需要借位,
				B1. 最低位到指定最高位之间(不包括指定最高位)求补, 被减数减去1
			否则: B2. 不必借位
			C. 然后被减数减去减数最高位到指定位那部分. 先减掉减数那部分长度, 若被减数还有剩余,
			D. 考虑到被减数可能大于进制数, 故用单位赋值. 因为结果存放在减数结构中, 先给减数增加位数.
		*/
		for (t = 0; t < nIndex; t++) {	// A) t 返回非零最低位, 如果等于指定位表示B2
			if (hn[t] != 0) { break; }
		}
		if (t < nIndex) {	// B1)
			hn[t] = nRadix-- - hn[t];	// nRadix - 1 形成补码被减数
			for (t++; t < nIndex; t++) {	// 指定最高位于非零最低位之间取补
				hn[t] = nRadix - hn[t];
			}
			nI--;
		}
		nBorrow = 0;
		for (t = nIndex; t < hn.m_nLength; t++) {	// C)
			// nI (nI[0]) - hn[t] -> hn[t], nI<, nBorrow; nI>, nCarry
			if (nI > hn[t]) {
				nCarry =

			s = nI % nRadix;

			nBorrow = 1 - (nRadix + nI - hn[t])

			hn[nIndex] = (nI - hn[nIndex] - 1) % nRadix; 	// 借了一位
			nI -= 0;

		if (t == nIndex) {
			hn[nIndex] = (nI - hn[nIndex]) % nRadix;
			nI -= nRadix - hn[nIndex];
		} else {
			hn[t] = nRadix-- - hn[t];	// nRadix - 1 形成补码被减数
			for (; t < nIndex; t++) {	// 指定最高位于非零最低位之间取补
				hn[t] = nRadix - hn[t];
			}
			hn[nIndex] = (nI - hn[nIndex] - 1) % nRadix; 	// 借了一位
			nI -= 0;
		}
		return -1;
	} else {	// 一般情况
		nBorrow = nI;
		while (nBorrow && nIndex < hn.m_nLength) {
			if (hn[nIndex] >= nBorrow) {	// 无借位产生, 加速
				hn[nIndex] -= nBorrow;
				nBorrow = 0;
				break;
			} else {
				if (nBorrow % nRadix != 0) {
					hn[nIndex] += nRadix - nBorrow % nRadix;	// nBorrow也许大于进位数
				}
				nBorrow = (nBorrow - 1) / nRadix + 1;	// nBorrow不可能是零
			}
			nIndex++;
		}
		return 1;
	}
}

void _HPBaseArith::Adjust(HPNum &hn, UINT nIL, UINT nDL) {
	if (nDL > hn.GetDL()) {	// // 1.调整小数长度
		hn.m_sData.InsertAt(0, 0, nDL - hn.GetDL());	// 增加小数位数
		hn.SetDL(nDL);
	} else if (nDL < hn.GetDL()) {	// 减少小数位数, 四舍五入.
		int nKeepBegin = hn.GetDL() - nDL;
		if (hn[hn.GetDL() - nDL - 1] >= hn.GetRadix() / 2) {	// 在m_nDL - nDL位之前的数将被删除
			AddI(hn, hn.GetDL() - nDL, 1);	// 五入
		}
		hn.m_sData.RemoveAt(0, hn.GetDL() - nDL);
		hn.SetDL(nDL);
	}
	if (nIL > hn.GetIL()) {	// 2.调整整数长度
		hn += nIL - hn.GetIL();		// 增加整数位数, 追加零
	} else if (nIL < hn.GetIL()) { // 减少整数位数
		if (hn.Trim() != 0) { Adjust(hn, nIL, nDL); }
	}
}

/*
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
*/

void Init(HPNum &hn, LPSTR lpStr) {
	UINT nLength = lstrlen(lpStr);
	hn.SetLength(nLength);
	hn.SetRadix(10);
	for (UINT i = 0; i < nLength; i++) {
		hn[i] = (CHAR)lpStr[nLength - i - 1] - '0';
	}
}

void Trans(LPSTR lpStr, HPNum &hn) {
	UINT i;
	for (i = 0; i < hn.m_nLength; i++) {
		(CHAR)lpStr[hn.m_nLength - i - 1] = hn[i] + '0';
	}
	lpStr[hn.m_nLength] = '\0';
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	_HPBaseArith a;
	LPSTR lpa = "12123";
	LPSTR lpb = "56567";
	LPSTR lpc = new char[100];
	HPNum hnA, hnB;
	Init(hnA, lpa);
	Init(hnB, lpb);
	a.SubI(hnA, 0, 90000);
	Trans(lpc, hnA);
	MessageBox(NULL, lpc, "Out", MB_OK);

	return 0;
}
