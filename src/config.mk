OS=/tmp/chad-os
SRCROOT=${OS}/src
CONFIG=${SRCROOT}/config.mk

OSLIBDIR=${OS}/lib
OSINCDIR=${OS}/include
OSBINDIR=${OS}/bin
SRCLIBDIR=${SRCROOT}/lib
SRCINCDIR=${SRCROOT}/include
SRCBINDIR=${SRCROOT}/bin

SHELL=/bin/bash
MAKE=make CONFIG=${CONFIG}

CC=cc
LD=cc
AR=ar rsc
I=-I${OS}/include
L=\
	-L${OSLIBDIR}\
	-lchad\
	-lrune\
	-lutf

CFLAGS=-Wall -pedantic -std=c99 ${I}
LDFLAGS=${L} -static
