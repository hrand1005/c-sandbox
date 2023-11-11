#include "ll_queue.h"
#include <stdlib.h>

/* ll_queue_new: allocates a new ll_queue object */
ll_queue_t *ll_queue_new(void) {
    ll_queue_t *q;

    if ((q = malloc(sizeof(ll_queue_t))) != NULL) {
        q->head = NULL;
        q->tail = NULL;
        q->size = 0;
    }
    return q;
}

/* ll_queue_enqueue: enqueues val to the end of ll_queue */
int ll_queue_enqueue(ll_queue_t *q, int val) {
    node_t *n;

    if ((n = malloc(sizeof(node_t))) == NULL)
        return 1;
    n->val = val;
    n->next = NULL;
    if (q->size == 0) {
        q->head = n;
        q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = n;
    }
    q->size++;
    return 0;
}

/* ll_queue_dequeue: dequeues oldest ll_queue value and saves it to 'val' arg */
int ll_queue_dequeue(ll_queue_t *q, int *val) {
    node_t *tmp;

    if (q->size == 0)
        return 1;
    *val = q->head->val;
    tmp = q->head;
    q->head = q->head->next;
    q->size--;
    if (q->size == 0)
        q->tail = NULL;
    return 0;
}

/* ll_queue_free: frees ll_queue object and associated storage */
void ll_queue_free(ll_queue_t *q) {
    node_t *cur, *tmp;

    cur = q->head;
    while (cur != NULL) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}
