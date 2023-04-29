#include <stdio.h>

enum table {
    LOWER = 0,
    UPPER = 300,
    STEP = 20,
};

int main() {
    int fahr;

    printf("%3c %6c\n", 'F', 'C');
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

    return 0;
}
