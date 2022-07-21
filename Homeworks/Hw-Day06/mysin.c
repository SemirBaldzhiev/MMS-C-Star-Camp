#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EPS 0.000003


double mysin(double angel){
    int sign = -1, power = 3;
    double previous, current, rad, res;
    
    rad = angel * (PI / 180);
    
    res = rad;
    current = rad;
    do{
        previous = current;
        current = (previous * pow(rad, 2.0)) / (power * (power - 1));
        
        res += sign * current;
        power += 2;
        sign *= -1;
    }
    while(fabs(current - previous) > EPS);
    
    return res;
}

int main() {

    double x;
    printf("x = ");
    scanf("%lf", &x);
    printf("sin(x) = %lf\n", mysin(x));
    return 0;
}