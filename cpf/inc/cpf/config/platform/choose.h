#ifndef _choose_umac_n_xWDeY_BEjht87g_
#define _choose_umac_n_xWDeY_BEjht87g_

#if defined (__PVM__)
#    define CPF_PLATFORM "POS VM"
#    include "pvm.h"
#elif defined(__IBMCPP__) || defined(_AIX)
#    define CPF_PLATFORM "IBM AIX"
#    include "aix.h"
#elif defined(__amigaos__)
#    define CPF_PLATFORM "Amiga OS"
#    include "amiga.h"
#elif defined(__BEOS__)
#    define CPF_PLATFORM "BeOS"
#    include "beos.h"
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
#    define CPF_PLATFORM "BSD"
#    include "bsd.h"
#elif defined(__CYGWIN__)
#    define CPF_PLATFORM "Cygwin"
#    include "cygwin.h"
#elif defined(__hpux)
#    define CPF_PLATFORM "HP Unix"
#    include "hpux.h"
#elif defined(__sgi)
#    define CPF_PLATFORM "SGI Irix"
#    include "irix.h"
#elif defined(linux) || defined(__linux) || defined(__linux__)
#    define CPF_PLATFORM "Linux"
#    include "linux.h"
#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
#    define CPF_PLATFORM "Apple MacOS"
#    include "mac.h"
#elif defined(__QNXNTO__)
#    define CPF_PLATFORM "QNX"
#    include "qnx.h"
#elif defined(sun) || defined(__sun)
#    define CPF_PLATFORM "Sun Solaris"
#    include "solaris.h"
#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#    define CPF_PLATFORM "Microsoft Win32"
#    include "win32.h"
#elif defined(unix) || defined(__unix) || defined(_XOPEN_SOURCE) || defined(_POSIX_SOURCE)
#    define CPF_PLATFORM "Generic Unix"
#    include "unix.h"
#else
#    error "Unknown platform"
#endif

#endif
