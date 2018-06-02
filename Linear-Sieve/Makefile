CFLAGS = -Wall -O3 -g -std=c11

lin_sieve: stack.o bin_heap.o linear_sieve.o
	$(CC) linear_sieve.o bin_heap.o stack.o -lm $(CFLAGS) -o linear_sieve

stack: rm_stack
	$(CC) -DDEBUG stack.c $(CFLAGS) -o stack

bin_heap: rm_heap
	$(CC) -DDEBUG bin_heap.c $(CFLAGS) -o bin_heap

rm_heap:
	$(RM) bin_heap

rm_stack:
	$(RM) stack

clean:
	$(RM) *.o stack bin_heap linear_sieve

