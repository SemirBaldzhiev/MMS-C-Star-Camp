#include <stdio.h>
#include <stdint.h>

void printValue(void* value, int type){
    if(1 == type){
        printf("%d\n", *(int*)value);
    }
    else if(2 == type){
        printf("%.2lf\n", *(double*)value);
    }
    if(3 == type){
        printf("%c\n", *(char*)value);
    }
}


void printArr(int *arr, int len){
    for (int i = 0; i < len; i++){
        printf("%d", *(arr + i));
    }
}


void setNBit(uint32_t* mask, unsigned len, unsigned bit){
    
}
void clearBit(uint32_t* mask, unsigned len, unsigned bit){
    
}

void printMask(uint32_t* mask, unsigned len){
    for (int i = 0; i < len; i++){
        for (int bit = sizeof(*(mask + i)) * __CHAR_BIT__ - 1; bit >= 0; bit--) {
            printf("%d", !!(*(mask + i)) & (1ULL << bit));
        }
    }
}

int main() {

    uint32_t mask[2] = {0, 0};
    //setNBit(&mask, 2, 45);
    printMask(&mask, 2);
    return 0;
}