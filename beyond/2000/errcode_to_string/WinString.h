
#pragma once

#ifdef WINSTRING_EXPORTS
#define WINSTRING_API __declspec(dllexport)
#else
#define WINSTRING_API __declspec(dllimport)
#endif

LPSTR WINSTRING_API LookUpTheMessage(UINT message, LPSTR Buf);
