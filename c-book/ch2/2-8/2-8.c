#include <stdio.h>

void print_rightrot(int, int);
unsigned rightrot(int, int);
int intbits();

int main() {
    print_rightrot(1, 0);
    return 0;
}

void print_rightrot(int x, int n) {
    printf("rightrot(%d, %d):\n", x, n);
    printf("%d\n", rightrot(x, n));
}

unsigned rightrot(int x, int n) {
    int i, size;
    size = intbits();
    for (i = 0; i < n; i++) {
        x = (x >> 1) | ((x & 1) << (size-1));
    }
    return x;
}

int intbits() {
    unsigned i, x;
    x = ~0;
    i = 0;
    while (x != 0) {
        x >>= 1;
        i++;
    }
    return i;
}
