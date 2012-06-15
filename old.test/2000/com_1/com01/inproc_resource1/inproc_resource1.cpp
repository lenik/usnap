// inproc_resource1.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#define SRC_UNUSED		0
#define SRC_USED		1

#define STR_USED		"."

/*
 * 本程序用于演示进程内DLL的资源利用情况。
 *
 * 分下面几个部分：
 *	进程和线程
 *		. 单进程单线程多次申请资源的情况
 *		. 单进程多线程的情况
 *		. 多进程的情况
 *	COM的套间线程
 *		. APARTMENT套间
 *		. FREE套间
 *		. BOTH套间
 *		. NEURAL套间
 */

LONG	src_thread		= SRC_UNUSED;
LONG	src_process		= SRC_UNUSED;
static LONG	stcsrc_thread	= SRC_UNUSED;
static LONG	stcsrc_process	= SRC_UNUSED;

BOOL RecordString(LPCTSTR str) {
	HANDLE	hFile;
	BOOL	r;

	hFile	= CreateFile(
		"C:\\winnt\\temp\\irr",
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_ARCHIVE,
		NULL);
	if (hFile == INVALID_HANDLE_VALUE) return FALSE;

	SetFilePointer(hFile, 0, 0, FILE_END);

	DWORD	written = 0;
	r	= WriteFile(hFile, (LPCVOID)str, lstrlen(str), &written, NULL);

	CloseHandle(hFile);
	return r;
}

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	TCHAR wbuf[1024];
	wsprintf(wbuf, _T("(module: %x)"), hModule);
	RecordString(wbuf);

	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		RecordString(_T("DLL_PROCESS_ATTACH\n"));
		src_process	= SRC_UNUSED;
		stcsrc_process	= SRC_UNUSED;
		break;
	case DLL_THREAD_ATTACH:
		RecordString(_T("DLL_THREAD_ATTACH\n"));
		src_thread	= SRC_UNUSED;
		stcsrc_thread	= SRC_UNUSED;
		break;
	case DLL_PROCESS_DETACH:
		RecordString(_T("DLL_PROCESS_DETACH\n"));
		break;
	case DLL_THREAD_DETACH:
		RecordString(_T("DLL_THREAD_DETACH\n"));
		break;
	default:
		RecordString(_T("DLL_????????????\n"));
	}

	return TRUE;
}

BOOL	_stdcall queryallsrc(LPCTSTR client_name) {
	TCHAR	wbuf[2048];
	BOOL	r;
	wsprintf(wbuf, _T("%s has: (%s %s %s %s), all taken. \n"),
		client_name,
		src_thread == SRC_USED ? _T(STR_USED) : _T("T_src"),
		src_process == SRC_USED ? _T(STR_USED) : _T("P_src"),
		stcsrc_thread == SRC_USED ? _T(STR_USED) : _T("stc_T_src"),
		stcsrc_process == SRC_USED ? _T(STR_USED) : _T("stc_P_src")
		);
	src_thread	= SRC_USED;
	src_process	= SRC_USED;
	stcsrc_thread	= SRC_USED;
	stcsrc_process	= SRC_USED;
	r = RecordString(wbuf);
	return r;
}

BOOL	_stdcall QueryThreadAvailable() {
	return src_thread == SRC_UNUSED;
}

BOOL	_stdcall QueryProcessAvailable() {
	return src_process == SRC_UNUSED;
}

BOOL	_stdcall QueryStaticThreadAvailable() {
	return stcsrc_thread == SRC_UNUSED;
}

BOOL	_stdcall QueryStaticProcessAvailable() {
	return stcsrc_process == SRC_UNUSED;
}
