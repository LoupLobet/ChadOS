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
	-lutf\
	-lutil

CFLAGS=-D _POSIX_C_SOURCE=200809L -Wall -pedantic -std=c99 ${I}
LDFLAGS=${L}

# OpenBSD uncomment
#LDFLAGS+=-lpledge

# Uncomment if you're a true Chad !
#LDFLAGS+=-static
