#include <stdio.h>

int bitcount(unsigned);

int main() {
    printf("bitcount(15): %d\n", bitcount(15));
    return 0;
}

/**
 * bitcount returns the number of bits set to 1.
 *
 * 2-9
 * Consider the result of the expression x-1 in binary.
 * This will always set the right-most zero bit to zero,
 * because by definition the bits to the right must not
 * hold any value. Thus the difference must be represented
 * with fewer bits. The full statement, x &= (x-1) is thus
 * guaranteed to set the right most 1 to 0, and all other
 * bits to the right will remain 0.
*/
int bitcount(unsigned x) {
    int i;
    for (i = 0; x != 0; i++)
        x &= (x-1);
    return i;
}
