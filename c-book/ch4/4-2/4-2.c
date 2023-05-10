#include <stdio.h>
#include <ctype.h>

double atof(char[]);
int atoi(char[]);

int main() {
    char input[] = "1234.5678";
    char sciinput[] = "12.34e3";
    char nsciinput[] = "12.34e-3";

    printf("atof(\"%s\"):\n%f\n", input, atof(input));
    printf("atof(\"%s\"):\n%f\n", sciinput, atof(sciinput));
    printf("atof(\"%s\"):\n%f\n", nsciinput, atof(nsciinput));
}

double atof(char s[]) {
    double val, pow;
    int i, j, sign, exp;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i]-'0');
    if (s[i] == '.')
        i++;
    for (pow = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        pow *= 10;
    }
    if (s[i] == 'e') {
        i++;
        exp = atoi(&s[i]);
        if (exp < 0) {
            for (j = 0; j < -exp; j++)
                pow *= 10;
        } else {
            for (j = 0; j < exp; j++)
                val *= 10;
        }
    }
    return sign * val / pow;
}

int atoi(char s[]) {
    int val, i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0; isdigit(s[i]); i++)
        val = 10 * val + (s[i]-'0');
    return sign * val;
}