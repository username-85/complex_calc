CC = gcc
CFLAGS = -std=c99 -Wall -Wextra
TARGET = complex_calc
LDFLAGS = -ldl
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))

default: $(TARGET)
all: default

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(LDFLAGS) $(OBJECTS)

clean:
	-rm -f *.o
	-rm -f $(TARGET)
