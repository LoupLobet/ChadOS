#define UNIX
#include <c.h>

#include <stdlib.h> /* calloc(3) free(3) malloc(3) realloc(3) */

void *
chadcalloc(ulong n, ulong size)
{
	return calloc(n, size);
}

void
chadfree(void *p)
{
	free(p);
}

void *
chadmalloc(ulong size)
{
	return malloc(size);
}

void *
chadrealloc(void *p, ulong size)
{
	return realloc(p, size);
}
