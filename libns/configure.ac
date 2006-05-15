#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(Network Service Fundamental Library, 1.0.0, lenik@bodz.net, libns)
AC_CONFIG_SRCDIR([src/libns.c])
AC_CONFIG_HEADER([config/config.h])
AC_CONFIG_AUX_DIR([extern])

AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_HEADER_STDC
AC_HEADER_DIRENT
AC_HEADER_TIME
AC_HEADER_SYS_WAIT
AC_CHECK_FUNCS([memset mkdir socket])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 test/Makefile
                 test/win32/Makefile])
AC_OUTPUT
