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
        Module Name:    Kernel Flags
        Description:    ___________________________________________________
                        ___________________________________________________
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-4-17       ZD|Started
        2003-5-15       ZD|split from util.h
        2003-6-29       ZD|adjust layout, as:  LSSCCDAP WEBEIEIR CE....VV SLIMUAAX
        2003-7-3        ZD|adjust layout, as: (....BECE LSSCWEIA)RDCIERVV SLIMUAAX,
                          |then (...) can be overloaded.
        2003-7-3        ZD|adjust layout, as:  ........ SCWEIACE LSDRCIER SLIMUAAX
        2003-7
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __KFLAGS_INCLUDED__
#define __KFLAGS_INCLUDED__
#ifdef POS_CF_ONCE
#   pragma once
#endif

#include "config.h"



///////////////////////////////////////////////////////////////////////////////
//
// Forward Declaration, Macros and Constants
// ----------------------------------------------------------------------------
POS_BEGIN

#   define UTILRESF_LOADED             0x00000001
#   define UTILRESF_SCANED             0x00000002
#   define UTILRESF_SAVEED             0x00000004
#   define UTILRESF_CHECKED            0x00000008
#   define UTILRESF_CACHED             0x00000010
#   define UTILRESF_DIRTY              0x00000020
#   define UTILRESF_ACTIVE             0x00000040
#   define UTILRESF_PROTECT            0x00000080
#   define UTILRESF_WARN               0x00000100
#   define UTILRESF_ERROR              0x00000200
#   define UTILRESF_BEGIN              0x00000400
#   define UTILRESF_END                0x00000800
#   define UTILRESF_IGNORE             0x00001000
#   define UTILRESF_EXPORT             0x00002000
#   define UTILRESF_INTEGRAL           0x00004000
#   define UTILRESF_RAW                0x00008000
#   define UTILRESF_COMPRESS           0x00010000
#   define UTILRESF_ENCRYPT            0x00020000
#   define UTILRESF_RESERVED           0x003C0000
#   define UTILRESF_VALUE              0x00400000
#   define UTILRESF_PVT                0x00800000
#   define UTILRESF_SYNC               0x01000000
#   define UTILRESF_LOCK               0x02000000
#   define UTILRESF_INVALID            0x04000000
#   define UTILRESF_MARK               0x08000000
#   define UTILRESF_USER               0x10000000
#   define UTILRESF_BINDX              0x20000000
#   define UTILRESF_BIND               0x40000000
#   define UTILRESF_EXTEND             0x80000000

#   define UTILARITHF_ZERO             0x00000001
#   define UTILARITHF_PARITY           0x00000002
#   define UTILARITHF_SIGN             0x00000004
#   define UTILARITHF_CARRY            0x00000008
#   define UTILARITHF_OVERFLOW         0x00000010
#   define UTILARITHF_DIRECTION        0x00000020
#   define UTILARITHF_NAN              0x00000040
#   define UTILARITHF_PRECISIONLOST    0x00000080
#   define UTILARITHF_SATURATED        0x00000100
#   define UTILARITHF_EXTEND           0x80000000

#   define UTILAPPF_DEBUG              0x00000001
#   define UTILAPPF_SAFE               0x00000002
#   define UTILAPPF_LOG                0x00000004
#   define UTILAPPF_ADS                0x00000008

    union res_t;
    union arith_t;
    union app_t;
    union word_t;

POS_END



// Header files to use
#include "error.h"
#include "variant.h"

///////////////////////////////////////////////////////////////////////////////
//
// Prototypes
// ----------------------------------------------------------------------------
#include "config/alignment_begin.h"
POS_BEGIN

    union res_t {
        u32_t flags;
        struct {
            int _res1: 8;

            // -------------------------------------------------------------------------SCWEIACE

            // bParsed_    object is scaned and analyzed
            int bScaned_: 1;

            // bVerified_    object was checked. however, the result may be error.
            int bChecked_: 1;

            // bVery_    warns in the object
            int bWarn: 1;

            // bOkay_    errors in the object
            int bError: 1;

            // bPartial    object is integral
            int bIntegral_: 1;

            // bEnabled_    object is actived (shall be deactived)
            int bActive_: 1;

            // bFlat_    object is compressed
            int bCompressed: 1;

            // bPlain_    object is encrypted
            int bEncrypted: 1;

            // -------------------------------------------------------------------------LSDRCIER
            // bInit_    object is loaded
            int bLoaded_: 1;

            // bFlushed    saved to disk
            int bSaved: 1;

            // bModified    has been modified
            int bDirty: 1;

            // bProtect    object is protected (permanently compared to bLocked)
            int bReadOnly: 1;

            // bIndexed    cache for the object is available
            int bCached: 1;

            // bImportant_    the object may be mapped or duplicated, or pre-deleted.
            int bIgnore: 1;

            // bVisible    (public) object is exported to others
            int bExport: 1;

            // bDirectly_    object is in raw-mode. otherwise, operating on the object will be verified.
            int bRaw_: 1;

            // -------------------------------------------------------------------------SLIMUAAX
            // object is synchoronized.
            int bSync_: 1;

            // locked by other
            int bLock: 1;

            // object is invalid. e.g. wrong format, expired, etc.
            int bInvalid: 1;

            // object is marked
            int bMark: 1;

            // reserved for user.
            int bUser: 1;

            // extend auto management bit.
            int bBindX_: 1;

            // apply auto management to object.
            int bBind_: 1;

            // more data after flags
            int bExtend: 1;

            void *_4() { return (void *)((u8_t *)this + 4); }
        };

        // synonym, ........ PVVOPEFP IFMPIIVD SLIMUAAX
        struct {
            int _res2: 8;

            int bParsed_: 1;
            int bVerified_: 1;
            int bVery_: 1;
            int bOkay_: 1;
            int bPartial: 1;
            int bEnabled_: 1;
            int bFlat_: 1;
            int bPlain_: 1;

            int bInit_: 1;
            int bFlushed: 1;
            int bModified: 1;
            int bProtect: 1;
            int bIndexed: 1;
            int bImportant_: 1;
            int bVisible: 1;
            int bDirectly_: 1;

            int _res3: 8;
        };
    }; // res

    union right_t {
        u32_t flags;
        struct {
            int bRead: 1;
            int bWrite: 1;
            int bExecute: 1;
            int bAccess: 1;
            int bModify: 1;
            int bCreate: 1;
            int bDelete: 1;
            int bSuper: 1;
            int bShutdown: 1;
            int bLog: 1;
        };
    };

    union arith_t {
        u32_t flags;
        struct {
            // ZF
            int bZero: 1;

            // PF
            int bParity: 1;

            // SF
            int bSign: 1;

            // CF
            int bCarry: 1;

            // OF; relate to SF/+inf or -inf, DF/>>inf or <<inf
            int bOverflow: 1;

            // DF
            int bDirection: 1;

            // not a number, or data is invalid format
            int bNaN: 1;

            // precision lost during calculating
            int bPrecisionLost: 1;

            // saturated, e.g. 100+3 == 100, '3' is cut for saturated mode calc.
            int bSaturated: 1;

            int _res1: 7;
            int _res2: 15;

            // this is an extended _flags
            int bExtend: 1;

            void *_4() { return (void *)((u8_t *)this + 4); }
        };
    }; // arith


    union app_t {
        u32_t flags;
        struct {
            // current was in debugging mode
            int debug: 1;
            // safe test enabled
            int safe: 1;
            // event loging is enabled
            int log: 1;
            // advertisement wrapping is enabled
            int ads: 1;
        };
    };  // app

    // not used yet.
    union word_t {
        u32_t flags;
        struct {
            enum {
                _bit_32 = 0,
                _bit_64 = 1,
                _bit_128 = 2,
                _bit_16 = 3
            } wordlength: 2;
            // align at 0-BYTE, 1-WORD, 2-DWORD, 3-8Bytes, 4-16Bytes, 5-32Bytes, 6-64Bytes, 7-128Bytes
            int alignbytes: 3;
            // mask the most significant bit (invalidate it)
            int msbmask: 1;
            // escape pointer enabled
            int escptr_enabled: 1;
        };
    };

POS_END
#include "config/alignment_end.h"



///////////////////////////////////////////////////////////////////////////////
//
// Inline implementations & Utility functions
// ----------------------------------------------------------------------------
POS_BEGIN

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
