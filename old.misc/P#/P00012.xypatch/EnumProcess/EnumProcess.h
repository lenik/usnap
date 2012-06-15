
#pragma once

#ifdef ENUMPROCESS_EXPORTS
#define EPAPI	__declspec(dllexport)
#else
#define EPAPI	__declspec(dllimport)
#endif

#include <windows.h>

BOOL EPAPI PASCAL EnumProcess(HWND &hWnd, BOOL FirstTime = FALSE);
