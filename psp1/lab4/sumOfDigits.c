// Write a C program to read n digit number and find the
// sum of digits using for loop.

#include <stdio.h>

int main() {
    int number, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    printf("The sum is: %d\n", sum);

    return 0;
}
