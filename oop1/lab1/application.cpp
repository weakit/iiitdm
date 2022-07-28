#include <cstdio>
#include "stack.h"


int inputInteger() {
    int x;
    scanf("%d", &x);
    return x;
}

void pushNumber(stack *s, int n) {
    while (n) {
        s->push(n % 10);
        n /= 10;
    }
}

int extractNumber(stack *s) {
    int x = 0;
    while (s->size()) {
        x = x * 10 + s->peek();
        s->pop();
    }

    return x;
}

int reverseNumber(int number) {
    int reversedNumber = 0;
    while (number) {
        reversedNumber = reversedNumber * 10 + number % 10;
        number /= 10;
    }
    return reversedNumber;
}

bool checkStackEmpty(stack *s) {
    if (!s->isEmpty()) return false;
    printf("Stack is currently empty. Please input a number first.\n");
    return true;
}

void putNumberInStack(stack *s) {
    printf("Enter a number: ");
    int n = inputInteger();

    if (!n) {
        s->push(0);
        return;
    }

    pushNumber(s, n);
}

void digitsToText(stack *s) {
    if (checkStackEmpty(s)) return;
    while (s->size()) {
        switch (s->peek()) {
            case 0:
                printf("zero ");
                break;
            case 1:
                printf("one ");
                break;
            case 2:
                printf("two ");
                break;
            case 3:
                printf("three ");
                break;
            case 4:
                printf("four ");
                break;
            case 5:
                printf("five ");
                break;
            case 6:
                printf("six ");
                break;
            case 7:
                printf("seven ");
                break;
            case 8:
                printf("eight ");
                break;
            case 9:
                printf("nine ");
        }
        s->pop();
    }
    printf("\n");
}

void reverseNumber(stack *s) {
    if (checkStackEmpty(s)) return;
    int number = reverseNumber(extractNumber(s));
    printf("%d\n", number);
}

void checkPalindrome(stack *s) {
    if (checkStackEmpty(s)) return;
    int number = extractNumber(s);
    int reversedNumber = reverseNumber(number);

    if (number == reversedNumber)
        printf("Number is a palindrome.\n");
    else
        printf("Number is not a palindrome.\n");
}

int main() {
    stack s;
    int choice = -1;

    printf("\n");
    while (choice != 5) {
        if (!s.isEmpty()) {
            printf("Stack contents: ");
            s.display();
            printf("\n\n");
        } else {
            printf("Stack is empty.\n\n");
        }

        printf("1: Get Number\n");
        printf("2: Digits to text\n");
        printf("3: Reverse\n");
        printf("4: Check palindrome\n");
        printf("5: Exit\n");

        printf("\nEnter a choice: ");
        choice = inputInteger();

        printf("\n");

        switch (choice) {
            case 1:
                putNumberInStack(&s);
                break;
            case 2:
                digitsToText(&s);
                break;
            case 3:
                reverseNumber(&s);
                break;
            case 4:
                checkPalindrome(&s);
            case 5:
                break;
            default:
                printf("Please enter a valid choice.\n");
        }

        printf("\n");
    }

    printf("Bye-bye!\n");
    return 0;
}

