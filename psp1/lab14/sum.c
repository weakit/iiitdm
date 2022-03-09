// Write a C program to add the elements of an array using recursion

#include <stdio.h>

int sumRecursive(int *p, int count) {
    if (count > 0)
        return *p + sumRecursive(p - 1, count - 1);
    return 0;
}

int sum(int array[], int length) {
    return sumRecursive(&array[length - 1], length);
}

int main() {
    int i, n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d integers: ", n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("%d\n", sum(a, n));
}
