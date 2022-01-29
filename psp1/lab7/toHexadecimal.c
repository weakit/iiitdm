// Write a C program to convert a decimal number to Hexadecimal.

#include <stdio.h>

int main() {
    int decimal, decimalCopy, power = 1, count;

    printf("Enter a number in decimal: ");
    scanf("%d", &decimal);

    decimalCopy = decimal;

    while (decimalCopy > 15) {
        decimalCopy = decimalCopy >> 4;
        power = power << 4;
    }

    while (power > 0) {
        count = 0;

        while (decimal >= power) {
            decimal -= power;
            count++;
        }

        power = power >> 4;

        if (count > 9) {
            if (count == 15) printf("F");
            else if (count == 14) printf("E");
            else if (count == 13) printf("D");
            else if (count == 12) printf("C");
            else if (count == 11) printf("B");
            else printf("A");
        } else printf("%d", count);
    }

    printf("\n");
}

