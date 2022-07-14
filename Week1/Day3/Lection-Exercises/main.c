#include <stdio.h>

int main() {

    float num = 1232424343242342.0f;
    printf("%.30f\n", num);
    printf("%lu\n", sizeof(num));
    double num2 = 1232424343242342.0;
    printf("%.30lf\n", num2);
    printf("%lu\n", sizeof(num2));
    return 0;
}