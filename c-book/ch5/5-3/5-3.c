#include <stdio.h>
#include <stdlib.h>
#define MAXSTRING 100

void strcat2(char *, char *);

int main()
{
    char s[MAXSTRING] = "hello, ";
    char *suffix = "world";

    printf("string: %s\nsuffix: %s\n", s, suffix);

    strcat2(s, suffix);
    printf("concatenated: %s\n", s);
}

void strcat2(char *s, char *suffix)
{
    while (*++s != '\0')
        ;
    while ((*s++ = *suffix++) != '\0')
        ;
}
