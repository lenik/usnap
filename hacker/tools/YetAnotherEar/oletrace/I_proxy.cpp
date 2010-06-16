

#include "stdafx.h"
#include "oletrace.h"
#include "I_proxy.h"
#include "utils.h"

void _stdcall _vtbl_made_call(void *whichvtbl, int off) {
	whichvtbl;
	off;
	return;
}

_IMP_VTBL_JMP_STDCALL_xxx(0)
_IMP_VTBL_JMP_STDCALL_xxx(1)

#define __IMP_VTBL_JMP_STDCALL_ASSIGN_(vtbl,f,n)	\
	vtbl._entry##n = (void *)&f##n;
#define __IMP_VTBL_JMP_STDCALL_ASSIGN_x(vtbl,f,n)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_(vtbl, f, n##0)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_(vtbl, f, n##1)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_(vtbl, f, n##2)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_(vtbl, f, n##3)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_(vtbl, f, n##4)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_(vtbl, f, n##5)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_(vtbl, f, n##6)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_(vtbl, f, n##7)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_(vtbl, f, n##8)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_(vtbl, f, n##9)
#define __IMP_VTBL_JMP_STDCALL_ASSIGN_xx(vtbl,f,n)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_x(vtbl, f, n##0)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_x(vtbl, f, n##1)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_x(vtbl, f, n##2)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_x(vtbl, f, n##3)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_x(vtbl, f, n##4)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_x(vtbl, f, n##5)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_x(vtbl, f, n##6)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_x(vtbl, f, n##7)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_x(vtbl, f, n##8)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_x(vtbl, f, n##9)
#define __IMP_VTBL_JMP_STDCALL_ASSIGN_xxx(vtbl,f,n)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_xx(vtbl, f, n##0)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_xx(vtbl, f, n##1)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_xx(vtbl, f, n##2)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_xx(vtbl, f, n##3)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_xx(vtbl, f, n##4)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_xx(vtbl, f, n##5)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_xx(vtbl, f, n##6)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_xx(vtbl, f, n##7)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_xx(vtbl, f, n##8)	\
	__IMP_VTBL_JMP_STDCALL_ASSIGN_xx(vtbl, f, n##9)

_vtbl __all_jmp_to_raw;
_initialize_local {
	__all_jmp_to_raw._entry0000 = (void *)&::_vtbl_stdcall_jmp_raw_0000;
	__IMP_VTBL_JMP_STDCALL_ASSIGN_xxx(__all_jmp_to_raw,_vtbl_stdcall_jmp_raw_, 0)
	__IMP_VTBL_JMP_STDCALL_ASSIGN_xxx(__all_jmp_to_raw,_vtbl_stdcall_jmp_raw_, 1)
	__all_jmp_to_raw._raw_vtbl = NULL;
	return true;
}
_vtbl *get_blank_wrapper() {
	_vtbl *_wrapper = new _vtbl;
	memcpy(_wrapper, &__all_jmp_to_raw, sizeof(_vtbl));
	return _wrapper;
}

IUnknown *wrap_IUnknown(IUnknown *pUnk) {
	ASSERT(pUnk);
	if (!pUnk) return NULL;

//	if (wrapped(pUnk)) return pUnk;

	// graph add
	if (g_Config.fTraceIntoVtbl) {
		_vtbls *_vs = (_vtbls *)pUnk;
		_vs->_entry00;
	} else {
		_vtbls *_vs = (_vtbls *)pUnk;
		_vtbl *_new_unk_vtbl = get_blank_wrapper();
		_new_unk_vtbl->_raw_vtbl = _vs->_entry00;
		_vs->_entry00 = _new_unk_vtbl;

//		_new_unk_vtbl->_entry0000 = QI_proxy;
	}
	return pUnk;
}

IDispatch *wrap_IDispatch(IDispatch *pDisp) {
	ASSERT(pDisp);
	if (!pDisp) return NULL;

	ASSERT(pDisp);
	if (!pDisp) return NULL;

//	if (wrapped(pDisp)) return pDisp;

	// graph add
	if (g_Config.fTraceIntoVtbl) {
		_vtbls *_vs = (_vtbls *)pDisp;
		_vs->_entry00;
	} else {
		_vtbls *_vs = (_vtbls *)pDisp;
		_vtbl *_new_disp_vtbl = get_blank_wrapper();
		_new_disp_vtbl->_raw_vtbl = _vs->_entry00;
		_vs->_entry00 = _new_disp_vtbl;

//		_new_disp_vtbl->_entry0000 = QI_proxy;
//		_new_disp_vtbl->_entry0005 = Invoke_proxy;
	}
	return pDisp;
}
