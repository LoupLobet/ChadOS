OS=/Users/loup/src/chados
SRCROOT=${OS}/src
CONFIG=${SRCROOT}/config.mk

OSLIBDIR=${OS}/lib
OSINCDIR=${OS}/include
SRCLIBDIR=${SRCROOT}/lib
SRCINCDIR=${SRCROOT}/include

SHELL=/bin/bash
MAKE=make CONFIG=${CONFIG}

CC=cc
LD=cc
AR=ar rsc
I=-I${OS}/include
L=\
	-L${OS}/lib\
	-lrune\
	-lutf

CFLAGS=-Wall -pedantic -std=c99 ${I}
LDFLAGS=${L}