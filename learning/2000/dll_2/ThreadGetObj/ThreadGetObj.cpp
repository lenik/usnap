// ThreadGetObj.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include <stdio.h>

HANDLE	ghHookThread;
BOOL CreateThreadHook();
DWORD hookMain(LPVOID lpv);

PROCESS_INFORMATION gHookProcess;
BOOL CreateProcessHook(LPCTSTR lpApplicationName, LPTSTR lpCommandLine);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	if (lpCmdLine[0] == 'x') {
		lpCmdLine++;
		LPTSTR app, cmd;
		app = lpCmdLine;
		cmd = strchr(app, ' ');
		if (cmd != NULL) {
			*cmd = 0;
			cmd++;
			if (*cmd <= ' ') cmd = NULL;
		}
		if (CreateProcessHook(app, cmd)) {
			DWORD ExitCode = 0;
			WaitForSingleObject(gHookProcess.hProcess, INFINITE);
			if (GetExitCodeProcess(gHookProcess.hProcess, &ExitCode)) {
				fprintf(outdev, "\n\nExit Code of Process %d'%x: \n\t%d'%x\n",
					gHookProcess.hProcess, gHookProcess.hProcess,
					ExitCode, ExitCode);
			}
		} else {
			DWORD e = GetLastError();
			fprintf(outdev, "\n\n\ncould not create the process: %d'%d. (%s)",
				e, e, lpCmdLine);
		}
	} else if (CreateThreadHook()) {
		for (int i = 0; i < 100; i++) {
			fprintf(outdev, "<<%d>>\n", i);
			Sleep(10);
		}
		WaitForSingleObject(ghHookThread, INFINITE);
	} else {
		fprintf(outdev, "\n\n\nError when creating thread: %d\n", GetLastError());
	}
	if (useFile) {
		fclose(outdev);
	}
	return 0;
}

BOOL CreateThreadHook() {
	DWORD Id;
	ghHookThread = CreateThread(
		NULL, 0,
		(LPTHREAD_START_ROUTINE)hookMain,
		0L, STANDARD_RIGHTS_REQUIRED, &Id);
	if (!ghHookThread) return FALSE;
	return TRUE;
}

DWORD hookMain(LPVOID lpv) {
	for (int i = 0; i < 100; i++) {
		fprintf(outdev, "%d\n", i);
		Sleep(5);
	}
	ExitThread(0);
}

DWORD _CreateProcess(LPCTSTR lpAppName,
			  LPTSTR lpCmdLine,
			  LPSECURITY_ATTRIBUTES lpProcessAttributes,
			  LPSECURITY_ATTRIBUTES lpThreadAttributes,
			  BOOL bInheritHandles,
			  DWORD dwCreationFlags,
			  LPVOID lpEnvironment,
			  LPCTSTR lpCurrentDirectory,
			  LPSTARTUPINFO lpStartupInfo,
			  LPPROCESS_INFORMATION lpProcessInformation) {
	UNREFERENCED_PARAMETER(lpAppName);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(lpProcessAttributes);
	UNREFERENCED_PARAMETER(lpThreadAttributes);
	UNREFERENCED_PARAMETER(bInheritHandles);
	UNREFERENCED_PARAMETER(dwCreationFlags);
	UNREFERENCED_PARAMETER(lpEnvironment);
	UNREFERENCED_PARAMETER(lpCurrentDirectory);
	UNREFERENCED_PARAMETER(lpStartupInfo);
	UNREFERENCED_PARAMETER(lpProcessInformation);
	return FALSE;
}

BOOL CreateProcessHook(LPCTSTR lpApplicationName, LPTSTR lpCommandLine) {
	DWORD Id;
	DWORD r;
	STARTUPINFO si;
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	memset(&gHookProcess, 0, sizeof(gHookProcess));
	r = CreateProcess(
		lpApplicationName, lpCommandLine,
		NULL, NULL,
		TRUE,				// Inherit
		0,					// CreationFlag
		NULL, NULL,			// Enviroment & CurDirectory
		&si,				// StartupInfo
		&gHookProcess);
	return r;
}
