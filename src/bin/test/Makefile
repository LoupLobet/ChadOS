include ${CONFIG}

NAME=test
BIN=test
SRCS=test.c
OBJS=${SRCS:.c=.o}

all: info clean ${OSBINDIR}/${BIN}

info:

.c.o: 
	${CC} -c ${CFLAGS} $<

${OSBINDIR}/${BIN}: ${OBJS}
	${LD} ${OBJS} -o $@ ${LDFLAGS}

clean:
	@rm -f *.o *.a
