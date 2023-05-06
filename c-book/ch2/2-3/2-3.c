#include <ctype.h>
#include <stdio.h>
#include <string.h>

void print_htoi(const char[]);
int htoi(const char[], int);
int hctoi(const char);

int main() {
    print_htoi("0xabc");
    print_htoi("0Xabc");
    print_htoi("abc");
    print_htoi("ABC");
    print_htoi("BC");
    print_htoi("C");
}

void print_htoi(const char s[]) {
    printf("hex: %6s\tdecimal: %6d\n", s, htoi(s, strlen(s)));
}

/* htoi returns the decimal representation of the provided hex string
 *  Assumes a valid hex string representation.
 *  0x or 0X prefixes permitted.
 *  0-9, a-f, A-F are permitted. */
int htoi(const char s[], int len) {
    int i, dec;

    i = 0;
    if (len >= 2) {
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            i = 2;
    }

    dec = 0;
    while (s[i] != '\0') {
        dec = dec * 16 + hctoi(s[i]);
        i++;
    }

    return dec;
}

/* hctoi returns the decimal representation of the provided hex char */
int hctoi(const char c) {
    if (isdigit(c))
        return c - '0';
    return tolower(c) - 'a' + 10;
}
