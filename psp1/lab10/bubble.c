//  Write a C program to sort the numbers (bubble sort) using function.

#include <stdio.h>

void bubble(int array[], int n) {
    int i, j, t;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                t = array[j + 1];
                array[j + 1] = array[j];
                array[j] = t;
            }
        }
}

int main() {
    int n, i;
    printf("Enter number of integers to be entered: ");

    scanf("%d", &n);

    printf("Enter %d numbers: ", n);

    int a[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    bubble(a, n);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
