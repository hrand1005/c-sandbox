#include "ll_queue.h"
#include <assert.h>
#include <stdio.h>

void test_1(void);

int main(void) {
    test_1();
    printf("All tests passed for ll_queue_t!\n");
    return 0;
}

void test_1(void) {
    int val;
    ll_queue_t *q;

    q = ll_queue_new();

    /* dequeue-ing an empty ll_queue should return error */
    assert(ll_queue_dequeue(q, &val) == 1);

    /* enqueue multiple values to the ll_queue */
    for (int i = 0; i < 3; i++)
        ll_queue_enqueue(q, i);

    /* ll_queue size should be updated */
    assert(q->size == 3);

    /* elements should be dequeued in LIFO order */
    for (int i = 0; i < 3; i++) {
        assert(ll_queue_dequeue(q, &val) == 0);
        assert(val == i);
    }

    /* ll_queue size should be zero again */
    assert(q->size == 0);

    /* dequeue-ing empty ll_queue should return error (again) */
    assert(ll_queue_dequeue(q, &val) == 1);

    ll_queue_free(q);
}
