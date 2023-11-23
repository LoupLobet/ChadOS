include ${CONFIG}

NAME=librune
LIB=librune.a
SRCS=rune.c
OBJS=${SRCS:.c=.o}

all: info clean ${OBJS} ${OSLIBDIR}/${LIB}

info:

${OBJS}: %.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${OSLIBDIR}/${LIB}: ${OBJS}
	${AR} $@ $<

clean:
	@rm -f *.o *.a