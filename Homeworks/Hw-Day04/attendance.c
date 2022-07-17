#include <stdio.h>
#include <stdint.h>

const uint64_t one = 1ULL;

void setAttendance(uint64_t *attendance, unsigned num) {
    *attendance |= (one << num);
}

void clearAttendance(uint64_t *attendance, unsigned num) {
    *attendance &= ~(one << num);
}

void info(uint64_t attendance, unsigned num) {
    for (int bit = sizeof(attendance) * __CHAR_BIT__ - 1; bit >= 0; bit--) {
        printf("%d", !!(attendance & (one << bit)));
    }
    putchar('\n');
}

void changeAttendance(uint64_t *attendance, unsigned num) {
    *attendance ^= (one << num);
}

int main() {
    uint64_t attendance = 0;
    int option;

    while(1) {
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance Info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n");

        scanf("%d", &option);

        if (option < 1 || option > 5){
            printf("Invalid option!");
            continue;
        }

        if (5 == option){
            break;
        }

        int num;
        if (3 != option) {
            scanf("%d", &num);
            if (num < 0 || num > 63){
                printf("Invalid number!");
                continue;
            }
        }

        if (1 == option) {
            setAttendance(&attendance, num);
        }
        else if (2 == option){
            clearAttendance(&attendance, num);
        }
        else if (3 == option){
            info(attendance, num);
        }
        else if (4 == option){
            changeAttendance(&attendance, num);
        }

    }

    return 0;
}