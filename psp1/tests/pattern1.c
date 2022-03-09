//               1
//          2    3    4
//     5    6    7    8    9
//10   11   12   13   14   15   16
//     A    B    C    D    E
//          *    *    *
//               G


#include <stdio.h>

int abs(int x) {
    if (x < 0) return -x;
    return x;
}

void printChar(int count) {
    if (count < 10) printf("%d    ", count);
    else if (count < 17) printf("%d   ", count);
    else if (count < 22) printf("%c    ", 48 + count);
    else if (count == 25) printf("G    ");
    else printf("*    ");
}

int main() {
    int diamond, i, count = 1;

    for (diamond = -3; diamond < 4; diamond++) {
        for (i = abs(diamond); i > 0; i--) printf("     ");
        for (i = (3 - abs(diamond)) * 2 + 1; i > 0; i--) printChar(count++);
        printf("\n");
    }
}


