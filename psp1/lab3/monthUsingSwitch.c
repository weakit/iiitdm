// Write a C program to read a month of a number and print the number of days in the month using a switch statement

#include <stdio.h>

int main() {
    int month;

    printf("Enter month number: ");
    scanf("%d", &month);

    if (month <= 0 || month > 12) {
        printf("Invalid month.\n");
        return -1;
    }

    switch(month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("\n31 days.\n");
            break;
        case 2:
            printf("\n28 days.\n");
            break;
        default:
            printf("\n30 days.\n");
    }
}

