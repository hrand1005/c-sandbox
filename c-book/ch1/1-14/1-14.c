#include <stdio.h>
#include <string.h>

#define ALPHABET_LENGTH 26

int main() {
    int c;
    int lower[ALPHABET_LENGTH];

    memset(lower, 0, sizeof(int) * ALPHABET_LENGTH);

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z')
            lower[c-'a']++;
    }

    printf("Histogram of letter frequencies:\n");
    for (int i = 0; i < ALPHABET_LENGTH; i++) {
        printf("%c: ", i+'a');
        for (int j = 0; j < lower[i]; j++) 
            printf("X");
        printf("\n");
    }

    return 0; 
}
