/*
 * MATLAB Compiler: 2.2
 * Date: Wed Apr 17 08:49:59 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "f_user1"
 */
#include "f_user1.h"
#include "libmatlbm.h"

static mxChar _array1_[132] = { 'R', 'u', 'n', '-', 't', 'i', 'm', 'e', ' ',
                                'E', 'r', 'r', 'o', 'r', ':', ' ', 'F', 'i',
                                'l', 'e', ':', ' ', 'f', '_', 'u', 's', 'e',
                                'r', '1', ' ', 'L', 'i', 'n', 'e', ':', ' ',
                                '1', ' ', 'C', 'o', 'l', 'u', 'm', 'n', ':',
                                ' ', '1', ' ', 'T', 'h', 'e', ' ', 'f', 'u',
                                'n', 'c', 't', 'i', 'o', 'n', ' ', '"', 'f',
                                '_', 'u', 's', 'e', 'r', '1', '"', ' ', 'w',
                                'a', 's', ' ', 'c', 'a', 'l', 'l', 'e', 'd',
                                ' ', 'w', 'i', 't', 'h', ' ', 'm', 'o', 'r',
                                'e', ' ', 't', 'h', 'a', 'n', ' ', 't', 'h',
                                'e', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'e',
                                'd', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ',
                                'o', 'f', ' ', 'o', 'u', 't', 'p', 'u', 't',
                                's', ' ', '(', '1', ')', '.' };
static mxArray * _mxarray0_;

static mxChar _array3_[131] = { 'R', 'u', 'n', '-', 't', 'i', 'm', 'e', ' ',
                                'E', 'r', 'r', 'o', 'r', ':', ' ', 'F', 'i',
                                'l', 'e', ':', ' ', 'f', '_', 'u', 's', 'e',
                                'r', '1', ' ', 'L', 'i', 'n', 'e', ':', ' ',
                                '1', ' ', 'C', 'o', 'l', 'u', 'm', 'n', ':',
                                ' ', '1', ' ', 'T', 'h', 'e', ' ', 'f', 'u',
                                'n', 'c', 't', 'i', 'o', 'n', ' ', '"', 'f',
                                '_', 'u', 's', 'e', 'r', '1', '"', ' ', 'w',
                                'a', 's', ' ', 'c', 'a', 'l', 'l', 'e', 'd',
                                ' ', 'w', 'i', 't', 'h', ' ', 'm', 'o', 'r',
                                'e', ' ', 't', 'h', 'a', 'n', ' ', 't', 'h',
                                'e', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'e',
                                'd', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ',
                                'o', 'f', ' ', 'i', 'n', 'p', 'u', 't', 's',
                                ' ', '(', '1', ')', '.' };
static mxArray * _mxarray2_;
static mxArray * _mxarray4_;
static mxArray * _mxarray5_;
static mxArray * _mxarray6_;
static mxArray * _mxarray7_;
static mxArray * _mxarray8_;
static mxArray * _mxarray9_;

void InitializeModule_f_user1(void) {
    _mxarray0_ = mclInitializeString(132, _array1_);
    _mxarray2_ = mclInitializeString(131, _array3_);
    _mxarray4_ = mclInitializeDouble(1.0);
    _mxarray5_ = mclInitializeDouble(-.2);
    _mxarray6_ = mclInitializeDouble(0.0);
    _mxarray7_ = mclInitializeDouble(3.0);
    _mxarray8_ = mclInitializeDouble(.5);
    _mxarray9_ = mclInitializeDouble(2.0);
}

void TerminateModule_f_user1(void) {
    mxDestroyArray(_mxarray9_);
    mxDestroyArray(_mxarray8_);
    mxDestroyArray(_mxarray7_);
    mxDestroyArray(_mxarray6_);
    mxDestroyArray(_mxarray5_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mf_user1(int nargout_, mxArray * x);

_mexLocalFunctionTable _local_function_table_f_user1
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfF_user1" contains the normal interface for the "f_user1"
 * M-function from file "d:\M6\work\f_user1.m" (lines 1-18). This function
 * processes any input arguments and passes them to the implementation version
 * of the function, appearing above.
 */
mxArray * mlfF_user1(mxArray * x) {
    int nargout = 1;
    mxArray * out = mclGetUninitializedArray();
    mlfEnterNewContext(0, 1, x);
    out = Mf_user1(nargout, x);
    mlfRestorePreviousContext(0, 1, x);
    return mlfReturnValue(out);
}

/*
 * The function "mlxF_user1" contains the feval interface for the "f_user1"
 * M-function from file "d:\M6\work\f_user1.m" (lines 1-18). The feval function
 * calls the implementation version of f_user1 through this function. This
 * function processes any input arguments and passes them to the implementation
 * version of the function, appearing above.
 */
void mlxF_user1(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
    mplhs[0] = Mf_user1(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mf_user1" is the implementation version of the "f_user1"
 * M-function from file "d:\M6\work\f_user1.m" (lines 1-18). It contains the
 * actual compiled code for that M-function. It is a static function and must
 * only be called from one of the interface functions, appearing below.
 */
/*
 * function out = f_user1(x)
 */
static mxArray * Mf_user1(int nargout_, mxArray * x) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_f_user1);
    mxArray * out = mclGetUninitializedArray();
    mxArray * fx = mclGetUninitializedArray();
    mxArray * Offset = mclGetUninitializedArray();
    mxArray * T = mclGetUninitializedArray();
    mclCopyArray(&x);
    /*
     * % user custom function 1: rectangle wave.
     * %
     * % out = f_user1(x)
     * %
     *
     * T = 1;
     */
    mlfAssign(&T, _mxarray4_);
    /*
     * Offset = -0.2;
     */
    mlfAssign(&Offset, _mxarray5_);
    /*
     *
     * fx = x + Offset;
     */
    mlfAssign(&fx, mclPlus(mclVa(x, "x"), mclVv(Offset, "Offset")));
    /*
     * fx = fx - floor(fx ./ T) .* T;
     */
    mlfAssign(
      &fx,
      mclMinus(
        mclVv(fx, "fx"),
        mclTimes(
          mclVe(mlfFloor(mclRdivide(mclVv(fx, "fx"), mclVv(T, "T")))),
          mclVv(T, "T"))));
    /*
     *
     * out = ...
     */
    mlfAssign(
      &out,
      mclPlus(
        mclPlus(
          mclTimes(
            _mxarray6_,
            mclLt(mclVv(fx, "fx"), mclMrdivide(mclVv(T, "T"), _mxarray7_))),
          mclTimes(
            _mxarray8_,
            mclAnd(
              mclGe(mclVv(fx, "fx"), mclMrdivide(mclVv(T, "T"), _mxarray7_)),
              mclLt(
                mclVv(fx, "fx"),
                mclMrdivide(
                  mclMtimes(mclVv(T, "T"), _mxarray9_), _mxarray7_))))),
        mclTimes(
          _mxarray4_,
          mclGe(
            mclVv(fx, "fx"),
            mclMrdivide(mclMtimes(mclVv(T, "T"), _mxarray9_), _mxarray7_)))));
    mclValidateOutput(out, 1, nargout_, "out", "f_user1");
    mxDestroyArray(T);
    mxDestroyArray(Offset);
    mxDestroyArray(fx);
    mxDestroyArray(x);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return out;
    /*
     * 0.00 .* (fx < (T / 3)) + ...
     * 0.50 .* (fx >= (T / 3) & fx < (T * 2 / 3)) + ...
     * 1.00 .* (fx >= (T * 2 / 3));
     *
     */
}
