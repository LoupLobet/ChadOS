include /Users/loup/src/chados/src/config.mk

LIBS=\
	librune\
	libutf

all: libs

libs:
	@for lib in ${LIBS}; do \
		${MAKE} -C "$${lib}"; \
	done
