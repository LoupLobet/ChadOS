#define UNIX
#include <c.h>
#include <libc.h>
#include <fcntl.h>  /* fcntl(2) open(2) */
#include <stdio.h>  /* remove(3) */
#include <unistd.h> /* close(2) write(2) */

int
chadclose(int fd)
{
	return close(fd);
}

int
chadopen(char *path, int oflag)
{
	struct flock fl;
	int fd, mode;

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
		return -1;
	fd = open(path, mode);
	if (fd >= 0) {
		if (oflag&OCEXEC)
			fcntl(fd, F_SETFL, FD_CLOEXEC);
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
				if (fcntl(fd, F_SETLK, &fl) < 0) {
					close(fd);
					return -1;
				}
			} else if (oflag&OLOCKW)
				fcntl(fd, F_SETLK, &fl);
		}
	}
	return fd;
}

long
chadwrite(int fd, void *buf, long size)
{
	return write(fd, buf, size);
}
