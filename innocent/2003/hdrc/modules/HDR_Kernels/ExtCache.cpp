
#include "stdafx.h"

#include "ExtCache.h"


bool std::greater<CacheBlock *>::operator()(const CacheBlock *_X, const CacheBlock *_Y) const {
    switch (m_cmp_mode) {
    case _cm_extaddr:
        return _X->dwExtAddr > _Y->dwExtAddr;
    case _cm_weight:
    default:
        return _X->Weight > _Y->Weight;
    }
}


void ExternalCacheMgr::AssertValid() {
    ASSERT(this);
    ASSERT(m_nUsedSize <= m_nMaxCacheSize);
}


void ExternalCacheMgr::UpdateList() {
    // AssertValid();

    // re-sort by weight.
    std::greater<CacheBlock *> theCmp_Weight;
    theCmp_Weight.m_cmp_mode = theCmp_Weight._cm_weight; // std::greater<CacheBlock *>::_cm_weight;
    m_listBlocks.sort(theCmp_Weight);

    m_bListModified = FALSE;
}


BOOL ExternalCacheMgr::DetachBlock(CacheBlock *pBlock) {

    //
    // if (this->bLock) return FALSE;

    // remove all blocks that match the value.
    m_listBlocks.remove(pBlock);

    return TRUE;
}


BOOL ExternalCacheMgr::FreeCache(CacheBlock *pBlock) {
    // pBlock->AssertValid();

    if (pBlock->bLock) return FALSE;

    if (DetachBlock(pBlock)) {
        pBlock->AssertValid();

        free(pBlock->pbMemory);
        delete pBlock;

        return TRUE;
    }

    return FALSE;
}



CacheBlock *ExternalCacheMgr::FindCacheBlock(DWORD dwExtAddress) {
    CacheBlocks::iterator it;
    for (it = m_listBlocks.begin(); it != m_listBlocks.end(); ++it) {
        CacheBlock *pBlock = *it;
        if (pBlock->dwExtAddr == dwExtAddress) {
            return pBlock;
        }
    }
    return NULL;
}


LPBYTE ExternalCacheMgr::CachePointer(DWORD dwExtAddress, DWORD *pcbBlockSize, BOOL bLinearExt) {
    CacheBlocks::iterator it;
    for (it = m_listBlocks.begin(); it != m_listBlocks.end(); ++it) {
        CacheBlock *pBlock = *it;
        if (bLinearExt) {
            if (pBlock->dwExtAddr <= dwExtAddress
                && pBlock->dwExtAddr + pBlock->cbSize > dwExtAddress) {
                // the right block.
                ASSERT(pBlock->pbMemory);
                DWORD BlockOffset = dwExtAddress - pBlock->dwExtAddr;
                if (*pcbBlockSize) *pcbBlockSize = pBlock->cbSize - BlockOffset;
                return pBlock->pbMemory + BlockOffset;
            }
        } else {
            if (pBlock->dwExtAddr == dwExtAddress) {
                ASSERT(pBlock->pbMemory);
                if (*pcbBlockSize) *pcbBlockSize = pBlock->cbSize;
                return pBlock->pbMemory;
            }
        }
    }
    if (*pcbBlockSize) *pcbBlockSize = 0;
    return NULL;
}


DWORD ExternalCacheMgr::JoinBlocks(DWORD dwExtAddressBegin, DWORD dwExtSize, LPBYTE pbBuffer, BOOL bLinearExt) {
    CacheBlocks::iterator it;
    DWORD cbCount = 0;

    if (bLinearExt) {
        DWORD ea1 = dwExtAddressBegin;
        DWORD ea2 = ea1 + dwExtSize - 1;
        for (it = m_listBlocks.begin(); it != m_listBlocks.end(); ++it) {
            CacheBlock *pBlock = *it;
            pBlock->AssertValid();

            DWORD ia1 = pBlock->dwExtAddr;
            DWORD ia2 = ia1 + pBlock->cbSize - 1;

            DWORD xa1, xa2;
            xa1 = ia1 > ea1 ? ia1 : ea1;
            xa2 = ia2 < ea2 ? ia2 : ea2;

            if (xa1 <= xa2) {
                DWORD offsetTarget = xa1 - ea1;
                DWORD offsetBlock = xa1 - ia1;
                DWORD cbCopy = xa2 - xa1 + 1;

                memcpy(pbBuffer + offsetTarget, pBlock->pbMemory + offsetBlock, cbCopy);
                cbCount += cbCopy;
            }
        }
    } else {
        // sort by ext-addr at first.
        std::greater<CacheBlock *> theCmp_ExtAddr;
        theCmp_ExtAddr.m_cmp_mode = theCmp_ExtAddr._cm_extaddr;

        CacheBlocks sortedEA = m_listBlocks;

        sortedEA.sort(theCmp_ExtAddr);

        for (it = sortedEA.begin(); it != sortedEA.end(); ++it) {
            CacheBlock *pBlock = *it;
            pBlock->AssertValid();
            if (pBlock->dwExtAddr >= dwExtAddressBegin &&
                pBlock->dwExtAddr < dwExtAddressBegin + dwExtSize) {

                memcpy(pbBuffer, pBlock->pbMemory, pBlock->cbSize);
                pbBuffer += pBlock->cbSize;
                cbCount += pBlock->cbSize;
            }
        }
    }
    return cbCount;
}


CacheBlock *ExternalCacheMgr::PrepareCache(DWORD cbSize) {
    ASSERT(cbSize > 0 && cbSize <= m_nMaxCacheSize);

    if (cbSize > m_nMaxCacheSize) {
        // it's impossible to allocate this large cache block.
        //SetLastError(ERROR_OUTOFMEMOTY);
        return NULL;
    }

    LPBYTE pBlockMem = (LPBYTE)malloc(cbSize);
    if (!pBlockMem) {
        // out of available memory.
        //SetLastError(ERROR_OUTOFMEMORY);
        return NULL;
    }

    if (cbSize + m_nUsedSize > m_nMaxCacheSize) {
        // some blocks with small weights shall be thrown.
        // the list must be sort.
        if (m_bListModified) {
            UpdateList();
            m_bListModified = FALSE;
        }
        CacheBlocks::reverse_iterator it;
        for (it = m_listBlocks.rbegin(); it != m_listBlocks.rend(); ++it) {
            CacheBlock *pBlock = *it;
            FreeCache(pBlock);
            if (cbSize + m_nUsedSize <= m_nMaxCacheSize) break;
        }

        ASSERT(cbSize + m_nUsedSize <= m_nMaxCacheSize);
    }

    CacheBlock *pBlock = new CacheBlock;
    ASSERT(pBlock != NULL);

    memset(pBlock, 0, sizeof(CacheBlock));
    /*
    pBlock->dwExtAddr = 0;      // the default external address.
    pBlock->Weight = 0;
    */
    pBlock->pbMemory = pBlockMem;
    pBlock->cbSize = cbSize;
    pBlock->bSync_ = 1;         // not sync. so un-readable.
    pBlock->bLock = 1;          // the initial block is locked.
    pBlock->bCached = 1;        // always cached.
    return pBlock;
}


BOOL ExternalCacheMgr::SubmitCache(CacheBlock *pBlock, BOOL bMakeAvail) {
    pBlock->AssertValid();

    /*
        // Comment out this provides the extra ability to have more cache size.
        if (m_nUsedSize + pBlock->cbSize > m_nMaxCacheSize) {
            // out of local max cache size.
            SetLastError(E_OUTOFMEMORY);
            return FALSE;
        }
    */

    if (bMakeAvail) {
        pBlock->bLock = 0;
        pBlock->bSync_ = 0;
    }

    m_nUsedSize += pBlock->cbSize;
    // ASSERT (m_nUsedSize + pBlock->cbSize <= m_nMaxCacheSize)

    m_listBlocks.push_back(pBlock);
    // sort blocks.
    m_bListModified = TRUE;

    return TRUE;
}


BOOL ExternalCacheMgr::SetCacheSize(DWORD cbSize) {
    if (cbSize > m_nMaxCacheSize) {
        // just extend the size.
        m_nMaxCacheSize = cbSize;
    } else {
        // cbSize <= nMaxCacheSize.
        if (m_nUsedSize > cbSize) {
            // release some, so as to shrink the size.
            /*
                std::greater<CacheBlock *> theCmp_Weight;
                m_Cache.sort(theCmp_Weight);
            */
            // sort by weight.
            UpdateList();

            CacheBlocks::reverse_iterator it;
            for (it = m_listBlocks.rbegin(); it != m_listBlocks.rend(); ++it) {
                CacheBlock *pBlock = *it;

                BOOL b;
                b = FreeCache(pBlock);
                ASSERT(b);
                if (!b) return FALSE;

                if (m_nUsedSize <= cbSize) break;
            }

            // now used size <= required size.
            m_nMaxCacheSize = cbSize;
        }
    }

    return TRUE;
}


BOOL ExternalCacheMgr::InvalidateCache() {
    CacheBlocks::iterator it;
    for (it = m_listBlocks.begin(); it != m_listBlocks.end(); ++it) {
        CacheBlock *pBlock = *it;

        BOOL b;
        b = FreeCache(pBlock);
        ASSERT(b);
        if (!b) return FALSE;
    }

    return TRUE;
}
