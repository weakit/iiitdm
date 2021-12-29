// Write a C program to read the value in rupees and prints the corresponding value in dollar
// Conversion rate as of today: 74.72

#include <stdio.h>

int main() {
    float dollars, rupees;

    printf("Please enter value in rupees: ");
    scanf("%f", &rupees);

    dollars = rupees / 74.72f;

    printf("\n%f rupees = %f dollars\n", rupees, dollars);

    return 0;
}
