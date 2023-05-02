#include <stdio.h>

float fahr_to_cels(float f);

int main() {
    float fahr = 0;
    int step = 20;

    printf("F\tC\n--------------\n");
    while (fahr <= 300) {
        printf("%3.0f\t%3.1f\n", fahr, fahr_to_cels(fahr));
        fahr += step;
    }
    return 0;
}

float fahr_to_cels(float f) {
    return (5.0 / 9.0) * (f - 32.0);
}
