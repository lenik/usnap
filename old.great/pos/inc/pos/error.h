/*
    POS - Practice-Oriented Structure (System)                        Version 1
    ---------------------------------------------------------------------------
                                Power Of the Software !

    License:    POS.LCL
    See Also:   X@A LaS PoX EPFS HFVC 1/bios HAS/HAD Aipos

    Ci Virtuality Integrated,
    Copyright 1997-2003, CHINA. All rights reserved.

    File:
        Module Name:    Error Definition
        Description:    ___________________________________________________
                        ___________________________________________________
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-5-8        ZD|Started
        2003-5-14       ZD|Lots of changes
        2003-7-15       ZD|Updated
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __ERROR_INCLUDED__
#define __ERROR_INCLUDED__
#ifdef POS_CF_ONCE
#   pragma once
#endif

#include "config.h"



///////////////////////////////////////////////////////////////////////////////
//
// Forward Declaration, Macros and Constants
// ----------------------------------------------------------------------------
POS_BEGIN

    enum error_type {
        err_none = 0,           // no info available. (no matter success/failure.)
        err_unexpected,         // unexpected error
        err_composition,        // complex error
        err_algorithm,          // class-algorithm
        err_execution,          // class-execution
        err_structure,          // class-structure
        err_resource,           // class-resource
        err_device,             // class-device, hardware
        err_network,            // class-network, router, gateway
        err_index,              // class-index, key
        err_pointer,            // class-pointer, buffer
        err_verify,             // class-verify, assertion
        err_security,           // class-security
        err_multiprocess,       // class-multiprocess
        err_version,            // class-version, software project
        err_system,             // class-system
        err_procedure,          // class-procedure system
        err_conception,         // class-conception
        err_nature,             // class-nature
        err_philosophy,         // class-philosophy
        err_specified,          // class-conflict with user specified restrictions
        // --------------------------------------------------------------------------------
        //    predefined detail error type.
        // --------------------------------------------------------------------------------
        err_alg_divide0,        // divided by zero
        err_alg_overflow,       //
        err_alg_domain,
        err_st_crossref,
        err_st_recursion,
        err_res_memory,
        err_res_bad,            // resource is bad, e.g. bad sectors.
        err_dev_,
        err_net_,
        err_id_bound,
        err_ptr_null,
        err_ptr_overlap,
        err_verify_pre,         // sub-routine: parameters check
        err_verify_post,        // sub-routine: result check
        err_sec_noaccess,       // no privilege to access the resource.
        err_mp_lock,            // related resource is locked by another processor.
        err_ver_obsolete,       // the routine is unavailable due to obsolete version
        err_ver_notyet,         // the routine is for future use.
        err_sys_initialize,     // can't initialize
        err_sys_dependency,     // some dependent feature/services are unavailable.
        err_proc_input,         //
        err_spec_timeout,       // timeout to caller provided duration
        err_spec_filter,        // caller suppressed the item
    }; // enum error_type

    struct error_t;
    struct error_value_t;
    struct error_more_t;
    namespace error {
        struct algorithm_t;
        struct structure_t;
        struct resource_t;
        struct device_t;
        struct network_t;
        struct index_t;
        struct security_t;
        struct multiprocess_t;
        struct version_t;
        struct system_t;
        struct procedure_t;
        struct conception_t;
        struct nature_t;
        struct philosophy_t;
        struct specified_t;
    }
    namespace ab {
        typedef error_t                     Err;
        typedef error_value_t               ErrV;
        typedef error_more_t                ErrX;
        typedef error::algorithm_t          ErA;
        typedef error::structure_t          ErSt;
        typedef error::resource_t           ErR;
        typedef error::device_t             ErD;
        typedef error::network_t            ErN;
        typedef error::index_t              ErI;
        typedef error::security_t           ErSec;
        typedef error::multiprocess_t       ErMP;
        typedef error::version_t            ErV;
        typedef error::system_t             ErSys;
        typedef error::procedure_t          ErP;
        typedef error::conception_t         ErC;
        typedef error::nature_t             ErNa;
        typedef error::philosophy_t         ErPh;
        typedef error::specified_t          ErX;
    }

POS_END



// Header files to use
#include "variant.h"
#include "pointer.h"
#include "bdt.h"
#include "k_vars.h"

///////////////////////////////////////////////////////////////////////////////
//
// Prototypes
// ----------------------------------------------------------------------------
#include "config/alignment_begin.h"
POS_BEGIN
    // 4-bytes error base (conceptional error)
    struct error_t {
        union {
            // code<0 means failure.
            i32_t code;
            u32_t hdr;
            union {
                struct {
                    u16_t type;
                    u16_t flags;
                };
                struct {
                    int _type_pad: 16;

                    // a 12-bytes value is valid for the error.
                    int bValue: 1;

                    // detail in var_t format follow the header.
                    // detail can be in _pos_error::detail_t.
                    int bDetail: 1;

                    // resumable error provides a resume-entry for resume.
                    int bResumable: 1;

                    // for success, optimizing has taken; for failure, some saving process has taken.
                    int bBetter: 1;

                    // bWorse means concessional success, or extended failure affected something else.
                    int bWorse: 1;

                    // for success/failure, this means the error is informational;
                    // for failure, caller must do something with non-ignorable error.
                    int bIgnorable: 1;

                    // don't change this error, and pass it directly to the topmost caller.
                    int bFinally: 1;

                    //
                    int _res1: 1;

                    // -------------------------------------------------------------------------SLIMUAAX
                    // object is synchoronized.
                    int bSync_: 1;

                    // locked by other
                    int bLock: 1;

                    // object is invalid. e.g. wrong format, expired, etc.
                    int bInvalid: 1;

                    // object is marked
                    int bMark: 1;

                    int bPVT_Value: 1;
                    int bPVT_Position: 1;

                    // auto release binded value and related detail info.
                    int bBind_: 1;

                    // success or failure
                    int bFailure: 1;
                };
            };
        };
    };

    // error with 12-bytes binded value, this is useful when error_t is used as return-type.
    struct error_value_t : public error_t {
        var12_t     _v12;
    };

    struct error_more_t: public error_value_t {
        // last errors on the stack
        union {
            error_t *       _st4;
            error_value_t * _st16;
            error_more_t *  _st32;
        };

        proc_t          _resume;
        //proc_t          _undo;

        struct detail_t {
            enum detail_position_type {
                dpt_file_row_col,
                dpt_mod_off_range,
                dpt_obj_off64,
                dpt_tree,
            };
            union {
                u32_t       hdr;
                struct {
                    u8_t    dpt;
                    u8_t    _x_type;
                };
            };
            union {
                struct {
                    asz_t   sz_file;
                    u32_t   n_row;
                    u32_t   n_col;
                } frc;
                struct {
                    asz_t   sz_mod;
                    u32_t   n_off;
                    u32_t   n_range;
                } mor;
                struct {
                    pv_t    _obj;
                    u64_t   n_off64;
                } oo64;
                pv_t _tree;
            } position;
        } *_detail;
    };

    namespace error {
        struct algorithm_t {
        };
        struct structure_t {
        };
        struct resource_t {
        };
        struct device_t {
        };
        struct index_t {
        };
        struct security_t {
        };
        struct multiprocess_t {
        };
        struct version_t {
        };
        struct system_t {
        };
        struct procedure_t {
        };
        struct conception_t {
        };
        struct nature_t {
        };
        struct philosophy_t {
        };
        struct specified_t {
        };
    } // pos:error:
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
