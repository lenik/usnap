// EMemory.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "EMemory.h"

static BOOL	bGlobalFunc;
static ULONG	uFlags;

BOOL	_stdcall EMemory_funcswitch(BOOL bAsGlobal) {
	BOOL	last = bGlobalFunc;
	bGlobalFunc = bAsGlobal;
	return last;
}

ULONG	_stdcall EMemory_setflags(ULONG newflags) {
	ULONG	last = uFlags;
	uFlags = newflags;
	return last;
}

BOOL	_stdcall EMemory_resetvar() {
	bGlobalFunc = FALSE;
	uFlags = LMEM_MOVEABLE;
	return TRUE;
}

// !!! be careful not to make delta = 0 !!!
// 获得对齐到delta的长度
LONG	_stdcall EBuffer_alignsize(LONG size, LONG delta) {
	return (LONG)(size / delta + 1) * delta;
}

LPVOID	_stdcall AllocMemory(DWORD size, LPDWORD saveHandle) {
	DWORD	h;
	LPVOID	p;

	if (bGlobalFunc) {
		h = (DWORD)GlobalAlloc(uFlags, size);
	} else {
		h = (DWORD)LocalAlloc(uFlags, size);
	}

	if (h != 0) {
		p = bGlobalFunc ? GlobalLock((HGLOBAL)h) : LocalLock((HLOCAL)h);
		if (p != NULL) {
			*saveHandle = h;
			return p;
		} else {
			FreeMemory(&h);
			*saveHandle = 0;
			return NULL;
		}
	}
	return NULL;
}

LPVOID	_stdcall ReallocMemory(DWORD NewSize, LPDWORD saveHandle) {
	DWORD	h = *saveHandle;
	LPVOID	p;

	if (h == 0) return AllocMemory(NewSize, saveHandle);

	if (bGlobalFunc) {
		GlobalUnlock((HGLOBAL)h);
		h = (DWORD)GlobalReAlloc((HGLOBAL)h, NewSize, uFlags);
	} else {
		LocalUnlock((HLOCAL)h);
		h = (DWORD)LocalReAlloc((HLOCAL)h, NewSize, uFlags);
	}

	if (h != 0) *saveHandle = h;

	h = *saveHandle;

	p = bGlobalFunc ? GlobalLock((HGLOBAL)h) : LocalLock((HLOCAL)h);
	if (p != NULL) return p;

	// Failure !
	FreeMemory(&h);
	*saveHandle = 0;
	return NULL;
}

BOOL	_stdcall FreeMemory(LPDWORD saveHandle) {
	DWORD	h = *saveHandle;

	if (bGlobalFunc) {
		if (GlobalFree((HGLOBAL)h)) *saveHandle = 0;
	} else {
		if (LocalFree((HLOCAL)h)) *saveHandle = 0;
	}
	return TRUE;
}

// 设置单元数目
//	若 lpb 尚未分配空间则分配空间
//	若 已分配单元数 < 新单元数则重新分配空间
//	一次分配空间以deltanum*unitsize为单位, 已使用空间一般 < 已分配空间
BOOL	_stdcall EBuffer_setsize(LPBUFFERTYPE lpb, LONG newsize) {
	if (lpb->deltanum < 1) lpb->deltanum	= 1;
	if (lpb->unitsize < 1) lpb->unitsize	= 0x1000;

	LONG	alloc_newsize = EBuffer_alignsize(newsize, lpb->deltanum);
	LPVOID	newdata;

	if (lpb->_data == NULL) {
		lpb->_data = AllocMemory(lpb->unitsize * alloc_newsize, &lpb->handle);
		if (lpb->_data != NULL) {
			lpb->allocnum = alloc_newsize;
			lpb->usednum = newsize;
			return TRUE;
		}
		return FALSE;
	}

	if (newsize <= lpb->allocnum) {
		lpb->usednum	= newsize;
		return TRUE;
	}

	newdata = ReallocMemory(lpb->unitsize * alloc_newsize, &lpb->handle);
	if (newdata != NULL) {
		lpb->_data = newdata;
		lpb->allocnum = alloc_newsize;
		lpb->usednum = newsize;
		return TRUE;
	}
	return FALSE;
}

BOOL	_stdcall EBuffer_clear(LPBUFFERTYPE lpb) {
	if (lpb->_data == NULL) return TRUE;
	if (FreeMemory(&lpb->handle)) {
		lpb->allocnum	= 0;
		lpb->usednum	= 0;
		lpb->_data	= NULL;
		return TRUE;
	}
	return FALSE;
}

// 压缩空间, 使已分配空间==已使用空间
BOOL	_stdcall EBuffer_compress(LPBUFFERTYPE lpb) {
	LPVOID	newdata;

	if (lpb->_data == NULL) {
		lpb->allocnum	= 0;
		lpb->usednum	= 0;
		return TRUE;
	}

	newdata	= ReallocMemory(lpb->usednum * lpb->unitsize, &lpb->handle);
	if (newdata != NULL) {
		lpb->_data	= newdata;
		lpb->allocnum	= lpb->usednum;
		return TRUE;
	}
	return FALSE;
}

BOOL	_stdcall EBuffer_setelement(LPBUFFERTYPE lpb, LONG index, LPVOID element, LONG size) {
	if (index >= lpb->usednum) return FALSE;

	if (size < 0) size = lpb->unitsize;
	memcpy((LPBYTE)lpb->_data + lpb->unitsize * index, element, size);
	return TRUE;
}

LPVOID	_stdcall EBuffer_getelement(LPBUFFERTYPE lpb, LONG index) {
	if (index >= lpb->usednum) return NULL;

	return (LPBYTE)lpb->_data + lpb->unitsize * index;
}

BOOL	_stdcall EBuffer_moveelement(LPBUFFERTYPE lpb, LONG fromindex, LONG toindex) {
	if (fromindex >= lpb->unitsize) return FALSE;
	if (toindex >= lpb->unitsize) return FALSE;

	if (fromindex == toindex) return TRUE;

	memcpy( (LPBYTE)lpb->_data + lpb->unitsize * toindex,
		(LPBYTE)lpb->_data + lpb->unitsize * fromindex,
		lpb->unitsize);
	return TRUE;
}

BOOL	_stdcall EBuffer_appendelement(LPBUFFERTYPE lpb, LPVOID element, LONG size) {
	if (!EBuffer_setsize(lpb, lpb->usednum + 1)) return FALSE;
	return EBuffer_setelement(lpb, lpb->usednum - 1, element, size);
}

BOOL	_stdcall EBuffer_insertelement(LPBUFFERTYPE lpb, LONG insertindex, LPVOID element, LONG size) {
	if (insertindex >= lpb->usednum) return FALSE;
	if (!EBuffer_setsize(lpb, lpb->usednum + 1)) return FALSE;
	for (LONG l = lpb->usednum - 1; l > insertindex; l--) {
		EBuffer_moveelement(lpb, l - 1, l);
	}
	return EBuffer_setelement(lpb, insertindex, element, size);
}

BOOL	_stdcall EBuffer_deleteelement(LPBUFFERTYPE lpb, LONG deleteindex, LONG num) {
	if (deleteindex + num - 1 >= lpb->usednum) return FALSE;
	if (lpb->_data == NULL && num > 0) return FALSE;

	for (LONG l = deleteindex + num; l < lpb->usednum; l++) {
		EBuffer_moveelement(lpb, l, l - num);
	}
	return EBuffer_setsize(lpb, lpb->usednum - num);
}

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		EMemory_resetvar();
		break;
	}
	return TRUE;
}