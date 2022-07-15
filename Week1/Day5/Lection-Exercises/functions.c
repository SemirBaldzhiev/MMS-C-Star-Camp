#include <stdio.h>
#include <stdarg.h>
#include <float.h>


double max(int cnt, ...);
int sum(int cnt, ...);
int sumWhile(int n, ...);

int main() {
    int s = sum(2, 1, 1);
    double m = max(5, 1.0, 2.0, 3.0, 4.0, 5.0);
    int sw = sumWhile(1, 1, 2, 3, 4, 5, 0);
    // printf("%d\n", s);
    // printf("%lf\n", m);
    printf("%d\n", sw);

    
    return 0;
}

int sumWhile(int n, ...) {
    int sum = 0;

    va_list args;
    va_start(args, n);

    int num = va_arg(args, int);

    while (num) {
        sum += num;
        num = va_arg(args, int);
    }

    return sum;
    
}

int sum(int cnt, ...){
    int sum = 0;
    va_list args;
    va_start(args, cnt);

    for (int i = 0; i < cnt; i++){
        sum += va_arg(args, int);
    }

    va_end(args);
    return sum;
}

double max(int cnt, ...) {
    double maxNum = DBL_MIN;
    va_list args;
    va_start(args, cnt);

    for (int i = 0; i < cnt; i++){
        double num = va_arg(args, double);
        if (num > maxNum){
            maxNum = num;
        }
    }

    return maxNum;
} 