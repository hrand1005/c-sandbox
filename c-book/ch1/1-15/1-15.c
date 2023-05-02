#include <stdio.h>

float cels_to_fahr(float c);

int main() {
    float cels = 0;
    int step = 20;

    printf("C\tF\n------------\n");
    while (cels <= 300) {
        printf("%3.0f\t%3.0f\n", cels, cels_to_fahr(cels));
        cels += step;
    }
    return 0;
}

float cels_to_fahr(float c) {
    return (9.0 / 5.0) * c + 32.0;
}
