
#pragma once

struct api_record {
	LPTSTR	name;
	LPVOID	addr;
};

BOOL	CallApi(pa, param pt[], return_record *r) {


	for (pt.length) {
		_asm push pt[i].val;
	}
	_asm call pa;
	if (proto == CALLPROTO_CDECL) {
		_asm call _chkesp;
	}
	if (proto == CALLPROTO_CDECL) {
		_asm add esp, length << 2;
	}

}
