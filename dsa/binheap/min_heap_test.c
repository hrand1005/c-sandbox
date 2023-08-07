#include "min_heap.c"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_1(void);

int main(void) {
    test_1();
    return 0;
}

void test_1(void) {
    size_t elems;
    min_heap_t *mh;
    int val;

    /* fill min heap with fixed number of elements */
    elems = 100;
    mh = min_heap_new(elems);
    for (int i = elems; i > 0; i--) {
        assert(min_heap_insert(mh, i));
        assert(mh->size == elems - i + 1);
        assert(mh->capacity == elems);
    }

    /* print for debugging */
    /* min_heap_print(mh); */

    /* one more element should grow the capacity by 2x */
    assert(min_heap_insert(mh, ++elems));
    assert(mh->size = elems);
    assert(mh->capacity = (elems - 1) * 2);

    /* pop elements from heap and verify correct ordering */ 
    for (int i = 1; i <= elems; i++) {
        assert(min_heap_remove_min(mh, &val));
        /* print for debugging */
        /* min_heap_print(mh); */
        assert(val == i);
    }

    /* size zero heap should not be able to remove new elements */
    assert(mh->size == 0);
    assert(!min_heap_remove_min(mh, &val));

    min_heap_free(mh);
}
