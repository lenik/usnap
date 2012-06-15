
#include "TBlock.h"

struct Flag {
	int CF:	1;	// Carry
	int AF:	1;	// Aux
	int OF:	1;	// Overflow
	int LF:	1;	// Loss
	int PF:	1;	// Parity
	int rF:	1;
	int ZF:	1;	// Zero
	int SF:	1;	// Sign
	Flag();
};

class HPNum {
public:
// Constructions
	HPNum();

// Attributes
	UINT m_nLength;		// 数据流长度映像, 执行GetLength()后有效.
	UINT GetLength();
	UINT SetLength(UINT);
	UINT GetDL();
	UINT SetDL(UINT);
	UINT GetIL();
	UINT SetIL(UINT);
	UINT GetRadix();
	UINT SetRadix(UINT);

// Operators
	BYTE &operator[](UINT nIndex);

	UINT operator=(UINT nNewLength);
	UINT operator++();
	UINT operator+=(UINT nAddLength);

// Implementions
protected:
	UINT m_nDL;	// int[l-1..d], dec[d-1..0]
	UINT m_nRadix;
public:
	Flag m_fFlag;
	TBlock<BYTE> m_sData;	// 数据流

// m_sData operators
public:
	UINT Trim();

public:
	~HPNum();

#ifdef _DEBUG
	void AssertValid();
#endif

};

inline UINT HPNum::GetLength() {
	return m_nLength = m_sData.GetSize();
}

inline UINT HPNum::SetLength(UINT nNewLength) {
	if (nNewLength == 0) { // 指定置零
		m_sData.SetSize(0);
		m_nLength = m_nDL = 0;
	} else {	// 扩张空间, 不改变原数值.
		if (nNewLength < m_nLength) { Trim(); }
		if (nNewLength > m_nLength) {	// 扩张时不做压缩处理, 因为有些
			m_sData.SetSize(nNewLength);
		}
	}
	return GetLength();
}

inline UINT HPNum::GetDL() {
	return m_nDL;
}

inline UINT HPNum::SetDL(UINT nNewDL) {
	ASSERT(nNewDL <= m_nLength);	// 最极端的情况是零位整数位
	return m_nDL = nNewDL;
}

inline UINT HPNum::GetIL() {
	return m_nLength - m_nDL;
}

inline UINT HPNum::SetIL(UINT nNewIL) {
	ASSERT(nNewIL <= m_nLength);
	m_nDL = m_nLength - nNewIL;
	return nNewIL;
}

inline UINT HPNum::GetRadix() {
	return m_nRadix;
}

inline UINT HPNum::SetRadix(UINT nNewRadix) {
	return m_nRadix = nNewRadix;
}

inline BYTE &HPNum::operator[](UINT nIndex) {
	ASSERT(nIndex < m_nLength);
	return m_sData[nIndex];
}

inline UINT HPNum::operator=(UINT nNewLength) {
	return SetLength(nNewLength);
}

inline UINT HPNum::operator++() {
	return SetLength(m_nLength + 1);
}

inline UINT HPNum::operator+=(UINT nAddLength) {
	return SetLength(m_nLength + nAddLength);
}

template <class T> int _cmp(T &a, T &b) { if (a == b) { return 0; } else { return (a > b) ? 1 : -1; } }
template <class T> int _cmp(T a, T b) { if (a == b) { return 0; } else { return (a > b) ? 1 : -1; } }

class _HPBaseArith {
protected:
	UINT nCarry, nPos;	// 被修改进位数, 单元指针
protected:
	HPNum *m_hnNum;
public:
	void Compare(HPNum &, HPNum &);
	void AssignI(HPNum &, UINT nIndex, UINT nI);
	int CmpI(HPNum &, UINT nIndex, UINT nI);	// 返回正负号, -1, 0, 1
	void AddI(HPNum &, UINT nIndex, UINT nI);
	int SubI(HPNum &, UINT nIndex, UINT nI);	// 返回正负号, -1, 0, 1

	void Shift(HPNum &, int);
	void Adjust(HPNum &, UINT nIL, UINT nDL);
public:
	void Add(HPNum &b, HPNum &a);
	int Sub(HPNum &b, HPNum &a);	// 返回正负号, -1, 0, 1
	void Mul(HPNum &c, HPNum &a, HPNum &b);
	void Div(HPNum &c, HPNum &a, HPNum &b);
};

inline void _HPBaseArith::AssignI(HPNum &hn, UINT nIndex, UINT nI) {
	AddI(hn, nIndex, nI - hn[nIndex]);
}
