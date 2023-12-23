CC		= gcc
FLAGS	= -I.

CFLAGS :=
CFLAGS += -std=gnu99
CFLAGS += -fPIC
CFLAGS += -pedantic
CFLAGS += -Wall
CFLAGS += -Wextra

bin/cutils: tests/logger.c src/logger/logger.c include/logger.h
	mkdir -p bin
	$(CC) tests/logger.c src/logger/logger.c $(CFLAGS) $(FLAGS) -o bin/cutils

tests: bin/cutils
	bin/cutils

clean:
	rm -rf bin
