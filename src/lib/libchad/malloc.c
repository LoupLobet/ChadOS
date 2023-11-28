#include <c.h>
#define UNIX
#include <libc.h>

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
