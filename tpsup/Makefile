# tpsup - TP Sup L3

include config.mk

SRC = binary.c debug.c tpsup.c
OBJ = ${SRC:.c=.o}

all: options tpsup

options:
	@echo tpsup build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"
	@echo "OBJ      = ${OBJ}"

.c.o:
	@echo GCC $<
	@${CC} -c ${CFLAGS} $<

${OBJ}: config.mk

config.h:
	@echo creating $@ from config.def.h
	@cp config.def.h $@

tpsup: ${OBJ}
	@echo CC -o $@ 
	@${CC} -o $@ $^ ${LDFLAGS}

clean:
	@echo cleaning
	@rm -f ${OBJ}

mrproper:
	@echo deep cleaning
	@rm -f tpsup ${OBJ} tpsup-${VERSION}.tar.gz

dist: mrproper
	@echo creating dist tarball
	@mkdir -p tpsup-${VERSION}
	@cp -R LICENSE Makefile config.mk config.def.h README \
		TODO.md tpsup.1 ${SRC} tpsup-${VERSION}
	@tar -cf tpsup-${VERSION}.tar tpsup-${VERSION}
	@gzip tpsup-${VERSION}.tar
	@rm -rf tpsup-${VERSION}

install: all
	@echo installing executable file to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f tpsup ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/tpsup
	@echo installing manual page to ${DESTDIR}${MANPREFIX}/man1
	@mkdir -p ${DESTDIR}${MANPREFIX}/man1
	@sed "s/VERSION/${VERSION}/g" < tpsup.1 > ${DESTDIR}${MANPREFIX}/man1/tpsup.1
	@chmod 644 ${DESTDIR}${MANPREFIX}/man1/tpsup.1

uninstall:
	@echo removing executable file from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/tpsup
	@echo removing manual page from ${DESTDIR}${MANPREFIX}/man1
	@rm -f ${DESTDIR}${MANPREFIX}/man1/tpsup.1

.PHONY: all options clean dist install uninstall

