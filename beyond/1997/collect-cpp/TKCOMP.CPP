
#include "tkcomp.h"
#include <scomp.h>

#include <stdlib.h>

/*
 * in:
 *	ft: 	file as template
 *	fc: 	file to be compared
 * out:
 *	r:	compare result
 *	it: 	info of ft
 *	ic: 	info of fc
 */

#define DEPTH		32
#define SAMESIZE	5

#define BUFSIZE		5000
#define CRSIZE		10

#define COMP_SUCCESS	0
#define COMP_ERROR	1

char *tbuf, *cbuf;
size_t *cr;

typedef struct _doublechar {
	char c1;
	char c2;
} doublechar;

int operator == (_doublechar &a, _doublechar &b) { return a.c1 == b.c1 && a.c2 == b.c2; }
int operator != (_doublechar &a, _doublechar &b) { return a.c1 != b.c1 || a.c2 != b.c2; }

int compfile_ises(int c) {
	return
		(c >= 33 && c <= 47) ||
		(c >= 58 && c <= 64) ||
		(c >= 91 && c <= 96) ||
		(c >= 123 && c <= 126);
}

int compfile_isec(int c) {
	return
		(c >= 48 && c <= 57) ||
		(c >= 65 && c <= 90) ||
		(c >= 97 && c <= 122);
}

int compfile_issp(int c) {
	return c == ' ' || c == '\t';
}

int compfile_isc(int c1, int c2) {
	c1 -= 160;
	if (c2 >= 128 && c2 <= 254) {
		if (c1 >= 0 && c1 <= 15)
			return 's';	// chinese symbol
		if (c1 >= 16)
			return 'c';	// chinese char
	}
	return 0;
}

int compfile_iscs(int c1, int c2) {
	return compfile_isc(c1, c2) == 's';
}

int compfile_iscc(int c1, int c2) {
	return compfile_isc(c1, c2) == 'c';
}

int compfile_isot(int c1, int c2) {
	if (compfile_ises(c2)) return 0;
	if (compfile_isec(c2)) return 0;
	if (compfile_issp(c2)) return 0;
	if (compfile_iscs(c1, c2)) return 0;
	if (compfile_iscc(c1, c2)) return 0;
	return 1;
}

int compfile(FILE *ft, FILE *fc, CResult &r, CInfo &it, CInfo &ic) {
	int c, c1;
	size_t p = 0;
	size_t used_size = CRSIZE;

	tbuf = (char *)malloc(BUFSIZE);
	cbuf = (char *)malloc(BUFSIZE);
	cr = (size_t *)malloc(sizeof(size_t) * CRSIZE);
	if (cr == NULL) return COMP_ERROR;

#define comppart(PN)							\
		fseek(ft, 0, SEEK_SET);					\
		fseek(fc, 0, SEEK_SET);                                 \
		p = 0;                                                  \
		while (!feof(ft)) {                                     \
			if ((c = fgetc(ft)) == EOF) break;              \
			if (compfile_is##PN(c)) tbuf[p++] = c;		\
		}                                                       \
		it.n##PN = p;                                       	\
		p = 0;                                                  \
		while (!feof(fc)) {                                     \
			if ((c = fgetc(fc)) == EOF) break;              \
			if (compfile_is##PN(c)) cbuf[p++] = c;		\
		}                                                       \
		ic.n##PN = p;                                           \
									\
		used_size = CRSIZE; 					\
		stream_comp(tbuf, cbuf, it.n##PN, ic.n##PN,		\
			    (size_t)DEPTH, (size_t)SAMESIZE,		\
			    cr, &used_size);             		\
									\
		r.r##PN = cr[0];                                        \
		r.w##PN = cr[1];                                        \
		r.e##PN = cr[2];                                        \
		r.l##PN = cr[3];

#define comppart2(PN)							\
		fseek(ft, 0, SEEK_SET);					\
		fseek(fc, 0, SEEK_SET);                                 \
		p = 0;                                                  \
		c1 = 0;                                                 \
		while (!feof(ft)) {                                     \
			if ((c = fgetc(ft)) == EOF) break;              \
			if (compfile_is##PN(c1, c)) {                   \
				tbuf[p++] = c1;                         \
				tbuf[p++] = c;                          \
				c = 0;                                  \
			}                                               \
			c1 = c;                                         \
		}                                                       \
		it.n##PN = p;                                       	\
		p = 0;                                                  \
		c1 = 0;                                                 \
		while (!feof(fc)) {                                     \
			if ((c = fgetc(fc)) == EOF) break;              \
			if (compfile_is##PN(c1, c)) {                   \
				cbuf[p++] = c1;                         \
				cbuf[p++] = c;                          \
				c = 0;                                  \
			}                                               \
			c1 = c;                                    	\
		}                                                       \
		ic.n##PN = p;                                       	\
									\
		used_size = CRSIZE; 					\
		stream_comp((doublechar *)tbuf, (doublechar *)cbuf,     \
			    it.n##PN, ic.n##PN,                         \
			    (size_t)DEPTH, (size_t)SAMESIZE,            \
			    cr, &used_size);                            \
									\
		r.r##PN = cr[0] * 2;                                    \
		r.w##PN = cr[1] * 2;                                    \
		r.e##PN = cr[2] * 2;                                    \
		r.l##PN = cr[3] * 2;

	comppart(es);
	comppart(ec);
	comppart(sp);

	comppart2(cs);
	comppart2(cc);

	// comppart??(ot)
		fseek(ft, 0, SEEK_SET);
		fseek(fc, 0, SEEK_SET);
		p = 0;
		c1 = 0;
		while (!feof(ft)) {
			if ((c = fgetc(ft)) == EOF) break;
			if (compfile_isot(c1, c)) {
				tbuf[p++] = c1;
				c = 0;
			}
			c1 = c;
		}
		if (compfile_isot(0, c)) tbuf[p++] = c;
		it.not = p;
		p = 0;
		c1 = 0;
		while (!feof(fc)) {
			if ((c = fgetc(fc)) == EOF) break;
			if (compfile_isot(c1, c)) {
				cbuf[p++] = c1;
				c = 0;
			}
			c1 = c;
		}
		if (compfile_isot(0, c)) tbuf[p++] = c;
		ic.not = p;

		used_size = CRSIZE;
		stream_comp(tbuf, cbuf, it.not, ic.not,
			    (size_t)DEPTH, (size_t)SAMESIZE,
			    cr, &used_size);

		r.rot = cr[0];
		r.wot = cr[1];
		r.eot = cr[2];
		r.lot = cr[3];

	free(tbuf);
	free(cbuf);
	free(cr);

	r.rtot = r.rec + r.res + r.rcc + r.rcs + r.rot + r.rsp;
	r.wtot = r.wec + r.wes + r.wcc + r.wcs + r.wot + r.wsp;
	r.etot = r.eec + r.ees + r.ecc + r.ecs + r.eot + r.esp;
	r.ltot = r.lec + r.les + r.lcc + r.lcs + r.lot + r.lsp;

	it.ntot = it.nec + it.nes + it.ncc + it.ncs + it.not + it.nsp;
	ic.ntot = ic.nec + ic.nes + ic.ncc + ic.ncs + ic.not + ic.nsp;

	return 0;
}
