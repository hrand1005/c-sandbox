#include <stdio.h>
#define MAXLINE 100

int get_line(char[], int);

int main() {
    char line[MAXLINE];

    while (get_line(line, MAXLINE))
        printf("line: %s", line);

    return 0;
}

int get_line(char s[], int lim) {
    int i, c;

    i = 0;
    while (i<lim-1) {
        if ((c=getchar()) == '\n')
            break;
        if (c == EOF)
            break;
        s[i] = c;
        i++;
    }

    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    return i;
}
