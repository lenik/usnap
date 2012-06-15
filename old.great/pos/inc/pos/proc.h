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
        Module Name:    Advanced Procedure
        Description:    POS Procedure includes general pascal/cdecl callings
                        and lots of other type procedures defined by different
                        calling protocols.
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-5-7        ZD|Started
        2003-5-13       ZD|some flags and SPC-support
        2003-7-15       ZD|Updated
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
    struct proc_t;

    enum proc_type {
        proc_pascal = 0,        // pf
        proc_cdecl,             // pf
        proc_fastcall,          // pf
        proc_thiscall,          // pf | sdd *
        proc_dispinvoke,        // invoke_desc | sdd *
        proc_interrupt,         // int_desc | sdd *
        proc_rpc,               // rpc_desc
        proc_poscall,
        proc_posrpc,
        proc_lasarcall,
        proc_composition,
        proc_script,            // script_code * | script_desc
        proc_exec,              // exec(path,param) * | exec_desc
        proc_control,           // control_code * | control_desc
    };

POS_END



// Header files to use
#include "error.h"
#include "variant.h"
#include "pointer.h"


///////////////////////////////////////////////////////////////////////////////
//
// Prototypes
// ----------------------------------------------------------------------------
#include "config/alignment_begin.h"
POS_BEGIN
    struct proc_t {
        union {
            u32_t hdr;
            union {
                struct {
                    u16_t type;
                    u16_t flags;
                };
                struct {
                    int _type_pad: 16;

                    // static flags

                    // the procedure is designed carefully to support parellel calling.
                    int bReentrant: 1;

                    // no obvious block. a procedure take less than __POS__ASYNC_TIMEOUT time.
                    int bAsync: 1;

                    // follow SPC(structured procedure control) standard
                    int bControlable: 1;


                    // run-time flags

                    // in-call is period just from enter procedure to leave, not include async process, etc.
                    int bIncall: 1;

                    // for reentrant/async, it maybe implemented by message-queue, so busy is useful.
                    // busy is period from precedure started until exited, include async process, ...
                    int bBusy: 1;

                    // SPC flags
                    int bPaused: 1;

                    // responded to exit/pause/resume/... requests. (so SPC is currently exiting/pausing/resuming/...)
                    int bResponded: 1;

                    // the procedure is calling another procedure currently.
                    // if a system made up with 100% SPC, and all SPC is bOutgoing, the deadlock happens.
                    int bOutgoing: 1;
                };
            };
        };

        //Pointer
    };


    struct proc_t_spc {
        enum spc_status;
        enum spc_period {
            spc_period_parsing,
            spc_period_initializing,
            spc_period_exiting,
            spc_period_pausing,
            spc_period_calculating
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
