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
        Module Name:    _________________________
        Description:    ___________________________________________________
                        ___________________________________________________
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-MM-DD      ZD|started
        2003-MM-DD
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __MODULE_INCLUDED__
#define __MODULE_INCLUDED__
#ifdef POS_CF_ONCE
#   pragma once
#endif

#include "config.h"



///////////////////////////////////////////////////////////////////////////////
//
// Forward Declaration, Macros and Constants
// ----------------------------------------------------------------------------
POS_BEGIN

POS_END



// Header files to use
#include "variant.h"
#include "error.h"

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



///////////////////////////////////////////////////////////////////////////////
//
// (SGP) Space Orgnization
// ----------------------------------------------------------------------------
struct space_element {
    space *     parent;

    outline     space_domain;

    space *     assoc_targets[];

    z_order     layer;

};


/*
    var_hdr_t
        flags
    var_
*/

var_t * PosVarWrap(void *pv) {
    var12_t *pWrapped = new var16_t;
    pWrapped->bComplex = TRUE;
    pWrapped->_body()->_pv = pv;
    pWrapped->_complex() = NULL;
    return pWrapped;
}

void * PosVarUnwrap(var_t *pvt) {
    return pvt->_body();
}
