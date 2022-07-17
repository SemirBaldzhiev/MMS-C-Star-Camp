#include <stdio.h>


int rectangle(double w, double h, double* S, double *P){
    if (w < 0 || h < 0){
        return -1;
    }

    *S = w * h;
    *P = 2 * w + 2 * h;
    return 0;
}

int main() {

    double w, h, s, p;

    while (scanf("%lf %lf", &w, &h) != EOF){
        if (rectangle(w, h, &s, &p)){
            fprintf(stderr, "Invalid rectangle sizes!\n");
        }
        else{
            printf("S = %.2lf\n", s);
            printf("P = %.2lf\n", p);
        }
    }

    return 0;
}