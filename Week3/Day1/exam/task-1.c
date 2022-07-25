#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// #define COUNT 10
//#define MIN -10
//#define MAX 20

int compareAsc(const void* num1, const void* num2){
    if (*(double*)num1 > *(double*)num2) return 1;
    else if (*(double*)num1 < *(double*)num2) return -1;
    else return 0;  
}

int compareDesc(const void* num1, const void* num2){
    if (*(double*)num1 > *(double*)num2) return -1;
    else if (*(double*)num1 < *(double*)num2) return 1;
    else return 0;  
}

int compareAbs(const void* num1, const void* num2){
    if (fabs(*(double*)num1) > fabs(*(double*)num2)) return 1;
    else if (fabs(*(double*)num1) < fabs(*(double*)num2)) return -1;
    else return 0;  
}

int compareBySum(const void* num1, const void* num2){
    int n1 = (int)*(double*)num1;
    int n2 = (int)*(double*)num2;

    int sum1 = 0;
    int sum2 = 0;

    while (n1){
        sum1 += n1 % 10;
        n1 /= 10;
    }

    while (n2){
        sum2 += n2 % 10;
        n2 /= 10;
    }

    return sum1 - sum2;
}


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