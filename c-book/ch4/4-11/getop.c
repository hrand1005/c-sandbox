#include <stdio.h>
#include <ctype.h>
#include "calc.h"
#define UNSET ' ';

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    static int mem = UNSET;
    int i, c;

    if (mem != ' ' && mem != '\t') {
        s[0] = c = mem;
        mem = UNSET;
    }
    else
        while ((s[0] = c = getch()) == ' ' || c == '\t')
            ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));
            ;
    s[i] = '\0';
    if (c != EOF)
        mem = c;
    return NUMBER;
}