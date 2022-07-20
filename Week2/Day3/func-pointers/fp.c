#include <stdio.h>

void printValue(int num){
    printf("Value: %d\n", num);
}

void printHello(int count){
    for (int i = 0; i < count; ++i){
        printf("hello ");
    }
    putchar('\n');
}

int ddoubleIt(int num){
    return num * 2;
}

void map(int *arr, int n, int(*func)(int)){
    for (int i = 0; i < n; ++i){
        arr[i] = func(arr[i]);
    }
}


int main() {

    void (*fp)(int) = NULL;
    fp = printHello;

    fp(5);

    fp = printValue;
    fp(5);

    int arr[] = {1,2,3,4,5};

    map(arr, 5, ddoubleIt);

    for(int i = 0; i < 5; ++i){
        printf("%d\n", arr[i]);
    }

    return 0;
}