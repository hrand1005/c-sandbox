#include <stdio.h>

int main() {
    float cels = 0;
    int step = 20;

    printf("C\tF\n------------\n");
    while (cels <= 300) {
        float fahr = (9.0 / 5.0) * cels + 32.0;
        printf("%3.0f\t%3.0f\n", cels, fahr);
        cels += step;
    }
    return 0;
}
