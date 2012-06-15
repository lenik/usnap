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
        Module Name:    POS Kernel Import
        Description:    Import the kernel POS functions, which are used to
                        help implementing the POS frameworks.
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-7-15       ZD|Started
        2003-7-
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __KERNEL_IMP_INCLUDED__
#define __KERNEL_IMP_INCLUDED__
#ifdef POS_CF_ONCE
#   pragma once
#endif

#include "config.h"



///////////////////////////////////////////////////////////////////////////////
//
// Forward Declaration, Macros and Constants
// ----------------------------------------------------------------------------
POS_BEGIN

#   define PosCheckAssert(x)
#   define PosEvalAssert(x)

#   define PosCheckNormal(x)
#   define PosEvalNormal(x)

#   define PosCheckOutput(x)
#   define PosEvalOutput(x)

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
        Development:
                Debug Feature:
                    PosCheckAssert, PosEvalAssert, ...
                POS Functions
                    void *PosAllocate(env_t *, size, grow, flags);
                    void *PosFree(env_t *, void *);
                    BOOL PosVarIsValid(PVT *, flags_which);
                    BOOL PosVarGetSize(PVT *, flags_which);
                    BOOL PosGraphEnum(graph_t *, proc_t *, flags);
                    BOOL Pos;
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
