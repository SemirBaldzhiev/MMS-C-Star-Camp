#include <stdio.h>

typedef int (*operation_t)(int, int);

int sum(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a + b;
}

int mult(int a, int b){
    return a * b;
}

int div(int a, int b){
    return a / b;
}

operation_t getOp(char op) {

//int (*getOp(char op))(int, int) 
    if ('+' == op){
        return sum;
    }
    else if ('-' == op){
        return sub;
    }
    else if ('*' == op){
        return mult;
    }
    else if ('/' == op){
        return div;
    }
    else{
        return NULL;
    }
}

typedef unsigned int litres_t;

int main() {
    litres_t rakiaBottle;
    printf("%d\n", getOp('+')(5, 6));
    return 0;
}