/*
                                                                  * CVI DRAFT *
    POS - Practice-Oriented Structure (System)                        Version 1
    ---------------------------------------------------------------------------
                                Power Of the Software !

    License:    POS.LCL
    See Also:   X@A LaS PoX EPFS HFVC 1/bios HAS/HAD Aipos

    Ci Virtuality Integrated,
    Copyright 1997-2003, CHINA. All rights reserved.

    File:
        Module Name:    POS Graph
        Description:    ___________________________________________________
                        ___________________________________________________
        Version:        0.0.2
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-5-10       ZD|Started
        2003-5-13       ZD|add R/T/S flags, typed_node_t
        2003-5-15       ZD|add (graph::)many types.
        2003-7-15       ZD|updated.
        2003-7-18       ZD|split node_hdr_t into node_t & node_simple_t.
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __GRAPH_INCLUDED__
#define __GRAPH_INCLUDED__

#include "config.h"



///////////////////////////////////////////////////////////////////////////////
//
// Forward Declaration, Macros and Constants
// ----------------------------------------------------------------------------
POS_BEGIN

#   define GRAPHF_REFLEXIVE         0x00010000
#   define GRAPHF_TRANSITIVE        0x00020000
#   define GRAPHF_SYMMETRIC         0x00040000
#   define GRAPHF_CLOSURED          0x00080000
#   define GRAPHF_LOOPED            0x00100000
#   define GRAPHF_PACKED            0x00200000
#   define GRAPHF_RESERVED          0x7FC00000
#   define GRAPHF_PP                0x80000000

#   define NODEF_LOCK               0x00010000
#   define NODEF_SCAN               0x00020000
#   define NODEF_SCANA              0x00040000
#   define NODEF_MARK               0x00080000
#   define NODEF_HDRVAR             0x00100000
#   define NODEF_ACTIVE             0x00200000
#   define NODEF_HIDDEN             0x00400000
#   define NODEF_BIND               0x00800000


    struct graph_t;
    struct node_hdr_t;
    struct node_t;
    struct node_simple_t;
    struct edge_t;

    enum graph_type {
        graph_rel_matrix,   // use relation-matrix instead of arbitrary links.
                    // when use relation-matrix in SDR mode, matrix(matrix_quad_t) item's value is 0-or-1;
                    // otherwise<???> the row is node-list, and columns of each row contains variable link-target node-list.
        graph_chain,        // only 1 link is allowed for each node.
        graph_chain_d,      // only 1 link is allowed for each node. (directional)
        graph_tree,     // general tree with local-tree support
        graph_tree_d,       // general tree with local-tree support (directional)
        graph_iolinks,      // 1-branch directional graph, each nodes have many in/out links.
        graph_stateflow,    // state-flow, like dfa or nfa.
        graph_geometry,     // geometry graph, with space-coordinate
        graph_topology,
        graph_
    };

    enum node_type {
        node_null,      // null node can be a terminal, its pointers are never considered.
        node_dummy,     // the node is meaningless, or a placeholder, instead of valuable node.
                    // it's a good way to setting a node to dummy than deleting it.
        node_normal,        // normal node
        node_dynamic,       // the value/value-type/links are all dynamic generated.
        node_reference,     // reference to another node. (like a pointer)

        node_state_episilon,
        node_state_timeout,
        node_state_symbol,

        node_geo1_point,
        node_geo2_line,     // maybe seg, ray, beeline.
        node_geo2_arc,      // maybe CSE, CRSE, SME,
        node_geo2_circle,   // oval or ellipse
        node_geo2_bezier,   // quadric/cubic/...
        node_geo2_b_spline,
        node_geo2_nurb,     // non-uniform rational B-spline
        node_geo2_poly,     // polynormial
        node_geo3_triangle,
        node_geo3_rectangle,
        node_geo3_npoly,    // normal polygon
        node_geo3_poly,     // non-normal polygon
        node_geo3_geo2,     // closed area of many geo2's as geo3.
    };

    namespace graph {
        struct rel_matrix_t;

        struct chain_t;
        struct tree_t;
        struct iolinks_t;
        struct stateflow_t;
        struct geometry_t;
        struct topology_t;

        struct chain_node_t;
        struct chain_node_dt;
        struct chain_node_st;
        struct chain_node_dst;
        struct tree_node_t;
        struct tree_node_dt;
        struct tree_node_st;
        struct tree_node_dst;
        struct iolinks_node_t;
        struct geo_node_t;
        struct state_node_t;
        struct topo_node_t;


        // the actual storage of coordinate is depends on PVT::type, e.g. for coord_rect,
        // which may be pvt_r4_3 (<x,y,z>), pvt_i4_4(<x,y,z,w>), ... etc.
        enum coord_type {
            coord_reference,    // only the coordinate is reference to another's,
                        // unlike node_type==node_reference, which is about all.
            coord_linear,       // (not used)
            coord_rect,
            coord_polar,
        };
    } // namespace graph

    namespace ab {
        typedef graph::rel_matrix_t     Rel;    // Rel is 2-D
        typedef graph::chain_t          C;
        typedef graph::tree_t           T;
        typedef graph::iolinks_t        G;  // common, and always directional.
        typedef graph::geometry_t       Y;
        typedef graph::stateflow_t      S;  // always directional

        typedef graph::chain_node_t     N1C;
        typedef graph::chain_node_dt    N2C;
        typedef graph::chain_node_st    N1c;
        typedef graph::chain_node_dst   N2c;
        typedef graph::tree_node_t      N1T;
        typedef graph::tree_node_dt     N2T;
        typedef graph::tree_node_st     N1t;
        typedef graph::tree_node_dst    N2t;
        typedef graph::iolinks_node_t   NG;
        typedef graph::geo_node_t       NY;
        typedef graph::state_node_t     NS;
    }

POS_END



// Header files to use
#include "variant.h"
#include "pointer.h"
#include "k_vars.h"
#include "bdt.h"
#include "agg.h"
#include "error.h"

///////////////////////////////////////////////////////////////////////////////
//
// Prototypes
// ----------------------------------------------------------------------------
#include "config/alignment_begin.h"
POS_BEGIN
    struct graph_t : public agg_hdr_t {
        union {
            u32_t _graph_hdr;
            union {
                struct {
                    u16_t _graph_type;
                    u16_t _graph_flags;
                };
                struct {
                    int _graph_type_pad: 16;

                    // each node is linked to themself, NO MATTER whether the pointer is existed.
                    int bReflexive: 1;

                    // a->b & b->c ==> a->c, NO MATTER whether the pointer is existed.
                    int bTransitive: 1;

                    // for nondirectional, a->b ==> b->a, NO MATTER whether the pointer is existed.
                    //  this is useful for quick switching between symmetric/not symmetric.
                    // for directional, this flag is useless.
                    //  or you can create the temporary symmetric graph for speed searching.
                    int bSymmetric: 1;

                    // reflexive/transitive/symmetric is applies into store-structure.
                    int bClosured: 1;

                    // for all "NULL"-link, link it back to node[0] (the first node), thus form a looped graph.
                    int bLooped: 1;

                    // reserved.
                    int _graph_res: 6;

                    // packed graph will always contain no 'dummy' nodes,
                    // and the storage layout is said to be have optimized.
                    int bPacked: 1;

                    // use node_hdr_t instead of a simple DWORD.
                    int bNode_: 1;

                    // use edge_t instead of a "void *" pointer.
                    int bEdge_: 1;

                    // use double links, which contain reversed link.
                    // this is a great improvement when do graph searching stuff.
                    int bDouble_: 1;

                    // Directional graph or Nondirectional graph. (hdr < 0 ==> directional)
                    int bDirectional: 1;
                };
            };
        };

        // detail of specified graph type
        union {
            void *                  _pv;
            graph::chain_t *        _chain;
            graph::tree_t *         _tree;
            graph::iolinks_t *      _iolinks;
            graph::geometry_t *     _geometry;
            graph::stateflow_t *    _stateflow;
        } _detail;

        // storage-entry node of the graph, WARNING: this isn't the edge.
        //  chain:      the left-most node
        //  tree:       the top-most node
        //  iolinks:    node which export the graph
        //  geometry:   ?
        //  stateflow:  node which export the state-flow graph, but not have to be the initial state.
        node_hdr_t *    _sentry;

        // context, free usage.
        void *      _ctx;

        void _release(bool _destroy_self = false);
        void _free() { _release(true); }
    }; // graph_t

    // 4-bytes, node hdr & flags type
    struct node_hdr_t {
        union {
            u32_t hdr;
            union {
                struct {
                    u16_t type;     // = simple PVT::type
                    u16_t flags;
                };
                struct {
                    int _type_pad: 16;

                    int _res1: 3;

                    // when scaning the graph, bScan* stop a node from scaning repeatly.
                    int bEnum: 1;

                    // the node is active, or enabled.
                    int bActive_: 1;

                    // if a node is exported, or visible.
                    int bExport_: 1;

                    // the value is PVT format. this affects bBind(X). non-PVT can have a key.
                    int bPVT_: 1;

                    // object is synchoronized.
                    int bSync_: 1;

                    // locked by other
                    int bLock: 1;

                    // node is invalid.
                    int bInvalid: 1;

                    // node is marked
                    int bMark: 1;

                    // reserved for user.
                    int bUser: 1;

                    // using node_simple_t instead of advanced node_t.
                    int bSimple: 1;

                    // shall release the members.
                    // !! members like chains ("_links->...") are always released by graph._agg
                    // !! for simple node, bBind_ will cause node_simple_t::_pv be deleted.
                    // !! otherwise, node_t::(_v8 & _k8) or (_pv, _k) will be released
                    // !!   depends on whether bVar8 bit.
                    int bBind_: 1;

                    int _res3: 1;
                };
            };
        };
    };

    // 24-bytes, standard node hdr
    struct node_t : public node_hdr_t {
        u32_t       _res;
        union {
            struct {
                var8_t  _v8;
                var8_t  _k8;
            } v;
            struct {
                _v32_t  _tagv;
                pv_t    _pv;
                _v32_t  _tagk;
                asz_t   _k;
            } nv;
        };

        inline void _release(bool _destroy_self = false) {
            if (!bBind_) {
                if (!bPVT_) {
                    v._v8._release();
                    v._k8._release();
                } else {
                    if (nv._pv) delete nv._pv;
                    if (nv._k) delete nv._k;
                }
            }
            if (_destroy_self) delete (void *)this;
        }
        inline void _free() { _release(true); }
    };

    // 8-bytes, simple node hdr
    struct node_simple_t : public node_hdr_t {
        node_hdr_t  hdr;
        union {
            _v32_t      _32;
            _v_p_t      _p;
            pv_t        _pv;
        };
    };

    struct edge_t {
        union {
            u32_t hdr;
            union {
                struct {
                    u16_t type;     // = simple PVT::type
                    u16_t flags;
                };
                struct {
                    int _type_pad: 16;

                    // the node which contain this edge is owner of the edge.
                    int bOwner_: 1;

                    int _res1: 3;

                    // the edge is active, or enabled.
                    int bActive_: 1;

                    // if the edge is exported, or visible.
                    int bExport_: 1;

                    // bTag (tag) value available.
                    int bValue_: 1;

                    // the value is PVT format. this affects bBind(X).
                    int bPVT: 1;

                    // edge is synchoronized.
                    int bSync_: 1;

                    // locked by other
                    int bLock: 1;

                    // edge is invalid.
                    int bInvalid: 1;

                    // edge is marked
                    int bMark: 1;

                    // reserved for user.
                    int bUser: 1;

                    // using edge_simple_t instead of advanced edge_t.
                    int bSimple: 1;

                    // release members when the node is destroyed.
                    // !! generally _links->... is always released by graph._agg
                    int bBind_: 1;

                    int _res3: 1;
                };
            };
        };

        pv_t    _pv;            // primary value of the node.
        union {
            var8_t  _v8;        // bPVT == true
            struct {        // bPVT == false
                _v32_t  _32;
                _v32_t  _32_tag;
            };
        };

        inline void _release(bool _destroy_self = false) {
            if (!bBind_) {
                if (_pv) delete _pv;
                if (bPVT) {
                    _v8._release();
                }
            }
            if (_destroy_self) delete (void *)this;
        }
        inline void _free() { _release(true); }
    }; // edge_t

    namespace graph {
        // --------------------------------------------------------------------------------
        //  *Graph* details of specific graph
        // --------------------------------------------------------------------------------
        struct rel_matrix_t {
            ab::M   _m;
        };
        struct chain_t {
            //
        };
        struct tree_t {
            //
        };
        struct iolinks_t {
            typedef bdt::list_t<iolinks_node_t *> list_t;

            // this list cover all nodes thru entry.
            list_t *    s;

            // this can be used for unique-enumeration.
            list_t *    connected_branch;

            // for plane-graph, nDimension == 2
            int         nDimension;
        };
        struct geometry_t {
            union {
                u32_t hdr;
                union {
                    struct {
                        u16_t type;     // coordinate type
                        u16_t flags;
                    };
                    struct {
                        int _type_pad: 16;
                    };
                };
            };
        };

        struct stateflow_t {
            state_node_t *  _initial;
            //
        };

        // --------------------------------------------------------------------------------
        //  *Node* details of specific graph
        // --------------------------------------------------------------------------------
        struct chain_node_t : public node_t {
            chain_node_t *      c;      // next node in the chain
        };
        struct chain_node_dt : public node_t {
            chain_node_dt *     c;      // next node in the chain
            chain_node_dt *     _c;     // next node in the chain
        };
        struct chain_node_st : public node_simple_t {
            chain_node_st *     c;      // next node in the chain
        };
        struct chain_node_dst : public node_simple_t {
            chain_node_dst *    c;      // next node in the chain
            chain_node_dst *    _c;     // next node in the chain
        };

        struct tree_node_t : public node_t {
            tree_node_t *       s;      // next sibling
            tree_node_t *       c;      // first of children
            tree_node_t *       t;      // extend: local-tree
        };
        struct tree_node_dt : public node_t {
            tree_node_dt *      s;      // next sibling
            tree_node_dt *      c;      // first of children
            tree_node_dt *      t;      // extend: local-tree
            tree_node_dt *      _s;     // prev sibling
            tree_node_dt *      _c;     // parent
            tree_node_dt *      _t;     // extend: parent of local-tree
        };
        struct tree_node_st : public node_simple_t {
            tree_node_st *      s;      // next sibling
            tree_node_st *      c;      // first of children
            tree_node_st *      t;      // extend: local-tree
        };
        struct tree_node_dst : public node_simple_t {
            tree_node_dst *     s;      // next sibling
            tree_node_dst *     c;      // first of children
            tree_node_dst *     t;      // extend: local-tree
            tree_node_dst *     _s;     // prev sibling
            tree_node_dst *     _c;     // parent
            tree_node_dst *     _t;     // extend: parent of local-tree
        };

        struct iolinks_node_t : public node_hdr_t {
            typedef bdt::list_t<iolinks_node_t *> list_t;
            // out-> elements
            list_t *    s;      // [auto: the list]
            // ->in elements
            list_t *    _s;     // [auto: the list]
        };

        struct state_node_t : public node_hdr_t {
            struct {
                int bVtbl: 1;
                int bStat: 1;
            };
            struct Vtbl {
                void (*_enter)();
                void (*_exit)();
            };

            Vtbl *  _vtbl;

            struct Event {
                // _target may be state, codeblock/las, or something else.
                // see node_hdr_t::type (node_state_ episilon/timeout/symbol)
                var8_t      _event;
                node_hdr_t *    _target;
            };
            typedef bdt::list_t<Event *> events;
            events *    _events;
        };

        struct geo_node_t : public node_hdr_t {
            var_t *     coord;      // [auto]

        };

        struct topo_node_t : public node_hdr_t {
            //
        };

    } // namespace graph
POS_END
#include "config/alignment_end.h"



///////////////////////////////////////////////////////////////////////////////
//
// Inline implementations & Utility functions
// ----------------------------------------------------------------------------
POS_BEGIN
    inline void graph_t::_release(bool _destroy_self) {
        if (!bBind_) {
            this->bSymmetric ;
        }
        agg_hdr_t::_release();
        if (_destroy_self) delete this;
    }
POS_END

#endif



///////////////////////////////////////////////////////////////////////////////
//
// The Developing Procedure
// ----------------------------------------------------------------------------
/*
        Summary:
                _____________________________________________
                _____________________________________________
        Motivation:
                ___________________________________________________________
        Objective:
                ___________________________________________
                ___________________________________________
                ___________________________________________
        Sandbox, Problems, Warnings:
                Graph size = Header + Data + User
                    Header  = 32(Agg) + 16(Graph) + X, X = |graph_detail| bytes;
                    Data    = N * (24 + Y), Y = |node_detail| bytes.
                    User    = All allocated bytes isolated thru pointers.
                _______________________________________
                _______________________________________
        Development:
                - Directional graph & Nondirectional graph
                    Logical     Persist     Detail
                    D           ->          Good, with <- is better..
                    D           ->, <-      Good. <- can be used in Reversed searching.
                    G           ->          A reversed-links cache is very helpful for searching.
                    G           ->, <-      Good. Nondirectional shall prevent Anti-"repeat scan".
                ___________________________________________________________
                ___________________________________________________________
        References:
                _________________________________________________
        Achievement:
                ________________________________________
        Outgrowth & Babies, Abbreviations:
                    Rel rel_matrix_t
                    C   chain_t
                    T   tree_t
                    G   iolinks_t
                    Y   geometry_t
                    S   stateflow_t

                    N1C chain_node_t
                    N2C chain_node_dt
                    N1c chain_node_st
                    N2c chain_node_dst
                    N1T tree_node_t
                    N2T tree_node_dt
                    N1t tree_node_st
                    N2t tree_node_dst
                    NG  iolinks_node_t
                    NY  geo_node_t
                    NS  state_node_t
                _____________________________
        Acknowledgement:
                _____________________________________________
*/
