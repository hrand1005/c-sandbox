#include "minheap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    minheap_t *minheap;
} maxheap_t;

/* maxheap_new: allocates a new min heap */
maxheap_t *maxheap_new(size_t capacity);

/* maxheap_push: pushes val into the heap */
bool maxheap_push(maxheap_t *mh, int val);

/* maxheap_pop: pop min element and stores in 'val' */
bool maxheap_pop(maxheap_t *mh, int *val);

/* maxheap_free: frees min heap and associated storage */
void maxheap_free(maxheap_t *mh);

/* maxheap_print: debug utility to show heap contents */
void maxheap_print(maxheap_t *mh);
