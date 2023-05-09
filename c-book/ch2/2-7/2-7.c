#include <stdio.h>

void print_invert(int, int, int);
unsigned invert(int, int, int);

int main() {
    print_invert(11, 3, 2);
    return 0;
}

void print_invert(int x, int p, int n) {
    printf("invert(%d, %d, %d):\n", x, p, n);
    printf("%d\n", invert(x, p, n));
}

unsigned invert(int x, int p, int n) {
    unsigned mask;
    mask = (~(~0 << n));
    return (x & ~(mask << p)) | (mask & ~(x & mask << p));
}
