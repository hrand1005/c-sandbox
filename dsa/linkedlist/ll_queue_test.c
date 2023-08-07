#include "ll_queue.c"
#include <assert.h>

void test_1(void);

int main(void) {
    test_1();
    return 0;
}

void test_1(void) {
    int val;
    queue_t *q;

    q = queue_new();

    /* popping an empty queue should return error */
    assert(queue_pop(q, &val) == 1);

    /* push multiple values to the queue */
    for (int i = 0; i < 3; i++)
        queue_push(q, i);

    /* queue size should be updated */
    assert(q->size == 3);

    /* elements should be popped in LIFO order */
    for (int i = 0; i < 3; i++) {
        assert(queue_pop(q, &val) == 0);
        assert(val == i);
    }

    /* queue size should be zero again */
    assert(q->size == 0);

    /* popping empty queue should return error (again) */
    assert(queue_pop(q, &val) == 1);

    queue_free(q);
}
