#include <stdio.h>
#include <math.h>
int main() {

    double mass, height;

    scanf("%lf %lf", &mass, &height);

    // a
    double bmi = mass / (height * height);

    // b
    double newBmi = 1.3 * (mass / pow(height, 2.5));


    printf("%.2lf\n", bmi);
    printf("%.2lf\n", newBmi);

    return 0;
}