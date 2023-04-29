#include <stdio.h>

int main() {
    float fahr = 0;
    int step = 20;

    printf("F\tC\n--------------\n");
    while (fahr <= 300) {
        float cels = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%3.1f\n", fahr, cels);
        fahr += step;
    }
    return 0;
}
