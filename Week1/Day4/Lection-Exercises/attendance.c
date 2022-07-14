#include <stdio.h>
#include <stdint.h>

int main() {
    const uint64_t one = 1;
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
            attendance |= (one << num);
        }
        else if (2 == option){
            attendance &= ~(one << num);
        }
        else if (3 == option){
            for (int bit = sizeof(attendance) * __CHAR_BIT__ - 1; bit >= 0; bit--) {
                printf("%d", !!(attendance & (one << bit)));
            }
            putchar('\n');
        }
        else if (4 == option){
            attendance ^= (one << num);
        }

    }

    return 0;
}