#ifndef _config_umac_n_xWDeYMDfEDqv7q_
#define _config_umac_n_xWDeYMDfEDqv7q_

#include "config/compiler/choose.h"
#include "config/platform/choose.h"

#if (defined(DEBUG) || defined(_DEBUG_)) && !defined(_DEBUG)
#   define _DEBUG 1
#endif

#endif
