#include <stdio.h>

#define POS_INFINITY 1e400
#define NEG_INFINITY (-POS_INFINITY)
#define NEG_ZERO (-1.0/POS_INFINITY)

int main()
{
    printf("1e10: %f\n", 1e10);
    printf("positive infinity: %lf\n", POS_INFINITY);
    printf("negative infinity: %lf\n", NEG_INFINITY);
    printf("negative zero: %lf\n", NEG_ZERO);
    printf("-inf * -inf: %lf\n", NEG_INFINITY * NEG_INFINITY);
    return 0;
}
