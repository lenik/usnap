
//
// POS full-featured Type
//

//
// 2003-5-13	add _pos_release
// 2003-5-9	start

#pragma once

// forward declare
namespace pos {
	struct type_t;

	struct var_t;
	inline size_t _pos_size_cid(cid_t *_cid);
	inline size_t _pos_sizeof(int type, void *pv, void *_subtype = NULL, u32_t _flags = 0/*not used*/);
	inline bool _pos_release(var_t *pvt_ref, void *data);
}


#include <pos/config.h>
#include <pos/variant.h>
#include <pos/pointer.h>
#include <pos/meta.h>
#include <tchar.h>

//
namespace pos {

#pragma pack(push, 4)
// flags;type |
struct type_t {
	union {
		u32_t hdr;
		union {
			struct {
				u16_t type;
				u16_t flags;
			};
			struct {
				int _type_pad: 16;
			};
		};
	};

	var_t *	_types;

	inline void _release(bool _destroy_self = false) {
	}
	inline void _free() { _release(true); }
};

// flags:
struct _pos_sizeof_flags {
	// not sizeof(entire-data), sub-data instead.
	// when the data is a simple link, bSubData may de-link that (like de-pointer, de-chain, etc.)
	int bSubData: 1;
};
#pragma pack(pop)


inline size_t _pos_size_cid(cid_t *_cid) {
	POS_ASSERT(_cid);
	// CID: 10987654321098765432109876543210 (size-1) u32_t's
	//	[-size-]
	// -or- FFxxxxxx FFxxxxxx .... (not FF)xxxxxx

	// unit:  (xxxx .... 28-bit ....) xxxx's u32_t
	//
	u32_t *pd = (u32_t *)_cid;
	size_t _x = 1, _l;
	while (_l = *pd >> 28) {
		_x += _l;
		pd += _l;
	}
	return _x << 2;
}

inline size_t _pos_sizeof(int type, void *pv, void *_subtype, u32_t _flags) {
	size_t i;

	switch (type) {
	case pvt_void:		return 0;
	case pvt_u8:
	case pvt_i8:
	case pvt_bcd8:
	case pvt_b8:
	case pvt_rel8:		return 1;
	case pvt_u16:
	case pvt_i16:
	case pvt_bcd16:
	case pvt_b16:
	case pvt_r16:
	case pvt_rel16:		return 2;
	case pvt_c16:
	case pvt_u32:
	case pvt_i32:
	case pvt_bcd32:
	case pvt_b32:
	case pvt_r32:
	case pvt_rel32:		return 4;
	case pvt_c32:
	case pvt_u64:
	case pvt_i64:
	case pvt_bcd64:
	case pvt_b64:
	case pvt_r64:
	case pvt_rel64:		return 8;
	case pvt_c64:
	case pvt_r128:		return 16;
	case pvt_c128:		return 32;
	case pvt_pv:		return sizeof(void *);
	case pvt_pointer:	{
					pointer_t *_p = (pointer_t *)pv;
					POS_ASSERT(_p);
					i = 2;	// hdr | pv/pcomplex
					if (_p->bValue) i++;
					if (_p->bCache) i++;
					//if (_p->b64Bit) i += i;
					return i * 4;
				}
	case pvt_fourcc32:	return 4;
	case pvt_posid96:	return 3;
	case pvt_guid128:
	case pvt_corbaid128:	return 16;
	case pvt_cid:		return _pos_size_cid((cid_t *)pv);
	case pvt_epfs:
	case pvt_struct8:
	case pvt_struct16:
	case pvt_struct32:
	case pvt_struct64:
	case pvt_struct128:
	case pvt_struct256:
	case pvt_hfvc_d8:
	case pvt_hfvc_d4:
	case pvt_hfvc_d16:
	case pvt_hfvc_d5:
	case pvt_lasar:		return sizeof(_unknown_t);
	case pvt_pvt:		{
					var_t *_p = (var_t *)pv;
					POS_ASSERT(_p);
					return _pos_sizeof(_p->type, _p->_body(), _p->_sub(), _flags);
				}
	case pvt__com_variant:	return sizeof(VARIANT);
	case pvt__com_array:	return sizeof(SAFEARRAY);
	case pvt__com_dec96:	return sizeof(DECIMAL);
	case pvt__com_scode:	return sizeof(SCODE);
	case pvt__com_cy64:	return sizeof(CY);
	case pvt__com_date:	return sizeof(DATE);
	case pvt__com_iunk:
	case pvt__com_idisp:	return sizeof(void *);
	case pvt_mpint:
	case pvt_mpreal:
	case pvt_asz:
	case pvt_ucsz16:
	case pvt_ucsz8:
	case pvt_bstr:		return sizeof(void *);
	case pvt_asz_pad:	return 1 + strlen((asz_t)pv);		// 1: '\0'
	case pvt_ucsz16_pad:	return 2 + wcslen((ucsz16_t)pv);	// 2: L'\0'
	case pvt_ucsz8_pad:	return 1 + _mbslen((ucsz8_t)pv);	// 1: UTF-8 '\0'

	//	pvt_pvt_2, 	pvt_pvt_3,	pvt_pvt_4,	pvt_pvt_22, 	pvt_pvt_33,	pvt_pvt_44,

	case pvt_u8_2:  case pvt_u8_3:  case pvt_u8_4:  case pvt_u8_22:  case pvt_u8_33:  case pvt_u8_44:
	case pvt_u16_2: case pvt_u16_3: case pvt_u16_4: case pvt_u16_22: case pvt_u16_33: case pvt_u16_44:
	case pvt_u32_2: case pvt_u32_3: case pvt_u32_4: case pvt_u32_22: case pvt_u32_33: case pvt_u32_44:
	case pvt_u64_2: case pvt_u64_3: case pvt_u64_4: case pvt_u64_22: case pvt_u64_33: case pvt_u64_44:
	case pvt_i8_2:  case pvt_i8_3:  case pvt_i8_4:  case pvt_i8_22:  case pvt_i8_33:  case pvt_i8_44:
	case pvt_i16_2: case pvt_i16_3: case pvt_i16_4: case pvt_i16_22: case pvt_i16_33: case pvt_i16_44:
	case pvt_i32_2: case pvt_i32_3: case pvt_i32_4: case pvt_i32_22: case pvt_i32_33: case pvt_i32_44:
	case pvt_i64_2: case pvt_i64_3: case pvt_i64_4: case pvt_i64_22: case pvt_i64_33: case pvt_i64_44:
	case pvt_r128_2:case pvt_r128_3:case pvt_r128_4:case pvt_r128_22:case pvt_r128_33:case pvt_r128_44:
	case pvt_r16_2: case pvt_r16_3: case pvt_r16_4: case pvt_r16_22: case pvt_r16_33: case pvt_r16_44:
	case pvt_r32_2: case pvt_r32_3: case pvt_r32_4: case pvt_r32_22: case pvt_r32_33: case pvt_r32_44:
	case pvt_r64_2: case pvt_r64_3: case pvt_r64_4: case pvt_r64_22: case pvt_r64_33: case pvt_r64_44:
	case pvt_c128_2:case pvt_c128_3:case pvt_c128_4:case pvt_c128_22:case pvt_c128_33:case pvt_c128_44:
	case pvt_c16_2: case pvt_c16_3: case pvt_c16_4: case pvt_c16_22: case pvt_c16_33: case pvt_c16_44:
	case pvt_c32_2: case pvt_c32_3: case pvt_c32_4: case pvt_c32_22: case pvt_c32_33: case pvt_c32_44:
	case pvt_c64_2: case pvt_c64_3: case pvt_c64_4: case pvt_c64_22: case pvt_c64_33: case pvt_c64_44:
		{
			static size_t _sizes[] = {
				2,	3,	4,	4,	9,	16,	// u8
				4,	6,	8,	8,	18,	32,	// u16
				8,	12,	16,	16,	36,	64,	// u32
				16,	24,	32,	32,	72,	128,	// u64
				2,	3,	4,	4,	9,	16,	// i8
				4,	6,	8,	8,	18,	32,	// i16
				8,	12,	16,	16,	36,	64,	// i32
				16,	24,	32,	32,	72,	128,	// i64
				32,	48,	64,	64,	144,	256,	// r128
				4,	6,	8,	8,	18,	32,	// r16
				8,	12,	16,	16,	36,	64,	// r32
				16,	24,	32,	32,	72,	128,	// r64
				64,	96,	128,	128,	288,	512,	// c128
				8,	12,	16,	16,	36,	64,	// c16
				16,	24,	32,	32,	72,	128,	// c32
				32,	48,	64,	64,	144,	256,	// c64
			};
			return _sizes[type - 0x80];
		}
	default:
		break;
	}

	POS_ASSERT(false);
	return 0;
}

inline bool _pos_release(var_t *pvt_ref, void *data) {
	POS_ASSERT(pvt_ref && data);
	bool ok = true;
	switch (pvt_ref->type) {
	case pvt_asz:
	case pvt_ucsz16:
	case pvt_ucsz8:
	case pvt_pv:
	//case pvt_unknown:
	case pvt_lasar:
	case pvt_epfs:
		free(*(void **)data);
		break;
	case pvt_pointer:
		{
			pointer_t *p = (pointer_t *)data;
			p->_release();
		}
		break;
	case pvt_pvt:
		{
			var_t *p = (var_t *)data;
			p->_release();
		}
		break;
	case pvt__com_iunk:
	case pvt__com_idisp:
		{
			IUnknown *punk = *(IUnknown **)data;
			punk->Release();
		}
		break;
	case pvt__com_variant:
		{
			VARIANT *pv = (VARIANT *)data;
			ok = SUCCEEDED(VariantClear(pv));
		}
		break;
	case pvt_bstr:
		{
			// [DWORD size]"content...\0"
			BSTR bstr = (BSTR)((pb_t)data + 4);
			SysFreeString(bstr);
		}
		break;
	default:
		return false;
	}
	return ok;
}


} // namespace pos