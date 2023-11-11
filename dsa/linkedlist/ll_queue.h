#include "ll.h"
#include <stdlib.h>

typedef struct {
    size_t size;
    node_t *head;
    node_t *tail;
} ll_queue_t;

/* ll_queue_new: allocates a new ll_queue object */
ll_queue_t *ll_queue_new(void);

/* ll_queue_push: pushes val to the end of ll_queue */
int ll_queue_push(ll_queue_t *q, int val);

/* ll_queue_pop: pops oldest ll_queue value and saves it to 'val' arg */
int ll_queue_pop(ll_queue_t *q, int *val);

/* ll_queue_free: frees ll_queue object and associated storage */
void ll_queue_free(ll_queue_t *q);
