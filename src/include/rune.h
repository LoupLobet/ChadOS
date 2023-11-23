#ifndef _RUNE_H_
#define _RUNE_H_ 1

typedef unsigned int Rune;

enum {
	Runemax  = 0x10FFFF,
	Badrune = 0xFFFD,
};

extern int	 chartorune(Rune *, char *);
extern Rune	*rstrcat(Rune *, Rune *);
extern Rune	*rstrchr(Rune *, Rune);
extern int	 rstrcmp(Rune *, Rune *);
extern Rune	*rstrcpy(Rune *, Rune *);
extern Rune	*rstrdup(Rune *);
extern long	 rstrlen(Rune *);
extern Rune	*rstrstr(Rune *, Rune *);
extern int	 runetochar(char *, Rune *);
extern char	*runestostr(Rune *);
extern Rune	*strtorunes(char *);

#endif
