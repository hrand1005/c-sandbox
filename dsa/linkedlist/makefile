CC=gcc
CFLAGS=-I.
DEPS = ll.h ll_stack.h ll_queue.h

all: stacktest queuetest

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stacktest: ll_stack.o ll_stack_test.o
	$(CC) -o stacktest ll_stack.o ll_stack_test.o

queuetest: ll_queue.o ll_queue_test.o
	$(CC) -o queuetest ll_queue.o ll_queue_test.o

clean:
	-rm *.o $(objects) stacktest queuetest
