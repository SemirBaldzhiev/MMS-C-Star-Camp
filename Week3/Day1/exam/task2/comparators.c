#include <math.h>

//#include "comparators.h"


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
