#ifndef _UTF_H_
#define _UTF_H_ 1

#include <rune.h>

extern long	 unicodelen(char *);
extern long	 utflen(Rune *);

enum {
	Asciimax = 0x80,
};

#endif
