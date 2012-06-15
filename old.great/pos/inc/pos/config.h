/*
                                                                  * CVI DRAFT *
    POS - Practice-Oriented Structure (System)	                      Version 1
    ---------------------------------------------------------------------------
                                Power Of the Software !

    License:    POS.LCL
    See Also:   X@A LaS PoX EPFS HFVC 1/bios HAS/HAD Aipos

    Ci Virtuality Integrated,
    Copyright 1997-2003, CHINA. All rights reserved.

    File:
        Module Name:    Main Configuration File
        Description:    ___________________________________________________
                        ___________________________________________________
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-4-17       ZD|Started
        2003-7-14       ZD|Rewrite
        2003-7-
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __CONFIG_INCLUDED__
#define __CONFIG_INCLUDED__
#ifdef POS_CF_ONCE
#   pragma once
#endif

#define POS_BEGIN               namespace pos {
#define POS_END                 }


//#	pragma warning(disable: 4100)		// unreferenced formal parameter
//#	pragma warning(disable: 4127)		// condition is constant
//#	pragma warning(disable: 4245)		// signed/unsigned mismatch
#	pragma warning(disable: 4786)		// symbol long in debug info
//#	pragma warning(disable: 4530)		// exception with /GX


///////////////////////////////////////////////////////////////////////////////
//
// Macros
// ----------------------------------------------------------------------------
//
//      PSL:    POS STRICT LEVEL, the lower means the more strict.
//
//
#define POS_VERSION                 1       // POS Standard 1.0
#define POS_BITS                    32      // 32-bit environment

#define POS_SL_CHECK                1
#define POS_SL_ALPHA                16
#define POS_SL_BETA                 32
#define POS_SL_GAMMA                64
#define POS_SL_RELEASE              256
#define POS_SL_REALTIME             512
#define POS_SL_ROM                  1024
#ifndef POS_SL
#   if defined(_DEBUG) || defined(DEBUG)
#       define POS_SL               POS_SL_DEBUG
#   elif defined(_RELEASE) || defined(RELEASE) || defined(NDEBUG)
#       define POS_SL               POS_SL_
#   endif
#endif
#if POS_SL <= POS_SL_CHECK
#   define POS_CHECKING
#endif
#if POS_SL <= POS_SL_CHECK
#   define POS_ASSERT(x)            PosCheckAssert(x)
#   define POS_NORMAL(x)            PosCheckNormal(x)
#   define POS_OUTPUT(x)            PosCheckOutput(x)
#elif POS_SL < POS_SL_RELEASE
#   define POS_ASSERT(x)            PosEvalAssert(x)
#   define POS_NORMAL(x)            PosEvalNormal(x)
#   define POS_OUTPUT(x)            PosEvalOutput(x)
#else
#   define POS_ASSERT(x)
#   define POS_NORMAL(x)
#   define POS_OUTPUT(x)
#endif


#define POS_INIT0(v)                memset(&(v), 0, sizeof(v))

#include "config/compiler_feature.h"



///////////////////////////////////////////////////////////////////////////////
//
// Default Headers
// ----------------------------------------------------------------------------
#include "typeimp.h"
#include "krnlimp.h"
#include "k_flags.h"
#include "allocator.h"

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
