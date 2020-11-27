CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wextra -pedantic -Iinclude -Ivendor/uki -Ivendor/callocs/src $(shell pkg-config --cflags glib-2.0)
LFLAGS := $(shell pkg-config --libs glib-2.0)

SRC := $(shell find ./src -name *.c) ./vendor/callocs/src/callocs.c

.PHONY : run clean

run : app.exe
	./app.exe

clean :
	rm -f app.exe

app.exe : vendor/uki/uki.h $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LFLAGS)
