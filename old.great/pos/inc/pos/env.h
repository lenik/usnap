
//
// POS.Env (Version 1)
//	system environment variables.
//

//
// 2003.5.10	started

#pragma once

// forward declarations
namespace pos {
	struct environment_t;
}

#include <pos/config.h>
#include <pos/variant.h>
#include <pos/pointer.h>
#include <pos/bdt.h>


namespace pos {

	struct environment_t {
		// enviornment bits
		struct {
			int bSpeedOpt;

			int bLog;

			// current is idle
			int bIdle;
		};

		int structure_pack_align;

	};

} // namespace pos