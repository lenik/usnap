// test_hc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <objbase.h>

int main(int argc, char* argv[])
{
    CoInitialize(NULL);

    BSTR bs = SysAllocStringByteLen("Hello", 5);

    _asm int 3
    printf("Hello World!\n");

    CoUninitialize();
	return 0;
}
