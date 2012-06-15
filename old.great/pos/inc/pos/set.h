
//
// POS.Set (Version 1)
//

//
// 2003.5.10	started

#pragma once

// forward declarations
namespace pos {
	struct set_t;
	typedef set_t Set;

	enum set_type {
		set_empty,
		set_full,
		set_composition,
		set_points,
		set_range,
		set_shape,
		set_formula,
		set_topology,
	};
} // pos:

#include <pos/config.h>
#include <pos/variant.h>
#include <pos/pointer.h>
#include <pos/agg.h>


namespace pos {

#	pragma pack(push, 4)

	struct set_t : public agg_hdr_t {
		union {
			u32_t hdr;
			union {
				struct {
					u16_t type;
					u16_t flags;
				};
				struct {
					int _type_pad: 16;

					// fuzzy-set
					int bFuzzy;

					// repeatable set
					int bRepeat;

				};
			};
		};

		domain_t *	m_pDomain;
		//_pos_
	};

#	pragma pack(pop)

} // pos: