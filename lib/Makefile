CC = gcc
CFLAGS = -std=c99 -fPIC -Wall -Wextra

.PHONY: default all clean

LDFLAGS = -shared
SOBJECTS = $(patsubst %.c, %.so, $(wildcard *.c))

default: all
all: $(SOBJECTS) 

%.so: %.c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	-rm -f *.so
