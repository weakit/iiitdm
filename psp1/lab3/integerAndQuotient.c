// Write a C program to read two integers m and n and print quotient and remainder when m/n

#include <stdio.h>

int main() {
    int m, n;

    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);

    printf("\nQuotient: %d\nRemainder: %d\n", m / n, m % n);

    return 0;
}