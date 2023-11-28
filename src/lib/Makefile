include ${CONFIG}

LIBS=\
	libchad \
	librune \
	libutf

all: libs

libs:
	@for lib in ${LIBS}; do \
		${MAKE} -C "$${lib}"; \
	done
