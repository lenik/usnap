
#include "stdafx.h"

CRITICAL_SECTION	cs;

DWORD	WINAPI	ThreadProc_use_semaphore(LPVOID p) {
	EnterCriticalSection(&cs);
	cout	<< ":Secondary thread ID = "
		<< GetCurrentThreadId() << endl;
	LeaveCriticalSection(&cs);

	HANDLE	hevent	= OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE,
					"MYSEMAPHORE");
	for (int i = 0; i < 2; i++) {
		WaitForSingleObject(hevent, INFINITE);
		static int count = 0;

		EnterCriticalSection(&cs);
		count++;
		cout	<< "I've got the mutex. Thread = "
			<< GetCurrentThreadId() << endl;
		cout	<< "Threads with mutex = " << count << endl;
		LeaveCriticalSection(&cs);
		Sleep(100);
		count--;
		ReleaseSemaphore(hevent, 1, NULL);
	}
	CloseHandle(hevent);
	return 0;
}

int main_use_semaphore(int argc, char **argv) {

	SECURITY_ATTRIBUTES	sa;
	SECURITY_DESCRIPTOR	sd;
	sa.nLength		= sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle	= TRUE;
	sa.lpSecurityDescriptor	= &sd;

	InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
	SetSecurityDescriptorDacl(&sd, TRUE, (PACL)NULL, FALSE);

	InitializeCriticalSection(&cs);

	HANDLE	hevent	= CreateSemaphore(&sa, 3, 3, "MYSEMAPHORE");


	cout	<< ":Primary thread ID = "
		<< GetCurrentThreadId() << endl;

	DWORD	dw;
	for (int i = 0; i < 5; i++) {
		HANDLE	handle	= CreateThread(NULL, 0, ThreadProc_use_semaphore, NULL, 0, &dw);
		CloseHandle(handle);
	}

	Sleep(5000);
	CloseHandle(hevent);
	DeleteCriticalSection(&cs);

	return 0;
}
