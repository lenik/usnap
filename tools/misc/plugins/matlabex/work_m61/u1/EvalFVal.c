/*
 * MATLAB Compiler: 2.2
 * Date: Wed Apr 17 09:05:45 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "EvalFVal"
 */
#include "EvalFVal.h"
#include "libmatlbm.h"
#include "subs.h"

static mxChar _array1_[134] = { 'R', 'u', 'n', '-', 't', 'i', 'm', 'e', ' ',
                                'E', 'r', 'r', 'o', 'r', ':', ' ', 'F', 'i',
                                'l', 'e', ':', ' ', 'E', 'v', 'a', 'l', 'F',
                                'V', 'a', 'l', ' ', 'L', 'i', 'n', 'e', ':',
                                ' ', '1', ' ', 'C', 'o', 'l', 'u', 'm', 'n',
                                ':', ' ', '1', ' ', 'T', 'h', 'e', ' ', 'f',
                                'u', 'n', 'c', 't', 'i', 'o', 'n', ' ', '"',
                                'E', 'v', 'a', 'l', 'F', 'V', 'a', 'l', '"',
                                ' ', 'w', 'a', 's', ' ', 'c', 'a', 'l', 'l',
                                'e', 'd', ' ', 'w', 'i', 't', 'h', ' ', 'm',
                                'o', 'r', 'e', ' ', 't', 'h', 'a', 'n', ' ',
                                't', 'h', 'e', ' ', 'd', 'e', 'c', 'l', 'a',
                                'r', 'e', 'd', ' ', 'n', 'u', 'm', 'b', 'e',
                                'r', ' ', 'o', 'f', ' ', 'o', 'u', 't', 'p',
                                'u', 't', 's', ' ', '(', '1', ')', '.' };
static mxArray * _mxarray0_;

static mxChar _array3_[133] = { 'R', 'u', 'n', '-', 't', 'i', 'm', 'e', ' ',
                                'E', 'r', 'r', 'o', 'r', ':', ' ', 'F', 'i',
                                'l', 'e', ':', ' ', 'E', 'v', 'a', 'l', 'F',
                                'V', 'a', 'l', ' ', 'L', 'i', 'n', 'e', ':',
                                ' ', '1', ' ', 'C', 'o', 'l', 'u', 'm', 'n',
                                ':', ' ', '1', ' ', 'T', 'h', 'e', ' ', 'f',
                                'u', 'n', 'c', 't', 'i', 'o', 'n', ' ', '"',
                                'E', 'v', 'a', 'l', 'F', 'V', 'a', 'l', '"',
                                ' ', 'w', 'a', 's', ' ', 'c', 'a', 'l', 'l',
                                'e', 'd', ' ', 'w', 'i', 't', 'h', ' ', 'm',
                                'o', 'r', 'e', ' ', 't', 'h', 'a', 'n', ' ',
                                't', 'h', 'e', ' ', 'd', 'e', 'c', 'l', 'a',
                                'r', 'e', 'd', ' ', 'n', 'u', 'm', 'b', 'e',
                                'r', ' ', 'o', 'f', ' ', 'i', 'n', 'p', 'u',
                                't', 's', ' ', '(', '2', ')', '.' };
static mxArray * _mxarray2_;

static mxChar _array5_[3] = { 's', 'y', 'm' };
static mxArray * _mxarray4_;

static mxChar _array7_[1] = { 'x' };
static mxArray * _mxarray6_;

void InitializeModule_EvalFVal(void) {
    _mxarray0_ = mclInitializeString(134, _array1_);
    _mxarray2_ = mclInitializeString(133, _array3_);
    _mxarray4_ = mclInitializeString(3, _array5_);
    _mxarray6_ = mclInitializeString(1, _array7_);
}

void TerminateModule_EvalFVal(void) {
    mxDestroyArray(_mxarray6_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * MEvalFVal(int nargout_, mxArray * f, mxArray * fx);

_mexLocalFunctionTable _local_function_table_EvalFVal
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfEvalFVal" contains the normal interface for the "EvalFVal"
 * M-function from file "d:\M6\work\EvalFVal.m" (lines 1-11). This function
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
 * M-function from file "d:\M6\work\EvalFVal.m" (lines 1-11). The feval
 * function calls the implementation version of EvalFVal through this function.
 * This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxEvalFVal(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[2];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(_mxarray0_);
    }
    if (nrhs > 2) {
        mlfError(_mxarray2_);
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

/*
 * The function "MEvalFVal" is the implementation version of the "EvalFVal"
 * M-function from file "d:\M6\work\EvalFVal.m" (lines 1-11). It contains the
 * actual compiled code for that M-function. It is a static function and must
 * only be called from one of the interface functions, appearing below.
 */
/*
 * function out = EvalFVal(f, fx)
 */
static mxArray * MEvalFVal(int nargout_, mxArray * f, mxArray * fx) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_EvalFVal);
    mxArray * out = mclGetUninitializedArray();
    mclCopyArray(&f);
    mclCopyArray(&fx);
    /*
     * % EvalFVal  General Functions evaluation, not limited in built-in or symbolic functions.
     * %
     * % out = EvalFVal(function, parameters)
     *
     * if isa(f, 'sym')
     */
    if (mlfTobool(mclVe(mlfIsa(mclVa(f, "f"), _mxarray4_)))) {
        /*
         * out = subs(f, 'x', fx);
         */
        mlfAssign(
          &out, mlfSubs(mclVa(f, "f"), _mxarray6_, mclVa(fx, "fx"), NULL));
    /*
     * else
     */
    } else {
        /*
         * out = feval(f, fx);
         */
        mlfAssign(
          &out,
          mlfFeval(mclValueVarargout(), mclVa(f, "f"), mclVa(fx, "fx"), NULL));
    /*
     * end
     */
    }
    mclValidateOutput(out, 1, nargout_, "out", "EvalFVal");
    mxDestroyArray(fx);
    mxDestroyArray(f);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return out;
}
