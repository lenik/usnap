
// LIBRARY SELF HELPER FUNCTIONS
LONG _stdcall returnIDFunc(); 
LONG _stdcall returnHandle(); 

// ADVANCED VB DATA TYPES
LONG _stdcall returnVal(LONG parameter); 

LONG _stdcall getStringLengthA(const char *parameter); 
LONG _stdcall getStringLengthW(const wchar_t *parameter); 
LONG _stdcall getStringLengthM(const unsigned char *parameter); 

LONG _stdcall copyBytes(LPBYTE src, LPBYTE dest, LONG cBytes); 

// CALLBACK SUPPORT
// NOTICE _stdcall !!
typedef LONG (_stdcall *_stdcallback)(...);	
typedef LONG (_cdecl *_cdeclcallback)(...); 

typedef LONG (_stdcall *_stdcallback0)(); 
typedef LONG (_stdcall *_stdcallback1)(LONG); 
typedef LONG (_stdcall *_stdcallback2)(LONG, LONG); 
typedef LONG (_stdcall *_stdcallback3)(LONG, LONG, LONG); 
typedef LONG (_stdcall *_stdcallback4)(LONG, LONG, LONG, LONG); 
typedef void (_stdcall *_stdvoidcallback0)(); 
typedef void (_stdcall *_stdvoidcallback1)(LONG); 
typedef void (_stdcall *_stdvoidcallback2)(LONG, LONG); 
typedef void (_stdcall *_stdvoidcallback3)(LONG, LONG, LONG); 
typedef void (_stdcall *_stdvoidcallback4)(LONG, LONG, LONG, LONG); 

LONG _stdcall callFunction0(_stdcallback0 parameter); 
LONG _stdcall callFunction1(_stdcallback1 parameter, LONG); 
LONG _stdcall callFunction2(_stdcallback2 parameter, LONG); 
LONG _stdcall callFunction3(_stdcallback3 parameter, LONG); 
LONG _stdcall callFunction4(_stdcallback4 parameter, LONG); 
void _stdcall callProcedure0(_stdvoidcallback0 parameter); 
void _stdcall callProcedure1(_stdvoidcallback1 parameter, LONG); 
void _stdcall callProcedure2(_stdvoidcallback2 parameter, LONG, LONG); 
void _stdcall callProcedure3(_stdvoidcallback3 parameter, LONG, LONG, LONG); 
void _stdcall callProcedure4(_stdvoidcallback4 parameter, LONG, LONG, LONG, LONG); 

LONG _stdcall _call_stdcall(_stdcallback proc, int vacount, int extra_release, LPINT pva); 
LONG _stdcall _call_cdecl(_cdeclcallback proc, int vacount, int extra_release, LPINT pva); 
LONG _stdcall call_stdcall(_stdcallback proc, int vacount, int extra_release, ...); 
LONG _stdcall call_cdecl(_cdeclcallback proc, int vacount, int extra_release, ...); 

DWORD _stdcall dword_add(DWORD a, DWORD b); 
DWORD _stdcall dword_sub(DWORD a, DWORD b); 
DWORD _stdcall dword_mul(DWORD a, DWORD b); 
DWORD _stdcall dword_div(DWORD a, DWORD b); 
DWORD _stdcall dword_shift_left(DWORD d, DWORD n); 
DWORD _stdcall dword_shift_right(DWORD d, DWORD n); 

// VB USER EXTEND

// 32bit platform

/*
	�ػ���Ϣ
	catchMessage���û���Ϣ���������ڴ���hWndԭ��Ϣ������ǰ�ˣ�
	�û��ص�switchprocProc����ԭ���ڴ������������û�ָ����ǰ��
	��Ϣ��������
		MSGPROC _stdcall switchprocProc(MSGPROC oldproc); 
	�û���ǰ����Ϣ�������������������ԭ��Ϣ������:
		chainMessage(oldproc, ...)
*/

DWORD _stdcall catchMessage(HWND hWnd, _stdcallback1 switchprocProc); 
DWORD _stdcall chainMessage(WNDPROC wndproc, HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); 
