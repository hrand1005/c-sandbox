#include <stdio.h>

int main() {
    int c, blank;

    blank = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blank = 1;
        } else {
            if (blank) {
                putchar(' ');
                blank = 0;
            }
            putchar(c);
        }
    }

    return 0;
}
