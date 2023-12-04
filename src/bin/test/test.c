#include <c.h>
#include <libc.h>

int
main(int argc, char *argv[])
{
	char buf[1024] = {0};
	File *f;

	if (argc == 2) {
		f = file();
		open(f, argv[1], OREAD);
		read(f, buf, sizeof(buf) - 1);
		write(chadstdout, buf, sizeof(buf) - 1);
		close(f);
		destroy(f);
	}
	return 0;
}