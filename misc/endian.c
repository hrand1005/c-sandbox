#include <stdio.h>
#include <stdint.h>

typedef unsigned char *byteptr;
void show_int(int);
void show_bytes(byteptr, size_t);

int main()
{
    int x;

    printf("\"Endian-ness\" refers to the order in which bytes are stored in memory.\n"
           "\"Big Endian\" is the ordering of bytes from most to least significant.\n"
           "\"Little Endian\" is the ordering of bytes from least to most significant.\n");

    x = 12345678;
    printf("\nConsider int x:\n%d\nAnd its hex representation:\n0x%x\n", x, x);
    printf("\nIn a big-endian system, this printed hex is also how the bytes are ordered " 
           "in memory.\nBytes appear from most-to-least significant reading left-to-right.\n"
           "Let's test the endian-ness of this system.\n");
    printf("\nShowing hex byte-by-byte, as ordered in memory: \n");
    show_int(x);
}

void show_int(int x)
{
    show_bytes((byteptr) &x, sizeof(x));
}

void show_bytes(byteptr bp, size_t len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%.2x%s", *bp++, (i < len-1) ? " " : "");
    printf("\n");
}
