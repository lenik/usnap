/*
 * MATLAB Compiler: 2.2
 * Date: Wed Apr 17 09:12:44 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "f_bi_function"
 */

#ifndef MLF_V2
#define MLF_V2 1
#endif

#ifndef __f_bi_function_h
#define __f_bi_function_h 1

#ifdef __cplusplus
extern "C" {
#endif

#include "libmatlb.h"

extern void InitializeModule_f_bi_function(void);
extern void TerminateModule_f_bi_function(void);
extern _mexLocalFunctionTable _local_function_table_f_bi_function;

extern mxArray * mlfF_bi_function(mxArray * x);
extern void mlxF_bi_function(int nlhs,
                             mxArray * plhs[],
                             int nrhs,
                             mxArray * prhs[]);

#ifdef __cplusplus
}
#endif

#endif
