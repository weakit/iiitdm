// Write a C program to print the fibonacci series using function.

#include <stdio.h>

void fib(int n) {
    int a = 0, b = 1, t;

    for (; n > 0; n--) {
        printf("%d ", a);
        t = a + b;
        a = b;
        b = t;
    }

    printf("\n");
}

int main() {
    int n;
    printf("Enter a number: ");

    scanf("%d", &n);

    fib(n);

    return 0;
}

