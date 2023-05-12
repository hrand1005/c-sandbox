#include <stdio.h>
#define swap(t, x, y) { t temp = x; x = y; y = temp; }

int main() {
    int a = 5;
    int b = 9;
    printf("a: %d, b: %d\n", a, b);
    printf("swapping a and b...\n");
    swap(int, a, b);
    printf("a: %d, b: %d\n", a, b);

    return 0;
}