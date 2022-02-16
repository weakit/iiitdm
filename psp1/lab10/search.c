// Write a C program for linear search using functions.

#include <stdio.h>

void search(int array[], int n, int x) {
    for (n--; n >= 0; n--) {
        if (array[n] == x) {
            printf("Element found.\n");
            return;
        }
    }

    printf("Element not found.\n");
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

    printf("Enter element to be searched: ");

    scanf("%d", &i);

    search(a, n, i);
}

