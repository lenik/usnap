/*
 * MATLAB Compiler: 2.2
 * Date: Wed Apr 17 09:21:32 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "precise_step"
 */
#include "precise_step.h"
#include "libmatlbm.h"

static mxChar _array1_[142] = { 'R', 'u', 'n', '-', 't', 'i', 'm', 'e', ' ',
                                'E', 'r', 'r', 'o', 'r', ':', ' ', 'F', 'i',
                                'l', 'e', ':', ' ', 'p', 'r', 'e', 'c', 'i',
                                's', 'e', '_', 's', 't', 'e', 'p', ' ', 'L',
                                'i', 'n', 'e', ':', ' ', '1', ' ', 'C', 'o',
                                'l', 'u', 'm', 'n', ':', ' ', '1', ' ', 'T',
                                'h', 'e', ' ', 'f', 'u', 'n', 'c', 't', 'i',
                                'o', 'n', ' ', '"', 'p', 'r', 'e', 'c', 'i',
                                's', 'e', '_', 's', 't', 'e', 'p', '"', ' ',
                                'w', 'a', 's', ' ', 'c', 'a', 'l', 'l', 'e',
                                'd', ' ', 'w', 'i', 't', 'h', ' ', 'm', 'o',
                                'r', 'e', ' ', 't', 'h', 'a', 'n', ' ', 't',
                                'h', 'e', ' ', 'd', 'e', 'c', 'l', 'a', 'r',
                                'e', 'd', ' ', 'n', 'u', 'm', 'b', 'e', 'r',
                                ' ', 'o', 'f', ' ', 'o', 'u', 't', 'p', 'u',
                                't', 's', ' ', '(', '1', ')', '.' };
static mxArray * _mxarray0_;

static mxChar _array3_[141] = { 'R', 'u', 'n', '-', 't', 'i', 'm', 'e', ' ',
                                'E', 'r', 'r', 'o', 'r', ':', ' ', 'F', 'i',
                                'l', 'e', ':', ' ', 'p', 'r', 'e', 'c', 'i',
                                's', 'e', '_', 's', 't', 'e', 'p', ' ', 'L',
                                'i', 'n', 'e', ':', ' ', '1', ' ', 'C', 'o',
                                'l', 'u', 'm', 'n', ':', ' ', '1', ' ', 'T',
                                'h', 'e', ' ', 'f', 'u', 'n', 'c', 't', 'i',
                                'o', 'n', ' ', '"', 'p', 'r', 'e', 'c', 'i',
                                's', 'e', '_', 's', 't', 'e', 'p', '"', ' ',
                                'w', 'a', 's', ' ', 'c', 'a', 'l', 'l', 'e',
                                'd', ' ', 'w', 'i', 't', 'h', ' ', 'm', 'o',
                                'r', 'e', ' ', 't', 'h', 'a', 'n', ' ', 't',
                                'h', 'e', ' ', 'd', 'e', 'c', 'l', 'a', 'r',
                                'e', 'd', ' ', 'n', 'u', 'm', 'b', 'e', 'r',
                                ' ', 'o', 'f', ' ', 'i', 'n', 'p', 'u', 't',
                                's', ' ', '(', '1', ')', '.' };
static mxArray * _mxarray2_;

static mxChar _array5_[18] = { 'F', 'O', 'R', 'C', 'E', '_', 'P', 'R', 'E',
                               'C', 'I', 'S', 'E', '_', 'S', 'T', 'E', 'P' };
static mxArray * _mxarray4_;
static mxArray * _mxarray6_;
static mxArray * _mxarray7_;

void InitializeModule_precise_step(void) {
    _mxarray0_ = mclInitializeString(142, _array1_);
    _mxarray2_ = mclInitializeString(141, _array3_);
    _mxarray4_ = mclInitializeString(18, _array5_);
    _mxarray6_ = mclInitializeDouble(1.0);
    _mxarray7_ = mclInitializeDouble(.0009);
}

void TerminateModule_precise_step(void) {
    mxDestroyArray(_mxarray7_);
    mxDestroyArray(_mxarray6_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mprecise_step(int nargout_, mxArray * inargs);

_mexLocalFunctionTable _local_function_table_precise_step
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfPrecise_step" contains the normal interface for the
 * "precise_step" M-function from file "d:\M6\work\precise_step.m" (lines
 * 1-12). This function processes any input arguments and passes them to the
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
 * "precise_step" M-function from file "d:\M6\work\precise_step.m" (lines
 * 1-12). The feval function calls the implementation version of precise_step
 * through this function. This function processes any input arguments and
 * passes them to the implementation version of the function, appearing above.
 */
void mlxPrecise_step(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
    mplhs[0] = Mprecise_step(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mprecise_step" is the implementation version of the
 * "precise_step" M-function from file "d:\M6\work\precise_step.m" (lines
 * 1-12). It contains the actual compiled code for that M-function. It is a
 * static function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function out = precise_step(inargs)
 */
static mxArray * Mprecise_step(int nargout_, mxArray * inargs) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_precise_step);
    mxArray * out = mclGetUninitializedArray();
    mclCopyArray(&inargs);
    /*
     * % precise_step  defines precise level for my own bussniss.
     * %
     * % out = precise_step
     * %   out always return .001 for current.
     *
     * if exist('FORCE_PRECISE_STEP') == 1
     */
    if (mclEqBool(mclVe(mlfExist(_mxarray4_, NULL)), _mxarray6_)) {
        /*
         * out = eval('FORCE_PRECISE_STEP');
         */
        mlfAssign(&out, mlfEval(mclValueVarargout(), _mxarray4_, NULL));
    /*
     * else
     */
    } else {
        /*
         * out = .0009;
         */
        mlfAssign(&out, _mxarray7_);
    /*
     * end
     */
    }
    mclValidateOutput(out, 1, nargout_, "out", "precise_step");
    mxDestroyArray(inargs);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return out;
}
