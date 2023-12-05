include ${CONFIG}

LIBS=\
	libchad \
	librune \
	libutf \
	libutil

all: libs

libs:
	@for lib in ${LIBS}; do \
		${MAKE} -C "$${lib}"; \
	done
