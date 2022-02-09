// Write a C program to read a binary number as a string(%s) and convert it into a decimal number.

#include <stdio.h>

int main() {
    int n = 0;
    char c;

    printf("Enter a number in binary: ");

    scanf("%c", &c);

    while (c != '\n') {
        
        // ignore characters that are not 0 or 1.
        if (c == '1') {
            n <<= 1;
            n += 1;
        } else if (c == '0') {
            n <<= 1;
        }

        scanf("%c", &c);
    }

    printf("%d\n", n);
}

