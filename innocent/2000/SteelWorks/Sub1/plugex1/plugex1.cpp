// plugex1.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "tchar.h"

// �Ʒֲ��ʾ��

float _stdcall score_for_stream_units_compare(int match, int unmatch, int extra, int lost) {
	return (match - 3.f * unmatch - 2.f * (extra + lost)) / (match + unmatch + extra + lost);
}

void _stdcall about_for_plugin() {
	MessageBox(NULL, _T("�Ʒֲ����ʾ\n\n��Ȩ���� (C)�ҿ���� 1997-2001"), _T("���ڱ����"), 0);
}

LPTSTR _stdcall syntax_for_plugin() {
	return _T("��ȷ - 3 * ���� - 2 * ��©");
}

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}
