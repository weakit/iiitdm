// Write a c function to implement bubble sort without using array
// Use pointer to integer, and also use malloc function as
// int* a = (int *) malloc(sizeof(int)) * size).
// Call the function from main after reading the sequence to sort.
// After function call,  print the sorted sequence in main function.

#include <stdio.h>
#include <stdlib.h>

void sort(int *head, int length) {
    int i, j, temp;
    for (i = 0; i < length - 1; i++)
        for (j = 0; j < length - 1 - i; j++)
            if (*(head + j) > *(head + j + 1)) {
                // swap
                temp = *(head + j);
                *(head + j) = *(head + j + 1);
                *(head + j + 1) = temp;
            }
}


int main() {
    int i, n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = (int *) malloc(sizeof(int) * n);

    printf("Enter %d integers: ", n);

    for (i = 0; i < n; i++)
        scanf("%d", a + i);

    sort(a, n);

    for (i = 0; i < n; i++)
        printf("%d ", *(a + i));

    printf("\n");
    return 0;
}
