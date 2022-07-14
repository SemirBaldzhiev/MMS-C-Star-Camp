#include <stdio.h>
#include <stdint.h>
int main() {
    uint16_t mask = 3;
    int bit = 1;
    mask |= (1 << bit);
    bit = 14;
    mask |= (1 << bit);
    bit = 10;
    mask |= (1 << bit);
    mask &= ~(1 << bit);
    for (bit = sizeof(mask) * __CHAR_BIT__ - 1; bit >= 0; bit--) {
        printf("%d", !!(mask & (1 << bit)));
    }
    putchar('\n');
    return 0;
}