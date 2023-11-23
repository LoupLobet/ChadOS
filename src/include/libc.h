#ifndef _LIBC_H_
#define _LIBC_H_ 1

#if __STDC_VERSION__ != 199901L
	#error "Host system must provide C99"
#endif

#if defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
#else
	#error "Host system must be POSIX"
#endif

/*
 * ANSI C(99) Standard Library
 */
#include <assert.h>
#include <complex.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * POSIX Library
 */

#include <dirent.h>

/*
 * OS libc
 */
#include <rune.h>
#include <utf.h>

#endif
