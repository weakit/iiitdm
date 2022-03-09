// Write a C program to print the array in the reverse order using recursion

#include <stdio.h>

void reversePrintRecursive(int *p, int count) {
    printf("%d ", *p);
    if (count > 0) reversePrintRecursive(p - 1, count - 1);
}

void reversePrint(int array[], int length) {
    reversePrintRecursive(&array[length - 1], length - 1);
    printf("\n");
}

int main() {
    int i, n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d integers: ", n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    reversePrint(a, n);
}
