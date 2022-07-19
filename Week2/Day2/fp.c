#include <stdio.h>

double sum(double num1, double num2){
    return num1 + num2;
}


double sub(double num1, double num2){
    return num1 - num2;
}

double mult(double num1, double num2){
    return num1 * num2;
}

double div(double num1, double num2){
    return num1 / num2;
}

int main(){

    double (*calcFunc[4])(double, double) = {sum, sub, mult, div};

    int num;

    scanf("%d", &num);

    printf("%.2lf\n", calcFunc[num](2.2, 3.1));
    // printf("Sub = %.2lf\n", calcFunc[1](2.2, 3.1));
    // printf("Mult = %.2lf\n", calcFunc[2](2.2, 3.1));
    // printf("Div = %.2lf\n", calcFunc[3](2.2, 3.1));

    return 0;
}