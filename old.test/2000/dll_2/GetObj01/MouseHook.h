
typedef LRESULT (CALLBACK* IHOOKPROC)(int &code, WPARAM &wParam, LPARAM &lParam);

#ifdef __MOUSEHOOK_CPP

	#define MOUSEHOOKAPI __declspec(dllexport)

	HANDLE hMouseHookModule = NULL;

	HHOOK hhk = NULL;
	BOOL Enable = TRUE;
	IHOOKPROC IMouseProc = NULL;

	LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);

#else

	#define MOUSEHOOKAPI __declspec(dllimport)

#endif

HHOOK MOUSEHOOKAPI InstallMouseHook(IHOOKPROC UserMouseProc);
BOOL MOUSEHOOKAPI UninstallMouseHook(HHOOK hhk);
void MOUSEHOOKAPI EnableMouseHook();
void MOUSEHOOKAPI DisableMouseHook();
