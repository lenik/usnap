// plugex1.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "tchar.h"

// 计分插件示例

float _stdcall score_for_stream_units_compare(int match, int unmatch, int extra, int lost) {
	return (match - 3.f * unmatch - 2.f * (extra + lost)) / (match + unmatch + extra + lost);
}

void _stdcall about_for_plugin() {
	MessageBox(NULL, _T("计分插件演示\n\n版权保留 (C)桃壳软件 1997-2001"), _T("关于本插件"), 0);
}

LPTSTR _stdcall syntax_for_plugin() {
	return _T("正确 - 3 * 错误 - 2 * 余漏");
}

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}
