#include <stdio.h>
#include <stdlib.h>
#include "randoms.h"

#define COUNT 5

int compare(const void* a, const void* b){
    return a - b;
}

int main() {
    randinit();
    double arr[COUNT];

    for (int i = 0; i < COUNT; i++){
        arr[i] = randreal(5.0, 10.2);
    }
    int (*mycomparator)(const void*, const void*) = compare;
    qsort(arr, COUNT, sizeof(*arr), mycomparator);

    
    for (int i = 0; i < COUNT; i++){
        printf("%lf\n", arr[i]);
    }
    return 0;
}