#include <stdio.h>
#include <limits.h>

void uchar_limits(void);
void schar_limits(void);
void ushort_limits(void);
void sshort_limits(void);
void uint_limits(void);
void sint_limits(void);
void ulong_limits(void);
void slong_limits(void);

int main() {
    uchar_limits();
    schar_limits();
    ushort_limits();
    sshort_limits();
    uint_limits();
    sint_limits();
    ulong_limits();
    slong_limits();
}

void uchar_limits() {
    printf("UCHAR_MAX: %u\n", UCHAR_MAX);

    unsigned char uc = 0;
    printf("computed max: %u\n", --uc);

    printf("\n");
}

void schar_limits() {
    signed char p, c;

    printf("SCHAR_MIN: %d\n", SCHAR_MIN);
    printf("SCHAR_MAX: %d\n", SCHAR_MAX);
    printf("CHAR_MIN: %d\n", CHAR_MIN);
    printf("CHAR_MAX: %d\n", CHAR_MAX);

    p = 0;
    c = 1;
    while (c >= 0) {
        p = c;
        c <<= 1;
        c |= 1;
    }
    c ^= p;

    printf("computed min: %d\n", c);
    printf("computed max: %d\n", p);

    printf("\n");
}

void ushort_limits() {
    printf("USHRT_MAX: %u\n", USHRT_MAX);

    unsigned short us = 0;
    printf("computed max: %u\n", --us);

    printf("\n");
}

void sshort_limits() {
    signed short p, c;

    printf("SSHRT_MIN: %d\n", SHRT_MIN);
    printf("SSHRT_MAX: %d\n", SHRT_MAX);

    p = 0;
    c = 1;
    while (c >= 0) {
        p = c;
        c <<= 1;
        c |= 1;
    }
    c ^= p;

    printf("computed min: %d\n", c);
    printf("computed max: %d\n", p);

    printf("\n");
}

void uint_limits() {
    printf("UINT_MAX: %u\n", UINT_MAX);

    unsigned int ui = 0;
    printf("computed max: %u\n", --ui);

    printf("\n");
}

void sint_limits() {
    signed int p, c;

    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);

    p = 0;
    c = 1;
    while (c >= 0) {
        p = c;
        c <<= 1;
        c |= 1;
    }
    c ^= p;

    printf("computed min: %d\n", c);
    printf("computed max: %d\n", p);

    printf("\n");
}

void ulong_limits() {
    printf("ULONG_MAX: %lu\n", ULONG_MAX);

    unsigned long ul = 0;
    printf("computed max: %lu\n", --ul);

    printf("\n");
}

void slong_limits() {
    signed long p, c;

    printf("INT_MIN: %ld\n", LONG_MIN);
    printf("INT_MAX: %ld\n", LONG_MAX);

    p = 0;
    c = 1;
    while (c >= 0) {
        p = c;
        c <<= 1;
        c |= 1;
    }
    c ^= p;

    printf("computed min: %ld\n", c);
    printf("computed max: %ld\n", p);

    printf("\n");
}
