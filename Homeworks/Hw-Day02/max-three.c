#include <stdio.h>

int main() {
    double a, b, c, max;

    scanf("%lf %lf %lf", &a, &b, &c);

    if (a >= b && a >= c) {
        max = a;
    }
    else if (b >= a && b >= c) {
        max = b;
    }  
    else {
        max = c;
    }

    printf("%lf\n", max);

}