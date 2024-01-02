#include <c.h>
#define UNIX_C
#include <libc.h>

#include <string.h>

void *
chadmemcpy(void *dst, void *src, long n)
{
	return memcpy(dst, src, n);
}

void *
chadmemmove(void *dst, void *src, long n)
{
	return memmove(dst, src, n);
}

void *
chadmemchr(const void *p, int c, long n)
{
	return memchr(p, c, n);
}

int
chadmemcmp(void *p1, void *p2, long n)
{
	return memcmp(p1, p2, n);
}

void *
chadmemset(void *p, int c, long n)
{
	return memset(p, c, n);
}

char *
chadstrcat(char *dst, char *src)
{
	return strcat(dst, src);
}

long
chadstrlcat(char *dst, char *src, long n)
{
	long dlen, slen;

	dlen = strnlen(dst, n);
	slen = strlen(src);
	if (dlen == n)
		return n + slen;
	if (slen < n - dlen)
		memcpy(dst + dlen, src, slen + 1);
	else {
		memcpy(dst + dlen, src, n - dlen - 1);
		dst[n - 1] = '\0';
	}
	return dlen + slen;
}

char *
chadstrncat(char *dst, char *src, long n)
{
	return strncat(dst, src, n);
}

char *
chadstrchr(char *s, int c)
{
	return strchr(s, c);
}

char *
chadstrrchr(char *s, int c)
{
	return strrchr(s, c);
}

int
chadstrcmp(char *s1, char *s2)
{
	return strcmp(s1, s2);
}

int
chadstrncmp(char *s1, char *s2, long n)
{
	return strncmp(s1, s2, n);
}

char *
chadstrcpy(char *dst, char *src)
{
	return strcpy(dst, src);
}

long
chadstrlcpy(char *dst, char *src, long n)
{
	long len;

	len = strlen(src);
	if (len + 1 < n)
		memcpy(dst, src, len + 1);
	else if (n) {
		memcpy(dst, src, n - 1);
		dst[n - 1] = '\0';
	}
	return len;
}

char *
chadstrncpy(char *dst, char *src, long n)
{
	return strncpy(dst, src, n);
}

long
chadstrlen(char *s)
{
	return strlen(s);
}

long
chadstrnlen(char *s, long n)
{
	return strnlen(s, n);
}

long
chadstrspn(char *s1, char *s2)
{
	return strspn(s1, s2);
}

long
chadstrcspn(char *s1, char *s2)
{
	return strcspn(s1, s2);
}

char *
chadstrpbrk(char *s1, char *s2)
{
	return strpbrk(s1, s2);
}

char *
chadstrstr(char *s1, char *s2)
{
	return strstr(s1, s2);
}

char *
chadstrtok(char *s1, char *s2)
{
	return strtok(s1, s2);
}

char *
chadstrdup(char *s)
{
	return strdup(s);
}
