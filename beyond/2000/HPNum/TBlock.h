
// Turbo Block Template
// template TBlock...

#ifndef __TBLOCK_H
#define __TBLOCK_H

#include "NHead.h"

template<class T>
class TBlock {
public:

// Construction
	TBlock();

// Attributes
	UINT GetSize();
	void SetSize(UINT nNewSize, UINT nGrowBy = 0);

// Operations
	T GetAt(UINT nIndex);
	void SetAt(UINT nIndex, T newElement);
	void SetAtGrow(UINT nIndex, T newElement);
	T *GetData();

	void FreeExtra();
	void RemoveAll();

	UINT Add(T newElement);

	int Append(TBlock& src);
	void Copy(TBlock& src);

// Operations that move elements around
	void InsertAt(UINT nIndex, T newElement, UINT nCount = 1);
	void RemoveAt(UINT nIndex, UINT nCount = 1);

	void InsertAt(UINT nStartIndex, TBlock* pNewBlock);

	T &operator[](UINT nIndex);

// Implementations
protected:
	UINT m_nSize;
	UINT m_nMaxSize;
	UINT m_nGrowBy;
	T *m_pData;

public:
	~TBlock();

#ifdef _DEBUG
	void AssertValid();
#endif

};

template<class T>
inline UINT TBlock<T>::GetSize() {
	return m_nSize;
}

template<class T>
inline T TBlock<T>::GetAt(UINT nIndex) {
	return m_pData[nIndex];
}

template<class T>
inline void TBlock<T>::SetAt(UINT nIndex, T newElement) {
	ASSERT(nIndex < m_nSize);

	m_pData[nIndex] = newElement;
}

template<class T>
inline T *TBlock<T>::GetData() {
	return m_pData;
}

template<class T>
inline void TBlock<T>::RemoveAll() {
	ASSERT_VALID(this);

	SetSize(0);
}

template<class T>
inline UINT TBlock<T>::Add(T newElement) {
	SetAtGrow(m_nSize, newElement);
	return nIndex;
}

template<class T>
inline T &TBlock<T>::operator[](UINT nIndex) {
	ASSERT(nIndex < m_nSize);

	return m_pData[nIndex];
}

#endif