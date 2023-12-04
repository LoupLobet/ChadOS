#include <c.h>
#define UNIX_C
#include <libc.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
unixclose(File *f)
{
	return close(*(int *)f->aux);
}

int
unixdestroy(File *f)
{
	free(f->aux);
	free(f);
	return 0;
}

File *
file(void)
{
	File *f;

	if ((f = malloc(sizeof(File))) == nil)
		return nil;
	if ((f->aux = malloc(sizeof(int))) == nil) {
		free(f);
		return nil;
	}
	f->type = UNIX_FILE;
	f->open = unixopen;
	f->read = unixread;
	f->write = unixwrite;
	f->close = unixclose;
	f->destroy = unixdestroy;
	return f;
}

int
unixopen(File *f, void *path, int oflag)
{
	struct flock fl;
	int *fp, mode;

	fp = (int *)f->aux;
	mode = oflag&3;
	if (oflag&ONONBLOCK) {
		mode |= O_NONBLOCK;
		oflag ^= ONONBLOCK;
	}
	if (oflag&OAPPEND) {
		mode |= O_APPEND;
		oflag ^= OAPPEND;
	}
	if (oflag&OTRUNC) {
		mode |= O_TRUNC;
		oflag ^= O_TRUNC;
	}

	if (oflag&(~(3|OCEXEC|ORCLOSE|OLOCK|OLOCKW)))
		return 1;
	*fp = open(path, mode);
	if (*fp >= 0) {
		if (oflag&OCEXEC)
			fcntl(*fp, F_SETFL, FD_CLOEXEC);
		if (oflag&ORCLOSE)
			remove(path);
		if (oflag&(OLOCK|OLOCKW)) {
			if ((oflag&3) == OREAD)
				fl.l_type = F_RDLCK;
			else
				fl.l_type = F_WRLCK;
			fl.l_whence = SEEK_SET;
			fl.l_start = 0;
			fl.l_len = 0;
			if (oflag&OLOCK) {
				if (fcntl(*fp, F_SETLK, &fl) < 0) {
					close(*fp);
					return 1;
				}
			} else if (oflag&OLOCKW)
				fcntl(*fp, F_SETLK, &fl);
		}
	}
	return 0;
}

long
unixread(File *f, void *buf, long n)
{
	return read(*(int *)f->aux, buf, n);
}

long
unixwrite(File *f, void *buf, long n)
{
	return write(*(int *)f->aux, buf, n);
}

static int stdinfd = STDIN_FILENO;
static int stdoutfd = STDOUT_FILENO;

static File _chadstdin = {
	.type = UNIX_FILE,
	.aux = &stdinfd,
	.close = nil,
	.destroy = nil,
	.open = nil,
	.read = unixread,
	.write = nil,
};

static File _chadstdout = {
	.type = UNIX_FILE,
	.aux = &stdoutfd,
	.close = nil,
	.destroy = nil,
	.open = nil,
	.read = nil,
	.write = unixwrite,
};

File *chadstdin = &_chadstdin;
File *chadstdout = &_chadstdout;
