//
// POS.AIM (POS 1.0)
//	AIM - Artificial Intelligence Memory
//


//
// 2003.5.14	change _pos_buffer to buffer_t
// 2003.4.17	started

#pragma once

// forward declarations
namespace pos {
	struct buffer_t;
	typedef buffer_t Buffer;

	enum buffer_type {
		buffer_linear,
		buffer_page,
		buffer_particle,
		buffer_fat,
		buffer_btree,
		buffer_composition,
		buffer_link,
		buffer_levelized_block,
	};
}

#include <pos/config.h>
#include <pos/variant.h>
#include <pos/pointer.h>
#include <pos/bdt.h>


namespace pos {

#pragma pack(push, 4)

	struct buffer_t {
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
	};

	// _pos_allocator
	//

	// (C)optreq to AIM.
	struct _pos__C_optimize_requirement {
		//
	};

	namespace buffer {
		// sand&particle buffer
		struct sp_t {
			int unit_bytes;
			// factor = 8u, for "DWORD" factor = 32, then 32k/1M, for "16byte" factor = 128, 8k/1M
		};
	} // namespace buffer

#pragma pack(pop)

} // namespace pos
