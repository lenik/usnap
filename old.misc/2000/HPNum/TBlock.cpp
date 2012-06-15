#include "TBlock.h"

template<class T>
TBlock<T>::TBlock() {
	m_nSize = m_nMaxSize = 0;
	m_pData = NULL;
	m_nGrowBy = max(1, 1024 / sizeof(T));
	SetSize(0);
}

template<class T>
TBlock<T>::~TBlock() {
	ASSERT_VALID(this);
	RemoveAll();
}

template<class T>
void TBlock<T>::SetSize(UINT nNewSize, UINT nGrowBy) {
	ASSERT_VALID(this);

	if (nGrowBy != 0) { m_nGrowBy = nGrowBy; }
	if (nNewSize == 0) {
		if (m_pData != NULL) {
			delete[] m_pData;
			m_pData = NULL;
		}
		m_nSize = m_nMaxSize = 0;
	} else {
		// 1.存在长度充分, 指定小于当前长度或指定大于当前长度
		// 2.存在长度欠缺, 指定大于当前最大长度
		if (nNewSize <= m_nMaxSize) {
			if (nNewSize > m_nSize) {
				memset(&m_pData[m_nSize], 0, (nNewSize - m_nSize) * sizeof(T));
			}
			m_nSize = nNewSize;
		} else {
			UINT nNewMaxSize; // 计算新的最大长度
			if (nNewSize < m_nMaxSize + m_nGrowBy) { // 当前最大长度增长一截足够
				nNewMaxSize = m_nMaxSize + m_nGrowBy;
			} else {	// 增长一截还不够, 这个指定长度确实够长的! (不必一定刚好整数截)
				nNewMaxSize = nNewSize;
			}
			ASSERT(nNewMaxSize >= m_nMaxSize);		// no wrap around
			ASSERT(nNewMaxSize > m_nSize);			// allocated more
			// nNewMaxSize >= m_nMaxSize needn'T be nNewMaxSize > m_nSize
			// for it may be m_nSize < nNewMaxSize < m_nMaxSize

			T *pNewData = new T[nNewMaxSize];
			if (m_pData != NULL) {	// 考虑源块是NULL的情况
				memcpy(pNewData, m_pData, m_nSize * sizeof(T));
				delete[] m_pData;
				memset(&pNewData[m_nSize], 0, (nNewMaxSize - m_nSize) * sizeof(T));		// construct remaining elements
			} else {
				memset(pNewData, 0, nNewMaxSize * sizeof(T));
			}
			m_pData = pNewData;
			m_nSize = nNewSize;
			m_nMaxSize = nNewMaxSize;
		}
	}
}

template<class T>
void TBlock<T>::FreeExtra() {
	ASSERT_VALID(this);

	if (m_nSize != m_nMaxSize) {
		T *pNewData = NULL;
		if (m_nSize != 0) {
			pNewData = new T[m_nSize];
			memcpy(pNewData, m_pData, m_nSize * sizeof(T));
		}
		delete[] m_pData;
		m_pData = pNewData;
		m_nMaxSize = m_nSize;
	}
}

template<class T>
int TBlock<T>::Append(TBlock &src) {
	ASSERT_VALID(this);
	ASSERT(this != &src);

	int nOldSize = m_nSize;
	UINT n;
	SetSize(m_nSize + src.m_nSize);

	for (n = 0; n < src.m_nSize; n++) {
		m_pData[nOldSize + n] = src.m_pData[n];
	}
	return nOldSize;
}

template<class T>
void TBlock<T>::Copy(TBlock &src) {
	ASSERT_VALID(this);
	ASSERT(this != &src);

	UINT n;
	SetSize(src.m_nSize);

	for (n = 0; n < src.m_nSize; n++) {
		m_pData[n] = src.m_pData[n];
	}
}

template<class T>
void TBlock<T>::InsertAt(UINT nIndex, T newElement, UINT nCount) {
	ASSERT_VALID(this);
	if (nIndex >= m_nSize) {
		SetSize(nIndex + nCount);
	} else {
		int nOldSize = m_nSize;
		SetSize(m_nSize + nCount);
		memmove(&m_pData[nIndex + nCount], &m_pData[nIndex], (nOldSize - nIndex) * sizeof(T));
		memset(&m_pData[nIndex], 0, nCount * sizeof(T));
	}

	ASSERT(nIndex + nCount <= m_nSize);

	while (nCount--) {
		m_pData[nIndex++] = newElement;
	}
}

template<class T>
void TBlock<T>::RemoveAt(UINT nIndex, UINT nCount) {
	ASSERT_VALID(this);
	ASSERT(nIndex + nCount <= m_nSize); // nCount in limit
	ASSERT(nIndex + nCount > nIndex);	// no wrap around

	UINT nMoveCount = m_nSize - (nIndex + nCount);	// how many elements after nindex+ncount

	if (nMoveCount > 0) {
		memmove(&m_pData[nIndex], &m_pData[nIndex + nCount], nMoveCount * sizeof(T));
	}

	m_nSize -= nCount;
}

template<class T>
void TBlock<T>::InsertAt(UINT nStartIndex, TBlock *pNewBlock) {
	ASSERT_VALID(this);
	ASSERT_VALID(pNewBlock);
	ASSERT(pNewBlock != NULL && pNewBlock != this);

	if (pNewBlock->GetSize() > 0) {
		InsertAt(nStartIndex, pNewBlock->GetAt(0), pNewBlock->GetSize());
		for (int i = 0; i < pNewBlock->GetSize(); i++) {
			SetAt(nStartIndex + i, pNewBlock->GetAt(i));
		}
	}
}

#ifdef _DEBUG
template<class T>
void TBlock<T>::AssertValid() {
	ASSERT(m_nSize <= m_nMaxSize);
}
#endif
