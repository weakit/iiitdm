// Write a C program to read the value in dollar and prints the corresponding value in rupees
// Conversion rate as of today: 74.72

#include <stdio.h>

int main() {
    float dollars, rupees;

    printf("Please enter value in dollars: ");
    scanf("%f", &dollars);

    rupees = dollars * 74.72f;

    printf("\n%f dollars = %f rupees\n", dollars, rupees);

    return 0;
}
