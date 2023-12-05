#include <c.h>
#define UNIX_C

#ifdef __OpenBSD__
#include <stdlib.h>

int
chadpledge(const char *promises, const char *execpromises)
{
	return pledge(promises, execpromises);
}
#endif

