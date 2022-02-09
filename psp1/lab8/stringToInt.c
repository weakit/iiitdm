//  Write a C program to read a number as a string, convert it into integer, then add 1 to and display the output.

#include <stdio.h>

// naive approach

int main() {
    int i = 0, n = 0, x;
    char str[11];

    printf("Enter a number: ");
    scanf("%s", str);

    while (str[i] != 0 && i < 12) {
        x = str[i];

        // ignore non-digits
        if (47 < x && x < 58) {
            n *= 10;
            n += x - 48;
        }

        i++;
    }

    printf("%d\n", n + 1);
}


