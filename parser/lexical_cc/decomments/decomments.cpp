

#include "stdafx.h"

//#define USE_A_cc_FRAME

#include "a\cc.c"

void A_cc_calltype A_cc_out(state S1, state S2, character c, buffer& ab) {
	while (ab.size()) {
		character c = ab.back();
		printf("%c", c);
		ab.pop_back();
	}
	return;
}

void A_cc_calltype A_cc_clear(state S1, state S2, character c, buffer& ab) {
	ab.clear();
	return;
}

void main() {
	A_cc_main();
}
