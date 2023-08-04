#include <c.h>
#include <utf.h>
#include <rune.h>

long
unicodelen(char *s)
{
	long n;
	Rune dr;
	uchar c;

	n = 0;
	for (;;) {
		c = *(uchar *)s;
		if (c < Asciimax) {
			if (!c)
				return n;
			s++;
		} else
			s += chartorune(&dr, s);
		n++;
	}
}

long
utflen(Rune *r)
{
	long n;
	char ds[4];

	n = 0;
	for (;;) {
		if (*r > Asciimax) {
			if (!*r)
				return n;
		} else
			n += runetochar(ds, r);
		r++;
	}
}
