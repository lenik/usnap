
//
// POS.Noodle (Version 1)
//

//
// 2003.5.15	sandbox->noodle
// 2003.5.10	started

#pragma once

// forward declarations
namespace pos {
	struct noodle_t;
	typedef noodle_t Noodle;

	enum noodle_type {
		//
		noodle_composition,

		noodle_particles,
	};
} // pos:

#include "variant.h"
#include "pointer.h"
#include "bdt.h"
#include "agg.h"
#include "error.h"


namespace pos {

	struct noodle_t {
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

				};
			};
		};
		//

	};

} // pos: