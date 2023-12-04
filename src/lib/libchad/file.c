#include <c.h>
#define UNIX_C
#include <libc.h>

int
chadopen(File *f, void *p, int oflag)
{
	return f->open(f, p, oflag);
}

long
chadread(File *f, void *p, long n)
{
	return f->read(f, p, n);
}

long
chadwrite(File *f, void *p, long n)
{
	return f->write(f, p, n);
}

int
chadclose(File *f)
{
	return f->close(f);
}

int
chaddestroy(File *f)
{
	return f->destroy(f);
}
