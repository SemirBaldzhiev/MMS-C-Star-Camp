#include <stdio.h>

int main() {

    double a, b;
    char op;

    while (scanf("%lf %c %lf", &a, &op, &b) != EOF) {
        if (op == '+'){
            printf("%.2lf\n", a + b);
        }
        else if (op == '-'){
            printf("%.2lf\n", a - b);
        }
        else if (op == 'x'){
            printf("%.2lf\n", a * b);
        }
        else if (op == '/'){
            if (b == 0){
                fprintf(stderr, "Cannot divide by zero!\n");
            }
            else{
                printf("%.2lf\n", a / b);
            }
        }
        else{
            fprintf(stderr, "Invalid operation!\n");
        }
    }

    return 0;
}