
#include "stdafx.h"

#include <gcsymbol.h>

_LEX_BEGIN

void adv_symbols::cache_by_sis() {
	symbol_infos::iterator i;
	symentry entry;
	int n;

	cachemap.resize(sis.size());
	for (n = 0, i = sis.begin(); i != sis.end(); ++i, ++n) {
		entry.first	= i->thissym;
		entry.second	= 0;
		cachemap[n]	= entry;
	}
}

symbol_info *adv_symbols::getsymbol(sym _s) {
	symmap::iterator i;
	for (i = cachemap.begin(); i != cachemap.end(); ++i) {
		if (i->first == _s) {
			return i->second;
		}
	}
	return NULL;
}

_LEX_END
