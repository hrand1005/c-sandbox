#include <stdio.h>

void print_any(char[], char[]);
int any(char[], char[]);

int main() {
    char word1[] = "systems";
    char sub1[] = "st";

    char word2[] = "systems";
    char sub2[] = "ym";

    char word3[] = "applications";
    char sub3[] = "al";

    char word4[] = "applications";
    char sub4[] = "is";

    char word5[] = "systems, applications";
    char sub5[] = "qz";

    print_any(word1, sub1);
    print_any(word2, sub2);
    print_any(word3, sub3);
    print_any(word4, sub4);
    print_any(word5, sub5);

    return 0;
}

void print_any(char word[], char sub[]) {
    printf("any(\"%s\", \"%s\"): ", word, sub);
    printf("%d\n\n", any(word, sub));
}

int any(char word[], char sub[]) {
    int i, j;

    for (i = 0; word[i] != '\0'; i++) {
        for (j = 0; sub[j] != '\0'; j++)
            if (word[i] == sub[j])
                return i;
    }

    return -1;
}
