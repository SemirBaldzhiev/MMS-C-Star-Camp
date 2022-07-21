#include <stdio.h>
#include <stdarg.h>

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...){
    unsigned countOnes = 0;
    unsigned countMasks = 0;
    va_list args;
    va_start(args, bitscnt);

    for (int i = 0; i < count; i++){
        countOnes = 0;
        int mask = va_arg(args, int);
        while(mask){
            countOnes += !!(mask & 1);
            mask >>= 1;
        }

        countMasks += (countOnes == bitscnt);
    }

    va_end(args);

    return countMasks;
}

int main() {
    printf("%u\n", bitsNCount(3, 4, 0x11110, 0x1101, 0x10101010));
    return 0;
}