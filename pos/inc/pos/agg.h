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
        Module Name:    POS Aggregates base
        Description:    The base header for all aggregates' type, include:
                            matrix graph hash set stream(noodle) etc.
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-5-8        ZD|started
        2003-5-13	    ZD|agg.union{pAggVar,VarHdr} for efficient
        2003-5-15	    ZD|try to add light-weight bdt::list_t, tuple_t, etc..
        2003-6-23	    ZD|compact the struct.
        2003-6-24	    ZD|isolated from bdt.h
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __AGGBASE_INCLUDED__
#define __AGGBASE_INCLUDED__
#ifdef POS_CF_ONCE
#   pragma once
#endif

#include "config.h"



///////////////////////////////////////////////////////////////////////////////
//
// Forward Declaration, Macros and Constants
// ----------------------------------------------------------------------------
POS_BEGIN
    enum SDR_type {
        SDR_DISABLE = 0,
        SDR_1,
        SDR_2,
        SDR_4,
        SDR_8,
        SDR_16,
        SDR_32,
        SDR_64,
        SDR_30_2,
        SDR_16_16,
        SDR_32_32,
        SDR_48_16,
        SDR_64_64,  // == 12
    };

	struct agg_hdr_t;

POS_END



// Header files to use
#include "variant.h"
#include "cpputil.h"
#include "error.h"

///////////////////////////////////////////////////////////////////////////////
//
// Prototypes
// ----------------------------------------------------------------------------
#include "config/alignment_begin.h"
POS_BEGIN

	// agg for: matrix set hash graph sandbox
	//	the agg_hdr_t contains most useful values for aggregators, like
	//		_r flags, _count, user _vAgg value;
	//	but not includes any item's data or entries to them.
	// ( 32-bytes )
	struct agg_hdr_t {
		union {
			u32_t _agg_hdr;
			union {
				struct {
					u16_t _agg_type;
					u16_t _agg_flags;
				};
				struct {
					int _agg_type_pad: 16;

					// variant- items, when item::type=pvt_void, it take the default type.
					int bMapVoidType: 1;

					// separate data and reference. (or stand-alone data and relation)
					//	(integer)-1 means default.
					int SDR: 4;

					// info may contain agg's name, agg's eigen value... or NULL if anonymous graph.
					int bAggVal: 1;

					// or "bDirty", the agg is validated.
                    // when not, some function will do updating before main process.
					int bValidated: 1;

					// each item's responsibility for updating the agg's value.
					//  e.g., when a matrix's unit is changed, then the unit shall update the matrix's eigenvalue.
					int bCleverItem: 1;

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

					// shall release the agg units.
					int bBindVal_: 1;

					// shall release the members (not include aggregates units)
					int bBind_: 1;

					int _agg_res2: 1;
				};
			};
		};

		// res usage about the entire aggregate.
		res_t	_r;

		// total items count.
		u32_t	_count;

		// SDR storage data (so matrix/set/hash/graph/sandbox/... can use index instead of)
		pv_t	_SDR;

		// the type may be used as template, if bMapVoidType and type==pvt_void.
		// the value may be used as the default, if SDR != SDR_DISABLE.  so:
		//	bMapVoidType	items use PVT instead of raw, otherwise (*)_vItem contain type info.
		//	_SDR		(*)Enabled if items are indexes.
		// (*): _vItem must set. ignored if (bMapVoidType && !_SDR)
		var8_t	_vItem;

		// info may contain agg's name, parent, agg's eigen value... or NULL if anonymous graph.
		var_t *	_vAgg;

		// scan the aggregate (not include embeded aggregate, just ONE level.)
		typedef bool (_stdcall agg_hdr_t::*agg_enum_proc)(void *);

		// WARNING: items shall be released first.
		inline void _release(const bool _destroy_self = false);
		inline void _free() { _release(true); }
	};

POS_END
#include "config/alignment_end.h"



///////////////////////////////////////////////////////////////////////////////
//
// Inline implementations & Utility functions
// ----------------------------------------------------------------------------
POS_BEGIN

	inline void agg_hdr_t::_release(const bool _destroy_self) {
		if (!bBind_) {
			_vItem._release();
			if (bAggVal) {
				POS_ASSERT(_vAgg);
				_vAgg->_free();
			}
			if (SDR != SDR_DISABLE) {
				if (_SDR) delete _SDR;
			}
		}
		if (_destroy_self) delete this;
	}

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