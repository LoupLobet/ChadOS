include ${CONFIG}

NAME=libchad
LIB=libchad.a
SRCS=malloc.c file.c unixfile.c
OBJS=${SRCS:.c=.o}

all: info clean ${OSLIBDIR}/${LIB}

info:

.c.o:
	${CC} -c ${CFLAGS} $<

${OSLIBDIR}/${LIB}: ${OBJS}
	${AR} $@ ${OBJS}

clean:
	@rm -f *.o *.a
