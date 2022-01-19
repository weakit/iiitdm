#include <stdio.h>

union xyz {
    int a;
    char c;
};

int main() {
    union xyz u;

    scanf("%d", &u.a);
    printf("u1.c %c\n", u.c);
    printf("u1.a %d\n", u.a);
    scanf("%d", NULL);
}

// conclusions

// the block of memory is shared,
// since memory is stored as little endian in most PCs (anything on x86/arm),
// the 8 least significant bits are used to decide the value of the char.
