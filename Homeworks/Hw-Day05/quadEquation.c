#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int quadEq(double a, double b, double c, double *x1, double *x2) {
    double d = b * b - 4 * a * c;

    if (d < 0){
        return -1;
    }

    *x1 = (-b + sqrt(d)) / 2 * a;
    *x2 = (-b - sqrt(d)) / 2 * a;

    return 0;
}

int main(int argc, char* argv[]) {
    double x1, x2;
    double a, b, c;

    sscanf(argv[1], "%lf", &a);
    sscanf(argv[2], "%lf", &b);
    sscanf(argv[3], "%lf", &c);

    if (quadEq(a, b, c, &x1, &x2)){
        fprintf(stderr, "Not real roots!\n");
    }
    else{
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
    }

    return 0;
}