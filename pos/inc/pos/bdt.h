//
// POS Basic Data Type (POS 1.0)
//

//
// 2003.6.24	restart

#pragma once


namespace pos {
namespace bdt {
	// forward declaration
}} // pos:bdt:


#include <pos/config.h>
#include <pos/variant.h>


namespace pos {
namespace bdt {
#pragma pack(push, 4)

	// light-weight aggregates for internal/efficiency usage.
	template<typename _ty>
	struct list_t {
		typedef _ty value_type;
		list_t *l;	// ->next
		list_t *_l;	// ->prev
		_ty data;
	};

#pragma pack(pop)

}} // pos:bdt: