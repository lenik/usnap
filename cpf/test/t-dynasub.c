
#include "stdhdrs.h"
#include <windows.h>
#define DYNALOAD
#include <cpf/dynasub.h>

DYNASUB("../../testdll/Debug/testdll.dll", test1, int, _stdcall,
        (int a, int b), (a, b))
DYNASUB_V("../../testdll/Debug/testdll.dll", hello, _stdcall,
        (), ())

int test_dynasub() {
    hello();
    test1(3, 4);
    return 0;
}
