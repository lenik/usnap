/*
 * MATLAB Compiler: 2.2
 * Date: Wed Apr 17 09:12:27 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "f_bi"
 */
#include "f_bi.h"
#include "d_int.h"
#include "libmatlbm.h"
#include "precise_step.h"

static mxChar _array1_[126] = { 'R', 'u', 'n', '-', 't', 'i', 'm', 'e', ' ',
                                'E', 'r', 'r', 'o', 'r', ':', ' ', 'F', 'i',
                                'l', 'e', ':', ' ', 'f', '_', 'b', 'i', ' ',
                                'L', 'i', 'n', 'e', ':', ' ', '1', ' ', 'C',
                                'o', 'l', 'u', 'm', 'n', ':', ' ', '1', ' ',
                                'T', 'h', 'e', ' ', 'f', 'u', 'n', 'c', 't',
                                'i', 'o', 'n', ' ', '"', 'f', '_', 'b', 'i',
                                '"', ' ', 'w', 'a', 's', ' ', 'c', 'a', 'l',
                                'l', 'e', 'd', ' ', 'w', 'i', 't', 'h', ' ',
                                'm', 'o', 'r', 'e', ' ', 't', 'h', 'a', 'n',
                                ' ', 't', 'h', 'e', ' ', 'd', 'e', 'c', 'l',
                                'a', 'r', 'e', 'd', ' ', 'n', 'u', 'm', 'b',
                                'e', 'r', ' ', 'o', 'f', ' ', 'o', 'u', 't',
                                'p', 'u', 't', 's', ' ', '(', '1', ')', '.' };
static mxArray * _mxarray0_;

static mxChar _array3_[125] = { 'R', 'u', 'n', '-', 't', 'i', 'm', 'e', ' ',
                                'E', 'r', 'r', 'o', 'r', ':', ' ', 'F', 'i',
                                'l', 'e', ':', ' ', 'f', '_', 'b', 'i', ' ',
                                'L', 'i', 'n', 'e', ':', ' ', '1', ' ', 'C',
                                'o', 'l', 'u', 'm', 'n', ':', ' ', '1', ' ',
                                'T', 'h', 'e', ' ', 'f', 'u', 'n', 'c', 't',
                                'i', 'o', 'n', ' ', '"', 'f', '_', 'b', 'i',
                                '"', ' ', 'w', 'a', 's', ' ', 'c', 'a', 'l',
                                'l', 'e', 'd', ' ', 'w', 'i', 't', 'h', ' ',
                                'm', 'o', 'r', 'e', ' ', 't', 'h', 'a', 'n',
                                ' ', 't', 'h', 'e', ' ', 'd', 'e', 'c', 'l',
                                'a', 'r', 'e', 'd', ' ', 'n', 'u', 'm', 'b',
                                'e', 'r', ' ', 'o', 'f', ' ', 'i', 'n', 'p',
                                'u', 't', 's', ' ', '(', '3', ')', '.' };
static mxArray * _mxarray2_;
static mxArray * _mxarray4_;

static mxChar _array6_[3] = { 's', 'y', 'm' };
static mxArray * _mxarray5_;

static mxChar _array8_[1] = { 'x' };
static mxArray * _mxarray7_;
static mxArray * _mxarray9_;

static mxChar _array11_[4] = { 'b', 'a', 's', 'e' };
static mxArray * _mxarray10_;

static mxChar _array13_[9] = { 'f', '_', 'b', 'i', '_', 'f', 'u', 'n', 'c' };
static mxArray * _mxarray12_;

static mxChar _array15_[6] = { 'f', '_', 'b', 'i', '_', 'i' };
static mxArray * _mxarray14_;

static mxChar _array17_[6] = { 'f', '_', 'b', 'i', '_', 'T' };
static mxArray * _mxarray16_;

static mxChar _array19_[8] = { 'f', '_', 'b', 'i', '_', 'o', 'm', 'g' };
static mxArray * _mxarray18_;

static mxChar _array21_[13] = { 'f', '_', 'b', 'i', '_', 'f', 'u',
                                'n', 'c', 't', 'i', 'o', 'n' };
static mxArray * _mxarray20_;

void InitializeModule_f_bi(void) {
    _mxarray0_ = mclInitializeString(126, _array1_);
    _mxarray2_ = mclInitializeString(125, _array3_);
    _mxarray4_ = mclInitializeDouble(6.283185307179586);
    _mxarray5_ = mclInitializeString(3, _array6_);
    _mxarray7_ = mclInitializeString(1, _array8_);
    _mxarray9_ = mclInitializeDouble(2.0);
    _mxarray10_ = mclInitializeString(4, _array11_);
    _mxarray12_ = mclInitializeString(9, _array13_);
    _mxarray14_ = mclInitializeString(6, _array15_);
    _mxarray16_ = mclInitializeString(6, _array17_);
    _mxarray18_ = mclInitializeString(8, _array19_);
    _mxarray20_ = mclInitializeString(13, _array21_);
}

void TerminateModule_f_bi(void) {
    mxDestroyArray(_mxarray20_);
    mxDestroyArray(_mxarray18_);
    mxDestroyArray(_mxarray16_);
    mxDestroyArray(_mxarray14_);
    mxDestroyArray(_mxarray12_);
    mxDestroyArray(_mxarray10_);
    mxDestroyArray(_mxarray9_);
    mxDestroyArray(_mxarray7_);
    mxDestroyArray(_mxarray5_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mf_bi(int nargout_, mxArray * func, mxArray * i, mxArray * T);

_mexLocalFunctionTable _local_function_table_f_bi
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfF_bi" contains the normal interface for the "f_bi"
 * M-function from file "d:\M6\work\f_bi.m" (lines 1-18). This function
 * processes any input arguments and passes them to the implementation version
 * of the function, appearing above.
 */
mxArray * mlfF_bi(mxArray * func, mxArray * i, mxArray * T) {
    int nargout = 1;
    mxArray * out = mclGetUninitializedArray();
    mlfEnterNewContext(0, 3, func, i, T);
    out = Mf_bi(nargout, func, i, T);
    mlfRestorePreviousContext(0, 3, func, i, T);
    return mlfReturnValue(out);
}

/*
 * The function "mlxF_bi" contains the feval interface for the "f_bi"
 * M-function from file "d:\M6\work\f_bi.m" (lines 1-18). The feval function
 * calls the implementation version of f_bi through this function. This
 * function processes any input arguments and passes them to the implementation
 * version of the function, appearing above.
 */
void mlxF_bi(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[3];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(_mxarray0_);
    }
    if (nrhs > 3) {
        mlfError(_mxarray2_);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = mclGetUninitializedArray();
    }
    for (i = 0; i < 3 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 3; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(0, 3, mprhs[0], mprhs[1], mprhs[2]);
    mplhs[0] = Mf_bi(nlhs, mprhs[0], mprhs[1], mprhs[2]);
    mlfRestorePreviousContext(0, 3, mprhs[0], mprhs[1], mprhs[2]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mf_bi" is the implementation version of the "f_bi" M-function
 * from file "d:\M6\work\f_bi.m" (lines 1-18). It contains the actual compiled
 * code for that M-function. It is a static function and must only be called
 * from one of the interface functions, appearing below.
 */
/*
 * function out = f_bi(func, i, T)
 */
static mxArray * Mf_bi(int nargout_, mxArray * func, mxArray * i, mxArray * T) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_f_bi);
    mxArray * out = mclGetUninitializedArray();
    mxArray * ans = mclGetUninitializedArray();
    mxArray * int0 = NULL;
    mxArray * x = mclGetUninitializedArray();
    mxArray * sym = NULL;
    mxArray * omg = mclGetUninitializedArray();
    mclCopyArray(&func);
    mclCopyArray(&i);
    mclCopyArray(&T);
    /*
     * % f_bi      get fourier b[i] parameter from func specfied.
     *
     * omg = 2 * pi / T;
     */
    mlfAssign(&omg, mclMrdivide(_mxarray4_, mclVa(T, "T")));
    /*
     *
     * if isa(func, 'sym')
     */
    if (mlfTobool(mclVe(mlfIsa(mclVa(func, "func"), _mxarray5_)))) {
        /*
         * x = sym('x');
         */
        mlfAssign(&x, mclArrayRef1(mclVsv(sym, "sym"), _mxarray7_));
        /*
         * out = int(func * sin(i * omg * x), -T / 2, T / 2) * 2 / T;
         */
        mlfAssign(
          &out,
          mclMrdivide(
            mclMtimes(
              mclVe(
                mlfIndexRef(
                  mclVsv(int0, "int"),
                  "(?,?,?)",
                  mclMtimes(
                    mclVa(func, "func"),
                    mclVe(
                      mlfSin(
                        mclMtimes(
                          mclMtimes(mclVa(i, "i"), mclVv(omg, "omg")),
                          mclVv(x, "x"))))),
                  mclMrdivide(mclUminus(mclVa(T, "T")), _mxarray9_),
                  mclMrdivide(mclVa(T, "T"), _mxarray9_))),
              _mxarray9_),
            mclVa(T, "T")));
    /*
     * else
     */
    } else {
        /*
         * assignin('base', 'f_bi_func', func);
         */
        mclAssignAns(
          &ans,
          mlfAssignin(_mxarray10_, _mxarray12_, mclVa(func, "func"), NULL));
        /*
         * assignin('base', 'f_bi_i', i);
         */
        mclAssignAns(
          &ans, mlfAssignin(_mxarray10_, _mxarray14_, mclVa(i, "i"), NULL));
        /*
         * assignin('base', 'f_bi_T', T);
         */
        mclAssignAns(
          &ans, mlfAssignin(_mxarray10_, _mxarray16_, mclVa(T, "T"), NULL));
        /*
         * assignin('base', 'f_bi_omg', omg);
         */
        mclAssignAns(
          &ans, mlfAssignin(_mxarray10_, _mxarray18_, mclVv(omg, "omg"), NULL));
        /*
         *
         * out = d_int('f_bi_function', -T / 2 : precise_step : T / 2) * 2 / T;
         */
        mlfAssign(
          &out,
          mclMrdivide(
            mclMtimes(
              mclVe(
                mlfD_int(
                  _mxarray20_,
                  mlfColon(
                    mclMrdivide(mclUminus(mclVa(T, "T")), _mxarray9_),
                    mclVe(mlfPrecise_step(NULL)),
                    mclMrdivide(mclVa(T, "T"), _mxarray9_)))),
              _mxarray9_),
            mclVa(T, "T")));
    /*
     * end
     */
    }
    mclValidateOutput(out, 1, nargout_, "out", "f_bi");
    mxDestroyArray(omg);
    mxDestroyArray(sym);
    mxDestroyArray(x);
    mxDestroyArray(int0);
    mxDestroyArray(ans);
    mxDestroyArray(T);
    mxDestroyArray(i);
    mxDestroyArray(func);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return out;
    /*
     *
     */
}
