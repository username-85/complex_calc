CC = gcc
CFLAGS = -std=c99 -Wall -Wextra

.PHONY: default all clean

TARGET = complex_calc
LDFLAGS = -ldl
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

default: $(TARGET)
all: default

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(LDFLAGS) $(OBJECTS)

clean:
	-rm -f *.o
	-rm -f $(TARGET)
