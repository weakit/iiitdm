// Write a C program to read two strings and calculate
// which string will come first in the dictionary.

#include <stdio.h>

void lowerCase(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
        i++;
    }
}

int compare(char a[], char b[]) {
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] < b[i])
            return 1;
        else if (a[i] > b[i])
            return -1;

        i++;
    }

    if (a[i] == '\0' && b[i] != '\0') return 1;
    if (a[i] != '\0') return -1;
    return 0;
}

int main() {
    char a[20], b[20];

    printf("Enter the first word: ");
    scanf("%s", a);

    printf("Enter the second word: ");
    scanf("%s", b);

    lowerCase(a);
    lowerCase(b);

    int result = compare(a, b);

    if (result > 0) printf("%s\n", a);
    else printf("%s\n", b);

    return 0;
}


