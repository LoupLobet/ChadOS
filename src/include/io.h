#ifndef _IO_H_
#define _IO_H_

#include <c.h>

#define BUFF_SIZE 4096

typedef struct {
	File *f;
	long buflen;
	char *buf;
	char *bob;
} Reader;

extern void	 rdclose(Reader *);
extern Reader	*rdopen(File *);
extern long	 rdread(Reader *, void *, long);
extern long	 rdwrite(Reader *, void *, long);
extern long	 readn(File *, void *, long);
extern long	 writen(File *, void *, long);

#endif
