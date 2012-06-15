//
// POS.EPFS (Version 1)
//

//
// 2003-7-3 classified node
// 2003-7-2 start

#pragma once



// forward declaration
namespace pos {
namespace epfs {
    struct epfs_hdr_t;
    // ...
    enum epfs_type {
        epfs_core_tree,
        epfs_core,
        epfs_xml,
        epfs_btree,
        epfs_fat32,
        epfs__com_storage,
    };
}} // pos:epfs:


#include <pos/config.h>
#include <pos/variant.h>

_NS_BEGIN

#pragma pack(push, 4)


// -bytes EPFS Header
struct epfs_hdr_t {
    u32_t   magic;          // 53465045H, FOURCC/EPFS

    u32_t   type;

    res_t   _r;

    struct {
        int bDriver: 1;
        int bFilter: 1;
        int bSecurity: 1;
        int bLogger: 1;
        int bCacher: 1;
        int bQuote: 1;
        int bSubEPFS: 1;
        int bOptimizer: 1;

        // act like an event chain, and to be both event source and sink. for EventChain,
        //   sink: children nodes report an event to this, and this pass the event to parents.
        //   src:  do the notify work to parents, when something happened.
        // so a "directory node" can know the recent changes for any in children's.
        int bEventChain: 1;

    } flags;
};

enum node_class {
    normal = 0,
    details,
    driver,
    filter,
    time,       // create, [modify], access
    security,
    qq,         // M-Q/q, include [ref-count], access-count, ***-count, ...
    index,
    quickview,
    icon,
    pos_layout,
    binds,      // [source-link] may be "copy", "instant", "reference", etc.
    quotes,
    overload,
};

// 24-bytes epfs-node header, compitable with pos-agg::node_hdr_t.
struct node_hdr_t {
    u32_t   _r;
    union {
        u32_t hdr;
        union {
            struct {
                u16_t _class;
                u16_t flags;
            };
            struct {
                int _type_pad: 16;

                // the directory is sorted. so 2-branch searching is allowed.
                int bSorted: 1;

                // includes repeated element.
                int bRepeated: 1;
            };
        };
    };
    var8_t  data;
    var8_t  key;
};

struct driver_t {

};


/*
    - /treeA.node/treeA.node:treeB.node/treeB.node/treeB.node:treeC.node ...
    - uExpression: {PATH,operation} -> {PATH}
        . union     [pathA pathB]
        . intersection  [pathA pathB] | (pathA.name == pathB.name)
        . sub-overload  [pathA] | (pathA/sub/... = [pathA/sub/... pathB])
        ...
    -
*/
struct path_t {
    struct {
        int bBind_;
    };
    asz_t   szRelPath;
    container _outmost;
    asz_t   szFullPath; // relate to _outmost container

    struct mapper {
        pv_t    FDT_info;

    };
    struct
};



///////////////////////////////////////////////////////////////////////////////
//
struct std_node_certs {
};

struct std_node_security {
    // crc32, md5, ...
    int hash_alg;
    void *_hash;            // hash code don't need PK.

    //
};

struct std_node_encoded {
    struct encoded_area {
        int bEncSecurity: 1;    //
        int bEncHash: 1;
        int bEnc;
    };
    cid_t cert_guid;

};


#pragma pack(pop)

}} // pos:epfs: