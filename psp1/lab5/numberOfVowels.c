// Write a C program to read 'n' characters and find the number of vowels

#include <stdio.h>

int main() {
    int n, vowels = 0;
    char c;

    printf("Enter the number of characters: ");
    scanf("%d", &n);
    scanf("%c", &c);

    printf("Enter %d characters: ", n);

    for (; n > 0; n--) {
        scanf("%c", &c);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            vowels++;
    }

    printf("The number of vowels are: %d\n", vowels);

    return 0;
}
