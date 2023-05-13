#include <stdio.h>
#include <ctype.h>
#define MAXINTS 100
#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getint(int*);
static char buf[BUFSIZE];
static int bufp = 0;


int main()
{
    int i, j, isint;
    int ints[MAXINTS];

    while ((isint = getint(&ints[i])) != EOF && i < MAXINTS) {
        if (isint != 0)
            i++;
        else {
            printf("encountered non-int: %d\n, EOF: %d\n", getch(), EOF);
        }
    }
    
    printf("\nINTS READ:\n");
    for (j = 0; j < i; j++)
        printf("%d\n", ints[j]);

    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c) && c != EOF) {
        ungetch(c);
        return 0;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch() {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: buffer full, too many characters\n");
    else
        buf[bufp++] = c;
}