#include <c.h>
#include <libc.h>

int
main(int argc, char *argv[])
{
	char s[] = "Be a Chad !\n";

	write(1, s, sizeof(s) - 1);
	return 0;
}
