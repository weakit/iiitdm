// Write a C program to read 'n' integers and find the second minimum integer

#include <stdio.h>

int main() {
    int n, min, secondMin, temp;

    printf("Enter the number of integers that will be entered: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);

    // quit if no of integers < 2
    if (n < 2) {
        printf("Can't compare a single integer");
        return -1;
    }

    // accept initial values
    scanf("%d", &min);
    scanf("%d", &secondMin);

    // swap if required
    if (min > secondMin) {
        temp = min;
        min = secondMin;
        secondMin = temp;
    }

    // account for accepted values
    for (; n > 2; n--) {
        scanf("%d", &temp);

        // if smaller than both, move values around as required
        if (temp < min) {
            secondMin = min;
            min = temp;
        } else if (temp < secondMin) // if only smaller than secondMin,
            secondMin = temp;        // but larger than actual minimum
    }

    printf("\nSecond Minimum: %d\nMinimum: %d\n", secondMin, min);
    return 0;
}
