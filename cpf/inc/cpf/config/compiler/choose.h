#ifndef _choose_umac_n_xWDeYOfGKzwlde_
#define _choose_umac_n_xWDeYOfGKzwlde_

#if defined(__Ca__)
#    define CPF_COMPILER "Calcium C*"
#    include "calcium.h"
#elif defined(__BORLANDC__)
#    define CPF_COMPILER "Borland C++"
#    include "borlandc.h"
#elif defined(__COMO__)
#    define CPF_COMPILER "Comeau C++"
#    include "como.h"
#elif defined(__DECCXX)
#    define CPF_COMPILER "Compaq Tru64 Unix cxx"
#    include "deccxx.h"
#elif defined(__DMC__)
#    define CPF_COMPILER "Digital Mars C++"
#    include "dmc.h"
#elif defined(__ghs)
#    define CPF_COMPILER "Greenhills C++"
#    include "ghs.h"
#elif defined(__GNUC__)
#    define CPF_COMPILER "GNU C++"
#    include "gnuc.h"
#elif defined(__HP_aCC)
#    define CPF_COMPILER "HP aCC"
#    include "hpacc.h"
#elif defined(__IBMCPP__)
#    define CPF_COMPILER "IBM Visual Age"
#    include "ibmcpp.h"
#elif defined (__ICC) || defined(__ICL) || defined(__ECC)
#    define CPF_COMPILER "Intel C++"
#    include "intel.h"
#elif defined (__INTEL_COMPILER)
#    define CPF_COMPILER "Intel C++"
#    include "intel.h"
#elif defined(__KCC)
#    define CPF_COMPILER "Kai C++"
#    include "kcc.h"
#elif defined (__MRC__) || defined(__SC__)
#    define CPF_COMPILER "MPW MrC++ or SC++"
#    include "mpw.h"
#elif defined(_MSC_VER)
#    define CPF_COMPILER "Microsoft (Visual) C/C++"
#    include "msc.h"
#elif defined(__MWERKS__)
#    define CPF_COMPILER "Metrowerks CodeWarrior"
#    include "mwerks.h"
#elif defined(__sgi)
#    define CPF_COMPILER "SGI MIPS pro C++"
#    include "sgi.h"
#elif defined(__SUNPRO_CC)
#    define CPF_COMPILER "Sun Workshop Compiler C++"
#    include "sunprocc.h"
#elif defined(__ANSIC__)
#    define CPF_COMPILER "ANSI C"
#    include "ansic.h"
#else
#    error "Unknown compiler"
#endif

#endif
