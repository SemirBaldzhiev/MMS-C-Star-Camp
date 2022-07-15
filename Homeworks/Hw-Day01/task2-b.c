#include <stdio.h>
#include <math.h>

int main() {
    double r, l, h;

    scanf("%lf %lf %lf", &r, &l, &h);

    double area = acos((r - h) / r) * r * r - (r - h) * sqrt(2 * r * h - h * h);
    double volume = area * l;

    printf("%.2lf\n", volume);

    return 0;
}