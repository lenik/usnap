
#ifdef DEBUG

#include <windows.h>
#include <windowsx.h>
#include <stdarg.h>
#include "debug.h"

#ifdef _WIN32
	#include <wchar>
#else
	#define lstrcatA		lstrcat
	#define lstrlenA		lstrlen
	#define GetProfileIntA		GetProfileInt
	#define OutputDebugStringA	OutputDebugString
	#define wsprintfA		wsprintf
	#define MessageBoxA		MessageBox
#endif

BOOL	__gfDbgEnabled		= TRUE;
UINT	__guDbgLevel		= 0;

void FAR CDECL DbgVPrintF(LPSTR szFormat, va_list va) {
	char		ach[DEBUG_MAX_LINE_LEN];
	BOOL		fDebugBreak	= FALSE;
	BOOL		fPrefix		= TRUE;
	BOOL		fCRLF		= TRUE;

	ach[0] = '\0';

	for (;;) {
		switch (*szFormat) {
			case '!':
				fDebugBreak = TRUE;
				szFormat++;
				continue;
			case '`':
				fPrefix = FALSE;
				szFormat++;
				continue;
			case '~':
				fCRLF = FALSE;
				szFormat++;
				continue;
		}
		break;
	}

	if (fDebugBreak) {
		ach[0] = '\007';
		ach[1] = '\0';
	}

	if (fPrefix) {
		lstrcatA(ach, DEBUG_MODULE_NAME ": ");
	}

#ifdef _WIN32
	wvsprintfA(ach + lstrlenA(ach), szFormat, va);
#else
	wvsprintf(ach + lstrlenA(ach), szFormat, (LPSTR)va);
#endif

	if (fCRLF) {
		lstrcatA(ach, "\r\n");
	}

	OutputDebugStringA(ach);

	if (fDebugBreak) {
		DebugBreak();
	}
}


void FAR CDECL dprintf(UINT uDbgLevel, LPSTR szFormat, ...) {
	va_list va;

	if (!__gfDbgEnabled || (__guDbgLevel < uDbgLevel)) return;

	va_start(va, szFormat);
	DbgVPrintF(szFormat, va);
	va_end(va);
}

BOOL WINAPI DbgEnable(BOOL fEnable) {
	BOOL 		fOldState;
	fOldState 	= __gfDbgEnabled;
	__gfDbgEnabled	= fEnable;
	return fOldState;
}
UINT WINAPI DbgSetLevel(UINT uLevel) {
	UINT 		uOldLevel;
	uOldLevel	= __guDbgLevel;
	__guDbgLevel	= uLevel;
	return uOldLevel;
}

UINT WINAPI DbgGetLevel() {
	return __guDbgLevel;
}

UINT WINAPI DbgInitialize(BOOL fEnable) {
	UINT	uLevel;

	uLevel	= GetProfileIntA(DEBUG_SECTION, DEBUG_MODULE_NAME, (UINT)-1);
	if ((UINT)-1 == uLevel) {
		uLevel	= 0;
		fEnable	= FALSE;
	}

	DbgSetLevel(uLevel);
	DbgEnable(fEnable);

	return __guDbgLevel;
}

#ifndef _WIN32
#pragma warning(disable:4704)
#endif

void WINAPI _Assert(char * szFile, int iLine) {
	static char	ach[300];
	int		id;

#ifndef _WIN32
	int		iExitCode;
#endif

	wsprintfA(ach, "Assertion failed in file %s, line %d.  [Press RETRY to debug.]", (LPSTR)szFile, iLine);

	id = MessageBoxA(NULL, ach, "Assertion Failed", MB_SYSTEMMODAL | MB_ICONHAND | MB_ABORTRETRYIGNORE);

	switch (id) {
	case IDABORT:
#ifndef _WIN32
		iExitCode = 0;
		_asm{
			mov	ah, 4Ch
			mov	al, BYTE PTR iExitCode
			int	21h
		}
#else
		FatalAppExit(0, TEXT("Good Bye"));
#endif
		break;
	case IDRETRY:
		DebugBreak();
		break;
	case IDIGNORE:
		break;
	}
}

#ifndef _WIN32
#pragma warning(default: 4704)
#endif

#endif
