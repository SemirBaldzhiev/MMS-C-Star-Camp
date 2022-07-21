#include <stdio.h>
#include <stdint.h>

#define TINT 1
#define TCHAR 2
#define TDBL 3
#define TFLOAT 4
#define TUI8 5
#define TUI16 6
#define TUI32 7
#define TUI64 8

//int, char, double, float, uint8_t, uint16_t, uint32_t, uint64_t.


void printValue(const void* valuePtr, uint8_t flag) {
    switch (flag)
    {
        case TINT: printf("%d\n", *((int*)valuePtr)); break;
        case TCHAR: printf("%c\n", *((char*)valuePtr)); break;
        case TDBL: printf("%lf\n", *((double*)valuePtr)); break;
        case TFLOAT: printf("%f\n", *((float*)valuePtr)); break;
        case TUI8: printf("%u\n", *((uint8_t*)valuePtr)); break;
        case TUI16: printf("%u\n", *((uint16_t*)valuePtr)); break;
        case TUI32: printf("%u\n", *((uint32_t*)valuePtr)); break;
        case TUI64: printf("%lu\n", *((uint64_t*)valuePtr)); break;
        default: printf("Unsupported format!\n"); break;
    }
}

int main() {

    int num = 23;
    printValue(&num, TINT);
    double num2 = 3.14;
    printValue(&num2, TDBL);
    char symbol = 'A';
    printValue(&symbol, TCHAR);

    return 0;
}