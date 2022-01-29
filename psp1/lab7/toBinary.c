// Write a C program to convert decimal number to binary number
#include <stdio.h>

int main() {
    int decimal, decimalCopy, power = 1;

    printf("Enter a number in decimal: ");
    scanf("%d", &decimal);

    decimalCopy = decimal;

    while (decimalCopy > 1) {
        decimalCopy = decimalCopy >> 1;
        power = power << 1;
    }

    while (power > 0) {
        if (decimal >= power) {
            decimal -= power;
            printf("1");
        } else
            printf("0");

        power = power >> 1;
    }

    printf("\n");

    return 0;
}

