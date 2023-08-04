include ${CONFIG}

LIB=\
	librune.a\
	libutf.a

all: ${LIB} clean install

.c.o:
	${CC} ${CFLAGS} -c $<

${LIB}: lib%.a: %.o
	${AR} rsc $@ $<

clean:
	rm -f *.o

install:
	mv *.a ${CHADOS}/lib/