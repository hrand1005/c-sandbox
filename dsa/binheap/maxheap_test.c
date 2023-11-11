#include "maxheap.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_1(void);

int main(void) {
    test_1();
    printf("All maxheap tests passed!\n");
    return 0;
}

void test_1(void) {
    size_t elems;
    maxheap_t *mh;
    int val;

    /* fill max heap with fixed number of elements */
    elems = 100;
    mh = maxheap_new(elems);
    for (int i = elems; i > 0; i--) {
        assert(maxheap_push(mh, i));
    }

    /* pop elements from heap and verify correct ordering */ 
    for (int i = elems; i > 0; i--) {
        assert(maxheap_pop(mh, &val));
        assert(val == i);
    }

    /* size zero heap should not be able to pop new elements */
    assert(!maxheap_pop(mh, &val));

    maxheap_free(mh);
}
