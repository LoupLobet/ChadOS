#include <c.h>
#include <libc.h>

int
main(int argc, char *argv[])
{
	Rune *r;
	char *s;

	r = strtorunes("4¥ ≈ 0$");
	if (r == nil) {
		puts("malloc");
		exit(1);
	}
	for (Rune *p = r; *p; p++) {
		printf("%x ", *p);
	}
	putchar('\n');

	s = runestostr(r);
	if (s == nil) {
		puts("malloc");
		exit(1);
	}

	for (char *p = s; *p; p++) {
		printf("%x ", *p);
	}
	putchar('\n');

	free(r);
	free(s);

	return 0;
}
