// Write a c function to implement linear search without using array
// use pointer to integer, and also use malloc function as
// int* a = (int *) malloc(sizeof(int)) * size).
// Call the function from main and return the first available
// position if the element is present else return 0 to main function.

#include <stdio.h>
#include <stdlib.h>

int search(int *head, int length, int elem) {
    for (int i = 0; i < length; i++)
        if (*(head + i) == elem)
            return i + 1;
    return 0;
}

int main() {
    int i, n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = (int *) malloc(sizeof(int) * n);

    printf("Enter %d integers: ", n);

    for (i = 0; i < n; i++)
        scanf("%d", a + i);

    printf("Enter integer to search: ");
    scanf("%d", &x);

    int result = search(a, n, x);

    if (result == 0)
        printf("Element not found.\n");
    else
        printf("Element found at position %d.\n", result);

    return 0;
}