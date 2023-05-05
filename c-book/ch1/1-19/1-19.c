#include <stdio.h>
#define MAXLINE 100
#define MAXLINECOUNT 100

int get_line(char line[], int maxline);
void reverse(char line[], int len);
void copy(char dest[], char src[]);

int main() {
    int i, j;
    int len;
    char line[MAXLINE];
    char lines[MAXLINECOUNT][MAXLINE];

    i = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse(line, len);
        copy(lines[i], line);
        i++;
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

/* reverse: reverses the provided string; newline characters not moved */
void reverse(char s[], int len) {
    int l, r, temp;
    
    r = len - 1;
    while (r >= 1 && s[r] == '\n')
        r--;

    l = 0;
    while (l < r) {
        temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

/* copy: copy 'src' into 'dest'; assume dest is big enough */
void copy(char dest[], char src[]) {
    int i;

    i = 0;
    while ((dest[i] = src[i]) != '\0')
        i++;
}
