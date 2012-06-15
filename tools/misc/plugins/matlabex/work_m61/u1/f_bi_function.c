/*
 * MATLAB Compiler: 2.2
 * Date: Wed Apr 17 09:12:44 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "f_bi_function"
 */
#include "f_bi_function.h"
#include "libmatlbm.h"

static mxChar _array1_[144] = { 'R', 'u', 'n', '-', 't', 'i', 'm', 'e', ' ',
                                'E', 'r', 'r', 'o', 'r', ':', ' ', 'F', 'i',
                                'l', 'e', ':', ' ', 'f', '_', 'b', 'i', '_',
                                'f', 'u', 'n', 'c', 't', 'i', 'o', 'n', ' ',
                                'L', 'i', 'n', 'e', ':', ' ', '1', ' ', 'C',
                                'o', 'l', 'u', 'm', 'n', ':', ' ', '1', ' ',
                                'T', 'h', 'e', ' ', 'f', 'u', 'n', 'c', 't',
                                'i', 'o', 'n', ' ', '"', 'f', '_', 'b', 'i',
                                '_', 'f', 'u', 'n', 'c', 't', 'i', 'o', 'n',
                                '"', ' ', 'w', 'a', 's', ' ', 'c', 'a', 'l',
                                'l', 'e', 'd', ' ', 'w', 'i', 't', 'h', ' ',
                                'm', 'o', 'r', 'e', ' ', 't', 'h', 'a', 'n',
                                ' ', 't', 'h', 'e', ' ', 'd', 'e', 'c', 'l',
                                'a', 'r', 'e', 'd', ' ', 'n', 'u', 'm', 'b',
                                'e', 'r', ' ', 'o', 'f', ' ', 'o', 'u', 't',
                                'p', 'u', 't', 's', ' ', '(', '1', ')', '.' };
static mxArray * _mxarray0_;

static mxChar _array3_[143] = { 'R', 'u', 'n', '-', 't', 'i', 'm', 'e', ' ',
                                'E', 'r', 'r', 'o', 'r', ':', ' ', 'F', 'i',
                                'l', 'e', ':', ' ', 'f', '_', 'b', 'i', '_',
                                'f', 'u', 'n', 'c', 't', 'i', 'o', 'n', ' ',
                                'L', 'i', 'n', 'e', ':', ' ', '1', ' ', 'C',
                                'o', 'l', 'u', 'm', 'n', ':', ' ', '1', ' ',
                                'T', 'h', 'e', ' ', 'f', 'u', 'n', 'c', 't',
                                'i', 'o', 'n', ' ', '"', 'f', '_', 'b', 'i',
                                '_', 'f', 'u', 'n', 'c', 't', 'i', 'o', 'n',
                                '"', ' ', 'w', 'a', 's', ' ', 'c', 'a', 'l',
                                'l', 'e', 'd', ' ', 'w', 'i', 't', 'h', ' ',
                                'm', 'o', 'r', 'e', ' ', 't', 'h', 'a', 'n',
                                ' ', 't', 'h', 'e', ' ', 'd', 'e', 'c', 'l',
                                'a', 'r', 'e', 'd', ' ', 'n', 'u', 'm', 'b',
                                'e', 'r', ' ', 'o', 'f', ' ', 'i', 'n', 'p',
                                'u', 't', 's', ' ', '(', '1', ')', '.' };
static mxArray * _mxarray2_;

static mxChar _array5_[4] = { 'b', 'a', 's', 'e' };
static mxArray * _mxarray4_;

static mxChar _array7_[9] = { 'f', '_', 'b', 'i', '_', 'f', 'u', 'n', 'c' };
static mxArray * _mxarray6_;

static mxChar _array9_[6] = { 'f', '_', 'b', 'i', '_', 'i' };
static mxArray * _mxarray8_;

static mxChar _array11_[6] = { 'f', '_', 'b', 'i', '_', 'T' };
static mxArray * _mxarray10_;

static mxChar _array13_[8] = { 'f', '_', 'b', 'i', '_', 'o', 'm', 'g' };
static mxArray * _mxarray12_;

void InitializeModule_f_bi_function(void) {
    _mxarray0_ = mclInitializeString(144, _array1_);
    _mxarray2_ = mclInitializeString(143, _array3_);
    _mxarray4_ = mclInitializeString(4, _array5_);
    _mxarray6_ = mclInitializeString(9, _array7_);
    _mxarray8_ = mclInitializeString(6, _array9_);
    _mxarray10_ = mclInitializeString(6, _array11_);
    _mxarray12_ = mclInitializeString(8, _array13_);
}

void TerminateModule_f_bi_function(void) {
    mxDestroyArray(_mxarray12_);
    mxDestroyArray(_mxarray10_);
    mxDestroyArray(_mxarray8_);
    mxDestroyArray(_mxarray6_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mf_bi_function(int nargout_, mxArray * x);

_mexLocalFunctionTable _local_function_table_f_bi_function
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfF_bi_function" contains the normal interface for the
 * "f_bi_function" M-function from file "d:\M6\work\f_bi_function.m" (lines
 * 1-8). This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
mxArray * mlfF_bi_function(mxArray * x) {
    int nargout = 1;
    mxArray * out = mclGetUninitializedArray();
    mlfEnterNewContext(0, 1, x);
    out = Mf_bi_function(nargout, x);
    mlfRestorePreviousContext(0, 1, x);
    return mlfReturnValue(out);
}

/*
 * The function "mlxF_bi_function" contains the feval interface for the
 * "f_bi_function" M-function from file "d:\M6\work\f_bi_function.m" (lines
 * 1-8). The feval function calls the implementation version of f_bi_function
 * through this function. This function processes any input arguments and
 * passes them to the implementation version of the function, appearing above.
 */
void mlxF_bi_function(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(_mxarray0_);
    }
    if (nrhs > 1) {
        mlfError(_mxarray2_);
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
    mplhs[0] = Mf_bi_function(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mf_bi_function" is the implementation version of the
 * "f_bi_function" M-function from file "d:\M6\work\f_bi_function.m" (lines
 * 1-8). It contains the actual compiled code for that M-function. It is a
 * static function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function out = f_bi_function(x)
 */
static mxArray * Mf_bi_function(int nargout_, mxArray * x) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_f_bi_function);
    mxArray * out = mclGetUninitializedArray();
    mxArray * omg = mclGetUninitializedArray();
    mxArray * T = mclGetUninitializedArray();
    mxArray * i = mclGetUninitializedArray();
    mxArray * func = mclGetUninitializedArray();
    mclCopyArray(&x);
    /*
     * func = evalin('base', 'f_bi_func');
     */
    mlfAssign(
      &func, mlfNEvalin(0, mclValueVarargout(), _mxarray4_, _mxarray6_));
    /*
     * i = evalin('base', 'f_bi_i');
     */
    mlfAssign(&i, mlfNEvalin(0, mclValueVarargout(), _mxarray4_, _mxarray8_));
    /*
     * T = evalin('base', 'f_bi_T');
     */
    mlfAssign(&T, mlfNEvalin(0, mclValueVarargout(), _mxarray4_, _mxarray10_));
    /*
     * omg = evalin('base', 'f_bi_omg');
     */
    mlfAssign(
      &omg, mlfNEvalin(0, mclValueVarargout(), _mxarray4_, _mxarray12_));
    /*
     *
     * out = feval(func, x) * sin(i * omg * x);
     */
    mlfAssign(
      &out,
      mclMtimes(
        mclVe(
          mlfFeval(
            mclValueVarargout(), mclVv(func, "func"), mclVa(x, "x"), NULL)),
        mclVe(
          mlfSin(
            mclMtimes(
              mclMtimes(mclVv(i, "i"), mclVv(omg, "omg")), mclVa(x, "x"))))));
    mclValidateOutput(out, 1, nargout_, "out", "f_bi_function");
    mxDestroyArray(func);
    mxDestroyArray(i);
    mxDestroyArray(T);
    mxDestroyArray(omg);
    mxDestroyArray(x);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return out;
    /*
     *
     */
}
