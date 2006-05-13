# Process this file with autoconf to produce a configure script.
AC_INIT(Common-C/C++ Programming Framework, 1.0, lenik@bodz.net, libcpf)
AC_CONFIG_SRCDIR([src/getopt.c])
AC_CONFIG_HEADER([config/config.h:config/config.h.in:config/config_def.h])
AC_CONFIG_AUX_DIR([extern])

AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([memory.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([src/Makefile])
AC_OUTPUT
