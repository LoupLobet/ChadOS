#include <c.h>
#include <libc.h>

int
main(int argc, char *argv[])
{
	char buf[1024] = {0};
	File *f;
#ifdef __OpenBSD__
	if (pledge("stdio rpath", nil) == -1)
		exit(1);
#endif
	if (argc == 2) {
		f = file();
		open(f, argv[1], OREAD);
		read(f, buf, sizeof(buf) - 1);
		write(stdout, buf, sizeof(buf) - 1);
		destroy(f);
	}
	return 0;
}
