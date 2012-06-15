
#include "stdafx.h"

#include <gcstack.h>

_LEX_BEGIN

lr_stack::lr_stack(adv_symbols& _syms) : _s(_syms) {
}

void lr_stack::reduce() {
	//
	syms::reverse_iterator ri;
	syms::iterator i;

	for (ri = shifts.end(); ri != shifts.begin(); ++ri) {
		i = ri;
		for (; i != shifts.end(); ++i) {
			;
		}
	}
}

_LEX_END
