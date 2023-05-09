#include <stdio.h>

#define S_SIZE 100

void lower(char*, char*);

int main() {
    char s[S_SIZE];
    char input[] = "Some String.";

    lower(s, input);
    printf("lower(\"%s\"):\n\"%s\"\n", input, s);

    return 0;
}

void lower(char s[], char in[]) {
    int i;
    for (i = 0; in[i] != '\0'; i++)
        s[i] = (in[i] >= 'A' && in[i] <= 'Z') ? (in[i] - 'A' + 'a') : in[i];
}
