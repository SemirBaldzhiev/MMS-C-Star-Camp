#include <stdio.h>

int main() {
    int opt, num;
    scanf("%d", &opt);

    switch (opt)
    {
        case 1:
            scanf("%d", &num);
            printf("%x\n", num);
            break;
        case 2:
            scanf("%d", &num);
            printf("%o\n", num);
            break;
        case 3:
            scanf("%x", &num);
            printf("%d\n", num);
            break;
        case 4:
            scanf("%x", &num);
            printf("%o\n", num);
            break;
        case 5:
            scanf("%o", &num);
            printf("%d\n", num);
            break;
        case 6:
            scanf("%o", &num);
            printf("%x\n", num);
            break;
    }
}