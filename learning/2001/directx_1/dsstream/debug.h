
#ifndef __DEBUG_INCLUDED__
#define __DEBUG_NICLUDED__

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef DEBUG
#	define DEBUG_SECTION		"Debug"
#	define DEBUG_MODULE_NAME	"DSSTREAM"
#	define DEBUG_MAX_LINE_LEN	255
#endif

#ifndef BCODE
#ifdef _WIN32
#	define BCODE
#else
#	define BCODE		_based(_segname("_CODE"))
#endif
#endif

#ifdef DEBUG
	BOOL WINAPI DbgEnable(BOOL fEnable);
	UINT WINAPI DbgGetLevel();
	UINT WINAPI DbgSetLevel(UINT uLevel);
	UINT WINAPI DbgInitialize(BOOL fEnable);
	void WINAPI _Assert(char * szFile, int iLine);

	void FAR CDECL dprintf(UINT uDbgLevel, LPSTR szFmt, ...);

	#define D(x)		{ x; }
	#define DPF		dprintf
	#define DPI(sz)		{ static char BCODE ach[] = sz; OutputDebugStr(ach); }
	#define ASSERT(x)	if (!(x)) _Assert(__FILE__, __LINE)
#else
	#define DbgEnable(x)	FALSE
	#define DbgGetLevel()	0
	#define DbgSetLevel(x)	0
	#define DbgInitialize(x) 0

	#ifdef _MSC_VER
	#pragma warning(disable:4002)
	#endif

	#define D(x)
	#define DPF()
	#define DPI(sz)
	#define ASSERT(x)
#endif

#ifdef __cplusplus
}
#endif
#endif
