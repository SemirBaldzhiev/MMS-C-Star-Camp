#include <stdio.h>

int main() {

    const double pi = 3.14159265359;
    double r, h;

    scanf("%lf %lf", &r, &h);

    double v = pi * r * r * h;

    printf("%.2lf\n", v);

    return 0;
}