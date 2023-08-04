CHADOS=/Users/loup/src/chados
CC=cc
LD=ld
AR=ar

INCS=-I${CHADOS}/include
LIBS=-L${CHADOS}/src

CFLAGS=-Wall -pedantic -std=c99 ${INCS}
LDFLAGS=${LIBS}
