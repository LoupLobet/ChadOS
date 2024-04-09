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
	if ((rd->buf = malloc(BUFF_SIZE)) == nil) {
		free(rd);
		return nil;
	}
	rd->buflen = 0;
}

long
rdread(Reader *rd, void *buf, long n)
{
	long nread;
	char *p;

	p = buf;

	do {
		/* refill the reader if empty */
		if (!rd->buflen) {
			if (!(rd->buflen = readn(rd->f, rd->buf, BUFF_SIZE))) {
				return nread;
			}
		}
		k = MIN(rd->buflen, n - nread);
		(void)memmove(p, rd->buf, k);
		nread += k;
		rd->buflen -= k;
	} while (k && nread < n);
}

long
readn(File *f, void *buf, long n)
{
	long k, nread;

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

	do {
		k = write(f, buf, n);
		nwrite += k;
	} while (k && nwrite < n)
	return nwrite;

}
