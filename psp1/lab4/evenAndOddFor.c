// Write a C program that reads n integers and prints the difference between
// the sum of even integers and the sum of odd integers using the for loop

#include <stdio.h>

int main() {
    int number, evenSum = 0, oddSum = 0, count = 0, difference;

    printf("Enter number of integers: ");
    scanf("%d", &count);

    printf("Enter %d integers(s): ", count);

    for (; count > 0; count--){
        scanf("%d", &number);

        if (number % 2 == 0) evenSum += number;
        else oddSum += number;
    }

    difference = evenSum - oddSum;
    if (difference < 0) difference *= -1;

    printf("Difference between sum of even and odd numbers: %d\n", difference);

    return 0;
}
