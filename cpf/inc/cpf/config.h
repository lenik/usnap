#ifndef _config_umac_n_xWDeYMDfEDqv7q_
#define _config_umac_n_xWDeYMDfEDqv7q_ "$Id: config.h,v 1.3 2006-05-15 15:14:54 dansei Exp $"

#include "config/compiler/choose.h"
#include "config/platform/choose.h"

#if (defined(DEBUG) || defined(_DEBUG_)) && !defined(_DEBUG)
#   define _DEBUG 1
#endif

/* CPF Common Calling Convention */
#ifndef _cc
#define _cc _stdcall
#endif

#endif
