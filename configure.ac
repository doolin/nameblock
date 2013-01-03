#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([blocking], [1.0], [david.doolin@gmail.com])
AM_INIT_AUTOMAKE([foreign])
AC_PROG_RANLIB
AM_PATH_CPPUNIT(1.12.1)
AC_CONFIG_SRCDIR([src/objects.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC


# Checks for libraries.

# FIXME: Replace `main' with a function in `-lm':
AC_CHECK_LIB([m], [main])

# FIXME: Replace `main' with a function in `-lpthread':
AC_CHECK_LIB([pthread], [main])

# FIXME: Replace `main' with a function in `-lsqlite3':
AC_CHECK_LIB([sqlite3], [main])

# FIXME: Replace `main' with a function in `-lcppunit':
AC_CHECK_LIB([cppunit], [main])

AC_LANG_PUSH([C++])
CPPFLAGS=-I/opt/local/include
LDFLAGS=-L/opt/local/lib
# FIXME: Replace `main' with a function in `-lyaml':
AC_CHECK_LIB([yaml], [yaml_parser_parse_document_content])

# FIXME: Replace `main' with a function in `-lyaml-cpp':
AC_CHECK_LIB([yaml-cpp], [main])

dnl AC_CHECK_HEADER(yaml.h, [], [], [/opt/local/include])
AC_CHECK_HEADER(yaml.h, [], [AC_MSG_WARN([Couldn't find or include yaml.h])], [])

dnl # Look for the yaml-cpp header file.  If it isn't found, terminate.
dnl AC_CHECK_HEADER(yaml-cpp/yaml.h, [], [AC_MSG_ERROR([Couldn't find or include yaml.h])], /opt/local/include)

# Checks for header files.
AC_CHECK_HEADERS([string.h unistd.h getopt.h])


# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset sqrt])

AC_CONFIG_FILES([Makefile
                 test/Makefile
                 src/Makefile])
AC_OUTPUT
