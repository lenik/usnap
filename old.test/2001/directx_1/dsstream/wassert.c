
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

extern HWND	hWndMain;
extern char	szAppName[];

#include "wassert.h"

#ifdef WASSERT
void AssertFail(char szErr[], char szFileName[], int nLine, char szMessage[]) {
	char szT[256];

	if (szMessage != NULL)
		wsprintf(szT, "Assert(%s); \nFile %s, line %d.	%s", szErr, szFileName, nLine, szMessage);
	else
		wsprintf(szT, "Assert(%s); \nFile %s, line %d. ", szErr, szFileName, nLine);
	switch (MessageBox(hWndMain, szT, szAppName, MB_ABORTRETRYIGNORE | MB_ICONSTOP | MB_APPLMODAL)) {
	case IDABORT:
		SengMessage(hWndMain, WM_CLOSE, 0, 0);
	case IDRETRY:
		_asm int 3;
		break;
	case IDIGNORE:
		break;
	}

#endif
