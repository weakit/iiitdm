#include <stdio.h>
#include <stdlib.h>

int sum (int* head, int size) {
    int sumValue = 0, i = -1;
    while (++i < size) sumValue += *(head + i);
    return sumValue;
}

int main() {
    int n, i = -1;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int* head = (int*) malloc(n * sizeof(int));

    if (head == NULL) {
        printf("Unable to allocate memory.\n");
        return 1;
    }

    printf("\nEnter %d integers: ", n);
    while(++i < n) scanf("%d", head + i);

    printf("Sum of Numbers: %d\n", sum(head, n));
    
    free(head);
    return 0;
}
