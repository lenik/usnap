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
        Module Name:    (PVT) POS Variant Type
        Description:    PVT is the kernel object in POS model.
                        All other objects in POS system are either using PVT
                        as the value container or just another type 'derived'
                        from PVT.
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-4-17       ZD|Started
        2003-5-7        ZD|isolated the Pointer.
        2003-5-9        ZD|m_pDomain & m_pUnit
        2003-5-10       ZD|bTemplate,bR/W->complex,hfvc-support,bCards
        2003-5-13       ZD|add LEB for PVT. (do not use now).
                          | add value-release(such as IUnknown::release).
        2003-5-14       ZD|split bAuto into (bAuto, bAutoVal)
        2003-5-28       ZD|add Meta. remove bDestroyFriend flag.
        2003-5-29       ZD|adjust the layout, so bAuto is always at 0x40000000
        2003-5-30       ZD|bPVT so PVT is more smart.
        2003-6-23       ZD|added var8_t, var12_t
        2003-6-24       ZD|swap bit bLock and bAlign. swap _vt::p and _vt::_p.
        2003-6-25       ZD|xref patch: move union _vt after PVT structure define,
                          | and before member functions implementation.
        2003-6-29       ZD|adjust the layout, so generally .....24-bit...SLIMUXA.
                          | (Sync Lock Invalid Mark User AutoX Auto)
        2003-7-3        ZD|remove bBigEndian
        2003-7-15       ZD|updated
        2003-7-21       ZD|change bAuto to bBind.
        2003-7-22       ZD|adjust the layout of complex_t, so complex information
                          | is more compact and faster.
		2004-1-3		ZD|(YTMF)reviewed: where is m_pBody and b_bodyCached?
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __PVT_INCLUDED__
#define __PVT_INCLUDED__
#ifdef POS_CF_ONCE
#   pragma once
#endif

#include "config.h"
#include "k_flags.h"
#include "hfvc.h"



///////////////////////////////////////////////////////////////////////////////
//
// Forward Declaration, Macros and Constants
// ----------------------------------------------------------------------------
POS_BEGIN
#   define PVTF_EXTYPE              0x00010000
#   define PVTF_ALIGN               0x00020000
#   define PVTF_COMPLEX             0x00040000
#   define PVTF_POINTER             0x00080000
#   define PVTF_ISOLATED            0x00100000
#   define PVTF_TEMPLATE            0x00200000
#   define PVTF_RESERVED            0x00C00000
#   define PVTF_SYNC                0x01000000
#   define PVTF_LOCK                0x02000000
#   define PVTF_INVALID             0x04000000
#   define PVTF_MARK                0x08000000
#   define PVTF_USER                0x10000000
#   define PVTF_BINDVAL             0x20000000
#   define PVTF_BIND                0x40000000
#   define PVTF_PVT                 0x80000000
#   define PVTF_TYPEMASK            0x0000FFFF


    enum var_type {
            pvt_void = 0,           // sizeof(PVT) = 4, other value is invalid.
    /* 1*/  pvt_u8,     pvt_u16,    pvt_u32,    pvt_u64,            // unsigned
    /* 5*/  pvt_i8,     pvt_i16,    pvt_i32,    pvt_i64,            // signed
    /*13*/  pvt_b8,     pvt_b16,    pvt_b32,    pvt_b64,            // bit, b8 ¼æ b1, b2, b4
    /*17*/  pvt_r128,   pvt_r16,    pvt_r32,    pvt_r64,            // real
    /*21*/  pvt_c128,   pvt_c16,    pvt_c32,    pvt_c64,            // complex(real, real)
    /*25*/  pvt_rel8,   pvt_rel16,  pvt_rel32,  pvt_rel64,          // relative offset (persistable pointer)
    /*29*/  pvt_bcd8,   pvt_bcd16,  pvt_bcd32,  pvt_bcd64,          // BCD
    /*33*/  pvt_pointer,            // pos-complex pointer. it can be converted to pvt_pointer.
            pvt_pv,                 // sizeof(pointer) is always == sizeof(void *), and not persistable.
            pvt_fourcc32,
            pvt_posid96,
            pvt_cid,
            pvt_guid128,
            pvt_corbaid128,
    /*40*/  pvt_epfs,
            pvt_struct8,            // pack(1)
            pvt_struct16,       // pack(2)
            pvt_struct32,       // pack(4)
            pvt_struct64,       // pack(8)
            pvt_struct128,      // pack(16)
            pvt_struct256,      // pack(32)
            pvt_hfvc_d8,        // delta-8, 32-bit
            pvt_hfvc_d4,        // delta-4, 16-bit
            pvt_hfvc_d16,       // delta-16, 64-bit
    /*50*/  pvt_hfvc_d5,        // delta-5, 15-bit
            pvt_lasar,
            pvt_pvt,            // repeat the variant.
            pvt__com_variant,   // VARIANT    16 (bytes)
            pvt__com_array,     // SAFEARRAY    16 [*pv] 16*cDims (bytes)
            pvt__com_iunk,      // IUnknown *
            pvt__com_idisp,     // IDispatch *
            pvt__com_dec96,     // 96-bit, 128-bit storage.
            pvt__com_scode,     // HRESULT
            pvt__com_cy64,      // currenecy, 64-bit integer scaled by 10000.
    /*60*/  pvt__com_date,      // DATE
            pvt_mpint,          // multi-precision integer
            pvt_mpreal,         // multi-precision real
            pvt_block_pad,      // simple block as (u32_t cb) + cb'BYTEs
            pvt_asz_pad,        // sz following type field, ascii 7-bit or 8-bit, end by zero '\0'
            pvt_asz,            // sz at some where
            pvt_ucsz16_pad,     // Unicode (or UTF-16), end by zero L'\0'
            pvt_ucsz16,
            pvt_ucsz8_pad,      // UTF-8
            pvt_ucsz8,
    /*70*/  pvt_bstr,           // pointer -> [count] ucsz16

            // these sub-type is different from bExType.
            // value of these sub-type is self-contained, where subtype-id is at the top of value.
    /*71*/  pvt_sub_fourcc,     // FOURCC32 as the sub-type
            pvt_sub_posid96,    // POSID96 as the sub-type
            pvt_sub_cid,        // CID var-len as the sub-type
            pvt_sub_bstr,       // [u32_t]ucsz16 var-len as the sub-type

            // place-holder: pos-aggregates
    /*75*/  pvt_set,
            pvt_hash,
            pvt_matrix,
            pvt_graph,
    /*79*/  pvt_noodle,

            // place-holder: simple tuples
    /*80*/  pvt_pvt_2,  pvt_pvt_3,  pvt_pvt_4,  pvt_pvt_22, pvt_pvt_33, pvt_pvt_44,
    /*86*/  pvt_u8_2,   pvt_u8_3,   pvt_u8_4,   pvt_u8_22,  pvt_u8_33,  pvt_u8_44,
    /*92*/  pvt_u16_2,  pvt_u16_3,  pvt_u16_4,  pvt_u16_22, pvt_u16_33, pvt_u16_44,
    /*98*/  pvt_u32_2,  pvt_u32_3,  pvt_u32_4,  pvt_u32_22, pvt_u32_33, pvt_u32_44,
    /*104*/ pvt_u64_2,  pvt_u64_3,  pvt_u64_4,  pvt_u64_22, pvt_u64_33, pvt_u64_44,
    /*110*/ pvt_i8_2,   pvt_i8_3,   pvt_i8_4,   pvt_i8_22,  pvt_i8_33,  pvt_i8_44,
    /*116*/ pvt_i16_2,  pvt_i16_3,  pvt_i16_4,  pvt_i16_22, pvt_i16_33, pvt_i16_44,
    /*122*/ pvt_i32_2,  pvt_i32_3,  pvt_i32_4,  pvt_i32_22, pvt_i32_33, pvt_i32_44,
    /*128*/ pvt_i64_2,  pvt_i64_3,  pvt_i64_4,  pvt_i64_22, pvt_i64_33, pvt_i64_44,
    /*134*/ pvt_r128_2, pvt_r128_3, pvt_r128_4, pvt_r128_22,pvt_r128_33,pvt_r128_44,
    /*140*/ pvt_r16_2,  pvt_r16_3,  pvt_r16_4,  pvt_r16_22, pvt_r16_33, pvt_r16_44,
    /*146*/ pvt_r32_2,  pvt_r32_3,  pvt_r32_4,  pvt_r32_22, pvt_r32_33, pvt_r32_44,
    /*152*/ pvt_r64_2,  pvt_r64_3,  pvt_r64_4,  pvt_r64_22, pvt_r64_33, pvt_r64_44,
    /*158*/ pvt_c128_2, pvt_c128_3, pvt_c128_4, pvt_c128_22,pvt_c128_33,pvt_c128_44,
    /*160*/ pvt_c16_2,  pvt_c16_3,  pvt_c16_4,  pvt_c16_22, pvt_c16_33, pvt_c16_44,
    /*166*/ pvt_c32_2,  pvt_c32_3,  pvt_c32_4,  pvt_c32_22, pvt_c32_33, pvt_c32_44,
    /*172*/ pvt_c64_2,  pvt_c64_3,  pvt_c64_4,  pvt_c64_22, pvt_c64_33, pvt_c64_44,
    /*178*/

    /*% 0*/ // users
            pvt_user_begin = 0x8000,

    /*! 0*/ pvt_moved = 0xF000,     // [ptr to new pvt] variant moved lazy-notify. see _complex::ref_count
            pvt_uninit,

    };


    struct var_t;
    namespace ab {
        typedef var_t PVT;
    } // pos:ab:

    // forward again.
    struct pointer_t;
    struct proc_t;
    struct domain_t;
    struct unit_t;

POS_END



// Header files to use

///////////////////////////////////////////////////////////////////////////////
//
// Prototypes
// ----------------------------------------------------------------------------
#include "config/alignment_begin.h"
POS_BEGIN
    // flags;type | [complex] | subtype-id... | value... | suffix
    struct var_t {
        union {
            u32_t hdr;
            union {
                struct {
                    u16_t type;
                    u16_t flags;
                };
                struct {
                    int _type_pad: 16;

                    // extend type, the type=majortype and subtype-id follow majortype.
                    // when bPointer or bIsolated, value m_pv points to doesn't contain any type info,
                    // when bComplex, more bytes after the subtype-id (subtype-id is var-length)
                    int bExType: 1;

                    // when bExType, align body to word boundary.
                    int bAlign: 1;

                    // true if more attributes before the pointer.
                    int bComplex: 1;

                    // pointer to the value, the pointer is in Pointer format.
                    // that is, the pointer is 8-bytes longer.
                    // Pointer has the ability of multi-level pointer.
                    int bPointer: 1;

                    // value is stored elsewhere than immediately after 'fulltype' field.
                    // this may also thinked as a second 'bPointer', or 'bOutOfStruct'.
                    // but pv instead of Pointer.
                    int bIsolated: 1;

                    // this variant is marked as a template. (for aggregate types)
                    int bTemplate: 1;

                    int _res: 2;

                    // synchronized, this is useful for async read/write proc.
                    int bSync_: 1;

                    // the variant is locked. this is useful for bmp (balanced multi-processor)
                    int bLock: 1;

                    // the _body or _byval is in invalid format. this is useful when in debug mode.
                    int bInvalid: 1;

                    // object is marked.
                    int bMark: 1;

                    // reserved for user.
                    int bUser: 1;

                    // !! subject to bBind !! bind the major value with the variant.
                    // thus release the value when this variant is destroyed.
                    int bBindVal_: 1;

                    // auto variant, release member when this variant is destroyed.
                    // this happened to bIsolated, bComplex, bPointer(if _p->bBind is also set.).
                    int bBind_: 1;

                    // if bPVT not set, this is just a 31-bit signed or 30-bit unsigned integer!!
                    //    so cast to i32_t by (hdr + 40000000h) & 0B0000000h.
                    int bPVT: 1;
                };
            };
        };

        // !!! for <complex>, bIsolated is assumed, and [complex] is follow m_pointer.
        // !!! all NON-complex && NON-extype goes here:
        // !!! for extype, here is subtype-id, and value stored follow subtype-id.
        // !!! use _body() to get pointer to value, and _byval() to dereference bPointer.
        union _vt;

        /*
            PVT Dynamic Procedures
                - read proc always save result to the body, and
                - write proc always get Input-Data from the body.
                - for context-based var (like a property of an object), the owner object
                    can be located thru _LEB of the var_t.
                - any arbitrary parameters are passed thru _args.
                    so a 1-Dimension index may be the m_i32 here.
                - more error details can be saved somewhere of the var's epfs storage.
        */
        typedef error_t (_stdcall *_var_read)(var_t *_v, _v32_t _args);
        typedef error_t (_stdcall *_var_write)(var_t *_v, _v32_t _args);
        typedef void (_stdcall *_var_release)(var_t *);

        // --------------------------------------------------------------------------------
        //    complex based on POS.CMV - compressed member vars
        // --------------------------------------------------------------------------------
        struct complex_t {
            union {
                u32_t   flags;
                res_t   _r;
                struct {
                    // use the reference-count, thus release() will depends on it.
                    // when pvt_moved using ref-count, body._pv points to new var_t,
                    // and cRef act as reloc-count, when it == 0, original allocation will be released.
                    int bRefCount: 1;

                    // bind another variant to this (for tag use mainly, don't make chain.)
                    //    auto destroy if pFriend->bBind. (this may cause circle-chain into problem)
                    int bBindFriend: 1;

                    // use read property (_vtbl::_read)
                    int bRead: 1;

                    // use write property (_vtbl::_write)
                    int bWrite: 1;

                    // switch the high-24 bits to res_t usage.
                    int b_r: 1;


                    // value shall be within domain, otherwise _a.bInvalid will be set.
                    int bDomain: 1;

                    // value is of 'unit', some as 'kg','km/h' etc.
                    int bUnit: 1;

                    // (not used) the variant exports some cards. :)
                    int bCards: 1;

                    // LEB(local env. block) to this variant is valid. pLEB->bBind is used.
                    int bLEB: 1;

                    // meta info. like "type info", "data-layout", etc. pMeta->bBind is used.
                    int bMeta: 1;

                    // interpret info. like "name", "self-location", "last access time", etc.
                    int bInterpret: 1;

                    // ---------------- both S/HFVC ------
                    // don't save read/write proc's result to local cache(the _body)
                    int bNoRWCache: 1;

                    // when elements in LEB existed in PVT, prefer LEB.
                    int bLEBPrior: 1;

                    //
                    int _reserved2: 8;

                    // more description bits were set before the var_t structure.
                    int bPrefix: 1;

                    // more description bits were set after the var_t structure.
                    int bSuffix: 1;

                    int bUser_2: 1;

                    //
                    int _reserved3: 1;

                    // auto destroy m_pDomain & m_pUnit.
                    int bBind_: 1;

                    // the complex-structure is a hfvc (15-bit, delta-1)
                    // if b_hfvc=0, sizeof(complex) is index of first non-FALSE CMV * (4 bytes)
                    int b_hfvc: 1;
                };
            };

            // reference-count
            u32_t   cRef;

            struct _ccore {
                var_t *     _friend;
                _var_read   _read;
                _var_write  _write;

            };
            _ccore  _core;

			// !!! temporary stuff
				pv_t	_body;
				BOOL	bBodyCached;

            pv_t    _vtbl;

            /*
                E/r of complex
                    - domain
                    - unit
                    - cards
                    - meta
                    - optimize
                    - security
                    - persist
                    - ...
            */
            pv_t    _root;
        };

#   ifdef POS_CF_CLASS_PROPERTY
        __declspec(property(get=_bodyr)) _vt v;
        inline _vt& _bodyr() { return *_body(); }
#   endif

        inline i32_t _i32() const {
            return (i32_t)((hdr + 0x40000000) & 0xB0000000);
        }
        inline i32_t _i32(i32_t _32) {
            hdr = (_32 & 0x3FFFFFFF) | ((_32 >> 1) & 0x40000000);
            return hdr;
        }

        // --------------------------------------------------------------------------------
        //    functions for variant.
        // --------------------------------------------------------------------------------
        inline operator u8_t&() const { return *(u8_t *)_byval(); }
        inline operator u16_t&() const { return *(u16_t *)_byval(); }
        inline operator u32_t&() const { return *(u32_t *)_byval(); }
        inline operator u64_t&() const { return *(u64_t *)_byval(); }
        inline void *_0() const { return (void *)this; }
        inline void *_4() const { return (void *)((pb_t)this + 4); }
        inline complex_t *_complex() const {
            if (bComplex) return (complex_t *)_4();
            return NULL;
        }
        inline void *_sub() const {
            if (bComplex) return (void *)((complex_t *)_4() + 1);
            return _4();
        }

        // _body: bIsolated: 0,hdr|complex|subid|->value|...; 1,_pv->[value]
        inline _vt *_body() const;
        // no care with bComplex, so won't call read/write proc.
        inline _vt *__body() const {
            void *_b = _sub();
            if (bExType) _b = (void *)((pb_t)_b + _size_subtype_id(_b));
            if (bIsolated) {
                POS_ASSERT(_b != NULL);
                return *(_vt **)_b;
            }
            return (_vt *)_b;
        }
        inline _vt *_byval(_vt *_b = NULL) const;
        inline int _size_subtype_id(void *_id = NULL) const;
        inline size_t _size_body(bool _de_isolated = false, bool _de_pointer = false) const;
        inline int _size_complex(bool _less_prior = true) const {
            if (!bComplex) return 0;
            complex_t *_c = _complex();
            POS_ASSERT(_c);
            if (!_c->b_hfvc) {
                // non-HFVC
                if (_less_prior) {
                    // 01111111 11111111
                    u16_t mask = 0x7FFF;
                    u16_t F = (u16_t)(_c->flags & 0x7FFF);
                    int n = 0;
                    while (F & mask) {
                        n++;
                        mask <<= 1;
                    }
                    return n * sizeof(void *);
                }
                return sizeof(complex_t);
            }
            // HFVC
            return 0;
        }
        inline void *_prefix(u32_t *_len = NULL) {
            POS_ASSERT(bComplex);
            POS_ASSERT(_complex()->bPrefix);
            u32_t len = *((u32_t *)this - 1);
            if (_len) *_len = len;
            return (pb_t)this - len;
        }
        inline void *_suffix(u32_t *_len = NULL) {
            POS_ASSERT(bComplex);
            POS_ASSERT(_complex()->bSuffix);
            void *_p = (pb_t)_body() + _size_body();
            if (_len) *_len = *(u32_t *)_p;
            return _p;
        }
        inline bool _setf(u32_t _newf, bool _careful = true, u32_t _newcf = (u32_t)-1);
        inline void _release(const bool _destroy_self = false);
        inline void _free() { _release(true); }
        // the constructor/destructor are commented out,
        // so var_t can embedded into general C/C++ struct.
        // caller should remember to call release() after use it.
        /*
        ~var_t() {
            if (bBind) _release(false);
        }
        */
    };

    // 8-bytes, u32_t contaienr
    struct var8_t : public var_t {
        union {
            _v32_t  _32;
            _v_p_t  _p;
            pv_t    _pv;
        } body;
    };
    // 12-bytes, u64_t container
    struct var12_t : public var_t {
        union {
            _v32_t  _32;
            _v64_t  _64;
            _v_p_t  _p;
            pv_t    _pv;
        } body;
    };

    struct var16_t : public var_t {
        union {
            _v32_t  _32;
            _v64_t  _64;
            _v_p_t  _p;
            pv_t    _pv;
        } body;
        u32_t       _32_3;
    };

    struct var_posid_t : public var_t {
        posid96_t   id;
    };

    struct var_cid_t : public var_t {
        u32_t       id_0;
    };

    struct var_guid_t : public var_t {
        guid128_t   id;
    };

    struct var_complex_t : public var_t {
        complex_t * _c;
    };


POS_END
#include "config/alignment_end.h"



///////////////////////////////////////////////////////////////////////////////
//
// !! the var_t::_vt must defined after included these files.
// ----------------------------------------------------------------------------
#include "error.h"
#include "type.h"
#include "pointer.h"
#include "domain.h"
#include "unit.h"
#include "proc.h"
POS_BEGIN
    union var_t::_vt {
        _v32_t        _32;
        _v64_t        _64;
        _v128_t        _128;
        _v_p_t        _p;
        _v_x_t        _x;
        // m_pointer is used when bPointer bit set, and the format points to is
        // in raw-format. e.g., PVTF_POINTER | pvt_real32, than (void *)m_pointer -> real32_t.
        pointer_t    p;
        // all non-pos pointer. for general C/C++ *ptr type, multi-level ***ptr, are suitable.
        // this is NOT for bPointer type, bPointer is in case of VT_BYREF.
        pv_t        _pv;
    };
POS_END



///////////////////////////////////////////////////////////////////////////////
//
// Inline implementations & Utility functions
// ----------------------------------------------------------------------------
POS_BEGIN

    inline int var_t::_size_subtype_id(void *_id) const {
        if (_id == NULL) _id = _sub();
        switch (type) {
        case pvt_posid96:
            return 12;
        case pvt_guid128:
        case pvt_corbaid128:
            return 16;
        case pvt_cid:
            return _pos_size_cid((cid_t *)_id); ;
        default:
            // see any other sub-type as a pointer (like mpint,pasciz,...)
            return sizeof(void *);
        }
    }

    inline size_t var_t::_size_body(bool _de_isolated, bool _de_pointer) const {
        if (bIsolated && !_de_isolated) return sizeof(void *);
        void *_b;
        int _type;
        if (bPointer) {
            if (_de_pointer) {
                _b = _byval();
                _type = type;
            } else {
                _b = _body();
                _type = pvt_pointer;
            }
        } else {
            _b = _body();
            _type = type;
        }
        return _pos_sizeof(_type, _b);
    }

    inline bool var_t::_setf(u32_t _newf, bool _careful, u32_t _newcf) {
        //
        size_t blen = this->_size_body();

        if (_newcf != (u32_t)-1) {
            size_t clen = this->_size_complex();
        }
        return true;
    }

    inline var_t::_vt *var_t::_body() const {
        if (bComplex) {
            var_t::complex_t *_c = _complex();
            if (!_c->b_hfvc) {
                // non-HFVC
                if (_c->bRead) {
                    if (_c->bNoRWCache) {
                        return NULL; //_c->m_pReadProc->...;
                    }
                    // read into cache
                    _c->_core._read;    // __body return -> read()'cache
                }
                if (!_c->bBodyCached) {
                    _vt *_b = __body();
                    _c->_body = _b;
                    _c->bBodyCached = true;
                }
                return (var_t::_vt *)_c->_body;
            } else {
                // HFVC
				/*
                if (_c->bRead) {
                    if (_c->bNoRWCache) {
                        return NULL; //_c->_get_hfvc_pReadProc()->...;
                    }
                    // read into cache
                    _c->_get_hfvc_read();    // __body return -> read()'cache
                }
                _vt *&pb = _c->_get_hfvc_pBody();
                if (!_c->b_bodyCached) {
                    _vt *_b = __body();
                    pb = _b;
                    _c->b_bodyCached = true;
                }
                return pb;
				*/
            }
        }
        return __body();
    }

    // _byval: bPointer: 0,->_body; 1,hdr|->pv/ppv|info|or ->cache
    inline var_t::_vt *var_t::_byval(_vt *_b) const {
        if (!_b) _b = _body();
        if (!bPointer) return _b;
        // bPointer: _body() -> (byval), here '->' is a pointer_t.
        pointer_t *_p = (pointer_t *)_b;
        // this assertion is only failed when bIsolated, _cptr mustn't NULL.
        POS_ASSERT(_p != NULL);

        void **ppv;
        switch (_p->type) {
        case pointer_pv:
            ppv = (void **)_p->_4();
            POS_ASSERT(ppv != NULL);
            return (_vt *)*ppv;
        case pointer_null:
            return NULL;
        case pointer_invalid:
            POS_ASSERT(NULL);
            break;
        default:
            // for non-void *, _val() return void * -> cached_value.
            if (!_p->bCache) {
                return NULL;
            }
            POS_ASSERT(_p->_cache());
            return (_vt *)_p->_cache()->pCached;
        }
    }

    inline void var_t::_release(const bool _destroy_self) {
        if (!bBind_) {
            if (bComplex) {
                var_t::complex_t *_c = _complex();
                POS_ASSERT(_c);
                if (!_c->b_hfvc) {
                    // non-HFVC
                    if (_c->bRefCount) {
                        if (--_c->cRef) return;
                        // otherwise m_cRef may < 0 due to over-released.
                        POS_NORMAL(_c->cRef < 0x80000000);
                    }
                    if (_c->bBindFriend) {
                        var_t *p = _c->_core._friend;
                        POS_ASSERT(p);
                        p->_free();    // _pvt will release its members according to friend::bBind.
                    }
                    if (!_c->bBind_) {
                        if (_c->bDomain) {
                            POS_ASSERT(_c->m_pDomain);
                            _c->_root/*m_pDomain->_destroy()*/;
                        }
                        if (_c->bUnit) {
                            POS_ASSERT(_c->m_pUnit);
                            _c->_root/*m_pUnit->_destroy()*/;
                        }
                    }
                    if (_c->bLEB) {
                        POS_ASSERT(_c->m_pLEB);
                        _c->_root/*m_pLEB->_destroy()*/;
                    }
                } else {
                    // HFVC
					/*
                    if (_c->bRefCount) {
                        u32_t& c = _c->_get_hfvc_cRef();
                        if (--c) return;
                        // otherwise m_cRef may < 0 due to over-released.
                        POS_NORMAL(c < 0x80000000);
                    }
                    if (_c->bBindFriend) {
                        var_t *&p = _c->_get_hfvc_pFriend();
                        POS_ASSERT(p);
                        p->_free();
                    }
                    if (!_c->bBind_) {
                        if (_c->bDomain) {
                            domain_t *&p = _c->_get_hfvc_pDomain();
                            POS_ASSERT(p);
                            p->_free();
                        }
                        if (_c->bUnit) {
                            unit_t *&p = _c->_get_hfvc_pUnit();
                            POS_ASSERT(p);
                            p->_free();
                        }
                    }
                    if (_c->bLEB) {
                        var_t *&p = _c->_get_hfvc_pLEB();
                        POS_ASSERT(p);
                        p->_free();
                    }
					*/
                }
                delete _c;
            } // bComplex

            _vt *_b = _body();
            if (!bBindVal_) {
                _vt *p;
                p = _byval(_b);

                // release lasar,iunk,idisp,... etc.
                if (p) _pos_release(this, p);
            }

            // release the pointer
            if (bPointer && !_b->p.bBind_) _b->p._release();

            // if not isolated, _body will be destroy thru delete this.
            if (bIsolated) delete (void *)_b;
        }
        if (_destroy_self) delete (void *)this;
    } // var_t::_release

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
                -> _set_flags(), this is a complex procedure.
                ___________________________________________
                ___________________________________________
        Sandbox, Problems, Warnings:
                _______________________________________
                _______________________________________
                _______________________________________
        Development:
                The most important problem is to design a efficiency data type.
                Using POSIC to operate PVT is recommend, it is a complex issue.
                ___________________________________________________________
                ___________________________________________________________
        References:
                _________________________________________________
        Achievement:
                ________________________________________
        Outgrowth & Babies, Abbreviations:
                _____________________________
                _____________________________
                _____________________________
        Acknowledgement:
                _____________________________________________
*/
