
#pragma once

#include "wmfview.h"

typedef struct _NoStr {
	DWORD	no;
	CString	str;
	DWORD	tag;
	_NoStr(DWORD o_no, CString* o_str) : no(o_no), str(*o_str) {}
	_NoStr(DWORD o_no, DWORD o_tag, CString* o_str) : no(o_no), str(*o_str), tag(o_tag) {}
} NoStr, *PNoStr;

typedef CArray<PNoStr, PNoStr> CNostrArray;

void wmfDecode(CDC *pDC, WORD fn, WORD *params, DWORD noparam);
