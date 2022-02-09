// Write a C program to read rational numbers using structures and do rational number multiplication.

#include <stdio.h>

struct Rational {
    int n;
    int d;
};

int main() {
    struct Rational a, b, result;
    printf("Enter 2 numbers in a/b format: ");

    scanf("%d / %d", &a.n, &a.d);
    scanf("%d / %d", &b.n, &b.d);

    if (a.d == 0 || b.d == 0) {
        printf("Denominators can't be zero");
        return -1;
    }

    if (a.d < 0) {
        a.d *= -1;
        a.n *= -1;
    }

    if (b.d < 0) {
        b.d *= -1;
        b.n *= -1;
    }

    result.n = a.n * b.n;
    result.d = a.d * b.d;

    if (result.n == 0) {
        printf("0");
        return 0;
    }

    int x = result.n, y = result.d, gcd;
    if (x < 0) x = -x;

    while (x && y) {
        x %= y;
        if (x) y %= x;
    }

    gcd = x + y;

    result.n /= gcd;
    result.d /= gcd;

    if (result.d == 1) printf("\n%d\n", result.n);
    else printf("\n%d/%d\n", result.n, result.d);

    return 0;
}
