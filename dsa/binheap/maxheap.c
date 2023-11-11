#include "maxheap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* maxheap_new: allocates a new min heap */
maxheap_t *maxheap_new(size_t capacity) {
    maxheap_t *mh;

    if ((mh = malloc(sizeof(maxheap_t))) != NULL) {
        mh->minheap = minheap_new(capacity);
    }
    return mh;
}

/* maxheap_push: pushes val into the heap */
bool maxheap_push(maxheap_t *mh, int val) {
    return minheap_push(mh->minheap, -val);
}

/* maxheap_pop: pop min element and stores in 'val' */
bool maxheap_pop(maxheap_t *mh, int *val) {
    bool ret = minheap_pop(mh->minheap, val);
    if (ret)
        *val = -*val;
    return ret;
}

/* maxheap_free: frees min heap and associated storage */
void maxheap_free(maxheap_t *mh) {
    minheap_free(mh->minheap);
    free(mh);
}

/* maxheap_print: debug utility to show heap contents */
void maxheap_print(maxheap_t *mh) {
    printf("maxheap array contents:\n[");
    minheap_print(mh->minheap);
    printf("]\n");
}
