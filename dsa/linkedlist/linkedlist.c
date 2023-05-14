/* linkedlist.c defines the most naive implementation
 * of a singly linked list you could possibly imagine. */
#include <stdio.h>
#include <stdlib.h>

struct node {
    char *val;
    struct node *next;
};

void walk(struct node *n)
{
    int i;

    for (i = 0; n != NULL; n = n->next){
        printf("index %d, node->val: %s\n", i++, n->val);
    }
}

int main() {
    struct node n1;
    struct node n2;

    n1.val = "n1";
    n1.next = &n2;

    n2.val = "n2";
    n2.next = NULL;
    walk(&n1);
}
