#include <stdio.h>
#include <stdlib.h>
#include "randoms.h"
#include <math.h>

//#define COUNT 10

int compareInt1(const void* num1, const void* num2){
    return fabs(*((int*)num1) - *((int*)num2));
}

int compareInt2(const void* num1, const void* num2){
    return fabs(*((int*)num2) - *((int*)num1));
}


int main() {
    randinit();

    int (*mycomparator)(const void*, const void*) = compareInt1;

    int numbers[COUNT];
    for (int i = 0; i < COUNT; i++){
        numbers[i] = randint(-100, 100);
    }
    qsort(numbers, COUNT, sizeof(numbers[0]), mycomparator);
    for(int i = 0; i < COUNT; i++){
        printf("%d ", numbers[i]);
    }
    putchar('\n');
    printf("%d\n", compareInt1);
    printf("%p\n", main);

    return 0;
}
