
#pragma once

#define ARRAY_NUM				4096
#define DATA_NONEXIST			0

long laDatas[ARRAY_NUM];

long _stdcall setld(int, long);
long _stdcall getld(int);
int _stdcall getarraynum();

HANDLE hDllModule = NULL;

GWin *winMain;

void _stdcall waInitialize();
void _stdcall waUninitialize();

ATOM _stdcall waRegister();
HWND _stdcall waCreate();
