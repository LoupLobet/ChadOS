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
 * C99
 */

#include <stdarg.h>

/*
 * OS specific
 */

#include <rune.h>
#include <utf.h>
#include <util.h>

extern void	 chadexit(int);

#ifndef UNIX_C
#define exit chadexit
#endif

/*
 * OpenBSD only
 */

#ifdef __OpenBSD__
#include <pledge.h>
#endif

/*
 * malloc
 */

extern void	*chadcalloc(ulong, ulong);
extern void	 chadfree(void *);
extern void	*chadmalloc(ulong);
extern void	*chadrealloc(void *, ulong);

#ifndef UNIX_C
#define calloc  chadcalloc
#define free    chadfree
#define malloc	chadmalloc
#define realloc chadrealloc
#endif

/*
 * File
 */

typedef struct file {
	uint type;
	void *aux;
	long esize;
	int  (*close)(struct file *);
	int  (*destroy)(struct file *);
	int  (*open)(struct file *, void *, int);
	long (*read)(struct file *, void *, long);
	long (*write)(struct file *, void *, long);
} File;


extern int	 chadclose(File *);
extern int	 chaddestroy(File *);
extern int	 chadopen(File *, void *, int);
extern long	 chadread(File *, void *, long);
extern long	 chadwrite(File *, void *, long);

#ifndef UNIX_C
#define close   chadclose
#define destroy chaddestroy
#define open    chadopen
#define read    chadread
#define write   chadwrite
#endif

/*
 * file types
 */

enum {
	UNIX_FILE,
	MAX_OS_FILE_TYPE,
};

/* unix file */

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

extern int	 unixclose(File *);
extern int	 unixdestroy(File *);
extern File	*file(void);
extern int	 unixopen(File *, void *, int);
extern long	 unixread(File *, void *, long);
extern long	 unixwrite(File *, void *, long);

extern File *chadstdin;
extern File *chadstdout;
extern File *chadstderr;

#ifndef UNIX_C
#define stdin  chadstdin
#define stdout chadstdout
#define stderr chadstderr
#endif

/*
 * string
 */

extern void	*chadmemcpy(void *, void *, long);
extern void	*chadmemmove(void *, void *, long);
extern void	*chadmemchr(const void *, int , long);
extern int	 chadmemcmp(void *, void *, long);
extern void	*chadmemset(void *, int , long);
extern char	*chadstrcat(char *, char *);
extern long	 chadstrlcat(char *, char *, long);
extern char	*chadstrncat(char *, char *, long);
extern char	*chadstrchr(char *, int);
extern char	*chadstrrchr(char *, int);
extern int	 chadstrcmp(char *, char *);
extern int	 chadstrncmp(char *, char *, long);
extern char	*chadstrcpy(char *, char *);
extern long	 chadstrlcpy(char *, char *, long);
extern char	*chadstrncpy(char *, char *, long);
extern long	 chadstrlen(char *);
extern long	 chadstrnlen(char *, long);
extern long	 chadstrspn(char *, char *);
extern long	 chadstrcspn(char *, char *);
extern char	*chadstrpbrk(char *, char *);
extern char	*chadstrstr(char *, char *);
extern char	*chadstrtok(char *, char *);
extern char	*chadstrdup(char *);

#ifndef UNIX_C
#define memcpy chadmemcpy
#define memmove chadmemmove
#define memchr  chadmemchr
#define memcmp  chadmemcmp
#define memset  chadmemset
#define strcat  chadstrcat
#define strlcat chadstrlcat
#define strncat chadstrncat
#define strchr  chadstrchr
#define strrchr chadstrrchr
#define strcmp  chadstrcmp
#define strncmp chadstrncmp
#define strcpy  chadstrcpy
#define strlcpy chadstrlcpy
#define strncpy chadstrncpy
#define strlen  chadstrlen
#define strnlen chadstrnlen
#define strspn  chadstrspn
#define strcspn chadstrcspn
#define strpbrk chadstrpbrk
#define strstr  chadstrstr
#define strtok  chadstrtok
#define strdup  chadstrdup
#endif

#endif
