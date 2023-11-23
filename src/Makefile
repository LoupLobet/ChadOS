include config.mk

all: include lib bin

.PHONY: include \
        lib \
        bin

include:
	@echo copy headers to the os tree; \
	mkdir -p ${OSINCDIR};
	cp ${SRCINCDIR}/*.h ${OSINCDIR};

lib:
	@echo build libraries; \
	mkdir -p ${OSLIBDIR}; \
	${MAKE} -C ${SRCLIBDIR};

bin:
	@echo build binaries; \
	mkdir -p ${OSBINDIR}; \
	${MAKE} -C ${SRCBINDIR};
