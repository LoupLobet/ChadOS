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
 * OS specific
 */

#include <rune.h>
#include <utf.h>

/*
 * malloc
 */
extern void	*chadcalloc(ulong, ulong);
extern void	 chadfree(void *);
extern void	*chadmalloc(ulong);
extern void	*chadrealloc(void *, ulong);

#ifndef UNIX
#define calloc  chadcalloc
#define free    chadfree
#define malloc	chadmalloc
#define realloc chadrealloc
#endif

/*
 * io
 */

/* oflag */
#define OREAD     0    /* read */
#define OWRITE    1    /* write */
#define ORW       2    /* read and write */
#define OEXEC     3    /* exec */
#define ONONBLOCK 8    /* non-blocking */
#define OAPPEND   16   /* open to the enf of file */
#define OTRUNC    32   /* truncate file on open */
#define OCEXEC    64   /* close file on exec */
#define ORCLOSE   128  /* remove after closing */
#define OLOCK     256  /* lock after opening, close if lock can't be set */
#define OLOCKW    512  /* lock after opening, wait if lock can't be set */

extern int	 chadclose(int);
extern int	 chadopen(char *, int);
extern long	 chadwrite(int, void *, long);

#ifndef UNIX
#define close chadclose
#define open  chadopen
#define write chadwrite
#endif

#endif
