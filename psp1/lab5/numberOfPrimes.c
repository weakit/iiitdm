// Write a C program to read 'n' integers and find the number of prime numbers

#include <stdio.h>

int main() {
    int n, primes = 0, t, i;

    printf("Enter number of integers that will be entered: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);

    for (; n > 0; n--) {
        scanf("%d", &t);

        // naive primality test
        if (t == 2) primes++;
        if (t % 2 == 0) continue;

        // t / 2 always > sqrt(t) for t >= 4
        // works as a semi-decent optimization in the absence of sqrt
        for (i = 3; i < t / 2; i += 2) {
            if (t % i == 0) {
                i = -1;
                break; // break with i negative if not prime
            }
        }

        if (i < 0) continue;
        primes++;  // if i positive, conclude as prime
    }

    printf("Number of primes: %d\n", primes);

    return 0;
}
