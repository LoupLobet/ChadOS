#include <c.h>
#define UNIX_C
#include <libc.h>

#include <stdlib.h>

void
chadexit(int status)
{
	exit(status);
}
