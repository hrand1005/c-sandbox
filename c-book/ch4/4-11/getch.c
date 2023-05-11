#include <stdio.h>
#include "calc.h"
#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int getch() {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: buffer full, too many characters\n");
    else
        buf[bufp++] = c;
}