include ${CONFIG}

NAME=libutf
LIB=libutf.a
SRCS=utf.c
OBJS=${SRCS:.c=.o}

all: info clean ${OSLIBDIR}/${LIB}

info:

.c.o:
	${CC} -c ${CFLAGS} $<

${OSLIBDIR}/${LIB}: ${OBJS}
	${AR} $@ ${OBJS}

clean:
	@rm -f *.o *.a
