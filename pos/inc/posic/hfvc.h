//
// POS in C/C++
//	HFVC template
//

//
// yy.mm.dd	...
// yy.mm.dd	history 2
// 2003.5.30	start

#pragma once


// forward declaration
namespace pos {
namespace posic {
namespace hfvc {
	//struct HFVC;
	// ...

	enum HFVC_type {
		HFVC_D1		= 0,
		HFVC_D2,
		HFVC_D4,
		HFVC_D5,
	};

}}} // ns pos.posic.hfvc

#include <pos/config.h>
// #include ...

namespace pos {

#	pragma pack(push, 4)

	template<int
	struct params {
	};

	template<HFVC_type hfvc_type, params_list_type>
	struct HFVC {
	}


#	pragma pack(pop)

	// additional implementation...

}}} // ns pos.posic.hfvc