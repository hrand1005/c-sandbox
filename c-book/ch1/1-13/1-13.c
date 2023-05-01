#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORDS 20

int main() {
    int c, wl, wc, state;
    int wlengths[MAX_WORDS];

    wl = wc = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if ((c == ' ' || c == '\n' || c == '\t') && state == IN) {
            wlengths[wc] = wl;
            wc++;
            wl = 0;
            state = OUT;
        } else {
            wl++;
            state = IN;
        }
    }

    printf("Histogram for %d read words:\n", wc);
    for (int i = 0; i < wc; i++) {
        printf("%d: ", i+1); /* offset 0 indexing */
        for (int j = 0; j < wlengths[i]; j++) {
            printf("X");
        }
        printf("\n");
    }

    return 0; 
}
