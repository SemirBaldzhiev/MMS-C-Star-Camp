#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int secondMax(const int* arr, size_t n, int* secondMax) {
    
    if (n == 0){
        return 1;
    }

    if (n == 1){
        return 2;
    }

    uint8_t equals = 1;
    for (int i = 1; i < n - 1; i++){
        if (arr[i] != arr[i + 1]){ //3 3 3 3 3 3
            equals = 0;
            break;
        }
    }

    if (equals){
        return 3;
    }
    
    int max1 = INT_MIN;
    *secondMax = INT_MIN;
    for (int i = 0; i < n; i++){
        if (arr[i] > max1){
            *secondMax = max1;
            max1 = arr[i];
        }
        else if (arr[i] < max1 && arr[i] > *secondMax){
            *secondMax = arr[i];
        }
    }

    return 0;
}

int main() {

    int sm;
    int arr[] = {12, 34, 5, 70, 46 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int statusCode = secondMax(arr, size, &sm);

    if(1 == statusCode){
        fprintf(stderr, "Empty array!\n");
    }
    else if (2 == statusCode){
        fprintf(stderr, "Array contains only one element!\n");
    }
    else if (3 == statusCode){
        fprintf(stderr, "All elements in the array are equal!\n");
    }
    else{
        printf("Second max = %d\n", sm);
    }

    return 0;
}