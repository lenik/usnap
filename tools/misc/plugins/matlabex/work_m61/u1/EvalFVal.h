/*
 * MATLAB Compiler: 2.2
 * Date: Wed Apr 17 09:07:45 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "d_int"
 */

#ifndef MLF_V2
#define MLF_V2 1
#endif

#ifndef __EvalFVal_h
#define __EvalFVal_h 1

#ifdef __cplusplus
extern "C" {
#endif

#include "libmatlb.h"

extern void InitializeModule_EvalFVal(void);
extern void TerminateModule_EvalFVal(void);
extern _mexLocalFunctionTable _local_function_table_EvalFVal;

extern mxArray * mlfEvalFVal(mxArray * f, mxArray * fx);
extern void mlxEvalFVal(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);

#ifdef __cplusplus
}
#endif

#endif
