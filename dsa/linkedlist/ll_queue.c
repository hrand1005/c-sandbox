#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

typedef struct {
    size_t size;
    node_t *head;
    node_t *tail;
} queue_t;

/* queue_new: allocates a new queue object */
queue_t *queue_new(void) {
    queue_t *q;

    if ((q = malloc(sizeof(queue_t))) != NULL) {
        q->head = NULL;
        q->tail = NULL;
        q->size = 0;
    }
    return q;
}

/* queue_pop: pops oldest queue value and saves it to val */
int queue_push(queue_t *q, int val) {
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

/* queue_pop: pops oldest queue value and saves it to 'val' arg */
int queue_pop(queue_t *q, int *val) {
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

/* queue_free: frees queue object and associated storage */
void queue_free(queue_t *q) {
    node_t *cur, *tmp;

    cur = q->head;
    while (cur != NULL) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}
