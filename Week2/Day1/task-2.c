#include <stdio.h>
#include <stdint.h>

unsigned zerosCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4);
void flipOddBits(uint64_t* mask);
void mirrorBits(uint16_t* mask);
void printMask(uint64_t* mask);
void printMask16(uint16_t* mask);


int main() {

    uint64_t mask1 = 0b1000;
    uint32_t mask2 = 0b10;
    uint16_t mask3 = 0b01;
    uint8_t mask4 = 0b1; 

    unsigned c = zerosCount(mask1, mask2, mask3, mask4);
    printf("%u\n", c);

    uint64_t mask = 0b0000000000000000000000000000000000000000000000000000000000000000;
    uint16_t mask5 = 0b0011111100000011;
    printMask(&mask);
    flipOddBits(&mask);
    printMask(&mask);
    mirrorBits(&mask5);
    printMask16(&mask5);
    return 0;
}

void flipOddBits(uint64_t* mask) {
    for (int i = 1; i < sizeof(*mask) * __CHAR_BIT__; i+=2){
        *mask ^= (1ULL << i);
    }
}

void mirrorBits(uint16_t* mask) {
    for (int i = 0; i < sizeof(*mask) * __CHAR_BIT__ / 2; i++){
        int firstBit =  !!(*mask & (1 << i));
        int lastBit = !!(*mask & (1 << (15 - i)));

        if (firstBit){
            *mask |= (1 << (15 - i));
        } 
        else {
            *mask &= ~(1 << (15 - i));
        }

        if (lastBit){
            *mask |= (1 << i);
        } 
        else {
            *mask &= ~(1 << i);
        } 
    }
}

void printMask(uint64_t *mask) {
    for (int i = 0; i < sizeof(*mask) * __CHAR_BIT__; i++) {
        printf("%d", !!(*mask & (1ULL << i)));
    }
    putchar('\n');
}

void printMask16(uint16_t *mask) {
    for (int i = 0; i < sizeof(*mask) * __CHAR_BIT__; i++) {
        printf("%d", !!(*mask & (1 << i)));
    }
    putchar('\n');
}

unsigned zerosCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4) {

    unsigned count = 0;

    for (int i = 0; i < sizeof(mask1) * __CHAR_BIT__; i++){
        if(!(!!(mask1 & (1 << i)))) {
            count++;
        }
    }

    for (int i = 0; i < sizeof(mask2) * __CHAR_BIT__; i++){
        if(!(!!(mask2 & (1 << i)))) {
            count++;
        }
    }

    for (int i = 0; i < sizeof(mask3) * __CHAR_BIT__; i++){
        if(!(!!(mask3 & (1 << i)))) {
            count++;
        }
    }

    for (int i = 0; i < sizeof(mask4) * __CHAR_BIT__; i++){
        if(!(!!(mask4 & (1ULL << i)))) {
            count++;
        }
    }

    return count;
} 