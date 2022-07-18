#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

size_t onesCount(size_t count, ...){
    size_t resCount = 0;
    
    va_list args;
    va_start(args, count);

    for(int i = 0; i < count; i++) {
        int mask = va_arg(args, int);
        while(mask) {
            resCount += mask & 1;
            mask >>= 1;
        }
    }
    va_end(args);
    return resCount;
}


int main(void) {
    size_t c1 = onesCount(4, 0x0a, 0, 1, 2);
    size_t c2 = onesCount(3, 0xff, 0x131, 0xaaaa);
    size_t c3 = onesCount(2, 0b0001, 9);

    printf("%lu\n", c1);
    printf("%lu\n", c2);
    printf("%lu\n", c3);

    return 0;
}