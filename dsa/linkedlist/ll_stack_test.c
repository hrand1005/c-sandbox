#include "ll_stack.h"
#include <assert.h>
#include <stdio.h>

void test_1(void);

int main(void) {
    test_1();
    printf("All tests passed for ll_stack_t!\n");
    return 0;
}

void test_1(void) {
    int val;
    ll_stack_t *s;

    s = ll_stack_new();

    /* popping an empty ll_stack should return error */
    assert(ll_stack_pop(s, &val) == 1);

    /* push multiple values to the ll_stack */
    for (int i = 0; i < 3; i++)
        ll_stack_push(s, i);

    /* ll_stack size should be updated */
    assert(s->size == 3);

    /* elements should be popped in FIFO order */
    for (int i = 2; i >= 0; i--) {
        assert(ll_stack_pop(s, &val) == 0);
        assert(val == i);
    }

    /* ll_stack size should be zero again */
    assert(s->size == 0);

    /* popping empty ll_stack should return error (again) */
    assert(ll_stack_pop(s, &val) == 1);

    ll_stack_free(s);
}
