// message_thread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MYMESSAGE	(WM_USER + 1000)

DWORD	WINAPI ThreadProc(void *p) {
	cout	<< ":Secondary thread ID = "
		<< GetCurrentThreadId() << endl;

	MSG	msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		switch (msg.message) {
		case MYMESSAGE:
			cout	<< ":MyMessage received" << endl;
			break;
		default:
			break;
		}
	}
	cout	<< ":Secondary thread exit. " << endl;
	return 0;
}

int main_message_thread(int argc, char* argv[])
{
	cout	<< ":Primary thread ID = "
		<< GetCurrentThreadId() << endl;
	DWORD	dw;
	HANDLE	handle	= CreateThread(NULL, 0, ThreadProc, NULL, 0, &dw);

	Sleep(1000);
	PostThreadMessage(dw, MYMESSAGE, 0, 0);
	Sleep(1000);
	PostThreadMessage(dw, MYMESSAGE, 0, 0);
	Sleep(1000);
	PostThreadMessage(dw, WM_QUIT, 0, 0);
	Sleep(1000);
	CloseHandle(handle);

	cout	<< ":Primary thread exit. " << endl;
	return 0;
}
