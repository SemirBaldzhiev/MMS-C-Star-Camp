#include <stdio.h>
#include "bitmasks.h"


int main() {

    uint32_t mask = 0b0110100101;
    printf("dsaasd\n");
    setBit(&mask, 20);
    for (int i = 0; i < sizeof(mask) * __CHAR_BIT__; i++){
        printf("%d", checkBit(&mask, i));
    }
    putchar('\n');
    for (int i = 0; i < 10000000000; i++){
    }
    return 0;
}