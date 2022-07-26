#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int c = 0; // global variable

void fun() {
    static int c2 = 0; // static variable
    c2++;
    c++;
    printf("%d\n", c2);
}


void f3(int d){
    int e = d + 200;
    printf("f3\n");
}
void f2(int c){
    printf("f2\n");
    f2(c + 200);
}
void f1(int a, int b){
    printf("f1\n");
    f2(100);
}

//int count = 0;
//void recur() {
//    count++;
//    printf("%d\n", count);
//    recur();
//}
//
int main() {
    
    int *arr = malloc(sizeof(int) * 1000);
    //int *arr = (int*)ptr;
    srand(time(NULL));
    for (int i = 0; i < 1000; i++){
        arr[i] = 250 + rand() % (750 - 250 + 1);
    }

    for (int i = 0; i < 1000; i++){
        if (arr[i] == 500){
            printf("arr[%d] = %d\n",i,arr[i]);
        }
    }

    free(arr);

}