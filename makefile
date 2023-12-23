CC		= gcc
FLAGS	= -I.
CFLAGS	= -fPIC -pedantic -Wall -Wextra

bin/cutils: tests/logger.c src/logger/logger.c include/logger.h
	mkdir -p bin
	$(CC) tests/logger.c src/logger/logger.c $(CFLAGS) $(FLAGS) -o bin/cutils

tests: bin/cutils
	bin/cutils
