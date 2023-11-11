CC=gcc
CFLAGS=-I.
DEPS = minheap.h maxheap.h

all: minheaptest maxheaptest

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

minheaptest: minheap.o minheap_test.o
	$(CC) -o minheaptest minheap.o minheap_test.o

maxheaptest: minheap.o maxheap.o maxheap_test.o
	$(CC) -o maxheaptest minheap.o maxheap.o maxheap_test.o

clean:
	-rm *.o $(objects) minheaptest maxheaptest
