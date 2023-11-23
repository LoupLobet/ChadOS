include ${CONFIG}

NAME=libc
LIB=libc.a
SRCS=malloc.c file.c
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