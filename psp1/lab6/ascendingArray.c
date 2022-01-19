// Write a C program to read 'n' integers into an array
// and check if they are in ascending order. (using arrays)

#include <stdio.h>

int main() {
    int size, i;

    printf("Enter the number of integers: ");
    scanf("%d", &size);

    int a[size];

    printf("\nEnter %d integers: ", size);

    for (i = 0; i < size; i++) scanf("%d", &a[i]);

    for (i = 1; i < size; i++)
        if (a[i - 1] > a[i]) {
            printf("\nThe integers were not entered in ascending order.\n");
            return 0;
        }

    printf("\nThe integers were entered in ascending order.\n");
    return 0;
}
