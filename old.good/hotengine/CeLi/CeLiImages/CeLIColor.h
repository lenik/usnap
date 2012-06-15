
#pragma once

#ifndef CELIAPI
#define CELIAPI extern "C" _declspec(dllimport)
#endif

CELIAPI
HRESULT _stdcall rgb24Plus(LONG c1, LONG c2, LONG *ret);
