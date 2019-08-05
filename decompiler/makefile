TARGET=decompile
CFLAGS= -Wall -ffreestanding
OPT_LVL=
LDFLAGS=-I$(IDIR)

IDIR=./include
SDIR=./src
ODIR=./bin
TDIR=./test

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	ifeq ($(shell which gcc-8), /usr/local/bin/gcc-8)
		CC=gcc-8#MacOS GNU gcc, not clang
		CXX=g++-8
	else
		CC=clang
		CXX=clang
	endif
	LIB=-lncurses
else
	CC=gcc#GNU gcc
	CXX=gcc
	LIB=-lcurses
endif

INC_DEPS=decompiler.h instructions.h
TEST_DEPS=
DEPS=$(patsubst %,$(IDIR)/%,$(INC_DEPS))
DEPS=$(patsubst %,$(TDIR)/%,$(TEST_DEPS))

_SRC=decompiler.c instructions.c main.c
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ=decompiler.o instructions.o main.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(ODIR)/$(TARGET)
	@printf "%b" "Compilation successful\n"

$(ODIR)/$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OPT_LVL) $(LDFLAGS) $^ -o $@

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(OPT_LVL) -MMD -c $< -o $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*
