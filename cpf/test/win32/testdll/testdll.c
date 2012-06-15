// testdll.cpp : Defines the entry point for the DLL application.
//

#include <stdio.h>
#include <windows.h>

#define DYNALOAD
#include <cpf/dynasub.h>

DYNASUB("testdll2.dll", add, int, _stdcall, (int a, int b), (a, b))

int _stdcall test1(int a, int b) {
    int c = add(a, b);
    char buf[300];
    sprintf(buf, "%d + %d = %d", a, b, c);
    return MessageBox(0, buf, "test-1", 0);
}

void _stdcall hello() {
    MessageBox(0, "Hello, World", "test-1", 0);
}

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}
