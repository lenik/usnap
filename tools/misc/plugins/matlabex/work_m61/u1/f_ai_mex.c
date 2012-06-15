/*
 * MATLAB Compiler: 2.2
 * Date: Wed Apr 17 09:12:10 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "f_ai"
 */

#ifndef MLF_V2
#define MLF_V2 1
#endif

#include "libmatlb.h"
#include "f_ai.h"
#include "d_int.h"
#include "precise_step.h"

static mexFunctionTableEntry function_table[1]
  = { { "f_ai", mlxF_ai, 3, 1, &_local_function_table_f_ai } };

static _mexInitTermTableEntry init_term_table[1]
  = { { InitializeModule_f_ai, TerminateModule_f_ai } };

static _mex_information _mex_info
  = { 1, 1, function_table, 0, NULL, 0, NULL, 1, init_term_table };

/*
 * The function "Mprecise_step" is the MATLAB callback version of the
 * "precise_step" function from file "d:\M6\work\precise_step.m". It performs a
 * callback to MATLAB to run the "precise_step" function, and passes any
 * resulting output arguments back to its calling function.
 */
static mxArray * Mprecise_step(int nargout_, mxArray * inargs) {
    mxArray * out = mclGetUninitializedArray();
    mclFevalCallMATLAB(
      mclNVarargout(nargout_, 0, &out, NULL), "precise_step", inargs, NULL);
    return out;
}

/*
 * The function "Md_int" is the MATLAB callback version of the "d_int" function
 * from file "d:\M6\work\d_int.m". It performs a callback to MATLAB to run the
 * "d_int" function, and passes any resulting output arguments back to its
 * calling function.
 */
static mxArray * Md_int(int nargout_, mxArray * f, mxArray * int_region) {
    mxArray * out = mclGetUninitializedArray();
    mclFevalCallMATLAB(
      mclNVarargout(nargout_, 0, &out, NULL), "d_int", f, int_region, NULL);
    return out;
}

/*
 * The function "mexLibrary" is a Compiler-generated mex wrapper, suitable for
 * building a MEX-function. It initializes any persistent variables as well as
 * a function table for use by the feval function. It then calls the function
 * "mlxF_ai". Finally, it clears the feval table and exits.
 */
mex_information mexLibrary(void) {
    mclMexLibraryInit();
    return &_mex_info;
}

/*
 * The function "mlfPrecise_step" contains the normal interface for the
 * "precise_step" M-function from file "d:\M6\work\precise_step.m" (lines 0-0).
 * This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
mxArray * mlfPrecise_step(mxArray * inargs) {
    int nargout = 1;
    mxArray * out = mclGetUninitializedArray();
    mlfEnterNewContext(0, 1, inargs);
    out = Mprecise_step(nargout, inargs);
    mlfRestorePreviousContext(0, 1, inargs);
    return mlfReturnValue(out);
}

/*
 * The function "mlxPrecise_step" contains the feval interface for the
 * "precise_step" M-function from file "d:\M6\work\precise_step.m" (lines 0-0).
 * The feval function calls the implementation version of precise_step through
 * this function. This function processes any input arguments and passes them
 * to the implementation version of the function, appearing above.
 */
void mlxPrecise_step(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: precise_step Line: 1 Column"
            ": 1 The function \"precise_step\" was called with"
            " more than the declared number of outputs (1)."));
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: precise_step Line: 1 Column"
            ": 1 The function \"precise_step\" was called with"
            " more than the declared number of inputs (1)."));
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
    mplhs[0] = Mprecise_step(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "mlfD_int" contains the normal interface for the "d_int"
 * M-function from file "d:\M6\work\d_int.m" (lines 0-0). This function
 * processes any input arguments and passes them to the implementation version
 * of the function, appearing above.
 */
mxArray * mlfD_int(mxArray * f, mxArray * int_region) {
    int nargout = 1;
    mxArray * out = mclGetUninitializedArray();
    mlfEnterNewContext(0, 2, f, int_region);
    out = Md_int(nargout, f, int_region);
    mlfRestorePreviousContext(0, 2, f, int_region);
    return mlfReturnValue(out);
}

/*
 * The function "mlxD_int" contains the feval interface for the "d_int"
 * M-function from file "d:\M6\work\d_int.m" (lines 0-0). The feval function
 * calls the implementation version of d_int through this function. This
 * function processes any input arguments and passes them to the implementation
 * version of the function, appearing above.
 */
void mlxD_int(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[2];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: d_int Line: 1 Column: 1"
            " The function \"d_int\" was called with more "
            "than the declared number of outputs (1)."));
    }
    if (nrhs > 2) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: d_int Line: 1 Column: 1 The function \"d_int"
            "\" was called with more than the declared number of inputs (2)."));
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
    mplhs[0] = Md_int(nlhs, mprhs[0], mprhs[1]);
    mlfRestorePreviousContext(0, 2, mprhs[0], mprhs[1]);
    plhs[0] = mplhs[0];
}
