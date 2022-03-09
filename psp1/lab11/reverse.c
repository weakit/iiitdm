// Write a C program to reverse an array using function.
// (Input from the main function and print the reversed array in the main function)

#include <stdio.h>

void reverse(int array[], int n) {
    int i, t, n2 = n / 2;
    n--;

    for (i = 0; i < n2; i++) {
        t = array[n - i];
        array[n - i] = array[i];
        array[i] = t;
    }
}

int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);

    int array[n];

    for(i = 0; i < n; i++)
        scanf("%d", &array[i]);

    reverse(array, n);

    for(i = 0; i < n; i++)
        printf("%d ", array[i]);

    printf("\n");
    return 0;
}


