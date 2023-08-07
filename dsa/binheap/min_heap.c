#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    size_t size;
    size_t capacity;
    int *heap;
} min_heap_t;

/* min_heap_new: allocates a new min heap */
min_heap_t *min_heap_new(size_t capacity) {
    min_heap_t *mh;

    if ((mh = malloc(sizeof(min_heap_t))) != NULL) {
        mh->size = 0;
        mh->capacity = capacity;
        if ((mh->heap = malloc(sizeof(int) * capacity)) == NULL) {
            free(mh);
            mh = NULL;
        }
    }
    return mh;
}

/* min_heap_heapify: reorders heap from index up to root */
void min_heap_heapify_up(min_heap_t *mh, int index) {
    int parent_index, tmp;

    if (index == 0)
        return;
    parent_index = (index - 1) / 2;
    if (mh->heap[parent_index] > mh->heap[index]) {
        tmp = mh->heap[parent_index];
        mh->heap[parent_index] = mh->heap[index];
        mh->heap[index] = tmp;
        min_heap_heapify_up(mh, parent_index);
    }
}

/* min_heap_heapify: reorders the heap from index down to leaf */
void min_heap_heapify_down(min_heap_t *mh, int index) {
    int left_index, right_index, min_child_index, tmp;

    min_child_index = left_index = (2*index) + 1;
    if (left_index > mh->size - 1)
        return;
    right_index = left_index + 1;
    if (right_index <= mh->size - 1 && mh->heap[right_index] < mh->heap[left_index])
        min_child_index = right_index;
    if (mh->heap[index] > mh->heap[min_child_index]) {
        tmp = mh->heap[min_child_index];
        mh->heap[min_child_index] = mh->heap[index];
        mh->heap[index] = tmp;
        min_heap_heapify_down(mh, min_child_index);
    }
}

/* min_heap_insert: inserts val into the heap */
bool min_heap_insert(min_heap_t *mh, int val) {
    int new_capacity;
    int *new_heap;

    if (mh->size == mh->capacity) {
        new_capacity = mh->capacity * 2;
        if ((new_heap = malloc(sizeof(int) * new_capacity)) == NULL)
            return false;
        memcpy(new_heap, mh->heap, mh->size * sizeof(int));
        free(mh->heap);
        mh->heap = new_heap;
        mh->capacity = new_capacity;
    }
    mh->heap[mh->size] = val;
    min_heap_heapify_up(mh, mh->size++);
    return true;
}

/* min_heap_remove_min: removes min element and stores in 'val' */
bool min_heap_remove_min(min_heap_t *mh, int *val) {
    if (mh->size == 0)
        return false;

    *val = mh->heap[0];
    mh->heap[0] = mh->heap[--mh->size];
    min_heap_heapify_down(mh, 0);
    return true;
}

/* min_heap_free: frees min heap and associated storage */
void min_heap_free(min_heap_t *mh) {
    free(mh->heap);
    free(mh);
}

/* min_heap_print: debug utility to show heap contents */
void min_heap_print(min_heap_t *mh) {
    printf("min_heap array contents:\n[");
    for (int i = 0; i < mh->size; i++)  {
        printf(" %d ", mh->heap[i]);
    }
    printf("]\n");
}
