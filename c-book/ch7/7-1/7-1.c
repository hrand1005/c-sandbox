#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum transforms { LOWER, UPPER, INVALID };

int main(int argc, char **argv)
{
    int c;
    enum transforms t;

    if (strstr(argv[0], "lower") != NULL)
        t = LOWER;
    else if (strstr(argv[0], "upper") != NULL)
        t = UPPER;
    else
        t = INVALID;

    while ((c = getchar()) != EOF)
        switch (t) {
        case LOWER:
            printf("%c", tolower(c));
            break;
        case UPPER:
            printf("%c", toupper(c));
            break;
        case INVALID:
            printf("invalid transform type %s\n", argv[0]);
            return 1;
        }
    return 0;
}

