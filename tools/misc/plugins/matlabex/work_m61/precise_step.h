/*
 * MATLAB Compiler: 2.2
 * Date: Wed Apr 17 09:21:32 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "precise_step"
 */

#ifndef MLF_V2
#define MLF_V2 1
#endif

#ifndef __precise_step_h
#define __precise_step_h 1

#ifdef __cplusplus
extern "C" {
#endif

#include "libmatlb.h"

extern void InitializeModule_precise_step(void);
extern void TerminateModule_precise_step(void);
extern _mexLocalFunctionTable _local_function_table_precise_step;

extern mxArray * mlfPrecise_step(mxArray * inargs);
extern void mlxPrecise_step(int nlhs,
                            mxArray * plhs[],
                            int nrhs,
                            mxArray * prhs[]);

#ifdef __cplusplus
}
#endif

#endif
