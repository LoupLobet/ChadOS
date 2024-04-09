#include <c.h>
#include <libc.h>

#include <io.h>

int
main(int argc, char *argv[])
{
	long n;
	File *f;
	Reader *rd;
	char buf[10];

	if (argc == 2) {
		f = file();
		open(f, argv[1], OREAD);
		rd = rdopen(f);
		while ((n = rdread(rd, buf, sizeof(buf))) > 0) {
			write(stdout, buf, n);
		}
		rdclose(rd);
		destroy(f);
	}
	return 0;
}
