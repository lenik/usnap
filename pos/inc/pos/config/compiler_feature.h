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
        Module Name:    _________________________
        Description:    ___________________________________________________
                        ___________________________________________________
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-MM-DD      ZD|Started
        2003-MM-DD
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __CONFIG_INCLUDED__
#define __CONFIG_INCLUDED__


#define LOCAL_IMP(x)            ::pos::config::x


///////////////////////////////////////////////////////////////////////////////
//
// Default Compiler-Related Settings (Macros)
// ----------------------------------------------------------------------------
POS_BEGIN
namespace config {

    typedef enum _COMPILER_TYPE {
        COMPILER_ANSI_C,
        COMPILER_CVI_CALCIUM,
        COMPILER_GNU_C,
        COMPILER_COMEAU_C,
        COMPILER_KAI_C,
        COMPILER_SGI_C,
        COMPILER_DEC_CXX,
        COMPILER_GREENHILLS_C,
        COMPILER_BORLAND_C,
        COMPILER_INTEL_C,
        COMPILER_METROWERKS,
        COMPILER_SUNPRO_C,
        COMPILER_HP_C,
        COMPILER_MPW_C,
        COMPILER_IBM_C,
        COMPILER_MICROSOFT_C,
    } COMPILER_TYPE;

} // (pos:)config:
POS_END



///////////////////////////////////////////////////////////////////////////////
//
// Default Compiler-Related Settings (Macros)
// ----------------------------------------------------------------------------
POS_BEGIN

#   if defined __Ca__                          // CVI Calcium C*
#       define POS_COMPILER LOCAL_IMP(COMPILER_CVI_CALCIUM)
#       include "compiler/cvica.h"
#   elif defined __ANSIC__                     // Using ANSI C/C++
#       define POS_COMPILER LOCAL_IMP(COMPILER_ANSI_C)
#       include "compiler/ansic.h"
#   elif defined __GNUC__                      // GNU C++
#       define POS_COMPILER LOCAL_IMP(COMPILER_GNU_C)
#       include "compiler/gnuc.h"
#   elif defined __COMO__                      // Comeau C++
#       define POS_COMPILER LOCAL_IMP(COMPILER_COMEAU_C)
#       include "compiler/comeau.h"
#   elif defined __KCC                         // Kai C++
#       define POS_COMPILER LOCAL_IMP(COMPILER_KAI_C)
#       include "compiler/kai.h"
#   elif defined __sgi                         // SGI MIPS pro C++
#       define POS_COMPILER LOCAL_IMP(COMPILER_SGI_C)
#       include "compiler/sgi.h"
#   elif defined __DECCXX                      // Compaq Tru64 Unix cxx
#       define POS_COMPILER LOCAL_IMP(COMPILER_DEC_CXX)
#       include "compiler/dec.h"
#   elif defined __ghs                         // Greenhills C++
#       define POS_COMPILER LOCAL_IMP(COMPILER_GREENHILLS_C)
#       include "compiler/ghs.h"
#   elif defined __BORLANDC__                  // Borland C++
#       define POS_COMPILER LOCAL_IMP(COMPILER__BORLAND_C)
#       include "compiler/borland.h"
#   elif defined (__ICL) || defined(__ICC)     // Intel C++
#       define POS_COMPILER LOCAL_IMP(COMPILER_INTEL_C)
#       include "compiler/intel.h"
#   elif defined __MWERKS__                    // Metrowerks CodeWarrior
#       define POS_COMPILER LOCAL_IMP(COMPILER_METROWERKS)
#       include "compiler/mwerks.h"
#   elif defined __SUNPRO_CC                   // Sun Workshop Compiler C++
#       define POS_COMPILER LOCAL_IMP(COMPILER_SUNPRO_C)
#       include "compiler/sun.h"
#   elif defined __HP_aCC                      // HP aCC
#       define POS_COMPILER LOCAL_IMP(COMPILER_HP_C)
#       include "compiler/hp.h"
#   elif defined (__MRC__) || defined(__SC__)  // MPW MrC++ or SC++
#       define POS_COMPILER LOCAL_IMP(COMPILER_MPW_C)
#       include "compiler/mpw.h"
#   elif defined __IBMCPP__                    // IBM Visual Age
#       define POS_COMPILER LOCAL_IMP(COMPILER_IBM_C)
#       include "compiler/ibm.h"
#   elif defined _MSC_VER
#       define POS_COMPILER LOCAL_IMP(COMPILER_MICROSOFT_C)
#       include "compiler/msc.h"
#   else
#       error "No compiler selected!"
#   endif

POS_END

#endif

// Apply once-include to self.
#ifdef POS_CF_ONCE
#   pragma once
#endif
#undef LOCAL_IMP



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
