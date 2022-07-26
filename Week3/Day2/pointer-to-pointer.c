#include <stdio.h>

int c = 9999;

void fun(int **b){
    **b = 10000;
    *b = &c;
    printf("b: %d\n", **b);
}

int main(){

    int a = 10;
    int *p = &a;
    int **ptr_to_p = &p; 

    printf("a: %d\n", a);
    fun(ptr_to_p);
    printf("a: %d\n", a);


    return 0;

}