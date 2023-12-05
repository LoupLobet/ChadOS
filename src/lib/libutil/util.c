#include <c.h>
#include <libc.h>

const char *_progname;

void *
ecalloc(ulong n, ulong size)
{
	void *p;

	if ((p = calloc(n, size)) == nil)
		err("calloc %ld", n * size);
	return p;
}

void *
emalloc(ulong size)
{
	void *p;

	if ((p = malloc(size)) == nil)
		err("malloc %ld", size);
	return p;
}

void
err(char *fmt, ...)
{
	/*
	va_list ap;

	va_start(ap, fmt);
	(void)fprintf(stderr, "%s: ", _progname);
	(void)vfprintf(stderr, fmt, ap);
	va_end(ap);
	fputc('\n', stderr);
	*/
	exit(1);
}

void
setprogname(const char *name)
{
	_progname = name;
}


void
warn(char *fmt, ...)
{
	/*
	va_list ap;

	va_start(ap, fmt);
	(void)fprintf(stderr, "%s: ", _progname);
	(void)vfprintf(stderr, fmt, ap);
	va_end(ap);
	fputc('\n', stderr);
	*/
}

