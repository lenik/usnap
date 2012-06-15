
#include "stdafx.h"


void KillThread() {
	HANDLE	hevent	= OpenEvent(EVENT_MODIFY_STATE, FALSE, "KILL_THREAD");
	cout	<< "set KILL_EVENT" << endl;
	SetEvent(hevent);
	CloseHandle(hevent);
}

DWORD	WINAPI ThreadProc_use_events(LPVOID pParam) {
	cout	<< ":Secondary thread ID = "
		<< GetCurrentThreadId() << endl;

	SECURITY_ATTRIBUTES	sa;
	SECURITY_DESCRIPTOR	sd;
	sa.nLength		= sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle	= TRUE;
	sa.lpSecurityDescriptor	= &sd;

	InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
	SetSecurityDescriptorDacl(&sd, TRUE, (PACL)NULL, FALSE);

	cout	<< "Thread::CreateEvent KILL_THREAD" << endl;
	HANDLE	hevent	= CreateEvent(&sa, FALSE, FALSE, "KILL_THREAD");

	cout	<< "wait for KILL_THREAD" << endl;
	WaitForSingleObject(hevent, INFINITE);
	cout	<< "received KILL_THREAD" << endl;

	cout	<< "GoodBye!" << endl;
	return 0;
}

int	main_use_events(int argc, char **argv) {
	cout	<< ":Primary thread ID = "
		<< GetCurrentThreadId() << endl;

	DWORD	dw;
	HANDLE	handle = CreateThread(NULL, 0, ThreadProc_use_events, NULL, 0, &dw);
	Sleep(1000);
	CloseHandle(handle);

	cout	<< "main::KillThread()" << endl;
	KillThread();
	return 0;
}
