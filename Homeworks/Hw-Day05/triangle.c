#include <stdio.h>
#include <math.h>
int triangle(double a, double b, double c, double *P, double *S){
    if (a + b <= c || a + c <= b || c + b <= a){
        return -1;
    }


    *P = a + b + c;
    double halfP = *P / 2;
    *S = sqrt(halfP * (halfP - a) * (halfP - b) * (halfP - c));
    return 0;
}

int main() {

    double a, b, c, p, s;

    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        if(triangle(a, b, c, &p, &s)){
            fprintf(stderr, "Invalid triangle sides!\n");
        }
        else{
            printf("S = %.2lf\n", s);
            printf("P = %.2lf\n", p);
        }
    }
    


    return 0;
}