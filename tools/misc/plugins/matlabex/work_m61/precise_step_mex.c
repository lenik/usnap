/*
 * MATLAB Compiler: 2.2
 * Date: Wed Apr 17 09:21:32 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "precise_step"
 */

#ifndef MLF_V2
#define MLF_V2 1
#endif

#include "libmatlb.h"
#include "precise_step.h"

static mexFunctionTableEntry function_table[1]
  = { { "precise_step", mlxPrecise_step, 1, 1,
        &_local_function_table_precise_step } };

static _mexInitTermTableEntry init_term_table[1]
  = { { InitializeModule_precise_step, TerminateModule_precise_step } };

static _mex_information _mex_info
  = { 1, 1, function_table, 0, NULL, 0, NULL, 1, init_term_table };

/*
 * The function "mexLibrary" is a Compiler-generated mex wrapper, suitable for
 * building a MEX-function. It initializes any persistent variables as well as
 * a function table for use by the feval function. It then calls the function
 * "mlxPrecise_step". Finally, it clears the feval table and exits.
 */
mex_information mexLibrary(void) {
    mclMexLibraryInit();
    return &_mex_info;
}
