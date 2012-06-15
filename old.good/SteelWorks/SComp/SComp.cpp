// SComp.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include <_scomp.h>
#include "scomp.h"

int	_stdcall stream_comp_byte(LPBYTE ref, LPBYTE obj, size_t size_ref, size_t size_obj, size_t search_depth, size_t same_size, size_t *cr, size_t *psize_cr) {
	return stream_comp<LPBYTE, LPBYTE, BYTE, BYTE>
		(ref, obj, size_ref, size_obj, search_depth, same_size, cr, psize_cr);
}

int	_stdcall stream_comp_word(LPWORD ref, LPWORD obj, size_t size_ref, size_t size_obj, size_t search_depth, size_t same_size, size_t *cr, size_t *psize_cr) {
	return stream_comp<LPWORD, LPWORD, WORD, WORD>
		(ref, obj, size_ref, size_obj, search_depth, same_size, cr, psize_cr);
}

int	_stdcall stream_comp_dword(LPDWORD ref, LPDWORD obj, size_t size_ref, size_t size_obj, size_t search_depth, size_t same_size, size_t *cr, size_t *psize_cr) {
	return stream_comp<LPDWORD, LPDWORD, DWORD, DWORD>
		(ref, obj, size_ref, size_obj, search_depth, same_size, cr, psize_cr);
}

int	_stdcall stream_comp_mbcs(LPBYTE ref, LPBYTE obj, size_t size_ref, size_t size_obj, size_t search_depth, size_t same_size, size_t *cr, size_t *psize_cr) {
	MBCS	_ref(ref);
	MBCS	_obj(obj);
	return stream_comp<MBCS, MBCS, LONG, LONG>
		(_ref, _obj, size_ref, size_obj, search_depth, same_size, cr, psize_cr);
}

int	_stdcall stream_comp_mbcs_fast(LPBYTE ref, LPBYTE obj, size_t size_ref, size_t size_obj, size_t search_depth, size_t same_size, size_t *cr, size_t *psize_cr) {
	LPWORD	_ref;
	LPWORD	_obj;
	if (_ref = new WORD[size_ref]) {
		if (_obj = new WORD[size_obj]) {
			int	r;
			mbcstoword(_ref, ref, size_ref, size_ref * 2);
			mbcstoword(_obj, obj, size_obj, size_obj * 2);
			r = stream_comp<LPWORD, LPWORD, WORD, WORD>
				(_ref, _obj, size_ref, size_obj, search_depth, same_size, cr, psize_cr);
			delete[] _ref;
			delete[] _obj;
			return r;
		}
	}

	return STREAM_COMP_ERROR;
}

int	_stdcall stream_comp_pretty_result_a(size_t *cr, size_t size_cr, size_t crmask, char *rbuf, size_t *psize_rbuf, char *obuf, size_t *psize_obuf) {
	return stream_comp_pretty_result<char *>(cr, size_cr, crmask, rbuf, psize_rbuf, obuf, psize_obuf);
}

int	_stdcall stream_comp_pretty_result_w(size_t *cr, size_t size_cr, size_t crmask, short *rbuf, size_t *psize_rbuf, short *obuf, size_t *psize_obuf) {
	return stream_comp_pretty_result<short *>(cr, size_cr, crmask, rbuf, psize_rbuf, obuf, psize_obuf);
}

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}
