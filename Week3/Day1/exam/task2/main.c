#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comparators.h"

int main() {

    double numbers[COUNT];
    srand(time(NULL));

    for (int i = 0; i < COUNT; i++){
        numbers[i] = MIN + ((double)rand() / RAND_MAX) * (MAX - MIN);
    }

    for (int i = 0; i < COUNT; i++){
        printf("%lf ", numbers[i]); 
    }

    putchar('\n');

    int (*comparators[4])(const void*, const void*) = {compareAsc, compareDesc, compareAbs, compareBySum};
    
    int n;
    scanf("%d", &n);

    if (n < 1 || n > 4){
        fprintf(stderr, "Invalid number of comparator!");
        return 0;
    }

    qsort(numbers, COUNT, sizeof(numbers[0]), comparators[n - 1]);

    for (int i = 0; i < COUNT; i++){
        printf("%lf ", numbers[i]); 
    }
    putchar('\n');
    return 0;
}