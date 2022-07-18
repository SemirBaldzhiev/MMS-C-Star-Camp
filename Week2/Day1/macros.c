#include <stdio.h>
#include <stdint.h>

#define SETBIT(mask, bit) (mask |= (1ULL << (bit)))
#define CLEARBIT(mask, bit) (mask &= ~(1ULL << (bit)))
#define CHECKBIT(mask, bit) (!!(mask & (1ULL << (bit))))
#define FLIPBIT(mask, bit) (mask ^= (1ULL << (bit))) 

void printMask(uint64_t *mask){
    for (int i = 0; i < sizeof(*mask) * __CHAR_BIT__; i++){
        printf("%d", CHECKBIT(*mask, i));
    }
    putchar('\n');
}

int main() {

    uint64_t mask = 0b010101111011101;
    SETBIT(mask, 54);
    printMask(&mask);
    return 0;
}