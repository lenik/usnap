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
	// ������ֵ, 1.��������������׶��� 2.�������С����ĩ����
	UINT nZeros = 0;
	UINT nIndex = m_sData.GetSize() - 1;
	while (m_sData[nIndex--] == 0) { nZeros++; }	// ���Ҷ���ĸ��� (��������)
	if (nZeros != 0) { m_sData.SetSize(nIndex + 1); }
	nIndex = 0;
	while (m_sData[nIndex++] == 0) { nZeros++; }	// �������ĸ��� (����С��)
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
	if (i > 0) {		// shift right, smaller ����, С��λ������, ��С
		if (hn.GetIL() >= nNum) {	// pointer in bound С����δ����
			hn.SetDL(hn.GetDL() + nNum);
			// nNum = 0;
		} else {	// append zeros С���㳬��, ���ұ߲���
			nNum -= hn.GetIL();
			hn.SetDL(hn += nNum);
		}
	} else {	// shift left, bigger ����, С��λ������, ���
		if (hn.GetDL() >= nNum) {	// pointer in bound С����δ����
			hn.SetDL(hn.GetDL() - nNum);
			// nNum = 0;
		} else {	// insert zeros at head С���㳬��
			nNum -= hn.GetDL();
			hn.SetDL(0);
			hn.m_sData.InsertAt(0, 0, nNum);		// ����߲�i����
		}
	}
}

void _HPBaseArith::AddI(HPNum &hn, UINT nIndex, UINT nI) {
	nCarry = nI;
	while (nCarry && nIndex < hn.m_nLength) {
		nCarry += hn[nIndex];
		if (nCarry < hn.GetRadix()) { // �޽�λ����, ����
			hn[nIndex] = nCarry;
			nCarry = 0;
		} else {
			hn[nIndex] = nCarry % hn.GetRadix();
			nCarry /= hn.GetRadix();
		}
		nIndex++;
	}
	while (nCarry) {	// ��Ҫ�ǿ��� nI ���ڽ�����, ���������>=1 λ
		if (nCarry < hn.GetRadix()) {	// �޽�λ����, ����
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
	// while (--t > nIndex) if (hn[t] != 0) /* hn'��Чλ > nIndex, ���� */ return 1;
	if (hn[nIndex] < nI) { // ��Ӧλ hn' < nI'
		while (t < hn.m_nLength) {	// �Ƚ� ���λ..��Ӧλhn'����� �� nI
			if (nI == 0) { break; }	// nI�Ⱦ�
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
	if (CmpI(hn, nIndex, nI) < 0) { // ���λ����, Ӧ�÷���
		// 1.ָ��Ϊ�Ҳ�������λȡ�� 2.ָ�����λ�ڷ������λ֮��ȡ�� 3.nI��ָ�����λ
		/*
			A. ��λ����, ������ָ��λ���Ϊ��, Ѱ�Ҽ����з������λ����Ѱ�Ҵ�����Ӧ���������λ.
			���������λ������ָ��λ˵���������ǲ���С�ڼ����ǲ���, ��Ҫ��λ,
				B1. ���λ��ָ�����λ֮��(������ָ�����λ)��, ��������ȥ1
			����: B2. ���ؽ�λ
			C. Ȼ�󱻼�����ȥ�������λ��ָ��λ�ǲ���. �ȼ��������ǲ��ֳ���, ������������ʣ��,
			D. ���ǵ����������ܴ��ڽ�����, ���õ�λ��ֵ. ��Ϊ�������ڼ����ṹ��, �ȸ���������λ��.
		*/
		for (t = 0; t < nIndex; t++) {	// A) t ���ط������λ, �������ָ��λ��ʾB2
			if (hn[t] != 0) { break; }
		}
		if (t < nIndex) {	// B1)
			hn[t] = nRadix-- - hn[t];	// nRadix - 1 �γɲ��뱻����
			for (t++; t < nIndex; t++) {	// ָ�����λ�ڷ������λ֮��ȡ��
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

			hn[nIndex] = (nI - hn[nIndex] - 1) % nRadix; 	// ����һλ
			nI -= 0;

		if (t == nIndex) {
			hn[nIndex] = (nI - hn[nIndex]) % nRadix;
			nI -= nRadix - hn[nIndex];
		} else {
			hn[t] = nRadix-- - hn[t];	// nRadix - 1 �γɲ��뱻����
			for (; t < nIndex; t++) {	// ָ�����λ�ڷ������λ֮��ȡ��
				hn[t] = nRadix - hn[t];
			}
			hn[nIndex] = (nI - hn[nIndex] - 1) % nRadix; 	// ����һλ
			nI -= 0;
		}
		return -1;
	} else {	// һ�����
		nBorrow = nI;
		while (nBorrow && nIndex < hn.m_nLength) {
			if (hn[nIndex] >= nBorrow) {	// �޽�λ����, ����
				hn[nIndex] -= nBorrow;
				nBorrow = 0;
				break;
			} else {
				if (nBorrow % nRadix != 0) {
					hn[nIndex] += nRadix - nBorrow % nRadix;	// nBorrowҲ����ڽ�λ��
				}
				nBorrow = (nBorrow - 1) / nRadix + 1;	// nBorrow����������
			}
			nIndex++;
		}
		return 1;
	}
}

void _HPBaseArith::Adjust(HPNum &hn, UINT nIL, UINT nDL) {
	if (nDL > hn.GetDL()) {	// // 1.����С������
		hn.m_sData.InsertAt(0, 0, nDL - hn.GetDL());	// ����С��λ��
		hn.SetDL(nDL);
	} else if (nDL < hn.GetDL()) {	// ����С��λ��, ��������.
		int nKeepBegin = hn.GetDL() - nDL;
		if (hn[hn.GetDL() - nDL - 1] >= hn.GetRadix() / 2) {	// ��m_nDL - nDLλ֮ǰ��������ɾ��
			AddI(hn, hn.GetDL() - nDL, 1);	// ����
		}
		hn.m_sData.RemoveAt(0, hn.GetDL() - nDL);
		hn.SetDL(nDL);
	}
	if (nIL > hn.GetIL()) {	// 2.������������
		hn += nIL - hn.GetIL();		// ��������λ��, ׷����
	} else if (nIL < hn.GetIL()) { // ��������λ��
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
