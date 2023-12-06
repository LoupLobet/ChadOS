#include <c.h>
#define UNIX_C

#ifdef __OpenBSD__
#include <unistd.h>

int
chadpledge(const char *promises, const char *execpromises)
{
	return pledge(promises, execpromises);
}
#endif

