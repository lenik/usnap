//
// POS.Meta
//

//
// 2003.7.3	lots of change.
// 2003.5.9	fix class::const declaration
// 2003.5.7	started

#pragma once


namespace pos {
// forward declaration
#	define TYPEF_MASK			0x00010000
#	define TYPEF_EXCLUDE			0x00020000
#	define TYPEF_ORNEXT			0x00040000
#	define TYPEF_COMPLEX			0x00080000
#	define TYPEF_EXTYPE			0x00100000

	struct type_range;
	struct type_intro;
	struct type_layout;
	struct type_cast;
	struct type_filter;
} // pos:


#include <pos/config.h>
#include <pos/variant.h>
#include <pos/proc.h>


namespace pos {

struct type_range {
	union {
		u32_t hdr;
		union {
			struct {
				u16_t type;
				u16_t flags;
			};
			struct {
				int _type_pad: 16;

				// two types is equal if (type1|mask == type2|mask), mask is default 0.
				int bMask: 1;

				// all types except this type.
				int bExclude: 1;

				// this type or next type(just follow this type)
				int bOrNext: 1;

				// complex type (complex_t after type/subtype)
				int bComplex: 1;

				// value-relative type
				int bValue: 1;
			};
		};
	};
};

struct type_intro {
	union {
		u32_t hdr;
		union {
			struct {
				u16_t type;
				u16_t flags;
			};
			struct {
				/* reference:
					bVisible
					bCompatibleWithXXX
					bCreatable
					bAggragatable
					bSimple
				*/
				int bVisible: 1;
			};
		};
	};
	var_t *		pvarDefault;
	pv_t		pvEPFS;			// reserved.

	// cache for speed.
	asz_t		szName;
	struct {
		pv_t	icon;
		// :)
	} _GUI;
	type_cast *	casts;
};

struct type_layout {
	// layout form in tios.
	u8_t *	_tios;

	struct _tios_runtime {
		typedef void (_stdcall *_tios_cb)(_tios_runtime *, void *_raw);
		var12_t		r[128];
		u32_t		s[128];

		res_t&		_r;
		arith_t&	_a;
		pv_t&		_tios;
		pv_t&		_flat;
		//pv_t&
		u32_t&		r1, r2;
		u32_t *&	r1stack;
		u32_t *&	r2stack;
		u32_t&		_align;

		void reset();
		void parse(u8_t *_tios, void *_flat);
	};

	/*
		* tios(type-info ones) streaming code *
		-----------------------
		syntax:
			ALIGN(_form)| _form layout		ALIGN(_raw)| _raw layout

		status vars and initials:
			<align>			= 0 (auto alignment)
			<r1>			= 0 (_form + 0)
			<r2>			= 0 (_raw + 0)

			register[256]: var16_t (512 bytes)

		notes:
			- '#' is machine word's length, it's a DWORD in win32.
	*/
	enum tios_register {
		otr_0, otr_1, otr_2, otr_3, otr_4, otr_5, otr_6, otr_7,
		otr_8, otr_9, otr_a, otr_b, otr_c, otr_d, otr_e, otr_f,
		otr_m0, otr_m1, otr_m2, otr_m3, otr_m4, otr_m5, otr_m6, otr_m7,
		otr_result = 127,
		otr_res = 240,
		otc_arith,
		otr_tios,
		otr_r2_ptr,
		otr_r1,
		otr_r2,
		otr_r1stack,
		otc_r2stack,
		otr_align,
	};
	enum tios_type {
		ot_nop = 0,		    // 1|ot
		ot_fix_u8,		    // 1|ot				1|u8
		ot_fix_u16,		    // 1|ot				2|u16
		ot_fix_u32,		    // 1|ot				4|u32
		ot_fix_u64,		    // 1|ot				8|u64
		ot_fix_u128,		// 1|ot				16|r128
		ot_fix_imm32,		// 1|ot  N=u32			1|N{u8,...}
		ot_fix_rel8,		// 1|ot				1|i8
		ot_fix_rel16,		// 1|ot				2|i16
		ot_fix_rel32,		// 1|ot				4|i32
		ot_fix_rel64,		// 1|ot				8|i64
		ot_len_u8,		    // 1|ot				1|N=u8  1|N{u8,...}
		ot_len_u16,		    // 1|ot				2|N=u16 1|N{u8,...}
		ot_len_u32,		    // 1|ot				4|N=u32 1|N{u8,...}
		ot_len_u64,		    // 1|ot				8|N=u64 1|N{u8,...}
		ot_asz,			    // 1|ot				1|asciz
		ot_ucsz8,		    // 1|ot				1|UTF-8 (sz)
		ot_ucsz16,		    // 1|ot				2|UTF-16 (sz)
		ot_pvt,			    // 1|ot				1|PVT (var-len)
		ot_body,		    // 1|ot  4|[pvt-hdr] [extype]	1|PVT::_vt (var-len)

		ot_align,		    // 1|ot  1|<align>=u8
		ot_jmp,			    // 1|ot  4|<r1>=u32
		ot_jmpr,		    // 1|ot  4|<r1>+=i32
		ot_out_jmp,		    // 1|ot  #|_form=(void*)#, <r1>=0
		ot_call,		    // 1|ot  push(r1), 4|<r1>=u32
		ot_lib_call,		// 1|ot  4|libid=u32, _form'=lib[libid], <r1'>=0
		ot_ret,			    // 1|ot  pop(r1)
		ot_fork,		    // 1|ot  1|<r1'>=<r1>+i8 (new flow with r1=r1')
		ot_end,			    // 1|ot

		ot_info,		    // 1|ot  asciz

		ot_save_loc,		// 1|ot reg=u8
		ot_jreg,		    // 1|ot reg=u8			<r2>=reg

		ot_save_u8,		    // 1|ot reg=u8			1|*reg=u8	(look-ahead)
		ot_save_u16,		// 1|ot reg=u8			2|*reg=u16	(look-ahead)
		ot_save_u32,		// 1|ot reg=u8			4|*reg=u32	(look-ahead)
		ot_save_u64,		// 1|ot reg=u8			8|*reg=u64	(look-ahead)
		ot_mov,			    // 1|ot dst=u8 src=u8
		ot_and,			    // 1|ot reg=u8 x=<u?>	reg&x
		ot_or,	ot_xor, ot_eq, ot_lt, ot_le, ot_gt, ot_ge, ot_ne,
		ot_jz,			    // 1|ot <r1>+=i8
		ot_jl,	ot_jle, ot_jg, ot_jge, ot_jnz,
		ot_dz,			    // 1|ot
		ot_dl,	ot_dle, ot_dg, ot_dge, ot_dnz,
		ot_done,		    // 1|ot
		ot_switch,		    // 1|ot reg=u8
		ot_case,		    // 1|ot v=<u?>
		ot_case_else,		// 1|ot
		ot_cend,		    // 1|ot
		ot_send,		    // 1|ot

		ot_cb,			    // 1|ot  "void (_stdcall *u32)(tios *, raw *)"
	};

};


struct type_cast {
	union {
		u32_t hdr;
		struct {
			// forward cast is cast 'this' type to other, or else are reversed. (cast other type to 'this')
			int bForward: 1;

			int bInPlace: 1;

			int b;
		};
	};
	proc_t	proc_cast;
};

} // pos: