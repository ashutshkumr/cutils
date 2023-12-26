SHELL	= /bin/sh
CC		= gcc

CFLAGS :=
CFLAGS += -std=gnu99
CFLAGS += -pedantic
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -o3

FLAGS :=
FLAGS += -Iinclude

SOFLAGS :=
SOFLAGS += -fPIC
SOFLAGS += -shared

LDFLAGS :=
LDFLAGS += -Lbin
LDFLAGS += -lcutils

export LD_LIBRARY_PATH := bin:$(LD_LIBRARY_PATH)

SOURCES := $(shell find src -name '*.c')
INCLUDES := $(shell find include -name '*.h')
TESTS := $(shell find tests -name '*.c')

all: tests

bin/libcutils.so: $(SOURCES) $(INCLUDES)
	mkdir -p bin
	$(CC) $(CFLAGS) $(FLAGS) $(SOFLAGS) $(SOURCES) -o bin/libcutils.so

bin/cutils: bin/libcutils.so $(INCLUDES) $(TESTS)
	mkdir -p bin
	$(CC) $(CFLAGS) $(FLAGS) $(TESTS) $(LDFLAGS) -o bin/cutils

tests: bin/cutils
	LOG_LEVEL=trace bin/cutils

clean:
	rm -rf bin
