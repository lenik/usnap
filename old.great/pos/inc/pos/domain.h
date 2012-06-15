
//
// POS.Domain (Version 1)
//

// 2003-5-9	start

#pragma once

// forward declare
namespace pos {
	struct domain_t;

	enum domain_type {
		domain_none = 0,		// all probable value for data-type. (so BYTE is 00-FF)
		domain_si_msb,			// as the signed integer (sign at MSB)
		domain_ui,			// as the unsigned integer, 2e+bits
		domain_bcd,			// 10e+bits/4
		domain_ieee754,			// IEEE Standard 754 for Binary Floating-Point Arithmetic
		//domain_set,			// index into set
	};
} // pos:

#include <pos/config.h>
#include <pos/variant.h>
#include <pos/pointer.h>


namespace pos {

#pragma pack(push, 4)
// flags;type |
struct domain_t {
	union {
		u32_t hdr;
		union {
			struct {
				u16_t type;
				u16_t flags;
			};
			struct {
				int _type_pad: 16;

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

				// extend auto management bit.
				int bBindX_: 1;

				// apply auto management to object.
				int bBind_: 1;

				// more data after flags
				int bExtend: 1;
			};
		};
	};

	var_t *	_domains;

	inline void _release(bool _destroy_self = false) {
		if (!bBind_) {
		}
		if (_destroy_self) delete this;
	}
	inline void _free() { _release(true); }
};

#pragma pack(pop)

} // pos: