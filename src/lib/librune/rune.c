#include <c.h>
#include <libc.h>


static int	 utfbyte(uchar *, uchar);

enum
{
	/* utf byte prefixes */
	Bytex = 0x80,    /* 10.. .... */
	Byte1 = 0x00,    /* 0... .... */
	Byte2 = 0xC0,    /* 110. .... */
	Byte3 = 0xE0,    /* 1110 .... */
	Byte4 = 0xF0,    /* 1111 0... */

	/* rune ranges */
	Rune1 = 0x7F,      /* 0000 0000 0000 0000 0111 1111 */
	Rune2 = 0x7FF,     /* 0000 0000 0000 0111 1111 1111 */
	Rune3 = 0xFFFF,    /* 0000 0000 1111 1111 1111 1111 */
	Rune4 = 0x3FFFFF,  /* 0011 1111 1111 1111 1111 1111 */

	/* utf byte value masks */
	Vx = 0x3F,   /* 0011 1111 */
	V1 = 0x7F,   /* 0111 1111 */
	V2 = 0x1F,   /* 0001 1111 */
	V3 = 0x0F,   /* 0000 1111 */
	V4 = 0x07,   /* 0000 0111 */
};

int
chartorune(Rune *r, char *s)
{
	int i, n;
	uchar c;

	if (!(n = utfbyte(&c, *(uchar *)s)))
		goto badrune;
	*r = c;
	for (i = 1; i < n; i++) {
		if (!*(s + i) || utfbyte(&c, *(uchar *)(s + i)))
			goto badrune;
		*r = *r<<6;
		*r += c;
	}
	return n;
badrune:
	*r = Badrune;
	return 1;
}

Rune *
rstrcat(Rune *s1, Rune *s2)
{
	Rune *p;

	p = s1;
	while (*s1)
		s1++;
	while ((*s1++ = *s2++));
	return p;
}

Rune *
rstrchr(Rune *s, Rune r)
{
	while (*s++ != r);
	return s-1;
}

int
rstrcmp(Rune *s1, Rune *s2)
{
	for (;;) {
		if (*s1 != *s2) {
			if (*s1 > *s2)
				return 1;
			return -1;
		}
		if (!*s1)
			return 0;
		s1++;
		s2++;
	}
}

Rune *
rstrcpy(Rune *s1, Rune *s2)
{
	Rune *p;

	p = s1;
	while ((*s1++ = *s2++));
	return p;
}

Rune *
rstrdup(Rune *s)
{
	Rune *p;

	if ((p = malloc(sizeof(Rune) * (rstrlen(s) + 1))) == nil)
		return nil;
	return rstrcpy(p, s);
}

long
rstrlen(Rune *s)
{
	Rune *p;

	p = s;
	while (*p++);
	return p - s - 1;
}

Rune *
rstrstr(Rune *s1, Rune *s2)
{
	Rune  *p;
	int i;

	for (p = s1; *p; p++) {
		for (i = 0; p[i] == s2[i] ; i++) {
			if (!s2[i])
				return p;
		}
	}
	return 0;
}

int
runetochar(char *s, Rune *r)
{
	Rune c;

	/* 1 byte seq */
	c = *r;
	if (c <= Rune1) {
		*s = c;
		return 1;
	}
	/* 2 bytes seq */
	if (c <= Rune2) {
		*s++ = Byte2|(c>>6);
		*s = Bytex|(c&Vx);
		return 2;
	}
	if (c > Runemax)
		c = Badrune;
	/* 3 bytes seq */
	if (c <= Rune3) {
		*s++ = Byte3|(c>>12);
		*s++ = Bytex|((c>>6)&Vx);
		*s = Bytex|(c&Vx);
		return 3;
	}
	/* 4 bytes seq */
	*s++ = Byte4|(c>>18);
	*s++ = Bytex|((c>>12)&Vx);
	*s++ = Bytex|((c>>6)&Vx);
	*s = Bytex|(c&Vx);
	return 4;
}

char *
runestostr(Rune *r)
{
	char *p, *s;

	s = malloc(sizeof(char) * (utflen(r) + 1));
	if (s != nil) {
		p = s;
		while (*r) {
			p += runetochar(p, r);
			r++;
		}
		*p = 0;
	}
	return s;
}

Rune *
strtorunes(char *s)
{
	long i, n;
	Rune *r;

	n = unicodelen(s);
	r = malloc(sizeof(Rune) * (n + 1));
	if (r != nil) {
		for (i = 0; i < n; i++)
			s += chartorune(&r[i], s);
		r[i + 1] = 0;
	}
	return r;
}

static int
utfbyte(uchar *byte, uchar utf)
{
	if (utf >= Byte4) {
		*byte = utf&V4;
		return 4;
	} if (utf >= Byte3) {
		*byte = utf&V3;
		return 3;
	} if (utf >= Byte2) {
		*byte = utf&V2;
		return 2;
	} if (utf >= Bytex) {
		*byte = utf&Vx;
		return 0;
	} else {
		*byte = utf&V1;
		return 1;
	}
}
