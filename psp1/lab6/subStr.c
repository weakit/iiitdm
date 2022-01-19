// Write a C program to read two strings and check if
// one string is a substring of the other string. (using arrays)

#include <stdio.h>

int main() {
    int size, subSize, compSize, i, j;

    printf("Enter the size of the string: ");
    scanf("%d", &size);
    char str[size];
    printf("Enter a %d character string: ", size);
    scanf("%s", str);

    printf("\nEnter the size of the substring: ");
    scanf("%d", &subSize);
    char subStr[subSize];
    printf("Enter a %d character substring: ", subSize);
    scanf("%s", subStr);

    if (subSize > size) {
        printf("Substring cannot be longer than the original string.");
        return -1;
    }

    compSize = size - subSize + 1;  // size to be measured

    for (i = 0; i < compSize; i++) {
        for (j = 0; j < subSize; j++)
            if (str[i + j] != subStr[j])
                break;

        if (j == subSize) {
            printf("\nSubstring found.\n");
            return 0;
        }
    }

    printf("\nNo substring found.\n");
    return 0;
}
