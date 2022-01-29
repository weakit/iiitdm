// Write a C program to convert binary number to decimal number.

#include <stdio.h>

int main() {
    int decimal = 0, power = 1, bits;
    char c;

    printf("Enter number of bits that will be entered: ");
    scanf("%d", &bits);

    power = power << (bits - 1);

    scanf("%c", &c);

    while (bits > 0) {
        scanf("%c", &c);
        if (c == '1')
            decimal += power;
        else if (c != '0') {
            printf("Invalid Input.");
            return -1;
        }

        power = power >> 1;
        bits--;
    }

    printf("%d\n", decimal);

    return 0;
}
