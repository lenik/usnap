#ifndef _defs_umac_n_xWDeY8rvGfL_qA_
#define _defs_umac_n_xWDeY8rvGfL_qA_ "$Id: defs.h,v 1.1 2007-11-03 12:23:05 lenik Exp $"

#ifndef ASSERT
#if defined(DEBUG) || defined(_DEBUG)
#include <assert.h>
#define ASSERT(x) assert(x)
#else
#define ASSERT(x)
#endif
#endif

#endif
