
//
// POS.Hash (Version 1)
//

//
// 2003.5.15	add bBinTree/bRepeat
// 2003.5.10	started

#pragma once

// forward declarations
namespace pos {
	struct hash_t;
	typedef hash_t Hash;

	//enum hash_storage_type {
	//};
}

#include <pos/config.h>
#include <pos/variant.h>
#include <pos/pointer.h>
#include <pos/bdt.h>


namespace pos {

	struct hash_t {
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

					// binary-tree used for search key.
					int bBinTree: 1;

					// key may be repeated. usually a key maybe corresponding to many values.
					int bRepeat: 1;

					// whether sub-hash is allowed.
					int bLayered: 1;
				};
			};
		};

		void *btree;

		// storage form:
		//	list
		//	array
		//	tree (balanced, then (void *btree) can be deleted.
	}; // hash_t

} // namespace pos