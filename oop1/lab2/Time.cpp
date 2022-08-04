#include "Time.h"
#include "cstdio"

void setTimeFromInput(Time *time) {
    int hours, minutes, seconds = -1;

    while (true) {
        printf("Please enter time in 24h UTC.\n\n");
        printf("Enter hours: ");
        scanf("%d", &hours);
        printf("Enter minutes: ");
        scanf("%d", &minutes);
        printf("Enter seconds: ");
        scanf("%d", &seconds);

        if (hours >= 24 || hours < 0 || minutes >= 60 || minutes < 0 || seconds >= 60 || seconds < 0)
            printf("\nPlease enter a valid time.\n\n");
        else
            break;
    }

    time->setHours(hours);
    time->setMinutes(minutes);
    time->setSeconds(seconds);
}

void print12hTime(Time *time) {
    int hours = time->getHours() % 12;
    printf("%02d:%02d:%02d ", hours ? hours : 12, time->getMinutes(), time->getSeconds());
    if (time->getHours() >= 12) printf("PM\n");
    else printf("AM\n");
}

void print24hTime(Time *time) {
    printf("%02d:%02d:%02d\n", time->getHours(), time->getMinutes(), time->getSeconds());
}

int main() {
    int choice = 1;
    Time t;

    while (choice != 6) {
        switch (choice) {
            case 1:
                setTimeFromInput(&t);
                break;
            case 2:
                printf("\nStandard Time: ");
                print12hTime(&t);
                break;
            case 3:
                printf("\nUTC: ");
                print24hTime(&t);
                break;
            case 4: {
                printf("\nIST: ");
                Time ist = t.add(5, 30);
                print24hTime(&ist);
                break;
            }
            case 5: {
                printf("\nPST: ");
                Time pst = t.add(-8);
                print12hTime(&pst);
                break;
            }
            case 6:
                continue;
            default:
                printf("\nPlease enter a valid choice.\n");
        }

        printf("\n1. Reset the Time\n");
        printf("2. Print Standard Time\n");
        printf("3. Print Universal Time\n");
        printf("4. Print Indian Standard Time\n");
        printf("5. Print Pacific Standard Time\n");
        printf("6. Exit\n\n");

        printf("Enter a choice: ");
        scanf("%d", &choice);
    }

    printf("\nBye-bye!\n");
    return 0;
}

