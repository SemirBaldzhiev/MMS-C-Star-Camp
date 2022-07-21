#include <stdio.h>  
#include <math.h>

#define ESP 0.000001

double mysqrt(double n) {

    double x = n;
    double root;

    while(1) {
        root = 0.5 * (x + (n / x));

        if (fabs(root - x) < ESP){
            break;
        }

        x = root;
    }

    return root;

}

int main() {

    double num;

    scanf("%lf", &num);

    double res = mysqrt(num);

    printf("%lf\n", res);

    return 0;
}