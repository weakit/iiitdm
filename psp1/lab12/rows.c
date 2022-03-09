// Write a C program to find the sum of each row in the given matrix using functions.

#include <stdio.h>

int main() {
    int x, y, i, j;

    printf("Enter width of matrix: ");
    scanf("%d", &x);
    printf("Enter height of matrix: ");
    scanf("%d", &y);

    int a[y][x];
    int r[y];

    printf("\nEnter elements of matrix:\n\n");

    for (i = 0; i < y; i++)
        for (j = 0; j < x; j++)
            scanf("%d", &a[i][j]);

    for (y--; y >= 0; y--) {
        r[y] = 0;
        for (i = 0; i < x; i++) r[y] += a[y][i];
    }

    printf("\n");
}

