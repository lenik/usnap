

#pragma once


/*
    External Device - Storage Cache

    The cache is designed for those devices which have slow I/O speed,
    and other reasons for less access. (some devices cost much on direct-access)


    The cache manager has features:

        - Many cache layers, so as to separate different usage of blocks.
        - Lock blocks to prevent substitutions on them.
*/


/*
#define CACHE_BLOCK_FREQ            0x0F
#define CACHE_BLOCK_HEAVY_IO        0x10
#define CACHE_BLOCK_LOCK            0x20
#define CACHE_BLOCK_SYNC_           0x40
#define CACHE_BLOCK_ALLOC           0x80

inline bool _cb_readable(BYTE status) {
    return
        (status & CACHE_BLOCK_ALLOC)            // block is allocated
        && (status & FREQ)                      // block is filled with data
        && !(status & CACHE_BLOCK_SYNC)         // block is synchronized
        ;
}

inline bool _cb_writable(BYTE status) {
    return
        (status & CACHE_BLOCK_ALLOC)            // block is allocated
        && !(status & CACHE_BLOCK_LOCK)         // block isn't locked
        ;
}
*/

#pragma warning(disable: 4201)                  // nameless struct/union
#pragma pack(push, 4)
struct CacheBlock {
    DWORD   dwExtAddr;
    DWORD   cbSize;
    LPBYTE  pbMemory;
    struct {
        int Weight: 16;

        int bLoaded_: 1;
        int bSaved: 1;
        int bDirty: 1;
        int bReadOnly: 1;
        int bCached: 1;
        int bIgnore: 1;
        int bSync_: 1;
        int bLock: 1;

        // "bad sector"
        int bInvalid: 1;
    };

    inline void AssertValid() {
        ASSERT(this);
        ASSERT(pbMemory);
    }

    inline void IncW() {
        if (Weight < 0x4000) Weight++;
    }
    inline void DecW() {
        if (Weight > 0) Weight--;
    }
};
#pragma pack(pop)


// !!  DO NOT FORGET "std" AGAIN  !!
namespace std {
    template<>
    struct greater<CacheBlock *> : public binary_function<CacheBlock *, CacheBlock *, bool> {
        enum _cmp_mode {
            _cm_weight,
            _cm_extaddr,
        };
        _cmp_mode   m_cmp_mode;
        bool operator()(const CacheBlock *_X, const CacheBlock *_Y) const;
    };
}
typedef std::list<CacheBlock *> CacheBlocks;


class ExternalCacheMgr {
protected:
    CacheBlocks m_listBlocks;
    DWORD       m_nMaxCacheSize;
    DWORD       m_nUsedSize;
    BOOL        m_bListModified;

public:
    void        AssertValid();
    void        UpdateList();
    BOOL        DetachBlock(CacheBlock *pBlock);
    BOOL        FreeCache(CacheBlock *pBlock);

    CacheBlock *FindCacheBlock(DWORD dwExtAddress);

    // Get the cache data pointer, and the block size.
    LPBYTE      CachePointer(DWORD dwExtAddress, DWORD *pcbBlockSize, BOOL bLinearExt);

    // for linear external address, joins with padding bytes. dwExtSize is the bytes.
    // for non-linear external address, joins blocks sorted by ext-size.
    //      dwExtSize is a count-style value. NOTICE: the return value is counted by bytes.
    DWORD       JoinBlocks(DWORD dwExtAddressBegin, DWORD dwExtSize, LPBYTE pbBuffer, BOOL bLinearExt);

    // Get the cache data block
    CacheBlock *PrepareCache(DWORD cbSize);

    BOOL        SubmitCache(CacheBlock *pBlock, BOOL bMakeAvail = TRUE);

    BOOL        SetCacheSize(DWORD cbSize);
    BOOL        InvalidateCache();
};

