#include <stdio.h>
#include <stdint.h>

unsigned onesCount(uint64_t mask){
    unsigned count;

    while (mask){
        count += mask & 1;
        mask >>= 1;
    }

    return count;
}

int main() {

    uint64_t mask = 0b010101;
    unsigned ones = onesCount(mask);
    printf("%d\n", ones);
    return 0;
}