
#include <gcsymbol.h>

_LEX_BEGIN

class lr_stack {
public:
	syms shifts;
	syms inputs;
public:
	void reduce();
public:
	lr_stack(adv_symbols& _syms);
private:
	adv_symbols& _s;
};


_LEX_END
