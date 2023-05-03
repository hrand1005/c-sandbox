#include <stdio.h>
#define MAXLINE 100

int get_line(char line[], int maxline);
void copy(char dest[], char src[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) {
        printf("longest line is %d characters.\n", max);
        printf("Printing longest (LIMIT %d):\n%s\n", MAXLINE-1, longest);
    }
    return 0;
}

/* get_line: read up to MAXLINE characters of a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c !='\n'; i++)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    while ((c = getchar()) != EOF && c != '\n') 
        i++;

    return i;
}

/* copy: copy 'src' into 'dest'; assume dest is big enough */
void copy(char dest[], char src[]) {
    int i;

    i = 0;
    while ((dest[i] = src[i]) != '\0')
        i++;
}
