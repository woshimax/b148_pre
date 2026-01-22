CC = gcc
CFLAGS = -Wall -Iinclude

all: bin/image_filter

bin/image_filter: src/main.c src/filter.c
	mkdir -p bin
	$(CC) $(CFLAGS) -o bin/image_filter src/main.c src/filter.c

clean:
	rm -rf bin
