/*
 * MATLAB Compiler: 2.2
 * Date: Wed Apr 17 09:07:45 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "d_int"
 */
#include "d_int.h"
#include "EvalFVal.h"
#include "libmatlbm.h"

static mxChar _array1_[128] = { 'R', 'u', 'n', '-', 't', 'i', 'm', 'e', ' ',
                                'E', 'r', 'r', 'o', 'r', ':', ' ', 'F', 'i',
                                'l', 'e', ':', ' ', 'd', '_', 'i', 'n', 't',
                                ' ', 'L', 'i', 'n', 'e', ':', ' ', '1', ' ',
                                'C', 'o', 'l', 'u', 'm', 'n', ':', ' ', '1',
                                ' ', 'T', 'h', 'e', ' ', 'f', 'u', 'n', 'c',
                                't', 'i', 'o', 'n', ' ', '"', 'd', '_', 'i',
                                'n', 't', '"', ' ', 'w', 'a', 's', ' ', 'c',
                                'a', 'l', 'l', 'e', 'd', ' ', 'w', 'i', 't',
                                'h', ' ', 'm', 'o', 'r', 'e', ' ', 't', 'h',
                                'a', 'n', ' ', 't', 'h', 'e', ' ', 'd', 'e',
                                'c', 'l', 'a', 'r', 'e', 'd', ' ', 'n', 'u',
                                'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'o',
                                'u', 't', 'p', 'u', 't', 's', ' ', '(', '1',
                                ')', '.' };
static mxArray * _mxarray0_;

static mxChar _array3_[127] = { 'R', 'u', 'n', '-', 't', 'i', 'm', 'e', ' ',
                                'E', 'r', 'r', 'o', 'r', ':', ' ', 'F', 'i',
                                'l', 'e', ':', ' ', 'd', '_', 'i', 'n', 't',
                                ' ', 'L', 'i', 'n', 'e', ':', ' ', '1', ' ',
                                'C', 'o', 'l', 'u', 'm', 'n', ':', ' ', '1',
                                ' ', 'T', 'h', 'e', ' ', 'f', 'u', 'n', 'c',
                                't', 'i', 'o', 'n', ' ', '"', 'd', '_', 'i',
                                'n', 't', '"', ' ', 'w', 'a', 's', ' ', 'c',
                                'a', 'l', 'l', 'e', 'd', ' ', 'w', 'i', 't',
                                'h', ' ', 'm', 'o', 'r', 'e', ' ', 't', 'h',
                                'a', 'n', ' ', 't', 'h', 'e', ' ', 'd', 'e',
                                'c', 'l', 'a', 'r', 'e', 'd', ' ', 'n', 'u',
                                'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'i',
                                'n', 'p', 'u', 't', 's', ' ', '(', '2', ')',
                                '.' };
static mxArray * _mxarray2_;
static mxArray * _mxarray4_;
static mxArray * _mxarray5_;

void InitializeModule_d_int(void) {
    _mxarray0_ = mclInitializeString(128, _array1_);
    _mxarray2_ = mclInitializeString(127, _array3_);
    _mxarray4_ = mclInitializeDoubleVector(0, 0, (double *)NULL);
    _mxarray5_ = mclInitializeDouble(0.0);
}

void TerminateModule_d_int(void) {
    mxDestroyArray(_mxarray5_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Md_int(int nargout_, mxArray * f, mxArray * int_region);

_mexLocalFunctionTable _local_function_table_d_int
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfD_int" contains the normal interface for the "d_int"
 * M-function from file "d:\M6\work\d_int.m" (lines 1-24). This function
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
 * M-function from file "d:\M6\work\d_int.m" (lines 1-24). The feval function
 * calls the implementation version of d_int through this function. This
 * function processes any input arguments and passes them to the implementation
 * version of the function, appearing above.
 */
void mlxD_int(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
    mplhs[0] = Md_int(nlhs, mprhs[0], mprhs[1]);
    mlfRestorePreviousContext(0, 2, mprhs[0], mprhs[1]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Md_int" is the implementation version of the "d_int"
 * M-function from file "d:\M6\work\d_int.m" (lines 1-24). It contains the
 * actual compiled code for that M-function. It is a static function and must
 * only be called from one of the interface functions, appearing below.
 */
/*
 * function out = d_int(f, int_region)
 */
static mxArray * Md_int(int nargout_, mxArray * f, mxArray * int_region) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_d_int);
    mxArray * out = mclGetUninitializedArray();
    mxArray * C_i = mclGetUninitializedArray();
    mxArray * Delta_C = mclGetUninitializedArray();
    mxArray * Last_F = mclGetUninitializedArray();
    mxArray * R_i = mclGetUninitializedArray();
    mxArray * Columns = mclGetUninitializedArray();
    mxArray * Rows = mclGetUninitializedArray();
    mxArray * RegionSize = mclGetUninitializedArray();
    mclCopyArray(&f);
    mclCopyArray(&int_region);
    /*
     * % Discrete Integration
     * %
     * % out = d_int(Function_desc, Integration_region)
     * %   Function_desc: specify function name, for EVAL use.
     * %   Integration_region: for linear discrete array integration,
     * %       this parameter can be as syntax as [LBOUND:UBOUND]
     * %       for other type, it may be LBOUND:step:UBOUND
     *
     * RegionSize = size(int_region);
     */
    mlfAssign(
      &RegionSize,
      mlfSize(mclValueVarargout(), mclVa(int_region, "int_region"), NULL));
    /*
     * Rows = RegionSize(1);
     */
    mlfAssign(&Rows, mclIntArrayRef1(mclVsv(RegionSize, "RegionSize"), 1));
    /*
     * Columns = RegionSize(2);
     */
    mlfAssign(&Columns, mclIntArrayRef1(mclVsv(RegionSize, "RegionSize"), 2));
    /*
     *
     * for R_i = 1:Rows,
     */
    {
        int v_ = mclForIntStart(1);
        int e_ = mclForIntEnd(mclVv(Rows, "Rows"));
        if (v_ > e_) {
            mlfAssign(&R_i, _mxarray4_);
        } else {
            /*
             * Last_F = EvalFVal(f, int_region(R_i, 1));
             * out(R_i) = 0;
             * Delta_C = diff(int_region(R_i, :));
             * for C_i = 2:Columns,
             * out(R_i) = out(R_i) + Last_F * Delta_C(C_i - 1);
             * Last_F = EvalFVal(f, int_region(R_i, C_i));
             * end
             * end
             */
            for (; ; ) {
                mlfAssign(
                  &Last_F,
                  mlfEvalFVal(
                    mclVa(f, "f"),
                    mclVe(
                      mclIntArrayRef2(
                        mclVsa(int_region, "int_region"), v_, 1))));
                mclIntArrayAssign1(&out, _mxarray5_, v_);
                mlfAssign(
                  &Delta_C,
                  mlfDiff(
                    mclVe(
                      mclArrayRef2(
                        mclVsa(int_region, "int_region"),
                        mlfScalar(v_),
                        mlfCreateColonIndex())),
                    NULL,
                    NULL));
                {
                    int v_0 = mclForIntStart(2);
                    int e_0 = mclForIntEnd(mclVv(Columns, "Columns"));
                    if (v_0 > e_0) {
                        mlfAssign(&C_i, _mxarray4_);
                    } else {
                        for (; ; ) {
                            mclIntArrayAssign1(
                              &out,
                              mclPlus(
                                mclVe(mclIntArrayRef1(mclVsv(out, "out"), v_)),
                                mclMtimes(
                                  mclVv(Last_F, "Last_F"),
                                  mclVe(
                                    mclIntArrayRef1(
                                      mclVsv(Delta_C, "Delta_C"), v_0 - 1)))),
                              v_);
                            mlfAssign(
                              &Last_F,
                              mlfEvalFVal(
                                mclVa(f, "f"),
                                mclVe(
                                  mclIntArrayRef2(
                                    mclVsa(int_region, "int_region"),
                                    v_,
                                    v_0))));
                            if (v_0 == e_0) {
                                break;
                            }
                            ++v_0;
                        }
                        mlfAssign(&C_i, mlfScalar(v_0));
                    }
                }
                if (v_ == e_) {
                    break;
                }
                ++v_;
            }
            mlfAssign(&R_i, mlfScalar(v_));
        }
    }
    mclValidateOutput(out, 1, nargout_, "out", "d_int");
    mxDestroyArray(RegionSize);
    mxDestroyArray(Rows);
    mxDestroyArray(Columns);
    mxDestroyArray(R_i);
    mxDestroyArray(Last_F);
    mxDestroyArray(Delta_C);
    mxDestroyArray(C_i);
    mxDestroyArray(int_region);
    mxDestroyArray(f);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return out;
    /*
     *
     */
}
