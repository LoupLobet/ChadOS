include ${CONFIG}

NAME=libutf
LIB=libutf.a
SRCS=utf.c
INCS=utf.h
OBJS=${SRCS:.c=.o}

all: info clean ${OBJS} ${OSLIBDIR}/${LIB}

info:
	@echo ${NAME}:

${OBJS}: %.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${OSLIBDIR}/${LIB}: ${OBJS}
	${AR} $@ $^

clean:
	@rm -f *.o *.a
