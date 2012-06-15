
#include "stdafx.h"

#include <pos/meta.h>

namespace pos {
namespace detail {
/*
u8_t tios_tios[] = {
	ot_save_u8, otr_0, ot_fix_u8,
	ot_switch, otr_0,
	ot_case, ot_nop,	ot_cend,
	ot_case, ot_fix_u8,	ot_cend,
	ot_case, ot_fix_u16,	ot_cend,
	ot_case, ot_fix_u32,	ot_cend,
	ot_case, ot_fix_u64,	ot_cend,
	ot_case, ot_fix_u128,	ot_cend,
	ot_case, ot_fix_imm16,	ot_fix_u16, ot_cend,
	ot_case, ot_fix_rel8,	ot_cend,
	ot_case, ot_fix_rel16,	ot_cend,
	ot_case, ot_fix_rel32,	ot_cend,
	ot_case, ot_fix_rel64,	ot_cend,
	ot_case, ot_len_u8,	ot_cend,
	ot_case, ot_len_u16,	ot_cend,
	ot_case, ot_len_u32,	ot_cend,
	ot_case, ot_len_u64,	ot_cend,
	ot_case, ot_asz,	ot_cend,
	ot_case, ot_ucsz8,	ot_cend,
	ot_case, ot_ucsz16,	ot_cend,
	ot_case, ot_pvt,	ot_cend,
	ot_case, ot_body,	ot_call
	ot_ucsz8,		// 1|ot				1|UTF-8 (sz)
	ot_ucsz16,		// 1|ot				2|UTF-16 (sz)
	ot_pvt,			// 1|ot				1|PVT (var-len)
	ot_body,		// 1|ot  4|[pvt-hdr] [extype]	1|PVT::_vt (var-len)

	ot_align,		// 1|ot  1|<align>=u8
	ot_jmp,			// 1|ot  4|<r1>=u32
	ot_jmpr,		// 1|ot  4|<r1>+=i32
	ot_out_jmp,		// 1|ot  #|_form=(void*)#, <r1>=0
	ot_call,		// 1|ot  push(r1), 4|<r1>=u32
	ot_ret,			// 1|ot  pop(r1)
	ot_fork,		// 1|ot  1|<r1'>=<r1>+i8 (new flow with r1=r1')
	ot_end,			// 1|ot

	ot_info,		// 1|ot  asciz

	ot_jreg,		// 1|ot reg=u8			<r2>=reg

	ot_save_u8,		// 1|ot reg=u8			1|*reg=u8	(look-ahead)
	ot_save_u16,		// 1|ot reg=u8			2|*reg=u16	(look-ahead)
	ot_save_u32,		// 1|ot reg=u8			4|*reg=u32	(look-ahead)
	ot_save_u64,		// 1|ot reg=u8			8|*reg=u64	(look-ahead)
	ot_and,			// 1|ot reg=u8 x=<u?>	reg&x
	ot_or,	ot_xor, ot_eq, ot_lt, ot_le, ot_gt, ot_ge, ot_ne,
	ot_jz,			// 1|ot <r1>+=i8
	ot_jl,	ot_jle, ot_jg, ot_jge, ot_jnz,
	ot_dz,			// 1|ot
	ot_dl,	ot_dle, ot_dg, ot_dge, ot_dnz,
	ot_done,		// 1|ot
	ot_switch,		// 1|ot reg=u8
	ot_case,		// 1|ot v=<u?>
	ot_cend,		// 1|ot

	ot_cb,			// 1|ot  "void (_stdcall *u32)(tios *, raw *)"

};

u8_t tios_pvt[] = {
	otc_save_u32, otr_0, otc_fix_u32,
	otc_,
	otc_and, otr_0, 0, 0, 1, 0,
	otc_dnz,
*/
} // detail:

namespace ic {

	void _parse_pvt(_tios_runtime *_tr, void *_raw) {
		var_t *_v = (var_t *)_raw;
		int n = _v->_size_subtype_id();
		_tr->r2 += n;
	}

	void _read(type_layout *_layout, void *_flat, void *_target) {
		//
		u8_t *_oo = _layout->_tios;

		switch ((type_layout::tios_type)*_oo) {
		case ot_nop:		break;
		case ot_fix_u8:		break;
		case ot_fix_u16:
		case ot_fix_u32:
		case ot_fix_u64:
		case ot_fix_u128:
		case ot_fix_imm16:
		case ot_fix_rel8:
		case ot_fix_rel16:
		case ot_fix_rel32:
		case ot_fix_rel64:
		case ot_len_u8:
		case ot_len_u16:
		case ot_len_u32:
		case ot_len_u64:
		case ot_asz:
		case ot_ucsz8:
		case ot_ucsz16:
		case ot_pvt:
		case ot_body:
		case ot_ucsz8:
		case ot_ucsz16:
		case ot_pvt:
		case ot_body:
		case ot_align:
		case ot_jmp:
		case ot_jmpr:
		case ot_out_jmp:
		case ot_call:
		case ot_ret:
		case ot_fork:
		case ot_end:

	}


} // ic:
} // pos:
