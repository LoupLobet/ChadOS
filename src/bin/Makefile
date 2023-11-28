include ${CONFIG}

BINS=test

all: bins

bins:
	@for bin in ${BINS}; do \
		${MAKE} -C "$${bin}"; \
	done
