
#define MOUSEHOOKAPI	WINAPI

typedef LRESULT (CALLBACK* HOOKPROC)(int code, WPARAM wParam, LPARAM lParam);
typedef LRESULT (CALLBACK* IHOOKPROC)(int &code, WPARAM &wParam, LPARAM &lParam);

#ifdef __MOUSEHOOK_CPP

	#pragma data_seg("GlobalData")

	extern HMODULE hMouseHookModule;

	extern HHOOK hhk;
	extern BOOL Enable;
	extern IHOOKPROC IMouseProc;

	// 记录在DLL中MouseHook的调用次数
	extern int nCallbackCount;

	#pragma data_seg()

#endif

HHOOK MOUSEHOOKAPI InstallMouseHook(IHOOKPROC UserMouseProc);
BOOL MOUSEHOOKAPI UninstallMouseHook(HHOOK hhk);
void MOUSEHOOKAPI EnableMouseHook();
void MOUSEHOOKAPI DisableMouseHook();

void MOUSEHOOKAPI SetIMouseProc(IHOOKPROC ihp);
LRESULT MOUSEHOOKAPI CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
int MOUSEHOOKAPI GetCallbackCount();
