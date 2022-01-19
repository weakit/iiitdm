// Write a C program to read a string and
// check if it is a palindrome or not. (using arrays)
#include <stdio.h>

int main() {
    int size, halfOfSize, i;

    printf("Enter the size of the string: ");
    scanf("%d", &size);
    halfOfSize = size / 2;

    char str[size];

    printf("Enter a %d character string: ", size);
    scanf("%s", str);

    for (i = 0; i < halfOfSize; i++) {
        if (str[i] != str[size - i - 1]) {
            printf("\nThe given string is not a palindrome.\n");
            return 0;
        }
    }

    printf("\nThe given string is a palindrome.\n");
    return 0;
}
