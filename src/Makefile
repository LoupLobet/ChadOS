include config.mk

all: clean lib test

.c.o:
	${CC} ${CFLAGS} -c $<

lib:
	cd lib; ${MAKE} -f Makefile

test: test.o
	${LD} -o $@ $^ ${LDFLAGS}

clean:
	rm -f *.o
	cd lib; ${MAKE} clean

.PHONY:lib
