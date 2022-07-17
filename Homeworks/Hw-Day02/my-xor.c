#include <stdio.h>

int xor(int a, int b){
    return (!a && b) || (a && !b);
}

int main() {

    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    int twoXor = xor(a, b);
    int res = xor(twoXor, c);
    printf("%d\n", res);
    return 0;
}