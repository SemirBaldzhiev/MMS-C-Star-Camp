#include <stdio.h>
#include <stdint.h>

int isValidBit(uint32_t mask, size_t n, size_t bit);
int setBit(uint32_t* mask, size_t n, size_t bit);
int clearBit(uint32_t* mask, size_t n, size_t bit);
int flipBit(uint32_t* mask, size_t n, size_t bit);
int checkBit(uint32_t* mask, size_t n, size_t bit);
void print(uint32_t* mask, size_t n);

int main() {
    const unsigned LEN = 2;
    uint32_t mask[] = {0, 0};
    setBit(mask, LEN);
    print(mask, LEN);
    printf("------------------------------------------------\n");
    clearBit(mask, LEN, 10);
    print(mask, LEN);
    printf("------------------------------------------------\n");
    setBit(mask, LEN, 12);
    print(mask, LEN);
    printf("------------------------------------------------\n");
    flipBit(mask, LEN, 15);
    print(mask, LEN);
    printf("------------------------------------------------\n");
    return 0;
}

int setBit(uint32_t* mask, size_t n, size_t bit){
    
    if (!isValidBit(*mask, n, bit)){
        return 1;
    }

    int i = bit / (sizeof(*mask) * __CHAR_BIT__);
    int b = bit % (sizeof(*mask) * __CHAR_BIT__);
    *(mask + i) |= (1ULL << b);
    return 0;
}

int clearBit(uint32_t* mask, size_t n, size_t bit){
    if (!isValidBit(*mask, n, bit)){
        return 1;
    }

    int i = bit / (sizeof(*mask) * __CHAR_BIT__);
    int b = bit % (sizeof(*mask) * __CHAR_BIT__);
    *(mask + i) &= ~(1ULL << bit);
    return 0;
}

int flipBit(uint32_t* mask, size_t n, size_t bit){
   if (!isValidBit(*mask, n, bit)){
        return 1;
    }

    int i = bit / (sizeof(*mask) * __CHAR_BIT__);
    int b = bit % (sizeof(*mask) * __CHAR_BIT__);
    *(mask + i) ^= (1ULL << bit);
    return 0;
}

int checkBit(uint32_t* mask, size_t n, size_t bit){
    
    if (!isValidBit(*mask, n, bit)){
        return -1;
    }
    
    int i = bit / (sizeof(*mask) * __CHAR_BIT__);
    int b = bit % (sizeof(*mask) * __CHAR_BIT__);

    return !!(*(mask + i) & (1ULL << b));
}

void print(uint32_t* mask, size_t n){
    
    for (int i = 63; i >= 0; i--){
        printf("%3d", i);
    }
    putchar('\n');
    
    for (int bit = sizeof(*mask) * __CHAR_BIT__ * n - 1; bit >= 0; bit--) {
        printf("%3d", checkBit(mask, n, bit));
    }
    putchar('\n');
}


int isValidBit(uint32_t mask, size_t n, size_t bit) {
    if (n * sizeof(mask) * __CHAR_BIT__ <= bit){
        return 0;
    }
    return 1;
}