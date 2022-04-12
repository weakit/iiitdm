#include <stdio.h>
#include <stdlib.h>

int findEnd(char* head) {
    int i = -1;
    while (*(head + ++i) != 0);
    return i;
}

int main() {
    char string[100];
    
    printf("Enter a string: ");
    fgets(string, 100, stdin);

    int endIndex = findEnd(string) - 2;
    int middleIndex = endIndex / 2;
    int i = -1;

    while (++i <= middleIndex)
    if (string[i] != string[endIndex - i])
    break;

    if (i > middleIndex) printf("Palindrome\n");
    else printf("Not a palindrome.\n"); 
    
    return 0;
}

