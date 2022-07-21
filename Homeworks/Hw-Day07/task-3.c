
#include <stdio.h>


int sum(int* arr, int n);
void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int));


int main() {

    int arr[] = {1, 2, 3};
    arrayEvaluate(arr, 3, sum);

    return 0;
}

int sum(int *arr, int n){
    int res = 0;
    for (int i = 0; i < n; i++){
        res += arr[i];
    }
    return res;
} 

void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int)) {
    printf("Value: %d\n", f(arr, n));
}