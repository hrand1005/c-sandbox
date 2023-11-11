#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    size_t size;
    size_t capacity;
    int *heap;
} minheap_t;

/* minheap_new: allocates a new min heap */
minheap_t *minheap_new(size_t capacity);

/* minheap_push: pushes val into the heap */
bool minheap_push(minheap_t *mh, int val);

/* minheap_pop: pop min element and stores in 'val' */
bool minheap_pop(minheap_t *mh, int *val);

/* minheap_free: frees min heap and associated storage */
void minheap_free(minheap_t *mh);

/* minheap_print: debug utility to show heap contents */
void minheap_print(minheap_t *mh);
