// EMemory.cpp : Defines the entry point for the DLL application.
//

typedef struct _tag_BUFFERTYPE {
	LPVOID	_data;
	LONG	unitsize;

	LONG	usednum;
	LONG	deltanum;
	LONG	allocnum;

	DWORD	handle;

	_tag_BUFFERTYPE() : _data(NULL), unitsize(1), usednum(0), deltanum(4), allocnum(0) {}
} BUFFERTYPE, *PBUFFERTYPE, *LPBUFFERTYPE;

BOOL	_stdcall EMemory_funcswitch(BOOL bAsGlobal);
ULONG	_stdcall EMemory_setflags(ULONG newflags);
BOOL	_stdcall EMemory_resetvar();

LPVOID	_stdcall AllocMemory(DWORD size, LPDWORD saveHandle);
LPVOID	_stdcall ReallocMemory(DWORD NewSize, LPDWORD saveHandle);
BOOL	_stdcall FreeMemory(LPDWORD saveHandle);

BOOL	_stdcall EBuffer_setsize(LPBUFFERTYPE lpb, LONG newsize);
BOOL	_stdcall EBuffer_clear(LPBUFFERTYPE lpb);
BOOL	_stdcall EBuffer_compress(LPBUFFERTYPE lpb);

BOOL	_stdcall EBuffer_setelement(LPBUFFERTYPE lpb, LONG index, LPVOID element, LONG size = -1);
LPVOID	_stdcall EBuffer_getelement(LPBUFFERTYPE lpb, LONG index);
BOOL	_stdcall EBuffer_moveelement(LPBUFFERTYPE lpb, LONG fromindex, LONG toindex);

BOOL	_stdcall EBuffer_appendelement(LPBUFFERTYPE lpb, LPVOID element, LONG size = -1);
BOOL	_stdcall EBuffer_insertelement(LPBUFFERTYPE lpb, LONG insertindex, LPVOID element, LONG size = -1);
BOOL	_stdcall EBuffer_deleteelement(LPBUFFERTYPE lpb, LONG deleteindex, LONG num = 1);
