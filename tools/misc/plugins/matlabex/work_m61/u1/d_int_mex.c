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

#include "libmatlb.h"
#include "d_int.h"
#include "EvalFVal.h"

static mexFunctionTableEntry function_table[1]
  = { { "d_int", mlxD_int, 2, 1, &_local_function_table_d_int } };

static _mexInitTermTableEntry init_term_table[1]
  = { { InitializeModule_d_int, TerminateModule_d_int } };

static _mex_information _mex_info
  = { 1, 1, function_table, 0, NULL, 0, NULL, 1, init_term_table };

/*
 * The function "MEvalFVal" is the MATLAB callback version of the "EvalFVal"
 * function from file "d:\M6\work\EvalFVal.m". It performs a callback to MATLAB
 * to run the "EvalFVal" function, and passes any resulting output arguments
 * back to its calling function.
 */
static mxArray * MEvalFVal(int nargout_, mxArray * f, mxArray * fx) {
    mxArray * out = mclGetUninitializedArray();
    mclFevalCallMATLAB(
      mclNVarargout(nargout_, 0, &out, NULL), "EvalFVal", f, fx, NULL);
    return out;
}

/*
 * The function "mexLibrary" is a Compiler-generated mex wrapper, suitable for
 * building a MEX-function. It initializes any persistent variables as well as
 * a function table for use by the feval function. It then calls the function
 * "mlxD_int". Finally, it clears the feval table and exits.
 */
mex_information mexLibrary(void) {
    mclMexLibraryInit();
    return &_mex_info;
}

/*
 * The function "mlfEvalFVal" contains the normal interface for the "EvalFVal"
 * M-function from file "d:\M6\work\EvalFVal.m" (lines 0-0). This function
 * processes any input arguments and passes them to the implementation version
 * of the function, appearing above.
 */
mxArray * mlfEvalFVal(mxArray * f, mxArray * fx) {
    int nargout = 1;
    mxArray * out = mclGetUninitializedArray();
    mlfEnterNewContext(0, 2, f, fx);
    out = MEvalFVal(nargout, f, fx);
    mlfRestorePreviousContext(0, 2, f, fx);
    return mlfReturnValue(out);
}

/*
 * The function "mlxEvalFVal" contains the feval interface for the "EvalFVal"
 * M-function from file "d:\M6\work\EvalFVal.m" (lines 0-0). The feval function
 * calls the implementation version of EvalFVal through this function. This
 * function processes any input arguments and passes them to the implementation
 * version of the function, appearing above.
 */
void mlxEvalFVal(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[2];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: EvalFVal Line: 1 Column: "
            "1 The function \"EvalFVal\" was called with mor"
            "e than the declared number of outputs (1)."));
    }
    if (nrhs > 2) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: EvalFVal Line: 1 Column:"
            " 1 The function \"EvalFVal\" was called with m"
            "ore than the declared number of inputs (2)."));
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = mclGetUninitializedArray();
    }
    for (i = 0; i < 2 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 2; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(0, 2, mprhs[0], mprhs[1]);
    mplhs[0] = MEvalFVal(nlhs, mprhs[0], mprhs[1]);
    mlfRestorePreviousContext(0, 2, mprhs[0], mprhs[1]);
    plhs[0] = mplhs[0];
}
