#include "minheap.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_1(void);

int main(void) {
    test_1();
    printf("All minheap tests passed!\n");
    return 0;
}

void test_1(void) {
    size_t elems;
    minheap_t *mh;
    int val;

    /* fill min heap with fixed number of elements */
    elems = 100;
    mh = minheap_new(elems);
    for (int i = elems; i > 0; i--) {
        assert(minheap_push(mh, i));
        assert(mh->size == elems - i + 1);
        assert(mh->capacity == elems);
    }

    /* print for debugging */
    /* minheap_print(mh); */

    /* one more element should grow the capacity by 2x */
    assert(minheap_push(mh, ++elems));
    assert(mh->size = elems);
    assert(mh->capacity = (elems - 1) * 2);

    /* pop elements from heap and verify correct ordering */ 
    for (int i = 1; i <= elems; i++) {
        assert(minheap_pop(mh, &val));
        /* print for debugging */
        /* minheap_print(mh); */
        assert(val == i);
    }

    /* size zero heap should not be able to pop new elements */
    assert(mh->size == 0);
    assert(!minheap_pop(mh, &val));

    minheap_free(mh);
}
