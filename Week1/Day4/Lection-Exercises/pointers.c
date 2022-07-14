#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = *a;
    *a = temp;
}


int main() {

    int num1 = 5;
    int num2 = 4;
    swap(&num1, &num2);
    printf("%d\n", num1);
    printf("%d\n", num2);

    return 0;
}