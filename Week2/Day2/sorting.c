#include <stdio.h>
#include <stdlib.h>
#include "randoms.h"
#include <math.h>

//#define COUNT 10

int compareAsc(const void* num1, const void* num2){
    return *((int*)num1) - *((int*)num2);
}

int compareDesc(const void* num1, const void* num2){
    return *((int*)num2) - *((int*)num1);
}

int compareAscAbs(const void* num1, const void* num2){
    return abs(*((int*)num1) - *((int*)num2));
}

int compareDescAbs(const void* num1, const void* num2){
    return abs(*((int*)num2) - *((int*)num1));
}


int main() {
    randinit();

    int (*comparators[4])(const void*, const void*) = {compareAsc, compareDesc, compareAscAbs, compareDescAbs};


    int num;

    scanf("%d", &num);

    int numbers[COUNT];
    for (int i = 0; i < COUNT; i++){
        numbers[i] = randint(-100, 100);
    }

    if (num < 0 || num > 3) {
        fprintf(stderr, "Invalid comparator number!");
    }
    else {
        qsort(numbers, COUNT, sizeof(numbers[0]), comparators[num]);
    }
    
    for(int i = 0; i < COUNT; i++){
        printf("%d ", numbers[i]);
    }
    putchar('\n');

    return 0;
}