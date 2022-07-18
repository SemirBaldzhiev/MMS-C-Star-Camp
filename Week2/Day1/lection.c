#include <stdio.h>

#define PI 3.14
#define mydouble double
#define SUM(x, y) ((x) + (y))
#define MULT(x, y) ((x) * (y))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAI(a, b) ((a) > (b) ? (b) : (a))
#define FORI(start, end, step) for (int i = start; i < end; i += step)

#define SWAP(a, b) {a ^= b; \
                    b ^= a; \
                    a^= b;}

#define MAX4(a, b, c, d) MAX(MAX(a, b), MAX(c, d))
#define CIRCLEAREA(r) (PI * (r) * (r))

int max(int a, int b){
    return a > b ? a : b;
}

int main() {


    double r = 10;
    double S = PI * r * r;
    double P = 2 * PI * r;
    int res = SUM(10, 20) * 2;
    int res2 = MULT(10, 20) * 2;


    printf("S = %.2lf\n", S);
    printf("P = %.2lf\n", P);
    printf("%d\n", res);
    printf("%d\n", res2);

    FORI(1, 10, 2){
        printf("%d\n", i);
    }

    int a = 10;
    int b = 20;

    printf("%d %d\n", a, b);
    SWAP(a, b);
    printf("%d %d\n", a, b);
    //int c = max(a++, b++);
    int c = MAX(a++, b++);
    
    printf("a = %d\nb = %d\nc = %d\n", a, b, c);


    return 0;
}