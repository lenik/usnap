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
        Module Name:    POS Image Basic
        Description:    From [CampoAccelerator] Image (2D)
                          ->FastImg
                              ->SGP
                                  ->CeICU (Image Core Utility)
                                      ->CeImage ( ->CeIMG )
                                          ->POS Image
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-7-18       ZD|started
        2003-
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __Pos_IMAGE_INCLUDED__
#define __Pos_IMAGE_INCLUDED__
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
#include "matrix.h"

///////////////////////////////////////////////////////////////////////////////
//
// Prototypes
// ----------------------------------------------------------------------------
#include "config/alignment_begin.h"
POS_BEGIN

    enum color_model {
    };

    struct image_t {

        // POS Image is based on matrix.
        //  the size of "pixel-unit" and alignment information is saved in
        //      spec of the matrix, not include color-model and
        matrix_t *      _mat;


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
