//
// POS.LaS	(POS Version 1, LaS Version 1)
//

//
// 2003-7-3	start

#pragma once


#define _NS_BEGIN		namespace pos { namespace las {
#define _NS_END			}}

// forward declaration
_NS_BEGIN
struct typename_t;

enum layer_type {
	layer_cdp,		// component description properties
	layer_exports,
	layer_imports,
	layer_pos,
	layer_scp,		// structural controlable process
	layer_debug,
	layer_security,
	layer_help,
	layer_data,
	layer_pcs,		// primary code sequence
	layer_tips,		// small helps in UI
};


_NS_END

#include <pos/config.h>
#include <pos/variant.h>

_NS_BEGIN

#pragma pack(push, 4)

//	struct ...

#pragma pack(pop)

_NS_END

struct object {
	struct {
	};
	epfs *root;
	var_t *value;
	u32_t _res;
};

enum vm_type {
	vm_message,
	vm_graph,
};

struct vm : public object {
	struct {
		u16_t type;
		union {
			u16_t flags;

			struct {
				// use common instruction framework
				int bCIF: 1;
			};
		};
	};
};

struct plug_in : public object {
	void *	pMainProc;
	void *	pConfiguration;
	void *	pMessageProc;
};
