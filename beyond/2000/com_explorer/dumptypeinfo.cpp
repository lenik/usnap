
#include "stdafx.h"

static char *__p_str = NULL;
static int __p_stepped = false;
void pstart(char *pstr = "[") {
	__p_str = pstr;
	__p_stepped = false;
}
void pstep(char *pstr = ",") {
	if (__p_str) printf(__p_str);
	__p_str = pstr;
	__p_stepped = true;
}
void pend(char *pstr = "]") {
	if (__p_stepped) {
		if (pstr) printf(pstr);
		__p_str = NULL;
	}
}
