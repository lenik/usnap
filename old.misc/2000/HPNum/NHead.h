
// ordinary funcs. macros
// simple "mfc"

// dansei, 99.6.25


#ifndef __NHEAD_H
#define __NHEAD_H

#include <Windows.h>

#ifdef _DEBUG
#	ifndef ASSERT
#		define ASSERT(x) \
do { \
	if (!(x)) { \
		char *__string = new char[4096]; \
		int nRet; \
		wsprintf(__string, "ASSERT ERROR: \n %s\tLine = %d\n", __FILE__, __LINE__); \
		nRet = MessageBox(NULL, __string, "ASSERT ERROR", MB_OKCANCEL); \
		delete[] __string; \
		if (nRet == IDCANCEL) { exit(-1); } \
	} \
} while (0)
#	endif
#	ifndef ASSERT_VALID
#		define ASSERT_VALID(x) do { if (x != NULL) { x->AssertValid(); } } while (0)
#	endif
#else
#	ifndef ASSERT
#		define ASSERT(x) ((void *)0)
#	endif
#	ifndef ASSERT_VALID
#		define ASSERT_VALID(x) ((void *)0)
#	endif
#endif

#endif
