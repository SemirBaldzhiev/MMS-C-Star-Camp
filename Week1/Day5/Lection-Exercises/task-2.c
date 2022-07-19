#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

size_t bitsNCount(size_t count, size_t bitscnt, ...){
    size_t c;
    size_t res = 0;
    va_list args;

    va_start(args, bitscnt);

    for (int i = 0; i < count; i++) {
       
        c = 0;
        int mask = va_arg(args, int);
        while(mask) {
            c += !!(mask & 1);
            mask >>= 1;
        }

        res = (c == bitscnt);
    }
    
    va_end(args);

    return res;

}

int main() {

    size_t n = bitsNCount(4, 2, 0x0a, 0xff, 0, 1);
    size_t n1 = bitsNCount(3, 8, 0xff, 0x13f1, 0xaaaa);

    printf("%lu\n", n);
    printf("%lu\n", n1);

    return 0;
}
