#include <c.h>
#include <libc.h>
#include <io.h>

void
rdclose(Reader *rd)
{
	free(rd->buf);
	free(rd);
}

Reader *
rdopen(File *f)
{
	Reader *rd;

	if ((rd = malloc(sizeof(Reader))) == nil)
		return nil;
	if ((rd->buf = malloc(BUFF_SIZE * sizeof(f->esize))) == nil) {
		free(rd);
		return nil;
	}
	rd->buflen = 0;
	rd->bob = rd->buf;
	rd->f = f;
	return rd;
}

long
rdread(Reader *rd, void *buf, long n)
{
	long k, nread;
	char *p;

	p = buf;
	nread = 0;
	do {
		/* refill the reader if empty */
		if (!rd->buflen) {
			if (!(rd->buflen = readn(rd->f, rd->buf, BUFF_SIZE))) {
				return nread;
			}
			rd->bob = rd->buf;
		}
		k = MIN(rd->buflen, n - nread);
		(void)memmove(p + nread * rd->f->esize, rd->bob, k * rd->f->esize);
		nread += k;
		rd->bob += k * rd->f->esize;
		rd->buflen -= k;
	} while (k && nread < n);
	return nread;
}

long
readn(File *f, void *buf, long n)
{
	long k, nread;

	nread = 0;
	do {
		k = read(f, buf, n);
		nread += k;
	} while (k && nread < n);
	return nread;
}

long
writen(File *f, void *buf, long n)
{
	long k, nwrite;

	nwrite = 0;
	do {
		k = write(f, buf, n);
		nwrite += k;
	} while (k && nwrite < n);
	return nwrite;

}
