#include <stdlib.h>
#include <strings.h>
#include "hashtable.h"

// #include <stdio.h>

/* nlist_free: frees provided node, but not linked nodes */
void nlist_free(struct nlist *np)
{
    free(np->name);
    free(np->defn);
    free(np);
}

static struct nlist *hashtab[HASHSIZE];

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free(np->defn);
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

void undef(char *s)
{
    struct nlist *nprev, *ncur, *nnext;

    nprev = NULL;
    for (ncur = hashtab[hash(s)]; ncur != NULL; ncur = ncur->next)
        if (strcmp(s, ncur->name) == 0) {
            if (nprev != NULL) {
                nnext = ncur->next;
                nprev->next = nnext;
            } else
                hashtab[hash(s)] = NULL;
            nlist_free(ncur);
            break;
        }
}
