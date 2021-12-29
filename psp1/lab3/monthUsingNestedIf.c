// Write a C program to read a month of a number and print the number of days in the month using a nested if statement

#include <stdio.h>

int main() {
    int month;

    printf("Enter month number: ");
    scanf("%d", &month);

    if (month > 0 && month <= 12) {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            printf("\n31 days.\n");
        else if (month == 2)
            printf("\n28 days.\n");
        else
            printf("\n30 days.\n");

        return 0;
    }

    printf("Invalid month.\n");
    return -1;
}

