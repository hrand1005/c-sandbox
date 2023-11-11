#include "ll.h"
#include <stdlib.h>

typedef struct {
    size_t size;
    node_t *head;
    node_t *tail;
} ll_stack_t;

/* ll_stack_new: allocates a new ll_stack object */
ll_stack_t *ll_stack_new(void);

/* ll_stack_push: pushes new val to the top of ll_stack */
int ll_stack_push(ll_stack_t *s, int val);

/* ll_stack_pop: pops oldest ll_stack value and saves it to 'val' arg */
int ll_stack_pop(ll_stack_t *s, int *val);

/* ll_stack_free: frees ll_stack object and associated storage */
void ll_stack_free(ll_stack_t *s);
