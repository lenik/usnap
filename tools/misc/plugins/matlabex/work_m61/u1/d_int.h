/*
 * MATLAB Compiler: 2.2
 * Date: Wed Apr 17 09:12:27 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "f_bi"
 */

#ifndef MLF_V2
#define MLF_V2 1
#endif

#ifndef __d_int_h
#define __d_int_h 1

#ifdef __cplusplus
extern "C" {
#endif

#include "libmatlb.h"

extern void InitializeModule_d_int(void);
extern void TerminateModule_d_int(void);
extern _mexLocalFunctionTable _local_function_table_d_int;

extern mxArray * mlfD_int(mxArray * f, mxArray * int_region);
extern void mlxD_int(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);

#ifdef __cplusplus
}
#endif

#endif
