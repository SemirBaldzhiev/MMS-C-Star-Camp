#include <stdio.h>
#include <math.h>

int main() {
    double num;

    scanf("%lf", &num);
    double res = sqrt(num);

    printf("%.2lf\n", res);

    return 0;
}