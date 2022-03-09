// Write a C program to find the sum of elements in the odd columns and even rows

#include <stdio.h>

int main() {
    int x, y, i, j, sum = 0;

    printf("Enter width of matrix: ");
    scanf("%d", &x);
    printf("Enter height of matrix: ");
    scanf("%d", &y);

    int a[y][x];

    printf("\nEnter elements of matrix:\n\n");

    for (i = 0; i < y; i++)
        for (j = 0; j < x; j++)
            scanf("%d", &a[i][j]);

    // odd columns
    for (i = 0; i < y; i++)
        for (j = 0; j < x; j += 2)
            sum += a[i][j];

    // even rows
    for (i = 1; i < y; i += 2)
        for (j = 1; j < x; j += 2)
            sum += a[i][j];

    printf("\n%d\n", sum);
}

