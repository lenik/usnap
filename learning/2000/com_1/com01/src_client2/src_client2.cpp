// src_client2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "..\src_client1\inproc_src.h"
#include <GWin.h>

DWORD WINAPI Thread1(LPVOID lpParameter) {
	BOOL r;

	printf("Thread 1 started. \n");
	r = queryallsrc("Thread 1-1");
	Sleep(1000);
	printf("Thread 1 stopped. \n");
	return 0;
}

DWORD WINAPI Thread2(LPVOID lpParameter) {
	BOOL r;

	printf("Thread 2 started. \n");
	r = queryallsrc("Thread 2-1");
	Sleep(1000);
	printf("Thread 2 stopped. \n");
	return 0;
}

int main(int argc, char* argv[])
{
	BOOL r;
	TCHAR buf[1024];

	printf("Process 1 started.\n");

	HANDLE	hThread1, hThread2;
	DWORD	idThread1, idThread2;
	hThread1 = CreateThread(NULL, 0, Thread1, NULL, 0, &idThread1);
	CloseHandle(hThread1);
	Sleep(500);
	hThread2 = CreateThread(NULL, 0, Thread2, NULL, 0, &idThread2);
	CloseHandle(hThread2);
	Sleep(300);

	printf("Process 1 querysrc\n");
	r = queryallsrc("Process 1-1");
	printf("Process 1 queryallsrc: %s\n", r ? "success" : "failure");

	if (!r) {
		PrintError(GetLastError());
	}

	printf("Process 1 stopped. \n");

	Sleep(3000);

	return 0;
}
