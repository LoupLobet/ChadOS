include ${CONFIG}

NAME=libio
LIB=libio.a
SRCS=io.c
OBJS=${SRCS:.c=.o}

all: info clean ${OSLIBDIR}/${LIB}

info:

.c.o:
	${CC} -c ${CFLAGS} $<

${OSLIBDIR}/${LIB}: ${OBJS}
	${AR} $@ ${OBJS}

clean:
	@rm -f *.o *.a
