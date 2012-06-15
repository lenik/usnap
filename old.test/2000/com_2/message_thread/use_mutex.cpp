
#include "stdafx.h"

DWORD	WINAPI	ThreadProc_use_mutex(LPVOID pParam) {

	cout	<< "[" << GetCurrentThreadId() << "] "
		<< "------------------->" << endl;

	HANDLE	hevent	= OpenMutex(EVENT_MODIFY_STATE, FALSE, "MYMUTEX");
	for (int i = 0; i < 4; i++) {
		cout	<< "[" << GetCurrentThreadId() << "] "
			<< "waiting for MYMUTEX" << endl;
		WaitForSingleObject(hevent, INFINITE);

		static int count	= 0;
		count++;
		cout	<< "[" << GetCurrentThreadId() << "] "
			<< "I've got the mutex. total: " << count << endl;
		cout	<< "[" << GetCurrentThreadId() << "] "
			<< "doing with mutex......" << endl;
		Sleep(3000);
		cout	<< "[" << GetCurrentThreadId() << "] "
			<< "I'll release the mutex. " << endl;
		count--;
		ReleaseMutex(hevent);
	}
	CloseHandle(hevent);
	cout	<< "[" << GetCurrentThreadId() << "] "
		<< "<-----------------" << endl;
	return 0;
}

int main_use_mutex(int argc, char **argv) {
	SECURITY_ATTRIBUTES	sa;
	SECURITY_DESCRIPTOR	sd;
	sa.nLength		= sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle	= TRUE;
	sa.lpSecurityDescriptor	= &sd;

	InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
	SetSecurityDescriptorDacl(&sd, TRUE, (PACL)NULL, FALSE);

	HANDLE	hevent	= CreateMutex(&sa, FALSE, "MYMUTEX");
	cout	<< ":Primary thread ID = "
		<< GetCurrentThreadId() << endl;
	DWORD	dw;
	HANDLE	handle;
	handle	= CreateThread(NULL, 0, ThreadProc_use_mutex, NULL, 0, &dw);
	CloseHandle(handle);
	Sleep(200);
	handle	= CreateThread(NULL, 0, ThreadProc_use_mutex, NULL, 0, &dw);
	CloseHandle(handle);
	Sleep(200);
	handle	= CreateThread(NULL, 0, ThreadProc_use_mutex, NULL, 0, &dw);
	CloseHandle(handle);

	Sleep(15000);
	CloseHandle(hevent);
	return 0;
}
