
//
// POS.Unit (Version 1)
//

//
// 2003-7-3	* unit system
// 2003-5-9	start

#pragma once

// forward declare
namespace pos {
	struct unit_t;

	enum unit_type {
		unit_number = 0,	// no unit.
		unit_com_multi,		// (unit * unit) * ...
		unit_com_div,		// (unit / unit) / ...
		unit_com_pow,		// (unit ^ unit) ^ ...
		unit_com_log,		// log (log unit,unit),unit ...
		unit_length = 100,
		unit_weight,
		unit_time,
		unit_currency,
	};

	namespace unit {
		enum length_system {
			length_meter,
			length_lightyear,
			length_
		};
		enum time_system {
			time_second,
			time_Rai_halfduration,
			time_cpu_cycle,
		};
		enum weight_system {
			weight_gram,
			weight_atom,
			weight_
		};
		enum currency_system {
			cy_ci,
			cy_dollar,
			cy_rmb,
			cy_hkd,
		};
	}
}

#include <pos/config.h>
#include <pos/variant.h>
#include <pos/pointer.h>


namespace pos {

#pragma pack(push, 4)
// flags;type |
struct unit_t {
	union {
		u32_t hdr;
		union {
			struct {
				u16_t type;
				u16_t flags;
			};
			struct {
				int _type_pad: 16;

				int _res: 8;

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

	var12_t		_scale;		// 1000 for "km,kg,kJ,kHz" and 1024 for "kb,.." etc.

	union {
		var8_t	_system;	// time-locale, currency-region, etc.
		struct {
			unit_t *	_units;
			u32_t		num;
		};
	};

	inline void _release(bool _destroy_self = false) {
		if (!bBind_) {
			_scale._release();
			_system._release();
		}
		if (_destroy_self) delete this;
	}
	inline void _free() { _release(true); }
};

#pragma pack(pop)

} // namespace pos