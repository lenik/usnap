
#ifndef __TKCOMP_H
#define __TKCOMP_H

#include <stdio.h>

struct CResult {
// engChr, engSym, chnChr * 2, chnSym * 2, other, space, total
	unsigned rec, res, rcc, rcs, rot, rsp, rtot; /* right */
	unsigned wec, wes, wcc, wcs, wot, wsp, wtot; /* wrong */
	unsigned eec, ees, ecc, ecs, eot, esp, etot; /* extra */
	unsigned lec, les, lcc, lcs, lot, lsp, ltot; /* lost  */
};

struct CInfo {
// engChr, engSym, chnChr * 2, chnSym * 2, space, other, total */
	unsigned nec, nes, ncc, ncs, nsp, not, ntot;
};

int compfile(FILE *tmpl, FILE *each, CResult &r, CInfo &itmpl, CInfo &ieach);

#endif
