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
        Module Name:    POS Matrix
        Description:    ___________________________________________________
                        ___________________________________________________
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-5-10       ZD|started
        2003-5-13       ZD|LEB-design
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __MATRIX_INCLUDED__
#define __MATRIX_INCLUDED__
#ifdef POS_CF_ONCE
#   pragma once
#endif

#include "config.h"



///////////////////////////////////////////////////////////////////////////////
//
// Forward Declaration, Macros and Constants
// ----------------------------------------------------------------------------
POS_BEGIN
	enum matrix_type {
		matrix_zero = 0,	// zero matrix for any type. what is 'zero'? this maybe configured in pos-env.
		matrix_identity,	// identity matrix for any type.
		matrix_dynamic,		// M-DD for Interface-Driven.
		matrix_vector,		// 1-D matrix, or simple array.
		matrix_mat2d,		// 2-D matrix with mathematic attributes
		matrix_quad,		// quadrate  2-D matrix
		matrix_rect,		// rectangle 2-D matrix
		matrix_quadx,		// quadrate  x-D matrix
		matrix_rectx,		// rectangle x-D matrix
	};

	enum streaming_code {
		SC_FULL,
		SC_SELF_DESC,
		SC_DELTA,
		SC_INTERP,
	};

	struct matrix_t;
	typedef matrix_t Matrix;

	namespace matrix {
		struct dynamic_t;
		struct vector_t;
		struct rect_t;
		struct quadx_t;
		struct rectx_t;
		struct mat_quad_t;
		struct mat_quadx_t;

		//struct
		struct raw_sparse_t;

	}

	namespace ab {
		typedef matrix::vector_t	V;
		typedef matrix::rect_t		R;
		typedef matrix::quadx_t		Qx;
		typedef matrix::rectx_t		Rx;
		typedef matrix::mat_quad_t	M;
		typedef matrix::mat_quadx_t	Mx;
	}

POS_END



// Header files to use
#include "variant.h"
#include "pointer.h"
#include "bdt.h"
#include "agg.h"
#include "error.h"

///////////////////////////////////////////////////////////////////////////////
//
// Prototypes
// ----------------------------------------------------------------------------
#include "config/alignment_begin.h"
POS_BEGIN
    // matrix-base, 32 + 16 (bytes)
    struct matrix_t {
	    agg_hdr_t _agg;
	    union {
		    u32_t hdr;
		    union {
			    struct {
				    u16_t type;
				    u16_t flags;
			    };
			    struct {
				    int _type_pad: 16;

				    // sparse matrix. for non-sparse matrix, always use linear storing.
				    int bSparse: 1;

				    // for var-len matrix, bIndexed means _index instead _align;
				    //	while fix-len matrix, _align is always used for index into items.
				    //	and _align is used for implementing faster matrixes, and bit-matrix.
				    int bIndexed: 1;

				    // indexed mode only, using streaming code instead of fixed index-table.
				    int bStreaming: 1;

				    int bNoDimCover: 1;

				    // Out-than-In order layout, 0:row-major 1:column-major
				    int bOIOrder: 1;
			    };
		    };
	    };

	    // may be i-o order, o-i order, sparse_layout
	    pv_t		_data;

	    union {
		    var8_t			_v8;

		    struct {
			    union {
				    // if _align == 0, unit size is calculated from PVT-type.
				    // when _align < 0, bits were used. (thus bit-matrix maybe supported).
				    i32_t	_align;

				    // fixed index-table is generally designed for big items,
				    //	because small-items shall be designed as fixed-len.
				    u32_t *	_index;

				    // small-items (sands) can be placed in noodle, or using stream index coding.
				    //	see also 'stream-index coding'.
				    pb_t	_streaming;
			    };

			    // dimensions coverage (max support 8-dims, 0 is in default dimension)
			    // for multi-dimensions, bOIOrder is considered. so the dim-index is always ordered.
			    u8_t	_dim_cover;

			    u8_t	_reserved[3];
		    };
	    };

	    inline void *_postfix() { return (pb_t)this + sizeof(*this); }
	    inline void _release(const bool _destroy_self = false);
	    inline void _free() { _release(true); }

    }; // matrix_t


    namespace matrix {
	    // --------------------------------------------------------------------------------
	    //	details of matrix types.
	    // --------------------------------------------------------------------------------
	    struct dynamic_t : public matrix_t {
		    /*
			    _pos_proc vtbl:
				    GetDimensions;
				    GetDimensionInfo;
				    GetUnit_Dims;
				    GetUnit_Index;
				    // set ...
				    Reset
		    */
	    };

	    struct vector_t : public matrix_t {
		    u32_t	m_Size;
	    };

	    struct rect_t : public matrix_t {
		    u32_t	m_Cols;
		    u32_t	m_Rows;
		    u32_t	m_Pitch;
	    };

	    struct quadx_t : public matrix_t {
		    u32_t	m_Dimensions;
		    u32_t	m_Size;
		    u32_t *	m_pPitches;
	    };

	    struct rectx_t : public matrix_t {
		    u32_t	m_Dimensions;
		    u32_t *	m_pSizes;	// always from minor to major, so A[7][8][5] will be u32_t{ 5, 8, 7 }.
		    u32_t *	m_pPitches;
	    };

	    struct mat_quad_t : public matrix_t {
		    struct {
			    // values of matrix characters is validated.
			    // the order of values is as: k_Scale, det|M|, eigen,
			    int bCharVals: 1;

			    // _data_inversed is validated
			    int bInversed: 1;

			    // --------------------------------------------------------------------------------
			    //	arithmatic matrix features.
			    // --------------------------------------------------------------------------------
			    int bSymmetry: 1;	// M==M'
			    // if both bTriUp & bTriDown, than this is a diag-matrix, form as "x--- -x-- --x- ---x"
			    int bTriUp: 1;		// up-side triangle, form as "xxxx xxx xx x"
			    int bTriDown: 1;	// down-side triangle, form as "x xx xxx xxxx"
		    };
		    u32_t	m_Size;			// size for row/column
		    u32_t	m_Pitch;		// pitch for a row
		    u32_t	m_Rank;			// rank of det|M|, when rank==size, 1/M exists.

		    // value serials, always linear-layout.
		    void *	_data_chars;
		    // inversed matrix, layout as _data.
		    void *	_data_inversed;

		    inline void _release(const bool _destroy_self = false) {
			    if (!_agg.bBind_) {
				    if (bCharVals) {
					    POS_ASSERT(_data_chars);
					    delete _data_chars;
				    }
				    if (bInversed) {
					    POS_ASSERT(_data_inversed);
					    delete _data_inversed;
				    }
			    }
			    matrix_t::_release(_destroy_self);
		    }
		    inline void _free() { _release(true); }
	    };

	    struct mat_quadx_t : public matrix_t {
		    struct {
			    int bCharVals: 1;
			    int bInversed: 1;
		    };

		    u32_t	m_Dimensions;
		    u32_t	m_Size;
		    u32_t *	m_pPitches;
		    u32_t	m_Rank;

		    void *	_data_chars;
	    };

	    // --------------------------------------------------------------------------------
	    //	implementations of sparse matrix (matrix_t::_data field)
	    // --------------------------------------------------------------------------------
	    template<typename _ty>
	    struct raw_fixed {
	    };

	    template<typename _ty>
	    struct raw_list {
	    };

	    // --------------------------------------------------------------------------------
	    //	implementations of sparse matrix (matrix_t::_data field)
	    // --------------------------------------------------------------------------------
	    struct raw_sparse_t {
		    enum sparse_type {
		    };
		    u32_t	m_Units;	// instantiated units, m_Units must <= matrix size.
		    union {
			    struct {
				    u32_t	m_Rows;
				    u32_t	m_Cols;
			    };
		    //	template<int _dims>
		    //	struct {
		    //		u32_t	m_Dims[_dims];
		    //	};
		    };
	    };
    } // namespace matrix


POS_END
#include "config/alignment_end.h"



///////////////////////////////////////////////////////////////////////////////
//
// Inline implementations & Utility functions
// ----------------------------------------------------------------------------
POS_BEGIN

    inline void matrix_t::_release(const bool _destroy_self) {
	    if (!_agg.bBind_) {
		    if (!_agg.bBindVal_) {
			    if (_data) {
				    delete _data;
			    }
		    }
	    }
	    _agg._release();
	    if (_destroy_self) delete (void *)this;
    } // matrix_t::_release

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
