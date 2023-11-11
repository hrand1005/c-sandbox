#include "ll_stack.h"
#include <stdlib.h>

/* ll_stack_new: allocates a new ll_stack object */
ll_stack_t *ll_stack_new(void) {
    ll_stack_t *s;

    if ((s = malloc(sizeof(ll_stack_t))) != NULL) {
        s->head = NULL;
        s->tail = NULL;
        s->size = 0;
    }
    return s;
}

/* ll_stack_push: pushes new val to the top of ll_stack */
int ll_stack_push(ll_stack_t *s, int val) {
    node_t *n;

    if ((n = malloc(sizeof(node_t))) == NULL)
        return 1;
    n->val = val;
    n->next = s->head;
    s->head = n;
    if (s->size == 0) {
        s->tail = n;
    }
    s->size++;
    return 0;
}

/* ll_stack_pop: pops oldest ll_stack value and saves it to 'val' arg */
int ll_stack_pop(ll_stack_t *s, int *val) {
    node_t *tmp;

    if (s->size == 0)
        return 1;
    *val = s->head->val;
    tmp = s->head;
    s->head = s->head->next;
    s->size--;
    if (s->size == 0)
        s->tail = NULL;
    return 0;
}

/* ll_stack_free: frees ll_stack object and associated storage */
void ll_stack_free(ll_stack_t *s) {
    node_t *cur, *tmp;

    cur = s->head;
    while (cur != NULL) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}
