#ifndef _start_umac_n_xWDeYtXaeGwSrK_
#define _start_umac_n_xWDeYtXaeGwSrK_

#include "config.h"

/* system-indepentent utilities */
#define _zinit_(v) memset(&(v), 0, sizeof(v))

/* platform-branch... */
#include "win32/start.h"

/* cpp utilities using c features */
#ifdef AfxDebugBreak
#    define _breakpoint_() AfxDebugBreak()
#else
#    define _breakpoint_() { __asm int 3 }
#endif

#endif
