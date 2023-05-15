#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

void nlist_free(struct nlist *np);
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *s);
