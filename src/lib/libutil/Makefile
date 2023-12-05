include ${CONFIG}

NAME=libutil
LIB=libutil.a
SRCS=util.c
OBJS=${SRCS:.c=.o}

all: info clean ${OSLIBDIR}/${LIB}

info:

.c.o:
	${CC} -c ${CFLAGS} $<

${OSLIBDIR}/${LIB}: ${OBJS}
	${AR} $@ ${OBJS}

clean:
	@rm -f *.o *.a
