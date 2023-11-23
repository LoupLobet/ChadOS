include config.mk

all: include lib

.PHONY: include \
        lib

include:
	@echo copy headers to the os tree; \
	mkdir -p ${OSINCDIR};
	cp ${SRCINCDIR}/*.h ${OSINCDIR};

lib:
	@echo build libraries; \
	mkdir -p ${OSLIBDIR}; \
	${MAKE} -C ${SRCLIBDIR};
