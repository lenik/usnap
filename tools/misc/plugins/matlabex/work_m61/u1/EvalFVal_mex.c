/*
 * MATLAB Compiler: 2.2
 * Date: Wed Apr 17 09:05:45 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "EvalFVal"
 */

#ifndef MLF_V2
#define MLF_V2 1
#endif

#include "libmatlb.h"
#include "EvalFVal.h"
#include "subs.h"

static mexFunctionTableEntry function_table[1]
  = { { "EvalFVal", mlxEvalFVal, 2, 1, &_local_function_table_EvalFVal } };

static _mexInitTermTableEntry init_term_table[1]
  = { { InitializeModule_EvalFVal, TerminateModule_EvalFVal } };

static _mex_information _mex_info
  = { 1, 1, function_table, 0, NULL, 0, NULL, 1, init_term_table };

/*
 * The function "Msubs" is the MATLAB callback version of the "subs" function
 * from file "D:\M6\toolbox\symbolic\subs.m". It performs a callback to MATLAB
 * to run the "subs" function, and passes any resulting output arguments back
 * to its calling function.
 */
static mxArray * Msubs(int nargout_, mxArray * f, mxArray * varargin) {
    mxArray * r = mclGetUninitializedArray();
    mclFevalCallMATLAB(
      mclNVarargout(nargout_, 0, &r, NULL),
      "subs",
      f, mlfIndexRef(varargin, "{?}", mlfCreateColonIndex()), NULL);
    return r;
}

/*
 * The function "mexLibrary" is a Compiler-generated mex wrapper, suitable for
 * building a MEX-function. It initializes any persistent variables as well as
 * a function table for use by the feval function. It then calls the function
 * "mlxEvalFVal". Finally, it clears the feval table and exits.
 */
mex_information mexLibrary(void) {
    mclMexLibraryInit();
    return &_mex_info;
}

/*
 * The function "mlfSubs" contains the normal interface for the "subs"
 * M-function from file "D:\M6\toolbox\symbolic\subs.m" (lines 0-0). This
 * function processes any input arguments and passes them to the implementation
 * version of the function, appearing above.
 */
mxArray * mlfSubs(mxArray * f, ...) {
    mxArray * varargin = NULL;
    int nargout = 1;
    mxArray * r = mclGetUninitializedArray();
    mlfVarargin(&varargin, f, 0);
    mlfEnterNewContext(0, -2, f, varargin);
    r = Msubs(nargout, f, varargin);
    mlfRestorePreviousContext(0, 1, f);
    mxDestroyArray(varargin);
    return mlfReturnValue(r);
}

/*
 * The function "mlxSubs" contains the feval interface for the "subs"
 * M-function from file "D:\M6\toolbox\symbolic\subs.m" (lines 0-0). The feval
 * function calls the implementation version of subs through this function.
 * This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxSubs(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[2];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: subs Line: 1 Column: 1 The function \"subs\""
            " was called with more than the declared number of outputs (1)."));
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = mclGetUninitializedArray();
    }
    for (i = 0; i < 1 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 1; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(0, 1, mprhs[0]);
    mprhs[1] = NULL;
    mlfAssign(&mprhs[1], mclCreateVararginCell(nrhs - 1, prhs + 1));
    mplhs[0] = Msubs(nlhs, mprhs[0], mprhs[1]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
    mxDestroyArray(mprhs[1]);
}
