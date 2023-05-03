#include <stdio.h>
#define MAXLINE 100
#define MAXLINECOUNT 100

int get_line(char line[], int maxline);
void copy(char dest[], char src[]);

int main() {
    int i, j;
    int len;
    char line[MAXLINE];
    char lines[MAXLINECOUNT][MAXLINE];

    i = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len >= 80) {
            copy(lines[i], line);
            i++;
        }
    }

    printf("printing lines over 80 characters:\n");
    for (j = 0; j < i; j++) 
        printf("%s\n", lines[j]);

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

    return i;
}

/* copy: copy 'src' into 'dest'; assume dest is big enough */
void copy(char dest[], char src[]) {
    int i;

    i = 0;
    while ((dest[i] = src[i]) != '\0')
        i++;
}
