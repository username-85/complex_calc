CC = gcc
CFLAGS = -std=c99 -fPIC -Wall -Wextra
LDFLAGS = -shared
SOBJECTS = $(patsubst %.c, %.so, $(wildcard *.c))

default: all
all: $(SOBJECTS)

%.so: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	-rm -f *.so
