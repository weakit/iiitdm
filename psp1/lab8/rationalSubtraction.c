// Write a C program to read rational numbers using structures and do rational number subtraction

#include <stdio.h>

struct Rational {
    int n;
    int d;
};

int main() {
    struct Rational a, b, sum;
    printf("Enter 2 numbers in a/b format: ");

    // accept rationals
    scanf("%d / %d", &a.n, &a.d);
    scanf("%d / %d", &b.n, &b.d);

    // check denominator
    if (a.d == 0 || b.d == 0) {
        printf("Denominators can't be zero");
        return -1;
    }

    // correct negative denominators
    if (a.d < 0) {
        a.d *= -1;
        a.n *= -1;
    }

    if (b.d < 0) {
        b.d *= -1;
        b.n *= -1;
    }

    // perform subtraction
    if (a.d == b.d) {
        sum.n = a.n - b.n;
        sum.d = a.d;
    } else {
        sum.n = a.n * b.d - b.n * a.d;
        sum.d = a.d * b.d;
    }

    // handle zero result
    if (sum.n == 0) {
        printf("0");
        return 0;
    }

    // find gcd
    int x = sum.n, y = sum.d, gcd;
    if (x < 0) x = -x;

    while (x && y) {
        x %= y;
        if (x) y %= x;
    }

    gcd = x + y;

    // simplify fraction
    sum.n /= gcd;
    sum.d /= gcd;

    // if denominator = 1, print only numerator
    if (sum.d == 1) printf("\n%d\n", sum.n);
    else printf("\n%d/%d\n", sum.n, sum.d);

    return 0;
}
