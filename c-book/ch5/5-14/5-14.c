#include <stdio.h>
#include <string.h>
#include "5-14.h"

#define MAXLINES 5000
char * lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right,
           int (*less)(void *, void *));
int numcmp(char *, char *);
int rev(void *, void *);

static int (*comp)(void *, void *) = (int (*)(void *, void *))strcmp;

int main(int argc, char *argv[])
{
    int nlines;
    int c, numeric, reverse, err;

    err = numeric = reverse = 0;
    while (--argc > 0 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch(c) {
            case 'n':
                numeric = 1;
                comp = (int (*)(void *, void *))numcmp;
                break;
            case 'r':
                reverse = 1;
                break;
            default:
                printf("sort lines: illegal option %c\n", c);
                argc = 0;
                err = 1;
            }
    if (argc > 1)
        printf("Usage: ./a.out -n -r\n");
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void **) lineptr, 0, nlines-1,
              (int (*)(void *,void *))(reverse ? rev : comp));
        writelines(lineptr, nlines);
    } else {
        printf("input too big to sort\n");
        err = 1;
    }
    return err;
}

/* rev: provides opposite output for static comp func */
int rev(void *a, void *b)
{
    return (((*comp)(a, b)) < 0) ? 1 : -1;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right,
           int (*less)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
        return;
    swap(v, left, (left+right)/2);  /* v[left] becomes our pivot */
    last = left;                    /* last is an index such that v[last] < v[left] */
    for (i = left+1; i <= right; i++)
        if ((*less)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);            /* assign pivot to final location */
    qsort(v, left, last-1, less);
    qsort(v, last+1, right, less);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define MAXLEN 1000
int getline2(char *, int);
char *alloc(int);

/* readlines: read input lines, if exceeds capacity return -1 */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline2(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

int getline2(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/* alloc: returns pointer to n characters, or NULL if exceeds capacity */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else
        return 0;
}
