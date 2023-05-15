#include <stdio.h>
#include "hashtable.h"

int main()
{
    char *k, *v, *prefix;
    struct nlist *res;

    prefix = "call\n\t";
    k = "hello";
    v = "world";
    if ((install(k, v)) != NULL)
        printf("%sinstall(%s, %s)\n\n", prefix, k, v);
    if ((res = lookup(k)) != NULL)
        printf("%sresult = lookup(%s)\nresult->defn: %s\n\n", prefix, k, res->defn);
    undef(k);
    printf("%sundef(%s)\n\n", prefix, k);
    if ((res = lookup(k)) != NULL)
        printf("%sresult = lookup(%s)\nresult->defn: %s\n\n", prefix, k, res->defn);
    else
        printf("%sresult = lookup(%s)\nresult is NULL!\n\n", prefix, k);
}
