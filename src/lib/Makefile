include ${CONFIG}

LIBS=\
	libchad \
	libpledge \
	librune \
	libutf \
	libutil


all: libs

libs:
	@for lib in ${LIBS}; do \
		${MAKE} -C "$${lib}"; \
	done
