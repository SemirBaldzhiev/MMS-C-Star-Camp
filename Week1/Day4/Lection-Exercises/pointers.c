#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = *a;
    *a = temp;
}


int main() {

    char c = 'Z';
    int num2 = 4;
    void * a = &c;
    printf("%d\n", num2);

    return 0;
}