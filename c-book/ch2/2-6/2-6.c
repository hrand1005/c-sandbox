#include <stdio.h>

void print_setbits(int, int, int, int);
unsigned setbits(int, int, int, int);

int main() {
    print_setbits(11, 3, 2, 3);
    return 0;
}

void print_setbits(int x, int p, int n, int y) {
    printf("setbits(%d, %d, %d, %d):\n", x, p, n, y);
    printf("%d\n", setbits(x, p, n, y));
}

unsigned setbits(int x, int p, int n, int y) {
    unsigned mask;
    mask = (~(~0 << n));
    return (x & ~(mask << p)) | ((mask & y) << p);
}
