include ${CONFIG}

SRCS=${wildcard *.c}
OBJS=${SRCS:.c=.o}
BINS=${SRCS:%.c=%}

all: clean ${BINS}

.PHONY: ${BINS}

.c.o:
	${CC} -c ${CFLAGS} $<

${BINS}: %: %.o
	${LD} $< -o ${OSBINDIR}/$@ ${LDFLAGS}

clean:
	rm -f *.o ${BINS}


