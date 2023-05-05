#include <stdio.h>
#define MAXLINE 100
#define MAXLINECOUNT 100

int get_line(char line[], int maxline);
int right_trim(char line[], int len);
void copy(char dest[], char src[]);

int main() {
    int i, j;
    int len;
    char line[MAXLINE];
    char lines[MAXLINECOUNT][MAXLINE];

    i = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        int len = right_trim(line, len);
        if (len > 1 || (len == 1 && line[0] != '\n')) {
            copy(lines[i], line);
            i++;
        }
    }

    for (j = 0; j < i; j++) 
        printf("%s", lines[j]);

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

/* right_trim: trims spaces, tabs from end of the line, returns new length */
int right_trim(char s[], int len) {
    int i, nl;

    nl = 0;
    i = len - 1;
    if (s[i] == '\n') {
        nl = 1;
        s[i] = '\0';
        i--;
    }

    while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
        s[i] = '\0';
        i--;
    }

    i++;
    if (nl)
        s[i] = '\n';

    return i+1;
}

/* copy: copy 'src' into 'dest'; assume dest is big enough */
void copy(char dest[], char src[]) {
    int i;

    i = 0;
    while ((dest[i] = src[i]) != '\0')
        i++;
}
