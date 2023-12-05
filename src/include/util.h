#ifndef _UTIL_H_
#define _UTIL_H_

#include <c.h>

extern const char *_progname;

extern void	*ecalloc(ulong, ulong);
extern void	*emalloc(ulong);
extern void	*erealloc(void *, ulong);
extern void	 err(char *, ...);
extern void	 setprogname(const char *);
extern void	 warn(char *, ...);

#endif
