#include <stdio.h>

int main() {
    int c, b, t, nl;

    b = t = nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            nl++;
        } else if (c == '\t') {
            t++;
        } else if (c == ' ') {
            b++;
        }
    }

    printf("blanks: %d\n", b);
    printf("tabs: %d\n", t);
    printf("newlines: %d\n", nl);

    return 0;
}
