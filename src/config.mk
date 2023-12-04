OS=/Users/loup/chad-os
SHELL=/bin/bash
MK=make
CC=cc
LD=cc
AR=ar rsc

SRCROOT=${OS}/src
CONFIG=${SRCROOT}/config.mk
OSLIBDIR=${OS}/lib
OSINCDIR=${OS}/include
OSBINDIR=${OS}/bin
SRCLIBDIR=${SRCROOT}/lib
SRCINCDIR=${SRCROOT}/include
SRCBINDIR=${SRCROOT}/bin
MAKE=${MK} CONFIG=${CONFIG}


I=-I${OS}/include
L=\
	-L${OSLIBDIR}\
	-lchad\
	-lrune\
	-lutf
CFLAGS=-Wall -pedantic -std=c99 ${I}
LDFLAGS=${L}
