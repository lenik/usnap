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
        Module Name:    POS Raw Data Type Import
        Description:    ___________________________________________________
                        ___________________________________________________
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-4-17       ZD|started
        2003-6-4        ZD|_R_type for strict type.
        2003-6-23       ZD|alloc_strict_type => _AST_
        2003-7-15       ZD|updated
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __TYPEIMP_INCLUDED__
#define __TYPEIMP_INCLUDED__
#ifdef POS_CF_ONCE
#   pragma once
#endif

#include "config.h"
#include <windows.h>
#include <objbase.h>



///////////////////////////////////////////////////////////////////////////////
//
// Forward Declaration, Macros and Constants
// ----------------------------------------------------------------------------
POS_BEGIN
#   pragma pack(push, 1)
    namespace detail {
        // AST: alloc_strict_type
        template<const char *_uid_s, int _uid, typename _ty>
        struct _AST_ {
            //enum _type_uid { uid = _uid, };
            _ty _val;
    //      inline operator _ty() const { return _val; }
    //      inline operator _ty&() { return _val; }
        };
    }
#   pragma pack(pop)

#   define _R_type(type) typedef detail::_AST_<0/*__FILE__*/, __LINE__, type>

    // --------------------------------------------------------------------------------
    //  primary type (non-strict)
    // --------------------------------------------------------------------------------
    typedef UINT8           u8_t;
    typedef UINT16          u16_t;
    typedef UINT32          u32_t;
    typedef UINT64          u64_t;
    typedef INT8            i8_t;
    typedef INT16           i16_t;
    typedef INT32           i32_t;
    typedef INT64           i64_t;
    _R_type(__int8)         bcd8_t;
    _R_type(__int16)        bcd16_t;
    _R_type(__int32)        bcd32_t;
    _R_type(__int64)        bcd64_t;

#   pragma pack(push, 1)
    struct b8_t {
        int _0: 1; int _1: 1; int _2: 1; int _3: 1; int _4: 1; int _5: 1; int _6: 1; int _7: 1;
    };
    struct b16_t {
        int _0: 1; int _1: 1; int _2: 1; int _3: 1; int _4: 1; int _5: 1; int _6: 1; int _7: 1;
        int _8: 1; int _9: 1; int _a: 1; int _b: 1; int _c: 1; int _d: 1; int _e: 1; int _f: 1;
    };
    struct b32_t {
        int _0: 1; int _1: 1; int _2: 1; int _3: 1; int _4: 1; int _5: 1; int _6: 1; int _7: 1;
        int _8: 1; int _9: 1; int _a: 1; int _b: 1; int _c: 1; int _d: 1; int _e: 1; int _f: 1;
        int _g: 1; int _h: 1; int _i: 1; int _j: 1; int _k: 1; int _l: 1; int _m: 1; int _n: 1;
        int _o: 1; int _p: 1; int _q: 1; int _r: 1; int _s: 1; int _t: 1; int _u: 1; int _v: 1;
    };
    struct b64_t {
        int _0: 1; int _1: 1; int _2: 1; int _3: 1; int _4: 1; int _5: 1; int _6: 1; int _7: 1;
        int _8: 1; int _9: 1; int _a: 1; int _b: 1; int _c: 1; int _d: 1; int _e: 1; int _f: 1;
        int _g: 1; int _h: 1; int _i: 1; int _j: 1; int _k: 1; int _l: 1; int _m: 1; int _n: 1;
        int _o: 1; int _p: 1; int _q: 1; int _r: 1; int _s: 1; int _t: 1; int _u: 1; int _v: 1;
        b32_t   _;
    };
#   pragma pack(pop)

#   pragma pack(push, 4)
    typedef long double     r128_t;     // not used
    _R_type(u16_t)          r16_t;      // not used
    typedef float           r32_t;
    typedef double          r64_t;

    typedef struct { r128_t r, i; } c128_t;
    typedef struct { r16_t r, i; }  c16_t;
    typedef struct { r32_t r, i; }  c32_t;
    typedef struct { r64_t r, i; }  c64_t;

    // simple tuples and matrix
    struct var_t;
    typedef var_t * pv_2t  [2], pv_3t  [3], pv_4t  [4], pv_22t  [2][2], pv_33t  [3][3], pv_44t  [4][4];

    typedef u8_t    u8_2t  [2], u8_3t  [3], u8_4t  [4], u8_22t  [2][2], u8_33t  [3][3], u8_44t  [4][4];
    typedef u16_t   u16_2t [2], u16_3t [3], u16_4t [4], u16_22t [2][2], u16_33t [3][3], u16_44t [4][4];
    typedef u32_t   u32_2t [2], u32_3t [3], u32_4t [4], u32_22t [2][2], u32_33t [3][3], u32_44t [4][4];
    typedef u64_t   u64_2t [2], u64_3t [3], u64_4t [4], u64_22t [2][2], u64_33t [3][3], u64_44t [4][4];

    typedef i8_t    i8_2t  [2], i8_3t  [3], i8_4t  [4], i8_22t  [2][2], i8_33t  [3][3], i8_44t  [4][4];
    typedef i16_t   i16_2t [2], i16_3t [3], i16_4t [4], i16_22t [2][2], i16_33t [3][3], i16_44t [4][4];
    typedef i32_t   i32_2t [2], i32_3t [3], i32_4t [4], i32_22t [2][2], i32_33t [3][3], i32_44t [4][4];
    typedef i64_t   i64_2t [2], i64_3t [3], i64_4t [4], i64_22t [2][2], i64_33t [3][3], i64_44t [4][4];

    typedef r128_t  r128_2t[2], r128_3t[3], r128_4t[4], r128_22t[2][2], r128_33t[3][3], r128_44t[4][4];
    typedef r16_t   r16_2t [2], r16_3t [3], r16_4t [4], r16_22t [2][2], r16_33t [3][3], r16_44t [4][4];
    typedef r32_t   r32_2t [2], r32_3t [3], r32_4t [4], r32_22t [2][2], r32_33t [3][3], r32_44t [4][4];
    typedef r64_t   r64_2t [2], r64_3t [3], r64_4t [4], r64_22t [2][2], r64_33t [3][3], r64_44t [4][4];

    typedef c128_t  c128_2t[2], c128_3t[3], c128_4t[4], c128_22t[2][2], c128_33t[3][3], c128_44t[4][4];
    typedef c16_t   c16_2t [2], c16_3t [3], c16_4t [4], c16_22t [2][2], c16_33t [3][3], c16_44t [4][4];
    typedef c32_t   c32_2t [2], c32_3t [3], c32_4t [4], c32_22t [2][2], c32_33t [3][3], c32_44t [4][4];
    typedef c64_t   c64_2t [2], c64_3t [3], c64_4t [4], c64_22t [2][2], c64_33t [3][3], c64_44t [4][4];

    typedef void *          pv_t;
    typedef u8_t *          pb_t;
    _R_type(__int8)         rel8_t;
    _R_type(__int16)        rel16_t;
    _R_type(__int32)        rel32_t;
    _R_type(__int64)        rel64_t;
    _R_type(DWORD)          fourcc32_t;
    _R_type(u32_3t)         posid96_t;
    _R_type(u32_t)          cid_t;      // the first DWORD of the variable-length
    typedef GUID            guid128_t;
    _R_type(u32_4t)         corbaid128_t;
    typedef void *          _unknown_t;
    _R_type(_unknown_t)     epfs_t;
    _R_type(_unknown_t)     struct8_t;
    _R_type(_unknown_t)     struct16_t;
    _R_type(_unknown_t)     struct32_t;
    _R_type(_unknown_t)     struct64_t;
    _R_type(_unknown_t)     struct128_t;
    _R_type(_unknown_t)     struct256_t;
    _R_type(_unknown_t)     hfvc_d8_t;
    _R_type(_unknown_t)     hfvc_d4_t;
    _R_type(_unknown_t)     hfvc_d16_t;
    _R_type(_unknown_t)     hfvc_d5_t;
    _R_type(_unknown_t)     lasar_t;
    typedef VARIANT         _com_var_t;
    typedef SAFEARRAY       _com_array_t;
    typedef IUnknown *      _com_iunk_t;
    typedef IDispatch *     _com_idisp_t;
    typedef DECIMAL         _com_dec96_t;
    typedef SCODE           _com_scode_t;
    typedef CY              _com_cy64_t;
    typedef DATE            _com_date_t;
    _R_type(_unknown_t)     mpint_t;
    _R_type(_unknown_t)     mpreal_t;
    typedef char            a_t;
    typedef unsigned short  uc16_t;
    typedef unsigned char   uc8_t;
    typedef a_t *           asz_t;
    typedef const a_t *     asz_ct;
    typedef uc16_t *        ucsz16_t;
    typedef const uc16_t *  ucsz16_ct;
    typedef uc8_t *         ucsz8_t;
    typedef const uc8_t *   ucsz8_ct;
    typedef BSTR            bs_t;

    struct date_t {
        int _res: 4;
        int y: 12;
        int D: 4;   // Duration support: 0-15 days
        int m: 4;
        int w: 3;
        int d: 5;
    };

    struct time_t {
        int _res: 5;
        int hour: 5;
        int m: 6;
        int s: 6;
        int ms: 10;
    };

    struct dt_t {
        date_t d;
        time_t t;
    };

    // $ = a + b/2^31 + c + d
    struct cicy_t {
        i32_t a;
        i32_t b;
        float c;
        float d;
    };


    // --------------------------------------------------------------------------------
    //  utility unions
    // --------------------------------------------------------------------------------
    union _v32_t {
        u8_t        m_u8;
        u16_t       m_u16;
        u32_t       m_u32;
        i8_t        m_i8;
        i16_t       m_i16;
        i32_t       m_i32;
        bcd8_t      m_bcd8;
        bcd16_t     m_bcd16;
        bcd32_t     m_bcd32;
        b8_t        m_b8;
        b16_t       m_b16;
        b32_t       m_b32;
        r128_t      m_r128;
        r16_t       m_r16;
        r32_t       m_r32;
        rel8_t      m_rel8;
        rel16_t     m_rel16;
        rel32_t     m_rel32;

        fourcc32_t  m_fourcc32;
        cid_t       m_cid_1;

        date_t      m_date;
        time_t      m_time;
    };

    union _v64_t {
        u64_t           m_u64;
        i64_t           m_i64;
        bcd64_t         m_bcd64;
        b64_t           m_b64;
        r64_t           m_r64;
        rel64_t         m_rel64;

        _com_date_t     m__com_date;
        _com_cy64_t     m__com_cy64;

        dt_t            m_dt;
    };

    union _v128_t {
        posid96_t       m_posid;
        guid128_t       m_guid;
        corbaid128_t    m_corbaid;

        _com_dec96_t    m__com_dec96;   // |DECIMAL|=128

        cicy_t          m_cicy;
    };

    union _v_p_t {
        pv_t            m_pv;

        mpint_t         m_mpint;
        mpreal_t        m_mpreal;
        a_t             m_a;
        uc16_t          m_uc16;
        uc8_t           m_uc8;
        asz_t           m_asz;
        asz_ct          m_asz_c;
        ucsz16_t        m_ucsz16;
        ucsz16_ct       m_ucsz16_c;
        ucsz8_t         m_ucsz8;
        ucsz8_ct        m_ucsz8_c;
        bs_t            m_bs;

        _com_iunk_t     m__com_iunk;
        _com_idisp_t    m__com_idisp;
        _com_scode_t    m__com_scode;
    };

    union _v_x_t {
        _com_var_t      m__com_var;
        _com_array_t    m__com_array;

        epfs_t          m_epfs;
        struct8_t       m_struct8;
        struct16_t      m_struct16;
        struct32_t      m_struct32;
        struct64_t      m_struct64;
        struct128_t     m_struct128;
        struct256_t     m_struct256;
        hfvc_d8_t       m_hfvc_d8;
        hfvc_d4_t       m_hfvc_d4;
        hfvc_d16_t      m_hfvc_d16;
        hfvc_d5_t       m_hfvc_d5;
        lasar_t         m_lasar;
    };
#   pragma pack(pop)

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
                _______________________________________
                _______________________________________
                _______________________________________
                _______________________________________
        Development:
                ___________________________________________________________
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
