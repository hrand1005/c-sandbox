#include <stdio.h>

void print_squeeze(char[], char[]);
void squeeze(char[], char[]);

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

    print_squeeze(word1, sub1);
    print_squeeze(word2, sub2);
    print_squeeze(word3, sub3);
    print_squeeze(word4, sub4);
    print_squeeze(word5, sub5);

    return 0;
}

void print_squeeze(char word[], char sub[]) {
    printf("squeeze(\"%s\", \"%s\"): ", word, sub);
    squeeze(word, sub);
    printf("\"%s\"\n\n", word);
}

void squeeze(char word[], char sub[]) {
    int i, j, k, contains;

    for (i = j = 0; word[i] != '\0'; i++) {
        for (contains = k = 0; sub[k] != '\0' && !contains; k++)
            contains = (word[i] == sub[k]);
        if (!contains)
            word[j++] = word[i];
    }
    word[j] = '\0';
}
