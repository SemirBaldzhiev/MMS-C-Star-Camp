#include <stdio.h>
#include <math.h>

#define EPS 1.0e-5f

int compare1(float a, float b){
    return a == b;
}

// fixed epsilon
int compare2(float a, float b){
    return fabs(a - b) < EPS;
}

// not fixed epsilon, depends from numbers
int compare3(float a, float b){
    return fabs(a - b) < EPS * fmax(fabs(a), fabs(b));
}

int compare1D(double a, double b){
    return a == b;
}

// fixed epsilon
int compare2D(double a, double b){
    return fabs(a - b) < __DBL_EPSILON__;
}

// not fixed epsilon, depends from numbers
int compare3D(double a, double b){
    return fabs(a - b) < __DBL_EPSILON__ * fmax(fabs(a), fabs(b));
}

int main() {

    printf("Double numbers\n");
    double num1D = 0.3*0.3 + 0.1;
    double num2D = 1.0;

    printf("Build in comparator(==): ");
    if (compare1D(num1D, num2D)){
        printf("Equal\n");
    }
    else{
        printf("Not Equal\n");
    }

    printf("Fixed Epsilon: ");
    if (compare2D(num1D, num2D)){
        printf("Equal\n");
    }
    else{
        printf("Not Equal\n");
    }

    printf("Not Fixed Epsilon:  ");
    if (compare3D(num1D, num2D)){
        printf("Equal\n");
    }
    else{
        printf("Not Equal\n");
    }



    printf("Float numbers\n");
    //float numbers
    float num1 = 100.0f;
    float num2 = 0.0f;
    for (int i = 0; i < 1000; i++, num2 += 0.1f);

    printf("Build in comparator(==): ");
    if (compare1(num1, num2)){
        printf("Equal\n");
    }
    else{
        printf("Not Equal\n");
    }

    printf("Fixed Epsilon: ");
    if (compare2(num1, num2)){
        printf("Equal\n");
    }
    else{
        printf("Not Equal\n");
    }

    printf("Not Fixed Epsilon: ");
    if (compare3(num1, num2)){
        printf("Equal\n");
    }
    else{
        printf("Not Equal\n");
    }


    // Double and float numbers comparison in precision
    float x = 0.9f;
    double y = 0.9;

    printf("x = %.30f\n", x);
    printf("y = %.30lf\n", y);

    float f = 0.7;   
    double d1 = 0.7;  
    double d2 = f;   
    printf ("d1 = %.30f\n", d1);
    printf ("d2 = %.30f\n", d2);
    
    return 0;
}