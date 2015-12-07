# tpsup version
VERSION = 0.1

# Customize below to fit your system

# paths
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

# includes and libs
INCS = -I. -I/usr/include
LIBS = -L/usr/lib -lm

# flags
CPPFLAGS = -DVERSION=\"${VERSION}\" -D_DEFAULT_SOURCE
CFLAGS = -Wall ${INCS} ${CPPFLAGS}
LDFLAGS = -g ${LIBS}

# debug
DEBUG = 1
DEBUG_FLAGS = -DDEBUG -g
OPT_FLAGS = -O2

ifeq (${DEBUG},1)
	CPPFLAGS += ${DEBUG_FLAGS}
else
	CPPFLAGS += ${OPT_FLAGS}
endif

# compiler and linker
CC = gcc
