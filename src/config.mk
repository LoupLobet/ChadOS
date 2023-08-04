CHADOS=/Users/loup/src/chados
CONFIG=${CHADOS}/config.mk

MAKE=make CONFIG=${CONFIG}
CC=cc
LD=cc
AR=ar

INCS=-I${CHADOS}/include
LIBS=\
	-L${CHADOS}/lib\
	-lrune\
	-lutf

CFLAGS=-Wall -pedantic -std=c99 ${INCS}
LDFLAGS=${LIBS}